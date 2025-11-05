#include <iostream>
using namespace std;

void vvod(double& h,double& s,double& p){
    cout << "Введите кол-во отработанных часов: ";
    cin >> h ;
    cout << "Введите ставку почасовой оплаты: ";
    cin >> s;
    cout << "Введите % премии ";
    cin >> p;
}

void f(double& h,double& s,double& p, double& salary,double& nalog,double& total){
    salary = h * s * (1 + p / 100);
    nalog = salary * 0.13;
    total = salary - nalog;
}


int main(){
    setlocale(0, "");
    double h, s, p, salary ,nalog, total;

    vvod(h, s, p);
    f(h, s, p, salary ,nalog, total);

    cout << "Общая заработанная сумма составляет " << salary << endl;
    cout << "Подоходный налог составляет " << nalog << endl;
    cout << "Сумма, получаемая на руки, составляет " << total << endl;

    return 0;
}
