#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void showWord(char[]);
bool isWordComplete(char[]);
void getWord(char[]);

int main() {

    srand(time(NULL)); // Initializes number generator

    int tries = 4; // declare and initialize tries

    printf("LET'S PLAY!\n");

    char word[6]; // increase word size to 6 to account for null character
    char hiddenword[] = {'_', '_', '_', '_', '\0'};

    printf("Guess the word\n%d incorrect tries allowed\n\n", tries);

    getWord(word); // get a random word from the list

    showWord(hiddenword); // show hidden word

    char letter; // declare letter variable
    bool correct = false; // initialize correct flag outside of the loop

    while (tries > 0) {

        printf("Please enter a letter: ");
        scanf(" %c", &letter); // use space before %c to skip white space characters

        for (int i = 0; i < 5; ++i) { // checks if the letter is present in the word
            if (word[i] == letter) {
                hiddenword[i] = letter; //Uncover the hidden letter
                correct = true;
            }
        }

        if (correct == false) { // decrement the number of tries
            tries--;
            printf("Incorrect. You have %d incorrect tries left\n\n", tries);
        } else {
            correct = false; // reset correct flag if it was true
        }

        showWord(hiddenword);
        printf("\n");

        if (isWordComplete(hiddenword) == true) { // check if word is complete
            // set tries to zero
            printf("Well done!\n\n");
            tries = 0; // break out of the loop by setting tries to zero
        }

    }

    if (isWordComplete(hiddenword) == false) {
        printf("Sorry!\nThe word is: \t");
        showWord(word);
    }

    return 0;
}

// function to get word
void getWord(char word[]) {

    char words[10][6] = { // increase word size to 6 to account for null character
        "great",
        "clown",
        "scare",
        "bless",
        "taste",
        "sleep",
        "flush",
        "every",
        "storm",
        "place"
    };

    int random = rand() % 10; // generate a random integer
    for (int i = 0; i < 5; ++i) {
        word[i] = words[random][i];
    }
    word[5] = '\0'; // add null character to end of word
}

// function to reveal word to be guessed
void showWord(char word[]) {
    printf("Word to guess: ");
    for (int i = 0; i < 5; ++i) {
        printf("%c ", word[i]);
    }
}

// function to check if all characters are found
bool isWordComplete(char word[]) {
    for (int i = 0; i < 5; ++i) {
        if (word[i] == '_') {
            return false;
        }
    }
    return true;
}
