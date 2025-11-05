#include <iostream>
using namespace std;


double summa(double h,double s,double p){
    double n;
    n = h * s * (1 + p / 100);
    return n;
}

double nalog(double sum){
    double s = sum * 0.13;
    return s;
}

double totl(double sum, double nal){
    double t = sum - nal;
    return t;
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

    double k = summa(h,s,p);
    double n = nalog(k);
    cout << "Общая заработанная сумма составляет " << k << endl;
    cout << "Подоходный налог составляет " << n << endl;
    cout << "Сумма, получаемая на руки, составляет " << totl(k, n) << endl;

    return 0;
}
