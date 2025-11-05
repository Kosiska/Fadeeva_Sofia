#include <iostream>
#include <ctime>
using namespace std; //выбор вставки пузырек

void random_fill(int s[], int n, int start, int end){ //функция заполнения s[] случайными числами
    srand(time(0));
    for (int i = 0; i < n; i ++){
        int x = rand() % (end - start + 1) + start;
        s[i] = x;
    }
}

void vivo(int s[], int n){ //вывод массива

     for (int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

void search(int s[], int n){ //сортировка выбором (поиском)
    for (int i = 0; i < n; i++){
        int jmin = i;
        for (int j = i + 1; j < n; j++){
            if (s[j] < s[jmin]){
                jmin = j;
            }
        }
    swap(s[i], s[jmin]);
    }

}

void insert(int s[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j < 0 && s[j] < s[j-1]; j--){
            swap(s[j], s[j-1]);
        }
    }
}

void bubble(int s[], int n){
    bool f = true;
    int j = 0;
    while(f){
        f = false;
        for (int i = 0; i + j + 1 < n; i++){
            if (s[i] > s[i+1]){
                swap(s[i], s[i+1]);
                f = true;
            }
        }
        j++;  
    }
}

int main(){
    setlocale(0, "");
    int n = 100, start = 0, end = 10000;
    int* s = new int[n];
    cout << "До заполнения массива числами:" << endl;
    vivo(s, n);
    cout << endl << "После заполнения случайными числами: " << endl;;
    random_fill(s, n, start, end);
    vivo(s, n);


    return 0;
}
