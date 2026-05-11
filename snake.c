#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x, y, fruitX, fruitY, score, gameOver;
char dir;

void setup() {
    srand(time(NULL));
    gameOver = 0;
    dir = 'S'; 
    x = 10; y = 10;
    fruitX = rand() % 20; fruitY = rand() % 20;
    score = 0;
}

void draw() {
    printf("\033[H\033[J"); // Clears the screen on online terminals
    for (int i = 0; i < 22; i++) printf("#");
    printf("\n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j == 0) printf("#");
            if (i == y && j == x) printf("O");
            else if (i == fruitY && j == fruitX) printf("F");
            else printf(" ");
            if (j == 19) printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < 22; i++) printf("#");
    printf("\nScore: %d\nMove (w/a/s/d) then Enter: ", score);
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        char input;
        scanf(" %c", &input); // Standard input replacement
        if (input == 'a') x--;
        else if (input == 'd') x++;
        else if (input == 'w') y--;
        else if (input == 's') y++;
        else if (input == 'x') gameOver = 1;

        if (x < 0 || x >= 20 || y < 0 || y >= 20) gameOver = 1;
        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % 20; fruitY = rand() % 20;
        }
    }
    printf("Game Over! Score: %d\n", score);
    return 0;
}
