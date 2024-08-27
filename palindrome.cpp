#include<iostream>
using namespace std;

int main(){
    int a, original, reva = 0;
    cout << "Enter the number to check if it's a palindrome: ";
    cin >> a;

    if (a == 0){
        cout << "0 is a palindrome.";
        return 0;
    }

    original = a;

    while(a > 0){
        reva = (reva * 10) + (a % 10);
        a /= 10;
    }

    if (reva == original){
        cout << "The number is a palindrome." << endl;
    }
    else{
        cout << "The number is not a palindrome." << endl;
    }

    return 0;
}

//=====================================leetcode Probelem=======================================// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) {
//             return false;
//         }

//         long reverse = 0;
//         int xcopy = x;

//         while (x > 0) {
//             reverse = (reverse * 10) + (x % 10);
//             x /= 10;
//         }

//         return reverse == xcopy;        
//     }
// };