//
// Created by Bell on 04/10/2022.
//

#include "../header/State.h"

State::State(Square **squares, int squaresHeight, int squaresWidth, int vacuumX, int vacuumY): m_vacuumX(vacuumX), m_vacuumY(vacuumY) {
    m_height = squaresHeight;
    m_width = squaresWidth;

    m_squares = new Square * [m_height];

    for (int i = 0; i < m_height; ++i) {
        m_squares[i] = new Square[m_width];
        for (int j = 0; j < m_width; ++j) {
            m_squares[i][j] = Square(squares[i][j]);
        }
    }
}

/*State::State(const State &other) {
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
}*/

State* State::nextState(Actions::Action action) {

    State* pState = nullptr;
    State newState = State(m_squares, m_height, m_width, m_vacuumX, m_vacuumY);
    switch (action) {
        case Actions::Action::CLEAN :
            newState.m_squares[m_vacuumX][m_vacuumY].cleanDust();
            pState = &newState;
            break;

        case Actions::Action::PICK :
            newState.m_squares[m_vacuumX][m_vacuumY].pickUpJewels();
            pState = &newState;
            break;

        case Actions::Action::RIGHT :
            if (m_vacuumX < m_width - 1) {
                newState.m_vacuumX++;
                pState = &newState;
            }
            break;

        case Actions::Action::LEFT :
            if (m_vacuumX > 0) {
                newState.m_vacuumX--;
                pState = &newState;
            }
            break;

        case Actions::Action::UP :
            if (m_vacuumY > 0) {
                newState.m_vacuumY--;
                pState = &newState;
            }
            break;

        case Actions::Action::DOWN :
            if (m_vacuumY < m_height - 1) {
                newState.m_vacuumY++;
                pState = &newState;
            }
            break;
    }

    return pState;
}

bool State::operator==(const State &other) {

    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            if (!(m_squares[i][j] == other.m_squares[i][j])) {
                return false;
            }
        }
    }

    return true;
}