#include "build/include/cs50.h"
#include <string.h> 
#include <stdio.h> 
#include <math.h> 
#include <ctype.h> 


int main(void)
{
    float letters = 0;
    float words = 0; 
    float sentences = 0; 
    float i; 
    float L; 
    float S; 
    float index; 

    string text = get_string("Text: "); //asks for input text 
    
    for (int i = 0; i < strlen(text); i++) //checks string length
    {
        if(text[i] >= 'a' && text[i] <= 'z') //lower case letters
        {
            letters++; 
        }
        
        if(text[i] >= 'A' && text[i] <= 'Z') //upper case letters 
        {
            letters++; 
        }

        if(text[i] == ' ') //counts amount of space between each word 
        {
            words++; 
        }

        if(text[i] == '.' || text[i] == '!' || text[i] == '?') //counts sentences 
        {
            sentences++; 
        }
    } 
    words++; //adds 1, since spaces is 1 less then the actual amount of words 

    L = letters / words * 100; 
    S = sentences / words * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8); //formula

    if(index > 16)
    {
        printf("Grade 16+\n"); 
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n"); 
    }

    printf("%i letter(s), %i word(s), and %i sentence(s).\n", letters, words, sentences); 
    printf("Grade %f\n", round(index)); 
}