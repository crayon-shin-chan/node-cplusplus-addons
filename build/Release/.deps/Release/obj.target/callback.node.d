cmd_Release/obj.target/callback.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=callback.node -o Release/obj.target/callback.node -Wl,--start-group Release/obj.target/callback/src/callback.o -Wl,--end-group 