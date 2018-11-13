#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int row = 0, col = 0;
int grid[MAX][MAX] = {};
int checkGrid[MAX][MAX] = {};
int score = 0;
void printGrid()
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d " , grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int checkBlock(int blockRow,int blockCol, int x, int y)
{
    int find;
    int curRep = grid[x][y];
    int cnt = 0;
    if (curRep == 0) 
        return 0;
    for(size_t i = 0; i < blockRow; i++)
    {
        for(size_t j = 0; j < blockCol; j++)
        {
            if(x+i > row || y+j > col)
                break;
            if(curRep == grid[x+i][y+j])
                cnt++;
        }
    }
    if(cnt == blockCol * blockRow)
    {
        for(size_t i = 0; i < blockRow; i++)
        {
            for(size_t j = 0; j < blockCol; j++)
            {
                checkGrid[x+i][j+j] = 1;
            }
        }
    }
    return (cnt == blockRow*blockCol) ? 1 : 0 ;
}
void refreshBlock()
{
    for(size_t i = 0; i < row; i++)
    {
        for(size_t j= 0; j < col; j++)
        {
            if(checkGrid[i][j] == 1){
                grid[i][j] = 0;
                score ++;
            }
        }
    }
}
void killBlock(int r,int c , int x, int y)
{
    for(size_t i = 0; i < r; i++)
    {
        for(size_t j = 0; j < c; j++)
        {
            grid[x+i][y+j] = 0 ;
            score ++;
        }
    }
}


void fallDown( int colIndex )
{
    int tempArray[MAX] = {};
    int cnt=0;

    for(int i = row-1; i >= 0; i--)
    {   
        if( grid[i][colIndex] != 0 )
        {
            tempArray[cnt] = grid[i][colIndex];
            cnt++;
            
        }
    }
    for(int i = row-1; i >= 0; i--)
    {
            grid[i][colIndex] = 0;
    }
    
    for(int i = 0 ; i <= cnt; i++)
    {
        grid[row-1-i][colIndex] = tempArray[i];
    }
    
}
void process(){
    int maxBlock = (row>col)? col:row;
    for(size_t i = 0; i < row; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            for(int x = maxBlock-1 ; x >= 2 ; x--)
                
                for(int y = maxBlock-1; y >= 2; y--)
                {
                    if(checkBlock(x,y,i,j)){
                        killBlock(x,y,i,j);
                        for(size_t blockId = 0; blockId < col; blockId++)
                        {
                            fallDown(blockId);
                            printGrid();
                            process();
                            
                        }
                    }
                    
                    
                }
                    
        }
            /* code */
    }
    
}
#endif // !1_ __GAME_H__
