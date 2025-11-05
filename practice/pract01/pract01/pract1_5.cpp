#include <iostream>
using namespace std;
template <typename T>

void f(T h1,  T s1, T h2,  T s2){
    double salary1 = h1 * s1;
    double salary2 = h2 * s2;

    cout << "Заработал больше работник под номером " << (salary1 > salary2?"1":"2") << endl;
    cout << "Сумма, заработанная двумя работниками вместе, составляет " << salary1+salary2 << endl;
}


int main(){
    setlocale(0, "");
    double h1, s1, h2, s2;

    cout << "Введите кол-во отработанных часов для первого работника: ";
    cin >> h1;
    cout << "Введите ставку почасовой оплаты для первого работника: ";
    cin >> s1;

    cout << "Введите кол-во отработанных часов для второго работника: ";
    cin >> h2;
    cout << "Введите ставку почасовой оплаты для второго работника: ";
    cin >> s2;
    
    f(h1, s1, h2, s2);

    return 0;
}
