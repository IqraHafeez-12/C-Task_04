#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual ~Shape() {} // Add a virtual destructor
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getAngleSum() const = 0;
    virtual void display() const = 0;
};

class Hexagon : public Shape
{
public:
    Hexagon(int cnic) : sideLength(cnic % 10 + 1) {}

    double getArea() const override { return 1.5 * sideLength * sideLength * sqrt(3); }
    double getPerimeter() const override { return 6 * sideLength; }
    double getAngleSum() const override { return 6 * 120; }
    void display() const override
    {
        std::cout << "Hexagon - Area: " << getArea() << ", Perimeter: " << getPerimeter() << ", Sum of angles: " << getAngleSum() << std::endl;
    }

private:
    int sideLength;
};

class Square : public Shape
{
public:
    Square(int cnic) : sideLength(cnic % 10 + 1) {}

    double getArea() const override { return sideLength * sideLength; }
    double getPerimeter() const override { return 4 * sideLength; }
    double getAngleSum() const override { return 4 * 90; }
    void display() const override
    {
        std::cout << "Square - Area: " << getArea() << ", Perimeter: " << getPerimeter() << std::endl;
    }

private:
    int sideLength;
};

int main()
{
    int cnic;
    std::cout << "Enter your CNIC: ";
    std::cin >> cnic;

    int choice;
    std::cout << "Enter 1 for Hexagon, 2 for Square: ";
    std::cin >> choice;

    Shape* shape;
    if (choice == 1)
    {
        shape = new Hexagon(cnic);
    }
    else if (choice == 2)
    {
        shape = new Square(cnic);
    }
    else
    {
        return 0;
    }

    shape->display();
    delete shape; // Use delete, not delete shape

    return 0;
}

