// Code goes here
var moment = require('moment');
var sum = 0;
var n = 10**9;
var start = moment();
for (var i=0; i<n; i++) {
  if (((Math.random()-1)**2 + (Math.random()-1)**2)<= 1) {
    sum++;
  }
}
var pi = 4 * sum / n;   
console.log(pi, 'Time:', moment.utc(moment(new Date()).diff(moment(start))).seconds()) 