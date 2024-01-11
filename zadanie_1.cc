#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canFormTinkoff(const string& letters) {
    string tinkoff = "TINKOFF";
    unordered_map<char, int> letterCount;

    for (char c : letters) {
        letterCount[c]++;
    }

    for (char c : tinkoff) {
        if (letterCount[c] > 0) {
            letterCount[c]--;
        } else {
            return false;
        }
    }

    for (auto& pair : letterCount) {
        if (pair.second > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string letters;
        cin >> letters;

        cout << (canFormTinkoff(letters) ? "Yes" : "No") << endl;
    }

    return 0;
}