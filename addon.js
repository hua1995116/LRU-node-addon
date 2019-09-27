var addon = require('bindings')('addon');

var fn = new addon.List();
// console.log(fn()); // 'hello world'
// fn.SetMax(10);

fn.Insert(10);
fn.Insert(11);
fn.Insert(12);
// fn.Insert(12);
// fn.Insert(13);

console.log(fn.getMax());
console.log(fn.Search(10));
