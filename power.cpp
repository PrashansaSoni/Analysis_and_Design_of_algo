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

int main(){
   float c= power(2.5,2);
   cout<<c;
}