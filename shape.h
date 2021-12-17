#pragma once

#include <string>
#include <memory>

class Shape
{
public:
    using ShapeSptr = std::shared_ptr<Shape>;

    virtual ~Shape() {}
    virtual std::string show() const = 0;
};

class Line : public Shape
{
public:
    
    using LineSptr = std::shared_ptr<Line>;

    [[nodiscard]] static LineSptr create(std::pair<float, float> startPt, float length)
    {
        _startPt = startPt;
        _length = length;
        return LineSptr(new Line());
    }
    std::string show() const override
    {
        return std::string("Line X1 = " + std::to_string(_startPt.first) + 
                               " Y1 = " + std::to_string(_startPt.second) + 
                               ", length = " + std::to_string(_length));
    }
private:
    Line() = default;
    static std::pair<float, float> _startPt;
    static float _length;
};

class Rectangle : public Shape
{
public:
    using RectangleSptr = std::shared_ptr<Rectangle>;

    [[nodiscard]] static RectangleSptr create(std::pair<float, float> leftToptPt, float length, float width)
    {
        _leftToptPt = leftToptPt;
        _length = length;
        _width = width;
        return RectangleSptr(new Rectangle());
    }
    std::string show() const override
    {
        return std::string("Rectangle X1 =" + std::to_string(_leftToptPt.first) + 
                                    " Y1 = " + std::to_string(_leftToptPt.second) + 
                                    ", length = " + std::to_string(_length) + 
                                    ", width = " + std::to_string(_width));
    }
private:
    Rectangle() = default;
    static std::pair<float, float> _leftToptPt;
    static float _length;
    static float _width;
};

class Ellipse : public Shape
{
public:
    using EllipseSptr = std::shared_ptr<Ellipse>;

    [[nodiscard]] static EllipseSptr create(std::pair<float, float> centerPt, float majorAxis, float minorAxis)
    {
        _centerPt = centerPt;
        _majorAxis = majorAxis;
        _minorAxis = minorAxis;
        return EllipseSptr(new Ellipse());
    }
    std::string show() const override
    {
        return std::string("Rectangle X0 =" + std::to_string(_centerPt.first) +
                                    " Y0 = " + std::to_string(_centerPt.second) +
                                    ", major axis = " + std::to_string(_majorAxis) +
                                    ", minor axis  = " + std::to_string(_minorAxis));
    }
private:
    Ellipse() = default;
    static std::pair<float, float> _centerPt;
    static float _majorAxis;
    static float _minorAxis;
};

std::pair<float, float> Line::_startPt;
float Line::_length;

std::pair<float, float> Rectangle::_leftToptPt;
float Rectangle::_length;
float Rectangle::_width;

std::pair<float, float> Ellipse::_centerPt;
float Ellipse::_majorAxis;
float Ellipse::_minorAxis;