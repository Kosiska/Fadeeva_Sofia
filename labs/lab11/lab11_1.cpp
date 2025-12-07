#include <iostream>
#include <vector>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()
using namespace std;


void vivo_square( const vector<vector<int>>& matrix) { //вывод квадратной матрицы
    
    int size = matrix.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void vvod(vector <vector<int>> & matrix){ //ввод значений в пустую матрицу
    int size = matrix.size();
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cin >> matrix[i][j];
        }
    }
}


void rand_vvod(vector <vector<int>> & matrix){ //заполнение случ числами
    srand(time(0));
    int size = matrix.size();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = rand();
        }
    }
}

void new_matr(int size){ //новая матрица со случ числами
    vector <vector<int>> matrix;
    srand(time(0));
    int size = matrix.size();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = rand();
            cout << matrix[i][j];
        }
    }
}


void sr_znach(const vector <vector<int>> & matrix){ //ср знач
    double size = matrix.size();
    double m = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            m += matrix[i][j];
        }
    }
    cout << m /size/size;
}

void min_el(const vector <vector<int>> & matrix){ //мин элемент столбцов матрицы m[0-n][0] , m[0-n][1]
    
    int size = matrix.size();
    vector<int> min_matr(size, 0); 
    int m;
    for (int i = 0; i < size; i++){
        m = matrix[0][i];
        for (int j = 0; j < size; j++){
            if (matrix[j][i] < m) m = matrix[j][i];
        }
        min_matr[i] = m;
        cout << m << " ";
    }
    cout << endl;
}



// g) Сортировка первого столбца методом вставок
void sort_insert(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 1; i < n; ++i) {
        int key = matrix[i][0];
        int j = i - 1;
        while (j >= 0 && matrix[j][0] > key) {
            matrix[j + 1][0] = matrix[j][0];
            --j;
        }
        matrix[j + 1][0] = key;
    }
}

// h) Сортировка последней строки методом выбора (по убыванию)
void sort_select(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int>& row = matrix[n - 1];  // последняя строка
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (row[j] > row[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(row[i], row[maxIdx]);
        }
    }
}

// i) Сортировка главной диагонали методом пузырька (по убыванию)
void sort_bubble(vector<vector<int>>& matrix) {
    int n = matrix.size();

    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (matrix[j][j] < matrix[j + 1][j + 1]) {
                swap(matrix[j][j], matrix[j + 1][j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

// j) Бинарный поиск на главной диагонали
int binary_search(const vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid][mid];

        if (midVal == target) {
            return mid;  // нашли элемент
        } else if (midVal < target) {
            right = mid - 1;  // ищем в левой половине (т.к. убывание)
        } else {
            left = mid + 1;   // ищем в правой половине
        }
    }
    return -1;  
}



int main(){
    int size;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> size;
    vector <vector<int>> matrix(size, vector<int>(size));
    
    cout << "Вывод квадратной матрицы:" << endl;
    vivo_square(matrix);

    return 0;
}