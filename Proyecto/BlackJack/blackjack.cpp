#include "blackjack.h"
#include "deck.h"
#include <string>
#include <iostream>

using namespace std;

BlackJack::BlackJack() {

    deck.shuffle();
    player.addCard(deck.draw());
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());
    dealer.addCard(deck.draw());
}

void BlackJack::showTable() const {
    player.showHand();
    dealer.showHand();
}

void BlackJack::playerTurn() {
}

void BlackJack::dealerTurn() {
}

[[nodiscard]] Winner BlackJack::getWinner() const {
    if (player.score > 21) {
        return Winner::DEALER;
    } else {
        if (player.score == 21) {
            return Winner::PLAYER;
        } else {
            if (player.score > dealer.score) {
                return Winner::PLAYER;
            } else if (player.score < dealer.score) {
                return Winner::DEALER;
            } else {
                return Winner::DRAW;
            }
        }
    }
}

void BlackJack::showWinner() const {
    string winner = "El ganador es: ";
    switch (getWinner()) {
        case Winner::PLAYER:
            winner += player.name;
        break;
        case Winner::DEALER:
            winner += dealer.name;
        break;
        case Winner::DRAW:
            winner += "Empate";
        break;
    }
    cout << winner << endl;
}
