
#include <stdlib.h>
#include <assert.h>
#include "src/wia.h"

#include <time.h>

int
main(void){
  wia_t *wia = wia_init("d_sk_uiaqbNd9MwnyFuDLLxNxwvIx");
  assert(wia);

  time_t mytime;
  mytime = time(NULL);

  int rc = wia_event_create(wia, "testEvent", ctime(&mytime));
  assert(rc == WIA_SUCCESS);

  wia_free(wia);
  return 0;
}
