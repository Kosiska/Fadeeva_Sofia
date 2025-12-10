#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct address {
    string street;
    string house;
    int apartment;
};


struct date {
    int day;
    int month;
    int year;
};


struct character {
    string surname;
    string name;
    address addr;
    date birth_date;
};

// Функция расчёта возраста (полных лет)
int calculate_age(const date& birth, const date& current) {
    int age = current.year - birth.year;
  
    if (current.month < birth.month || 
        (current.month == birth.month && current.day < birth.day)) {
        age--;
    }
    return age;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int num_characters = 5;
    vector<character> characters(num_characters);

    // Ввод данных для 5 персонажей
    for (int i = 0; i < num_characters; ++i) {
        cout << "Персонаж " << (i + 1) << ":\n";

        cout << "Фамилия: ";
        getline(cin, characters[i].surname);

        cout << "Имя: ";
        getline(cin, characters[i].name);

        cout << "Улица: ";
        getline(cin, characters[i].addr.street);

        cout << "Дом: ";
        getline(cin, characters[i].addr.house);

        cout << "Квартира: ";
        cin >> characters[i].addr.apartment;
        cin.ignore();


        cout << "День рождения (день месяц год): ";
        cin >> characters[i].birth_date.day
             >> characters[i].birth_date.month
             >> characters[i].birth_date.year;
        cin.ignore();
    }

    // Ввод текущей даты
    date current_date;
    cout << "\nВведите текущую дату (день месяц год): ";
    cin >> current_date.day >> current_date.month >> current_date.year;
    cin.ignore();

    // а) Выводим персонажей, у которых день рождения совпадает с текущей датой
    cout << "\nЛюди, у которых сегодня день рождения:\n";
    bool found_birthday = false;
    for (const auto& ch : characters) {
        if (ch.birth_date.day == current_date.day &&
            ch.birth_date.month == current_date.month) {
            cout << ch.surname << " " << ch.name << " ("
                 << ch.addr.street << ", д. " << ch.addr.house
                 << ", кв. " << ch.addr.apartment << ")\n";
            found_birthday = true;
        }
    }
    if (!found_birthday) {
        cout << "Нет людей с днём рождения сегодня.\n";
    }

    // б) Выводим возраст каждого человека
    cout << "\nВозраст каждого человека:\n";
    for (const auto& ch : characters) {
        int age = calculate_age(ch.birth_date, current_date);
        cout << ch.surname << " " << ch.name << " — " << age << " лет\n";
    }

    return 0;
}