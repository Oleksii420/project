// 7. Перерахування
// Група: Комп-мат2
// Прізвище: Дідик Олексій
// Цей файл реалізує програму для демонстрації використання перерахувань, структур і обчислювальних функцій у задачах
// друку значень, порівняння карт, конвертації одиниць довжини, відмінювання слів, підрахунку складів і розрахунку руху
// корабля.


#include "Enumeration.h"
#include <iostream>

using namespace std;

int main() {
    // Завдання 1: Друк значень перерахувань
    cout << "Завдання 1: Друк значень перерахувань\n";
    int dayInput, monthInput, colorInput, pieceInput;
    cout << "Введіть день тижня (0 - Понеділок, 1 - Вівторок, 2 - Середа, 3 - Четвер, 4 - П'ятниця, 5 - Субота, 6 - Неділя) ";
    cin >> dayInput;
    printDay(static_cast<DaysOfWeek>(dayInput));

    cout << "Введіть місяць (0 - Січень, 1 - Лютий, 2 - Березень, 3 - Квітень, 4 - Травень, 5 - Червень, 6 - Липень, 7 - Серпень, 8 - Вересень, 9 - Жовтень, 10 - Листопад, 11 - Грудень):";
    cin >> monthInput;
    printMonth(static_cast<Months>(monthInput));

    cout << "Введіть колір спектру (0 - Червоний, 1 - Помаранчевий, 2 - Жовтий, 3 - Зелений, 4 - Синій, 5 - Індigo, 6 - Фіолетовий): ";
    cin >> colorInput;
    printColor(static_cast<SpectrumColor>(colorInput));

    cout << "Введіть шахову фігуру (0 - Король, 1 - Королева, 2 - Ладья, 3 - Слон, 4 - Кінь, 5 - Пішак): ";
    cin >> pieceInput;
    printChessPiece(static_cast<ChessPiece>(pieceInput));

    // Завдання 2: Порівняння карт
    cout << "\nЗавдання 2: Порівняння карт\n";
    int rank1, suit1, rank2, suit2, trump;
    cout << "Введіть масть та ранг першої карти (0-3, 7-14): ";
    cin >> suit1 >> rank1;
    cout << "Введіть масть та ранг другої карти (0-3, 7-14): ";
    cin >> suit2 >> rank2;
    cout << "Введіть козирну масть (0-3): ";
    cin >> trump;

    Card card1 = {static_cast<Suit>(suit1), static_cast<Rank>(rank1)};
    Card card2 = {static_cast<Suit>(suit2), static_cast<Rank>(rank2)};
    cout << "Карта 1 перемагає карту 2: " << beat(card1, card2, static_cast<Suit>(trump)) << "\n";

    // Завдання 3: Конвертація довжин
    cout << "\nЗавдання 3: Конвертація довжин\n";
    float value;
    int unitInput;
    cout << "Введіть значення довжини: ";
    cin >> value;
    cout << "Введіть одиницю вимірювання (0 - міліметри, 1 - сантиметри, 2 - дециметри, 3 - метри, 4 - кілометри): ";
    cin >> unitInput;
    cout << "Довжина в метрах: " << convertToMeters(value, static_cast<LengthUnit>(unitInput)) << "\n";

    // Завдання 4: Відмінювання слів
    cout << "\nЗавдання 4: Відмінювання слів\n";
    string word;
    int caseInput;
    cout << "Введіть слово: ";
    cin >> word;
    cout << "Введіть відмінок (0 - Називний, 1 - Родовий, 2 - Давальний, 3 - Знахідний, 4 - Орудний, 5 - Місцевий): ";
    cin >> caseInput;
    cout << "Відмінене слово: " << declineWord(word, static_cast<Case>(caseInput)) << "\n";

    // Завдання 5: Підрахунок складів
    cout << "\nЗавдання 5: Підрахунок складів\n";
    cin.ignore(); // Очистити вхідний потік
    string sentence;
    cout << "Введіть речення(на англіській): ";
    getline(cin, sentence);
    cout << "Кількість складів: " << countSyllables(sentence) << "\n";

    // Завдання 6: Рух корабля
    cout << "\nЗавдання 6: Рух корабля\n";
    int startCourse;
    int commandCount;
    cout << "Введіть початковий курс корабля (0 - North, 1 - South, 2 - West, 3 - East): ";
    cin >> startCourse;
    cout << "Введіть кількість команд: ";
    cin >> commandCount;

    vector<Order> commands;
    vector<float> speeds, times;

    for (int i = 0; i < commandCount; ++i) {
        int command;
        float speed, time;
        cout << "Введіть команду (0-3), швидкість, час для команди " << i + 1 << ": ";
        cin >> command >> speed >> time;
        commands.push_back(static_cast<Order>(command));
        speeds.push_back(speed);
        times.push_back(time);
    }

    Course finalCourse = calculateFinalCourse(static_cast<Course>(startCourse), commands);
    cout << "Фінальний напрямок: " << static_cast<int>(finalCourse) << "\n";

    float distance = calculateDistance(speeds, times);
    cout << "Загальна пройдена відстань: " << distance << "\n";

    return 0;
}
