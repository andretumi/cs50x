#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Prints the winner or tie
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
        printf("Tie!\n");
    }
}

//function that returns the score of the inputed word
int compute_score(string word)
{
    //variable that stores the total score of the word (remains as 0 in case of not inputing a letter)
    int score = 0;
    //loop that iterates through all the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        //data casting each letter of the string(word) to char and uppercase
        char letter = toupper(word[i]);
        //transforming the char(letter) to its respective ASCII value and substracting 65, because A's ASCII value is 65
        //and by doing so, getting its respective index in the POINTS array
        int index = letter - 65;
        //conditional to prove if the char(letter) is in the POINTS array and is capable to add to the score
        if (index >= 0 && index < 26)
        {
            //adding the letter value to the score
            score += POINTS[index];
        }
    }
    //returning the value of score to print the final result in the main function
    return score;
}
