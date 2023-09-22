#include <iostream>
#include <cstdlib>
#include "calcu chasse au tresore.h"
#include <ctime>
int s;

// ici tout se fais au debut sa appelle et genere les trsore puis sa dessine le plateau puis sa demande de metre la ligne et collogne et si utilisateur mets un nombre plus grand sa lui dit pas posiblée 

int main() {

		bool treasurefound = false;
		std::srand(std::time(nullptr));
		randomarray();
		drawplayfield(false);


		do {
			int idxSearch = input();

			if (idxSearch < 16)//bloque le fait que si on a mis plus que 4 * 4 il ne l'acpete pas 
			{
				if (cases[idxSearch] == 0) {
					int pelle = 2;
					cases[idxSearch] = pelle;
					std::cout << "\npas de tresor\n\n";
					j--;
					system("cls");
					std::cout << "\t\t\t\t\t\t\t\t\t\tnombre de vie restant : " << (j - 1) << "\n";
					if (j == 0)
					{
						treasurefound = true;
					}

				}
				else if (cases[idxSearch] == 2) {
					system("cls");
					std::cout << "\t\t\t!!!!!!tu ne peu pas creuser ou tu la deja fais!!!!!!\n\n\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\n\n";
					std::cout << "\t\t\t\t\t\t\t\t\t\tnombre de vie restant : " << (j - 1) << "\n";
				}

				else {
					int pelletrouvetresore = 3;
					cases[idxSearch] = pelletrouvetresore;
					std::cout << "\ntresor\n";
					treasurefound = true;
				}
			}
			else
			{
				system("cls");
				if (idxSearch == 64)
				{
					std::cout << "bien joue mon fillou tu triche\n";
				}
				else
				{
					std::cout << "!!!!!tu ma mis des valeur pour le x ou le y trop elever je te rappel que c'est que entre 1 et 4 qu'il faut metrre !!!!!\n\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\t!!!Attention!!!\n\n";
					std::cout << "\t\t\t\t\t\t\t\t\t\tnombre de vie restant : " << (j - 1) << "\n";
				}

			}
			if (idxSearch == 64)
			{
				drawplayfield(true);
			}
			else
			{
				drawplayfield(false);
			}



		} while (!treasurefound);

		if (j == 0)
		{//affichage quand lon perd
			system("cls");
			std::cout << "\n\n\n\n\n\t\t\t\t\t\tfelicitation vous ete mort \n\n\n";
			std::cout << "⠀      %%% %%%%%%%            |#|" << std::endl;
			std::cout << "    %%%% %%%%%%%%%%%        |#|####" << std::endl;
			std::cout << "  %%%%% %         %%%       |#|=#####" << std::endl;
			std::cout << " %%%%% %   @    @   %%      | | ==####" << std::endl;
			std::cout << "%%%%%% % (_  ()  )  %%     | |    ===##" << std::endl;
			std::cout << "%%  %%% %  \_    | %%      | |       =##" << std::endl;
			std::cout << "%    %%%% %  u^uuu %%     | |         ==#" << std::endl;
			std::cout << "      %%%% %%%%%%%%%      | |           V" << std::endl;
			std::cout << "note moi : ";
			std::cin >> s;
			std::cout << "bas code moi par ce que je suis pas aassez fort pour faire sa ";
		}
		else
		{//affichage quand lon gagne plus dessin 
			system("cls");
			std::cout << "\n\n\n\n\n\t\t\t\t\t\tfelicitation vous avez trouve le tresor\n\n\n";

			printf("    *             _____          ..-~---------------- ~-..-~\n");
			printf("   * *           |     |   \~~~\.'                    `./~~~/\n");
			printf("  *   *         ---------   \__/                        \__/\n");
			printf(" *     *       .'  O    \     /               /       \  '\n");
			printf("*       *     (_____,    `._.'               |         }  \/~~~/\n");
			printf("*********      `----.          /       }     |        /    \__/\n");
			printf("*       *            `-.      |       /      |       /      `. ,~~|\n");
			printf("*       *                ~-.__|      /_ - ~ ^|      /- _      `..-'\n");
			printf("*       *                     |     /        |     /     ~-.     `-. _  _  _\n");
			printf("*********                     |_____|        |_____|         ~ - . _ _ _ _ _>\n");
			std::cout << "note moi: ";
			std::cin >> s;
			std::cout << "bas code moi par ce que je suis pas aassez fort pour faire sa ";
		}
		
	}




