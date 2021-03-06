/*
 * gsttiplugin.c
 *
 * Authors:
 *      Diego Dompe, ddompe@gmail.com
 *      Luis Arce, luis.arce@ridgerun.com
 *
 * Copyright (C) 2012 RidgeRun	
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation version 2.1 of the License.
 *
 * This program is distributed #as is# WITHOUT ANY WARRANTY of any kind,
 * whether express or implied; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */

#include "gsttiplugin.h"

GST_DEBUG_CATEGORY_STATIC (tiplugin);
#define GST_CAT_DEFAULT tiplugin

void gst_cmem_allocator_initialize (void);

static gboolean
TIPlugin_init (GstPlugin * plugin)
{
  GST_DEBUG_CATEGORY_INIT (tiplugin, "ti", 0, "TI plugin debugging");
  gst_cmem_allocator_initialize ();
//  return gst_element_register (plugin, "tiplugin", GST_RANK_PRIMARY, GST_TYPE_BASECEENC);
  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    "tiplugin",
    "GStreamer Plugin for codecs based on CodecEngine API for Texas Instruments SoC",
    TIPlugin_init, VERSION, "LGPL", "gst-ti-plugin", "RidgeRun")
