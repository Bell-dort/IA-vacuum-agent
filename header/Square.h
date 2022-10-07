//
// Created by Bell on 28/09/2022.
//

#ifndef IA_VACUUM_AGENT_SQUARE_H
#define IA_VACUUM_AGENT_SQUARE_H


class Square {
public:
    Square();
    Square(Square const &other);
    int getNbDust();
    int getNbJewel();
    void addDust();
    void addJewel();
    int pickUpJewels();
    int cleanDust();
    static Square** emptySquares(int height, int width);
    static Square** fullSquares(int height, int width);

    bool operator==(const Square& other);

private:
    int m_nbDust;
    int m_nbJewel;
};


#endif //IA_VACUUM_AGENT_SQUARE_H
