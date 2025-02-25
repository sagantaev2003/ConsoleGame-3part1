#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// Функция для инициализации генератора случайных чисел
void initRandom() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Функция для генерации случайного элемента из вектора
std::string getRandomElement(const std::vector<std::string>& vec) {
    int index = std::rand() % vec.size();
    return vec[index];
}

// Функция для генерации истории
std::string generateStory(const std::vector<std::string>& heroes,
    const std::vector<std::string>& places,
    const std::vector<std::string>& actions,
    const std::vector<std::string>& details) {
    return getRandomElement(heroes) + " " + getRandomElement(places) + ", " +
        getRandomElement(actions) + " " + getRandomElement(details) + ".";
}

// Функция для сохранения истории в файл
void saveStory(const std::string& story) {
    setlocale(LC_ALL, "RU");
    std::ofstream outFile("stories.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << story << "\n";
        outFile.close();
        std::cout << "История сохранена в файл stories.txt\n";
    }
    else {
        std::cout << "Ошибка открытия файла!\n";
    }
}

// Основная функция
int main() {
    setlocale(LC_ALL, "RU"); //Установка кодировку на RU
    initRandom();
    //перечень слов
    std::vector<std::string> heroes = { "Смелый рыцарь", "Хитрый вор", "Волшебник", "Отважный пират", "Дерзкий исследователь" };
    std::vector<std::string> places = { "в далёком королевстве", "на заброшенной фабрике", "в густом лесу", "на просторах космоса", "у подножия гор" };
    std::vector<std::string> actions = { "победил дракона", "обнаружил сокровища", "выиграл битву", "устроил бал", "раскрыл древнюю тайну" };
    std::vector<std::string> details = { "с волшебным мечом", "на летающем ковре", "под звуки волшебной музыки", "с удивительной силой", "в сопровождении магического существа" };

    char playAgain;
    do {
        std::string story = generateStory(heroes, places, actions, details);
        std::cout << "\nСгенерированная история:\n" << story << "\n";

        std::cout << "\nСохранить историю в файл (Y/N)? ";
        char saveChoice;
        std::cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y') {
            saveStory(story);
        }

        std::cout << "\nХотите создать ещё одну историю? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    std::cout << "Спасибо за игру!" << std::endl;
    return 0;
}