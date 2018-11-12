#ifndef __RLE_H__
#define __RLE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *str_replace(char *orig, const char *rep, const char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}






typedef struct Word
{
    char text;
    int num_repeat;    
} Word;

typedef struct CompressedFullWord
{
    Word* data;
    int numOfCharacterType;   
} CompressedFullWord;

char* decode(CompressedFullWord * cwf);
void replace(char * a, const char * b,const char * c, int startPoint);



void setWordLength(CompressedFullWord * cfw , int length)
{
    cfw->numOfCharacterType = length;
    cfw->data = malloc(sizeof(Word) * length);
}
void setWord(CompressedFullWord * cfw ,int index, char character, int num_repeat)
{
    cfw->data[index].text = character;
    cfw->data[index].num_repeat = num_repeat;
}
void printCompressedWord(CompressedFullWord * cfw )
{
    for (size_t i = 0; i < cfw->numOfCharacterType; i++)
    {
        printf("%c %d " , cfw->data[i].text , cfw->data[i].num_repeat );    
    }
    printf("\n \n ");
}

char* decode(CompressedFullWord * cwf )
{
    char * decodedWord;
    int wordTotalLength = 0;
    for (size_t i = 0; i < (size_t)cwf->numOfCharacterType; i++)
    {
        wordTotalLength += cwf->data[i].num_repeat;
    }
    decodedWord = (char *)malloc(sizeof(char)*wordTotalLength);
    for (size_t i =0,index = 0; i < (size_t)cwf->numOfCharacterType; i++)
    {
        
        for (size_t j = 0; j < (size_t)cwf->data[i].num_repeat; j++)
        {
            decodedWord[index] = cwf->data[i].text;
            index ++;
        }
    }
    return decodedWord;
}
CompressedFullWord* encoding( char * decodedWord )
{
    //printf("encoding ...\n");
    CompressedFullWord *cwf = malloc(sizeof(CompressedFullWord));
    int i = 0, numOfCharType = 0;
    char curChar = '\0';
    while( i < (int)strlen(decodedWord) )
    {
        if(curChar != decodedWord[i]){
            numOfCharType ++;
            curChar = decodedWord[i];
        }
        i++;
    }
    setWordLength(cwf,numOfCharType);
    i = 0;
    int cwf_index = 0;
    curChar = decodedWord[0];
    int repeatNum = 0;
    while(i < (int)strlen(decodedWord) )
    {
        if(curChar != decodedWord[i])
        {
            setWord(cwf,cwf_index,curChar,repeatNum);
            cwf_index ++;
            repeatNum = 1;
            curChar = decodedWord[i];
        }
        else
        {
            repeatNum ++;    
        }
        i++;
    }
    setWord(cwf,cwf_index,curChar,repeatNum);

    //printf("encoding end\n");
    return cwf;
}

int find(char * a, const char * b,const char * c)
{
    int aLength = (int)strlen(a);
    int bLength = (int)strlen(b);
    int cLength = (int)strlen(c);
    for (size_t i = 0; i < aLength; i++)
    {
        int curIndex = i;
        int matchNum = 0;
        for (size_t j = 0; j < bLength; j++)
        {
            if( curIndex + j > aLength-1)
                break;
            if( a[curIndex + j] == b[j] )
            {
                matchNum ++;
            }
            else
            {
                break;
            }
        }
        if(matchNum == bLength)// find match , curIndex is start point
        {
            printf("curIndex = %d",curIndex);
            str_replace(a,b,c);
            return 1;
            //replace b to c
            //recursively call find and replace
        }
    }
    return 0;
}
void replace(char * a, const char * b,const char * c , int startPoint){
    
}
char * process(char * a, const char *b , const char * c){
    char * result;
    result = str_replace(a,b,c);
    return result;
}
#endif