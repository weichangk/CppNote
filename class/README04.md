# explicit关键字
git：https://github.com/weichangk/hellocpp/tree/master/class

## explicit关键字
c++ 提供了关键字explicit，禁止通过构造函数进行的隐式转换，声明为explicit的构造函数不能在隐式转换中使用。
explicit用于修饰构造函数防止隐式转换是针对单参数构造函数（或者除第一个参数外其余参数都有默认值的多参数构造）而言

```
namespace ns_class_04
{
  class A
  {
    public:
      //防止构造函数隐式转换
      explicit A(int a)
      {
        cout << "ns_class_04 A无参构造函数 " << a << endl;
      }
      A(const char* a)
      {
        cout << "ns_class_04 A有参构造函数 " << a << endl;
      }
  };
}

void func04()
{
  cout << "explicit关键字" << endl;
  //ns_class_04::A a = 1; //explicit A(int a) 不能进行构造函数隐式转换
  ns_class_04::A b = "bbb";//A(const char* a) 存在构造函数隐式转换
}
```