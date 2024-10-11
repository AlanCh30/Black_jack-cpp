#include <iostream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

const int MazoTam = 52; // Tamaño del mazo
int puntosJugador = 0;
int puntosDealer = 0;
string mensajeJugador = "Las cartas del jugador son: ";
string mensajeDealer = "Las cartas del dealer son: ";
int mazo[MazoTam]; // Arreglo para el mazo de cartas
int cartaMazo = 0; // Índice de la carta actual

void crearMazo() {
    int indice = 0;
    for (int tipoCarta = 0; tipoCarta < 4; tipoCarta++) {
        for (int rango = 1; rango <= 13; rango++) {
            if (rango >= 10) {
                mazo[indice] = 10; // 10, J, Q, K valen 10
            } else {
                mazo[indice] = rango; // 2 a 9 valen su valor
            }
            indice++;
        }
    }
    // Mezclar el mazo
    random_device rd;
    mt19937 gen(rd());
    shuffle(mazo, mazo + MazoTam, gen);
    cartaMazo = 0; // Reiniciar índice
}

int sacarCarta() {
    if (cartaMazo >= MazoTam) {
        cout << "No quedan cartas en el mazo." << endl;
        return 0; // No quedan cartas para repartir
    }

    int carta = mazo[cartaMazo]; // Sacar la carta actual
    cartaMazo++; // Avanzar al siguiente índice
    return carta; // Retornar la carta sacada
}

void repartirCartas() {
    // Repartir dos cartas al jugador
    puntosJugador += sacarCarta();
    puntosJugador += sacarCarta();

    // Repartir dos cartas al dealer
    puntosDealer += sacarCarta();
    puntosDealer += sacarCarta();

    // Mostrar los resultados
    cout << mensajeJugador << puntosJugador << endl;
    cout << mensajeDealer << puntosDealer << endl;
}

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
    crearMazo();
    repartirCartas();
    determinarGanador();

    return 0;
}