// 7. Перерахування
// Група: Комп-мат2
// Прізвище: Дідик Олексій
// У цьому файлі реалізовано перелік задач, пов'язаних з перерахуваннями (enum),
// включаючи друк значень, порівняння карт, конвертацію довжин, відмінювання слів, підрахунок складів,
// та розрахунок руху корабля.

#include "Enumeration.h"
#include <iostream>
#include <map>
using namespace std;

// Друк днів тижня
void printDay(DaysOfWeek day) {
    // Масив назв днів тижня
    static const string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << days[static_cast<int>(day)] << endl;
}

// Друк місяців
void printMonth(Months month) {
    // Масив назв місяців
    static const string months[] = {"January", "February", "March", "April", "May", "June",
                                    "July", "August", "September", "October", "November", "December"};
    cout << months[static_cast<int>(month)] << endl;
}

// Друк кольорів спектру
void printColor(SpectrumColor color) {
    // Масив кольорів спектру
    static const string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
    cout << colors[static_cast<int>(color)] << endl;
}

// Друк назв шахових фігур
void printChessPiece(ChessPiece piece) {
    // Масив назв шахових фігур
    static const string pieces[] = {"King", "Queen", "Rook", "Bishop", "Knight", "Pawn"};
    cout << pieces[static_cast<int>(piece)] << endl;
}

// Функція для порівняння двох карт, враховуючи козирну масть
bool beat(const Card& x, const Card& y, Suit trump) {
    // Якщо карти однієї масті — порівняти за рангом
    if (x.suit == y.suit) {
        return static_cast<int>(x.rank) > static_cast<int>(y.rank);
    }
    // Козирна карта завжди перемагає
    return x.suit == trump;
}

// Конвертація довжини у метри
float convertToMeters(float value, LengthUnit unit) {
    // Використання switch для визначення відповідного коефіцієнта
    switch (unit) {
        case LengthUnit::Millimeter: return value / 1000;
        case LengthUnit::Centimeter: return value / 100;
        case LengthUnit::Decimeter: return value / 10;
        case LengthUnit::Meter: return value;
        case LengthUnit::Kilometer: return value * 1000;
        default: return -1; // Повернення помилки
    }
}

// Відмінювання слова залежно від граматичного відмінку
string declineWord(const string& word, Case grammaticalCase) {
    // Масив суфіксів для відмінків
    static const string cases[] = {"(Nominative)", "(Genitive)", "(Dative)", "(Accusative)", "(Instrumental)", "(Prepositional)"};
    return word + " " + cases[static_cast<int>(grammaticalCase)];
}

// Підрахунок складів у реченні
int countSyllables(const string& sentence) {
    int count = 0;
    // Перевірка кожної букви, чи є вона голосною
    for (char ch : sentence) {
        if (string("AEIOUYaeiouy").find(ch) != string::npos) {
            ++count;
        }
    }
    return count;
}

// Розрахунок фінального напрямку руху корабля
Course calculateFinalCourse(Course start, const vector<Order>& commands) {
    Course current = start;
    // Опрацювання кожної команди
    for (Order command : commands) {
        switch (command) {
            case Order::Forward: break;
            case Order::Backward: current = static_cast<Course>((static_cast<int>(current) + 2) % 4); break;
            case Order::Left: current = static_cast<Course>((static_cast<int>(current) + 3) % 4); break;
            case Order::Right: current = static_cast<Course>((static_cast<int>(current) + 1) % 4); break;
        }
    }
    return current;
}

// Обчислення загальної відстані, пройденої об'єктом
float calculateDistance(const vector<float>& speeds, const vector<float>& times) {
    float totalDistance = 0;
    // Помноження кожної швидкості на відповідний час
    for (size_t i = 0; i < speeds.size(); ++i) {
        totalDistance += speeds[i] * times[i];
    }
    return totalDistance;
}
