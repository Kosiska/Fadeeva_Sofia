#include <iostream>
using namespace std;


void f(double& h,double& s,double& p){
    double salary, nalog, total;
    salary = h * s * (1 + p / 100);
    nalog = salary * 0.13;
    total = salary - nalog;
    
    cout << "Общая заработанная сумма составляет " << salary << endl;
    cout << "Подоходный налог составляет " << nalog << endl;
    cout << "Сумма, получаемая на руки, составляет " << total << endl;
}


int main(){
    setlocale(0, "");
    double h, s, p;

    cout << "Введите кол-во отработанных часов: ";
    cin >> h ;
    cout << "Введите ставку почасовой оплаты: ";
    cin >> s;
    cout << "Введите % премии ";
    cin >> p;
    f(h,s,p);

    return 0;
}
