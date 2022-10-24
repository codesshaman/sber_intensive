#include <stdio.h>

int field_l = 80;
int field_w = 25;
int board_w = 3;
int board1_sp_Y = 19;
int board2_sp_Y = 5;
int board1_def_X = 2;
int board2_def_Y = 77;
int ball_sp_X = 40;
int ball_sp_Y = 12;
int start_inp_ex = 5;
int start_inp_sc = 19;
int num_sc_char = 55;
int winscore = 21;

void moveRocket(int *rocket_1_Y, int *rocket_2_Y); //объявление функции для движения ракеток по оси Y
void moveBall(int *ball1_x, int *ball1_y, int *vector_X, int *vector_Y, int *rocket_1_Y, int *rocket_2_Y); //объявление функции для движения мяча: по осям X, Y; переменные для задания вектора движения; переменные для задания положения ракеток по оси Y,
void screenRendering (int *rocket_1_Y, int *rocket_2_Y, int *ball1_x, int *ball1_y, int *scPlayer1, int *scPlayer2); // функция вывода на экран положения элементов игры: поля, сетки, ракеток, положение мяча, положение счетчика очков
int checkTablo(int *scPlayer1, int *scPlayer2, int *ball1_x, int *ball1_y); // функция проверки положения мяча на поле: проверка измения счета игры, проверка изменения положения мяча на поле,
void clearScreen(void); // функция очищения экрана для обновления вывода

int main(void) {
    int rocket_1_Y = board1_sp_Y;
    int rocket_2_Y = board2_sp_Y;

    int ball_X = ball_sp_X;
    int ball_Y = ball_sp_Y;
    int vector_X = -1;
    int vector_Y = 1;

    int score_Player_1 = 0;
    int score_Player_2 = 0;

    while (1) {
        screenRendering(&rocket_1_Y, &rocket_2_Y, &ball_X, &ball_Y, &score_Player_1, &score_Player_2);
        moveRocket(&rocket_1_Y, &rocket_2_Y);
        moveBall(&ball_X, &ball_Y,&vector_X, &vector_Y, &rocket_1_Y, &rocket_2_Y);
        clearScreen();

        if (checkTablo(&score_Player_1, &score_Player_2, &ball_X, &ball_Y)) {
            break;
        }
    }
    return 0;
}

void screenRendering (int *rocket_1_Y, int *rocket_2_Y, int *ball1_x, int *ball1_y, int *scPlayer1, int *scPlayer2) {
    for (int y = 0; y < board_w; ++y) {
        for (int x = 0; x < field_l; ++x) {
            if ((y == 0 && x != 0 && x != field_l - 1) ||
                (y == board_w - 1 && x != 0 && x != field_l - 1)) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != board_w - 1) ||
                        (x == field_l - 1 && y != 0 && y != board_w - 1))) {
                printf("|");
            } else if (x == start_inp_ex) {
                printf("Press \'Control + c\' to exit");
            } else if (x == start_inp_sc) {
                printf("Player one: %d | Player two: %d", *scPlayer1, *scPlayer2);
            }  else if (y == 1 && x < field_l - num_sc_char) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < field_w; ++y) {
        for (int x = 0; x < field_l; ++x) {
            if ((x == board1_def_X &&
                (y == *rocket_1_Y - 1 || y == *rocket_1_Y || y == *rocket_1_Y + 1)) ||
                (x == board2_def_Y &&
                (y == *rocket_2_Y - 1 || y == *rocket_2_Y || y == *rocket_2_Y + 1))) {
                printf("|");
            } else if (x == *ball1_x && y == *ball1_y) {
                printf("o");
            } else if ((y == 0 && x != 0 && x != field_l - 1) ||
                        (y == field_w - 1 && x != 0 && x != field_l - 1)) {
                printf("-");
            } else if ((x == 0 && y != 0 && y != field_w - 1) ||
                        (x == field_l - 1 && y != 0 && y != field_w - 1) ||
                        (x == field_l / 2)) {
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
        case 'z' : ((*rocket_1_Y + 2) != field_w - 1) ? (*rocket_1_Y += 1) : *rocket_1_Y; break;
        case 'k' : ((*rocket_2_Y - 2) != 0) ? (*rocket_2_Y -= 1) : *rocket_2_Y; break;
        case 'm' : ((*rocket_2_Y + 2) != field_w - 1) ? (*rocket_2_Y += 1) : *rocket_2_Y; break;
    }
}

void moveBall(int *ball1_x, int *ball1_y, int *vector_X, int *vector_Y, int *rocket_1_Y, int *rocket_2_Y) {
    if (*ball1_y == 1 || *ball1_y == field_w - 2) {
        *vector_Y = -(*vector_Y);
    }
    if (*ball1_x == board1_def_X + 1 &&
        (*ball1_y == *rocket_1_Y - 1 ||*ball1_y == *rocket_1_Y  || *ball1_y == *rocket_1_Y + 1)) {
        *vector_X = -(*vector_X);
    }
    if (*ball1_x == board2_def_Y - 1 &&
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
        *ball1_x = ball_sp_X;
        *ball1_y = ball_sp_Y;
    }
    if (*ball1_x > field_l - 3) {
        *scPlayer1 += 1;
        *ball1_x = ball_sp_X;
        *ball1_y = ball_sp_Y;
    }
    if (*scPlayer1 == winscore) {
        printf("\n\tCONGRATULATION!!! PLAYER ONE IS WON BY %d TO %d.", *scPlayer1, *scPlayer2);
        return 1;
        }
        else if (*scPlayer2 == winscore) {
        printf("\n\tCONGRATULATION!!! PLAYER TWO IS WON BY %d TO %d.", *scPlayer2, *scPlayer1);
        return 1;
        }
    return 0;
    }

//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, ORGANIC AI