
//
// wia.c
//
// Copyright (c) 2017 Wia Technologies Limited
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdio.h>
#include <curl/curl.h>

#include "wia.h"

/**
 * Initialize with `access_token`.
 */

wia_t *
wia_init(const char *access_token) {
  assert(access_token);

  wia_t *self;
  if (!(self = malloc(sizeof(wia_t)))) {
    return NULL;
  }

  self->access_token = access_token;
  self->rest_host = "https://api.wia.io";
  self->stream_mqtt_host = "mqtts://api.wia.io";

  return self;
}

/**
 * Create a new event.
 */

wia_event_t *
wia_event_new() {
  wia_event_t *event;

  if (!(event = malloc(sizeof(wia_event_t)))) {
    return NULL;
  }

  event->name = NULL;
  event->data = NULL;

  return event;
}

/**
 * Free up analytics after use.
 */

void
wia_free(wia_t *self) {
  free(self);
  self = NULL;
}

int
wia_event_create(wia_t *self, const char *event_name, const char *event_data) {
  wia_event_t *event = wia_event_new();

  if (!event) {
    return WIA_MEMORY_ERROR;
  }

  event->name = event_name;
  event->data = event_data;

  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if (curl) {
    char authorization_header[80];
    strcpy(authorization_header, "Authorization: Bearer ");
    strcat(authorization_header, self->access_token);

    struct curl_slist *headers = NULL;

    headers = curl_slist_append(headers, authorization_header);

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, "http://api.wia.io/v1/events");

    char post_fields[256];
    strcpy(post_fields, "name=");
    strcat(post_fields, event_name);
    strcat(post_fields, "&data=");
    strcat(post_fields, event_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields);

    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  return WIA_SUCCESS;
}
