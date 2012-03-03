/* GStreamer
 * Copyright (C) 2012 RidgeRun
 *
 * Author: Diego Dompe <ddompe@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "gstcmemallocator.h"

#include <string.h>

#include <gst/gstmemory.h>

GST_DEBUG_CATEGORY_STATIC (cmem);
#define GST_CAT_DEFAULT cmem

static GstAllocator *_cmem_allocator;

typedef struct
{
  GstMemory mem;
  guint8 *data;
  guint32 alloc_size;
  Memory_AllocParams alloc_params;
//  guint32 physical_address;
} GstMemoryCMEM;

GstMemoryCMEM *
_cmem_new_mem_block(gsize maxsize, gsize align, gsize offset, gsize size)
{
  GstMemoryCMEM *mem;

  mem = g_slice_alloc (sizeof (GstMemoryCMEM));
  if (mem == NULL)
    return NULL;

  mem->alloc_params = Memory_DEFAULTPARAMS;
  mem->alloc_params.type = Memory_CONTIGPOOL;
  mem->alloc_params.flags = Memory_CACHED;
  mem->alloc_params.align = ((UInt)(align - 1));

  mem->data = (guint8 *) Memory_alloc(maxsize, &mem->alloc_params);
  if (mem->data == NULL) {
    g_slice_free1 (sizeof(GstMemoryCMEM), mem);
  }
  mem->alloc_size = maxsize;
  mem->mem.allocator = _cmem_allocator;
  mem->mem.flags = 0;
  mem->mem.refcount = 1;
  mem->mem.parent = NULL;
  mem->mem.state = 0;
  mem->mem.maxsize = maxsize;
  mem->mem.offset = offset;
  mem->mem.size = size;

  return mem;
}

static GstMemory *
_cmem_alloc (GstAllocator * allocator, gsize maxsize, gsize align,
    gpointer user_data)
{
  return (GstMemory *) _cmem_new_mem_block (maxsize, align, 0, maxsize);
}

static gpointer
_cmem_map (GstMemoryCMEM * mem, GstMapFlags flags)
{
  if (flags & GST_MAP_READ) {
    GST_DEBUG ("invalidate cache for memory %p", mem);
    Memory_cacheInv(mem->data,mem->alloc_size);
  }
  return mem->data;
}

static gboolean
_cmem_unmap (GstMemoryCMEM * mem)
{
  GST_DEBUG ("write-back cache for memory %p", mem);
  Memory_cacheWb(mem->data,mem->alloc_size);
  return TRUE;
}

static void
_cmem_free (GstMemoryCMEM * mem)
{
  GST_DEBUG ("free memory %p", mem);

  if (mem->mem.parent)
    gst_memory_unref (mem->mem.parent);

  Memory_free(mem->data,mem->alloc_size,&mem->alloc_params);
  g_slice_free1 (sizeof(GstMemoryCMEM), mem);
}

static GstMemoryCMEM *
_cmem_copy (GstMemoryCMEM * mem, gssize offset, gsize size)
{
  GstMemoryCMEM *copy;

  if (size == -1)
    size = mem->mem.size > offset ? mem->mem.size - offset : 0;

  copy =
      _cmem_new_mem_block (mem->mem.maxsize, 0, mem->mem.offset + offset,
      size);
  memcpy (copy->data, mem->data, mem->mem.maxsize);
  GST_DEBUG ("cmem copy memory %p -> %p", mem, copy);

  return copy;
}

static GstMemoryCMEM *
_cmem_share (GstMemoryCMEM * mem, gssize offset, gsize size)
{
#if 0
  GstMemoryCMEM *sub;
  GstMemory *parent;

  /* find the real parent */
  if ((parent = mem->mem.parent) == NULL)
    parent = (GstMemory *) mem;

  if (size == -1)
    size = mem->mem.size - offset;

  sub =
      _default_mem_new (parent->flags, parent, mem->data, NULL,
      mem->mem.maxsize, mem->mem.offset + offset, size);

  return sub;
#else 
  return NULL;
#endif
}

static gboolean
_cmem_is_span (GstMemoryCMEM * mem1, GstMemoryCMEM * mem2,
    gsize * offset)
{
#if 0
  if (offset) {
    GstMemoryDefault *parent;

    parent = (GstMemoryDefault *) mem1->mem.parent;

    *offset = mem1->mem.offset - parent->mem.offset;
  }

  /* and memory is contiguous */
  return mem1->data + mem1->mem.offset + mem1->mem.size ==
      mem2->data + mem2->mem.offset;
#else
  return FALSE;
#endif
}

static void
_priv_cmem_notify (gpointer user_data)
{
  g_warning ("The cmem memory allocator was freed!");
}

void
gst_cmem_allocator_initialize (void)
{
  static const GstMemoryInfo _mem_info = {
    GST_ALLOCATOR_CMEM,
    (GstAllocatorAllocFunction) _cmem_alloc,
    (GstMemoryMapFunction) _cmem_map,
    (GstMemoryUnmapFunction) _cmem_unmap,
    (GstMemoryFreeFunction) _cmem_free,
    (GstMemoryCopyFunction) _cmem_copy,
    (GstMemoryShareFunction) _cmem_share,
    (GstMemoryIsSpanFunction) _cmem_is_span,
  };

  GST_DEBUG_CATEGORY_INIT(cmem, "cmem", 0, "CMEM allocation debugging");

  _cmem_allocator = gst_allocator_new(&_mem_info,NULL,_priv_cmem_notify);
  gst_allocator_register (GST_ALLOCATOR_CMEM,
      gst_allocator_ref (_cmem_allocator));
  GST_DEBUG("cmem memory allocator registered!");
}
