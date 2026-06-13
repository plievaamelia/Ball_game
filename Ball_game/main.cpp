#include <iostream>
#include <vector>
#include <fstream>
#include "BallsGame_Header.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    fstream file("Balls_colors.txt");
    int balls_amount; 
    DoubleLinkedList balls;
    int color;
    vector<int> colors;
    int choice;
    int example_choice;
    do {
        cout << "Компьюторная игра \"Шарики\"" << endl;
        cout << "1 - Ввести последовательность шаров вручную." << endl;
        cout << "2 - Прочитать последовательность шаров из файла Balls_colors.txt." << endl;
        cout << "3 - Готовые примеры последовательностей шаров на проверку работы программы." << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        while (!(cin >> choice) || choice > 3 || choice < 0) { 
            cout << "Неверный выбор! Введите число от 0 до 3: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n');
        switch (choice) {
        case 1:
            cout << "Введите количество шаров: ";
            while (!(cin >> balls_amount) || balls_amount > 100000 || balls_amount <= 0) { 
                cout << "Неверный выбор! Введите целое число от 1 до 100000: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin.ignore(1000, '\n');
            cout<<"Введите цвета (от 0 до 9): ";
            for (int i = 0; i < balls_amount; i++) {
                int color;
                while (!(cin >> color) || color > 9 || color < 0) { 
                    cout << "Неверный выбор! Введите цифру от 0 до 9: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                cin.ignore(1000, '\n');
                balls.push_back(color);
            }
            break;
        case 2:
            if (!file.is_open()) {
                cout << "Ошибка открытия файла Balls_colors.txt" << endl;
                return 1;
            }
            if (!(file >> balls_amount) || balls_amount > 100000 || balls_amount <= 0) { 
                cout << "Неверные входные данные! Количество шаров должно быть целым числом от 1 до 100000 ";
                return 1;
            }
            cout << "Количество шаров в последовательности: " << balls_amount << endl;
            for (int i = 0; i < balls_amount; i++) {
                if (!(file >> color) || color > 9 || color < 0) { 
                    cout << "Неверные входные данные! Цвет каждого шара должен быть цифрой от 0 до 9 ";
                    return 1;
                }
                balls.push_back(color);
            }
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Выберите один пример из предложенных" << endl;
            cout << "Пример 1 - Количество шаров: 100, последовательность: 1 2 3 4 5 ..." << endl;
            cout << "Пример 2 - Количество шаров: 10, последовательность: 3 3 2 1 1 1 2 2 3 3" << endl;
            cout << "Пример 3 - Количество шаров: 7, последовательность: 1 2 3 4 5 5 5" << endl;
            cout << "Пример 4 - Количество шаров: 12, последовательность: 1 1 2 2 2 1 1 3 3 2 2" << endl;
            cout << "Пример 5 - Количество шаров: 10, последовательность: 1 2 3 4 5 6 7 8 9 1" << endl;
            cout << "0 - Выход" << endl;
            cout << "Ваш выбор: ";
            while (!(cin >> example_choice) || example_choice > 5 || example_choice < 0) { 
                cout << "Неверный выбор! Введите число от 0 до 5: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin.ignore(1000, '\n');
            switch (example_choice) {
            case 1:
                cout << "Пример 1:" << endl;
                cout << "Количество шаров: 100, последовательность: 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 5 5 5 5 5 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5" << endl;
                colors = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,5,5,5,5,5,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5 };
                for (int i = 0; i < colors.size(); i++) {
                    balls.push_back(colors[i]);
                }
                break;
            case 2:
                cout << "Пример 2:" << endl;
                cout << "Количество шаров: 10, последовательность: 3 3 2 1 1 1 2 2 3 3" << endl;
                colors = { 3, 3, 2, 1, 1, 1, 2, 2, 3, 3 };
                for (int i = 0; i < colors.size(); i++) {
                    balls.push_back(colors[i]);
                }
                break;
            case 3:
                cout << "Пример 3:" << endl;
                cout << "Количество шаров: 7, последовательность: 1 2 3 4 5 5 5" << endl;
                colors = { 1, 2, 3, 4, 5, 5, 5 };
                for (int i = 0; i < colors.size(); i++) {
                    balls.push_back(colors[i]);
                }
                break;
            case 4:
                cout << "Пример 4:" << endl;
                cout << "Количество шаров: 12, последовательность: 1 1 2 2 2 1 1 3 3 2 2" << endl;
                colors = { 1, 1, 2, 2, 2, 1, 1, 3, 3, 2, 2 };
                for (int i = 0; i < colors.size(); i++) {
                    balls.push_back(colors[i]);
                }
                break;
            case 5:
                cout << "Пример 5:" << endl;
                cout << "Количество шаров: 10, последовательность: 1 2 3 4 5 6 7 8 9 1" << endl;
                colors = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1 };
                for (int i = 0; i < colors.size(); i++) {
                    balls.push_back(colors[i]);
                }
                break;
            case 0:
                cout << "Выход из подменю." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
                break;
            }
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
        int chains = balls.countChains();
        if (chains > 1) {
            cout << "Неверные входные данные! В начальной последовательности обнаружено больше одной цепочки." << endl;
            return 1;
        }
        int removed = balls.removeChains();
        cout << "Количество количество шариков, которое будет уничтожено " << removed << endl;
        cout << endl;
    } while (choice != 0);

    file.close();

    return 0;
}
