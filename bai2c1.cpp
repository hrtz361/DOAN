#include <iostream>

using namespace std;

// Khoi tao bang ghi nho 2 chieu
int memo[100][100];

// Hàm de quy có ghi nho tính C(n, k)
int combination(int n, int k) {
    // Ði?m d?ng: C(n, 0) = C(n, n) = 1
    if (k == 0 || k == n) return 1;

    // Neu dã tính giá tri này truoc do, tra ve luon tu bang memo
    if (memo[n][k] != -1) return memo[n][k];

    // Tinh toan theo công thuc Pascal và luu vào memo
    memo[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
    return memo[n][k];
}

int main() {
    int n, k;
    cout << "Nhap n va k: ";
    cin >> n >> k;

    // Kiem tra tính hop le cua du lieu nhap vào
    if (k < 0 || k > n) {
        cout << "Du lieu khong hop le! (Can 0 <= k <= n)" << endl;
        return 1;
    }

    // Khoi tao tat ca phan tu cua bang memo = -1 (chua tính)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            memo[i][j] = -1;
        }
    }

    int result = combination(n, k);

    cout << "Gia tri C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
