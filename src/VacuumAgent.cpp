//
// Created by Bell on 03/10/2022.
//

#include "../header/VacuumAgent.h"

VacuumAgent::VacuumAgent(Environment *environment) : m_sensor(environment), m_frequency(0.1) {
}

void VacuumAgent::run() {
    while (1) {
        m_sensor.observe();
        sleep(0.5/m_frequency);
        m_sensor.displayObsEnv();
        sleep(0.5/m_frequency);
    }
}