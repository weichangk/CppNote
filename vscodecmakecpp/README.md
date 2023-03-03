# windows 下 vscode + cmake 的 c++开发

## 开发环境搭建
- 安装vscode
- 安装qt，通过qt在线安装工具可以选择安装cmake（构建工具），mingw64（编译套件）
Qt安装可以参考：https://blog.csdn.net/qq_39827640/article/details/127411878?spm=1001.2014.3001.5502
在线安装工具下载：https://download.qt.io/archive/online_installers/4.5/
- 配置cmake，mingw64环境变量
  - D:\Qt\Tools\CMake_64\bin
  - D:\Qt\Tools\mingw810_64\bin
- 安装插件
  - C/C++
  - CMake

## 代码演练

### 基于g++命令
g++编译单文件，带-g参数生成带调试信息的可执行文件，调试。
```cpp
g++ -g main.cpp -o single
.\single.exe
```
g++编译多个文件，生成带调试信息的可执行文件，调试
```cpp
g++ -g main.cpp swap.cpp -o multi
```


### 使用launch.json配置文件启动调试
点击调试按钮，创建launch.json文件，选择对应的项目或工作区，选择g++.exe生成和调试活动文件
如果没有g++(GDB/LLDB)选项可以将c++插件退回到1.8.4（右键插件安装另一个版本）
### 基于cmake编译调试
编写最简单的CMakeLists.txt
```cmake
project(myswap)
add_executable(my_cmake_swap, main.cpp, swap.cpp)
```
手动命令编译，进行多文件编译，并调试
```
mkdir build
cd build
# 如果电脑上已经安装了vs，可能会调用微软MSVC编译器，使用（cmake -G "MinGW Makefiles" ...）代替（cmake ..）即可
# 仅第一次使用cmake时使用（cmake -G "MinGW Makefiles" ...）后面可使用cmake ..）
```
### 配置json


# Cross-platform development
CMake是一个跨平台的安装编译工具，可用简单的语句来描述所有平台的安装（编译过程）
CMake可以说已经成为大部分c++开源项目的标配

# 语法特性介绍
基本语法格式：指令(参数1 参数2 ...)
参数之间使用空格或分号分开
指令是不分大小写，参数和变量是区分大小写的
变量使用${}方式取值，但是在if控制语句中是直接使用变量名
# 重要指令和常用变量

# CMake编译工程
cmake_minimum_required 指定cmake最小版本要求
语法：cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])
cmake_minimum_required(VERSION 2.8.3)

project 定义工程名称，并可指定工程支持的语言
project(projecrname [CXX][C][Java])
# CMake代码实践