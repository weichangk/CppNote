#include <iostream>
#include "section_01.h"
#include "section_02.h"
using namespace std;

void section_01()
{
  cout << "函数原型、函数签名、函数定义、函数参数传递方式" << endl;
  ns_section_01::func01();
  ns_section_01::func02();
  ns_section_01::func03();
}
void section_02()
{
  cout << "函数参数-数组、结构体、字符串、array对象" << endl;
  ns_section_02::func01();
  ns_section_02::func02();
  ns_section_02::func03();

  char text[] = "Hello, world!";//带验证是不是'\0'结尾
  string str = "Hello, world!";
  int count = ns_section_02::c_in_str(str, 'l');
}
int main(int argc, char const *argv[])
{
  cout << "hello function" << endl;
  section_01();
  section_02();
}
