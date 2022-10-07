//
// Created by Bell on 04/10/2022.
//

#ifndef IA_VACUUM_AGENT_STATE_H
#define IA_VACUUM_AGENT_STATE_H

#include <vector>
#include "Square.h"
#include "Action.h"


class State {
public:
    State(Square** squares, int squaresHeight, int squaresWidth, int vacuumX, int vacuumY);
    // State(const State &other);
    State* nextState(Actions::Action action);

    bool operator==(const State& other);
private:
    int m_height;
    int m_width;
    Square** m_squares;
    int m_vacuumX;
    int m_vacuumY;
};


#endif //IA_VACUUM_AGENT_STATE_H
