n = 10**9-1
sum = 0
start = as.numeric(Sys.time())
for (i in 0:n) {
    if (((runif(1,0,1)-1)**2 + (runif(1,0,1)-1)**2) <=1) {
        sum = sum + 1
    }
}
pi = 4 * sum / n
stop = as.numeric(Sys.time())
cat(pi, 'Time:', stop - start, '\n')