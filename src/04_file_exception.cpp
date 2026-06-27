#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

const double PI_VALUE = 3.141592653589793;

class FileNotOpenedException : public runtime_error {
public:
    FileNotOpenedException(const string& fileName)
        : runtime_error("Cannot open file: " + fileName) {}
};

class Shape {
private:
    double unitPrice;

public:
    Shape(double price) : unitPrice(price) {}
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() {}

    double price() const {
        return perimeter() * unitPrice;
    }

    double getUnitPrice() const {
        return unitPrice;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, double price) : Shape(price), radius(r) {}

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
    Rectangle(double w, double h, double price) : Shape(price), width(w), height(h) {}

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
    RightTriangle(double aa, double bb, double price) : Shape(price), a(aa), b(bb) {}

    double perimeter() const override {
        return a + b + sqrt(a * a + b * b);
    }

    void print() const override {
        cout << "RightTriangle a=" << a << " b=" << b;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s, double price) : Shape(price), side(s) {}

    double perimeter() const override {
        return 4 * side;
    }

    void print() const override {
        cout << "Square side=" << side;
    }
};

vector<Shape*> loadShapes(const string& fileName) {
    ifstream fin(fileName);
    if (!fin) {
        throw FileNotOpenedException(fileName);
    }

    vector<Shape*> shapes;
    string type;

    while (fin >> type) {
        if (type == "Circle") {
            double radius;
            double price;
            fin >> radius >> price;
            shapes.push_back(new Circle(radius, price));
        } else if (type == "Rectangle") {
            double width;
            double height;
            double price;
            fin >> width >> height >> price;
            shapes.push_back(new Rectangle(width, height, price));
        } else if (type == "RightTriangle") {
            double a;
            double b;
            double price;
            fin >> a >> b >> price;
            shapes.push_back(new RightTriangle(a, b, price));
        } else if (type == "Square") {
            double side;
            double price;
            fin >> side >> price;
            shapes.push_back(new Square(side, price));
        } else {
            throw runtime_error("Unknown shape type: " + type);
        }
    }

    return shapes;
}

void deleteShapes(vector<Shape*>& shapes) {
    for (int i = 0; i < (int)shapes.size(); ++i) {
        delete shapes[i];
    }
    shapes.clear();
}

int main() {
    string fileName = "data/Shapes.txt";

    try {
        vector<Shape*> shapes = loadShapes(fileName);
        double total = 0;

        cout << fixed << setprecision(2);
        for (int i = 0; i < (int)shapes.size(); ++i) {
            shapes[i]->print();
            cout << " perimeter=" << shapes[i]->perimeter();
            cout << " price=" << shapes[i]->price() << endl;
            total += shapes[i]->price();
        }

        cout << "Total price: " << total << endl;
        deleteShapes(shapes);
    } catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
