#ifndef DECK_H
#define DECK_H

#include "CARD.h"
#include <vector>

using namespace std;

struct Deck {
    vector<Card> cards; // Vector de cartas de la baraja
    Deck();            // Constructor que crea una nueva baraja de cartas
    void shuffle();    // Baraja las cartas
    Card draw();       // Reparte una carta de la baraja
};

#endif
