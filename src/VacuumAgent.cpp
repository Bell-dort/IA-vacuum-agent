//
// Created by Bell on 03/10/2022.
//

#include "../header/VacuumAgent.h"

VacuumAgent::VacuumAgent(Environment *environment, int posX, int posY, Square **desire, float frequency) : m_posX(posX), m_posY(posY), m_sensor(environment), m_desire(desire), m_actuators(environment, &m_posX, &m_posY), m_frequency(frequency) {
    m_beliefs = m_sensor.getObsSquares();
}

void VacuumAgent::run() {
    while (1) {
        if (m_intents.empty()) {
            m_sensor.observe();

            if(m_beliefs) {
                State initialState(m_beliefs, m_sensor.getObsSquaresHeight(), m_sensor.getObsSquaresWidth(), m_posX, m_posY);
                State finalState(m_desire, m_sensor.getObsSquaresHeight(), m_sensor.getObsSquaresWidth(), 0, 0);
                Node* solution = GraphSearchStrategy::depthFirstSearch(initialState, finalState);
                std::cout << std::endl << "Computing solution..." << std::endl;
                m_intents = solution->getActionsFromSolution();
                std::cout << std::endl << "Moving..." << std::endl;
            }
        }

        doAction();

        sleep(1/m_frequency);

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
        sleep(1);

        // Testing cleaning
        std::cout << "Cleaning..." << std::endl;
        m_actuators.cleanSquare();

        // Test movements
        sleep(1);

        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving right..." << std::endl;
        m_actuators.moveRight();
        sleep(1);

        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving left..." << std::endl;
        m_actuators.moveLeft();
        sleep(1);

        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving up..." << std::endl;
        m_actuators.moveUp();
        sleep(1);

        std::cout << "X : " + std::to_string(m_posX) + " | Y : " + std::to_string(m_posY) << std::endl;
        std::cout << "Moving down..." << std::endl;
        m_actuators.moveDown();*/
    }
}

void VacuumAgent::doAction() {
    if(m_intents.empty()) {
        return;
    }
    switch (m_intents.front()) {
        case Actions::Action::CLEAN :
            m_actuators.cleanSquare();
            break;

        case Actions::Action::PICK :
            m_actuators.pickUpJewel();
            break;

        case Actions::Action::RIGHT :
            m_actuators.moveRight();
            break;

        case Actions::Action::LEFT :
            m_actuators.moveLeft();
            break;

        case Actions::Action::UP :
            m_actuators.moveUp();
            break;

        case Actions::Action::DOWN :
            m_actuators.moveDown();
            break;
    }

    m_intents.erase(m_intents.begin());
}

bool VacuumAgent::isPosition(int x, int y) {
    return m_posX == x && m_posY == y;
}