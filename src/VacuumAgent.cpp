//
// Created by Bell on 03/10/2022.
//

#include "../header/VacuumAgent.h"

VacuumAgent::VacuumAgent(Environment *environment, int posX, int posY, Square **desire) : m_posX(posX), m_posY(posY), m_sensor(environment), m_beliefs(m_sensor.getObsSquares()), m_desire(desire), m_actuators(environment, &m_posX, &m_posY), m_frequency(0.1) {
}

void VacuumAgent::run() {
    while (1) {

        // Test percepts
/*        m_sensor.observe();
        sleep(0.5/m_frequency);
        m_sensor.displayObsEnv();
        sleep(0.5/m_frequency);*/

        /*sleep(1);
        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        // Testing picking
        std::cout << "Picking..." << std::endl;
        m_actuators.pickUpJewel();
        // Testing cleaning
        std::cout << "Cleaning..." << std::endl;
        m_actuators.cleanSquare();

        // Test movements
        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving right..." << std::endl;
        m_actuators.moveRight();
        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving left..." << std::endl;
        m_actuators.moveLeft();
        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving up..." << std::endl;
        m_actuators.moveUp();
        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving down..." << std::endl;
        m_actuators.moveDown();*/
    }
}