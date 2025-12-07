#include <iostream>
#include <vector>
using namespace std;

void nnn(int n){
    if (n > 0){
        cout << n << " " << n*n << endl;
        return nnn(n-1);
    }
}

void vec_vivo(const vector<int>& vec, int size){
    if (size >= 0){
          cout << vec[size] << " ";
        return vec_vivo(vec, size - 1);
    }
}

int numbers(int n, int i = 1){
    if (n < 10) return i;
    i++;
    return numbers(n/10, i);
}

int summa(int num1, int num2, int s = 0 ){
    if (num1 > 0 && num2 > 0) {
        s+=2;
        return summa(num1 - 1, num2 - 1, s);
    }
    return s;
}

//сложение через прибавление единицы
int add(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (b > 0) {
        return add(a + 1, b - 1);
    }
    else {
        return add(a - 1, b + 1);
    }
}

//умножение через сложение
int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + multiply(a, b - 1);
    }
    else {
        return -multiply(a, -b);
    }
}

bool poz(const vector<int>& vec, int i = 0){
    if (i >= vec.size()) return false;
        if (vec[i] > 0) return true;
        return poz(vec, i+1);

}

bool neg(const vector<int>& vec, int i = 0){
    if (i >= vec.size()) return true;
        if (vec[i] <= 0) return false;
        return poz(vec, i+1);

}

bool search(const vector<int>& vec, int target, int i = 0){
    if (i >= vec.size()) return false;
        if (vec[i] > target) return true;
        return poz(vec, i+1);

}

int max_element(const vector<int>& vec, int m = -100000, int i = 0){
    if (i >= vec.size()) return m;
        if (vec[i] > m) {
            m = vec[i];
            return max_element(vec, m, i+1);

        }
        return max_element(vec, m, i+1);

}

int kolvo_poz(const vector<int>& vec, int i = 0, int s =0){
    if (i >= vec.size()) return s;
        if (vec[i] > 0) return kolvo_poz(vec, i +1, s+1);
        return kolvo_poz(vec, i+1, s);

}

void sort_search( vector<int>& vec){ //сортировка (поиском)
    int n = vec.size();
    for (int i = 0; i < n; i++){
        int jmin = i;
        for (int j = i + 1; j < n; j++){
            if (vec[j] < vec[jmin]){
                jmin = j;
            }
        }
    swap(vec[i], vec[jmin]);
    }

}


int find_max(vector<int> arr, int left, int right) {
    if (left == right) {
        return (arr[left] < 0) ? arr[left] : 0;
    }
    int mid = left + (right - left) / 2;
    int maxLeft = find_max(arr, left, mid);
    int maxRight = find_max(arr, mid + 1, right);
    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

// h) Сумма всех отриц элементов
int sum_neg(vector<int> arr, int left, int right) {
    if (left == right) {
        return (arr[left] < 0) ? arr[left] : 0;
    }
    int mid = left + (right - left) / 2;
    int sumLeft = sum_neg(arr, left, mid);
    int sumRight = sum_neg(arr, mid + 1, right);
    return sumLeft + sumRight;
}

// i) Произведение элементов, квадрат которых меньше W
double pro_w(vector<int> arr, int left, int right, int W) {
    if (left == right) {
        return (arr[left] * arr[left] < W) ? arr[left] : 1.0;
    }
    int mid = left + (right - left) / 2;
    double prodLeft = pro_w(arr, left, mid, W);
    double prodRight = pro_w(arr, mid + 1, right, W);
    return prodLeft * prodRight;
}



int main(){
    nnn(10);
    int v = 1;
    vector<int> vec;

    cout << "Введите число, 0 чтобы остановить ввод: ";
    while (v != 0){
        cin >> v;
        if (v != 0)
        vec.push_back(v);
    }

    vec_vivo(vec, vec.size());
    cout << endl;
    cout << numbers(12345);
    cout << endl;
    cout << summa(12,30);
    cout << endl;
    cout << add(11,20);
    cout << endl;
    cout << multiply(10,20);
    cout << endl;
    cout << poz({0,0,1});
   
}
