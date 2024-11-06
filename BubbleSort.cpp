#include<iostream>
using namespace std;
#include<vector>


class Sorting{
    public:
    vector<int>arr;
    int n;
    string S;
   

   Sorting(vector<int> &brr,string s){
    arr = brr;
    n=arr.size();
    S=s;
     }
   private:
   void bubblesort(int n){
    if(n==1){
        return;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    bubblesort(n-1);
}

public:
void print(){
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
}
void sort(){
    if(S=="bubble")
    bubblesort(n);
}

};

int main(){
    vector<int>num = {5,3,4,2,8};
    int k = num.size();
    string st = "bubble" ;
    Sorting S(num,st);
    S.sort();

    S.print();

}