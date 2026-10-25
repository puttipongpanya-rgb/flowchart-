/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>

void showScene1();
void showScene2();
void showScene3();
void showScene4();
void showScene5();
void clearScreen();

void clearScreen() {
    printf("\033[2J\033[H");
}

void showScene1() {
    int choice;

    clearScreen();

    printf("=== My Visual Novel ===\n\n");
    printf("Girl: Hello!\n\n");
    printf("1. Say hello\n");
    printf("2. Walk away\n\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nGirl: Nice to meet you!\n");
    } else if (choice == 2) {
        printf("\nGirl: Oh, okay...\n");
    } else {
        printf("\nInvalid choice, but let's continue.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    showScene2();
}

void showScene2() {
    int choice;

    clearScreen();

    printf("=== Scene 2: Test ===\n\n");
    printf("Girl: Do you want to be friends?\n\n");
    printf("1. Of course!\n");
    printf("2. Maybe later\n\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nGirl: Yay! Thank you!\n");
    } else if (choice == 2) {
        printf("\nGirl: That's okay.\n");
    } else {
        printf("\nInvalid choice, but let's continue.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    showScene3();
}

void showScene3() {
    int choice;

    clearScreen();

    printf("=== Scene 3: Lunch ===\n\n");
    printf("Girl: What do you want to eat?\n\n");
    printf("1. Fried rice\n");
    printf("2. Noodles\n\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nGirl: Fried rice sounds good!\n");
    } else if (choice == 2) {
        printf("\nGirl: I love noodles!\n");
    } else {
        printf("\nInvalid choice, but let's continue.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    showScene4();
}

void showScene4() {
    int choice;

    clearScreen();

    printf("=== Scene 4: After School ===\n\n");
    printf("Girl: Should we go home together?\n\n");
    printf("1. Let's go!\n");
    printf("2. I have something to do\n\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nGirl: Great! Let's go!\n");
    } else if (choice == 2) {
        printf("\nGirl: Okay, see you tomorrow!\n");
    } else {
        printf("\nInvalid choice, but let's continue.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();

    showScene5();
}

void showScene5() {
    int choice;

    clearScreen();

    printf("=== Scene 5: The End ===\n\n");
    printf("Girl: I had a nice day with you!\n\n");
    printf("1. See you tomorrow!\n");
    printf("2. Goodbye!\n\n");
    printf("Choose: ");
    scanf("%d", &choice);

    clearScreen();

    printf("=== My Visual Novel ===\n\n");

    if (choice == 1) {
        printf("Girl: See you tomorrow!\n\n");
        printf("Ending: New Friendship\n");
    } else if (choice == 2) {
        printf("Girl: Goodbye!\n\n");
        printf("Ending: A Nice Day\n");
    } else {
        printf("Ending: The End\n");
    }

    printf("\nThank you for playing!\n");
}

int main() {
    showScene1();

    return 0;
}
