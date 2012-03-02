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

static gboolean
TIPlugin_init (GstPlugin * plugin)
{
//  return gst_element_register (plugin, "tiplugin", GST_RANK_PRIMARY, GST_TYPE_BASECEENC);
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    "tiplugin",
    "GStreamer Plugin for codecs based on CodecEngine API for Texas Instruments SoC",
    TIPlugin_init, VERSION, "LGPL", "gst-ti-plugin", "RidgeRun")
