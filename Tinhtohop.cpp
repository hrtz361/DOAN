#include <iostream>
#include <fstream>

using namespace std;

long long memo[105][105];

long long C(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k > n || k < 0) return 0;
    
    if (memo[n][k] != -1) {
        return memo[n][k];
    }
    
    memo[n][k] = C(n - 1, k - 1) + C(n - 1, k);
    return memo[n][k];
}

int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            memo[i][j] = -1;
        }
    }

    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cout << "[LOI] Khong the mo file input.txt!" << endl;
        system("pause");
        return 1;
    }

    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cout << "[LOI] Khong the tao file output.txt!" << endl;
        inFile.close();
        system("pause");
        return 1;
    }

    int n, k;
    int lineCount = 0;

    while (inFile >> n >> k) {
        lineCount++;
        if (n < 0 || k < 0 || k > n) {
            outFile << "Dong " << lineCount << ": C(" << n << ", " << k << ") = 0 (Gia tri khong hop le)\n";
        } else {
            long long result = C(n, k);
            outFile << "Dong " << lineCount << ": C(" << n << ", " << k << ") = " << result << "\n";
        }
    }

    inFile.close();
    outFile.close();

    cout << "==> Da tinh xong tat ca " << lineCount << " cap n, k va ghi vao output.txt!" << endl;
    return 0;
}
