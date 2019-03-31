#include<iostream>
#include <set>
using namespace std;

enum symbols {ROCK, PAPER, SCISSOR};

set<string> rock = {
        "Kamen",
        "Rock",
        "Pierre",
        "Stein",
        "Ko",
        "Koe",
        "Sasso",
        "Roccia",
        "Guu",
        "Kamien",
        "Piedra"
};
set<string> paper = {
        "Papir",
        "Paper",
        "Feuille",
        "Papier",
        "Papir",
        "Carta",
        "Rete",
        "Paa",
        "Papier",
        "Papel"
};
set<string> scissors = {
        "Nuzky",
        "Scissors",
        "Ciseaux",
        "Schere",
        "Ollo",
        "Olloo",
        "Forbice",
        "Choki",
        "Nozyce",
        "Tijera"
};

int main() {
    string lang_one, lang_two, name_one, name_two;
    string input, play_1, play_2;

    int result1 = 0, result2 = 0;
    int points1 = 0, points2 = 0;
    int games = 0;

    while(true) {
        points1 = 0;
        points2 = 0;


        cin >> lang_one >> name_one;
        cin >> lang_two >> name_two;

        while(true) {
            cin >> input;

            if (input[0] == '-' || input[0] == '.') {
                games++;
                // resultados
                cout << "Game #" <<games <<":" <<endl;
                printf("%s: %d point%s\n", name_one.c_str(), points1, (points1 != 1) ? "s" : "");
                printf("%s: %d point%s\n", name_two.c_str(), points2, (points2 != 1) ? "s" : "");
                if (points1 == points2) {
                	printf("TIED GAME\n");
                }
                else {
                	printf("WINNER: %s\n", (points1 > points2) ? name_one.c_str() : name_two.c_str());
                }
                printf("\n");

                break;
            }

            play_1 = input;
            cin >> play_2;

            result1 = (rock.find(play_1) != rock.end()) ? ROCK : ((scissors.find(play_1) != scissors.end()) ? SCISSOR : PAPER);
            result2 = (rock.find(play_2) != rock.end()) ? ROCK : ((scissors.find(play_2) != scissors.end()) ? SCISSOR : PAPER);

            if ((result1 == ROCK && result2 == SCISSOR) ||
                (result1 == PAPER && result2 == ROCK) ||
                (result1 == SCISSOR && result2 == PAPER))
                points1++;
            else if (result1 != result2)
                points2++;

        }

        if (input[0] == '.')
            break;
    }
    return 0;
}
