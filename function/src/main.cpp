#include <iostream>
using namespace std;

void changeValue(int n) {
    n = 100;
}
void func01() {
    int a = 10;
    changeValue(a);
    cout << a << endl; // 输出 10
}
void changeValueByRef(int& n) {
    n = 100;
}
void func02() {
    int a = 10;
    changeValueByRef(a);
    cout << a << endl; // 输出 100
}
void changeValueByPtr(int* n)
{
  *n = 100;
}
void func03()
{
  int a = 10;
  changeValueByPtr(&a);
  cout << a << endl; // 输出 100
}

//[] 指出 arr 是一个数组，[] 为空表示可以将任何长度的数组传递进来，arr 实际上不是数组而是指针。 C++ 将数组名解释为其第一个元素的地址。
//所以数组做形参时传递进来的实参是地址。
//无论 arr 是指针还是数组名，表达式 arr[3] 都指的是数组的第4个元素
// arr[i] == *(arr + i)
// &arr[i] == arr + i

//数组名作为形参
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << &arr[i] << " " << arr[i] << endl;
    }
}
void func04()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  //使用数组名作为参数传递时，传递的是数组的地址。在函数中可以通过指针的方式访问数组元素。
  printArray(arr, size);
}

int main(int argc, char const *argv[])
{
  cout << "hello function" << endl;
  func01();
  func02();
  func03();
}
