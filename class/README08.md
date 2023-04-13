# c++ 面向对模型
git：https://github.com/weichangk/hellocpp/tree/master/class

## 成员变量和函数的存储
c++实现了“封装”，“数据”和“处理数据的操作（函数）”是分开的存储的。c++中的非静态数据成员直接包含在类对象中，成员函数虽然包含在class内声明，却不包含在对象中。每个非内联成员函数共享一份函数实例
```
class Data
{
  public:
    char a;
    int b;
    static int c;
    void func(){;}
}
```
sizeof(Data)的大小只是a和b所占用的空间大小（类的对象所占空间大小）

## this指针
c++的数据和操作是分开存储的，并且每一个非内敛成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码，那么这一块代码是如何区分哪个对象调用自己的呢？
c++通过提供特殊的对象指针，this指针来解决上面的问题，this指针指向被调用的成员函数所属的对象。
成员函数通过this指针即可知道操作的是那个对象的数据，this指针是一种隐藏指针，在类的非静态成员函数中的数据，this指针可以无需显示。

注意：静态成员函数内部没有this指针，静态成员函数不能操作非静态成员变量

```
//函数形参和成员变量同名可以使用this指针解决
class Data {
public:
  int a;

public:
  void func(int a) {
    this->a = a;
  }
};

//this指针完成链式操作
class Data1 {
public:
  Data1& func(char *str) {
    cout << str << endl;
    return *this;
  }
};
void test()
{
  Data1().func("11").func("22").func("33");
}
```
## const修饰成员函数
用const修饰的成员函数时，const修饰this指针指向的内存区域，成员函数体内不可以修改类中的任何普通成员变量，当成员变量类型符前用mutable修饰时例外
```
class Data {
public:
  int a;
  mutable int b;
public:
  void func(void) const{
    
  }
};
```

