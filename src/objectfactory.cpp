#include <node.h>

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
/* v8对象，类似于js中的简单对象 */
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

/* 创建对象函数 */
void CreateObject(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* 创建v8句柄时需要传入Isolate实例，与垃圾回收有关 */
    Local<Object> obj = Object::New(isolate);
    /* 简单对象可以直接设置数学 */
    obj->Set(String::NewFromUtf8(isolate, "name"), args[0]->ToString());
    obj->Set(String::NewFromUtf8(isolate, "age"), Number::New(isolate, args[1]->NumberValue()));
    /* 设置返回值为对象 */
    args.GetReturnValue().Set(obj);
}

void Init(Local<Object> exports, Local<Object> module)
{
    NODE_SET_METHOD(module, "exports", CreateObject);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
}