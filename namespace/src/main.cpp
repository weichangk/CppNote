#include "iostream"
#include "test"
#include "test1"
using namespace std;

/*
test文件存在命名空间（不同命名空间有相同函数（标识符））
namespace_test1
namespace_test2
namespace_test2嵌套namespace_test3
每个命名空间都存在foo函数


test1文件存在命名空间（不同文件存在相同命名空间）
namespace_test2 有foo2函数
namespace_test3 有foo3函数
*/

using namespace namespace_test1;

using namespace namespace_test3;//当存在被嵌套同名命名空间时，引用该命名空间要写在嵌套了该命名空间的命名空间之前！！！

using namespace namespace_test2;

namespace namespace_test2_namespace_test3 = namespace_test2::namespace_test3;//命名空间嵌套
using namespace namespace_test2_namespace_test3;//命名空间别名


int main(int argc, char const *argv[])
{
  cout << "hello namespace" << endl;

  Test t;
  t.foo();
  //foo();//有重载namespace_test2::foo() 和 namespace_test2::namespace_test3::foo()
  namespace_test2_namespace_test3::foo();

  foo2();
  foo3();
}
