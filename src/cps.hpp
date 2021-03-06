//
// Created by jlrine2 on 3/23/20.
//

#ifndef CS372_CPS_CPS_HPP
#define CS372_CPS_CPS_HPP

#include <ostream>
#include <memory>
#include <vector>




class Shape {
public:
    [[nodiscard]] virtual double get_height() const = 0;

    virtual double get_width() const = 0;

    virtual void createPostScript(std::ostream &os) const = 0;

};


class Polygon : public Shape {
public:
    Polygon(double sLen, unsigned int sides) : sideLength(sLen), sides(sides) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
    int sides;
};


class Square : public Shape {
public:
    explicit Square(double l) : sideLength(l) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
};


class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double height;
    double width;
};


class Triangle : public Shape {
public:
    explicit Triangle(double l) : sideLength(l) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
};


class Circle : public Shape {
public:
    explicit Circle(double r) : radius(r) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double radius;

};


class Spacer : public Shape {
public:
    Spacer(double w, double h) : width(w), height(h) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double height;
    double width;
};


class Rotated : public Shape {
public:
    Rotated(std::shared_ptr<Shape> shape, int rotationAngle) : shape(shape), rotation(rotationAngle) {}

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    std::shared_ptr<Shape> shape;
    int rotation;
};


class Scaled : public Shape {
public:
    Scaled(std::shared_ptr<Shape> shape, double fx, double fy);

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    std::shared_ptr<Shape> shape;
    double x;
    double y;
};
class Container : public Shape{
    public:
    //Container(std::initializer_list<std::shared_ptr<Shape>> shapes);

    virtual void moveTo(std::ostream &os,int index) const = 0;
    virtual std::vector<std::shared_ptr<Shape>> getShapes() const = 0;
    void createPostScript(std::ostream &os) const override;
    private:
};

class Layered : public Container{
public:
    Layered(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() const override;

    double get_height() const override;

    std::vector<std::shared_ptr<Shape>> getShapes() const override;  

    void moveTo(std::ostream &os,int index) const override;

private:
    std::vector<std::shared_ptr<Shape>> shapes;
};


class Vertical : public Container {
public:
    Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() const override;

    double get_height() const override;

    std::vector<std::shared_ptr<Shape>> getShapes() const override;  

    void moveTo(std::ostream &os,int index) const override;



private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};


class Horizontal : public Container {
public:
    Horizontal(std::initializer_list<std::shared_ptr<Shape>> shapes);

    double get_width() const override;

    double get_height() const override;

    std::vector<std::shared_ptr<Shape>> getShapes() const override;

    void moveTo(std::ostream &os,int index) const override;

private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

class Star : public Shape {
public:
    Star(double sidelength);

    double get_width() const override;

    double get_height() const override;

    void createPostScript(std::ostream &os) const override;

private:
    double sideLength;
};

void getPostScriptPage(std::ostream & os, std::shared_ptr<Shape> shape);

std::shared_ptr<Shape> getCircle(double radius);
std::shared_ptr<Shape> getSquare(double sideLength);
std::shared_ptr<Shape> getRectangle(double width, double height);
std::shared_ptr<Shape> getTriangle(double sidelength);
std::shared_ptr<Shape> getSpacer(double width, double height);
std::shared_ptr<Shape> getPolygon(double sideLength, double numberOfSides);


std::shared_ptr<Shape> getRotated(std::shared_ptr<Shape> shape, int rotationAngle);
std::shared_ptr<Shape> getVertical(std::initializer_list<std::shared_ptr<Shape>> shapes);
std::shared_ptr<Shape> getHorizontal(std::initializer_list<std::shared_ptr<Shape>> shapes);
std::shared_ptr<Shape> getLayered(std::initializer_list<std::shared_ptr<Shape>> shapes);


std::shared_ptr<Star> getStar(double sideLength);
#endif //CS372_CPS_CPS_HPP
