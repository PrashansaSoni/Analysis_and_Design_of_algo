#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Knapsack{
  public:

  double weight;
  double profit;
  double profitperweight;


    Knapsack() : weight(0), profit(0), profitperweight(0) {}

  Knapsack(double weight,double profit){
    this->weight = weight;
    this->profit = profit;
    this->profitperweight = profit/weight;
  }

 static void merge(vector<Knapsack>&items,int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
  

  vector<Knapsack>L(n1);
  vector<Knapsack>R(n2);

for(int i=0;i<n1;++i){
    L[i] = items[left+i];
}
    for(int j=0;j<n2;++j){
    R[j] = items[mid+1+j];
    }
int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].profitperweight >= R[j].profitperweight) {
            items[k++] = L[i++];
        } else {
            items[k++] = R[j++];
        }
    }

    while (i < n1) {
        items[k++] = L[i++];
    }

    while (j < n2) {
        items[k++] = R[j++];
    }


  }

  static void mergeSort(vector<Knapsack>& items, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(items, left, mid);
        mergeSort(items, mid + 1, right);

        merge(items, left, mid, right);
    }
}


 static double fractionalKnapsack(vector<Knapsack>& items, double capacity) {
    // Sort items based on profit per weight using merge sort
    mergeSort(items, 0, items.size() - 1);

    double totalProfit = 0.0;
    double remainingCapacity = capacity;

    for (const auto& item : items) {
        if (remainingCapacity == 0) break;

        if (item.weight <= remainingCapacity) {
            // Take the whole item
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            // Take the fraction of the item
            totalProfit += item.profitperweight * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    return totalProfit;
}

  
};


int main() {
    vector<Knapsack>items = {
        Knapsack( 5, 40),
        Knapsack( 15, 135),
        Knapsack( 25, 100)
    };

    double capacity = 35;
    double maxProfit = Knapsack::fractionalKnapsack(items, capacity);

    cout << "Maximum profit that can be obtained: " << maxProfit << endl;

    return 0;
}