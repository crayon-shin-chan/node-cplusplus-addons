// myobject.cc
#include "myobject.h"

namespace demo
{

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Persistent;
using v8::String;
using v8::Value;
/* 声明js类构造函数 */
Persistent<Function> MyObject::constructor;

/* c++类构造函数 */
MyObject::MyObject(double value) : value_(value)
{
}

/* 析构函数 */
MyObject::~MyObject()
{
}

/* 初始化exports */
void MyObject::Init(Local<Object> exports)
{
    Isolate *isolate = exports->GetIsolate();
    /* 使用New方法构建函数模板，New方法使用参数构造c++对象 */
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    /* 函数模板设置类名 */
    tpl->SetClassName(String::NewFromUtf8(isolate, "MyObject"));
    /* 实例模板设置内部字段数量，只有一个_value字段 */
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    /* 设置原型方法plusOne */
    NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);
    /* 构造函数重置为函数模板获取的函数 */
    constructor.Reset(isolate, tpl->GetFunction());
    /* exports到处MyObject为构造函数 */
    exports->Set(String::NewFromUtf8(isolate, "MyObject"),
                 tpl->GetFunction());
}

/* 函数模板的参数，用来构造对象，设置到FunctionCallbackInfo */
void MyObject::New(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* 是否作为构造函数调用 */
    if (args.IsConstructCall())
    {
        double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
        /* 新建一个MyObject对象 */
        MyObject *obj = new MyObject(value);
        /* 使用ObjectWrap的Wrap方法包装回调信息中的this */
        obj->Wrap(args.This());
        /* 设置返回值为this，即new MyObject()这个方法调用返回this */
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        /* 如果不是作为构造函数调用 */
        const int argc = 1;
        Local<Value> argv[argc] = {args[0]};
        Local<Context> context = isolate->GetCurrentContext();
        Local<Function> cons = Local<Function>::New(isolate, constructor);
        Local<Object> result =
            cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

/* 原型方法 */
void MyObject::PlusOne(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    /* Holder好像是方法的隐式参数，即this，调用Unwrap方法获取c++对象 */
    MyObject *obj = ObjectWrap::Unwrap<MyObject>(args.Holder());
    obj->value_ += 1;
    /* 设置返回值 */
    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}

} 
