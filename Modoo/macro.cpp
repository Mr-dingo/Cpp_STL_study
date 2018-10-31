#include <iostream>

#define myMacro(i) i*2
#define printValue(var) std::cout<<#var" = "<<var<<std::endl;
#define myMacro2(a,b) a##b
int main(int argc, char const *argv[])
{
    int i = myMacro(4+1);
    int x = 10;
    int y = myMacro(x);
    int myMacro2(aoi,sora) = 10;
    printValue(i);
    printValue(x);
    printValue(myMacro2(aoi,sora));
    return 0;
}

