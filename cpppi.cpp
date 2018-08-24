#include <iostream>
#include <math.h>
#include <chrono>

int main()
{
    long n = pow(10,9);
    double sum = 1;
    auto start = std::chrono::system_clock::now();
    double coefficient = -1;
    
    for ( long i(1); i != n; i++ ) {
        sum += coefficient / ( i * 2 + 1 );
        coefficient *= -1;
    }
    
    double pi = sum * 4;
    
    
    auto end = std::chrono::system_clock::now();

    
    std::chrono::duration<double> diff = end-start;
<<<<<<< HEAD
    std::cout << pi << " Time: " << diff.count() << std::endl;
=======
    std::cout << pi << " Time: " << diff.count();
>>>>>>> 5cf68241005f0be7ed9fbfbb4d8a55a63432c0bd

}
