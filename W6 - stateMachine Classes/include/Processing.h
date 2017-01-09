#ifndef PROCESSING_H
#define PROCESSING_H

#include <State.h>
#include "Idle.h"

using namespace std;

class Processing : public State
{
  public:
    Processing()
    {
        cout << "   processing-ctor ";
    };
    ~Processing()
    {
        cout << "   dtor-processing\n";
    };
    void idle(Node *n);
};

void Processing::idle(Node *n)
{
  cout << "   going from processing to idle\n";
  n->setCurrent(new Idle());
  delete this;
}

#endif // PROCESSING_H
