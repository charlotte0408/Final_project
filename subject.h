#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Observer;
class Subject
{
public:

private:
    vector<Observer*> observers;
};

#endif // SUBJECT_H
