#include "pnums.hpp"

#include <iostream>
#include <string>
#include <chrono>

int main()
{
    pnums::pnum::init();
    srand(time(NULL));
    // auto tGlob = std::chrono::high_resolution_clock::now();
    // for (size_t i = 1; i < 100000; i++)
    // {
    //     if (pnums::pnum::isPrimary(i))
    //         std::cout << "I: " << i << std::endl;
    //     // pnums::pnum::isPrimary(i);
    // }


    auto t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(100000);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(200000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(300000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(400000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(500000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(600000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(700000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(800000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(900000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    t1 = std::chrono::high_resolution_clock::now();
    pnums::pnum::isPrimary(1000000);
    t2 = std::chrono::high_resolution_clock::now();
    ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
    // auto tGlob2 = std::chrono::high_resolution_clock::now();
    // ms_double = tGlob2 - tGlob;
    // std::cout << "Global time elapsed: " << ms_double.count() << "ms\n";
    // pnums::pnum::printEratosthenesSieve(9000);

    return 0;
}