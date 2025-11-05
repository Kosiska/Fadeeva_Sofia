#include <iostream>
using namespace std;
int main(){
    setlocale(0, "");
    double h, s, p, n;
    cout << "¬ведите кол-во отработанных часов: ";
    cin >> h ;
    cout << "¬ведите ставку почасовой оплаты: ";
    cin >> s;
    cout << "¬ведите % премии ";
    cin >> p;
    n = h * s * (1 + p / 100);
    cout << "ќбща€ заработанна€ сумма составл€ет " << n;
    return 0;
}
