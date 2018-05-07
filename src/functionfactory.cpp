#include <node.h>

namespace demo
{
/* v8函数 */
using v8::Function;
using v8::FunctionCallbackInfo;
/* v8函数模板 */
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
/* 模板的回调函数 */
void MyFunction(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world"));
}
/* 创建函数 */
void CreateFunction(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* 使用回调函数创建函数模板 */
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, MyFunction);
    /* 从函数模板获取函数 */
    Local<Function> fn = tpl->GetFunction();
    /* 设置函数名称 */
    fn->SetName(String::NewFromUtf8(isolate, "theFunction"));
    /* 设置函数为返回值 */
    args.GetReturnValue().Set(fn);
}

void Init(Local<Object> exports, Local<Object> module)
{
    NODE_SET_METHOD(module, "exports", CreateFunction);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}
