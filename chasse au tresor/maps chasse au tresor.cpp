#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calcu chasse au tresore.h"
int cases[width * height];

#define width 4
#define height 4
//c'est pour randomiser un nombre de l'array qui fais 4 par 4 pour savoir se se trouvera le tresor 
int tresor() {
    int randomValue = rand() % (width * height);
    return randomValue;
}
// c'est la suite. la on  utilise le chiffre que l'on a randomiser juste avant pour pour le modifier dans array et on le fais deux fois avec la boucle for  
void randomarray() {
    for (int i = 0; i < 2; ++i) {
        cases[tresor()] = 1;
    }
}

//ici c'est pour dessiner le plateau j'y ai rajoute else if avec un pour pouvoir controle ou sont les tresor il peu etre ammeliore mais je perd c'est fonctionaliter 
void drawplayfield(bool debugmode) 
{
    
    int a = 0;

    std::cout << "pour jouer veuille rentre des nombre compris entre 1 et 4 et en  premier la ligne puis la cologne\n\n";
    std::cout << "\t[1]\t[2]\t[3]\t[4]\n";

    for (int row = 0; row < height; row++) {

        std::cout << "[" << row + 1 << "]\t";

        for (int column = 0; column < width; column++) {

            int case_state = cases[a++];
            if (case_state == 0) {
                std::cout << " -" << '\t';
            }
            else if (case_state == 1)
            {
                if (debugmode == true)
                {
                    std::cout << " p" << '\t';
                }
                else
                {
                    std::cout << " -" << '\t';
                }
                
            }
            else if (case_state == 3)
            {
                std::cout << " $" << '\t';
            }
            else if (case_state == 2)
            {
                std::cout << " O" << '\t';
            }
            else {
                std::cout << " -" << '\t';
            }
        }

        std::cout << '\n';

    }
}

//ici c'est les imput pour controlere la ligne et la colonge j'y ai ajjoute des commande que jai trouve sur internet mais je lais ai pas tres bien compris si je peu avoir un explication ?
int input() {
    int x;
    int y;
    bool validInput = false;
   
    do {
        std::cout << "\nCoordonnees de recherche ?\n";
        std::cout << "x : ";
        if (std::cin >> x) {
            std::cout << "y : ";
            if (std::cin >> y) {
                validInput = true;
            }
            else {
                system("cls");
                drawplayfield();
                std::cout << "\nVeuillez entrer un nombre valide pour 'y'.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            system("cls");
            drawplayfield();
            std::cout << "\nVeuillez entrer un nombre valide pour 'x'.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //. Si l'une des saisies échoue (par exemple, si l'utilisateur entre une lettre au lieu d'un nombre),
        //  nous affichons un message d'erreur, effaçons le flux d'entrée et ignorons les caractères restants jusqu'à la fin de la ligne (std::cin.ignore(...)).
    } while (!validInput);
 

    int index = ((x - 1) * 4 + y) - 1;
    return index;
}