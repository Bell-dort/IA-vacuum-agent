//
// Created by Bell on 06/10/2022.
//

#ifndef IA_VACUUM_AGENT_NODE_H
#define IA_VACUUM_AGENT_NODE_H

#include <vector>
#include "State.h"


class Node {
public:
    Node(Node* father, State state, int cost);
    std::vector<Node> expand();
private:
    Actions::Action m_lastAction;
    Node* m_father;
    State m_state;
    int m_cost;
};


#endif //IA_VACUUM_AGENT_NODE_H
