#define _CRT_SECURE_NO_WARNINGS
#define pathMult 5
#include <stdio.h>

struct playerInfo{
    char sym;
    int liv;
};
struct gameInfo{
    int move, path, bomb[70], trea[70];
};

int main(void){

    struct playerInfo player;
    struct gameInfo game;
    int i, j;

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
    do{
        printf("Set the path length (a multiple of %d between 10-70): ", pathMult);
        scanf("%d", &game.path);
        if (game.path < 10 || game.path > 70 || game.path % pathMult != 0){
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    }while (game.path < 10 || game.path > 70|| game.path % pathMult != 0);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.move);
        if (game.move < player.liv || game.move > (game.path * 75 / 100)) {
            printf("    Value must be between %d and %d\n", player.liv, (game.path * 75 / 100));
        }

    } while (game.move < player.liv || game.move > (game.path * 75 / 100));

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
        //scanf("%d %d %d %d %d", &game.bomb[i * pathMult], &game.bomb[(i * pathMult) + 1], &game.bomb[(i * pathMult) + 2], &game.bomb[(i * pathMult) + 3], &game.bomb[(i * pathMult) + 4]);
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
        //scanf("%d %d %d %d %d", &game.trea[i * 5], &game.trea[(i * 5) + 1], &game.trea[(i * 5) + 2], &game.trea[(i * 5) + 3], &game.trea[(i * 5) + 4]);
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
    printf("====================================\n");

    return 0;
}