#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "PLAYER.h"
#include <string>

struct BlackJack {

    Player player = Player("Jugador");
    Player dealer = Player("Dealer");
    Deck deck;

    BlackJack();

    void showTable() const;

    void playerTurn();

    void dealerTurn();

    [[nodiscard]] Winner getWinner() const;

    void showWinner() const;
};

#endif //BLACKJACK_H
