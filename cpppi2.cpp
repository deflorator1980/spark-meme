//g++  5.4.0

#include <random>
#include <iostream>
#include <math.h>
#include <chrono>

int main()
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    long n = pow(10,9);
    double sum = 1;
    auto start = std::chrono::system_clock::now();
    double coefficient = -1;
    
    for ( long i(1); i != n; i++ ) {
        if((pow(dis(gen)-1, 2) + pow(dis(gen)-1, 2)) <=1) {
            sum++;
        }
    }
    
    double pi = sum * 4;
    
    auto end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> diff = end-start;
    std::cout << pi << " Time: " << diff.count() << std::endl;
    
}