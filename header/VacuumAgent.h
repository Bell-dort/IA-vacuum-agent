//
// Created by Bell on 03/10/2022.
//

#ifndef IA_VACUUM_AGENT_VACUUMAGENT_H
#define IA_VACUUM_AGENT_VACUUMAGENT_H

#include <vector>
#include "Square.h"
#include "Sensor.h"
#include "Actuators.h"
#include "Environment.h"
#include "Action.h"


class VacuumAgent {
public:
    VacuumAgent(Environment *environment, int posX, int posY, Square **desire);
    void run();

private:
    int m_posX = 0;
    int m_posY = 0;
    Square** m_beliefs;
    Square** m_desire;
    std::vector<Actions::Action> m_intents;
    Sensor m_sensor;
    Actuators m_actuators;
    float m_frequency;
};


#endif //IA_VACUUM_AGENT_VACUUMAGENT_H
