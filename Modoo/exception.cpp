#include <iostream>

float divide(float a, float b)
{
    return (b==0) ? NULL : a/b;
}
int main(int argc, char const *argv[])
{
    std::cout<<divide(12.0,2)<<std::endl;
    std::cout<<divide(10.0,0.0)<<std::endl;
    return 0;
}
