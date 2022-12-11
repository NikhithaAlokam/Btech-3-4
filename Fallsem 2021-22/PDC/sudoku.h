#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 16
#define MINIGRIDSIZE 4|

int empty_cells=0;

struct pair_t{
int x,y;

};

typedef struct pair_t pair;
pair empty_cells_list[SIZE*SIZE];

struct queue_element{
    int board[SIZE][SIZE];
    int forward_map[SIZE][SIZE][SIZE];
};

struct queue
{
    struct queue_element **list;
    int size,length;
    int head,tail;
};

int forward_map[SIZE][SIZE][SIZE];
int found = 0;
int **final_board;
int reverse_map_row[SIZE][SIZE][SIZE],reverse_map_column[SIZE][SIZE][SIZE];
int reverse_map_box[SIZE][SIZE][MINIGRIDSIZE][MINIGRIDSIZE];

void init_queue(struct queue *q, int Length)
{
    q->list = malloc(sizeof(struct queue_element*)*length);
    q->head=0;
    q->tail=0;
    q->length=0;
    q->size=length;
}


void push(struct queue *q, struct queue_element *elem)


 

//second pic
{
    if ((q->tail+1)%q->size==(q->head))
    {
        exit(0);
    }
    q->list[q->tail] = elem;
    q->tail = ((q->tail)+1)%(q->size);
    q->length++;
}

struct queue_element* pop(struct queue *q)
{
    if(q->head == q->tail)
    {
      exit(0);
    }
    struct queue_element* ret = q->list[q->head];
    q->head = ((q->head)+1)%(q->size);
    q->length--;
}

void populate_f(int x, int y, int val, int map[SIZE][SIZE][SIZE])
{
    if(val!=0)
    {
        int j,k;
        for(j=0; j<SIZE; j++)
        {
            if(j!=x)
                map[j][y][val-1]=1;
            if(j!=y)
                map[x][j][val-1]=1;
            if(j!=val-1)
                map[x][y][j]=1;
        }
        j=x-x%MINIGRIDSIZE;
        k=y-y%MINIGRIDSIZE;

        int jj,kk;
        for (jj=j;jj<j+MINIGRIDSIZE;jj++)
            for (kk=k;kk<k+MINIGRIDSIZE;kk++)
               if(jj!=x || kk!=y)
                  map[jj][kk][val-1]=1;
    }
 
//3rd pic

}

void dfs_populate_f(int x, int y, int val, int map[SIZE][SIZE][SIZE])
{
    if(val!=0)
    {
        int j,k;
        for(j=0; j<SIZE; j++)
        {
            if (j!=x)
                map[j][y][val-1]=1;
            if(j!=y)
                map[x][j][val-1]=1;
        }
        j=x-x%MINIGRIDSIZE;
        k=y-y%MINIGRIDSIZE;
            
        int jj,kk;
        for (jj=j;jj<j+MINIGRIDSIZE;jj++)
            for (kk=k;kk<k+MINIGRIDSIZE;kk++)
               if(jj!=x || kk!=y)
                  map[jj][kk][val-1]=1;
    }
 
}
 
int findPosition(int x, int y)
{
    int i,single=0,idx=-1;
    for(i=0; i<SIZE; i++)
    {
        if(single)
        {
            if(forward_map[x][y][i] == 0)
                return -1;
        }
        else
        {
            if(forward_map[x][y][i] == 0)
            {
                single = 1;
                idx = i+1;
                
            }
        }
}

return idx;

//4th pic

}

int findCol(int x, int y, int **inp)
{
    int i,single=0,idx=-1;
    for(i=0; i<SIZE; i++)
    {
        if(single)
        {
            if(forward_map[x][i][y] == 0 && inp[x][i]==0)
                return -1;
        }
        else
        {
            if(forward_map[x][i][y] == © && inp[x][i]==0)
            {
                single = 1;
                idx = i;
                
            }
        }
    }
    return idx;
}
int findRow(int x, int y, int **inp)
{
    int i,single=0,idx=-1;
    for(i=0; i<SIZE; i++)
    {
        if(single)
        {
            if(forward_map[i][x][y] == 0 && inp[i][x]==0)
            return -1;
        }
        else
        {
            if(forward_map[il[x][y] == 0 && inp[i][x]==0)
            {
                single = 1;
                idx = i;
                
            }
        }
    }
    return idx;
}

//5th pic

 
pair findcell(int x, int y, int val, int **inp)
{
    int i,j,single=0;
    pair idx;
    idx.x=1;
    for(i=x; i<x+MINIGRIDSIZE; i++)
    {
        for(j=y; j<y+MINIGRIDSIZE; j++)
        {
            if(single)
            {
                if(forward_map[i][j][val] == 0 && inp[i][j]==0)
                {
                    idx.x=-1;
                    idx.y=-1;
                    return idx;
                }
            }
            else
            {
                if(forward_map[i][j][val] == 0 && inp[i][j]==0)
                {
                   single = 1;
                   idx.x = i;
                   idx.y = j;
                    
                }
                
            }
        }
    }
    return idx;
}

void dfs(int board[SIZE][SIZE], int forward_map[SIZE][SIZE][SIZE], int idx)
{
    if(idx==empty_cells)
    {
        found = 1;
        int i,j;
        for(i=0;<SIZE;i++)
            for(j=0;j<SIZE; j++)
                final_board[t][j]=board[i][i];
        return;
    }
    else if(found)
        return;




//6th pic


else
{
    int val;
    for(val=0; val<SIZE; val++)
    {
        int x = empty_cells_list[idx].x;
        int y = empty_cells_list[idx].y;
        if(forward_map[x][y][val]==0)
        {
            int row_bkp[SIZE], col_bkp[SIZE], box_bkp[MINIGRIDSIZE][MINIGRIDSIZE], val_bkp[SIZE];
            int j,k;
            for(j=0; j<SIZE; j++)
            {
                if (j!=x)
                    col_bkp[j]=forward_map[j][y][val];
                if(j!=y)
                    row_bkp[j]=forward_map[x][j][val];
            }
            j=x-x%MINIGRIDSIZE;
            k=y-y%MINIGRIDSIZE;
            int jj,kk;
            for(jj=j; jj<j+MINIGRIDSIZE; jj++)
                for(kk=k;kk<k+MINIGRIDSIZE;kk++)
                    if(jj!=x || kk!=y)
                       box_bkp[jj-j][kk-k]=forward_map[jj][kk][val];
            board[x][y]=val+1;
            dfs_populate_f(x,y,val+1,forward_map);
            dfs(board, forward_map, idx+1) ;
            
            for(j=0;j<SIZE; j++)
            {
                if(j!=x)
                    forward_map[j][y][val]=col_bkp[j];
                if(j!=y)
                    forward_map[x][j][val]=row_bkp[j];
            }
            j=x-x%MINIGRIDSIZE;
            k=y-y%MINIGRIDSIZE;

            for(jj=j;jj<j+MINIGRIDSIZE; jj++)
                for(kk=k;kk<k+MINIGRIDSIZE;kk++)
                    if(jj!=x || kk!=y)
//7th pic
                        forward map[jj][kk][val]=box_bkp[jj-j][kk-k];
            board[x][y]=0;
        }
    }
}
}
 
     


