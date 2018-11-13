#include <stdlib.h>
#include <stdio.h>
#include "game.h"


void key_input(){
    int n[2];
    scanf("%d %d", &col, &row);
    
    for(size_t i = 0; i <row; i++)
    {
        int temp =0;
        while(temp< col && scanf(" %d", &grid[i][temp]))
        {
            temp++;
        }
    }
    printf("key input compelte\n");
    return;

}


int main(int argc, char const *argv[])
{
    /* code */
    key_input();
    process();
    printGrid();
    return 0;
}
