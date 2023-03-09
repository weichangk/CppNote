#include "section_01.h"
#include <iostream>
using namespace std;
namespace ns_section_01
{
  //函数参数传递方式:
  //1.值传递
  void changeValue(int n) {
    n = 100;
  }
  void func01() {
    int a = 10;
    changeValue(a);
    cout << a << endl; // 输出 10
  }
  //2.引用传递
  void changeValueByRef(int& n) {
    n = 100;
  }
  void func02() {
    int a = 10;
    changeValueByRef(a);
    cout << a << endl; // 输出 100
  }
  //3.指针传递
  void changeValueByPtr(int* n)
  {
    *n = 100;
  }
  void func03()
  {
    int a = 10;
    changeValueByPtr(&a);
    cout << a << endl; // 输出 100
  }
}
