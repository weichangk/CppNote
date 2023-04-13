#pragma once
#include <iostream>
using namespace std;

namespace ns_class_08
{
  class MyClass01 {
  public:
    int mA;
  };
  class MyClass02 {
  public:
    int mA;
    static int mB;
  };
  class MyClass03 {
  public:
    void printMyClass() {
      cout << "hello class03" << endl;
    }
  public:
    int mA;
    static int mB;
  };
  class MyClass04 {
  public:
    void printMyClass() {
      cout << "hello class04" << endl;
    }
    void showMyClass() {
      cout << "hello class04" << endl;
    }
  public:
    int mA;
    static int mB;
  };
}
