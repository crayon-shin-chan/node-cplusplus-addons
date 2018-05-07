const addon = require('../build/Release/functionfactory.node')
const fn1 = addon()
const fn2 = addon()
console.log(fn1())
console.log(fn2())
/* 函数名称为thefunction */
console.log(fn1.name)
/* 获取的两个函数不相等 */
console.log(fn1 == fn2)