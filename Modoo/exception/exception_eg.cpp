#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
void function1(int i)
{
  if( i == 0 )
    throw std::underflow_error("under flow error at function1");
  else
    cout<<"function1 complete!!!"<<endl;
}
void function2(int i)
{
  if ( i == 0 )
    throw string("string error at function2");
  else
    cout<<"function2 complete!!!"<<endl;
}
void function3(int i)
{
  if ( i == 0 )
    throw 1;
  else
    cout<<"function3 complete!!!"<<endl;
}
void function4(int i, int j, int k)
{
  function1(i);
  function2(j);
  function3(k);
  cout<<"function4 complete!!!"<<endl;
}

int main() {
  int i, j ,k= 0;
  cin >> i >> j >> k;
  try {
    function4( i , j ,k);
  } catch (std::exception& e) {
    cout << e.what() << endl;
  } catch (string s){
    cout<< s <<endl;
  } catch (...){
    cout<<"default exception"<<endl;
  }

  return 0;
  // 예외가 발생하지 않았다면 3을 이 출력되고, 예외가 발생하였다면 원래 data 에
  // 들어가 있던 0 이 출력된다.
}