#include "iostream"
#include "01/person.h"
#include "02/person.h"
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
  ns_class_02::Person p1;                               //隐式调用无参构造函数（推荐）
  ns_class_02::Person p2 = ns_class_02::Person();       //显示调用无参构造函数
  ns_class_02::Person p3(0, "p3", "p3");                        //隐式调用有参构造函数（推荐）
  ns_class_02::Person p4 = ns_class_02::Person(0, "p4", "p4");  //显示调用有参构造函数

  //匿名对象，执行完立即析构，不会等到{}作用域结束才析构。
  ns_class_02::Person();
  ns_class_02::Person(0, "aa", "aa");

  //构造函数 隐式转换（类中只有一个数据成员）
  //ns_class_02::Person p5 = 100;

  //旧对象给新对象初始化调用拷贝构造函数
  //有指针成员，如果不自定义拷贝构造函数会有问题
  ns_class_02::Person p5 = p3;
}

int main(int argc, char const *argv[])
{
  cout << "hello class" << endl;
  func01();
  func02();
}
