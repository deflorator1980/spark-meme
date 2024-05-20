<?php
function randomFloat($min = 0, $max = 1) {
    return $min + mt_rand() / mt_getrandmax() * ($max - $min);
}

$n = pow(10, 9);
$sum = 0;

$start = microtime(true);

for ($i = 0; $i < $n; $i++) {
    if ((pow(randomFloat() - 1, 2) + pow(randomFloat() - 1, 2)) <= 1) {
        $sum++;
    }
}

$pi = 4 * $sum / $n;

$stop = microtime(true);
$duration = $stop - $start;

echo $pi . " Time: " . $duration . " seconds\n";
?>
