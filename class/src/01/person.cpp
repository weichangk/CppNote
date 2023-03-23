#include "person.h"
#include <iostream>
using namespace std;

namespace ns_class_01
{
  Person::Person()
  {
  }
  Person::~Person()
  {
  }
  void Person::PersonInit(char *name, int age)
  {
    strcpy(mName, name);
    mAge = age;
  }
  void Person::SetAge(int age)
  {
    mAge = age;
  }
  void Person::SetName(char *name)
  {
    strcpy(mName, name);
  }
  char* Person::GetName()
  {
    return mName;
  }
  void Person::ShowPerson()
  {
    cout << "name:" << mName << ", age:" << mAge << endl;
  }
}

