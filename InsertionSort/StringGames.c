#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD 30
#define MAX_LINE 256

void PrintByLine();
void PrintByWord();
void PrintWord(char* startOfWord);
void PrintLine();
bool IsWordInLine();

char wordBuffer[MAX_WORD]; 
char lineBuffer[MAX_LINE];

int main()
{ 
    // Read the word 
    fgets(wordBuffer, MAX_WORD, stdin);

    // Read empty line
    fgets(lineBuffer, MAX_LINE, stdin);

    char* firstSpacePtr =(char*) memchr(wordBuffer, ' ', MAX_WORD);
    char operation =  *(firstSpacePtr + 1);
    
    // Convert the word + operation string to word string only by replacing the space with \0
    *firstSpacePtr = '\0';

    if (operation == 'a')
    {
        PrintByLine();
    }
    else 
    {
        PrintByWord();
    }
    
      return 0  ;  
}


void PrintByLine()
{
    while(fgets(lineBuffer, MAX_LINE, stdin) != NULL)
    {
        if(IsWordInLine(lineBuffer , wordBuffer)) // Check if the first line contains the word
        {
            PrintLine(lineBuffer); // Print the first line
        }
    }
}

bool isWhitespace(char c)
{
    return (c == '\t' || c == ' ' || c == '\n' || c == '\0');
}

int lengthOfWord(char* buffer)
{
    int i = 0;
    while (!isWhitespace(buffer[i]))
    {
        i++;
    }

    return i;
}

void PrintByWord()
{
    bool mistakeFound;
    int lineIndex, wordIndex, wordLength, lineLength, testWordLength;
    wordLength = strlen(wordBuffer);
    

    while(fgets(lineBuffer, MAX_LINE, stdin) != NULL)
    {
        lineIndex = 0;
        lineLength = strlen(lineBuffer);

        while (lineIndex < lineLength)
        {
            testWordLength = lengthOfWord(&lineBuffer[lineIndex]);

            if ((testWordLength == wordLength) || (testWordLength == wordLength + 1))
            {
                mistakeFound = false;
                wordIndex = 0;

                while (true)
                {
                    if (!mistakeFound)
                    {
                        // Match
                        if (wordBuffer[wordIndex] == lineBuffer[lineIndex + wordIndex]) {
                            wordIndex++;
                            if (wordIndex == wordLength) {
                                PrintWord(&lineBuffer[lineIndex]);
                                break;
                            }
                        } else { // Mismatch
                            mistakeFound = true;
                        }
                    }
                    else { // Mistake found
                        // Match
                        if (wordBuffer[wordIndex] == lineBuffer[lineIndex + wordIndex + 1]) { 
                            wordIndex++;
                            if (wordIndex == wordLength) {
                                PrintWord(&lineBuffer[lineIndex]);
                                break;
                            }
                        }
                        else { // Second mismatch
                            break;
                        }
                    }
                }
            }

            lineIndex += testWordLength + 1;
        }
    }
}


bool IsWordInLine(char* line ,char* word)
{
     int lineIndex;
     int wordIndex = 0;
    for(lineIndex =  0; (line[lineIndex] != '\n') && (line[lineIndex] != '\0'); lineIndex++)
    { // run over the whole line 
        wordIndex = 0;
        while(line[lineIndex + wordIndex] == word[wordIndex] ) // check if the words are the same
        {// The current char's are equal , this might be our word.
            wordIndex++;
            if(word[wordIndex] == '\0') // If the next word char is \n it means our words match.
                return true;            
        }
    }    
     return false;  
}

void PrintWord(char* startOfWord)
{
    int i;
    for(i =  0; (startOfWord[i] != ' ') && (startOfWord[i] != '\t') && (startOfWord[i] != '\0') && (startOfWord[i] != '\n'); i++)
    {
       printf("%c", startOfWord[i]);
    } 
    printf("\n"); 
}

void PrintLine(char* strartOfLine)
{
    int i;
    for(i =  0; (strartOfLine[i] != '\n') && (strartOfLine[i] != '\0'); i++) // run over the whole line 
    {
       printf("%c", strartOfLine[i]);
    } 
    printf("\n"); 
}