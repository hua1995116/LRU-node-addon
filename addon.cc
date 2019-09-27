#include <napi.h>
#include "list.h"


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return List::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)

