
#include <stdlib.h>
#include <assert.h>
#include "src/wia.h"

int
printData(void){
  printf("GOt here");
  return 0;
}

int
main(void){
  wia_t *wia = wia_init("d_sk_uiaqbNd9MwnyFuDLLxNxwvIx");
  assert(wia);

  int rc = wia_event_create(wia, "testEvent", "21.5", printData);
  assert(rc == WIA_SUCCESS);

  wia_free(wia);
  return 0;
}
