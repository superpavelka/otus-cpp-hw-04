#pragma once

#include "observer.h"
#include "shape.h"
#include <string>
#include <memory>

class Model : public Observable
{    
public:    

    using ModelSptr = std::shared_ptr<Model>;    

    void createNewFile()
    {
        _state = "New document was created\n";
        clear();
        notifyAll();
    }

    void importFromFile(const std::string& filename)
    {
        _state = "Document was imported from file " + filename + "\n";
        clear();
        notifyAll();
    }

    void exportToFile(const std::string& filename)
    {
        _state = "Document was exported to file " + filename + "\n";
        notifyAll();
    }

    void addShape(Shape::ShapeSptr shape)
    {
        _state = shape->show() + " was added to document\n";
        _shapes.push_back(shape);
        notifyAll();
    }

    void removeShapeByIndex(int index)
    {
        if (index >= 0 && index < (int)_shapes.size()) {
            auto front = _shapes.begin();
            std::advance(front, index);
            _state = (*front)->show() + " was removed from document\n";
            _shapes.erase(front);
        }
        else 
            _state = "Warning! Invalid index.\n";

        notifyAll();
    }

    [[nodiscard]] static ModelSptr create()
    {
        return ModelSptr(new Model());
    }

    std::string getState() const
    {
        return _state;
    }

private:
    Model() = default;

    void clear()
    {
        if (_shapes.size() > 0) 
        {
            _shapes.clear();
            _state.append("All Shapes was removed\n");
        }
    }

    std::string _state;
    std::vector<Shape::ShapeSptr> _shapes;
};