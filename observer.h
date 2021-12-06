#pragma once

#include <vector>

class Observer
{
public:
    virtual void update() = 0;
};

class Observable 
{
public:
    void addObserver(Observer* observer)
    {
        _observers.push_back(observer);
    }
    void notifyAll()
    {
        int size = (int)_observers.size();
        for (int i = 0; i < size; i++)
        {
            _observers[i]->update();
        }
    }
private:
    std::vector<Observer*> _observers;
};