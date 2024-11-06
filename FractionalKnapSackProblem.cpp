#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
 

class Item
{
public:
    int weight;
    int value;

    Item(int v, int w)//contructor
    {
        this->weight = w;
        this->value = v;
    }
};

static bool cmp(Item I1, Item I2)
{
    double r1 = (double)I1.value / (double)I1.weight;
    double r2 = (double)I2.value / (double)I2.weight;
    return r1 > r2;
}

double fKnapSack(int capacity,Item arr[],int n)
{
    sort(arr,arr+n,cmp);
    double final_value=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=capacity)
        {
            capacity-=arr[i].weight;
            final_value+=arr[i].value;
        }
        else{
        final_value += arr[i].value * ((double)capacity / arr[i].weight);
            break; 
        }
    }
    return final_value;
}

int main()
{
    int W=50;
    Item I[]={Item(60,10),Item(100,20),Item(120,30)};
    cout<<fKnapSack(W,I,3);
    return 0;
}