/*
 * Matrix Exponentiation
 *
 * Complexity: O(k^3 log n) where k = matrix size
 *
 * Common use: Linear recurrences (Fibonacci in O(log n), etc.)
 *
 * Usage:
 *   Matrix base = {{1,1},{1,0}};  // Fibonacci transition
 *   Matrix result = mat_pow(base, n, MOD);
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;
const int MOD = 1e9 + 7;

Matrix mat_mul(Matrix& A, Matrix& B, long long mod) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (A[i][k])
                for (int j = 0; j < n; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

Matrix mat_pow(Matrix base, long long exp, long long mod) {
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1;  // identity

    while (exp > 0) {
        if (exp & 1) result = mat_mul(result, base, mod);
        base = mat_mul(base, base, mod);
        exp >>= 1;
    }
    return result;
}
