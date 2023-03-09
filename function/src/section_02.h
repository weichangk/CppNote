#pragma once
#include <iostream>
using namespace std;

namespace ns_section_02
{
  void printArray(int arr[], int size);
  void func01();
  void printArray1(int* arr, int size);
  void func02();
  void printArray(int (&arr)[5]);
  void func03();

  // int c_in_str(char str[], char ch);
  int c_in_str(char* str, char ch);
  int c_in_str(string &str, char ch);
}

