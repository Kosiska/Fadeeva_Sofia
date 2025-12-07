
#include <iostream>
#include <iomanip>
using namespace std;

double vectors(double* a, double* b, int n) { //скалярное произведение двух векторов
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += a[i] * b[i];
    }
    return result;
}


void add_vectors(double* a, double* b, double* result, int n) { //сложение векторов
    for (int i = 0; i < n; ++i) {
        result[i] = a[i] + b[i];
    }
}

int find_max(double* arr, int n, double target, double& foundValue) {//Поиск элемента или ближайшего большего
    int pos = -1;
    double minGreater = 1e300;  // очень большое число


    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            pos = i;
            foundValue = target;
            return pos;
        }
        if (arr[i] > target && arr[i] < minGreater) {
            minGreater = arr[i];
            pos = i;
        }
    }

    if (pos != -1) {
        foundValue = minGreater;
    }
    return pos;  // -1 если нет ни равного, ни большего
}



void matrix_sum(double** A, double** B, double** result, int rows, int cols) { // Сумма двух матриц
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}



void matrix_multiply(double** A, double** B, double** result, int rowsA, int colsA, int colsB) {
    // Инициализация результата нулями
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0.0;
        }
    }

    // Умножение
    for (int i = 0; i < rowsA; ++i) {
        for (int k = 0; k < colsA; ++k) {
            for (int j = 0; j < colsB; ++j) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main(){

const int N = 3;
    const int M = 2;

    // 1. Тестируем векторные операции
    cout << "=== Векторные операции ===\n";


    double* v1 = new double[N]{1.0, 2.0, 3.0};
    double* v2 = new double[N]{4.0, 5.0, 6.0};
    double* sumVec = new double[N];


    // Скалярное произведение
    double dp = vectors(v1, v2, N);
    cout << "Скалярное произведение: " << dp << endl;

    // Сложение
    add_vectors(v1, v2, sumVec, N);
    cout << "Сумма векторов: ";
    for (int i = 0; i < N; ++i) cout << sumVec[i] << " ";
    cout << endl;

    // Поиск или следующий больший
    double target = 2.5;
    double found;
    int idx = find_max(v1, N, target, found);
    if (idx != -1) {
        cout << "Найден элемент >= " << target << ": " << found << " (позиция " << idx << ")" << endl;
    } else {
        cout << "Нет элемента >= " << target << endl;
    }

    delete[] v1; delete[] v2; delete[] sumVec;

    // 2. Тестируем матричные операции
    cout << "\n=== Матричные операции ===\n";

    // Матрица A (3x2)
    double** A = new double*[3];
    for (int i = 0; i < 3; ++i) A[i] = new double[2];
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    A[2][0] = 5; A[2][1] = 6;

    // Матрица B (3x2) — для сложения
    double** B = new double*[3];
    for (int i = 0; i < 3; ++i) B[i] = new double[2];
    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    // Результат сложения (3x2)
    double** C = new double*[3];
    for (int i = 0; i < 3; ++i) C[i] = new double[2];


    matrix_sum(A, B, C, 3, 2);
    cout << "Сумма матриц A+B:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << setw(4) << C[i][j];
        }
        cout << endl;
    }

    // Матрица D (2x3) — для умножения
    double** D = new double*[2];
    for (int i = 0; i < 2; ++i) D[i] = new double[3];
    D[0][0] = 1; D[0][1] = 2; D[0][2] = 3;
    D[1][0] = 4; D[1][1] = 5; D[1][2] = 6;


    // Результат умножения A*D (3x3)
    double** E = new double*[3];
    for (int i = 0; i < 3; ++i) E[i] = new double[3];

    matrix_multiply(A, D, E, 3, 2, 3);
    cout << "Произведение матриц A*D:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << setw(6) << E[i][j];
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) delete[] A[i]; delete[] A;
    for (int i = 0; i < 3; ++i) delete[] B[i]; delete[] B;
    for (int i = 0; i < 3; ++i) delete[] C[i]; delete[] C;
    for (int i = 0; i < 2; ++i) delete[] D[i]; delete[] D;
    for (int i = 0; i < 3; ++i) delete[] E[i]; delete[] E;
return 0;
}