# Visual Studio 上机流程

## 新建控制台项目

1. 打开 Visual Studio。
2. 选择 `Create a new project`。
3. 选择 `Console App`，语言选 `C++`。
4. 项目名建议用英文，例如 `ExamPractice01`。
5. 如果是空项目，右键 `Source Files`，选择 `Add > New Item`，添加 `main.cpp`。

## 每次写题的顺序

1. 先写头文件：

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
```

2. 写类声明和函数声明。
3. 写 `main()`，先保证能运行。
4. 再补成员函数逻辑。
5. 每完成一小段就按 `Ctrl + F5` 运行一次。

## 常用快捷键

- `Ctrl + F5`：不调试运行。
- `F5`：调试运行。
- `F9`：设置/取消断点。
- `F10`：单步执行。
- `Ctrl + K, Ctrl + D`：格式化代码。

## 怎么看编译错误

优先处理第一条错误。很多后面的错误都是第一条引起的。

常见错误：

- `expected ';'`：上一行或类定义末尾少了分号。
- `identifier not found`：变量名、函数名、类名拼错，或声明位置在使用之后。
- `no default constructor`：创建对象数组时，类没有无参构造函数。
- `cannot instantiate abstract class`：抽象类有纯虚函数，不能直接创建对象。
- `unresolved external symbol`：函数声明了但没有定义，或项目文件没加入。

## 考试建议

- 如果题目没要求拆文件，优先全部写在一个 `main.cpp`。
- 如果中文输出乱码，先保证逻辑正确；输出内容可以用英文或数字格式。
- 每个类先写最小版本，能编译后再加功能。
- 不确定 STL 时，用数组也可以；但 `vector` 更安全。
