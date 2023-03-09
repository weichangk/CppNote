#include "section_02.h"
#include <iostream>
using namespace std;
namespace ns_section_02
{
  //数组做函数参数:
  //1.数组做函数参数 - 使用数组名作为形参
  //[] 指出 arr 是一个数组，[] 为空表示可以将任何长度的数组传递进来，arr 实际上不是数组而是指针。
  //使用数组名作为参数传递时，C++ 将数组名解释为数组第一个元素的的地址。在函数中可以通过指针的方式(arr[i] 等同 *(arr + i))访问数组元素。
  void printArray(int arr[], int size) {
    cout << arr << endl;//0x61fdd0 == &arr[0] //数组名为数组第一个元素地址
    for (int i = 0; i < size; i++) {
      cout << &arr[i] << " == " << arr + i << endl;
      cout << arr[i] << " == " << *(arr + i) << endl;
      // 0x61fdd0 == 0x61fdd0
      // 1 == 1
      // 0x61fdd4 == 0x61fdd4
      // 2 == 2
      // 0x61fdd8 == 0x61fdd8
      // 3 == 3
      // 0x61fddc == 0x61fddc
      // 4 == 4
      // 0x61fde0 == 0x61fde0
      // 5 == 5
    }
  }
  void func01()
  {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
  }

  //2.数组做函数参数 - 使用指针做形参
  //函数中使用指向数组首元素地址的指针来操作整个数组
  void printArray1(int* arr, int size)
  {
    cout << arr << endl;//0x61fdd0 == &arr[0] //指针指向数组首元素地址
    for (int i = 0; i < size; i++) {
      cout << &arr[i] << " == " << arr + i << endl;
      cout << arr[i] << " == " << *(arr + i) << endl;//
      // 0x61fdd0 == 0x61fdd0
      // 1 == 1
      // 0x61fdd4 == 0x61fdd4
      // 2 == 2
      // 0x61fdd8 == 0x61fdd8
      // 3 == 3
      // 0x61fddc == 0x61fddc
      // 4 == 4
      // 0x61fde0 == 0x61fde0
      // 5 == 5
    }
  }
  void func02()
  {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray1(arr, size);
  }

  //3.数组做函数参数 - 使用数组引用作为形参
  //使用数组引用作为参数传递时，传递的是数组的引用（数组变量的别名），在函数中数组引用直接访问数组元素。
  //和上面的使用数组名作为形参的区别只是形参的写法形式不一样而已。
  void printArray(int (&arr)[5])
  {
    cout << arr << endl;//0x61fdd0 == &arr[0] //引用（数组名别名）为数组第一个元素地址
    for (int i = 0; i < 5; i++) {
      cout << &arr[i] << " == " << arr + i << endl;
      cout << arr[i] << " == " << *(arr + i) << endl;//
      // 0x61fdd0 == 0x61fdd0
      // 1 == 1
      // 0x61fdd4 == 0x61fdd4
      // 2 == 2
      // 0x61fdd8 == 0x61fdd8
      // 3 == 3
      // 0x61fddc == 0x61fddc
      // 4 == 4
      // 0x61fde0 == 0x61fde0
      // 5 == 5
    }
  }
  void func03()
  {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr);
  }

  //通过上面的例子可以看出，无论 arr 是指针还是数组还是引用，表达式 arr[i] 都指的是数组的第i+1个元素
  // arr[i] == *(arr + i)
  // &arr[i] == arr + i
  //将指针（包括数组名，数组引用）+1 实际上是加上了一个与指针指向的类型的长度（字节为单位）相等的值，对指针（包括数组名）加减就是地址偏移的过程，达到通过地址操作数组的结果。
  //相比使用指针，使用数组的引用是一种更高效的方法，因为它不需要进行指针运算，也避免了指针所需的间接性。
  //无论哪种方式，都可以将数组传递给函数，并在函数中对其进行操作或修改。


  //int c_in_str(char str[], char ch) == int c_in_str(char* str, char ch)
  int c_in_str(char* str, char ch)
  {
    int count = 0;
    while (*str)
    {
      if(*str == ch)
        count++;
      str++;
    }
    return count;
  }
  int c_in_str(string &str, char ch)
  {
    int count = 0;
    int len = size(str) - 1;
    while (str[len])
    {
      char c = str[len];
      if(str[len] == ch)
        count++;
      len--;
    }
    return count;
  }
}
