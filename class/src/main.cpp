#include "iostream"
#include "01/person.h"
#include "02/person.h"
#include "03/test.h"
#include "04/test.h"
#include "07/test.h"
#include "08/test.h"
using namespace std;

void func01()
{
  ns_class_01::Person lucy;
  lucy.PersonInit("lucy", 18);
  lucy.ShowPerson();
  lucy.SetName("lucy pro");
  cout << lucy.GetName() << endl;
}

void func02()
{
  ns_class_02::Person p1;
  p1.SetLastName("p1");                                         //隐式调用无参构造函数（推荐）
  ns_class_02::Person p2 = ns_class_02::Person();               //显示调用无参构造函数
  p2.SetLastName("p2");
  ns_class_02::Person p3(0, "p3", "p3");                        //隐式调用有参构造函数（推荐）
  ns_class_02::Person p4 = ns_class_02::Person(0, "p4", "p4");  //显示调用有参构造函数

  //匿名对象，执行完立即析构，不会等到{}作用域结束才析构。
  ns_class_02::Person().SetLastName("p5");
  ns_class_02::Person(0, "aa", "aa").SetLastName("p6");

  //构造函数 隐式转换（类中只有一个数据成员）
  //ns_class_02::Person p7 = 100;

  //旧对象给新对象初始化调用拷贝构造函数
  //有指针成员，如果不自定义拷贝构造函数会有问题
  ns_class_02::Person p7 = p3;
  p7.SetLastName("p7");
}

void func03()
{
  cout << "对象成员" << endl;
  ns_class_03::B ob1;
  cout << "初始化列表" << endl;
  ns_class_03::B ob2(1, 2);
}

void func04()
{
  cout << "explicit关键字" << endl;
  //ns_class_04::A a = 1; //explicit A(int a) 不能进行构造函数隐式转换
  ns_class_04::A b = "bbb";//A(const char* a) 存在构造函数隐式转换
}

void func05()
{
  cout << "对象数组" << endl;
  //对象数组，每个元素都会自动调用构造
  ns_class_03::A arr1[5];
  ns_class_03::A arr2[5] = {ns_class_03::A(1), ns_class_03::A(2), ns_class_03::A(3), ns_class_03::A(4), ns_class_03::A(5)};
}

void func06()
{
  cout << "动态对象" << endl;
  ns_class_02::Person *p = new ns_class_02::Person;
  ns_class_02::Person *p1 = new ns_class_02::Person(0, "pp" , "ppp");
  delete p;
  delete p1;

  //栈聚合初始化
  ns_class_02::Person p2[] = {ns_class_02::Person(), ns_class_02::Person()};
  //创建堆上对象数组必须提供构造函数
  ns_class_02::Person *p3 = new ns_class_02::Person[2];
  delete [] p3;
}

void func07()
{
  cout << "单例模式" << endl;
  ns_class_07::Singleton* s1 = ns_class_07::Singleton::getInstance();
  ns_class_07::Singleton* s2 = ns_class_07::Singleton::getInstance();
  cout << (s1 == s2) << endl; // 输出1，表示s1和s2指向同一个实例
}

void func08()
{
  cout << "成员变量和函数的存储" << endl;
  ns_class_08::MyClass01 c1;
  ns_class_08::MyClass02 c2;
  ns_class_08::MyClass03 c3;
  ns_class_08::MyClass04 c4;
  cout << "c1:" << sizeof(c1) << endl;//4
  cout << "c2:" << sizeof(c2) << endl;//4
  cout << "c3:" << sizeof(c3) << endl;//4
  cout << "c4:" << sizeof(c4) << endl;//4
}

int main(int argc, char const *argv[])
{
  cout << "hello class" << endl;
  // func01();
  // func02();
  // func03();
  // func04();
  // func05();
  // func06();
  // func07();
  func08();
}
