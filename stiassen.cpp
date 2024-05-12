#include <iostream>

using namespace std;

void strassenMatrixMultiply2x2(int A[2][2], int B[2][2], int C[2][2]) {
    int a11 = A[0][0], a12 = A[0][1], a21 = A[1][0], a22 = A[1][1];
    int b11 = B[0][0], b12 = B[0][1], b21 = B[1][0], b22 = B[1][1];

    int P = (a11 + a22) * (b11 + b22);
    int Q = (a21 + a22) * b11;
    int R = a11 * (b12 - b22);
    int S = a22 * (b21 - b11);
    int T = (a11 + a12) * b22;
    int U = (a21 - a11) * (b11 + b12);
    int V = (a12 - a22) * (b21 + b22);

    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P + R - Q + U;
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of Matrix A (2x2):\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B (2x2):\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    strassenMatrixMultiply2x2(A, B, C);

    cout << "Matrix A:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix B:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix C (A * B) using Strassen algorithm:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
