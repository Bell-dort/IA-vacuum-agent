//
// Created by Bell on 04/10/2022.
//

#include "../header/State.h"

State::State(Square **squares, int vacuumX, int vacuumY): m_vacuumX(vacuumX), m_vacuumY(vacuumY) {
    int squareRowSize = sizeof squares[0];
    int height = sizeof squares / squareRowSize;
    int width = squareRowSize / sizeof(Square);

    m_squares = new Square * [height];

    for (int i = 0; i < height; ++i) {
        m_squares[i] = new Square[width];
        for (int j = 0; j < width; ++j) {
            m_squares[i][j] = Square(squares[i][j]);
        }
    }
}