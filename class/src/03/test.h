#pragma once
#include <iostream>
using namespace std;

namespace ns_class_03
{
  class A
  {
    public:
      int mA;
    public:
      A()
      {
        cout << "A无参构造函数" << endl;
      }
      A(int a)
      {
        mA = a;
        cout << "A有参构造函数" << mA << endl;
      }
      ~A()
      {
        cout << "A析构函数" << mA << endl;
      }
  };

  class B
  {
    public:
      int mB;
      A obA;//对象成员
    public:
      B()
      {
        cout << "B无参构造函数" << endl;
      }
      B(int b)
      {
        mB = b;
        cout << "B有参构造函数" << endl;
      }
      //初始化列表有参构造函数
      B(int a, int b) : obA(a)
      {
        //obA.mA = a;//如果不用初始化列表 : obA(a) 则自动调用A无参构造函数
        mB = b;
        cout << "B初始化列表有参构造函数" << endl;
      }
      ~B()
      {
        cout << "B析构函数" << endl;
      }
  };
}
