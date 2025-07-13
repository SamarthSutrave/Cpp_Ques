#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    long long minMovesToEqual(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        sort(arr.begin(), arr.end());
        
        long long minMoves = 0;
        if (n % 2 == 1) {

            int median = arr[n / 2];
            for (int x : arr) {
                minMoves += abs(x - median);
            }
        } else {
            // Even length: try both middle elements
            int median1 = arr[(n / 2) - 1]; // First middle element
            int median2 = arr[n / 2];       // Second middle element
            long long moves1 = 0, moves2 = 0;
            for (int x : arr) {
                moves1 += abs(x - median1);
                moves2 += abs(x - median2);
            }
            minMoves = min(moves1, moves2);
        }
        
        return minMoves;

// int sum=0;

//         for(int i = 0; i<n ; i++){
//             sum = sum+arr[i];
//         }
// sum = sum/n;
// for(int i=0;i<n ; i++)
// while()

// }
};

int main() {
    Solution solution;  

    vector<int> arr1 = { 1, 2, 3};
    cout << "Test Case 1: arr = [1, 2, 3]\n";
    cout << "Minimum moves: " << solution.minMovesToEqual(arr1) << "\n"; // Expected: 2
    

    vector<int> arr2 = {1, 2, 9, 10};
    cout << "\nTest Case 2: arr = [1, 2, 9, 10]\n";
    cout << "Minimum moves: " << solution.minMovesToEqual(arr2) << "\n"; // Expected: 16
    
    return 0;
}