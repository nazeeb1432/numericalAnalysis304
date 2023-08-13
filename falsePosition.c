#include<stdio.h>
#include<stdlib.h>
# define EPSILON 0.01

double func(double x){
    return x*x*x-x*x+2;
}

void false_Pos(double a,double b){

    if(func(a)*func(b)>=0){
        printf("You have not assumed right a and b\n");
        return;
    }

    double c;

    while((b-a)>=EPSILON){
        
    c = (a*func(b) - b*func(a))/ (func(b) - func(a));
 

        if(func(c)==0){
            break;
        }
        else if(func(c)*func(a)<0){
            b=c;
        }
        else a=c;

    }

    printf("root is %lf\n",c);


}

int main(){

    //initial value assumed;
    double a=-200,b=300;
    false_Pos(a,b);
    return 0;
}