cmd_Release/obj.target/napi/src/n_api.o := g++ '-DNODE_GYP_MODULE_NAME=napi' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/czy/.node-gyp/9.10.1/include/node -I/home/czy/.node-gyp/9.10.1/src -I/home/czy/.node-gyp/9.10.1/deps/uv/include -I/home/czy/.node-gyp/9.10.1/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=gnu++0x -MMD -MF ./Release/.deps/Release/obj.target/napi/src/n_api.o.d.raw   -c -o Release/obj.target/napi/src/n_api.o ../src/n_api.cpp
Release/obj.target/napi/src/n_api.o: ../src/n_api.cpp \
 /home/czy/.node-gyp/9.10.1/include/node/node_api.h \
 /home/czy/.node-gyp/9.10.1/include/node/node_api_types.h
../src/n_api.cpp:
/home/czy/.node-gyp/9.10.1/include/node/node_api.h:
/home/czy/.node-gyp/9.10.1/include/node/node_api_types.h:
