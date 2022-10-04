//
// Created by Bell on 30/09/2022.
//

#ifndef IA_VACUUM_AGENT_DISPLAY_H
#define IA_VACUUM_AGENT_DISPLAY_H

#include <iostream>
#include "Environment.h"
#include "Square.h"

class Display {
public:
    Display();
    void consoleRender(Environment env);
};


#endif //IA_VACUUM_AGENT_DISPLAY_H
