math.randomseed(os.time())

n = 10^8

start = os.clock()
p = {}
for i = 1, n do
    table.insert(p, {math.random(), math.random()})
end

count = 0
for i = 1, n do
    if math.sqrt(p[i][1]^2 + p[i][2]^2) < 1 then
        count = count + 1
    end
end

pi = count / n * 4
stop = os.clock()
print(pi, 'Time:', stop - start)
