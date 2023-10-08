#include<bits/stdc++.h>
using namespace std;
#define eps 10.0e-6
#define max 3
 
double matA[max][max+1]={{4,1,1,8},{2,5,2,3},{1,2,4,11}};
double oldX[]={0,0,0};
double newX[]={0,0,0};
double b[max];

bool diagonally_dominant()
{
    double sum;
    int i,j;
    for(int i=0;i<3;i++){
        sum=0;
        double Diagonal=matA[i][i];
        for(j=0;j<3;j++){
            if(j!=i){
                sum+=matA[i][j];
               
            }
        }
        if(sum>=Diagonal){
            cout<<"Not diagonally dominant"<<endl;
            return false;
        }
    }
    return true;
}
void jacobian(){
    int i,j;
    double sum;
    bool done=false;
    int iterator =1;
    while(!done){
        for(i=0;i<3;i++){
            oldX[i]=newX[i];
        }

        for(i=0;i<3;i++){
            sum=0;
            for(j=0;j<3;j++){
                if(j!=i){
                    sum+=matA[i][j]*oldX[j];
                }
            }
            newX[i]=(b[i]-sum)/matA[i][i];
        }
        done=true;
        for(i=0;i<3;i++){
            if(fabs(newX[i]-oldX[i])>eps){
                done=false;
                break;
            }
        }
        if(done){
            for(i=0;i<3;i++){
                cout<<newX[i]<<endl;               
            }
            cout<<iterator<<endl<<endl;
        }
        else{
            iterator++;
        }
    }
}


void gauss_seadle(){
    // oldX[max]={0,0,0};
    // newX[max]={0};
    
    int i,j;
    double sum;
    bool done=false;
    int iterator =1;

    for(i=0;i<3;i++){
        oldX[i]=0;
        newX[i]=0;
    }
    while(!done){
        for(i=0;i<3;i++){
            oldX[i]=newX[i];
        }

        for(i=0;i<3;i++){
            sum=0;
            for(j=0;j<3;j++){
                if(j!=i){
                    sum+=matA[i][j]*newX[j];
                }
            }
            newX[i]=(b[i]-sum)/matA[i][i];
        }
        done=true;
        for(i=0;i<3;i++){
            if(fabs(newX[i]-oldX[i])>eps){
                done=false;
                break;
            }
        }
        if(done){
            for(i=0;i<3;i++){
                cout<<newX[i]<<endl;               
            }
            cout<<iterator<<endl<<endl;
        }
        else{
            iterator++;
        }
    }
}

int main(){
    int i,j;
    for(i=0;i<3;i++){
        b[i]=matA[i][3];
    }
    bool solvable=diagonally_dominant();
    if(solvable){
        jacobian();
        gauss_seadle();
    }
}