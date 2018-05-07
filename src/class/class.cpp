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
using v8::Number;

/* 使用工厂模式创建类对象 */
void CreateObject(const FunctionCallbackInfo<Value> &args)
{
    MyObject::NewInstance(args);
}

/* 两个对象相加函数 */
void Add(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* js传递的参数需要Unwrap才能获取c++对象 */
    MyObject *obj1 = node::ObjectWrap::Unwrap<MyObject>(
        args[0]->ToObject());
    MyObject *obj2 = node::ObjectWrap::Unwrap<MyObject>(
        args[1]->ToObject());
    /* 设置返回值 */
    double sum = obj1->value() + obj2->value();
    args.GetReturnValue().Set(Number::New(isolate, sum));
}

/* 将exports初始化为类 */
void InitAll(Local<Object> exports, Local<Object> module)
{
    /* 设置MyObject为导出，必须使用new调用 */
    MyObject::Init(exports);
    /* 设置CreateObject为导出 */
    NODE_SET_METHOD(exports, "CreateObject", CreateObject);
    /* 不是实例方法 */
    NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

} // namespace demo