#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
template <typename T>
void f(T h1,  T s1, T h2,  T s2, string fam1, string fam2){
    double salary1, salary2, nalog1, nalog2, total1, total2;
    
    salary1 = h1 * s1;
    salary2 = h2 * s2;

    nalog1 = salary1 * 0.13;
    total1 = salary1 - nalog1;

    nalog2 = salary2 * 0.13;
    total2 = salary2 - nalog1;

    cout << "‘амилии тех, кто получил на руки меньше 1000 руб - ";
    if (total1 < 1000) {
        cout << fam1 << endl;
    }
    if (total2 < 1000) {
        cout << fam2 << endl;
    }
    cout << "–аботники с налогом более 50 рублей (перва€ и последн€€ буква фамилии):" << endl;
    if (nalog1 > 50) {
        cout << fam1[0] << "-" << fam1[fam1.length() - 1] << endl;
    }
    if (nalog2 > 50) {
        cout << fam2[0] << "-" << fam2[fam2.length() - 1] << endl;
    }
    
}


int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double h1, s1, h2, s2;
    string fam1, fam2;
    cout << "¬ведите фамилию первого работника: ";
    cin >> fam1;
    cout << "¬ведите кол-во отработанных часов дл€ первого работника: ";
    cin >> h1;
    cout << "¬ведите ставку почасовой оплаты дл€ первого работника: ";
    cin >> s1;
    cin.ignore();
    
    cout << "¬ведите фамилию второго работника: ";
    cin >> fam2;
    cout << "¬ведите кол-во отработанных часов дл€ второго работника: ";
    cin >> h2;
    cout << "¬ведите ставку почасовой оплаты дл€ второго работника: ";
    cin >> s2;

    cout << fam1 << h1 << s1 << endl;
    f(h1, s1, h2, s2 , fam1, fam2);

    return 0;
}
