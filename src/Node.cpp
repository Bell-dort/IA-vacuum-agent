//
// Created by Bell on 06/10/2022.
//

#include "../header/Node.h"

Node::Node(Node* father, State state, int cost) : m_state(state), m_cost(cost) {
    m_father = father;
}

std::vector<Node*> Node::expand() {
    std::vector<Node*> newNodes;

    for (Actions::Action action : Actions::All) {
        State* pNextState = m_state.nextState(action);
        if (pNextState) {
            State nextState = *pNextState;
            // potential problems with **squares
            Node* temp = new Node(this, (nextState), m_cost + 1);
            temp->m_father = this;

            temp->m_lastAction = action;
            newNodes.push_back(temp);
        }
    }

    return newNodes;
}

std::vector<Actions::Action> Node::getActionsFromSolution() {
    std::vector<Actions::Action> newActions;
    if (m_father) {
        newActions = m_father->getActionsFromSolution();
        newActions.push_back(m_lastAction);
    }

    return newActions;
}

State *Node::getState() {
    return &m_state;
}

int Node::getCost() {
    return m_cost;
}