#include <chrono>
#include <iostream>
#include <cmath>
void Test()
{
    for ( long i = 0; i < 10000000; ++i )
    {
        std::sqrt( 123.456L );
    }

}

int main(int argc, char const *argv[])
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    Test();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> sec = end - start;
    std::cout << "Test() function operation time (sec) : " << sec.count() << " seconds" << std::endl;
    std::cout << "Test() function operation time (milisec) : " << std::chrono::duration_cast<std::chrono::milliseconds>(sec).count() << " millisec" << std::endl;
    std::cout << "Test() function operation time (nanosec) : " << std::chrono::duration_cast<std::chrono::nanoseconds>(sec).count() << " nanosec" << std::endl;

    return 0;
}
