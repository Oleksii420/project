// 7. Перерахування
// Група: Комп-мат2
// Прізвище: Дідик Олексій
// У цьому файлі міститься оголошення перерахувань (enum) та пов'язаних із ними функцій.

#ifndef ENUMERATION_H
#define ENUMERATION_H

#include <string>
#include <vector>

using namespace std;

// 1. Перерахування для задач
enum class ChessPiece {
    King, Queen, Rook, Bishop, Knight, Pawn
};

enum class Rank {
    Seven = 7, Eight, Nine, Ten, Jack, Queen, King, Ace
};

enum class Suit {
    Spades, Clubs, Diamonds, Hearts
};

struct Card {
    Suit suit; // Масть карти
    Rank rank; // Ранг карти
};

enum class DaysOfWeek {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

enum class Months {
    January, February, March, April, May, June, July, August, September, October, November, December
};

enum class SpectrumColor {
    Red, Orange, Yellow, Green, Blue, Indigo, Violet
};

enum class LengthUnit {
    Millimeter, Centimeter, Decimeter, Meter, Kilometer
};

enum class Case {
    Nominative, Genitive, Dative, Accusative, Instrumental, Prepositional
};

enum class Vowel : char {
    A = 'A', E = 'E', I = 'I', O = 'O', U = 'U', Y = 'Y',
    a = 'a', e = 'e', i = 'i', o = 'o', u = 'u', y = 'y'
};

enum class Course {
    North, South, West, East
};

enum class Order {
    Forward, Backward, Left, Right
};

// Оголошення функцій
void printDay(DaysOfWeek day);            // Друк назви дня тижня
void printMonth(Months month);            // Друк назви місяця
void printColor(SpectrumColor color);     // Друк назви кольору спектру
void printChessPiece(ChessPiece piece);   // Друк назви шахової фігури

bool beat(const Card& x, const Card& y, Suit trump); // Порівняння карт

float convertToMeters(float value, LengthUnit unit); // Конвертація довжин у метри

string declineWord(const string& word, Case grammaticalCase); // Відмінювання слів

int countSyllables(const string& sentence); // Підрахунок складів у реченні

Course calculateFinalCourse(Course start, const vector<Order>& commands); // Обчислення фінального напряму руху корабля
float calculateDistance(const vector<float>& speeds, const vector<float>& times); // Обчислення загальної відстані

#endif // ENUMERATION_H
