cmd_Release/obj.target/napi.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=napi.node -o Release/obj.target/napi.node -Wl,--start-group Release/obj.target/napi/src/n_api.o -Wl,--end-group 
