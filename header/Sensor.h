//
// Created by Bell on 04/10/2022.
//

#ifndef IA_VACUUM_AGENT_SENSOR_H
#define IA_VACUUM_AGENT_SENSOR_H

#include "Environment.h"

class Sensor {
public:
    Sensor(Environment* environment);
    ~Sensor();
    void observe();

    Square** getObsSquares();
    int getObsSquaresHeight();
    int getObsSquaresWidth();

    void displayObsEnv();

private:
    Environment* env;
    int m_obsEnvHeight;
    int m_obsEnvWidth;
    Square** m_obsSquares;
};


#endif //IA_VACUUM_AGENT_SENSOR_H
