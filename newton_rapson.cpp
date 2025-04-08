#include<iostream>
#include<cmath>

using namespace  std;

double fx(double x){
    return pow(x,4)-x-10;
}

double Dfx(double x){
    return 4*pow(x,3)-1;
}


double roots(){
    for(int i = 0; i < 5; i++){
        double f1 = fx(i);
        double f2 = fx(i+1);
        
        if(f1 * f2 < 0){ 
            if(fabs(f1) > fabs(f2)){
                return i + 1;
            } else {
                return i;
            }
        }
    }
}
void NewtonRapson(double x){
    for(int i=0;i<5;i++){
    double x1=x-(fx(x)/Dfx(x));
    int y = fx(x1);
    cout<<"Iteration "<<i+1<<": x = "<<x1<<", fx(x) = "<<y<<"\n";
    if(fabs(x1 - x) < 1e-6){
        break;
    }
    x=x1;
    }
}

int main(){
    double x=roots();
    NewtonRapson(x);
    return 0;
}