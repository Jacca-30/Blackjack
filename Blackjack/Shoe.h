#pragma once

#include <vector>

class Card;

class Shoe {
private:
    std::vector<Card*> shoe;
    int nextCardIndex;
    static const int size = 52;
public:
    Shoe();
    ~Shoe();
    void generateShoe();
    void clearShoe();
    void shuffleShoe();
    void showShoe() const;
    int getCardIndex();
    Card* drawCard();
};