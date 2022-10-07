//
// Created by Bell on 30/09/2022.
//

#ifndef IA_VACUUM_AGENT_DISPLAY_H
#define IA_VACUUM_AGENT_DISPLAY_H

#include <iostream>
#include "Environment.h"
#include "VacuumAgent.h"
#include "Square.h"

class Display {
public:
    Display();
    Display(Environment* env, VacuumAgent* vacuum, float frequency);
    void run();
    void consoleRender();
private:
    Environment* pEnv;
    VacuumAgent* pVacuum;
    float m_frequency;
};


#endif //IA_VACUUM_AGENT_DISPLAY_H
