// Задача: 7. Перерахування
// Група: комп-мат2
// Прізвище: Дідик Олексій
// У цьому файлі знаходяться визначення перерахувань, структур та прототипи функцій для різних завдань.

#ifndef ENUMERATION_H
#define ENUMERATION_H

#include <stdio.h>

// 1. Визначення перерахувань
typedef enum {
    CHESS_King, CHESS_Queen, CHESS_Rook, CHESS_Bishop, CHESS_Knight, CHESS_Pawn
} ChessPiece;

typedef enum {
    CARD_Seven = 7, CARD_Eight, CARD_Nine, CARD_Ten, CARD_Jack, CARD_Queen, CARD_King, CARD_Ace
} Rank;

typedef enum {
    Spades, Clubs, Diamonds, Hearts
} Suit;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef enum {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
} DaysOfWeek;

typedef enum {
    January, February, March, April, May, June, July, August, September, October, November, December
} Months;

typedef enum {
    Red, Orange, Yellow, Green, Blue, Indigo, Violet
} SpectrumColor;

typedef enum {
    Millimeter, Centimeter, Decimeter, Meter, Kilometer
} LengthUnit;

typedef enum {
    Nominative, Genitive, Dative, Accusative, Instrumental, Prepositional
} Case;

typedef enum {
    A = 'A', E = 'E', I = 'I', O = 'O', U = 'U', Y = 'Y', a = 'a', e = 'e', i = 'i', o = 'o', u = 'u', y = 'y'
} Vowel;

typedef enum {
    North, South, West, East
} Course;

typedef enum {
    Forward, Backward, Left, Right
} Order;

// Прототипи функцій
// Задача 1
void printDay(DaysOfWeek day);
void printMonth(Months month);
void printColor(SpectrumColor color);
void printChessPiece(ChessPiece piece);

// Функції введення/виведення для структури Card
void inputCard(Card* card);
void outputCard(const Card* card);
void saveCardToFile(FILE* file, const Card* card);
void loadCardFromFile(FILE* file, Card* card);

// Задача 2
int beat(Card x, Card y, Suit trump);

// Задача 3
float convertToMeters(float value, LengthUnit unit);

// Задача 4
const char* declineWord(const char* word, Case grammaticalCase);

// Задача 5
int countSyllables(const char* sentence);

// Задача 6
Course calculateFinalCourse(Course start, const Order* commands, int commandCount);
float calculateDistance(const float* speeds, const float* times, int count);

#endif // ENUMERATION_H
