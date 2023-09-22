#include <iostream>
#include <cstdlib> // Ajoutez cette ligne
#include <ctime>
#define width 4
#define height 4

int cases[width * height];

// Fonction pour générer la grille avec des valeurs aléatoires de 0 ou 1
void randomarray() {
    for (int i = 0; i < width * height; ++i) {
        cases[i] = tresor();
    }
}

// Fonction pour afficher la grille
void drawplayfield() {
    int a = 0;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            int case_state = cases[a++];
            std::cout << case_state << ' ';
        }
        std::cout << '\n';
    }
}

int tresor() {
    std::srand(std::time(nullptr));
    int randomValue = rand() % 2;
    return randomValue;
}

int main() {
    randomarray();
    drawplayfield();

    return 0;
}
