// Week 6 Portfolio - Event Driven Programming.
// State design pattern - a Finite State Machine(FSM).
// The FSM has 3 states and 3 events.
// To choose states, enter 0 for idle, 1 for sensing or 2 for processing.
// The code needs further work, as it will allow the wrong state
// sequence to be entered.

#include <iostream>

using namespace std;

// Node is the context class
class Node
{
  class State *current;
  public:
    Node();
    void setCurrent(State *s)
    {
        current = s;
    }
    // Pointers point to these 3 functions
    void sensing();
    void processing();
    void idle();
};

// Abstract class with virtual functions
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

// Callback functions
// Current is a pointer to a state
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

// Sensing, Processing and Idle
// are the derived classes of State
class Sensing: public State
{
  public:
    Sensing()
    {
        cout << "   sensing-ctor ";
    };
    ~Sensing()
    {
        cout << "   dtor-sensing\n\n";
    };
    void processing(Node *n);
};

class Processing: public State
{
  public:
    Processing()
    {
        cout << "   processing-ctor ";
    };
    ~Processing()
    {
        cout << "   dtor-processing\n\n";
    };
    void idle(Node *n);
};

class Idle: public State
{
  public:
    Idle()
    {
        cout << "   idle-ctor ";
    };
    ~Idle()
    {
        cout << "   dtor-idle\n\n";
    };
    void sensing(Node *n);
};

void Sensing::processing(Node *n)
{
  cout << "   going from sensing to processing\n";
  n->setCurrent(new Processing());
  delete this;
}

void Processing::idle(Node *n)
{
  cout << "   going from processing to idle\n";
  n->setCurrent(new Idle());
  delete this;
}

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

int main()
{
// Pointer to an array of functions, to member classes
// Class Node has 3 functions idle, sensing and processing
  void(Node:: *ptrs[])() =
  {
    Node::idle, Node::sensing, Node::processing
  };
  // fsm object
  Node fsm;
  int num;
  while (1)
    // Command line numerical input to choose state
  {
    cout << "Enter 0 for idle, 1 for sensing or 2 for processing: ";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}
