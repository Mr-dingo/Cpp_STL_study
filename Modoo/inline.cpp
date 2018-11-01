/*********************************

compile to Assembly : g++ -std=c++11 -S -c -O3 -Winline inline.cpp
compile to output file : g++ -std=c++11 -O3 -Winline inline.cpp

*********************************/

#include <iostream>
template <typename T>
T myInline1(T a, T b)
{
    return (a+b);
}

template <typename T>
inline void myPrint(T a)
{
    std::cout << "value is " <<a<<std::endl;
    return ;
}
inline int www(int a,int b){
    return (a+b);
}
int vvv(int a,int b){
    return (a+b);
}


int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 4;
    auto x = myInline1<int>(a,b);
    www(a,b);
    int zz = vvv(a,b);
    return 0;
}
