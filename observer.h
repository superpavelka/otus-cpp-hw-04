#pragma once

#include <vector>
#include <memory>

class Observer
{
public:
    using ObserverSptr = std::shared_ptr<Observer>;

    virtual void update() = 0;
    virtual ~Observer() {}
};

class Observable 
{
public:
    void addObserver(Observer::ObserverSptr observer)
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
    std::vector<Observer::ObserverSptr> _observers;
};