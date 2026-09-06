#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

//declaring functions that will count letters, words and sentences
double calculate_index(float words, float letters, float sentences);
float count_words(string text);
float count_letters(string text);
float count_sentences(string text);


int main(void)
{
    //asking user to input the text, to be evaluated, and storing it in the variable text
    string text = get_string("Text: ");

    //storing the result of the Coleman-Liau formula inside the result variable
    int result = calculate_index(count_words(text), count_letters(text), count_sentences(text));

    //printing in case grade is lesser than 1
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    //in case grade is 16 or above
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    //in case grade is between 1 and 15
    else
    {
        printf("Grade %i\n", result);
    }
}

//function that uses the count_words, count_letters and count_sentences functions and applies them to the Coleman-Liau formula
//and stores the result in the variable index
double calculate_index(float words, float letters, float sentences)
{
    //average number of letters per 100 words
    float average_letters = (letters / words) * 100;
    //average number of sentences per 100 words
    float average_sentences = (sentences / words) * 100;
    //Coleman-Liau formula
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    //rounds the value of index to the closest int; nontheless, it returns a double because of the round() function
    return round(index);
}

//function that takes text as an input and returns the number of words in the text
float count_words(string text)
{
    int space_counter = 0;
    //loop that iterates through the whole text
    for (int j = 0; text[j] != '\0'; j++)
    {
        //conditional that looks for spaces in the text, meaning the separation between words
        if (text[j] == ' ')
        {
            //in case the condition is meeted, space_counter is added 1
            space_counter++;
        }
    }
    //equals to the quantity of words (EG: 4 spaces = 5 words)
    int total_words = space_counter + 1;
    return (float)total_words;
}

//function that takes text as an input and returns the number of letters in the text
float count_letters(string text)
{
    int total_letters = 0;
    for (int k = 0; text[k] != '\0'; k++)
    {
        //conditional that looks for only alphabetical characters
        if (isalpha(text[k]))
        {
            //in case the condition is meeted, the counter total_letters is incremented by 1
            total_letters++;
        }
    }
    return (float)total_letters;
}

//function that takes text as an input and returns the number of sentences in the text
float count_sentences(string text)
{
    int total_sentences = 0;
    for (int l = 0; text[l] != '\0'; l++)
    {
        //conditional that looks for periods, exclamation and interrogation sign; meaning the end of a sentence
        if (text[l] == '.' || text[l] == '!' || text[l] == '?')
        {
            total_sentences++;
        }
    }
    return (float)total_sentences;
}
