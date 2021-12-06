#pragma once

#include <string>
#include <memory>

class Shape
{
public:
    virtual ~Shape() {}
    virtual std::string show() const = 0;
};

class Line : public Shape, public std::enable_shared_from_this<Line>
{
public:    
    [[nodiscard]] static std::shared_ptr<Line> create(std::pair<float, float> startPt, float length)
    {
        _startPt = startPt;
        _length = length;
        return std::shared_ptr<Line>(new Line());
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

class Rectangle : public Shape, public std::enable_shared_from_this<Rectangle>
{
public:
    [[nodiscard]] static std::shared_ptr<Rectangle> create(std::pair<float, float> leftToptPt, float length, float width)
    {
        _leftToptPt = leftToptPt;
        _length = length;
        _width = width;
        return std::shared_ptr<Rectangle>(new Rectangle());
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

class Ellipse : public Shape, public std::enable_shared_from_this<Ellipse>
{
public:
    [[nodiscard]] static std::shared_ptr<Ellipse> create(std::pair<float, float> centerPt, float majorAxis, float minorAxis)
    {
        _centerPt = centerPt;
        _majorAxis = majorAxis;
        _minorAxis = minorAxis;
        return std::shared_ptr<Ellipse>(new Ellipse());
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