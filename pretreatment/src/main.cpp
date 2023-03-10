#include "iostream"
// #include "section_01.h"
// #include "section_02.h"
#include "section_03.h"
using namespace std;

extern int va;
extern int getG(void);
extern int getO(void);

int main(int argc, char const *argv[])
{
  cout << "hello pretreatment" << endl;

  int a = getO();
  cout << a <<endl;//2
  int b = getG();
  cout << b <<endl;//10
  cout << va <<endl;//1
  cout << va*a*b <<endl;//1*2*10

  int c = SQUARE(5);
  cout << c <<endl;//25
  #undef HAHA
  #ifdef HAHA
  int d = MY_MUL(10 + 10, 20 + 20);
  cout << d <<endl;//230
  #endif
}
