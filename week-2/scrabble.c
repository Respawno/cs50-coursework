#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Need each letter/character to have their own score.That will determine each players score.
// Make an array of points
int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype
int compute_score(string word);

int main(void)
{
    // Input from 2 players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Scores that are tracked for each player
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Output that tells which player won. If a tie in points, then is prompted a tie.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Its a tie!\n");
    }
}

int compute_score(string word)
{
    // Start with a score of 0
    int score = 0;
    // We want to calculate every word with using a bunch of loops
    int len = strlen(word);

    // i = 0 means first character
    // i < len = keeps going until every character has been checked
    // i++ means move to the next character each time the loop repeats
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}

// Would just like to end with some final notes because I had some issues with this problem. When using "int compute_score(string word)". The variable for the function is a string and called word.
// In order to use the function I had to call on it for my scores above in the variables score1 and score2.
// The function was also called at the top before main becasue the compiler will then know what function to use when it runs into it later on.
// Personal note/overall feeling: C is a LOT!! Lot more confusing than python or java. Its not as english/readable friendly as other languages.
// But I am having fun coding and learning all the new stuff. Still need my hand held a good majority of the time
// I feel like once I have 45% of the problem running or coded my flow is better forsure.
