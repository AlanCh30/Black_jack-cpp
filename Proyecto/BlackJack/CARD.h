#ifndef CARD_H
#define CARD_H

#include "ENUMS.h"
#include <string>

struct Card {
    int value;
    Suite suite;
    Figure figure;
    bool isTaken = false;

    explicit Card(Suite suite, Figure figure);

    [[nodiscard]] std::string getCard() const;

    [[nodiscard]] std::string getSuiteDisplay() const;
};

#endif


