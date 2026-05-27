#pragma once

#include "Hand.h"
#include "Shoe.h"

class Player {
protected:
	Hand hand;
    int balance = 0;
    int bet = 0;
public:
    void receiveCard(Card* card);
    void showHand() const;
    void clearHand();
    int getHandValue() const;
    char takeAction(bool isFirst) const;
    bool inputBalance();
    bool inputBet();
    int getBalance() const;
    bool doubleBet();
    void outputBalance() const;
    void payoutPlayer(bool isBJ);
    void returnBet();
};

class Dealer : public Player {
public:
    void playTurn(Shoe& shoe);
    void showInitialHand() const;
};