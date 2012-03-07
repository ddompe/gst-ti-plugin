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

#define GST_CAT_DEFAULT gst_ce_base_encoder_debug
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);

enum
{
	PROP_0,
	PROP_A
};

static void
gst_base_ce_encoder_base_init (GstBaseCEEncoderClass * klass)
{
  /* Initialize dynamic data */
}

static void
gst_base_ce_encoder_base_finalize (GstBaseCEEncoderClass * klass)
{
}

static void
gst_base_ce_encoder_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
 // GstBaseCEEncoder *base_enc = GST_BASE_CE_ENCODER (object);

  /* Set base params */
  switch (prop_id) {
    default:
      break;
  }

}

static void
gst_base_ce_encoder_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
//  GstBaseCEEncoder *base_enc = GST_BASE_CE_ENCODER (object);

  switch (prop_id) {
    default:
      break;
  }
}

static void
gst_base_ce_encoder_class_init (GstBaseCEEncoderClass * klass)
{
  GObjectClass *gobject_class = (GObjectClass *) klass;

  GST_DEBUG_CATEGORY_INIT (gst_ce_base_encoder_debug, "gstcebaseencoder", 0,
      "Base CE Encoder Class");

  gobject_class->set_property = gst_base_ce_encoder_set_property;
  gobject_class->get_property = gst_base_ce_encoder_get_property;

  g_object_class_install_property (gobject_class, PROP_A,
      g_param_spec_boolean ("testa", "Test A", "Testing A", FALSE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));


}

static void
gst_base_ce_encoder_class_finalize (GstBaseCEEncoderClass * klass,
    gpointer * class_data)
{
}

/* Obtain the type of the class */
GType
gst_base_ce_encoder_get_type (void)
{
  static GType object_type = 0;

  static const GTypeInfo object_info = {
    sizeof (GstBaseCEEncoderClass),
    (GBaseInitFunc) gst_base_ce_encoder_base_init,
    (GBaseFinalizeFunc) gst_base_ce_encoder_base_finalize,
    (GClassInitFunc) gst_base_ce_encoder_class_init,
    (GClassFinalizeFunc) gst_base_ce_encoder_class_finalize,
    NULL,
    sizeof (GstBaseCEEncoder),
    0,
    NULL,
    NULL
  };

  object_type = g_type_register_static (GST_TYPE_ELEMENT,
      "GstBaseCEEncoder", &object_info, (GTypeFlags) 0);

  return object_type;
};

/** gst_base_ce_encoder_get_output_buffer
 * @base_encoder : a #GstBaseCEEncoder object
 * @size : size for the buffer
 *
 * Returns: a #GstBuffer 
 */
GstBuffer *
gst_base_ce_encoder_get_output_buffer (GstBaseCEEncoder * base_encoder,
    gsize size)
{
  return NULL;
}

void
gst_base_ce_encoder_shrink_output_buffer (GstBaseCEEncoder * base_encoder,
    GstBuffer * buffer, gsize new_size)
{
}

void
gst_base_ce_encoder_encode (GstBaseCEEncoder * base_encoder,
    GstBuffer * input_buffer, GstBuffer * output_buffer)
{
}
