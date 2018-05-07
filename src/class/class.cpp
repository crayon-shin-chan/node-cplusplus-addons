#include <node.h>
#include "myobject.h"

namespace demo
{

using v8::Local;
using v8::Object;
/* 将exports初始化为类 */
void InitAll(Local<Object> exports)
{
    MyObject::Init(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

} // namespace demo