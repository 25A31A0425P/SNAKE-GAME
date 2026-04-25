#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int x, y, fruitX, fruitY, score;
int gameOver;
char dir;

void setup() {
    gameOver = 0;
    dir = 'S';
    x = 10;
    y = 10;
    fruitX = rand() % 20;
    fruitY = rand() % 20;
    score = 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < 22; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O"); // Snake Head
            else if (i == fruitY && j == fruitX)
                printf("F"); // Fruit
            else
                printf(" ");

            if (j == 19)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < 22; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = 'L';
            break;
        case 'd':
            dir = 'R';
            break;
        case 'w':
            dir = 'U';
            break;
        case 's':
            dir = 'D';
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void logic() {
    switch (dir) {
    case 'L':
        x--;
        break;
    case 'R':
        x++;
        break;
    case 'U':
        y--;
        break;
    case 'D':
        y++;
        break;
    }

    // Collision with wall
    if (x < 0 || x >= 20 || y < 0 || y >= 20)
        gameOver = 1;

    // Fruit eaten
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % 20;
        fruitY = rand() % 20;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    printf("Game Over! Final Score = %d\n", score);
    return 0;
}