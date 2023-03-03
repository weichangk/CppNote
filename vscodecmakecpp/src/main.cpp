#include <iostream>
#include <vector>
#include <string>
#include "test.h"
using namespace std;


int main(int argc, char const *argv[])
{
  cout << "hello World" << endl;

  testa = 100;
  cout << "testa = "<< testa << endl;

  int v1 = 10;
  int v2 = 20;
  cout << "before swap:" << endl;
  cout << "v1 = "<< v1 << endl;
  cout << "v2 = "<< v2 << endl;
  Test t;
  t.swap(v1, v2);
  cout << "after swap:" << endl;
  cout << "v1 = "<< v1 << endl;
  cout << "v2 = "<< v2 << endl;

  vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
  for (const string& word : msg)
  {
      cout << word << " ";
  }
  return 0;
}
