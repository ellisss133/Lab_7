// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     // открываем файл
//     ifstream file("RndmText.txt");
//     if (!file.is_open()) {
//         cout << "ошибка открытия файла  >:/" << endl;
//         return 1;
//     }

//     int letterFreq[26] = {0};  // массив для частоты букв (26 букв англ алфавита)
//     int twoLetterFreq[26][26] = {0};  // двумерный масив для двухбуквенных сочетаний

//     char prevChar = '\0'; // переменная для хранения предыдущей буквы
//     char currChar; // текущая буква

//     // чтение символов из файла
//     while (file.get(currChar)) {
//         // преобразуем все буквы в маленькие
//         if (currChar >= 'A' && currChar <= 'Z') {
//             currChar = currChar - 'A' + 'a';
//         }

//         //проверяем что это ваще буква
//         if (currChar >= 'a' && currChar <= 'z') {
//             // считаем буквы
//             letterFreq[currChar - 'a']++;

//             // если у нас есть предыдущая буква то считаем сочетание
//             if (prevChar >= 'a' && prevChar <= 'z') {
//                 twoLetterFreq[prevChar - 'a'][currChar - 'a']++;
//             }

//             // обновляем предыдущий символ
//             prevChar = currChar;
//         } else {
//             // если символ не буква то сбрасываем предыдущий символ
//             prevChar = '\0';
//         }
//     }

//     file.close();

//     // вывод частоты букв
//     cout << "частота букв:" << endl;
//     for (int i = 0; i < 26; i++) {
//         if (letterFreq[i] > 0) {
//             cout << char('a' + i) << ": " << letterFreq[i] << endl;
//         }
//     }

//     // вывод частоты двухбуквенных сочетаний
//     cout << "\nчастота двухбуквенных сочетаний:" << endl;
//     for (int i = 0; i < 26; i++) {
//         for (int j = 0; j < 26; j++) {
//             if (twoLetterFreq[i][j] > 0) {
//                 cout << char('a' + i) << char('a' + j) << ": " << twoLetterFreq[i][j] << endl;
//             }
//         }
//     }

//     return 0;
// }