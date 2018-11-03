#include <iostream>
#include <vector>

typedef std::vector< int,std::vector<int,int> > studentID_List;
typedef int array[10];
typedef int (*functor)(int,int) ;

int add(int a, int b)
{
    return a+b;
}
int main(int argc, char const *argv[])
{
    array A;
    for(int i = 9; i ; i--)
    {
        A[i] = i;
    }
    for(int i : A)
    {
        std::cout<< i <<" -> "<< A[i] <<std::endl;
    }
    functor Add_function = nullptr;
    Add_function = &add;
    std::cout<<Add_function(2,3)<<std::endl;

    return 0;
}

