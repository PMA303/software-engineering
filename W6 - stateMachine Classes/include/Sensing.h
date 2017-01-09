#ifndef SENSING_H
#define SENSING_H

#include <State.h>
#include "Processing.h"

using namespace std;

class Sensing : public State
{
  public:
    Sensing()
    {
        cout << "   sensing-ctor ";
    };
    ~Sensing()
    {
        cout << "   dtor-sensing\n";
    };
    void processing(Node *n);
};

void Sensing::processing(Node *n)
{
  cout << "   going from sensing to processing\n";
  n->setCurrent(new Processing());
  delete this;
}

#endif // SENSING_H
