#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс Person (из предыдущего примера, сокращённо)
class Person {
private:
    string surname;
    string name;
    int birth_day, birth_month, birth_year;
    char gender;

public:
    Person() : surname(""), name(""), birth_day(0), birth_month(0), birth_year(0), gender('\0') {}
    Person(const string& s, const string& n, int d, int m, int y, char g)
        : surname(s), name(n), birth_day(d), birth_month(m), birth_year(y), gender(g) {}

    string getSurname() const { return surname; }
    string getName() const { return name; }
    int getBirthYear() const { return birth_year; }
    char getGender() const { return gender; }

    void setSurname(const string& s) { surname = s; }
    void setName(const string& n) { name = n; }
    
    void setBirthDate(int d, int m, int y) {
        if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y > 0) {
            birth_day = d; birth_month = m; birth_year = y;
        }
    }

    void setGender(char g) {
        char lower_g = tolower(g);
        if (lower_g == 'm' || lower_g == 'f' || lower_g == 'м' || lower_g == 'ж')
            gender = lower_g;
    }

    int getAge(int current_year, int current_month, int current_day) const {
        int age = current_year - birth_year;
        if (current_month < birth_month ||
            (current_month == birth_month && current_day < birth_day))
            age--;
        return age;
    }

    friend istream& operator>>(istream& is, Person& p);
    friend ostream& operator<<(ostream& os, const Person& p);
};

istream& operator>>(istream& is, Person& p) {
    cout << "Фамилия: "; getline(is, p.surname);
    cout << "Имя: "; getline(is, p.name);
    int d, m, y; cout << "Дата рождения (д м г): "; is >> d >> m >> y; p.setBirthDate(d, m, y);
    char g; cout << "Пол (m/f/м/ж): "; is >> g; p.setGender(g); is.ignore();
    return is;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.surname << " " << p.name.substr(0, 1) << ". ("
       << p.getAge(2025, 12, 11) << " лет, " << p.gender << ")";
    return os;
}

// Производный класс: Рабочий с фиксированным окладом
class SalaryWorker : public Person {
private:
    double salary;     // оклад
    double bonus_pct;  // % премии

public:
    // Конструкторы
    SalaryWorker() : Person(), salary(0.0), bonus_pct(0.0) {}
    
    SalaryWorker(const string& s, const string& n, int d, int m, int y, char g,
                double sal, double bpc)
        : Person(s, n, d, m, y, g), salary(sal), bonus_pct(bpc) {}

    // Сеттеры с валидацией
    void setSalary(double sal) {
        if (sal >= 0) salary = sal;
    }
    
    void setBonusPercent(double bpc) {
        if (bpc >= 0) bonus_pct = bpc;
    }

    // Геттеры
    double getSalary() const { return salary; }
    double getBonusPercent() const { return bonus_pct; }

    // 1. Расчёт общей суммы зарплаты с премией
    double calculateTotalSalary() const {
        return salary + (salary * bonus_pct / 100.0);
    }

    // 2. Расчёт подоходного налога (13%)
    double calculateIncomeTax() const {
        return calculateTotalSalary() * 0.13;
    }

    // 3. Расчёт суммы «на руки» (после налога)
    double calculateNetSalary() const {
        return calculateTotalSalary() - calculateIncomeTax();
    }

    // Переопределяем ввод/вывод
    friend istream& operator>>(istream& is, SalaryWorker& sw);
    friend ostream& operator<<(ostream& os, const SalaryWorker& sw);
};

// Ввод для SalaryWorker (наследует Person + добавляет оклад и премию)
istream& operator>>(istream& is, SalaryWorker& sw) {
    is >> static_cast<Person&>(sw);  // вводим базовые поля Person
    cout << "Оклад: "; is >> sw.salary;
    cout << "% премии: "; is >> sw.bonus_pct;
    is.ignore();
    return is;
}

// Вывод для SalaryWorker
ostream& operator<<(ostream& os, const SalaryWorker& sw) {
    os << static_cast<const Person&>(sw)  // выводим базовые данные Person
       << " | Оклад: " << sw.salary
       << " | Премия: " << sw.bonus_pct << "%"
       << " | Итого: " << sw.calculateTotalSalary()
       << " | Налог (13%): " << sw.calculateIncomeTax()
       << " | На руки: " << sw.calculateNetSalary();
    return os;
}

// Программа тестирования
int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Сколько работников ввести? ";
    cin >> n;
    cin.ignore();

    vector<SalaryWorker> workers(n);

    // Ввод данных
    for (int i = 0; i < n; ++i) {
        cout << "\nРаботник " << (i + 1) << ":\n";
        cin >> workers[i];
    }

    // Вывод результатов
    cout << "\nДанные по работникам:\n";
    for (const auto& worker : workers) {
        cout << worker << endl;
    }

    return 0;
}
