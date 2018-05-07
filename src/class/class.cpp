#include <node.h>
#include "myobject.h"

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

/* 使用工厂模式创建类对象 */
void CreateObject(const FunctionCallbackInfo<Value> &args)
{
    MyObject::NewInstance(args);
}

/* 将exports初始化为类 */
void InitAll(Local<Object> exports, Local<Object> module)
{
    /* 设置MyObject为导出，必须使用new调用 */
    MyObject::Init(exports);
    /* 设置CreateObject为导出 */
    NODE_SET_METHOD(exports, "CreateObject", CreateObject);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

} // namespace demo