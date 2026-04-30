#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// index = 0.0588 * L - 0.296 * S - 15.8
// L = Average number of letters per 100 words in text
// S = Average number of sentences per 100 words in the text.
int find_letters(string letters);
int find_sentences(string sentences);
int find_words(string text);

int main(void)
{
    // The input of text the user will put in, in order to find the grade level
    string user_text = get_string("Text : ");

    // Making variables for the letters and sentences to help find the index
    int letters = find_letters(user_text);
    int sentences = find_sentences(user_text);
    int words = find_words(user_text);

    // Letters and sentences are both floating so we don't have truncated division. I kept getting the wrong index number because I didn't have it.
    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    float index = (0.0588 * L - 0.296 * S - 15.8);

    // Rounding the result of the index to the nearest whole number
    int grade = round(index);

    // Easiest way to write all the grade levels needed. I wrote out all the if statements and realized that was way too much and way too messy. Whoops...
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16 and up\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

// We need to find the number of letters per 100 words in the text.
int find_letters(string text)
{
    int count = 0;
    int len = 0;
    // This while loops looks for the letters in the string. The "\0" is the nul character. There is one at the end of every string which is why we are able to count the letters.
    while (text[len] != '\0')
    {
        if (isalpha(text[len]))
        {
            count++;
        }
        len++;
    }
    return count;
}

// We also need to find the number of sentences per 100 words in the text
int find_sentences(string text)
{
    int sen = 0;
    int count = 0;
    while (text[sen] != '\0')
    {
        // Best practice to search for multiple characters using pipes.
        if (text[sen] == '.' || text[sen] == '?' || text[sen] == '!')
        {
            count++;
        }
        sen++;
    }
    return count;
}

// Lastly we need to find the amount of words in text
int find_words(string text)
{
    // words variable is the index aka i. I replaced it with words because it was easier for me to read. Same thing was repeated on the other functions.
    int words = 0;
    int count = 1;
    while (text[words] != '\0')
    {
        if (text[words] == ' ')
        {
            count++;
        }
        words++;
    }
    return count;
}
