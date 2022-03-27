#include <stdio.h>
#include <stdlib.h>

typedef struct BoundedArray
{
    int R, C;
    int **matrix;
} boundedArray;

boundedArray* removeRowsWithSameValue(int R, int C, int *matrix)
{
boundedArray *br =(boundedArray*)malloc(sizeof(boundedArray));

int **mat = (int**)malloc(R* sizeof(int*));

for(int i=0; i<R; i++)
    mat[i] = (int*)malloc(C* sizeof(int));
    
    
int f=1;

int tr=-1;
int tc=-1;

int tpf=1;
for(int i=0; i<R; i++){
    f=0;
    tc=0;
    for(int j=0; j<C-1; j++){
        
        if(matrix[i*C+j] != matrix[i*C + j + 1]){
            f=1;
            tr++;
            break;
        }
        //mat[i][j] = matrix[i*C+j];
    }
    
    if(f){
        tpf=0;
        for(int j=0; j<C; j++){
            mat[tr][j] = matrix[i*C + j];
        }
    }
}

if(tpf){
    mat[0][0] = -1;
    br->R = 1;
    br->C = 1;
    br->matrix = mat;
}
else{
    br->R = tr+1;
    br->C = C;
    br->matrix=mat;
}

return br;
} // End of removeRowsWithSameValue function

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    int matrix[R][C];
    for(int row = 0; row < R; row++)
    {
        for(int col = 0; col < C; col++)
        {
            scanf(" %d", &matrix[row][col]);
        }
    }
    boundedArray *bArr = removeRowsWithSameValue(R, C, matrix);
    if(bArr == NULL)
    {
        printf("Matrix is not formed\n");
    }
    if(bArr->R <= 0 || bArr->C <= 0)
    {
        printf("Invalid size for the revised matrix\n");
    }
    for(int row = 0; row < bArr->R; row++)
    {
        for(int col = 0; col < bArr->C; col++)
        {
            printf("%d ", bArr->matrix[row][col]);
        }
        printf("\n");
    }
    return 0;
} // End of main() function
