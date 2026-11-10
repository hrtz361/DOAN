#include <iostream>

using namespace std;

// Hàm de quy giai bài toán
void towerOfHanoi(int n, char nguon, char dich, char phu, int &stepCount) {
    // Ðiem dung de quy: 1 dia
    if (n == 1) {
        stepCount++;
        cout << "Buoc " << stepCount << ": Chuyen dia 1 tu coc " << nguon << " sang coc " << dich << "\n";
        return;
    }
    
    // Buoc 1: Chuyen (n-1) dia tu coc nguon sang coc phu 
    towerOfHanoi(n - 1, nguon, phu, dich, stepCount);
     
    // Buoc 2: Chuyen dia lon nhat (n) tu coc nguon sang coc dich
    stepCount++;
    cout << "Buoc " << stepCount << ": Chuyen dia " << n << " tu coc " << nguon << " sang coc " << dich << "\n";
    
    // Buoc 3: Chuyen (n-1) dia tu coc phu sang coc dich
    towerOfHanoi(n - 1, phu, dich, nguon, stepCount);
}

int main() {
    int n;
    
    // Nhap n
    cout << "Nhap so luong dia: ";
    cin >> n;

    // kiem tra lai du lieu
    if (cin.fail() || n <= 0) {
        cout << "So luong dia phai la so nguyen duong (> 0)!" << endl;
        return 1;
    }

    int stepCount = 0;
    cout << "\nLOI GIAI BAI TOAN THAP HA NOI VOI " << n << " DIA\n";
    cout << "==========================================\n";

    // Goi hàm giai bài toán (Chuyen n dia tu coc 'A' sang coc 'C', dùng coc 'B' làm phu)
    towerOfHanoi(n, 'A', 'C', 'B', stepCount);

    cout << "==========================================\n";
    cout << "Tong so buoc thuc hien: " << stepCount << endl;

    return 0;
}
