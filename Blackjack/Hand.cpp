#include "Hand.h"
#include <iostream>

Hand::~Hand() {
    clearHand();
}
void Hand::addCard(Card* card) {
    hand.push_back(card);
}
void Hand::clearHand() {
    hand.clear();
}
void Hand::showHand() const {
    for (int i = 0; i < hand.size(); i++) {
        hand[i]->showCard();
    }
}
int Hand::getCardCount() const {
    return static_cast<int>(hand.size());
}
Card* Hand::getCard(int index) const {
    return hand[index];
}