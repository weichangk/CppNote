#include "person.h"

namespace ns_class_02
{
  Person::Person()
  {
    age = 0;
    name = "";
    lastName = nullptr;
    cout << "ctor 1." << endl;
  }

  Person::Person(int a, string n, char *str) {
    age = a;
    name = n;
    lastName = new char[strlen(str) + 1];
    strcpy(lastName, str);
    cout << "ctor 2." << endl;
  }

  //拷贝构造函数实现深拷贝
  Person::Person(const Person& p)
  {
    age = p.age;
    name = p.name;
    lastName = new char[strlen(p.lastName) + 1];
    strcpy(lastName, p.lastName);
    cout << lastName << " cpy ctor." << endl;
  }

  Person::~Person()
  {
    cout << name << " Person object is destroyed." << endl;
    if(lastName != nullptr)
    {
      cout << "delete " << lastName << endl;
      delete [] lastName;
    }
  }

  void Person::SetLastName(const char *ln)
  {
    lastName = new char[strlen(ln) + 1];
    strcpy(lastName, ln);
  }
}

