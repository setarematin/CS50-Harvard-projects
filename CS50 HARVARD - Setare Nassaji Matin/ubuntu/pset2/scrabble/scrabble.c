#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// I perefer to Define a new array  Ascci code of small letters,So that I do not get involved with the ascci code of the other characters(with an else),and I can understand what is my character.

int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// I perefer to Define a new array for Ascci code of capital letters,So that I do not get involved with the ascci code of the other characters.and I can understand what is my character.
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};


int copute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = copute_score(word1);
    int score2 = copute_score(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins");
    }
    else
    {
        printf("Tie");
    }
}

int copute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++) // the lenght of array : strlen
    {
        // checks if the letter is upper
        if (isupper(word[i]))
        {
            for (int m = 0; m < sizeof(capital_letters); m++)
            {
                if (word[i] == capital_letters[m])
                {
                    score += POINTS[m];


                }
           }
        }
        else if (islower(word[i]))
        {

            for (int m = 0; m < sizeof(small_letters); m++)
            {
                if (word[i] == small_letters[m])
                {
                   score += POINTS[m];

                }
            }
        }
        //we want to ignor other characters.
        else
        {
            i += 1;
        }
    }
    // returns Score
    return score;

}