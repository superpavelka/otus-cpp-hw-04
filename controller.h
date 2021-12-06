#pragma once
#include "model.h"

class Controller : public std::enable_shared_from_this<Controller>
{
public:    

    [[nodiscard]] static std::shared_ptr<Controller> create(std::shared_ptr<Model> model)
    {
        return std::shared_ptr<Controller>(new Controller(model));
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
    std::shared_ptr<Model> _model;

public:
    Controller(std::shared_ptr<Model> model)
    {
        _model = model;
    }
};