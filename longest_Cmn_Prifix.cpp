
//==================LEETCODE SOLUTION=========================================>

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ans = "";
//         int n = strs.size();
//         if (n == 0) return ans;
//         // Traverse each character of the first string
//         for (int i = 0; i < strs[0].length(); i++) {
//             char ch = strs[0][i];
//             bool match = true;

//             // Compare this character with the corresponding character in other strings
//             for (int j = 1; j < n; j++) {
//                 // If the current string is shorter or characters don't match
//                 if (i >= strs[j].length() || ch != strs[j][i]) {
//                     match = false;
//                     break;
//                 }
//             }

//             // If all strings have the same character at position i, add it to ans
//             if (match) {
//                 ans.push_back(ch);
//             } else {
//                 break;
//             }
//         }
//         return ans;
//     }
// };
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    int n;

    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    string result = solution.longestCommonPrefix(strs);

    if (result.empty()) {
        cout << "There is no common prefix among the strings." << endl;
    } else {
        cout << "The longest common prefix is: " << result << endl;
    }

    return 0;
}
