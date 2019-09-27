const addon = require('bindings')('addon');

const list = new addon.List();
// list.SetMax(10);

list.Insert(10, 'hello');
list.Insert(11, 'world');
list.Insert(12, 'hi');
// list.Insert(12);
// list.Insert(13);

// console.log(list.getMax());
// console.log(list.Search(10));
console.log(list.Print());