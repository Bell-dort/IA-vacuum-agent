//
// Created by Bell on 28/09/2022.
//

#include "../header/Environnement.h"

Environnement::Environnement(): m_height(5), m_width(5), m_dustSpawnProbability(0.3f), m_jewelSpawnProbability(0.2f), m_frequency(1) {
    m_squares = new Square * [m_width];

    for (int i(0); i < m_width; i++) {
        m_squares[i] = new Square[m_height];
    }

    srand(time(NULL));
}

void Environnement::run() {
    float spawningJewel;
    float spawningDust;
    while (1) {
        spawningDust = float(rand() % 10)/10;
        spawningJewel = float(rand() % 10)/10;

        std::cout << "sJ: " + std::to_string(spawningJewel) + "pJ : " + std::to_string(m_jewelSpawnProbability) << std::endl;
        if (spawningJewel < m_jewelSpawnProbability) {
            generateJewel();
        }
        std::cout << "sD: " + std::to_string(spawningDust) + "pD : " + std::to_string(m_dustSpawnProbability) << std::endl;

        if (spawningDust < m_dustSpawnProbability) {
            generateDust();
        }

        sleep(1/m_frequency);
    }
}

void Environnement::generateDust() {
    int randX = rand() % 5;
    int randY = rand() % 5;
    m_squares[randX][randY].addDust();
    display();
}

void Environnement::generateJewel() {
    int randX = rand() % 5;
    int randY = rand() % 5;
    m_squares[randX][randY].addJewel();
    display();
}

void Environnement::display() {
    std::string tempLine("");
    std::string hSeparator("----------------------------------------------");

    for (int i(0); i < m_height; i++) {
        tempLine += "|";
        for (int j = 0; j < m_width; ++j) {
            tempLine += "D:" + std::to_string(m_squares[i][j].getNbDust()) + " J:" + std::to_string(m_squares[i][j].getNbJewel()) + "|";
        }
        std::cout << tempLine << std::endl;
        tempLine = "";
    }
    std::cout << hSeparator << std::endl << std::endl;
}

Square** Environnement::getSquares() {
    return m_squares;
}

int const Environnement::getHeight() {
    return m_height;
}

int const Environnement::getWidth() {
    return m_width;
}

int Environnement::getDustSpawnProbability() {
    return m_dustSpawnProbability;
}

int Environnement::getJewelSpawnProbability() {
    return m_jewelSpawnProbability;
}


