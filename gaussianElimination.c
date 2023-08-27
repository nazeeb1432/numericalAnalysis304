#include <stdio.h>
#include<math.h>
#define NMAX 4

int main(){
    int pivot,mp,p;

    double x[NMAX][NMAX+1]={{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};

    for( int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }

    printf("After\n");

    for(int i=0;i<NMAX-1;i++){
        pivot=x[i][i];
        if(pivot==0){
            for(p=i+1;p<NMAX;p++){
                if(x[p][i]!=0.0) break;
            }
            for(int a=0;a<NMAX+1;a++){//swap
                int temp=x[i][a];
                x[i][a]=x[p][a];
                x[p][a]=temp;
            }
        }
        for(int j=i+1;j<NMAX;j++){
            pivot=x[i][i];
            mp=x[j][i]/pivot;
            for(int k=0;k<NMAX+1;k++){
                x[j][k]-=mp*x[i][k];
            }
        }
    }

     for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX+1;j++){
            printf("%0.1lf\t",x[i][j]);
        }printf("\n");
    }
}