cmd_Release/obj.target/add.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=add.node -o Release/obj.target/add.node -Wl,--start-group Release/obj.target/add/src/add.o -Wl,--end-group 
