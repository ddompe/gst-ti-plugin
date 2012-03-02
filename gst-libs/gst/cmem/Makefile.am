
lib_LTLIBRARIES = libgstbasecmem-@GST_MAJORMINOR@.la

libgstbasecmem_@GST_MAJORMINOR@_la_SOURCES = \
	gstcmemmeta.c                        \
	gstcmemallocator.c

libgstbasecmem_@GST_MAJORMINOR@includedir = $(includedir)/gstreamer-@GST_MAJORMINOR@/gst/cmem
libgstbasecmem_@GST_MAJORMINOR@include_HEADERS = \
	gstcmemmeta.h

libgstbasecmem_@GST_MAJORMINOR@_la_CFLAGS = $(GST_CFLAGS) $(CODEC_CFLAGS)
libgstbasecmem_@GST_MAJORMINOR@_la_LIBADD = $(GST_LIBS) $(CODEC_LIBS)

noinst_HEADERS = gstcmemallocator.h