#define _CRT_SECURE_NO_WARNINGS
#define pathMult 5
#include <stdio.h>

struct playerInfo {
    char sym, hist[70];
    int liv, treaFound;
};
struct gameInfo {
    int move, path, bomb[70], trea[70];
};

int main(void) {

    struct playerInfo player;
    struct gameInfo game;
    int i ,j, nextMov;
    player.treaFound = 0;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c", &player.sym);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.liv);
        if (player.liv < 1 || player.liv > 10) {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.liv < 1 || player.liv > 10);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of %d between 10-70): ", pathMult);
        scanf("%d", &game.path);
        if (game.path < 10 || game.path > 70 || game.path % pathMult != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.path < 10 || game.path > 70 || game.path % pathMult != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.move);
        if (game.move < player.liv || game.move >(game.path * 75 / 100)) {
            printf("    Value must be between %d and %d\n", player.liv, (game.path * 75 / 100));
        }

    } while (game.move < player.liv || game.move >(game.path * 75 / 100));

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", pathMult);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);

    for (i = 0; i < (game.path / pathMult); i++) {
        printf("   Positions [%2d-%2d]: ", 1 + (i * pathMult), (i + 1) * pathMult);
        for (j = 0; j < pathMult; j++) {
            scanf("%d", &game.bomb[(i * pathMult) + j]);
        }
        
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", pathMult);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);
    for (i = 0; i < (game.path / pathMult); i++) {
        printf("   Positions [%2d-%2d]: ", 1 + (i * pathMult), (i + 1) * pathMult);
        for (j = 0; j < pathMult; j++) {
            scanf("%d", &game.trea[(i * pathMult) + j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.sym);
    printf("   Lives      : %d\n", player.liv);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");;
    printf("   Path Length: %d\n", game.path);
    printf("   Bombs      : ");
    for (i = 0; i < game.path; i++) {
        printf("%d", game.bomb[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.path; i++) {
        printf("%d", game.trea[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    for (i = 0; i < game.path; i++) {
        player.hist[i] = '-';
    }
    do {
        if (i == 1) { //Do NOT run this for the first loop
            do {
                printf("Next Move [1-20]: ");
                scanf("%d", &nextMov);
                if (nextMov<1 || nextMov>game.path) {
                    printf("  Out of Range!!!\n");
                }
            } while (nextMov<1 || nextMov>game.path);

            if (player.hist[nextMov - 1] != '-') {
                printf("\n===============> Dope! You've been here before!\n\n");
            }
            else if (game.bomb[nextMov - 1] == 0 && game.trea[nextMov - 1] == 0) {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                player.hist[nextMov - 1] = '.';
                game.move--;
            }
            else if (game.bomb[nextMov - 1] == 1 && game.trea[nextMov - 1] == 0) {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                player.hist[nextMov - 1] = '!';
                game.move--;
                player.liv--;
            }
            else if (game.bomb[nextMov - 1] == 0 && game.trea[nextMov - 1] == 1) {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                player.hist[nextMov - 1] = '$';
                game.move--;
                player.treaFound++;
            }
            else if (game.bomb[nextMov - 1] == 1 && game.trea[nextMov - 1] == 1) {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                player.hist[nextMov - 1] = '&';
                game.move--;
                player.liv--;
                player.treaFound++;
            }
            if (player.liv == 0) {
                printf("No more LIVES remaining!\n\n");
            }
            if (game.move == 0) {
                printf("No more MOVES remaining!\n\n"); //No instruction for this statement in this workshop
            }
            for (i = 0; i < nextMov; i++) {
                printf(" ");
            }
            printf(" %c\n", player.sym);
        }
        printf("  ");
        for (i = 0; i < game.path; i++) {
            printf("%c", player.hist[i]);
        }
        printf("\n  ");
        for (i = 0; i < game.path; i++) {
            if (i == 0 || (i + 1) % 10 != 0) {
                printf("|");
            }
            else {
                printf("%d", (i + 1) / 10);
            }
        }
        printf("\n  ");
        for (i = 0; i < game.path; i++) {
            printf("%d", (i + 1) % 10);
        }

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.liv, player.treaFound, game.move);
        printf("+---------------------------------------------------+\n");
        i = 1;
    } while (player.liv > 0 && game.move > 0);


    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}