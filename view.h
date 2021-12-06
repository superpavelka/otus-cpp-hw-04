#pragma once

#include <iostream>
#include <memory>
#include "model.h"

class GUIView : public Observer, public std::enable_shared_from_this<GUIView>
{

public:
    
    virtual void update() override
    {
        std::cout << _model->getState();
    }

    void createNewFile()
    {
        _controller->createNewFile();
    }

    void importFromFile(const std::string& filename)
    {
        _controller->importFromFile(filename);
    }

    void exportToFile(const std::string& filename)
    {
        _controller->exportToFile(filename);
    }

    void addLine(std::pair<float, float> start, float length)
    {
        _controller->addLine(Line::create(start, length));
    }

    void addRectangle(std::pair<float, float> leftTop, float length, float width)
    {

        _controller->addRectangle(Rectangle::create(leftTop, length, width));
    }

    void addEllipse(std::pair<float, float> center, float majorAxis, float minorAxis)
    {
        _controller->addEllipse(Ellipse::create(center, majorAxis, minorAxis));
    }    

    void removeShapeByIndex(int index)
    {
        _controller->removeShapeByIndex(index);
    }

private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<Controller> _controller;

    GUIView(std::shared_ptr<Model> model, std::shared_ptr<Controller> controller)
    {
        _model = model;
        _controller = controller;
        _model->addObserver(this);
    }

public:
    [[nodiscard]] static std::shared_ptr<GUIView> create(std::shared_ptr<Model> model, std::shared_ptr<Controller> controller)
    {
        return std::shared_ptr<GUIView>(new GUIView(model, controller));
    }
};