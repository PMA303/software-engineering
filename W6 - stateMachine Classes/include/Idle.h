#ifndef IDLE_H
#define IDLE_H

#include <State.h>
#include "Sensing.h"

using namespace std;

class Idle : public State
{
  public:
    Idle()
    {
        cout << "   idle-ctor ";
    };
    ~Idle()
    {
        cout << "   dtor-idle\n";
    };
    void sensing(Node *n);
};

void Idle::sensing(Node *n)
{
  cout << "   going from idle to sensing\n";
  n->setCurrent(new Sensing());
  delete this;
}

Node::Node()
{
  current = new Idle();
  cout << '\n';
}

#endif // IDLE_H
