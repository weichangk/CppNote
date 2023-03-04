#include "test"
#include "iostream"
using namespace std;

namespace namespace_test1
{
  Test::Test()
  {
    cout << "test ctor" << endl;
  }

  Test::~Test()
  {
    cout << "test ~ctor" << endl;
  }

  void Test::foo()
  {
    cout << "namespace_test1 Test foo" << endl;
  }
}

namespace namespace_test2
{
  void foo()
  {
    cout << "namespace_test2 foo" << endl;
  }

  namespace namespace_test3
  {
    void foo()
    {
      cout << "namespace_test2 namespace_test3 foo" << endl;
    }
  }
}
