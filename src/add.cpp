#include <node.h>

namespace demo
{

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

/* js参数通过FunctionCallbackInfo<Value>引用传递 */
void Add(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* 参数长度 */
    if (args.Length() < 2)
    {
        /* 抛出js异常，其中TypeError代表了js中的对应异常 */
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }
    /* 检查参数类型 */
    if (!args[0]->IsNumber() || !args[1]->IsNumber())
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
    }
    /* 参数相加，转换为Number句柄 */
    double value = args[0]->NumberValue() + args[1]->NumberValue();
    Local<Number> num = Number::New(isolate, value);
    /* 设置返回值 */
    args.GetReturnValue().Set(num);
}

/* 初始化方法 */
void Init(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "add", Add);
}

/* 调研初始化方法 */
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}