#include "PLAYER.h"
#include <iostream>

using namespace std;

Player::Player(std::string name) : name(std::move(name)) {
    hand.reserve(2);
}

void Player::addCard(Card card) {
    hand.push_back(card);
    score += card.value;
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (const auto& card : hand) {
        std::cout << card.getCard() << " "; // Supone que la función getCard() de la clase Card devuelve la representación de la carta.
    }
    std::cout << "\nTotal score: " << score << std::endl;
}