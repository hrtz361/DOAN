#include <iostream>
#include <fstream>

using namespace std;

// 1. T? CÀI Ð?T STACK B?NG M?NG TINH
const int MAX_SIZE = 1000;
int customStack[MAX_SIZE];
int topIndex = -1; // Stack r?ng khi topIndex = -1

// Ki?m tra Stack r?ng
bool isEmpty() {
    return topIndex == -1;
}

// Ð?y ph?n t? vào Stack (Push)
void push(int value) {
    if (topIndex < MAX_SIZE - 1) {
        topIndex++;
        customStack[topIndex] = value;
    }
}

// L?y ph?n t? trên d?nh Stack ra (Pop)
int pop() {
    if (!isEmpty()) {
        int val = customStack[topIndex];
        topIndex--;
        return val;
    }
    return -1;
}

// 2. HÀM TÍNH GIAI TH?A KH? Ð? QUY B?NG STACK T? VI?T
long long factorialWithStack(int n) {
    if (n <= 1) return 1;

    // Reset Stack
    topIndex = -1;

    // Bu?c A: Ð?y t?t c? các giá tr? t? n gi?m v? 1 vào Stack
    for (int i = n; i >= 1; i--) {
        push(i);
    }

    // Bu?c B: Rút t?ng ph?n t? ra t? d?nh Stack và tính tích
    long long result = 1;
    while (!isEmpty()) {
        int val = pop();
        result *= val;
    }

    return result;
}

int main() {
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

    int n;
    int lineCount = 0;

    // Ð?c t?ng giá tr? N trong file input.txt
    while (inFile >> n) {
        lineCount++;
        if (n < 0) {
            outFile << "Dong " << lineCount << ": N = " << n << " khong hop le.\n";
        } else {
            long long res = factorialWithStack(n);
            outFile << "Dong " << lineCount << ": " << n << "! = " << res << "\n";
        }
    }

    inFile.close();
    outFile.close();

    cout << "==> Da tinh xong giai thua bang Stack tu cai dat va ghi vao file output.txt!" << endl;
    return 0;
}
