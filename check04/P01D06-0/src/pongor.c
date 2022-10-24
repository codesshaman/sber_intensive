#include <stdio.h>

#define WIDTH_SCRING 82
#define HEIGHT_SCRING 27
#define HEIGHT_SCOPE 3
#define ROCKET1_START_Y 19
#define ROCKET2_START_Y 5
#define ROCKET1_DEFAULT_X 2
#define ROCKET2_DEFAULT_X (WIDTH_SCRING - 3)
#define BALL_START_X (WIDTH_SCRING / 2)
#define BALL_START_Y (HEIGHT_SCRING / 2)
#define START_INPUT_EXIT 5
#define START_INPUT_SCOPE 19
#define NUMBER_SCOPE_CHARACTERS 55
#define WINSCORE 21
#define TRUE 1
#define FALSE 0

void moveRocket(int *rocket_1_Y, int *rocket_2_Y); //объявление функции для движения ракеток по оси Y
void moveBall(int *ball1_x, int *ball1_y, //объявление функции для движения мяча: по осям X, Y;
                int *vector_X, int *vector_Y, //переменные указатели для задания вектора движения;
                const int *rocket_1_Y, const int *rocket_2_Y); //переменные указатели для задания положения ракеток по оси Y, 
void screenRendering(const int *rocket_1_Y, const int *rocket_2_Y, // функция вывода на экран положения элементов игры: поля, сетки, ракеток,
                        const int *ball1_x, const int *ball1_y, // положение мяча
                        int *scPlayer1, int *scPlayer2); // положение счетчика очков
int checkTablo(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y); // функция проверки положения мяча на поле: проверка измения счета игры, проверка изменения положения мяча на поле,
void clearScreen(void); // функция очищения экрана для обновления вывода

int main(void) {
    int rocket_1_Y = ROCKET1_START_Y;
    int rocket_2_Y = ROCKET2_START_Y;

    int ball_X = BALL_START_X;
    int ball_Y = BALL_START_Y;
    int vector_X = -1;
    int vector_Y = 1;

    int score_Player_1 = 0;
    int score_Player_2 = 0;

    while (TRUE) {
        screenRendering(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y,
                                                        &score_Player_1, &score_Player_2);
        moveRocket(&rocket_1_Y, &rocket_2_Y);
        moveBall(&ball_X, &ball_Y,
                    &vector_X, &vector_Y,
                    &rocket_1_Y, &rocket_2_Y);
        clearScreen();

        if (checkTablo(&score_Player_1, &score_Player_2,
                                &ball_X, &ball_Y)) {
            break;
        }
    }
    return 0;
}

void screenRendering(const int *rocket_1_Y, const int *rocket_2_Y,
                    const int *ball1_x, const int *ball1_y,
                    int *scPlayer1, int *scPlayer2) {
    for (int y = 0; y < HEIGHT_SCOPE; ++y) {
        for (int x = 0; x < WIDTH_SCRING; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                (y == HEIGHT_SCOPE - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != HEIGHT_SCOPE - 1) ||
                        (x == WIDTH_SCRING - 1 && y != 0 && y != HEIGHT_SCOPE - 1))) {
                printf("|");
            } else if (x == START_INPUT_EXIT) {
                printf("Press \'Control + c\' to exit");
            } else if (x == START_INPUT_SCOPE) {
                printf("Player one: %d | Player two: %d", *scPlayer1, *scPlayer2);
            }  else if (y == 1 && x < WIDTH_SCRING - NUMBER_SCOPE_CHARACTERS) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < HEIGHT_SCRING; ++y) {
        for (int x = 0; x < WIDTH_SCRING; ++x) {
            if ((x == ROCKET1_DEFAULT_X &&
                (y == *rocket_1_Y - 1 || y == *rocket_1_Y || y == *rocket_1_Y + 1)) ||
                (x == ROCKET2_DEFAULT_X &&
                (y == *rocket_2_Y - 1 || y == *rocket_2_Y || y == *rocket_2_Y + 1))) {
                printf("|");
            } else if (x == *ball1_x && y == *ball1_y) {
                printf("o");
            } else if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                        (y == HEIGHT_SCRING - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
                printf("-");
            } else if ((x == 0 && y != 0 && y != HEIGHT_SCRING - 1) ||
                        (x == WIDTH_SCRING - 1 && y != 0 && y != HEIGHT_SCRING - 1) ||
                        (x == WIDTH_SCRING / 2)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void moveRocket(int *rocket_1_Y, int *rocket_2_Y) {
    char temp;
    switch (temp = getchar()) {
        case 'a' : ((*rocket_1_Y - 2) != 0) ? (*rocket_1_Y -= 1) : *rocket_1_Y; break;
        case 'z' : ((*rocket_1_Y + 2) != HEIGHT_SCRING - 1) ? (*rocket_1_Y += 1) : *rocket_1_Y; break;
        case 'k' : ((*rocket_2_Y - 2) != 0) ? (*rocket_2_Y -= 1) : *rocket_2_Y; break;
        case 'm' : ((*rocket_2_Y + 2) != HEIGHT_SCRING - 1) ? (*rocket_2_Y += 1) : *rocket_2_Y; break;
    }
}

void moveBall(int *ball1_x, int *ball1_y, int *vector_X, int *vector_Y,
                const int *rocket_1_Y, const int *rocket_2_Y) {
    if (*ball1_y == 1 || *ball1_y == HEIGHT_SCRING - 2) {
        *vector_Y = -(*vector_Y);
    }
    if (*ball1_x == ROCKET1_DEFAULT_X + 1 &&
        (*ball1_y == *rocket_1_Y - 1 ||*ball1_y == *rocket_1_Y  || *ball1_y == *rocket_1_Y + 1)) {
        *vector_X = -(*vector_X);
    }
    if (*ball1_x == ROCKET2_DEFAULT_X - 1 &&
        (*ball1_y == *rocket_2_Y - 1 || *ball1_y == *rocket_2_Y  || *ball1_y == *rocket_2_Y + 1)) {
        *vector_X = -(*vector_X);
    }

    *ball1_y += *vector_Y;
    *ball1_x += *vector_X;
}

void clearScreen(void) {
    printf("\33[0d\33[2J");
}

int checkTablo(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y) {
    if (*ball1_x < 2) {
        *scPlayer2 += 1;
        *ball1_x = BALL_START_X;
        *ball1_y = BALL_START_Y;
    }
    if (*ball1_x > WIDTH_SCRING - 3) {
        *scPlayer1 += 1;
        *ball1_x = BALL_START_X;
        *ball1_y = BALL_START_Y;
    }
    if (*scPlayer1 == WINSCORE) {
        printf("\n\tCONGRATULATION!!! PLAYER ONE IS WON BY %d TO %d.", *scPlayer1, *scPlayer2);
        return TRUE;
    } else if (*scPlayer2 == WINSCORE) {
        printf("\n\tCONGRATULATION!!! PLAYER TWO IS WON BY %d TO %d.", *scPlayer2, *scPlayer1);
        return TRUE;
    }
    return FALSE;
}

//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, ORGANIC AI



