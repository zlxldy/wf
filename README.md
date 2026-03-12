# WF(watch folder)

[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

v1.1.0\
一个基于***c++17***的**cli**工具，显示文件夹中的内容，**并且 跨平台（windows、类unix（linux,mac））**！
## 安装
windows下可能会被拦截[重启玄学或许能解决(认真的吗？)]\
Linux输入以下命令
```bash
$ git clone https://github.com/zlxldy/wf.git
$ cd wf
$ make #g++编译器
$ make -f clang.mak #clang++编译器
```

windows同理，不过还准备了两个ps1脚本（clangb.ps1、gccb.ps1）看名字大概就知道怎么选择运行了

## v1.1.0
增添table模式，加上-t或--table选项即可开启，效果是仅输出文件名，可与-n -a选项搭配使用

## History
### v1.1.0（当前版本）
### v1.0.0
文件大小显示人类可读的单位，并智能选择单位（B、KB、MB、GB），尽量减少误差
### v0.5.0b
添加右对齐模式，加上-r或--right选项即可开启
### v0.4.1b
针对clang编译器的头文件缺失编译错误进行修复
### v0.4.0b
最后修改时间默认显示可读的格式，加上-s或--stamp时才会显示时间戳格式
### v0.3.1b
makefile的编译去掉了item.hpp，解决了clang编译器的编译错误
### v0.3.0a
隐藏的文件默认不会显示，只有带上-a或--all选项时才会显示
### v0.2.0a
隐藏的文件或文件夹的type与正常的区分开来，使得输出更加具体
### v0.1.2a
现在选项可以在任意位置，解决了编码问题导致的nerd font失效
### V0.1.1a
更加美观的格式化，并且添加了-n（--nerd）可选参数来让输出包含nerdfont的特殊字符，更加美观了
### V0.0.1a
性能优化
### V0.0.0a
alpha第一个小版本

# 正式版本
功能完善了www，最近不写了（图0魔咒太狠了w）