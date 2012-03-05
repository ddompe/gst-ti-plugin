/*
 * Authors:
 *   Diego Dompe <ddompe@gmail.com>
 *   Luis Arce <luis.arce@rigerun.com>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gstbaseceencoder.h>

#include <string.h>
#include <stdlib.h>

#define GST_CAT_DEFAULT gstcebaseencoder_debug
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);

static void
gst_base_ce_encoder_finalize (GObject * object);

static void
gst_base_ce_encoder_class_init (GstBaseCEEncoderClass * klass)
{
  GObjectClass *gobject_class = (GObjectClass *) klass;
  GstElementClass *gstelement_class = GST_ELEMENT_CLASS (klass);

  GST_DEBUG_CATEGORY_INIT (gstcebaseencoder_debug, "gstcebaseencoder", 0, "Base CE Encoder Class");

  gobject_class->finalize = gst_base_ce_encoder_finalize;
}

static void
gst_base_ce_encoder_init (GstBaseCEEncoder *base_encoder)

}

/* Function for Finalize the class instance */
static void
gst_base_ce_encoder_finalize (GObject * object)
{
  GstBaseCEEncoder *base_encoder = GST_BASE_CE_ENCODER (object);

  GST_DEBUG_OBJECT (base_encoder, "Finalizing");
}

/* Obtain the type of the class */
GType gst_base_ce_encoder_get_type(void)
{
    static GType object_type = 0;
    
    static const GTypeInfo object_info = {
            sizeof(GstBaseCEEncoderClass),
            NULL,
            NULL,
            (GClassInitFunc)gst_base_ce_encoder_class_init,
            NULL,
            NULL,
            sizeof(GstBaseCEEncoder),
            0,
            (GInstanceInitFunc) gst_base_ce_encoder_init,
            NULL
        };

    object_type = g_type_register_static(GST_TYPE_ELEMENT,
                          "GstBaseCEEncoder", &object_info, (GTypeFlags)0);

    return object_type;
};

/** gst_base_ce_encoder_get_output_buffer
 * @base_encoder : a #GstBaseCEEncoder object
 * @size : size for the buffer
 *
 * Returns: a #GstBuffer 
 */
GstBuffer*
gst_base_ce_encoder_get_output_buffer(GstBaseCEEncoder *base_encoder, gsize size) 
{
  return NULL;
}
