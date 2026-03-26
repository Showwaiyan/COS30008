#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle() {
        radius = 0.0;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return 3.14159 * radius * radius;
    }

    double getDiameter() const {
        return 2 * radius;
    }

    double getCircumference() const {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    Circle circle;
    double r;

    cout << "Enter the radius of the circle: ";
    cin >> r;

    circle.setRadius(r);

    cout << fixed << setprecision(2);
    cout << "\nCircle Information:" << endl;
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.getArea() << endl;
    cout << "Diameter: " << circle.getDiameter() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}
