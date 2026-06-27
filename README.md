# study-C++-flash

这是一个面向 C++ 上机考试的三天冲刺学习包，适合 C++ 基础较弱、需要在 Visual Studio 中独立完成控制台程序的同学。

当前学习目标：

- 能从零新建 Visual Studio C++ 控制台项目。
- 能写出可编译、可运行的 `main.cpp`。
- 能掌握考试高频内容：输入输出、流程控制、函数、数组、类与对象、继承、多态、文件操作和异常处理。
- 能完成一个“类 + 数组/容器 + 输入输出 + 简单统计/排序”的综合上机题。

## 快速开始

先看：

- [`START_HERE.md`](START_HERE.md)：从哪里开始学。
- [`study_plan_3_days.md`](study_plan_3_days.md)：6月27日到6月29日的三天安排。
- [`visual_studio_workflow.md`](visual_studio_workflow.md)：Visual Studio 新建、运行、调试流程。

然后按这个顺序练：

1. 打开 [`exercises.md`](exercises.md)，从练习 1 开始自己写。
2. 卡住 15 分钟后，再看 [`src`](src) 目录里的参考答案。
3. 考前只看 [`cheat_sheet.md`](cheat_sheet.md) 和 [`mistake_checklist.md`](mistake_checklist.md)。

## 目录结构

```text
.
├── START_HERE.md                 # 学习入口
├── study_plan_3_days.md          # 三天冲刺计划
├── visual_studio_workflow.md     # Visual Studio 操作说明
├── cheat_sheet.md                # C++ 考试速查表
├── mistake_checklist.md          # 高频错误排查
├── exercises.md                  # 练习题单
├── data/
│   └── Shapes.txt                # 文件题测试数据
├── scripts/
│   ├── build_all.cmd             # 在 VS 开发者命令行中编译全部示例
│   └── build_with_vs.cmd         # 自动加载 VS 环境并编译全部示例
└── src/
    ├── exam_template.cpp
    ├── 01_foundation_temperature.cpp
    ├── 02_point_date_employee.cpp
    ├── 03_shapes_polymorphism.cpp
    ├── 04_file_exception.cpp
    └── 05_mock_exam_solution.cpp
```

## 示例代码覆盖内容

- `01_foundation_temperature.cpp`：数组、循环、函数、统计。
- `02_point_date_employee.cpp`：类、构造函数、组合、对象数组。
- `03_shapes_polymorphism.cpp`：继承、多态、抽象类、排序。
- `04_file_exception.cpp`：文件读取、异常、继承多态。
- `05_mock_exam_solution.cpp`：90 分钟模拟上机题参考答案。
- `exam_template.cpp`：考试时可复用的空模板。

## 编译验证

本项目已用 Visual Studio C++ 工具链编译验证。

在仓库根目录运行：

```bat
scripts\build_with_vs.cmd
```

编译产物会生成到 `build/` 目录，该目录不会提交到 Git。

## 学习策略

- 不要先完整啃课件，先练能写出来的程序。
- 每道题都从空 `main.cpp` 开始写。
- 每完成一个函数或类就编译一次。
- 最后 10 分钟只修编译错误和输出格式，不要重构。

## 考前最小目标

考前至少要能不看答案写出：

1. 一个能读输入、输出结果的 `main()`。
2. 一个带构造函数和成员函数的 `class`。
3. 一个包含另一个类对象的数据成员。
4. 一个基类、两个派生类和一个 `virtual` 函数。
5. 一个读文本文件并处理打开失败的程序。
6. 一个数组或 `vector` 的遍历、统计和排序。
