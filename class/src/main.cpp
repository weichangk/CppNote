#include "iostream"
#include "person.h"
using namespace std;

void func01()
{
  Person lucy;
  lucy.PersonInit("lucy", 18);
  lucy.ShowPerson();
  lucy.SetName("lucy pro");
  cout << lucy.GetName() << endl;
}

int main(int argc, char const *argv[])
{
  cout << "hello class" << endl;
  func01();
}
