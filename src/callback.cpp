#include <node.h>

namespace demo {

/* v8函数 */
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Null;
using v8::Object;
using v8::String;
using v8::Value;

/* 运行js函数的c++函数 */
void RunCallback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  /* 传入参数转换为v8函数 */
  Local<Function> cb = Local<Function>::Cast(args[0]);
  /* 整数值 */
  const unsigned argc = 1;
  /* 转换为v8Local句柄，v8中所有操作都是通过Local进行的，为了垃圾回收 */
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
  /* 调用v8函数，传入参数数量，参数数组，只有这个参数数组展开后作为js函数的参数传入 */
  cb->Call(Null(isolate), argc, argv);
}

/* 这个初始化方法，第一个参数为exports，第二个参数为module对象 */
void Init(Local<Object> exports, Local<Object> module) {
    /* 整个exports为c++方法 */
  NODE_SET_METHOD(module, "exports", RunCallback);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} 
