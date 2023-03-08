# struct 类型
git：https://github.com/weichangk/hellocpp/tree/master/struct

C 语言的 struct 定义了一组变量的集合，C 编译器并不认为这是一种新的类型。
C++ 中的 struct 是一个新类型的定义声明。

## 结构体概述
struct 关键字将不同类型封装在一起，形成新的结构叫做结构体。
```
//结构体类型定义
struct Student
{
  //成员列表，不要给成员初始化值
  char name[20];
  int age;
};
```
结构体类型定义变量时开辟内存空间，结构体中的成员拥有独立的内存空间。

三种定义结构体类型的方法：
1. 先定义结构体类型，在定义结构体变量
    ```
    struct Student
    {
      char name[20];
      int age;
    };
    Student stu;
    ```
2. 定义结构体类型的同时定义结构体变量
    ```
    struct Student
    {
      char name[20];
      int age;
    }stu;//定义类型同时定义变量  
    Student stu1;//也可以继续用类型定义变量
    ```
3. 定义一次性结构体类型 
    ```
    struct
    {
      char name[20];
      int age;
    }stu;
    ```

## 结构体变量操作
结构体变量初始化需要遵循成员的顺序以及自身数据类型
```
struct Student
{
  char name[20];
  int age;
};
Student stu = {"weick", 18};
```

清空整体结构体变量
```
void func03()
{
  Student stu;
  memset(&stu, 0, sizeof(stu));//将地址从&stu到sizeof(stu)的每个字节赋值为0，也就是将stu内存中每个字节赋值为0
  cout << "定义结构体变量，不初始化，再清空整个结构体变量" << stu.name << stu.age << endl;
}
```

单独操作结构体中成员
```
void func04()
{
  Student stu = {"weick", 18};
  //stu.name = "hahaha";//name成员是数组名，为符号常量不允许赋值
  strcpy(stu.name, "weickweick");
  stu.age += 10;
  cout << "单独操作结构体中成员" << stu.name << stu.age << endl;
}
```

相同类型结构体变量可直接赋值
```
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
```

## 结构体嵌套结构体
```
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
```

## 结构体数组
结构体数组本质是数组，数组的每个元素为结构体变量
```
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
```
## 结构体指针变量
结构体指针变量本质保存结构体变量地址的变量
```
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
```
## 结构体的指针成员
```
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
```
## 结构体对齐规则
<b>先了解下什么是内存对齐？</b>
参考：https://zhuanlan.zhihu.com/p/30007037

现代计算机中内存空间都是按照 byte 划分的，从理论上讲似乎对任何类型的变量的访问可以从任何地址开始，但是实际的计算机系统对基本类型数据在内存中存放的位置有限制，它们会要求这些数据的首地址的值是某个数k（通常它为4或8）的倍数，这就是所谓的内存对齐。

<b>为什么要进行内存对齐</b>
尽管内存是以字节为单位，但是大部分处理器并不是按字节块来存取内存的。它一般会以双字节，四字节，8字节，16字节甚至32字节为单位来存取内存，我们将上述这些存取单位称为内存存取粒度。

现在考虑4字节存取粒度的处理器取int类型变量（32位系统），该处理器只能从地址为4的倍数的内存开始读取数据。

假如没有内存对齐机制，数据可以任意存放，现在一个int变量存放在从地址1开始的联系四个字节地址中，该处理器去取数据时，要先从0地址开始读取第一个4字节块，剔除不想要的字节（0地址），然后从地址4开始读取下一个4字节块，同样剔除不要的数据（5，6，7地址），最后留下的两块数据合并放入寄存器，这需要做很多工作。

现在有了内存对齐的，int类型数据只能存放在按照对齐规则的内存中，比如说0地址开始的内存。那么现在该处理器在取数据时一次性就能将数据读出来了，而且不需要做额外的操作，提高了效率。

<b>内存对齐规则</b>
每个特定平台上的编译器都有自己的默认“对齐系数”（也叫对齐模数）。gcc中默认#pragma pack(4)，可以通过预编译命令#pragma pack(n)，n = 1,2,4,8,16来改变这一系数，这将影响结构体内成员的排列顺序和大小。

有效对齐值：是给定值#pragma pack(n)和结构体中最长数据类型长度中较小的那个。有效对齐值也叫对齐单位。

<b>内存对齐需要遵循的规则</b>
1. 结构体第一个成员的偏移量（offset）为0，以后每个成员相对于结构体首地址的 offset 都是该成员大小与对齐单位的整数倍，如有需要编译器会在成员之间加上填充字节。
2. 结构体的总大小为对齐单位的整数倍，如有需要编译器会在最末一个成员之后加上填充字节。

<b>C++结构体自动对齐规则</b>
1. 结构体的起始地址必须是其成员中最大对齐长度的整数倍。
2. 在结构体中，每个成员的地址应该是它大小的整数倍。
3. 结构体的总大小必须是其最大成员大小的整数倍。
4. 如果结构体中包含数组，则数组的对齐方式与普通变量相同。
5. 如果结构体中包含指针，则指针所占用的空间大小固定（通常是4字节或8字节），指针变量的对齐方式也是4字节或8字节。

## 结构体位域
C++ 结构体位域（Bit fields）是一种数据成员，是一种用于定义结构体成员的特殊方式，允许变量占用少量的位数而不是整个字节。结构体成员可以使用数据类型和长度来指定需要分配的内存位数，这些数据成员被称为“位域”或“比特域”（二进制位），通过指定需要用到的比特位数来对结构体成员变量进行优化。

相同类型的相邻位域可以压缩，但是压缩的位数不能小于自身类型的大小。

位域通常用于节省内存空间，例如在嵌入式系统或其他需要优化内存占用的应用程序中。

以下是结构体位域的声明格式：
```
struct MyStruct {
   unsigned int var1:1;
   unsigned int var2:2;
   unsigned int var3:1;
   ...
};
```
在上面的示例中，使用冒号（:）运算符指定每个位域的位数，注意位域的长度不能大于其所在类型的位数。
MyStruct 是一个包含位域的结构体类型，由三个成员组成：var1、var2 和 var3。这三个成员都是无符号整数类型，但它们分别只占用了 1 个、2 个和 1 个比特位（二进制位）。

使用位域成员时还有一些具体要注意的事项：
1. 对位域操作不要超过自身位域防止溢出
2. 位域成员不能取地址
3. 位域成员不能用于数组或函数参数类型
4. 在使用位域成员时应该明确标注结构体、成员名称和数据类型。

总的来说，位域成员是一种很好的语言特性，可以让程序运行更快，内存占用更小，但同时也得注意其局限性，以免造成不必要的问题。

<b>结构体位域应用</b>
通过结构体位域形成寄存器内存分布，对寄存器操作即对结构体变量中位域赋值，取代二进制位运算。
```
如8位寄存器
00 设备号
0  无效位
00 操作
0  无效位
00 校验位

//对应结构体位域
struct REG {
  unsigned char var1:2;
  unsigned char var2:1;
  unsigned char var3:2;
  unsigned char var4:1;
  unsigned char var5:2;
};

//10001001
REG reg;
reg.var1 = 2;
reg.var3 = 1;
reg.var5 = 1;
```
