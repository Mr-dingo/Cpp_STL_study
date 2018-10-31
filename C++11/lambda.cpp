#include <iostream>
#include <functional>

using namespace std;

class random_generator{
public:
    int n;
    random_generator(){n = rand()%40;}
};
 
int compare(const void* lhs, const void* rhs)
{
    int a = ((random_generator*)lhs)->n;
    int b = ((random_generator*)rhs)->n;
 
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}
 
int main()
{
    random_generator random_array[40];
//std::function<bool(const void* ,const void* )>

    auto compare2 = [](const void* lhs,const void* rhs)
        ->int 
        {
            int a = ((random_generator*)lhs)->n;
            int b = ((random_generator*)rhs)->n;
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
            else
                return 0;
        };
    qsort(random_array, 40 , sizeof(random_generator), compare2); 
    
    for (int i = 0; i < 40; i++)
        cout << random_array[i].n << endl;
}