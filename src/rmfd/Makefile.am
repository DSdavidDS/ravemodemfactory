
SUBDIRS = . test

sbin_PROGRAMS      = rmfd
dist_bin_SCRIPTS   = rmfd-port-data-wwan-service
noinst_LTLIBRARIES =

BUILT_SOURCES = \
	rmfd-error-types.h \
	rmfd-error-types.c

CLEANFILES = $(BUILT_SOURCES)

# Stats support
noinst_LTLIBRARIES += librmfd-stats.la
librmfd_stats_la_SOURCES = \
	rmfd-stats.h rmfd-stats.c
librmfd_stats_la_CPPFLAGS = \
	-I$(top_srcdir) \
	$(GLIB_CFLAGS)

# rmfd daemon
rmfd_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/src/librmf-common \
	-I$(top_srcdir)/src/librmf \
	$(GLIB_CFLAGS) \
	$(QMI_CFLAGS) \
	$(GUDEV_CFLAGS)

rmfd_SOURCES = \
	rmfd.c \
	rmfd-utils.h rmfd-utils.c \
	rmfd-syslog.h rmfd-syslog.c \
	rmfd-error.h rmfd-error.c \
	rmfd-error-types.h rmfd-error-types.c \
	rmfd-charsets.h rmfd-charsets.c \
	rmfd-sms-part.h rmfd-sms-part.c \
	rmfd-sms-part-3gpp.h rmfd-sms-part-3gpp.c \
	rmfd-sms.h rmfd-sms.c \
	rmfd-sms-list.h rmfd-sms-list.c \
	rmfd-manager.h rmfd-manager.c \
	rmfd-port.h rmfd-port.c \
	rmfd-port-processor.h rmfd-port-processor.c \
	rmfd-port-processor-qmi.h rmfd-port-processor-qmi.c \
	rmfd-port-data.h rmfd-port-data.c \
	rmfd-port-data-wwan.h rmfd-port-data-wwan.c

rmfd_LDADD = \
	$(top_builddir)/src/librmf/librmf.la \
	$(top_builddir)/src/librmf-common/librmf-common.la \
	$(builddir)/librmfd-stats.la \
	$(GLIB_LIBS) \
	$(QMI_LIBS) \
	$(GUDEV_LIBS)

# Error types & quarks
rmfd-error-types.h: Makefile.am rmfd-error.h $(top_srcdir)/build-aux/rmfd-error-types-template.h
	$(AM_V_GEN) $(GLIB_MKENUMS) \
		--fhead "#ifndef __RMFD_ERROR_TYPES_H__\n#define __RMFD_ERROR_TYPES_H__\n" \
		--template $(top_srcdir)/build-aux/rmfd-error-types-template.h \
		--ftail "#endif /* __RMFD_ERROR_TYPES_H__ */\n" \
		rmfd-error.h > $@

rmfd-error-types.c: Makefile.am rmfd-error.h $(top_srcdir)/build-aux/rmfd-error-types-template.c rmfd-error-types.h
	$(AM_V_GEN) $(GLIB_MKENUMS) \
		--fhead "#include \"rmfd-error.h\"\n#include \"rmfd-error-types.h\"\n" \
		--template $(top_srcdir)/build-aux/rmfd-error-types-template.c \
		rmfd-error.h > $@
