//
// Created by Bell on 04/10/2022.
//

#include "../header/State.h"

State::State(Square **squares, int vacuumX, int vacuumY): m_vacuumX(vacuumX), m_vacuumY(vacuumY) {
    int squareRowSize = sizeof squares[0];
    m_height = sizeof squares / squareRowSize;
    m_width = squareRowSize / sizeof(Square);

    m_squares = new Square * [m_height];

    for (int i = 0; i < m_height; ++i) {
        m_squares[i] = new Square[m_width];
        for (int j = 0; j < m_width; ++j) {
            m_squares[i][j] = Square(squares[i][j]);
        }
    }
}

State::State(const State &other) {
    m_height = other.m_height;
    m_width = other.m_width;

    m_squares = new Square * [m_height];

    for (int i = 0; i < m_height; ++i) {
        m_squares[i] = new Square[m_width];
        for (int j = 0; j < m_width; ++j) {
            m_squares[i][j] = Square(other.m_squares[i][j]);
        }
    }

    m_vacuumX = other.m_vacuumX;
    m_vacuumY = other.m_vacuumY;
}

State* State::nextState(Actions::Action action) {

    State newState = State(m_squares, m_vacuumX, m_vacuumY);
    switch (action) {
        case Actions::Action::CLEAN :
            newState.m_squares[m_vacuumX][m_vacuumY].cleanDust();
            return &newState;
            break;

        case Actions::Action::PICK :
            newState.m_squares[m_vacuumX][m_vacuumY].pickUpJewels();
            return &newState;
            break;

        case Actions::Action::RIGHT :
            if (m_vacuumX < m_width) {
                newState.m_vacuumX++;
                return &newState;
            }
            break;

        case Actions::Action::LEFT :
            if (m_vacuumX > 0) {
                newState.m_vacuumX--;
                return &newState;
            }
            break;

        case Actions::Action::UP :
            if (m_vacuumY > 0) {
                newState.m_vacuumY--;
                return &newState;
            }
            break;

        case Actions::Action::DOWN :
            if (m_vacuumY < m_height) {
                newState.m_vacuumY++;
                return &newState;
            }
            break;
    }
    return nullptr;
}