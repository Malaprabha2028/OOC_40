#include <iostream>
#include <cmath> 
#include <iomanip> 
class Shape {
public:
    
    Shape() {}
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159; 

public:

    Circle(double r) : radius(r) {
        std::cout << "Circle object created with radius: " << radius << std::endl;
    }

    double calculateArea() override {
    
        return PI * radius * radius;
    }

    double calculatePerimeter() override {

        return 2 * PI * radius;
    }

    void display() override {
        std::cout << "\n--- Circle Info ---" << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << calculateArea() << std::endl;
        std::cout << "Perimeter (Circumference): " << calculatePerimeter() << std::endl;
        std::cout << "-------------------\n" << std::endl;
    }

    ~Circle() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        std::cout << "Rectangle object created with length: " << length << " and width: " << width << std::endl;
    }
    
    double calculateArea() override {

        return length * width;
    }

    double calculatePerimeter() override {
    
        return 2 * (length + width);
    }

    void display() override {
        std::cout << "\n--- Rectangle Info ---" << std::endl;
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
        std::cout << "Area: " << calculateArea() << std::endl;
        std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
        std::cout << "----------------------\n" << std::endl;
    }

    ~Rectangle() {}
};

class Triangle : public Shape {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        std::cout << "Triangle object created with sides: " << sideA << ", " << sideB << ", " << sideC << std::endl;
    }


    double calculateArea() override {

        double s = calculatePerimeter() / 2.0;

       
        if (s - sideA <= 0 || s - sideB <= 0 || s - sideC <= 0) {
            std::cerr << "Error: Invalid triangle sides provided for area calculation." << std::endl;
            return 0.0;
        }

        return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() override {
        return sideA + sideB + sideC;
    }

    void display() override {
        std::cout << "\n--- Triangle Info ---" << std::endl;
        std::cout << "Sides: " << sideA << ", " << sideB << ", " << sideC << std::endl;
        if ((sideA + sideB <= sideC) || (sideA + sideC <= sideB) || (sideB + sideC <= sideA)) {
            std::cerr << "Warning: The sides provided do not form a valid triangle." << std::endl;
            std::cout << "Area: N/A (Invalid Triangle)" << std::endl;
            std::cout << "Perimeter: " << calculatePerimeter() << " (Sum of sides)" << std::endl;
        } else {
            std::cout << "Area (Heron's Formula): " << calculateArea() << std::endl;
            std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
        }
        std::cout << "---------------------\n" << std::endl;
    }

    ~Triangle() {}
};

int main() {
    cout << " Name        : Malaprabha Bekwadkar\n";
    cout << " Roll No     : 40\n";
    cout << " Division    : B\n";
    cout << " Department  : CSE(SY)\n";
    
    std::cout << std::fixed << std::setprecision(2);

    Circle myCircle(4.5);          
    Rectangle myRectangle(6.0, 8.0);
    Triangle myTriangle(3.0, 4.0, 5.0); 
    Triangle invalidTriangle(1.0, 2.0, 10.0); 

    Shape* shapes[4];

    shapes[0] = &myCircle;
    shapes[1] = &myRectangle;
    shapes[2] = &myTriangle;
    shapes[3] = &invalidTriangle;

    std::cout << "Demonstrating Virtual Functions (Runtime Polymorphism):" << std::endl;

    for (int i = 0; i < 4; ++i) {
        shapes[i]->display(); 
    }

    return 0;
}

