#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
  class State *current;
  public:
    Node();
    void setCurrent(State *s)
    {
        current = s;
    }
    void sensing();
    void processing();
    void idle();
};

#endif // NODE_H
