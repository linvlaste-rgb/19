#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double base, difficulty, danger, taxPercent;

    std::cout << "--- Охотник за головами ---\n";
    std::cout << "Введите базовую награду, коэффициенты сложности и опасности, налог (%).\n";
    std::cout << "Пример: 1000 1.5 2 10\n";

    // Проверяем, что введены четыре числа.
    if (!(std::cin >> base >> difficulty >> danger >> taxPercent)) {
        std::cout << "Ошибка: нужно ввести четыре числа.\n";
        return 1;
    }
    if (!std::isfinite(base) || !std::isfinite(difficulty) ||
        !std::isfinite(danger) || !std::isfinite(taxPercent)) {
        std::cout << "Ошибка: числа должны быть конечными.\n";
        return 1;
    }

    // Повышающие коэффициенты не могут быть меньше единицы.
    if (base <= 0 || difficulty < 1 || danger < 1 ||
        taxPercent < 0 || taxPercent > 100) {
        std::cout << "Ошибка: награда должна быть больше 0, коэффициенты не меньше 1, налог от 0 до 100.\n";
        return 1;
    }

    // Сначала рассчитываем полную награду, затем вычитаем налог.
    double reward = base * difficulty * danger;
    if (!std::isfinite(reward)) {
        std::cout << "Ошибка: слишком большие значения для расчета.\n";
        return 1;
    }
    double tax = reward * (taxPercent / 100);
    double total = reward - tax;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nНаграда за контракт: " << reward << " золотых монет\n";
    std::cout << "Налог гильдии: " << tax << " золотых монет\n";
    std::cout << "Охотник получает: " << total << " золотых монет\n";
    return 0;
}
