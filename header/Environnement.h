//
// Created by Bell on 28/09/2022.
//

#ifndef IA_VACUUM_AGENT_ENVIRONNEMENT_H
#define IA_VACUUM_AGENT_ENVIRONNEMENT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include "Square.h"



class Environnement {
public:
    Environnement();
    Square** getSquares();
    const int getHeight();
    const int getWidth();
    int getJewelSpawnProbability();
    int getDustSpawnProbability();

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
};


#endif //IA_VACUUM_AGENT_ENVIRONNEMENT_H
