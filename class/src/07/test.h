#pragma once
#include <iostream>
using namespace std;

namespace ns_class_07
{
  class Singleton {
  public:
    static Singleton* instance; // 静态成员变量声明，用于保存唯一实例的指针
    Singleton() {} // 构造函数私有化，防止外部创建实例
  public:
    static Singleton* getInstance() { // 静态成员函数，用于获取唯一实例的指针
      if (instance == nullptr) { // 如果实例不存在，则创建一个新实例
        instance = new Singleton();
      }
      return instance;
    }
  };

  Singleton* Singleton::instance = nullptr; // 静态成员变量初始化为nullptr
}
