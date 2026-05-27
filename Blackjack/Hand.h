#pragma once

#include <vector>

class Card;

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