//
// Created by Bell on 03/10/2022.
//

#ifndef IA_VACUUM_AGENT_VACUUMAGENT_H
#define IA_VACUUM_AGENT_VACUUMAGENT_H

#include "Square.h"
#include "Sensor.h"
#include "Environment.h"


class VacuumAgent {
public:
    VacuumAgent(Environment *environment);
    void run();

private:
    Square** m_beliefs;
    Square** m_desire;
    // Intent;
    Sensor m_sensor;
    float m_frequency;
};


#endif //IA_VACUUM_AGENT_VACUUMAGENT_H
