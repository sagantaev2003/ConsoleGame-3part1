#include <iostream>
#include <random>

void playGame() { //Функция для одной игры
    setlocale(LC_ALL, "RU"); //Установка кодировку на RU
    //Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);
    int secretNumber = distrib(gen);
    int guess;
    int attempts = 0;

    std::cout << "Я загадал число от 1 до 100. Попробуйте угадать!  " << "Подсказка: " << secretNumber << std::endl;

    while (true) { //Проверка на некорректность ввода числа
        std::cout << "Введите число: ";
        if (!(std::cin >> guess)) {
            std::cin.clear(); //Сброс флага ошибки
            std::cin.ignore(10000, '\n'); //Очистить буфер ввода
            std::cout << "Некорректный ввод. Введите число!" << std::endl;
            continue;
        }

        attempts++; //Увеличение счетчика попыток

        //Проверка введеннего числа
        if (guess < secretNumber) {
            std::cout << "Загаданное число больше." << std::endl;
        }
        else if (guess > secretNumber) {
            std::cout << "Загаданное число меньше." << std::endl;
        }
        else {
            std::cout << "Поздравляю! Вы угадали число за " << attempts << " попыток." << std::endl;
            break;
        }
    }
}

int main() { // Проверяет хочет ли пользователь сыграть еще раз
    char playAgain;
    do {
        playGame();
        std::cout << "Хотите сыграть ещё раз? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Спасибо за игру!" << std::endl; //Если не хочет, то игра заканчивается и выводит 
    return 0;
}