#include <stdlib.h>
#include <stdio.h>
#include "rle.h"

CompressedFullWord A;
CompressedFullWord B;
CompressedFullWord C;

void key_input(){
    int n[3];
    scanf("%d %d %d", n, n+1, n+2);
    setWordLength(&A,n[0]);
    setWordLength(&B,n[1]);
    setWordLength(&C,n[2]);
    
    int temp =0;
    while(temp< n[0] && scanf(" %c %d",&A.data[temp].text , &A.data[temp].num_repeat))
    {
        temp++;
    }
    temp = 0; 
    while(temp< n[1] && scanf(" %c %d",&B.data[temp].text , &B.data[temp].num_repeat))
    {
        temp++;
    }
    temp = 0; 
    while(temp< n[2] && scanf(" %c %d",&C.data[temp].text , &C.data[temp].num_repeat))
    {
        temp++;
    }
    printf("key input compelte\n");
    return;

}

int main()
{

    key_input();
    //printCompressedWord(&A);
    char * decodedA = decode(&A );
    char * decodedB = decode(&B );
    char * decodedC = decode(&C );

    char * resultDecoded = process(decodedA,decodedB,decodedC);
    //printf("%s",resultDecoded);
    CompressedFullWord * result = encoding(resultDecoded);
    printf("\n\n");
    printCompressedWord(result);
    return 0;
}
