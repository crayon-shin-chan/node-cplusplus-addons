const napi = require('../build/Release/napi.node')
console.log(napi.hello())
console.dir(napi.hello.toString())