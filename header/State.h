//
// Created by Bell on 04/10/2022.
//

#ifndef IA_VACUUM_AGENT_STATE_H
#define IA_VACUUM_AGENT_STATE_H

#include "Square.h"

class State {
public:
    State(Square** squares, int vacuumX, int vacuumY);
private:
    Square** m_squares;
    int m_vacuumX;
    int m_vacuumY;
};


#endif //IA_VACUUM_AGENT_STATE_H
