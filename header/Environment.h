//
// Created by Bell on 28/09/2022.
//

#ifndef IA_VACUUM_AGENT_ENVIRONMENT_H
#define IA_VACUUM_AGENT_ENVIRONMENT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include "Square.h"



class Environment {
public:
    Environment();
    ~Environment();
    Square** getSquares();
    const int getHeight();
    const int getWidth();
    int getJewelSpawnProbability();
    int getDustSpawnProbability();
    // int getVacuumX();
    // int getVacuumY();
    // void setVacuumX(int x);
    // void setVacuumY(int y);

    void run();
    void generateDust();
    void generateJewel();

    void display();

private:
    Square** m_squares;
    const int m_height;
    int m_width;
    float m_dustSpawnProbability;
    float m_jewelSpawnProbability;
    float m_frequency;
    // int m_vacuumX;
    // int m_vacuumY;
};


#endif //IA_VACUUM_AGENT_ENVIRONMENT_H
