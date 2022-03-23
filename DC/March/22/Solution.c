#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int mat[r][c], b[c], ml;
    
    for(int i=0; i<c; i++)
        b[i] = 0;
        
    for(int i=0; i<r; i++)  
        for(int j=0; j<c; j++)
            scanf("%d", &mat[i][j]);
            
    scanf("%d", &ml);
    
    int balls=0;
    
    for(int i=r-1; i>=0; i--){
        for(int j=0; j<c; j++){
            b[j]+=mat[i][j];
            if(b[j]>=ml){
                balls++;
                b[j]=0;
            }
            
            
        }
       
    }
    printf("%d", balls*ml);
}
