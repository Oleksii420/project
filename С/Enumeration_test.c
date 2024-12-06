// Задача: 7. Перерахування
// Група: комп-мат2
// Прізвище: Дідик Олексій
// Цей файл реалізує тестову програму для роботи з перерахуваннями та функціями, що включають введення й виведення
// значень, порівняння карт, конвертацію одиниць довжини, відмінювання слів, підрахунок складів і обчислення траєкторії
// руху корабля

#include "Enumeration.h"
#include <stdio.h>

int main() {
    // Задача 1: Введення та виведення перерахувань
    printf("Задача 1: Введення та виведення перерахувань\n");
    int dayInput, monthInput, colorInput, pieceInput;

    printf("Введіть день тижня (0 - Понеділок, 1 - Вівторок, 2 - Середа, 3 - Четвер, 4 - П'ятниця, 5 - Субота, 6 - Неділя): ");
    scanf("%d", &dayInput);
    printDay((DaysOfWeek)dayInput);

    printf("Введіть місяць (0 - Січень, 1 - Лютий, 2 - Березень, 3 - Квітень, 4 - Травень, 5 - Червень, 6 - Липень, 7 - Серпень, 8 - Вересень, 9 - Жовтень, 10 - Листопад, 11 - Грудень): ");
    scanf("%d", &monthInput);
    printMonth((Months)monthInput);

    printf("Введіть колір спектру (0 - Червоний, 1 - Помаранчевий, 2 - Жовтий, 3 - Зелений, 4 - Синій, 5 - Індigo, 6 - Фіолетовий): ");
    scanf("%d", &colorInput);
    printColor((SpectrumColor)colorInput);

    printf("Введіть шахову фігуру (0 - Король, 1 - Королева, 2 - Ладья, 3 - Слон, 4 - Кінь, 5 - Пішак): ");
    scanf("%d", &pieceInput);
    printChessPiece((ChessPiece)pieceInput);

    // Задача 2: Введення карт і порівняння
    printf("\nЗадача 2: Введення карт і порівняння\n");
    Card card1, card2;
    Suit trump;

    printf("Введіть першу карту:\n");
    inputCard(&card1);
    printf("Введіть другу карту:\n");
    inputCard(&card2);
    printf("Введіть козирну масть (0 - Spades, 1 - Clubs, 2 - Diamonds, 3 - Hearts): ");
    scanf("%d", &trump);

    printf("Перша карта перевершує другу: %d\n", beat(card1, card2, trump));

    // Задача 3: Введення довжини
    printf("\nЗадача 3: Введення довжини\n");
    float lengthValue;
    int unitInput;
    printf("Введіть значення довжини: ");
    scanf("%f", &lengthValue);
    printf("Введіть одиницю вимірювання (0 - міліметри, 1 - сантиметри, 2 - дециметри, 3 - метри, 4 - кілометри): ");
    scanf("%d", &unitInput);
    printf("Довжина в метрах: %.3f\n", convertToMeters(lengthValue, (LengthUnit)unitInput));

    // Задача 4: Відмінювання слів
    printf("\nЗадача 4: Відмінювання слів\n");
    char word[256];
    int caseInput;
    printf("Введіть слово: ");
    scanf("%s", word);
    printf("Введіть відмінок (0 - Називний, 1 - Родовий, 2 - Давальний, 3 - Знахідний, 4 - Орудний, 5 - Місцевий): ");
    scanf("%d", &caseInput);
    printf("Результат: %s\n", declineWord(word, (Case)caseInput));

    // Задача 5: Підрахунок складів
    printf("\nЗадача 5: Підрахунок складів\n");
    char sentence[256];
    printf("Введіть речення(на англіській): ");
    getchar(); // Очищення буфера
    fgets(sentence, sizeof(sentence), stdin);
    printf("Кількість складів: %d\n", countSyllables(sentence));

    // Задача 6: Введення даних для руху корабля
    printf("\nЗадача 6: Рух корабля\n");
    int startCourse;
    int commandCount;
    printf("Введіть початковий курс корабля (0 - North, 1 - South, 2 - West, 3 - East): ");
    scanf("%d", &startCourse);

    printf("Введіть кількість команд: ");
    scanf("%d", &commandCount);

    Order commands[commandCount];
    float speeds[commandCount];
    float times[commandCount];

    for (int i = 0; i < commandCount; ++i) {
        printf("Введіть команду (0 - Forward, 1 - Backward, 2 - Left, 3 - Right): ");
        scanf("%d", &commands[i]);

        printf("Введіть швидкість (м/с) для команди %d: ", i + 1);
        scanf("%f", &speeds[i]);

        printf("Введіть час руху (с) для команди %d: ", i + 1);
        scanf("%f", &times[i]);
    }

    Course finalCourse = calculateFinalCourse((Course)startCourse, commands, commandCount);
    printf("Фінальний курс корабля: %d\n", finalCourse);

    float distance = calculateDistance(speeds, times, commandCount);
    printf("Загальна пройдена відстань: %.2f м\n", distance);

    return 0;
}

