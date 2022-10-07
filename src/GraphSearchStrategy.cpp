//
// Created by Bell on 06/10/2022.
//

#include "../header/GraphSearchStrategy.h"

Node* GraphSearchStrategy::depthFirstSearch(State initialState, State finalState) {
    Node* initialNode = new Node(nullptr, initialState, 0);
    std::vector<Node*> openList;
    std::vector<Node*> closeList;

    openList.push_back(initialNode);

    while (!openList.empty()) {
        Node* currentNode = openList.front();
        closeList.push_back(currentNode);
        openList.erase(openList.begin());

        if (*(currentNode->getState()) == finalState) {
            return currentNode;
        }
        std::vector<Node*> expandNodes = currentNode->expand();

        for (auto itExpandNodes(expandNodes.begin()); itExpandNodes != expandNodes.end(); ++itExpandNodes) {
            for (auto itOpenList(openList.begin()); itOpenList != openList.end(); ++itOpenList) {
                if (*(*itOpenList)->getState() == *(*itExpandNodes)->getState()) {
                    if ((*itExpandNodes)->getCost() < (*itOpenList)->getCost()) {
                        *itOpenList = *itExpandNodes;
                    }
                    continue;
                }
            }

            for (auto itCloseList(closeList.begin()); itCloseList != closeList.end(); ++itCloseList) {
                if (*(*itExpandNodes)->getState() == *(*itCloseList)->getState())
                    continue;
            }

            openList.push_back(*itExpandNodes);
        }
    }
}