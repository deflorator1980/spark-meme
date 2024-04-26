#!/bin/bash

sum=0
n=$((10**5))
start=$(date +%s%N)

for (( i=0; i<n; i++ )); do
    x=$(echo "scale=10; ($RANDOM / 32767.0 * 2 - 1)^2" | bc -l)
    y=$(echo "scale=10; ($RANDOM / 32767.0 * 2 - 1)^2" | bc -l)
    if (( $(echo "$x + $y <= 1" | bc -l) )); then
        ((sum++))
    fi
done

pi=$(echo "scale=10; 4 * $sum / $n" | bc -l)
stop=$(date +%s%N)

elapsed=$(echo "scale=2; ($stop - $start) / 1000000" | bc)
echo "pi = $pi, Time: $elapsed ms"
