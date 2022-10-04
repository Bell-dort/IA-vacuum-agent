//
// Created by Bell on 04/10/2022.
//

#include "../header/Sensor.h"

Sensor::Sensor(Environment* environment) {
    env = environment;
    m_obsEnvHeight = env->getHeight();
    m_obsEnvWidth = env->getWidth();

    m_obsSquares = new Square* [m_obsEnvHeight];

    for (int i(0); i < m_obsEnvHeight; i++) {
        m_obsSquares[i] = new Square[m_obsEnvWidth];
    }
}

Sensor::~Sensor() {
    for (int i(0); i < m_obsEnvHeight; i++) {
        delete m_obsSquares[i];
    }

    delete m_obsSquares;
}

void Sensor::observe() {

    std::cout << "Observing..." << std::endl;
    Square** envSquares = env->getSquares();

    for (int i = 0; i < m_obsEnvHeight; ++i) {
        for (int j = 0; j < m_obsEnvWidth; ++j) {
            m_obsSquares[i][j] = Square(envSquares[i][j]);
        }
    }

    m_obsVacuumX = env->getVacuumX();
    m_obsVacuumY = env->getVacuumY();

    displayObsEnv();
}

void Sensor::displayObsEnv() {
    std::string tempLine("");
    std::string hSeparator("----------------------------------------------");

    std::cout << "Sensor's observed env : " << std::endl;
    for (int i(0); i < m_obsEnvHeight; i++) {
        tempLine += "|";
        for (int j = 0; j < m_obsEnvWidth; ++j) {
            tempLine += "D:" + std::to_string(m_obsSquares[i][j].getNbDust()) + " J:" + std::to_string(m_obsSquares[i][j].getNbJewel()) + "|";
        }
        std::cout << tempLine << std::endl;
        tempLine = "";
    }
    std::cout << hSeparator << std::endl << std::endl;
}