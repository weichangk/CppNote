# 动态对象
git：https://github.com/weichangk/hellocpp/tree/master/class

当创建一个c++对象时会发生两件事：
1. 为对象分配内存
2. 调用构造函数来初始化那块内存

## new创建动态对象
c++中解决动态内存分配的方案是把创建一个对象所需要的操作都结合给一个new运算符里，当new创建一个对象时它就在堆中为对象分配内存并调用构造函数完成初始化。
```
Person *p = new Person;
```

## delete释放动态对象
delete表达式先调用析构函数然后释放内存
```
void func06()
{
  cout << "动态对象" << endl;
  ns_class_02::Person *p = new ns_class_02::Person;
  ns_class_02::Person *p1 = new ns_class_02::Person(0, "pp" , "ppp");
  delete p;
  delete p1;
}
```

## 用new创建动态对象和不使用new创建的普通对象有什么区别？
使用new创建动态对象和不使用new创建的普通对象的主要区别在于内存的分配和释放方式不同，以及对象的生命周期不同。

使用new创建动态对象时，会在堆上动态分配一块内存，并返回指向该内存的指针。这意味着对象的生命周期可以在程序运行时动态控制，可以在任何时候使用delete运算符释放动态分配的内存。而不使用new创建的普通对象则会在栈上分配内存，其生命周期由程序的控制流程决定。当程序执行离开该对象的作用域时，该对象的内存会自动被释放。

另外，使用new创建动态对象可以动态地创建和销毁对象，可以节省内存空间，但需要手动释放内存，否则会导致内存泄漏的问题。而不使用new创建的普通对象则不需要手动释放内存，但是对象的生命周期与程序控制流程相同，无法动态控制对象的生命周期。

总的来说，使用new创建动态对象适用于需要动态控制对象生命周期的情况，而不使用new创建的普通对象适用于对象生命周期与程序控制流程相同的情况。但是，需要注意的是，使用new创建动态对象需要手动释放内存，如果不小心造成内存泄漏，会导致程序运行效率低下或者崩溃。


## 动态对象数组
当创建一个对象数组的时候，必须对数组中的每一个对象调用构造函数，除了在栈上可以聚合初始化，必须提供一个默认的构造函数
```
//栈聚合初始化
ns_class_02::Person p2[] = {ns_class_02::Person(), ns_class_02::Person()};
//创建堆上对象数组必须提供构造函数
ns_class_02::Person *p3 = new ns_class_02::Person[2];
delete [] p3;
```