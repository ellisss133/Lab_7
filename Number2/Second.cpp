#include <iostream>
#include <string>
using namespace std;

// функция для проверки является ли год високосным
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// функция для получения количества дней в месяце
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;  // для февраля
    }
    if (month == 4 || month == 6  || month == 9 || month == 11) {
        return 30;  // для месяцев с 30 днями
    }
    return 31;  // для месяцев с 31 днем
}

// функция для вычисления первого дня года (0 - понедельник ... 6 - воскресенье)
int getStartDayOfYear(int year) {
    int d = 1;  // 1 января
    int m = 1;  // январь

    // если месяц меньше 3 учитываем начало года
    if (m < 3) {
        m += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    // формула Зеллера для вычисления дня недели
    int f = d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    return f % 7; // возвращаем остаток от деления для дня недели
}

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    int startDay = getStartDayOfYear(year);  // определяем день недели для 1 января
    string months[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                       "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

    // проходим по каждому месяцу
    for (int month = 0; month < 12; month++) {
        int daysInMonth = getDaysInMonth(month + 1, year);  // аолучаем количество дней в месяце
        cout << "\n" << months[month] << " " << year << endl;
        cout << " Пн Вт Ср Чт Пт Сб Вс" << endl;

        // печатаем отступы чтобы выровнять первый день месяца
        for (int i = 0; i < startDay; i++) {
            cout << "   ";  // печатаем пустое место
        }

        // печатаем дни месяца
        for (int day = 1; day <= daysInMonth; day++) {
            cout.width(2);  // выравниваем числа дней по ширине 2
            cout << day << " ";
            if (++startDay == 7) {  // если воскресенье, переходим на новую строку
                startDay = 0;
                cout << endl;
            }
        }
        cout << endl;
    }

    return 0;
}