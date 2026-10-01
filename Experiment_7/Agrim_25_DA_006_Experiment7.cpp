// Agrim Chaturvedi 25/DA/006
#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}
void printMaxActivities(Activity arr[], int n) {
    sort(arr, arr + n, activityCompare);

    cout << "Selected activities are: " << endl;

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main() {
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}

