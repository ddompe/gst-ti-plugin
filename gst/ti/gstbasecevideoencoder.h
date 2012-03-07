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

#ifndef ___GST_BASE_CE_VIDEO_ENCODER_H__
#define ___GST_BASE_CE_VIDEO_ENCODER_H__

#include <glib-object.h>
#include <gstbaseceencoder.h>

G_BEGIN_DECLS
#define GST_TYPE_BASE_CE_VIDEO_ENCODER \
  (gst_base_ce_video_encoder_get_type())
#define GST_BASE_CE_VIDEO_ENCODER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_BASE_CE_VIDEO_ENCODER,GstBaseCEVideoEncoder))
#define GST_BASE_CE_VIDEO_ENCODER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_BASE_CE_VIDEO_ENCODER,GstBaseCEVideoEncoderClass))
#define GST_IS_BASE_CE_VIDEO_ENCODER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_BASE_CE_VIDEO_ENCODER))
#define GST_IS_BASE_CE_VIDEO_ENCODER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_BASE_CE_VIDEO_ENCODER))

typedef struct _GstBaseCEVideoEncoder GstBaseCEVideoEncoder;
typedef struct _GstBaseCEVideoEncoderClass GstBaseCEVideoEncoderClass;

struct _GstBaseCEVideoEncoder
{
  GstBaseCEEncoder base_encoder;
};

struct _GstBaseCEVideoEncoderClass
{
  GstBaseCEEncoderClass parent_class;

  /* Set caps function */
  void (*set_caps) (GstPad * pad, GstObject * parent, GstQuery * query);
};

/* Class functionality */
GType gst_base_ce_video_encoder_get_type (void);

#endif /* ___GST_BASE_CE_VIDEO_ENCODER_H__ */
