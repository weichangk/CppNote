#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main(int argc, char const *argv[])
{
  int v1 = 10;
  int v2 = 20;
  cout << "before swap:" << endl;
  cout << "v1 = "<< v1 << endl;
  cout << "v2 = "<< v2 << endl;
  swap(v1, v2);
  cout << "after swap:" << endl;
  cout << "v1 = "<< v1 << endl;
  cout << "v2 = "<< v2 << endl;
  return 0;
}
