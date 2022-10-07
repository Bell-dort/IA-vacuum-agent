//
// Created by Bell on 06/10/2022.
//

#ifndef IA_VACUUM_AGENT_GRAPHSEARCHSTRATEGY_H
#define IA_VACUUM_AGENT_GRAPHSEARCHSTRATEGY_H

#include <vector>
#include "State.h"
#include "Node.h"

class GraphSearchStrategy {
private:
public:
    static Node* depthFirstSearch(State initialState, State finalState);
};


#endif //IA_VACUUM_AGENT_GRAPHSEARCHSTRATEGY_H
