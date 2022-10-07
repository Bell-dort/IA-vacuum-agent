//
// Created by Bell on 28/09/2022.
//

#include "../header/Square.h"

Square::Square(): m_nbDust(0), m_nbJewel(0) {}

Square::Square(Square const &other): m_nbDust(other.m_nbDust), m_nbJewel(other.m_nbJewel) {}

int Square::getNbDust() {
    return m_nbDust;
}

int Square::getNbJewel() {
    return m_nbJewel;
}

void Square::addDust() {
    m_nbDust += 1;
}

void Square::addJewel() {
    m_nbJewel += 1;
}

int Square::cleanDust() {
    int nbDust = m_nbDust;
    m_nbDust = 0;
    m_nbJewel = 0;

    return nbDust;
}

int Square::pickUpJewels() {
    int nbJewel = m_nbJewel;
    m_nbJewel = 0;

    return nbJewel;
}

Square **Square::emptySquares(int height, int width) {
    Square** squares = new Square * [height];
    for (int i = 0; i < height; ++i) {
        squares[i] = new Square[width];
        for (int j = 0; j < width; ++j) {
            squares[i][j] = Square();
        }
    }

    return squares;
}

Square **Square::fullSquares(int height, int width) {
    Square** squares = new Square * [height];
    for (int i = 0; i < height; ++i) {
        squares[i] = new Square[width];
        for (int j = 0; j < width; ++j) {
            squares[i][j] = Square();
            squares[i][j].m_nbJewel = 1;
            squares[i][j].m_nbDust = 1;
        }
    }

    return squares;
}

bool Square::operator==(const Square &other) {
    return m_nbJewel == other.m_nbJewel && m_nbDust == other.m_nbDust;
}