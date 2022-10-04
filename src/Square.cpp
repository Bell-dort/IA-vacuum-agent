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
