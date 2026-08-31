// Agrim Chaturvedi 25/DA/006

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& arr) {
    for (int i = 0; i < arr.size(); i++)
        arr[i].ratio = (double)arr[i].value / arr[i].weight;

    sort(arr.begin(), arr.end(), compare);

    double totalValue = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        }
        else {
            totalValue += arr[i].value * (double)W / arr[i].weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items and capacity: ";
    cin >> n >> W;
    vector<Item> arr(n);
    cout << "Enter value and weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << "Maximum value: " << fractionalKnapsack(W, arr);

    return 0;
}
