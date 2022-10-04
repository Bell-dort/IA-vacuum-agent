//
// Created by Bell on 04/10/2022.
//

#ifndef IA_VACUUM_AGENT_ACTUATORS_H
#define IA_VACUUM_AGENT_ACTUATORS_H

#include "Environment.h"

class Actuators {
public:
    Actuators(Environment* environment, int* vacuumPosX, int* vacuumPosY);
    void moveRight();
    void moveLeft();
    void moveDown();
    void moveUp();
    void pickUpJewel();
    void cleanSquare();

private:
    Environment* pEnv;
    int* pVacuumPosX;
    int* pVacuumPosY;
};


#endif //IA_VACUUM_AGENT_ACTUATORS_H
