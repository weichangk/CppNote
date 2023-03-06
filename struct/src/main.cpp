#include "iostream"
#include "string.h"
using namespace std;

//定义结构体类型
struct Student
{
  char name[20];
  int age;
};

void func01()
{
  Student stu;
  cout << "定义结构体变量，不初始化直接使用，输出乱码" << stu.name << stu.age << endl;
}

void func02()
{
  Student stu = {"weick", 18};
  cout << "定义结构体变量并初始化" << stu.name << stu.age << endl;
}

void func03()
{
  Student stu;
  memset(&stu, 0, sizeof(stu));//将地址从&stu到sizeof(stu)的每个字节赋值为0，也就是将stu内存中每个字节赋值为0
  cout << "定义结构体变量，不初始化，再清空整个结构体变量" << stu.name << stu.age << endl;
}

void func04()
{
  Student stu = {"weick", 18};
  //stu.name = "hahaha";//name成员是数组名，为符号常量不允许赋值
  strcpy(stu.name, "weickweick");
  stu.age += 10;
  cout << "单独操作结构体中成员" << stu.name << stu.age << endl;
}

void func05()
{
  Student stu = {"weick", 18};
  Student stu1 = stu;
  stu1.age +=1;
  cout << "相同类型结构体变量可直接赋值" << stu1.name << stu1.age << endl;
  Student stu2;
  memcpy(&stu2, &stu, sizeof(stu));
  cout << "结构体变量内存拷贝，结构体变量直接赋值的底层实现" << stu2.name << stu2.age << endl;
}


//结构体嵌套结构体
struct StudentDate
{
  int year;
  int month;
  int day;
};
struct Student02
{
  char name[20];
  int age;
  StudentDate dt;
};

void func06()
{
  Student02 stu = {"weick", 18, {2023, 3, 5}};
  cout << "结构体嵌套结构体:" << "name:" << stu.name << "age:" << stu.age  << "Date:" << stu.dt.year << stu.dt.month << stu.dt.day << endl;
}

void func07()
{
  Student stuarr[3] = {{"weick", 18}, {"zs", 19}, {"sl", 20}};
  //数组个数 = 数组大小除以元素大小 = 3
  int n = sizeof(stuarr) / sizeof(stuarr[0]);
  for (int i = 0; i < n; i++)
  {
    cout << stuarr[i].name << endl;
  }

  //清空数组
  memset(stuarr, 0, sizeof(stuarr));
  for (int i = 0; i < n; i++)
  {
    cout << stuarr[i].name << endl;
  }
}

void func08()
{
  Student stu = {"weick", 18};
  Student *p = &stu;
  cout << stu.name << endl;
  //*p == stu
  cout << (*p).name << endl;
  //指针变量通过 -> 访问成员
  p->age = 20;
  cout << p->age << endl;
  //如果是地址可直接使用->访问成员，如果是变量需要用.访问成员
  (&stu)->age = 21;
  cout << p->age << endl;
  (*p).age = 22;
  cout << (&stu)->age << endl;
}

//结构体的指针成员
struct Student03
{
  char *name;
  int age;
};
void func09()
{
  //stu.name保存的是"weick"的首元素地址，而"weick"字符串本身存储在文字常量区
  Student03 stu = {"weick", 18};
  cout << stu.name << endl;

  //stu1.name保存的是"weick"的首元素地址,而"weick"字符串本身存储在堆空间
  Student03 stu1;
  stu1.name = new char[32];
  strcpy(stu1.name, "weick");
  cout << stu1.name << endl;
  //释放空间
  delete [] stu1.name;
}
//相同类型结构体变量可以整体赋值，默认赋值方式为浅拷贝。
//如果结构体中有指针成员（浅拷贝只会拷贝指针变量的值 即 指针所指向空间内存首地址），浅拷贝可能会多次操作堆空间的问题。
void func10()
{
  Student03 stu;
  stu.name = new char[32];
  strcpy(stu.name, "weick");

  Student03 stu1 = stu;
  cout << stu1.name << endl;
  //释放空间
  delete [] stu.name;
  //delete [] stu1.name;//stu.name stu1.name 相同地址，指向同一内存空间，重复释放报错。
}
//结构体深拷贝，为指针成员申请独立内存空间
void func11()
{
  Student03 stu;
  stu.name = new char[32];
  strcpy(stu.name, "weick");

  Student03 stu1 = stu;
  stu1.name = new char[32];//重新分配内存空间
  strcpy(stu1.name, "weick");

  //释放空间
  delete [] stu.name;
  delete [] stu1.name;
}
void func12()
{
  //结构体指针，结构体指针变量指向堆区
  Student03 *stu = new Student03;
  //结构体指针成员，结构体指针成员变量也指向堆区
  stu->name = new char[32];
  strcpy(stu->name, "weick");
  stu->age = 18;
  cout << stu->name << endl;
  //释放空间，要由里到外释放
  delete [] stu->name;
  delete stu;
}

int main(int argc, char const *argv[])
{
  cout << "hello struct" << endl;
  func01();
  func02();
  func03();
  func04();
  func05();
  func06();
  func07();
  func08();
  func09();
  func10();
  func11();
  func12();
}
