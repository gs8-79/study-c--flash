# 上机练习题单

## 练习 1：温度统计

输入 `n` 和 `n` 个整数温度，输出：

- 最高温度。
- 最低温度。
- 出现次数最多的温度。
- 最长连续升温天数。

要求：

- 至少写 3 个函数。
- 处理 `n <= 0`。

参考答案：`src/01_foundation_temperature.cpp`

## 练习 2：Point、Date、Employee

设计：

- `Point`：包含 `x`、`y`，能移动和计算到原点距离。
- `Date`：包含年、月、日，能比较日期大小。
- `Employee`：包含姓名、入职日期，能输出信息。

要求：

- 使用构造函数。
- `Employee` 使用 `Date` 作为数据成员。
- 创建员工数组，找入职最早的员工。

参考答案：`src/02_point_date_employee.cpp`

## 练习 3：图形框架

设计抽象类 `Shape`，派生类：

- `Circle`
- `Rectangle`
- `RightTriangle`

要求：

- 每个图形能计算周长。
- 使用 `vector<Shape*>` 存储不同图形。
- 按周长从大到小排序并输出。

参考答案：`src/03_shapes_polymorphism.cpp`

## 练习 4：文件和异常

读取 `data/Shapes.txt`，每行格式：

```text
Circle 3 4.0
Rectangle 3 4 2.0
RightTriangle 3 4 3.5
Square 5 1.5
```

含义：

- 图形类型。
- 尺寸参数。
- 单价。

要求：

- 文件不存在时抛出异常。
- 计算每个图形周长和价格。
- 输出总价格。

参考答案：`src/04_file_exception.cpp`

## 练习 5：90 分钟模拟上机

题目：旅行社报名系统。

设计一个简单系统，管理游客报名旅游团。

### 数据

每位游客有：

- 姓名。
- 目的地类型：`DomesticShort`、`DomesticLong`、`International`。
- 行李数量。

每个旅游团有：

- 团名。
- 目的地类型。
- 最多 6 名游客。

票价：

- `DomesticShort`：10 元。
- `DomesticLong`：100 元。
- `International`：500 元。
- 每位游客免费带 2 件行李，多出的每件加 100 元。

### 要求

- 至少设计 `Passenger`、`Team`、`TicketOffice` 三个类。
- 使用数组或 `vector` 保存游客。
- 自动把游客加入匹配的团队，满员则不加入。
- 输出每位游客票价和总收入。

参考答案：`src/05_mock_exam_solution.cpp`
