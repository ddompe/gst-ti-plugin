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

#ifndef _GST_BASE_CE_ENCODER_H_
#define _GST_BASE_CE_ENCODER_H_

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_TYPE_BASE_CE_ENCODER \
  (gst_base_ce_encoder_get_type())
#define GST_BASE_CE_ENCODER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_BASE_CE_ENCODER,GstBaseCEEncoder))
#define GST_BASE_CE_ENCODER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_BASE_CE_ENCODER,GstBaseCEEncoderClass))
#define GST_IS_BASECEENC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_BASE_CE_ENCODER))
#define GST_IS_BASE_CE_ENCODER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_BASE_CE_ENCODER))

typedef struct _GstBaseCEEncoder GstBaseCEEncoder;
typedef struct _GstBaseCEEncoderClass GstBaseCEEncoderClass;

/**
 * GstBaseCEEncoder:
 */
struct _GstBaseCEEncoder
{
  GstElement element;

  GstPad *sink_pad;
  GstPad *src_pad;
  
  /* Members for encode process */
  char          *codec_name;
  gpointer      codec_handle;
  gpointer      codec_params;
  gpointer      codec_dynamic_params;
  
  /* Pointers to hold data submitted into CodecEngine */
  gpointer      submitted_input_buffers;
  gpointer      submitted_output_buffers;
  gpointer      submitted_input_arguments;
  gpointer      submitted_output_arguments;

};

struct _GstBaseCEEncoderClass
{
  GstElementClass parent_class;

#if 0  
  /* Extend properties manipulate functions */
  void      (set_extend_property) (GObject * object, guint prop_id, const GValue * value, GParamSpec * pspec);
  void      (get_extend_property) (GObject * object, guint prop_id, const GValue * value, GParamSpec * pspec);
#endif
  
  /* Virtual functions for CE API */
  void      (*encoder_alloc_params) (GstBaseCEEncoder *base_encoder);
  void      (*encoder_free_params) (GstBaseCEEncoder *base_encoder);
  gint32    (*encoder_control) (GstBaseCEEncoder *base_encoder);
  void 		  (*encoder_delete) (GstBaseCEEncoder *base_encoder);
  gpointer  (*encoder_create) (GstBaseCEEncoder *base_encoder);
  gint32	  (*encoder_process_async) (GstBaseCEEncoder *base_encoder, GstBuffer *input_buffer, GstBuffer *output_buffer);
  gint32  	(*encoder_process_wait) (GstBaseCEEncoder *base_encoder);
};

GType gst_base_ce_encoder_get_type (void);

/* Class functionality */
GstBuffer *   gst_base_ce_encoder_get_output_buffer(GstBaseCEEncoder *base_encoder, gsize size);
void          gst_base_ce_encoder_shrink_output_buffer(GstBaseCEEncoder *base_encoder, GstBuffer *buffer, gsize new_size);
void          gst_base_ce_encoder_encode(GstBaseCEEncoder *base_encoder, GstBuffer *input_buffer, GstBuffer *output_buffer);

G_END_DECLS

#endif
