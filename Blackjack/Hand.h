#pragma once

#include "Card.h"
#include <vector>

class Hand {
private:
	std::vector<Card*> hand;
public:
    ~Hand();
    Card* getCard(int index) const;
    void clearHand();
    void addCard(Card* card);
    void showHand() const;
    int getCardCount() const;
};