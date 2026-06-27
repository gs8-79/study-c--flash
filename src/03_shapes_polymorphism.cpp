#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double PI_VALUE = 3.141592653589793;

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
        return 2 * PI_VALUE * radius;
    }

    void print() const override {
        cout << "Circle radius=" << radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() const override {
        return 2 * (width + height);
    }

    void print() const override {
        cout << "Rectangle width=" << width << " height=" << height;
    }
};

class RightTriangle : public Shape {
private:
    double a;
    double b;

public:
    RightTriangle(double aa, double bb) : a(aa), b(bb) {}

    double perimeter() const override {
        return a + b + sqrt(a * a + b * b);
    }

    void print() const override {
        cout << "RightTriangle a=" << a << " b=" << b;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new RightTriangle(3, 4));
    shapes.push_back(new Circle(2));

    sort(shapes.begin(), shapes.end(), [](const Shape* left, const Shape* right) {
        return left->perimeter() > right->perimeter();
    });

    cout << fixed << setprecision(2);
    for (int i = 0; i < (int)shapes.size(); ++i) {
        cout << i + 1 << ". ";
        shapes[i]->print();
        cout << " perimeter=" << shapes[i]->perimeter() << endl;
    }

    for (int i = 0; i < (int)shapes.size(); ++i) {
        delete shapes[i];
    }

    return 0;
}
