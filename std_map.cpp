#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
  map<string,int> name_score;
  pair<map<string,int>::iterator,bool> iter_bool_0 = name_score.insert(pair<string,int>("Aoi",100));
  pair<map<string,int>::iterator,bool> iter_bool_1 = name_score.insert(pair<string,int>("Aoi",90));
  pair<map<string,int>::iterator,bool> iter_bool_2 = name_score.insert(pair<string,int>("Sora",100));

  cout<< (iter_bool_0.second == true ? "true" : "false" )<<endl;
  cout<< (iter_bool_1.second == true ? "true" : "false" )<<endl;
  cout<< (iter_bool_2.second == true ? "true" : "false" )<<endl;

  name_score["Sora"] = 90;
  name_score["ZZang"] = 20;
  name_score["ZZang"] += 20;

  cout<<"total size of name_score is "<<name_score.size()<<endl;
  for(auto i : name_score)
  {
    cout<<i.first<<" : "<<i.second<<endl;
  }
  //접근
  int sora_value = name_score["Sora"];
  map<string,int>::iterator iterator_ = name_score.find("ZZang");
  
  turn 0;
}
