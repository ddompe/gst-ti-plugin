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

#ifndef _GST_CMEM_META_H_
#define _GST_CMEM_META_H_

#include <gst/gst.h>

#include <xdc/std.h>
#include <ti/sdo/ce/osal/Memory.h>

G_BEGIN_DECLS typedef struct _GstCMEMMeta GstCMEMMeta;

/**
 * GstMEMMeta:
 * @physical_address: physical_address of the buffer.
 *
 */
struct _GstCMEMMeta
{
  GstMeta meta;

  gpointer physical_address;
};

const GstMetaInfo *gst_cmem_meta_get_info (void);
#define GST_CMEM_META_INFO (gst_cmem_meta_get_info())

#define gst_buffer_get_cmem_meta(b) \
  ((GstCMEMMeta*)gst_buffer_get_meta((b),GST_CMEM_META_INFO))
#define gst_buffer_add_cmem_meta(b) \
  ((GstCMEMMeta*)gst_buffer_add_meta((b),GST_CMEM_META_INFO,NULL))

/**
 * gst_buffer_get_cmem_physical_address:
 * @buffer: a GstBuffer
 * 
 * Returns: the physical address of the buffer, or NULL if the buffer does not
 * have the metadata
 */
inline gpointer
gst_buffer_get_cmem_physical_address (GstBuffer * buffer)
{
  GstCMEMMeta *meta = gst_buffer_get_cmem_meta (buffer);
  if (meta != NULL)
    return meta->physical_address;
  return NULL;
}

G_END_DECLS
#endif
