#ifndef PLAYER_H_H
#define PLAYER_H_H

#include "CARD.h"
#include <string>
#include <vector>

using namespace std;

struct Player {
    string name;
    vector<Card> hand;
    int score = 0;

    explicit Player(std::string name);

    void addCard(Card card);

    void showHand() const;
};

#endif //PLAYER_H_H
