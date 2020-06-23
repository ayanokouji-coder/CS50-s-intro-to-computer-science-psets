#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: "); //prompt the user for the text
    int letterscount = 0;
    int wordcount = 1;
    int sentencecount = 0;

//count letters, words , sentences 
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterscount++;
        }
        else if (text[i] == ' ')
        {
            wordcount++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentencecount++;
        }
    }
    float L = (100 * letterscount) / (float)wordcount;     // letters per 100 words
    float S = (100 * sentencecount) / (float)wordcount;   // sentences per 100 words
    int grade = round(0.0588 * L - 0.296 * S - 15.8);    //Coleman-Liau index 
    if (grade >= 1 && grade < 16) 
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else           //index >= 16
    {
        printf("Grade 16+\n");
    }
}    