
#include <stdio.h>
#include <string.h>

#define PC 50
#define QUESTION 4

// Function Declaration
void menu(void);
void clearScreen(void);
void inputname(void);
void play(void);
void score(void);
void allscore(void);
void showQuestion(int playerIndex);
void sortScore(void);

// Struct Player
struct Player {
    int id;
    char name[40];
    int score;
};

// Array of Struct
struct Player S[PC];

int PlayerCount = 0;

// Function Clear Screen
void clearScreen(void) {
    printf("\033[3J\033[2J\033[H");
}

// Function Menu
void menu(void) {
    int choice;

    do {
        
        printf("\n========== QUIZ GAME ==========\n\n");
        printf("1. Player Name\n");
        printf("2. Play Game\n");
        printf("3. Show Player Score\n");
        printf("4. All Score Board\n");
        printf("0. Exit\n");
        printf("\n===============================\n");
        printf("Select Menu: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                inputname();
                break;

            case 2:
                play();
                break;

            case 3:
                score();
                break;

            case 4:
                allscore();
                break;

            case 0:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid Menu! Try again.\n");
        }

    } while (choice != 0);
}

// Function Input Player Name
void inputname(void) {
    int i;

    if (PlayerCount >= PC) {
        printf("\nPlayer is full!\n");
        return;
    }

    printf("\n========== PLAYER NAME ==========\n");

    printf("How many players do you want to add? ");
    scanf("%d", &i);

    if (i <= 0 || i > PC - PlayerCount) {
        printf("\nInvalid number of players!\n");
        return;
    }

    for (int j = 0; j < i; j++) {

        S[PlayerCount].id = PlayerCount + 1;

        printf("\nPlayer ID: %d\n", S[PlayerCount].id);

        printf("Enter Player Name: ");
        scanf(" %39[^\n]", S[PlayerCount].name);

        S[PlayerCount].score = 0;

        PlayerCount++;
    }

    printf("\nInput Player Data Successfully!\n");
}

// Function Play Game
void play(void) {
    int id;

    if (PlayerCount == 0) {
        printf("\nPlease add player first!\n");
        return;
    }

    printf("\n========== SELECT PLAYER ==========\n");

    for (int i = 0; i < PlayerCount; i++) {
        printf("%d. %s\n", S[i].id, S[i].name);
    }

    printf("\nEnter Player ID: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < PlayerCount; i++) {

        if (S[i].id == id) {
            found = 1;

            printf("\nWelcome %s!\n", S[i].name);

            showQuestion(i);

            break;
        }
    }

    if (found == 0) {
        printf("\nPlayer not found!\n");
    }
}

// Function Question & Answer
void showQuestion(int playerIndex) {

    char answer;

    int correct = 0;

    char questions[QUESTION][150] = {
        "What is the capital of Thailand?",
        "How many days are there in a week?",
        "What is 5 + 5?",
        "Which language is used in this program?"
    };

    char choices[QUESTION][4][60] = {
        {"A. Bangkok", "B. Tokyo", "C. Seoul", "D. Beijing"},
        {"A. 5 Days", "B. 6 Days", "C. 7 Days", "D. 8 Days"},
        {"A. 8", "B. 9", "C. 10", "D. 11"},
        {"A. Python", "B. Java", "C. C", "D. HTML"}
    };

    char answers[QUESTION] = {'A', 'C', 'C', 'C'};

    printf("\n========== QUIZ START ==========\n");

    for (int i = 0; i < QUESTION; i++) {

        printf("\nQuestion %d: %s\n", i + 1, questions[i]);

        for (int j = 0; j < 4; j++) {
            printf("%s\n", choices[i][j]);
        }

        printf("\nYour Answer: ");
        scanf(" %c", &answer);

        if (answer >= 'a' && answer <= 'z') {
            answer -= 32;
        }

        if (answer == answers[i]) {
            printf("Correct! +10 Points\n");
            correct++;
        }
        else {
            printf("Wrong Answer! +0 Points\n");
        }
    }

    // Add Score
    S[playerIndex].score += correct * 10;

    printf("\n========== GAME RESULT ==========\n");
    printf("Player : %s\n", S[playerIndex].name);
    printf("Correct: %d / %d\n", correct, QUESTION);
    printf("Score  : %d\n", correct * 10);
    printf("Total Score: %d\n", S[playerIndex].score);
}

// Function Show Individual Score
void score(void) {

    int id;
    int found = 0;

    if (PlayerCount == 0) {
        printf("\nNo Player Data!\n");
        return;
    }

    printf("\nEnter Player ID: ");
    scanf("%d", &id);

    for (int i = 0; i < PlayerCount; i++) {

        if (S[i].id == id) {

            printf("\n========== PLAYER SCORE ==========\n");
            printf("Player ID    : %d\n", S[i].id);
            printf("Player Name  : %s\n", S[i].name);
            printf("Player Score : %d\n", S[i].score);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPlayer not found!\n");
    }
}

// Function Sort Score
void sortScore(void) {

    struct Player temp;

    for (int i = 0; i < PlayerCount - 1; i++) {

        for (int j = 0; j < PlayerCount - i - 1; j++) {

            if (S[j].score < S[j + 1].score) {

                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

// Function All Score Board
void allscore(void) {

    if (PlayerCount == 0) {
        printf("\nNo Player Data!\n");
        return;
    }

    // Sort Array
    sortScore();

    printf("\n============== SCORE BOARD ==============\n");

    printf("%-10s %-20s %-10s\n",
           "Rank", "Player Name", "Score");

    printf("-----------------------------------------\n");

    for (int i = 0; i < PlayerCount; i++) {

        printf("%-10d %-20s %-10d\n",
               i + 1,
               S[i].name,
               S[i].score);
    }

    printf("=========================================\n");
}

// Main Function
int main(void) {

    menu();

    return 0;
}