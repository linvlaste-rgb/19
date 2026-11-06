#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double cost = 0;
    double difficulty = 0;
    double danger = 0;
    double taxPercent = 0;

    std::cout << "--- Охотник за головами ---\n";

    // Вводим цену контракта, сложность, опасность и налог
    std::cout << "Базовая награда: ";
    std::cin >> cost;

    std::cout << "Коэффициент сложности: ";
    std::cin >> difficulty;

    std::cout << "Коэффициент опасности: ";
    std::cin >> danger;

    std::cout << "Налог гильдии в процентах: ";
    std::cin >> taxPercent;

    // Если вместо числа ввели текст, дальше не считаем
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно вводить числа.\n";
        return 1;
    }

    // За контракт должны платить больше нуля
    if (cost <= 0) {
        std::cout << "Ошибка: награда должна быть больше 0.\n";
        return 1;
    }

    // Коэффициент 1 ничего не добавляет, больше 1 увеличивает награду
    if (difficulty < 1 || danger < 1) {
        std::cout << "Ошибка: коэффициенты должны быть не меньше 1.\n";
        return 1;
    }

    // Налог не может быть меньше 0 или больше 100 процентов
    if (taxPercent < 0 || taxPercent > 100) {
        std::cout << "Ошибка: налог должен быть от 0 до 100.\n";
        return 1;
    }

    // Умножаем цену на оба коэффициента
    double reward = cost * difficulty * danger;

    // Если получилась бесконечность или не число, выводим ошибку
    if (!std::isfinite(reward) || !std::isfinite(taxPercent)) {
        std::cout << "Ошибка: слишком большие или неверные числа.\n";
        return 1;
    }

    // Считаем сколько заберет гильдия и сколько останется нам
    double tax = reward * (taxPercent / 100);
    double total = reward - tax;

    // Показываем суммы с двумя цифрами после точки
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nНаграда за контракт: " << reward << " золотых монет\n";
    std::cout << "Налог гильдии: " << tax << " золотых монет\n";
    std::cout << "Охотник получает: " << total << " золотых монет\n";

    return 0;
}
