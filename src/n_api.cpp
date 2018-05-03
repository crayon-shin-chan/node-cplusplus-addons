/* 导入头文件不同，N-API可以保证向后兼容，v8不能保证 */
#include <node_api.h>
#include <iostream>

namespace demo
{

/* c++方法，与node.h中API不同：
   1.有返回值，类型为napi_value，里面存储了返回值
   2.参数为env与args，其中env对应了node.hAPI中的Isolate */
napi_value Method(napi_env env, napi_callback_info args)
{
    std::cout << "进入N-API方法" << std::endl;
    napi_value greeting;
    napi_status status;
    /* 不过还不太清楚，为什么创建一个值需要使用env参数，可能代表作用域的意思 */
    status = napi_create_string_utf8(env, "hello", NAPI_AUTO_LENGTH, &greeting);
    if (status != napi_ok)
        return nullptr;
    return greeting;
}

/* 在exports上注册函数 */
napi_value init(napi_env env, napi_value exports)
{
    napi_status status;
    napi_value fn;
    /* 将函数存储为napi_value */
    status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
    if (status != napi_ok)
        return nullptr;
    /* 将napi_value设置为exports的hello属性 */
    status = napi_set_named_property(env, exports, "hello", fn);
    if (status != napi_ok)
        return nullptr;
    /* 返回exports */
    return exports;
}
/* 调用导出方法 */
NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

} // namespace demo