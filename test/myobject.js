const { MyObject } = require('../build/Release/myobject.node')

const o1 = new MyObject(23)
const o2 = new MyObject(67)
console.log(o1.plusOne())
console.log(o2.plusOne())