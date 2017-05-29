# Wia C SDK

Note: This is still in beta and should not be used in production.

# Development
```
$ make test
$ ./test
```

# Example
```c
#include <stdlib.h>
#include <assert.h>
#include "src/wia.h"

int
main(void){
  wia_t *wia = wia_init("d_sk_uiaqbNd9MwnyFuDLLxNxwvIx");
  assert(wia);

  int rc = wia_event_create(wia, "testEvent", "21.5");
  assert(rc == WIA_SUCCESS);

  wia_free(wia);
  return 0;
}
```

# License

This SDK is distributed under the the MIT License

Copyright (c) 2010-2017 Wia Technologies Limited. http://wia.io

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
