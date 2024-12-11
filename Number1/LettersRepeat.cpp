#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("RndmText.txt");
    if (!file.is_open()) {
        cout << "ошибка открытия файла  >:/" << endl;
        return 1;
    }

    int letterFreq[26] = {0};
    int twoLetterFreq[26][26] = {0};

    char prevChar = '\0';
    char currChar;

    while (file.get(currChar)) {
        if (currChar >= 'A' && currChar <= 'Z') {
            currChar = currChar - 'A' + 'a';
        }

        if (currChar >= 'a' && currChar <= 'z') {
            letterFreq[currChar - 'a']++;

            if (prevChar >= 'a' && prevChar <= 'z') {
                twoLetterFreq[prevChar - 'a'][currChar - 'a']++;
            }

            prevChar = currChar;
        } else {
            prevChar = '\0';
        }
    }

    file.close();

    cout << "частота букв:" << endl;
    for (int i = 0; i < 26; i++) {
        if (letterFreq[i] > 0) {
            cout << char('a' + i) << ": " << letterFreq[i] << endl;
        }
    }

    cout << "\nчастота двухбуквенных сочетаний:" << endl;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (twoLetterFreq[i][j] > 0) {
                cout << char('a' + i) << char('a' + j) << ": " << twoLetterFreq[i][j] << endl;
            }
        }
    }

    return 0;
}