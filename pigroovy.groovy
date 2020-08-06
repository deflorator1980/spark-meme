import groovy.time.TimeCategory 
import groovy.time.TimeDuration
long sum = 0
n = 10**9
start = new Date()
0.step n, 1, {
    if (((Math.random()-1)**2 + (Math.random()-1)**2) <= 1) {
        sum++
    }
}
pi = 4 * sum / n
stop = new Date()
td = TimeCategory.minus( stop, start )
println pi + ' ' + td
