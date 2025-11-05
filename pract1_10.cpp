#include <iostream>
#include <cstdio>
using namespace std;

double sum_1r_2m(double n[][4]){ //1  сумма 1 работник 2 месяц (умножаем на 0.87, т.к. с вычетом налогов)
    return (n[1][0] * 0.87);
}

double sum_nalog_3r(double n[][4], int m){ //2  общ сумма налога у 3 за весь год
    double nal = 0;
    for (int i = 0; i < m; i++){
        nal += n[i][2];
    }
    return nal*0.13;
}

double max_salary_3m(double n[][4], int r){ //3  номер работника с макс зп в 3 месяце
    int k = 0;
    double max = -1;
    for (int i  = 0; i < r; i++){
        if (n[2][i] > max){
            max = n[2][i];
            k = i+1;
        }
    }
    return k;
}

int main(){
    setlocale(0, "");
    double h, s, k = 1, sum = 0;
    const int r = 4, m = 3;
    double n[m][r];

    //создаем двумерный массив с зп (без вычета налогов):
    for (int i = 0; i < m; i++){
        printf( "%d месяц:\n", i+1);
        for (int j = 0; j < r;j++){
            printf("\tВведите через пробел кол-во отработанных часов и почасовую ставку для %d работника ", j+1);
            cin >> h >> s;
            n[i][j] = h*s;
            sum += h*s*0.87; //4 общ сумма заработанная всей бригадой
        }
    }
    
    cout << "Сумма, полученная первым работником на руки во втором месяце: " << sum_1r_2m(n) << endl;
    cout << "Общая сумма налога, удержанная у третьего работника за весь год: " << sum_nalog_3r(n, m) << endl;
    cout << "Номер работника, заработавшего больше всех в третьем месяце: " << max_salary_3m(n, r) << endl;
    cout << "Общая сумма, заработанная всей бригадой за год: "<< sum << endl;

    return 0;

}