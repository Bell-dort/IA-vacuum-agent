//
// Created by Bell on 06/10/2022.
//

#include "../header/Node.h"

Node::Node(Node* father, State state, int cost) : m_father(father), m_state(state), m_cost(cost) {}

std::vector<Node> Node::expand() {
    std::vector<Node> newNodes;

    for (Actions::Action action : Actions::All) {
        State *nextState = m_state.nextState(action);
        if (nextState) {
            Node newNode(this, *nextState, m_cost + 1);
            newNodes.push_back(newNode);
        }
    }
}