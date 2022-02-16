#pragma once

enum class Color : unsigned char {
White,
Red,
Blue,
};
class Shape
{
private:
Color color = Color::White;


public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;


};
