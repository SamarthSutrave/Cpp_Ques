
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

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // If the array is empty, return an empty string
        if (strs.empty()) return "";

        // Initialize the prefix to the first string
        std::string prefix = strs[0];

        // Traverse the array of strings
        for (int i = 1; i < strs.size(); i++) {
            // Find the common prefix between prefix and strs[i]
            while (strs[i].find(prefix) != 0) {
                // Reduce the prefix by one character
                prefix = prefix.substr(0, prefix.length() - 1);
                // If no common prefix exists, return an empty string
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs;
    int n;

    // Taking user input for the number of strings
    std::cout << "Enter the number of strings: ";
    std::cin >> n;

    // Taking user input for the strings
    std::cout << "Enter the strings:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        strs.push_back(str);
    }

    // Finding the longest common prefix
    std::string result = solution.longestCommonPrefix(strs);

    // Displaying the result
    if (result.empty()) {
        std::cout << "There is no common prefix among the strings." << std::endl;
    } else {
        std::cout << "The longest common prefix is: " << result << std::endl;
    }

    return 0;
}
