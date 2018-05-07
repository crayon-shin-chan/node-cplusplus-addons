
// myobject.h
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include <node_object_wrap.h>

namespace demo
{
/* c++类继承了node的对象包装类 */
class MyObject : public node::ObjectWrap
{
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit MyObject(double value = 0);
    ~MyObject();

    static void New(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void PlusOne(const v8::FunctionCallbackInfo<v8::Value> &args);
    /* 构造函数，为静态属性，一个v8函数 */
    static v8::Persistent<v8::Function> constructor;
    /* 包含一个double值 */
    double value_;
};

} // namespace demo

#endif