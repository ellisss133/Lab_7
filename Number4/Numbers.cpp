// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// using namespace std;

// struct BigInt {
//     string value;

//     BigInt(string val = "0") : value(val) {}

//     // сложениее
//     BigInt operator+(const BigInt& other) {
//         string num1 = value, num2 = other.value;
//         if (num1.length() < num2.length()) swap(num1, num2);

//         int carry = 0;
//         string result = "";
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());

//         for (size_t i = 0; i < num2.length(); ++i) {
//             int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
//             result += (sum % 10) + '0';
//             carry = sum / 10;
//         }

//         for (size_t i = num2.length(); i < num1.length(); ++i) {
//             int sum = (num1[i] - '0') + carry;
//             result += (sum % 10) + '0';
//             carry = sum / 10;
//         }

//         if (carry) result += (carry + '0');

//         reverse(result.begin(), result.end());
//         return BigInt(result);
//     }

//     // вычитание
//     BigInt operator-(const BigInt& other) {
//         string num1 = value, num2 = other.value;
//         if (num1.length() < num2.length()) swap(num1, num2);

//         int borrow = 0;
//         string result = "";
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());

//         for (size_t i = 0; i < num2.length(); ++i) {
//             int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
//             if (diff < 0) {
//                 diff += 10;
//                 borrow = 1;
//             } else {
//                 borrow = 0;
//             }
//             result += diff + '0';
//         }

//         for (size_t i = num2.length(); i < num1.length(); ++i) {
//             int diff = (num1[i] - '0') - borrow;
//             if (diff < 0) {
//                 diff += 10;
//                 borrow = 1;
//             } else {
//                 borrow = 0;
//             }
//             result += diff + '0';
//         }

//         while (result.back() == '0' && result.length() > 1) result.pop_back();
//         reverse(result.begin(), result.end());
//         return BigInt(result);
//     }

//     // умножение
//     BigInt operator*(const BigInt& other) {
//         string num1 = value, num2 = other.value;
//         int n1 = num1.length(), n2 = num2.length();
//         vector<int> result(n1 + n2, 0);

//         for (int i = n1 - 1; i >= 0; --i) {
//             for (int j = n2 - 1; j >= 0; --j) {
//                 int mul = (num1[i] - '0') * (num2[j] - '0');
//                 int sum = mul + result[i + j + 1];
//                 result[i + j + 1] = sum % 10;
//                 result[i + j] += sum / 10;
//             }
//         }

//         string res_str = "";
//         for (int num : result) {
//             if (!(res_str.empty() && num == 0)) res_str += to_string(num);
//         }

//         return BigInt(res_str.empty() ? "0" : res_str);
//     }

//     // целочисленное деление
//     BigInt operator/(const BigInt& other) {
//         string num1 = value, num2 = other.value;
//         if (num2 == "0") throw runtime_error("Division by zero");

//         string result = "", current = "";
//         for (char c : num1) {
//             current += c;
//             int quotient = 0;
//             while (compare(current, other.value) >= 0) {
//                 current = subtract(current, other.value);
//                 quotient++;
//             }
//             result += to_string(quotient);
//         }

//         if (result.empty()) return BigInt("0");

//         return BigInt(result);
//     }

//     // сравнение чисел
//     int compare(const string& num1, const string& num2) {
//         if (num1.length() > num2.length()) return 1;
//         if (num1.length() < num2.length()) return -1;
//         return num1.compare(num2);
//     }

//     // вспомогательные функции для работы со строками
//     string subtract(const string& num1, const string& num2) {
//         string res = "";
//         int borrow = 0;
//         int len1 = num1.length(), len2 = num2.length();
//     for (int i = 0; i < len1; i++) {
//             int n1 = num1[len1 - i - 1] - '0';
//             int n2 = (i < len2) ? num2[len2 - i - 1] - '0' : 0;
//             int diff = n1 - n2 - borrow;
//             if (diff < 0) {
//                 diff += 10;
//                 borrow = 1;
//             } else {
//                 borrow = 0;
//             }
//             res += (diff + '0');
//         }

//         reverse(res.begin(), res.end());
//         return res;
//     }

//     // Вывод числа
//     void print() {
//         cout << value << endl;
//     }
// };

// int main() {
//     BigInt num1("12345678901234567890");
//     BigInt num2("98765432109876543210");

//     BigInt sum = num1 + num2;
//     BigInt diff = num2 - num1;
//     BigInt product = num1 * num2;
//     BigInt quotient = num2 / num1;

//     cout << "Sum: ";
//     sum.print();
//     cout << "Difference: ";
//     diff.print();
//     cout << "Product: ";
//     product.print();
//     cout << "Quotient: ";
//     quotient.print();

//     return 0;
// }