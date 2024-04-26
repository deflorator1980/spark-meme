# Get current time
set start [clock seconds]

# Initialize sum and n
set sum 0
set n [expr {10**7}]

# Loop from 0 to n-1
for {set i 0} {$i < $n} {incr i} {
    # Generate random numbers between 0 and 1 using built-in rand()
    set x [expr {rand() - 1.0}]
    set y [expr {rand() - 1.0}]
    
    # Check if the point falls within the unit circle
    if {($x*$x + $y*$y) <= 1.0} {
        incr sum
    }
}

# Calculate pi
set pi [expr {4.0 * $sum / $n}]

# Get current time again
set stop [clock seconds]

# Calculate elapsed time
set elapsed [expr {$stop - $start}]

# Print the result
puts "pi = $pi, Time: ${elapsed} seconds"
