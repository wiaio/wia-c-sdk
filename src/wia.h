//
// wia.h
//
// Copyright (c) 2017 Wia Technologies Limited
//

#ifndef WIA_H
#define WIA_H 1

/**
 * Return codes.
 */

typedef enum {
  WIA_SUCCESS = 0,
  WIA_MEMORY_ERROR = -1,
  WIA_QUEUE_ERROR = -2
} wia_rc;

/**
 * Wia API method types.
 */

typedef enum {
  WIA_METHOD_EVENT,
  WIA_METHOD_SENSOR
} wia_method_t;

/**
 * Event structure.
 */

typedef struct {
  const char *name;
  const char *data;
} wia_event_t;

/**
 * Create a new event.
 */

wia_event_t *
wia_event_new();

/**
 * Wia.
 */

typedef struct {
  const char *access_token;
  const char *rest_host;
  const char *stream_mqtt_host;
} wia_t;

wia_t *
wia_init(const char *access_token);

void
wia_free(wia_t *self);

int
wia_event_create(wia_t *self, const char *event_name, const char *event_data);

#endif // WIA_H
