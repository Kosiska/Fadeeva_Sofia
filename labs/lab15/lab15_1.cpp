#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Класс Person
class Person {
private:
    string surname;
    string name;
    int birth_day;
    int birth_month;
    int birth_year;
    char gender;  // 'm', 'f', 'м', 'ж'

public:
    // Конструкторы
    Person() : surname(""), name(""), birth_day(0), birth_month(0), birth_year(0), gender('\0') {}

    Person(const string& s, const string& n, int d, int m, int y, char g) {
        setSurname(s);
        setName(n);
        setBirthDate(d, m, y);
        setGender(g);
    }

    // Деструктор
    ~Person() = default;

    // Геттеры
    string getSurname() const { return surname; }
    string getName() const { return name; }
    int getBirthDay() const { return birth_day; }
    int getBirthMonth() const { return birth_month; }
    int getBirthYear() const { return birth_year; }
    char getGender() const { return gender; }

    // Сеттеры с валидацией
    void setSurname(const string& s) { surname = s; }
    void setName(const string& n) { name = n; }

    void setBirthDate(int d, int m, int y) {
        if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y > 0) {
            birth_day = d;
            birth_month = m;
            birth_year = y;
        } else {
            throw invalid_argument("Некорректная дата рождения");
        }
    }

    void setGender(char g) {
        char lower_g = tolower(g);
        if (lower_g == 'm' || lower_g == 'f' || lower_g == 'м' || lower_g == 'ж') {
            gender = lower_g;
        } else {
            throw invalid_argument("Пол должен быть 'm', 'f', 'м' или 'ж'");
        }
    }

    // Функция-член: расчёт возраста (полных лет)
    int getAge(int current_year, int current_month, int current_day) const {
        int age = current_year - birth_year;
        if (current_month < birth_month || 
            (current_month == birth_month && current_day < birth_day)) {
            age--;
        }
        return age;
    }

    // Ввод данных в диалоге с пользователем
    void inputFromConsole() {
        cout << "Фамилия: ";
        getline(cin, surname);

        cout << "Имя: ";
        getline(cin, name);

        int d, m, y;
        cout << "Дата рождения (день месяц год): ";
        cin >> d >> m >> y;
        cin.ignore();
        setBirthDate(d, m, y);

        char g;
        cout << "Пол (m/f/м/ж): ";
        cin >> g;
        cin.ignore();
        setGender(g);
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.surname << " " << p.name.substr(0, 1) << ". "
           << "(" << p.getAge(2025, 12, 11) << " лет, " << p.gender << ")";
        return os;
    }

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Person& p) {
        p.inputFromConsole();
        return is;
    }

    // Операторы сравнения (по возрасту)
    bool operator<(const Person& other) const {
        return getAge(2025, 12, 11) < other.getAge(2025, 12, 11);
    }

    bool operator>(const Person& other) const {
        return getAge(2025, 12, 11) > other.getAge(2025, 12, 11);
    }
};

// Простая сортировка выбором (по возрастанию возраста)
void sortPersonsByAge(vector<Person>& persons) {
    for (size_t i = 0; i < persons.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < persons.size(); ++j) {
            if (persons[j] < persons[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(persons[i], persons[min_idx]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n;
    cout << "Сколько человек ввести? ";
    cin >> n;
    cin.ignore();  // очищаем буфер

    vector<Person> people(n);

    // Ввод данных
    for (int i = 0; i < n; ++i) {
        cout << "\nЧеловек " << (i + 1) << ":\n";
        cin >> people[i];
    }

    // Сортировка по возрасту
    sortPersonsByAge(people);

    // Вывод результатов
    cout << "\nОтсортированный список (по возрасту):\n";
    for (const auto& person : people) {
        cout << person << endl;
    }

    return 0;
}
