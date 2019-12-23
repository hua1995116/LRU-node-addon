const memoryUsage = require('./helper');
const LRU = require("lru-cache");
const MAX = 100;
const cache = new LRU(MAX);

const buffer = [];
for(let i = 0; i < MAX; i++) {
    buffer.push(i + '');
}
console.time('test');
for(i = 0; i < MAX; i++) {
    cache.set(i + '', buffer[i]);
}
for(let j = 0; j < MAX; j++) {
    cache.get(j + '');
} 

console.timeEnd('test');
memoryUsage();
