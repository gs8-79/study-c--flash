# C++ 上机考试速查表

## 最小程序

```cpp
#include <iostream>
using namespace std;

int main() {
    return 0;
}
```

## 常用头文件

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdexcept>
using namespace std;
```

## 输出两位小数

```cpp
cout << fixed << setprecision(2) << value << endl;
```

## 函数

```cpp
int add(int a, int b) {
    return a + b;
}
```

## 数组传参

```cpp
int maxValue(const int a[], int n) {
    int best = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > best) best = a[i];
    }
    return best;
}
```

## vector 遍历

```cpp
vector<int> nums;
nums.push_back(10);

for (int i = 0; i < (int)nums.size(); ++i) {
    cout << nums[i] << endl;
}
```

## class 骨架

```cpp
class Point {
private:
    int x;
    int y;

public:
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int xx) { x = xx; }
    void setY(int yy) { y = yy; }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};
```

## 组合

```cpp
class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 2000, int m = 1, int d = 1) : year(y), month(m), day(d) {}
};

class Employee {
private:
    string name;
    Date hireDate;

public:
    Employee(string n = "", Date d = Date()) : name(n), hireDate(d) {}
};
```

## 继承

```cpp
class Automobile {
protected:
    string plate;

public:
    Automobile(string p = "") : plate(p) {}
};

class Car : public Automobile {
private:
    string brand;

public:
    Car(string p = "", string b = "") : Automobile(p), brand(b) {}
};
```

## 多态

```cpp
class Shape {
public:
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {
        return 2 * 3.1415926 * radius;
    }

    void print() const override {
        cout << "Circle radius=" << radius;
    }
};
```

## 排序

```cpp
sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
    return a.score > b.score;
});
```

## 运算符重载

```cpp
bool operator>(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}
```

## 模板

```cpp
template <typename T>
T maxValue(T a, T b) {
    return a > b ? a : b;
}
```

## 文件读取

```cpp
ifstream fin("input.txt");
if (!fin) {
    cout << "Cannot open file" << endl;
    return 1;
}

int x;
while (fin >> x) {
    cout << x << endl;
}
```

## 异常

```cpp
try {
    throw runtime_error("file not opened");
} catch (const exception& e) {
    cout << e.what() << endl;
}
```
