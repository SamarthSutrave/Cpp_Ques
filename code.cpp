#include <iostream>
#include <cstring> // for strlen
using namespace std;

int main() {
    char str[12];
    cout << "Enter the array: ";
    cin.getline(str, 12);

    // Print each character separated by space
    for (int i = 0; i < strlen(str); i++) {
        cout << str[i] << " ";
    }

    cout << endl;
    return 0;
}
