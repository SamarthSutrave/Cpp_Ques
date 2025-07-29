// #include<bits/stdc++.h>
// using namespace std;

// int countnum(string s){
//     sort(s.begin(),s.end());
// int n = s.length();
// for(int i = 0 ; i < n ; ){
//     int count =1;
//     while( i +count < n && s[i]==s[i+count]){
//         count++;
//     }
//      if (count > 1) {
//             cout << "['" << s[i] << "', " << count << "], ";
//         }
//         i += count;

// }
// }

// int main(){
//      string s = "geeksforgeeks";

//     countnum(s);

//     return 0;

// }
// C++ Code to print duplicate characters 
// and their counts using Sorting 
#include <bits/stdc++.h>
using namespace std;

// Function to print duplicate characters with their count
void printDuplicates(string s) {

    // Sort the string to group same characters together
    sort(s.begin(), s.end());

    // Traverse the sorted string to count duplicates
    for (int i = 0; i < s.length();) {

        int count = 1;

        // Count occurrences of current character
        while (i + count < s.length() && s[i] == s[i + count]) {
            count++;
        }

        // If count > 1, print the character and its count
        if (count > 1) {
            cout << "['" << s[i] << "', " << count << "], ";
        }

        // Move to the next different character
        i += count;
    }
}

int main() {

    string s = "geeksforgeeks";

    printDuplicates(s);

    return 0;
}