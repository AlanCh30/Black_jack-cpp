#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

// Enumeraciones para el juego
enum class Winner {
    PLAYER,  // El jugador gana
    DEALER,  // El dealer gana
    DRAW     // Empate
};

enum class Suit {
    HEARTS,   // Corazones
    DIAMONDS, // Diamantes
    CLUBS,    // Tréboles
    SPADES    // Picas
};

enum class Figure {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

// Estructura que representa una carta
struct Card {
    int value;          // Valor de la carta
    Suit suit;         // Palo de la carta
    Figure figure;     // Figura de la carta
    bool isTaken;      // Indica si la carta ha sido tomada por un jugador

    [[nodiscard]] string getCard() const; // Devuelve la carta en formato de texto
    [[nodiscard]] string getSuit() const;  // Devuelve el palo de la carta en formato de texto

    Card();
    explicit Card(Figure figure, Suit suit);
};

// Constructor por defecto
Card::Card() : value(0), suit(Suit::HEARTS), figure(Figure::TWO), isTaken(false) {}

// Constructor que recibe la figura y el palo de la carta
Card::Card(Figure figure, Suit suit) : figure(figure), suit(suit), isTaken(false) {
    value = static_cast<int>(figure); // Asigna el valor correspondiente a la figura
}

// Devuelve la carta en formato de texto
string Card::getCard() const {
    return getSuit() + " " + to_string(value); // Formato de texto de la carta
}

// Devuelve el palo de la carta en formato de texto
string Card::getSuit() const {
    switch (suit) {
        case Suit::HEARTS:   return "Corazones";
        case Suit::DIAMONDS: return "Diamantes";
        case Suit::CLUBS:    return "Treboles";
        case Suit::SPADES:   return "Picas";
        default:             return ""; // Valor por defecto
    }
}

// Estructura que representa un jugador
struct Player {
    int score;               // Puntos del jugador
    vector<Card> cards;      // Cartas del jugador
    string name;            // Nombre del jugador

    void addCard(const Card& card); // Añade una carta al jugador
    void showHand() const;          // Muestra las cartas del jugador

    Player();                       // Constructor por defecto
    explicit Player(string name);   // Constructor que recibe el nombre del jugador
};

// Constructor por defecto
Player::Player() : score(0), name("Jugador") {}

// Constructor que recibe el nombre del jugador
Player::Player(string name) : score(0), name(name) {}

// Estructura que representa la baraja de cartas
struct Deck {
    vector<Card> cards; // Vector de cartas de la baraja

    Deck();            // Constructor que crea una nueva baraja de cartas
    void shuffle();    // Baraja las cartas
    Card draw();       // Reparte una carta de la baraja
};

// Constructor que crea una nueva baraja de cartas
Deck::Deck() {
    for (int s = 0; s < 4; ++s) { // Itera a través de los 4 palos
        for (int f = 2; f <= 11; ++f);
    }
}

// Repartir una carta de la baraja
Card Deck::draw() {
    if (cards.empty()) {
        cout << "No hay más cartas en la baraja." << endl;
        return Card(); // Devuelve una carta vacía si no hay cartas
    }
    Card card = cards.back(); // Toma la última carta
    cards.pop_back();         // Elimina la carta de la baraja
    return card;             // Devuelve la carta
}

// Estructura que representa el juego de Blackjack
struct BlackJack {
    Player player;   // Jugador
    Player dealer;   // Dealer
    Deck deck;       // Baraja

    explicit BlackJack(string playerName); // Constructor de BlackJack

    void showTable();   // Muestra la mesa
    void dealCards();   // Reparte cartas
    [[nodiscard]] Winner getWinner() const; // Obtiene el ganador
    void showWinner() const; // Muestra el ganador
};

// Constructor de BlackJack
BlackJack::BlackJack(string playerName)
    : player(playerName), dealer("Dealer"), deck() {
    deck.shuffle(); // Baraja las cartas al inicio del juego
    dealCards();    // Reparte las cartas al iniciar el juego
}

// Barajar la baraja de cartas
void Deck::shuffle() {
    random_device rd;  // Dispositivo aleatorio
    mt19937 g(rd());   // Generador de números aleatorios
    std::shuffle(cards.begin(), cards.end(), g); // Baraja las cartas
}

// Repartir las cartas iniciales al jugador y al dealer
void BlackJack::dealCards() {
    for (int i = 0; i < 2; ++i) {
        player.addCard(deck.draw()); // Añade una carta al jugador
        dealer.addCard(deck.draw()); // Añade una carta al dealer
    }
}

// Mostrar la mesa
void BlackJack::showTable() {
    cout << "Mesa actual:\n";
    player.showHand(); // Muestra las cartas del jugador
    dealer.showHand(); // Muestra las cartas del dealer
}

// Obtener el ganador
[[nodiscard]] Winner BlackJack::getWinner() const {
    if (player.score > 21) return Winner::DEALER; // Si el jugador se pasa de 21
    if (dealer.score > 21) return Winner::PLAYER; // Si el dealer se pasa de 21
    if (player.score > dealer.score) return Winner::PLAYER; // El jugador gana si tiene más puntos
    if (dealer.score > player.score) return Winner::DEALER; // El dealer gana si tiene más puntos
    return Winner::DRAW; // Si ambos tienen el mismo puntaje
}

// Mostrar el ganador
void BlackJack::showWinner() const {
    Winner winner = getWinner(); // Obtiene el ganador
    switch (winner) {
        case Winner::PLAYER:
            cout << "Jugador gana" << endl;
            break;
        case Winner::DEALER:
            cout << "Dealer gana" << endl;
            break;
        case Winner::DRAW:
            cout << "Empate" << endl;
            break;
    }
}

int main() {
    BlackJack game("Jugador 1");
    game.showTable(); // Muestra la mesa
    game.showWinner(); // Muestra el ganador
    return 0;
}
