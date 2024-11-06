#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    char id;
    int dead;
    int profit;

  Job(char i , int d,int p){
    this->id = i;
    this->dead = d;
    this->profit = p;
}

static bool cmp(Job j1 ,Job j2 ){
  return  (j1.profit>j2.profit);
}

void JobScheduling(Job arr[],int n){
    sort(arr,arr+n,cmp);
     
     int result[n];
     bool slot[n];

     for(int i=0;i<n;i++){
        slot[i]=false;
     }


     for(int i=0;i<n;i++){
        for(int j = min(n,arr[i].dead)-1;j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
     }

     for(int i = 0; i < n; i++){
        if (slot[i])
            cout << arr[result[i]].id << " ";
}
}

};

int main()
{
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    arr[0].JobScheduling(arr, n);
    return 0;
}

