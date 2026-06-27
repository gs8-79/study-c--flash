# 三天学习安排

日期按当前时间 2026-06-27 处理，考试按 2026-06-30 周二处理。

## 6月27日：先能写出基础程序，约 6 小时

目标：看到普通输入输出题，不慌，能写完整 `main.cpp`。

### 1. Visual Studio 入门，40 分钟

- 新建 `Console App` 或 `Empty Project`。
- 添加 `main.cpp`。
- 写并运行最小程序：

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello C++" << endl;
    return 0;
}
```

- 学会看 Error List：双击错误跳到对应行。
- 学会断点：在行号左侧点一下，按 F5 调试，F10 单步执行。

### 2. 基础语法，2 小时

必须掌握：

- `int`、`double`、`char`、`string`。
- `cin >> a >> b;`
- `cout << fixed << setprecision(2) << x;`
- `if / else`、`switch`。
- `for`、`while`。
- 函数：返回值、参数、数组参数。

当天必须写出来：`src/01_foundation_temperature.cpp`。

### 3. 数组和统计，2 小时

练这些能力：

- 找最大值、最小值。
- 统计某个值出现次数。
- 找出现次数最多的数。
- 找最长连续上升、连续相等、连续满足条件的长度。

### 4. 当天验收，1 小时 20 分钟

从空文件重新写一遍温度统计题，不看答案。要求：

- 能编译。
- 能处理 0 个或 1 个数据的边界。
- 输出格式稳定。

## 6月28日：面向对象主线，约 7 小时

目标：能按题目设计类，能写继承和多态。

### 1. 类与对象，2 小时

必须掌握：

- `class` 默认 private。
- 成员变量通常放 `private`。
- 构造函数负责初始化。
- 成员函数通过对象调用：`p.print();`
- 对象数组：`Employee employees[5];`

当天必须写出来：`src/02_point_date_employee.cpp`。

### 2. 组合，1 小时

重点：一个类包含另一个类对象。

例子：`Employee` 包含 `Date hireDate`。

构造函数写法：

```cpp
Employee(string name, Date date) : name(name), hireDate(date) {}
```

### 3. 继承，1.5 小时

必须掌握：

```cpp
class Car : public Automobile {
public:
    Car(string plate, string brand) : Automobile(plate), brand(brand) {}
};
```

理解：

- `public` 继承是考试最常用写法。
- 派生类构造函数要先调用基类构造函数。
- 基类指针可以指向派生类对象。

### 4. 多态，1.5 小时

必须掌握：

```cpp
class Shape {
public:
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};
```

重点：

- 有 `virtual` 才会动态绑定。
- 纯虚函数 `= 0` 会让类成为抽象类，不能直接创建对象。
- 基类析构函数建议写成 `virtual`。

当天必须写出来：`src/03_shapes_polymorphism.cpp`。

### 5. 当天验收，1 小时

从空文件写一个 `Account` 继承题：

- `Account` 有 `balance`。
- `SavingsAccount` 有利率。
- `CheckingAccount` 每次操作收费。
- 用 `Account* accounts[]` 循环调用虚函数输出余额。

## 6月29日：综合和模拟，约 5 小时

目标：把考试最可能组合出现的点串起来。

### 1. 运算符重载，50 分钟

会写这三个就够用：

```cpp
bool operator>(const Date& other) const;
int operator-(const Date& other) const;
ostream& operator<<(ostream& out, const Date& date);
```

### 2. 函数模板，40 分钟

会写求最大值模板：

```cpp
template <typename T>
T maxValue(T a, T b) {
    return a > b ? a : b;
}
```

前提：自定义类要能用 `>` 比较。

### 3. 文件与异常，1 小时

必须掌握：

- `#include <fstream>`
- `ifstream fin("Shapes.txt");`
- `if (!fin) { ... }`
- `throw runtime_error("file not opened");`
- `try / catch`

当天必须写出来：`src/04_file_exception.cpp`。

### 4. 90 分钟模拟上机

题目见 `exercises.md` 的“模拟题”。参考答案是 `src/05_mock_exam_solution.cpp`。

考试流程：

1. 读题 5 分钟，写类名和成员函数草稿。
2. 先写能编译的空类和 `main()`。
3. 每写完一个类就编译一次。
4. 最后 15 分钟只修编译错误和输出格式，不再大改结构。

### 5. 最终复盘，1 小时

只看：

- `cheat_sheet.md`
- `mistake_checklist.md`
- 自己写错过的代码
