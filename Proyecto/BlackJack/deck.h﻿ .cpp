#ifndef BLACK_JACK_DECK_H
#define BLACK_JACK_DECK_H

#include "CARD_H"
#include <vector>
#include <random>
#include <algorithm>

struct Deck {
    vector<Card> cards; // Vector de cartas de la baraja
    Deck();            // Constructor que crea una nueva baraja de cartas
    void shuffle();    // Baraja las cartas
    Card draw();       // Reparte una carta de la baraja
};

#endif //BLACK_JACK_DECK_H

