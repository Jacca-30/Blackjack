#include "Game.h"
#include <iostream>

void Game::startRound() {
    while(inputBalance == false){
        if (!player.inputBalance()) {
            std::cout << "Insufficient balance to start the game." << std::endl;
        }
        else inputBalance = true;
    }
    if (player.getBalance() <= 0) {
        std::cout << "Insufficient balance to start the game." << std::endl;
        exit(0);
    }
    while(inputBet == false) {
        if (!player.inputBet()) {
            std::cout << "Not enough balance to place a bet." << std::endl;
        }
        else inputBet = true;
    }
    inputBet = false;
    resetShoe();
    resetHands();
    dealInitialCards();
    playerTurn();
    if (player.getHandValue() <= 21) {
        dealerTurn();
    }
    determineWinner();
}
void Game::dealInitialCards() {
    player.receiveCard(shoe.drawCard());
    dealer.receiveCard(shoe.drawCard());
    player.receiveCard(shoe.drawCard());
    dealer.receiveCard(shoe.drawCard());
    std::cout << std::endl << "Your hand: " << std::endl;
    player.showHand();
    dealer.showInitialHand();
    bool pBlackjack = (player.getHandValue() == 21);
    bool dBlackjack = (dealer.getHandValue() == 21);
    if (pBlackjack || dBlackjack) {
        std::cout << std::endl << "Dealer's full hand: " << std::endl;
        dealer.showHand();
        if (pBlackjack && dBlackjack) {
            std::cout << "Both player and dealer have Blackjack. Push!" << std::endl;
            player.returnBet();
        }
        else if (pBlackjack) {
            std::cout << "Blackjack! You win!" << std::endl;
            player.payoutPlayer(true);
        }
        else {
            std::cout << "Dealer has Blackjack. Dealer wins." << std::endl;
        }
        player.outputBalance();
    }
}
void Game::playerTurn() {
    bool firstMove = true;
    while (true) {
        char action = player.takeAction(firstMove);
        if (action == 'h') {
            firstMove = false;
            player.receiveCard(shoe.drawCard());
            std::cout << std::endl << "Your hand: " << std::endl;
            player.showHand();
            if (player.getHandValue() > 21) {
                std::cout << "You bust!" << std::endl;
                break;
            }
        }
        else if (action == 's') {
            firstMove = false;
            std::cout << std::endl << "Your hand: " << std::endl;
            player.showHand();
            break;
        }
        else if (action == 'd' && firstMove) {
            if (!player.doubleBet()) {
                std::cout << "Not enough for double down." << std::endl;
                firstMove = false;
                continue;
            }
            player.receiveCard(shoe.drawCard());
            std::cout << std::endl << "Your hand: " << std::endl;
            player.showHand();
            if (player.getHandValue() > 21) {
                std::cout << "You bust!" << std::endl;
            }
            break;
        }
        else {
            std::cout << "Invalid action. Please choose again." << std::endl;
        }
    }
}
void Game::dealerTurn() {
    std::cout << std::endl << "Dealer's turn: " << std::endl;
    dealer.showHand();
    dealer.playTurn(shoe);
    std::cout << std::endl << "Dealer's final hand: " << std::endl;
    dealer.showHand();
}
void Game::determineWinner() {
    unsigned int playerTotal = player.getHandValue();
    unsigned int dealerTotal = dealer.getHandValue();
    std::cout << std::endl << "Final scores - Player: " << playerTotal << ", Dealer: " << dealerTotal << std::endl;
    if (playerTotal > 21) {
        std::cout << "Dealer wins (player busts)." << std::endl;
    }
    else if (dealerTotal > 21) {
        std::cout << "Player wins (dealer busts)." << std::endl;
        player.payoutPlayer(false);
    }
    else if (playerTotal > dealerTotal) {
        std::cout << "Player wins!" << std::endl;
        player.payoutPlayer(false);
    }
    else if (dealerTotal > playerTotal) {
        std::cout << "Dealer wins." << std::endl;
    }
    else {
        std::cout << "It's a tie (push)." << std::endl;
        player.returnBet();
    }
    player.outputBalance();
}
void Game::resetHands() {
    player.clearHand();
    dealer.clearHand();
}
void Game::resetShoe() {
    shoe.generateShoe();
}