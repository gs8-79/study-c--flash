#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void moveRight(int offset) { x += offset; }
    void moveDown(int offset) { y += offset; }

    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 1990, int m = 1, int d = 1) : year(y), month(m), day(d) {}

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const {
        return other < *this;
    }

    void print() const {
        cout << year << "-";
        cout << setw(2) << setfill('0') << month << "-";
        cout << setw(2) << setfill('0') << day;
        cout << setfill(' ');
    }
};

class Employee {
private:
    string name;
    Date hireDate;

public:
    Employee(string n = "", Date d = Date()) : name(n), hireDate(d) {}

    const Date& getHireDate() const {
        return hireDate;
    }

    void print() const {
        cout << name << " hired at ";
        hireDate.print();
        cout << endl;
    }
};

int findEarliestEmployee(const vector<Employee>& employees) {
    int best = 0;
    for (int i = 1; i < (int)employees.size(); ++i) {
        if (employees[i].getHireDate() < employees[best].getHireDate()) {
            best = i;
        }
    }
    return best;
}

int main() {
    Point p(3, 4);
    cout << "Point p: ";
    p.print();
    cout << ", distance=" << fixed << setprecision(2) << p.distanceToOrigin() << endl;

    p.moveRight(10);
    p.moveDown(5);
    cout << "After move: ";
    p.print();
    cout << endl;

    vector<Employee> employees;
    employees.push_back(Employee("Alice", Date(2022, 5, 1)));
    employees.push_back(Employee("Bob", Date(2020, 3, 15)));
    employees.push_back(Employee("Cindy", Date(2021, 9, 8)));

    cout << "Employees:" << endl;
    for (int i = 0; i < (int)employees.size(); ++i) {
        employees[i].print();
    }

    int earliest = findEarliestEmployee(employees);
    cout << "Earliest employee: ";
    employees[earliest].print();

    return 0;
}
