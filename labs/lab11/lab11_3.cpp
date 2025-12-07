#include <iostream>
#include <iomanip>  // для setw
using namespace std;


void matrix_sum(double** A, double** B, double** C, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


void matrix_multiply(double** A, double** B, double** C, 
                  int m, int n, int p) {
    // Обнуляем результат
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0.0;
        }
    }

    // Умножение
    for (int i = 0; i < m; ++i) {      // строки A
        for (int k = 0; k < n; ++k) {   // столбцы A / строки B
            for (int j = 0; j < p; ++j) { // столбцы B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main() {
    const int M = 2;  // строки A, строки C
    const int N = 3;  // столбцы A, строки B
    const int P = 2;  // столбцы B, столбцы C

    // A (2?3), B (3?2) ? C (2?2)


    // Выделяем память
    double** A = new double*[M];
    double** B = new double*[N];
    double** C = new double*[M];  // для суммы
    double** D = new double*[M];  // для произведения


    for (int i = 0; i < M; ++i) {
        A[i] = new double[N];
        C[i] = new double[N];
        D[i] = new double[P];
    }
    for (int i = 0; i < N; ++i) {
        B[i] = new double[P];
    }

    // Заполняем матрицы
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7;  B[0][1] = 8;
    B[1][0] = 9;  B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;


    // 1. Сумма матриц A + A (для примера)
    matrix_sum(A, A, C, M, N);
    cout << "Сумма A + A:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(6) << C[i][j];
        }
        cout << endl;
    }

    // 2. Произведение A ? B
    matrix_multiply(A, B, D, M, N, P);
    cout << "\nПроизведение A ? B:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            cout << setw(8) << D[i][j];
        }
        cout << endl;
    }

    // Освобождаем память
    for (int i = 0; i < M; ++i) {
        delete[] A[i]; delete[] C[i]; delete[] D[i];
    }
    for (int i = 0; i < N; ++i) {
        delete[] B[i];
    }
    delete[] A; delete[] B; delete[] C; delete[] D;


    return 0;
}
