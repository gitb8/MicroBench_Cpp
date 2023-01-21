#include <iostream>
#include <chrono>

// set run repetitions
const int64_t RUNS = 65536;

void func1() {}     // demo function

void func2() {}     // demo function

int main() {
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point end;
    float first;
    float second;
    // std::chrono::_V2::system_clock::rep first;
    // std::chrono::_V2::system_clock::rep second;

    // bench setup
    int64_t a = 0;
    // /bench setup

    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 1st run

        a++;
        // a += 1;          // reverse test

        // bench function
        // func1();
        // func2();          // reverse test

    }   // /1st run
    end = std::chrono::high_resolution_clock::now();
    first = (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // reset bench setup
    a = 0;
    // /reset bench setup

    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 2nd run

        a += 1;
        // a++;             // reverse test

        // bench function
        // func2();
        // func1();          // reverse test

    }   // /2nd run
    end = std::chrono::high_resolution_clock::now();
    second = (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // print result nanoseconds
    // std::cout << "1st run: " << first / (float)RUNS << " ns" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS << " ns" << std::endl;

    // print result microseconds
    std::cout << "1st run: " << first / (float)RUNS / 1000.0f << " µs" << std::endl;
    std::cout << "2nd run: " << second / (float)RUNS / 1000.0f << " µs" << std::endl;

    // print result milliseconds
    // std::cout << "1st run: " << first / (float)RUNS / 1.0e6f << " ms" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS / 1.0e6f << " ms" << std::endl;

    // print result seconds
    // std::cout << "1st run: " << first / (float)RUNS / 1.0e9f << " s" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS / 1.0e9f << " s" << std::endl;
}
