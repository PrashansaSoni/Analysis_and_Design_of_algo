
#include<iostream>
using namespace std;

int power(int a, int b){
    int ans =1;
    for(int i=0;i<b/2;i++){
        ans *= a;
    }
     if(b%2==0){
        return (ans *= ans);
    }

    else{
      return ( ans = ans*ans*a);
    }
}

int main(){
   int c= power(2,3);
   cout<<c;
}