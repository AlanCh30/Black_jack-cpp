#include "CARD.h"
#include <string>

Card::Card(Suite suite, Figure figure) : suite(suite), figure(figure) {
    switch (figure) {
        case Figure::TWO:
            value = 2;
        break;
        case Figure::THREE:
            value = 3;
        break;
        case Figure::FOUR:
            value = 4;
        break;
        case Figure::FIVE:
            value = 5;
        break;
        case Figure::SIX:
            value = 6;
        break;
        case Figure::SEVEN:
            value = 7;
        break;
        case Figure::EIGHT:
            value = 8;
        break;
        case Figure::NINE:
            value = 9;
        break;
        case Figure::TEN:
        case Figure::JACK:
        case Figure::QUEEN:
        case Figure::KING:
            value = 10;
        break;
        case Figure::ACE:
            value = 11;
        break;
    }
}

std::string Card::getCard() const {
    std::string cardDisplay;
    switch (figure) {
        case Figure::JACK:
            cardDisplay = "J";
        break;
        case Figure::QUEEN:
            cardDisplay = "Q";
        break;
        case Figure::KING:
            cardDisplay = "K";
        break;
        case Figure::ACE:
            cardDisplay = "A";
        break;
        default:
            cardDisplay = std::to_string(value);
        break;
    }
    return cardDisplay + getSuiteDisplay();
}

std::string Card::getSuiteDisplay() const {
    std::string suiteDisplay;
    switch (suite) {
        case Suite::HEARTS:
            suiteDisplay = "(C)";
        break;
        case Suite::DIAMONDS:
            suiteDisplay = "(D)";
        break;
        case Suite::CLUBS:
            suiteDisplay = "(T)";
        break;
        case Suite::SPADES:
            suiteDisplay = "(P)";
        break;
    }

    return suiteDisplay;
}
