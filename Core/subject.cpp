#include "subject.h"
#include "observer.h"

Subject::Subject()
{

}

void Subject::registerObserver(Observer* o)
{
    observers.push_back(o);
}

void Subject::notifyObservers()
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i] -> notify();
    }
}
