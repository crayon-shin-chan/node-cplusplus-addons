#include <node.h>
#include <iostream>
namespace demo
{
/* 方法回调信息，用来设置返回值等 */
using v8::FunctionCallbackInfo;
/* v8隔离区 */
using v8::Isolate;
/* 值句柄 */
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

/* c++中执行方法，使用FunctionCallbackInfo来传递参数，设置返回值，获取v8上下文等 */
void Method(const FunctionCallbackInfo<Value> &args)
{
    std::cout << "进入c++方法" << std::endl;
    /* 获取v8隔离区指针 */
    Isolate *isolate = args.GetIsolate();
    /* 设置返回值 */
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

/* 将c++方法设置为exports的hello属性 */
void init(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "hello", Method);
}

/* 在指定模块名上调用注册方法，模块名必须匹配c++编译后的二进制文件名 
这是语句？还是宏？后面没有分号 */
NODE_MODULE(NODE_GYP_MODULE_NAME, init)
}