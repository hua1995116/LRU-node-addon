const memoryUsage = require('./helper');
const LRUCache = require('../index');
const cache = new LRUCache(); 
const MAX = 100;
cache.SetMax(MAX);
const buffer = [];
for(let i = 0; i < MAX; i++) {
    buffer.push(i + '');
}
console.time('test');
for(i = 0; i < MAX; i++) {
    cache.Insert(i + '', buffer[i]);
}
for(let j = 0; j < MAX; j++) {
    cache.Search(j + '');
} 

console.timeEnd('test');
memoryUsage();