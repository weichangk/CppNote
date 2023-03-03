# C++ vscode 开发环境搭建
笔记内容：
- C++ vscode 开发环境搭建准备
- 了解g++命令编译调试
- 掌握使用launch.json和tasks.json配置文件编译调试
- cmake构建工具学习

git:
https://github.com/weichangk/hellocpp/tree/master/vscodecmakecpp
## 环境搭建准备
- 安装vscode
- 安装qt，通过Qt在线安装工具可以选择安装cmake（构建工具），mingw64（编译套件）
Qt安装可以参考：https://blog.csdn.net/qq_39827640/article/details/127411878?spm=1001.2014.3001.5502
Qt在线安装工具下载：https://download.qt.io/archive/online_installers/4.5/
- 配置cmake，mingw64环境变量
  - D:\Qt\Tools\CMake_64\bin
  - D:\Qt\Tools\mingw810_64\bin
- 安装插件
  - C/C++
  - C/C++ Themes
  - C/C++ Extension Pack
  - CMake
## 创建一个hello World

## 基于g++命令编译调试
参考：
https://www.runoob.com/w3cnote/cpp-header.html
https://www.runoob.com/w3cnote/gcc-parameter-detail.html
https://blog.csdn.net/Three_dog/article/details/103688043

C++的编译过程
1. 编译预处理：主要对包含的头文件（＃include ）和宏定义（＃define,#ifdef … ）还有注释等进行处理。
g++ -E test.cpp -o test.ii
g++ -E main.cpp -o main.ii

2. 编译：C++ 语法错误的检查，检查无误后，g++ 把代码翻译成汇编语言。
g++ -S test.ii -o test.s
g++ -S main.ii -o main.s

3. 汇编：g++ 汇编阶段：生成目标代码 *.o
g++ -c test.s -o test.o
g++ -c main.s -o main.o

4. g++ 链接阶段：生成可执行文件；Windows下生成.exe
g++ main.o test.o -o multi.exe

带-g参数生成带调试信息的可执行文件并执行调试
1. g++编译单文件
g++ -g main.cpp -o single
.\single.exe

2. g++编译多个文件
g++ -g main.cpp test.h test.cpp -o multi
.\multi.exe

## 使用launch.json和tasks.json配置文件启动编译调试
参考：
https://code.visualstudio.com/docs/cpp/config-mingw

.vscode文件夹中文件作用注释:
- tasks.json (构建指令)
- launch.json (设置调试器)
- c_cpp_properties.json (编译器路径和智能感知设置)
- settings.json


1. 生成默认的tasks.json文件
VSCode中Task的使用参考：https://blog.csdn.net/qq_53653262/article/details/120859147
选择一个cpp文件，打开“终端”菜单“配置默认生成任务”选择“C/C++: g++.exe 生成活动文件”，文件如下：
    ```
    {
      "version": "2.0.0",
      "tasks": [
        {
          "type": "cppbuild",
          "label": "C/C++: g++.exe 生成活动文件",
          "command": "D:\\Qt\\Tools\\mingw810_64\\bin\\g++.exe",
          "args": [
            "-fdiagnostics-color=always",
            "-g",
            "${file}",
            "-o",
            "${fileDirname}\\${fileBasenameNoExtension}.exe"
          ],
          "options": {
            "cwd": "${fileDirname}"
          },
          "problemMatcher": [
            "$gcc"
          ],
          "group": {
            "kind": "build",
            "isDefault": true
          },
          "detail": "编译器: D:\\Qt\\Tools\\mingw810_64\\bin\\g++.exe"
        }
      ]
    }
    ```

2. 生成默认的launch.json文件
更多内容可参考：https://blog.csdn.net/qq_16587307/article/details/106593867
点击调试按钮，创建launch.json文件，选择对应的项目或工作区，选择g++.exe生成和调试活动文件，如果没有g++(GDB/LLDB)选项可以将c++插件退回到1.8.4（右键插件安装另一个版本），文件如下：
    ```
    {
        // 使用 IntelliSense 了解相关属性。 
        // 悬停以查看现有属性的描述。
        // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
        "version": "0.2.0",
        "configurations": [
            {
                "name": "(gdb) 启动",
                "type": "cppdbg",
                "request": "launch",
                "program": "输入程序名称，例如 ${workspaceFolder}/a.exe",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${fileDirname}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "miDebuggerPath": "/path/to/gdb",
                "setupCommands": [
                    {
                        "description": "为 gdb 启用整齐打印",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    },
                    {
                        "description": "将反汇编风格设置为 Intel",
                        "text": "-gdb-set disassembly-flavor intel",
                        "ignoreFailures": true
                    }
                ]
            }
        ]
    }
    ```
3. 修改tasks.json launch.json文件关键参数
详细参数说明参考：
https://code.visualstudio.com/docs/cpp/config-mingw

- tasks.json
  - label
  - command
  - args
  - options cwd
- launch.json
  - program
  - cwd
  - miDebuggerPath
  - preLaunchTask

4. 修改后的文件
    ```
    //tasks.json
    {
      "version": "2.0.0",
      "tasks": [
        {
          "type": "cppbuild",
          "label": "C/C++: g++.exe vscodecmakecpp",
          "command": "D:\\Qt\\Tools\\mingw810_64\\bin\\g++.exe",
          "args": [
            "-fdiagnostics-color=always",
            "-g",
            "main.cpp",
            "test.cpp",
            "-o",
            "${workspaceFolder}\\src\\${workspaceFolderBasename}.exe"
          ],
          "options": {
            "cwd": "${workspaceFolder}\\src"
          },
          "problemMatcher": [
            "$gcc"
          ],
          "group": {
            "kind": "build",
            "isDefault": true
          },
          "detail": "编译器: D:\\Qt\\Tools\\mingw810_64\\bin\\g++.exe"
        }
      ]
    }

    //launch.json
    {
      "version": "0.2.0",
      "configurations": [
          {
              "name": "(gdb) 启动",
              "type": "cppdbg",
              "request": "launch",
              "program": "${workspaceFolder}\\src\\${workspaceFolderBasename}.exe",
              "args": [],
              "stopAtEntry": false,
              "cwd": "${workspaceFolder}\\src",
              "environment": [],
              "externalConsole": false,
              "MIMode": "gdb",
              "miDebuggerPath": "D:\\Qt\\Tools\\mingw810_64\\bin\\gdb.exe",
              "setupCommands": [
                  {
                      "description": "为 gdb 启用整齐打印",
                      "text": "-enable-pretty-printing",
                      "ignoreFailures": true
                  },
                  {
                      "description": "将反汇编风格设置为 Intel",
                      "text": "-gdb-set disassembly-flavor intel",
                      "ignoreFailures": true
                  }
              ],
              "preLaunchTask": "C/C++: g++.exe vscodecmakecpp"//关联tasks.json文件
          }
      ]
    }
    ```

5. tasks.json launch.json之间的关系
  - tasks.json：g++构建指令，可以直接在“终端”选择“运行任务”中选择构建任务执行编译。
  - launch.json：gdb调试器参数，附加tasks.json可以通过vscode执行编译调试并输出调试信息。

6. c_cpp_properties.json 配置文件作用是：代码提示、代码跳转等
参考：
https://blog.csdn.net/fdfdsds/article/details/102248876
https://blog.csdn.net/weixin_40694527/article/details/84251461

## 基于cmake编译调试
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