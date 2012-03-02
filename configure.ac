AC_PREREQ(2.60)
AC_CONFIG_MACRO_DIR([m4])

AC_INIT(GStreamer Plug-ins for Texas Instruments SoC using CE, 1.0,
    http://ridgerun.github.com, gst-ti-plugins)

AG_GST_INIT

dnl versions of gstreamer and plugins-base
GST_MAJORMINOR=0.11
GST_REQUIRED=0.11.0
GSTPB_REQUIRED=0.11.0

AM_INIT_AUTOMAKE([-Wno-portability 1.10])

dnl define PACKAGE_VERSION_* variables 
AS_VERSION

dnl make aclocal work in maintainer mode
AC_SUBST(ACLOCAL_AMFLAGS, "-I m4")

AM_CONFIG_HEADER(config.h)

dnl check for tools
AC_PROG_CC
AC_PROG_LIBTOOL

dnl decide on error flags
                                                                                
if test "x$GST_WALL" = "xyes"; then
   GST_ERROR="$GST_ERROR -Wall"
                                                                                
fi

dnl Check for pkgconfig first
AC_CHECK_PROG(HAVE_PKGCONFIG, pkg-config, yes, no)

dnl Give error and exit if we don't have pkgconfig
if test "x$HAVE_PKGCONFIG" = "xno"; then
  AC_MSG_ERROR(you need to have pkgconfig installed !)
fi

dnl Now we're ready to ask for gstreamer libs and cflags
dnl And we can also ask for the right version of gstreamer

PKG_CHECK_MODULES(GST, \
  gstreamer-$GST_MAJORMINOR >= $GST_REQUIRED,
  HAVE_GST=yes,HAVE_GST=no)

dnl Give error and exit if we don't have gstreamer
if test "x$HAVE_GST" = "xno"; then
  AC_MSG_ERROR(you need gstreamer development packages installed !)
fi

dnl append GST_ERROR cflags to GST_CFLAGS
GST_CFLAGS="$GST_CFLAGS $GST_ERROR"

dnl make GST_CFLAGS and GST_LIBS available
AC_SUBST(GST_CFLAGS)
AC_SUBST(GST_LIBS)

dnl make GST_MAJORMINOR available in Makefile.am
AC_SUBST(GST_MAJORMINOR)

dnl If we need them, we can also use the base class libraries
PKG_CHECK_MODULES(GST_BASE, gstreamer-base-$GST_MAJORMINOR >= $GST_REQUIRED,
                  HAVE_GST_BASE=yes, HAVE_GST_BASE=no)

dnl Give a warning if we don't have gstreamer libs
dnl you can turn this into an error if you need them
if test "x$HAVE_GST_BASE" = "xno"; then
  AC_MSG_NOTICE(no GStreamer base class libraries found (gstreamer-base-$GST_MAJORMINOR))
fi

dnl make _CFLAGS and _LIBS available
AC_SUBST(GST_BASE_CFLAGS)
AC_SUBST(GST_BASE_LIBS)

dnl set the plugindir where plugins should be installed
if test "x${prefix}" = "x$HOME"; then
  plugindir="$HOME/.gstreamer-$GST_MAJORMINOR/plugins"
else
  plugindir="\$(libdir)/gstreamer-$GST_MAJORMINOR"
fi
AC_SUBST(plugindir)

dnl set proper LDFLAGS for plugins
GST_PLUGIN_LDFLAGS='-module -avoid-version -export-symbols-regex [_]*\(gst_\|Gst\|GST_\).*'
AC_SUBST(GST_PLUGIN_LDFLAGS)

platform=no
AC_ARG_WITH(platform,
  [AS_HELP_STRING([--with-platform=<platform>],
    [Select a target platform. Options available: dm36x])],
  [platform=$withval]
)

if test "x${platform}" = "xno" ; then
    AC_MSG_ERROR([no platform defined, please use --with-platform])
fi
HAVE_CODECS=no

if test "x${platform}" = "xdm36x" ; then
    AC_MSG_NOTICE([Configuring for DM36x SoC])
    PKG_CHECK_MODULES(CODECS, libdm36x-codecs >= 1.0,
                  HAVE_CODECS=yes, HAVE_CODECS=no)

    if test "x$HAVE_CODECS" = "xno" ; then
      AC_MSG_ERROR([no DM36x codec libraries found (libdm36x-codecs)])
    fi

    AC_SUBST(CODECS_CFLAGS)
    AC_SUBST(CODECS_LIBS)
fi

if test "x$HAVE_CODECS" = "xno" ; then
    AC_MSG_ERROR([no codec library know for the platform ${platform}])
fi

AC_OUTPUT(Makefile m4/Makefile gst/Makefile gst/ti/Makefile gst-libs/Makefile gst-libs/gst/Makefile gst-libs/gst/cmem/Makefile)
