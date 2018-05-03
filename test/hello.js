const addon = require('../build/Release/hello.node')
console.log(addon.hello())
console.dir(addon.hello.toString())