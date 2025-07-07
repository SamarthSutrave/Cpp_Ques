#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
    // Operator overloading for area comparison
    bool operator==(const Shape& other) const { return fabs(area() - other.area()) < 1e-6; }
    bool operator<(const Shape& other) const { return area() < other.area(); }
    bool operator>(const Shape& other) const { return area() > other.area(); }
};

// Circle
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
    void display() const override {
        cout << "Circle: radius = " << radius << ", area = " << area() << ", perimeter = " << perimeter() << endl;
    }
};

// Rectangle
class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
    void display() const override {
        cout << "Rectangle: width = " << width << ", height = " << height << ", area = " << area() << ", perimeter = " << perimeter() << endl;
    }
};

// Square (inherits Rectangle)
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    void display() const override {
        cout << "Square: side = " << width << ", area = " << area() << ", perimeter = " << perimeter() << endl;
    }
};

// Triangle
class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
    void display() const override {
        cout << "Triangle: sides = " << a << ", " << b << ", " << c << ", area = " << area() << ", perimeter = " << perimeter() << endl;
    }
};

// Ellipse
class Ellipse : public Shape {
    double a, b; // semi-major and semi-minor axes
public:
    Ellipse(double a_, double b_) : a(a_), b(b_) {}
    double area() const override { return M_PI * a * b; }
    double perimeter() const override {
        // Ramanujan's approximation
        return M_PI * (3*(a+b) - sqrt((3*a+b)*(a+3*b)));
    }
    void display() const override {
        cout << "Ellipse: a = " << a << ", b = " << b << ", area = " << area() << ", perimeter = " << perimeter() << endl;
    }
};

// Menu functions
void printMenu() {
    cout << "\n--- Shape Calculator Menu ---\n";
    cout << "1. Create Circle\n";
    cout << "2. Create Rectangle\n";
    cout << "3. Create Square\n";
    cout << "4. Create Triangle\n";
    cout << "5. Create Ellipse\n";
    cout << "6. Display all shapes\n";
    cout << "7. Compare two shapes by area\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Shape*> shapes;
    int choice;
    while (true) {
        printMenu();
        cin >> choice;
        if (cin.fail()) { clearInput(); continue; }
        if (choice == 1) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            if (r > 0) shapes.push_back(new Circle(r));
            else cout << "Invalid radius!\n";
        } else if (choice == 2) {
            double w, h;
            cout << "Enter width and height: ";
            cin >> w >> h;
            if (w > 0 && h > 0) shapes.push_back(new Rectangle(w, h));
            else cout << "Invalid dimensions!\n";
        } else if (choice == 3) {
            double s;
            cout << "Enter side: ";
            cin >> s;
            if (s > 0) shapes.push_back(new Square(s));
            else cout << "Invalid side!\n";
        } else if (choice == 4) {
            double a, b, c;
            cout << "Enter three sides: ";
            cin >> a >> b >> c;
            if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
                shapes.push_back(new Triangle(a, b, c));
            else cout << "Invalid triangle sides!\n";
        } else if (choice == 5) {
            double a, b;
            cout << "Enter semi-major axis (a) and semi-minor axis (b): ";
            cin >> a >> b;
            if (a > 0 && b > 0) shapes.push_back(new Ellipse(a, b));
            else cout << "Invalid axes!\n";
        } else if (choice == 6) {
            if (shapes.empty()) cout << "No shapes created yet.\n";
            else {
                for (size_t i = 0; i < shapes.size(); ++i) {
                    cout << i+1 << ". ";
                    shapes[i]->display();
                }
            }
        } else if (choice == 7) {
            if (shapes.size() < 2) {
                cout << "Need at least two shapes to compare.\n";
                continue;
            }
            size_t i, j;
            cout << "Enter indices of two shapes to compare (1-based): ";
            cin >> i >> j;
            if (i < 1 || j < 1 || i > shapes.size() || j > shapes.size()) {
                cout << "Invalid indices!\n";
                continue;
            }
            Shape* s1 = shapes[i-1];
            Shape* s2 = shapes[j-1];
            cout << "Shape " << i << ": "; s1->display();
            cout << "Shape " << j << ": "; s2->display();
            if (*s1 == *s2) cout << "Areas are equal.\n";
            else if (*s1 > *s2) cout << "Shape " << i << " has larger area.\n";
            else cout << "Shape " << j << " has larger area.\n";
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    // Clean up
    for (Shape* s : shapes) delete s;
    cout << "Goodbye!\n";
    return 0;
} 