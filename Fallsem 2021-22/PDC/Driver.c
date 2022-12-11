#include <stdio.h>
#include <stdlib.h>
#include "sudokuSolver.h"
#include <string.h>
#include <omp.h>
#include <sys/time.h>

int thread_count=4;

int ** readInput(char *filename){
    FILE *infile;
    infile = fopen(filename,"r");
    int i, j;
    char dummyline[SIZE+1];
    char dummy;
    int value;
    int *sudokuGrid = (int)malloc(sizeof(int)*SIZE);
    
    for (i=0;i<SIZE;i++){
        sudokuGrid[i] = (int*)malloc(sizeof(int)*SIZE);
        for(j=0;j<SIZE;j++)
                     sudokuGrid[i][j] =0;
    }
    
   
    
    for (int i=0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            if (feof(infile)){
                if (i != SIZE){
                    printf("The input puzzle has less number of rows than %d. Exiting.\n", SIZE);
                    exit(-1);
                }
            }
            fscanf(infile, "%d", &value);
            if(value >= 0 && value <= SIZE)
                      sudokuGrid[i][j] = value;
            else{
                printf("The input puzzle is not a grid of numbers (0 <= n <= %d) of size %dx%d. Exiting.\n", SIZE, SIZE, SIZE);
                exit(-1);
            }
        }
        fscanf(infile, "%c", &dummy);
        
        if (j > SIZE){
                printf("Row %d has more number of elements than %d. Exiting.\n", i+1, SIZE);
                exit(-1);
        }
    }
    return sudokuGrid;
}






int isValid(int **original, int **solution){
    int valuesSeen[SIZE],i,j,k;
    
    for (i=0;i<SIZE;i++){
        for (k=0;k<SIZE;k++) valuesSeen[k] = 0;
        for (j=0;j<SIZE;j++){
            if (solution[i][j]==0) return 0;
            if ((original[i][j])&&(solution[i][j] != original[i][j])) return 0;
            int v = solution[i][i];
            if (valuesSeen[v-1]==1){
                return 0;
                
            }
            valuesSeen[v-1] = 1;
            
        }
    }

    for (i=0;i<SIZE;i++){
        for (k=0;k<SIZE;k++) valuesSeen[k] = 0;
        for (j=0;j<SIZE;j++){
            int v = solution[j][i];
            if (valuesSeen[v-1]==1){
                return 0;
            }
            valuesSeen[v-1] = 1;
        }
    }

    for (i=0;i<SIZE;i=i+MINIGRIDSIZE){
        for (j=0; j<SIZE; j=j+MINIGRIDSIZE){
            for (k=0;k<SIZE;k++) valuesSeen[k] = 0;
            int r,c;
            for (r=i; r<i+MINIGRIDSIZE; r++)
                for (c=j;c<j+MINIGRIDSIZE;c++){
                    int v = solution[r][c];
                    if (valuesSeen[v-1]==1) {
                        return 0;
                        
                    }
                    valuesSeen[v-1] = 1;
                }
        }
    }
    return 1;
}



int main(){
    printf("Enter path to the input file relative to ~/Desktop/PDC: ");
    char path[50];
    scanf("%s" path);
    
    int **originalGrid = readInput(path);
    int **gridToSolve = readInput(path);
    printf("Enter number of threads: ");
    scanf("%d", athread_count);
    if (thread_count<=0){
        printf("Usage: Thread Count should be positive\n");
    }
    omp_set_num_threads(thread_count);
    
    int i,j;
    printf("\nINPUT GRID\n");
    for (i=0;i<SIZE;i++){
        for (j=0;j<SIZE;j++){
            printf("%d ",originalGrid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    struct timeval start, end;
    gettimeofday(&start, 0);
    
    int **outputGrid = solveSudoku(originalGrid) ;
    gettimeofday(&end, 0);
    int sec = end.tv_sec-start.tv_sec;
    int usec = end.tv_usec-start.tv_usec;
    
    printf("\nOUTPUT GRID\n");
    for (i=0;i<SIZE;i++){
        for (j=0;j<SIZE; j++)
           printf("%d ",outputGrid[i][j]);
        printf("\n");
    }
    printf("\n");
    if (isvalid(originalGrid, outputGrid)){
        printf("SOLUTION FOUND\n");
        printf("Elapsed Time: %lf sec\n", (sec*1000+(usec/1000.0))/1000);
    }
    else{
        printf("No SOLUTION FOUND\n");
    }

}