# 类和对象的基本概念
git：https://github.com/weichangk/hellocpp/tree/master/class

## 类和对象的基本概念
C++中的类是一种用户自定义的数据类型，它可以包含数据成员和成员函数。对象是类的实例，它可以访问类的成员函数和数据成员。

类的定义通常包括以下部分：
- 类名：用于标识类的名称。
- 数据成员：类中的变量，用于存储对象的状态。
- 成员函数：类中的函数，用于操作对象的状态。
- 访问控制：用于限制类的成员的访问权限，包括public、private和protected。

对象是类的实例，它可以通过类的构造函数创建。对象可以访问类的成员函数和数据成员，可以使用点运算符来访问类的成员。

类和对象是面向对象编程的基本概念，它们可以帮助程序员更好地组织代码，提高代码的可重用性和可维护性。

### 类的封装性
C++类的封装性是指将类的数据和方法封装在一起，只对外部提供必要的接口，隐藏内部实现细节，保证类的安全性和可维护性。

封装性的实现主要依靠访问控制符，包括public、private和protected。其中，public成员可以被任何对象访问，private成员只能被类内部的成员函数访问，protected成员可以被类内部和派生类的成员函数访问。

通过封装，可以实现以下几个目标：

- 隐藏实现细节，保护数据安全。将数据成员设置为private，只能通过类的公有成员函数来访问和修改数据，避免了外部直接访问和修改数据的风险。

- 简化接口，提高代码可读性。将类的实现细节隐藏起来，只对外部提供必要的接口，使得类的使用更加简单明了。

- 提高代码的可维护性。封装可以使得类的实现细节与外部接口分离，使得修改类的实现细节不会影响到外部接口，从而提高了代码的可维护性。

总之，封装是C++面向对象编程的重要特性之一，它可以提高代码的安全性、可读性和可维护性，是编写高质量代码的必要手段。


### 定义一个类
```
//Data 是一个类型
class Data
{
  //类中成员默认私有
  private:
    int a;
  protected:
    int b;
  public:
    int c;
    void show()
    {
    }
}

int main(int argc, char *argv[])
{
  Data da;
  //对象不能直接访问类私有和保护成员
  //cout << da.a << endl;
  //cout << da.b << endl;
  cout << da.c << endl;
  da.show();
}
```

在头文件定义
```
#pragma once
class Person
{
private:
  char mName[32];
  int mAge;
public:
  Person();
  ~Person();
  void PersonInit(char *name, int age);
  void SetAge(int age);
  void SetName(char *name);
  char* GetName(void);
  void ShowPerson(void);
};
```
在源文件实现
```
#include "person.h"
#include <iostream>
using namespace std;

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

```


