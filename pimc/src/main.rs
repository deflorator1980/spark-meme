extern crate rand;

use rand::distributions::{IndependentSample, Range};
use std::time::{Instant};


fn main() {
    let between = Range::new(-1f64, 1.);
    let mut rng = rand::thread_rng();
    let total = 1_00_000_000;
    let now = Instant::now();
    let in_circle: i32 = (0..total)
        .map(|_| (
                between.ind_sample(&mut rng),
                between.ind_sample(&mut rng)
                ))
        .map(|(a, b)| if a*a + b*b <= 1. { 1 } else { 0 })
        .sum();
    // prints something close to 3.14159...
    let new_now = Instant::now();
    println!("{:?}", new_now.duration_since(now));
    println!("{}", 4. * (in_circle as f64) / (total as f64));
}
