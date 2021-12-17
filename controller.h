#pragma once
#include "model.h"

class Controller : public std::enable_shared_from_this<Controller>
{    
public:    

    using ControllerSptr = std::shared_ptr<Controller>;

    [[nodiscard]] static ControllerSptr create(Model::ModelSptr model)
    {
        return ControllerSptr(new Controller(model));
    }

    void createNewFile()
    {
        _model->createNewFile();
    }

    void importFromFile(const std::string& filename)
    {
        _model->importFromFile(filename);
    }

    void exportToFile(const std::string& filename)
    {
        _model->exportToFile(filename);
    }

    void addLine(std::shared_ptr<Line> line)
    {
        _model->addShape(line);
    }

    void addRectangle(std::shared_ptr<Rectangle> rectangle)
    {
        _model->addShape(rectangle);
    }

    void addEllipse(std::shared_ptr<Ellipse> ellipse)
    {
        _model->addShape(ellipse);
    }    

    void removeShapeByIndex(int index)
    {
        _model->removeShapeByIndex(index);
    }

private:
    Model::ModelSptr _model;

public:
    Controller(Model::ModelSptr model)
    {
        _model = model;
    }
};