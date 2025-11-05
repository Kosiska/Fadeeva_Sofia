#include <iostream>
using namespace std;

int main(){
    setlocale(0, "");
    double h, s, p, n;
    
    cout << "Введите кол-во отработанных часов: ";
    cin >> h ;
    cout << "Введите ставку почасовой оплаты: ";
    cin >> s;
    cout << "Введите % премии ";
    cin >> p;

    n = h * s * (1 + p / 100);
    cout << "Общая заработанная сумма составляет " << n;
    return 0;
}
