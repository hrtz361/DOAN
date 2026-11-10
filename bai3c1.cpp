#include <iostream>

using namespace std;

int n;
int x[100];         // Mang luu hoán vi hien tai
bool used[100];     // Mang danh dau: used[j] = true neu giá tri j da duoc su dung

// Ham in mot hoan vi ra man hinh
void printPermutation() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// Ham quay lui tìm giá tri cho vi tri i
void backtrack(int i) {
    for (int j = 1; j <= n; j++) {
        // Neu gia tri j chua duoc dung o cac vi tri truoc
        if (!used[j]) {
            x[i] = j;        // Gan j cho vi tri i
            used[j] = true;  // Danh dau j da duoc su dung

            // Ðiem dung: Neu da xep du n vi tri
            if (i == n) {
                printPermutation(); // In ket qua hoan vi hoan chinh
            } else {
                backtrack(i + 1);   // De quy xep tiep cho vi tri i + 1
            }

            // Quay lùi: Bo danh dau j de thu cho cac truong hop khac
            used[j] = false;
        }
    }
}

int main() {
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Gia tri n phai la so nguyen duong!" << endl;
        return 1;
    }

    // Khoi tao mang danh dau tat ca cac so chua duoc su dung
    for (int j = 1; j <= n; j++) {
        used[j] = false;
    }

    cout << "Cac hoan vi cua " << n << " phan tu:" << endl;
    backtrack(1);

    return 0;
}
