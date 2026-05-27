#pragma once

#include "Player.h"
#include "Shoe.h"

class Game {
private:
    Player player;
    Dealer dealer;
    Shoe shoe;
    bool inputBalance = false;
    bool inputBet = false;
public:
    void startRound();
    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void resetHands();
    void resetShoe();
};