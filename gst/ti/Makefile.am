plugin_LTLIBRARIES = libgstti_plugin.la

libgstti_plugin_la_SOURCES = gsttiplugin.c \
 gstbaseceencoder.c

libgstti_plugin_la_HEADER = gsttiplugin.h \
 gstbaseceencoder.h

libgstti_plugin_la_CFLAGS = $(GST_CFLAGS)
libgstti_plugin_la_LIBADD = $(GST_LIBS) $(GST_BASE_LIBS)
libgstti_plugin_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstti_plugin_la_LIBTOOLFLAGS = --tag=disable-static
