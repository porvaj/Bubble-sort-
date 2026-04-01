#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);

    int n = str.length();

    for(int i = n - 1; i >= 0; i--) {
        cout << str[i];
    }

    return 0;
}