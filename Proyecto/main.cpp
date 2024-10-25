#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Estructura para representar una carta con su valor y su palo
struct Carta {
    string valor;
    string palo;
};

const int MazoTam = 52; // Tamaño del mazo
int puntosJugador = 0;
int puntosDealer = 0;
string mensajeJugador = "Las cartas del jugador son: ";
string mensajeDealer = "Las cartas del dealer son: ";
vector<Carta> mazo; // Vector para el mazo de cartas
int cartaMazo = 0; // Índice de la carta actual

// Función para crear el mazo de cartas
void crearMazo() {
    string palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"};
    string valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "As"};
    mazo.clear(); // Limpiar el mazo por si ya hay cartas

    // Llenar el mazo con las cartas
    for (int palo = 0; palo < 4; palo++) {
        for (int valor = 0; valor < 13; valor++) {
            Carta carta;
            carta.valor = valores[valor];
            carta.palo = palos[palo];
            mazo.push_back(carta);
        }
    }
}

// Función para mezclar el mazo
void shuffleDeck() {
    random_device rd;
    mt19937 gen(rd());
    shuffle(begin(mazo), end(mazo), gen);  // Mezclar el mazo
    cartaMazo = 0;  // Reiniciar índice
}

// Función para sacar una carta del mazo
Carta sacarCarta() {
    if (cartaMazo >= MazoTam) {
        cout << "No quedan cartas en el mazo." << endl;
        return {"0", "Ninguno"}; // No quedan cartas para repartir
    }

    Carta carta = mazo[cartaMazo]; // Sacar la carta actual
    cartaMazo++; // Avanzar al siguiente índice
    return carta; // Retornar la carta sacada
}

// Función para obtener el valor numérico de una carta
int obtenerValor(Carta carta) {
    if (carta.valor == "J" || carta.valor == "Q" || carta.valor == "K") {
        return 10; // J, Q, K valen 10
    } else if (carta.valor == "As") {
        return 11; // El As vale 11
    } else {
        return stoi(carta.valor); // Convertir el valor numérico de la carta
    }
}

// Función para repartir las cartas y mostrar los resultados
void repartirCartas() {
    // Repartir dos cartas al jugador
    Carta carta1 = sacarCarta();
    Carta carta2 = sacarCarta();
    puntosJugador += obtenerValor(carta1);
    puntosJugador += obtenerValor(carta2);

    // Repartir dos cartas al dealer
    Carta carta3 = sacarCarta();
    Carta carta4 = sacarCarta();
    puntosDealer += obtenerValor(carta3);
    puntosDealer += obtenerValor(carta4);

    // Mostrar los resultados
    cout << mensajeJugador << carta1.valor << " de " << carta1.palo << ", "
         << carta2.valor << " de " << carta2.palo << " (Total: " << puntosJugador << ")" << endl;
    cout << mensajeDealer << carta3.valor << " de " << carta3.palo << ", "
         << carta4.valor << " de " << carta4.palo << " (Total: " << puntosDealer << ")" << endl;
}

// Función para determinar el ganador
void determinarGanador() {
    if (puntosJugador > 21) {
        cout << "Perdiste." << endl;
    } else if (puntosDealer > 21) {
        cout << "Ganaste." << endl;
    } else if (puntosJugador > puntosDealer) {
        cout << "Ganaste." << endl;
    } else if (puntosJugador < puntosDealer) {
        cout << "Perdiste." << endl;
    } else {
        cout << "Empate." << endl;
    }
}

int main() {
    crearMazo();    // Crear el mazo
    shuffleDeck();  // Mezclar el mazo
    repartirCartas();
    determinarGanador();

    return 0;
}
