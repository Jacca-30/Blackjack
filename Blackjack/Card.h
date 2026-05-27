#pragma once

class Card {
protected:
    int value;
    char suit;
public:
    Card(int v, char s);
    virtual void showCard() const = 0;
    int getValue() const;
};

class NumericCard : public Card {
public:
    NumericCard(int v, char s);
    void showCard() const override;
};

class FaceCard : public Card {
private:
    char face = '_';
public:
    FaceCard(char f, int v, char s);
    void showCard() const override;
};

class AceCard : public Card {
public:
    AceCard(int v, char s);
    void showCard() const override;
};