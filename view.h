#pragma once

#include <iostream>
#include "model.h"
#include "controller.h"

class GUIView : public Observer
{
    
public:
    
    using GUIViewSptr = std::shared_ptr<GUIView>;

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

    GUIView(Model::ModelSptr model, Controller::ControllerSptr controller)
    {
        _model = model;
        _controller = controller;
        //_model->addObserver(this);
    }

    void addObserver(GUIViewSptr vsptr)
    {
        _model->addObserver(vsptr);
    }

private:
    Model::ModelSptr _model;
    Controller::ControllerSptr _controller;    

public:
    [[nodiscard]] static GUIViewSptr create(Model::ModelSptr model, Controller::ControllerSptr controller)
    {
        return GUIViewSptr(new GUIView(model, controller));
    }
};