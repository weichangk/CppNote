# 初始化列表
git：https://github.com/weichangk/hellocpp/tree/master/class

## 对象成员
在类中定义的数据成员一般是基本的数据成员，但是类中的成员也可以是对象，叫做对象成员
先调用对象成员的构造函数，再调用本身的构造函数；先调用自身析构函数，再调用对象成员析构函数


## 初始化列表
类想要调用对象成员有参构造函数就可以使用初始化列表

```
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
        cout << "A有参构造函数" << endl;
      }
      ~A()
      {
        cout << "A析构函数" << endl;
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

```
