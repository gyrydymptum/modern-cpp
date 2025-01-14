#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
}

auto perimeterBiggerThan20(shared_ptr<Shape> s) {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
}

auto areaLessThan10(shared_ptr<Shape> s) {
    if (s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection) {
    for (const auto & el : collection) {
        if (el) {
            (el)->print();
        }
    }
}

void printAreas(const Collection& collection) {
    for (const auto & el : collection) {
        if (el) {
             cout << el->getArea() << std::endl;
        }
    }

}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main() {
    Collection shapes = {
    make_shared<Circle>(2.0),
    make_shared<Circle>(3.0),
    nullptr,
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(10.0, 5.0),
    make_shared<Square>(3.0),
    make_shared<Circle>(4.0),
    };
    shapes.push_back(make_shared<Circle>(Color::Red));
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);
  
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");
     std:: cout << "Alignment of" << '\n'
     
       << "class Circle: " << alignof(Circle)     << '\n';

    return 0;
}
