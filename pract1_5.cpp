#include <iostream>
using namespace std;

void vvod(double& h,double& s){
    cout << "Введите часы и ставку: ";
    cin >> h >> s;
   
}

void f(double& h, double& s, double& salary){
    salary = h*s;
}

int main(){
    setlocale(0, "");
    double h1, h2, s1, s2, salary1, salary2;

    cout << "Для 1 работника:" << endl;
    vvod(h1, s1);
    f(h1, s1, salary1);

    cout << "Для 2 работника:" << endl;
    vvod(h2, s2);
    f(h2, s2, salary2);

    cout << "Заработал больше работник под номером " << (salary1 > salary2?"1":"2") << endl;
    cout << "Сумма, заработанная двумя работниками вместе, составляет " << salary1+salary2 << endl;

    return 0;

}