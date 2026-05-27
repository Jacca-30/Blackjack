#include "Card.h"
#include <iostream>

Card::Card(int v, char s) : value(v), suit(s) {}

NumericCard::NumericCard(int v, char s) : Card(v, s) {}
void NumericCard::showCard() const {
	std::cout << value << " of " << suit << std::endl;
}

FaceCard::FaceCard(char f, int v, char s) : face(f), Card(10,s) {}
void FaceCard::showCard() const {
	std::cout << face << " of " << suit << std::endl;
}

AceCard::AceCard(int v, char s) : Card(11, s) {}
void AceCard::showCard() const {
	std::cout << "Ace of " << suit << std::endl;
}

int Card::getValue() const{
	return value;
}