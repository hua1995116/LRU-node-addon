const format = function(bytes) { 
    return (bytes/1024/1024).toFixed(2)+'MB'; 
};

module.exports = function() {
    const mem = process.memoryUsage();
    console.log('Process: heapTotal '+format(mem.heapTotal) + ' heapUsed ' + format(mem.heapUsed) + ' rss ' + format(mem.rss));
}

