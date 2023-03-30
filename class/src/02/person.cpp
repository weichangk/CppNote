#include "person.h"

namespace ns_class_02
{
  Person::Person()
  {
    age = 0;
    name = "";
    lastName = nullptr;
  }

  Person::Person(int a, string n, char *str) {
    age = a;
    name = n;
    lastName = new char[strlen(str) + 1];
    strcpy(lastName, str);
  }

  //定义拷贝构造函数
  Person::Person(const Person &p)
  {
    cout << "cpy ctor." << endl;
    age = p.age;
    name = p.name;
    lastName = p.lastName;
  }

  Person::~Person()
  {
    cout << name << " Person object is destroyed." << endl;
    if(lastName != nullptr)
    {
      cout << lastName << endl;
      delete [] lastName;
    }
  }
}

