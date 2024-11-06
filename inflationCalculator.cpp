#include<iostream>
using namespace std;

float power(float a,int b){
    float ans = 1;
    if(b==0){
        return 1;
    }

    else if(b==1){
        return a;

    }

    else{
        ans *= a;
        ans = power(a,b/2);
    }

    if(b%2==0){
        return (ans *= ans);
    }

    else{
      return ( ans = ans*ans*a);
    }
}

float inflationCalcultor(float cv , float ir , int yr){
 return cv*power(1+ir,yr);
}



int main(){
    cout<<"    Inflation calculator   "<<endl;

    float currentValue;
    cout<<"Enter current value"<<endl;
    cin>>currentValue;

    float inflationRate;
    cout<<"Enter inflation rate"<<endl;
    cin>>inflationRate;
    inflationRate /= 100;

    int years;
    cout<<"Enter years"<<endl;
    cin>>years;

    float futureValue;
    futureValue = inflationCalcultor(currentValue,inflationRate, years);
    cout<<"future value is "<<futureValue;




}