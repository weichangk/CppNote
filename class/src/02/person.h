#pragma once
#include <iostream>
using namespace std;

namespace ns_class_02
{
  class Person
  {
  private:
    int age;
    string name;
    char *lastName;
  public:
    Person();
    Person(int a, string n, char *str);
    Person(const Person &p);
    ~Person();
    void SetLastName(const char *ln);
  };
}


