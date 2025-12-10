#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

// Структура с полями
struct property {
    string street_name;      // Улица
    string house_number;       // Дом
    double area_sqm;          // Площадь помещения
    double price_per_sqm;     // Стоимость аренды
};

// Функция расчёта общей стоимости аренды
double calculate_total_rent(const property& prop) {
    return prop.area_sqm * prop.price_per_sqm;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Создаём две переменные типа property
    property first_property;
    property second_property;

    // Вводим данные для первого помещения
    cout << "Введите данные для первого помещения:\n";
    
    cout << "Улица: ";
    getline(cin, first_property.street_name);
    
    cout << "Дом: ";
    getline(cin, first_property.house_number);
    
    cout << "Площадь (м?): ";
    cin >> first_property.area_sqm;
    
    cout << "Стоимость аренды за 1 м? (руб.): ";
    cin >> first_property.price_per_sqm;

    cin.ignore();

    // Задаём значения для второго помещения
    second_property.street_name = "Кремлевская";
    second_property.house_number = "18";
    second_property.area_sqm = 200.0;
    second_property.price_per_sqm = 10000.0;

    // Рассчитываем стоимость аренды для обоих помещений
    double first_rent = calculate_total_rent(first_property);
    double second_rent = calculate_total_rent(second_property);

    // Выводим адрес помещения с меньшей стоимостью аренды
    cout << "\nПомещение с меньшей стоимостью аренды:\n";
    
    if (first_rent < second_rent) {
        cout << first_property.street_name << ", " << first_property.house_number << endl;
    }
    else 
        cout << second_property.street_name << ", " << second_property.house_number << endl;
    return 0;
}