// Задача: 7. Перерахування
// Група: комп-мат2
// Прізвище: Дідик Олексій
// У цьому файлі реалізовані функції для роботи з перерахуваннями та іншими завданнями.

#include "Enumeration.h"
#include <stdio.h>
#include <string.h>

// Задача 1: Функції для виведення значень перерахувань
void printDay(DaysOfWeek day) {
    const char* days[] = {"Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота", "Неділя"};
    printf("%s\n", days[day]);
}

void printMonth(Months month) {
    const char* months[] = {"Січень", "Лютий", "Березень", "Квітень", "Травень", "Червень", "Липень", "Серпень", "Вересень", "Жовтень", "Листопад", "Грудень"};
    printf("%s\n", months[month]);
}

void printColor(SpectrumColor color) {
    const char* colors[] = {"Червоний", "Помаранчевий", "Жовтий", "Зелений", "Синій", "Індigo", "Фіолетовий"};
    printf("%s\n", colors[color]);
}

void printChessPiece(ChessPiece piece) {
    const char* pieces[] = {"Король", "Королева", "Ладья", "Слон", "Кінь", "Пішак"};
    printf("%s\n", pieces[piece]);
}

// Функція введення даних для карти
void inputCard(Card* card) {
    printf("Введіть масть (0 - Spades, 1 - Clubs, 2 - Diamonds, 3 - Hearts): ");
    scanf("%d", &card->suit);

    printf("Введіть старшинство карти (7 - CARD_Seven, 8 - CARD_Eight, 9 - CARD_Nine, 10 - CARD_Ten, ");
    printf("11 - CARD_Jack, 12 - CARD_Queen, 13 - CARD_King, 14 - CARD_Ace): ");
    scanf("%d", &card->rank);
}


// Функція виведення даних карти
void outputCard(const Card* card) {
    const char* suits[] = {"Spades", "Clubs", "Diamonds", "Hearts"};
    const char* ranks[] = {"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    printf("Масть: %s, Ранг: %s\n", suits[card->suit], ranks[card->rank - 7]);
}

// Функція запису карти у файл
void saveCardToFile(FILE* file, const Card* card) {
    fprintf(file, "%d %d\n", card->suit, card->rank);
}

// Функція читання карти з файлу
void loadCardFromFile(FILE* file, Card* card) {
    fscanf(file, "%d %d", &card->suit, &card->rank);
}

// Задача 2: Порівняння карт
int beat(Card x, Card y, Suit trump) {
    if (x.suit == y.suit) {
        return x.rank > y.rank;
    }
    return x.suit == trump;
}

// Задача 3: Переведення одиниць довжини
float convertToMeters(float value, LengthUnit unit) {
    switch (unit) {
        case Millimeter: return value / 1000;
        case Centimeter: return value / 100;
        case Decimeter: return value / 10;
        case Meter: return value;
        case Kilometer: return value * 1000;
        default: return -1; // Помилка
    }
}

// Задача 4: Відмінювання слів
const char* declineWord(const char* word, Case grammaticalCase) {
    static char result[256];
    switch (grammaticalCase) {
        case Nominative: snprintf(result, sizeof(result), "%s (Номінативний)", word); break;
        case Genitive: snprintf(result, sizeof(result), "%s (Родовий)", word); break;
        case Dative: snprintf(result, sizeof(result), "%s (Давальний)", word); break;
        case Accusative: snprintf(result, sizeof(result), "%s (Знахідний)", word); break;
        case Instrumental: snprintf(result, sizeof(result), "%s (Орудний)", word); break;
        case Prepositional: snprintf(result, sizeof(result), "%s (Місцевий)", word); break;
        default: snprintf(result, sizeof(result), "%s (Невідомий відмінок)", word); break;
    }
    return result;
}

// Задача 5: Підрахунок складів
int countSyllables(const char* sentence) {
    int count = 0;
    for (const char* p = sentence; *p; ++p) {
        switch (*p) {
            case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
                ++count;
                break;
            default:
                break;
        }
    }
    return count;
}

// Задача 6: Рух корабля
Course calculateFinalCourse(Course start, const Order* commands, int commandCount) {
    Course current = start;
    for (int i = 0; i < commandCount; ++i) {
        switch (commands[i]) {
            case Forward: break;
            case Backward: current = (current + 2) % 4; break;
            case Left: current = (current + 3) % 4; break;
            case Right: current = (current + 1) % 4; break;
        }
    }
    return current;
}

// Розрахунок загальної відстані
float calculateDistance(const float* speeds, const float* times, int count) {
    float totalDistance = 0;
    for (int i = 0; i < count; ++i) {
        totalDistance += speeds[i] * times[i];
    }
    return totalDistance;
}
