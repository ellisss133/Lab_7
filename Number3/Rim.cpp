#include <iostream>
#include <string>
#include <map>
using namespace std;

// функция для перевода арабского числа в римское
string arabicToRoman(int num) {
    string result = "";
    // маппинг арабских цифр на римские
    pair<int, string> romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (auto& pair : romanNumerals) {
        while (num >= pair.first) {
            result += pair.second;  // добавляем соответствующий римский символ
            num -= pair.first;      // уменьшаем арабское число
        }
    }
    return result;
}

// функция для перевода римского числа в арабское
int romanToArabic(const string& roman) {
    // маппинг римских цифр на арабские
    map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = roman.size() - 1; i >= 0; --i) {
        char c = roman[i];
        int currentValue = romanValues[c];

        if (currentValue < prevValue) {
            result -= currentValue;  // если текущая цифра меньше предыдущей, вычитаем
        } else {
            result += currentValue;  // иначе прибавляем
        }

        prevValue = currentValue;
    }

    return result;
}

int main() {
    // перевод арабских чисел в римские
    int arabic;
    cout << "Введите арабское число: ";
    cin >> arabic;
    cout << "Римское число: " << arabicToRoman(arabic) << endl;

    // перевод римских чисел в арабские
    string roman;
    cout << "Введите римское число: ";
    cin >> roman;
    cout << "Арабское число: " << romanToArabic(roman) << endl;

    return 0;
}