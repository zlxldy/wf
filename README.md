# WF(watch folder)

[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

v0.1.2a\
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

## v0.2.0a
隐藏的文件或文件夹的type与正常的区分开来，使得输出更加具体了！

## History
### v0.2.0a（当前版本）
### v0.1.2a
现在选项可以在任意位置，解决了编码问题导致的nerd font失效
### V0.1.1a
更加美观的格式化，并且添加了-n（--nerd）可选参数来让输出包含nerdfont的特殊字符，更加美观了
### V0.0.1a
性能优化
### V0.0.0a
alpha第一个小版本