#ifndef STATE_H
#define STATE_H

#include "Node.h"


using namespace std;

class State
{
  public:
    virtual void sensing(Node *n)
    {
        cout << "   already sensing\n\n";
    }
    virtual void processing(Node *n)
    {
        cout << "   already processing\n\n";
    }
    virtual void idle(Node *n)
    {
        cout << "   already idling\n\n";
    }
};

void Node::sensing()
{
  current->sensing(this);
}

void Node::processing()
{
  current->processing(this);
}

void Node::idle()
{
  current->idle(this);
}

#endif // STATE_H
