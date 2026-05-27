#include "Shoe.h"
#include <iostream>
#include <random>
#include <algorithm>

Shoe::Shoe() {
	generateShoe();
}
Shoe::~Shoe() {
    clearShoe();
}

void Shoe::generateShoe() {
    clearShoe();
    nextCardIndex = 0;
    const char suits[4] = { 'H', 'D', 'C', 'S' };
    for (int s = 0; s < 4; s++) {
        for (int rank = 2; rank <= 14; rank++) {
            char suit = suits[s];
            if (rank <= 10) {
                shoe.push_back(new NumericCard(rank, suit));
            }
            else if (rank == 11) {
                shoe.push_back(new FaceCard('J', 10, suit));
            }
            else if (rank == 12) {
                shoe.push_back(new FaceCard('Q', 10, suit));
            }
            else if (rank == 13) {
                shoe.push_back(new FaceCard('K', 10, suit));
            }
            else if (rank == 14) {
                shoe.push_back(new AceCard(11, suit));
            }
        }
    }
    shuffleShoe();
}
void Shoe::clearShoe() {
    for (auto card : shoe) {
        delete card;
    }
    shoe.clear();
}
void Shoe::showShoe() const {
    for (int i = 0; i < shoe.size(); i++) {
        std::cout << '[' << i << "] ";
        shoe[i]->showCard();
    }
}
void Shoe::shuffleShoe() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(shoe.begin(), shoe.end(), rng);
}
Card* Shoe::drawCard() {
    return shoe[nextCardIndex++];
}
int Shoe::getCardIndex() {
    return nextCardIndex;
}