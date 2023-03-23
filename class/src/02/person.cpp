#include "person.h"

namespace ns_class_02
{
  Person::Person()
  {
    age = 0;
    name = "";
  }

  Person::Person(int a, string n) {
    age = a;
    name = n;
  }
  Person::~Person()
  {
    cout << "Person object is destroyed." << endl;
  }
}

