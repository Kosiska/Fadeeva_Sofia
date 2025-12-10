#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;


struct student {
    string full_name;    
    string group_number;     
    int grades[4];        
};

// Функция для нахождения наилучшей оценки студента
int get_best_grade(const student& stu) {
    int best = stu.grades[0];
    for (int i = 1; i < 4; ++i) {
        if (stu.grades[i] > best) {
            best = stu.grades[i];
        }
    }
    return best;
}

// Функция для расчёта среднего балла студента
double calculate_average(const student& stu) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += stu.grades[i];
    }
    return static_cast<double>(sum) / 4.0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // а) Массив из 3 студентов
    const int num_students_part_a = 3;
    student students_part_a[num_students_part_a];

    cout << "а): ввод данных для 3 студентов\n";
    for (int i = 0; i < num_students_part_a; ++i) {
        cout << "Студент " << (i + 1) << ":\n";
        
        cout << "Фамилия И.О.: ";
        getline(cin, students_part_a[i].full_name);
        
        cout << "Номер группы: ";
        getline(cin, students_part_a[i].group_number);
        
        cout << "Оценки по 4 предметам (через пробел): ";
        for (int j = 0; j < 4; ++j) {
            cin >> students_part_a[i].grades[j];
        }
        cin.ignore(); // очищаем буфер после числового ввода
    }

    // Выводим наилучшую оценку для каждого студента
    cout << "\nНаилучшие оценки студентов:\n";
    for (int i = 0; i < num_students_part_a; ++i) {
        int best_grade = get_best_grade(students_part_a[i]);
        cout << students_part_a[i].full_name << " — " << best_grade << endl;
    }

    // б) Массив с произвольным количеством студентов
    int num_students_part_b;
    cout << "\nб): введите количество студентов: ";
    cin >> num_students_part_b;
    cin.ignore();

    vector<student> students_part_b(num_students_part_b);

    cout << "Введите данные для " << num_students_part_b << " студентов:\n";
    for (int i = 0; i < num_students_part_b; ++i) {
        cout << "Студент " << (i + 1) << ":\n";
        
        cout << "Фамилия И.О.: ";
        getline(cin, students_part_b[i].full_name);
        
        cout << "Номер группы: ";
        getline(cin, students_part_b[i].group_number);
        
        cout << "Оценки по 4 предметам (через пробел): ";
        for (int j = 0; j < 4; ++j) {
            cin >> students_part_b[i].grades[j];
        }
        cin.ignore();
    }

    // Выводим средний балл каждого студента и собираем фамилии отличников
    cout << "\nСредние баллы студентов:\n";
    vector<string> otlichniki; // будем хранить фамилии круглых отличников 

    for (const auto& stu : students_part_b) {
        double avg = calculate_average(stu);
        cout << stu.full_name << " — " << avg << endl;

        // Проверяем, является ли студент круглым отличником (все оценки = 5)
        bool is_excellent = true;
        for (int grade : stu.grades) {
            if (grade != 5) {
                is_excellent = false;
                break;
            }
        }
        if (is_excellent) {
            otlichniki.push_back(stu.full_name);
        }
    }

    // Выводим фамилии круглых отличников
    if (!otlichniki.empty()) {
        cout << "\nКруглые отличники:\n";
        for (const string& name : otlichniki) {
            cout << name << endl;
        }
    } else {
        cout << "\nКруглых отличников нет.\n";
    }

    return 0;
}