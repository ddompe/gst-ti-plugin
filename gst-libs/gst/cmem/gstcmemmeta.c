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

#include "gstcmemmeta.h"

/**
 * SECTION:gstcmemmeta
 * @short_description: Contiguous memory (CMEM) metadata
 *
 * This meta data is used to abstract hardware accelerated buffers (in the
 * sense that they can be shared with hardware subsystems that does not 
 * support MMU).
 */

const GstMetaInfo *
gst_cmem_meta_get_info (void)
{
  static const GstMetaInfo *meta_info = NULL;

  if (meta_info == NULL) {
    meta_info = gst_meta_register ("GstCMEMMeta", "GstCMEMMeta",
        sizeof (GstCMEMMeta),
        (GstMetaInitFunction) NULL,
        (GstMetaFreeFunction) NULL,
        (GstMetaCopyFunction) NULL, 
        (GstMetaTransformFunction) NULL);
  }
  return meta_info;
}
