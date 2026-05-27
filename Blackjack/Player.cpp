#include "Player.h"
#include <iostream>

void Player::receiveCard(Card* card) {
    hand.addCard(card);
}
void Player::showHand() const {
    hand.showHand();
}
void Player::clearHand() {
    hand.clearHand();
}
int Player::getHandValue() const {
    int total = 0;
    int aceCount = 0;
    for (int i = 0; i < hand.getCardCount(); i++) {
        Card* card = hand.getCard(i);
        total += card->getValue();
        if (card->getValue() == 11)
            aceCount++;
    }
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}
char Player::takeAction(bool isFirst) const{
    char choice;
    std::cout << "(h)it / (s)tand " ;
    if (isFirst) std::cout << "/ (d)ouble ";
    std::cin >> choice;
    choice = std::tolower(choice);
    if (choice == 'h' || choice == 's') {
        return choice;
    }
    else if (choice == 'd' && isFirst) {
        return choice;
    }
}
void Dealer::playTurn(Shoe& shoe) {
    while (getHandValue() < 17) {
        receiveCard(shoe.drawCard());
    }
}
void Dealer::showInitialHand() const {
    std::cout << "Dealer's visible card: ";
    hand.getCard(1)->showCard();
}
bool Player::inputBalance() {
    std::cout << "Your initial balance: ";
    std::cin >> balance;
    if (balance <= 0) {
        return 0;
    }
    else return 1;
}
bool Player::inputBet() {
    std::cout << "Make a bet: ";
    std::cin >> bet;
    if (bet > balance || bet <= 0) {
        return 0;
    }
    else {
        balance -= bet;
        return 1;
    }
}
void Player::outputBalance() const {
    std::cout << "Current balance: " << balance << '.' << std::endl;
}
void Player::returnBet() {
    balance += bet;
}
void Player::payoutPlayer(bool isBJ) {
    if (isBJ) balance = (balance*3) / 2;
    else balance += bet * 2;
}
int Player::getBalance() const {
    return balance;
}
bool Player::doubleBet() {
    balance -= bet;
    if (balance < 0) {
        balance += bet;
        return 0;
    }
    else {
        bet *= 2;
        return 1;
    }
}