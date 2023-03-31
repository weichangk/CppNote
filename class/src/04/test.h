#pragma once
#include <iostream>
using namespace std;

namespace ns_class_04
{
  class A
  {
    public:
      //防止构造函数隐式转换
      explicit A(int a)
      {
        cout << "ns_class_04 A无参构造函数 " << a << endl;
      }
      A(const char* a)
      {
        cout << "ns_class_04 A有参构造函数 " << a << endl;
      }
  };

}
