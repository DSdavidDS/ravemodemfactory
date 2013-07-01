/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * rmfd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 Zodiac Inflight Innovations
 *
 * Author: Aleksander Morgado <aleksander@lanedo.com>
 */

#ifndef RMFD_PROCESSOR_H
#define RMFD_PROCESSOR_H

#include <glib-object.h>
#include <gio/gio.h>
#include <libqmi-glib.h>
#include <rmf-messages.h>

#define RMFD_TYPE_PROCESSOR            (rmfd_processor_get_type ())
#define RMFD_PROCESSOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), RMFD_TYPE_PROCESSOR, RmfdProcessor))
#define RMFD_PROCESSOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), RMFD_TYPE_PROCESSOR, RmfdProcessorClass))
#define RMFD_IS_PROCESSOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RMFD_TYPE_PROCESSOR))
#define RMFD_IS_PROCESSOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), RMFD_TYPE_PROCESSOR))
#define RMFD_PROCESSOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), RMFD_TYPE_PROCESSOR, RmfdProcessorClass))

#define RMFD_PROCESSOR_FILE "processor-file"

typedef struct _RmfdProcessor RmfdProcessor;
typedef struct _RmfdProcessorClass RmfdProcessorClass;
typedef struct _RmfdProcessorPrivate RmfdProcessorPrivate;

struct _RmfdProcessor {
    GObject parent;
    RmfdProcessorPrivate *priv;
};

struct _RmfdProcessorClass {
    GObjectClass parent;
};

GType rmfd_processor_get_type (void);

/* Create a processor */
void           rmfd_processor_new        (GFile                *file,
                                          GAsyncReadyCallback   callback,
                                          gpointer              user_data);
RmfdProcessor *rmfd_processor_new_finish (GAsyncResult         *res,
                                          GError              **error);


/* Processes the request and gets back a response */
void        rmfd_processor_run        (RmfdProcessor        *processor,
                                       GByteArray           *request,
                                       GAsyncReadyCallback   callback,
                                       gpointer              user_data);
GByteArray *rmfd_processor_run_finish (RmfdProcessor        *processor,
                                       GAsyncResult         *res,
                                       GError              **error);

#endif /* RMFD_PROCESSOR_H */
