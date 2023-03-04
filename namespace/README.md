# namespace 命名空间
git：https://github.com/weichangk/hellocpp/tree/master/namespace

在 C++ 中， 名称可以是符号常量、变量、宏、函数、结构、枚举、类和对象等等，为了避免在大规模程序设计中以及在使用各种各样的 C++ 库时这些标识符的命名发生冲突，C++ 增加了命名空间的概念，命名空间是指标识符的各种可见范围，可以更好的控制标识符的作用域。

标准化后的 C++ 还统一了 C++ 头文件的各种后缀名，例如 .h、.hpp、.hxx 等。标准化之前的头文件就是带后缀名的文件，标准化后的头文件就是不带后缀名的文件。C++ 98 规定用户应使用新版头文件，对旧版本头文件不再进行强制规范，但大多数编译器厂商依然提供旧版本头文件，以求向下兼容。

std 是 C++ 标准命名空间，C++ 标准程序库中的所有标识符都被定义在 std 中。

比如要使用标准输出函数 cout，对于标准化之后 iostream 头文件，要声明使用std命名空间
```
#include "iotream"
using namespace std;
cout << "hello namespace" << endl;
```
而对于标准化之前的头文件iostream.h，则直接使用
```
#include <iostream.h>
cout << "hello namespace" << endl;
```

## c 中的命名空间
在 c 语言中只有一个全局作用域，c 语言中所有的全局标识符共享同一个作用域，标识符之间可能发生冲突。

## c++ 命名空间
命名空间将全局作用域分为不同的部分，不同命名空间中的标识符可以同名而不会发生冲突，命名空间可以嵌套，全局作用域也叫默认命名空间。

## 命名空间定义与使用
1. 不同文件存在相同命名空间
2. 命名空间嵌套
3. 命名空间别名

```
#pragma once

namespace namespace_test1
{
  class Test
  {
    public:
      Test();
      ~Test();
      void foo();
  };
}

namespace namespace_test2
{
  void foo();

  namespace namespace_test3
  {
    void foo();
  }
}

```
```
#pragma once

namespace namespace_test2
{
  void foo2();
}

namespace namespace_test3
{
  void foo3();
}

```
```
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

```





