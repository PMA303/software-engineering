// Week 6 Portfolio - Event Driven Programming.
// State design pattern - a Finite State Machine(FSM).
// The FSM has 3 states and 3 events.
// The code needs further work, as it will not compile.

#include <iostream>
#include "Node.h"
#include "State.h"
#include "Sensing.h"
#include "Processing.h"
#include "Idle.h"

using namespace std;

int main()
{
  void(Node:: *ptrs[])() =
  {
    Node::idle, Node::sensing, Node::processing
  };
  Node fsm;
  int num;
  while (1)
  {
    cout << "Enter 0 for idle, 1 for sensing or 2 for processing: ";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}

