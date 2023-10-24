#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<vector<int>> createMatrix(int n) {
    vector<vector<int>> Matrix(n, vector<int>(n, 0));

    int element = 1;

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Matrix[i][j] = element++;
        }
    }
    return Matrix;
}
vector<vector<int>> Multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];            
            }
        }
    }
    return result;
}
void printMatrix(const vector<vector<int>> C) {
    int m = C.size();	// number of rows
    int n = C[0].size();  // number of columns

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
    }
    cout << endl;
}
double calculateTFLOPS(int n, double elapsed_time) {
	double TFLOPS = (2.0 * n * n * n) / (elapsed_time / 1000000);
	return TFLOPS;
}
	

int main() {
    int n = 1024;
    vector<vector<int>> A = createMatrix(n);
    vector<vector<int>> B = createMatrix(n);

    auto start_time = std::chrono::high_resolution_clock::now();

    vector<vector<int>> result = Multiply(A,B);

    auto end_time = std::chrono::high_resolution_clock::now();
    printMatrix(result);

    auto duration = duration_cast<microseconds>(end_time - start_time);

    double elapsed_time = duration.count();

    cout << "Matrix mulitplication runtime: " << elapsed_time / 1000 << " milliseconds" << endl;

    cout << "TFLOPS: " << calculateTFLOPS(n, elapsed_time) << endl;



    return 0;
}
