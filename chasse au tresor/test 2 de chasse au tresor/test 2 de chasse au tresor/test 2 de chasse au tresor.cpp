#include <iostream>
#define WIDTH 8
#define HEIGHT 16

int cases[WIDTH * HEIGHT] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void drawPlayfield() {
    int a = 0;
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            int case_state = cases[a++];
            if (case_state == 0) {
                std::cout << '-' << '\t';
            }
            else {
                std::cout << 'x' << '\t';
            }
        }
        std::cout << '\n';
    }
}

int input() {
    int x, y;
    std::cout << "Coordonnées de recherche ?\n";
    std::cout << "x : ";
    std::cin >> x;
    std::cout << "y : ";
    std::cin >> y;
    return y * WIDTH + x; // Calculate the index from coordinates
}

int main() {
    bool treasureFound = false;

    do {
        int idxSearch = input();

        if (cases[idxSearch] == 0) {
            std::cout << "Pas de trésor\n";
        }
        else {
            std::cout << "Trésor trouvé\n";
            treasureFound = true; // Mark the treasure as found
        }

        drawPlayfield();

    } while (!treasureFound);

    return 0;
}
