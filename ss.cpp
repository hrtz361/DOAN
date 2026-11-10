
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;

// 1. Selection Sort
void selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        swap(a[i], a[min]);
    }
}

// 2. Insertion Sort
void insertionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// 3. Bubble Sort
void bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// 4. Quick Sort
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// Ham do thoi gian
template <typename Func>
double doThoiGian(vector<int> a, Func sortFunction) {
    auto start = high_resolution_clock::now();

    sortFunction(a);

    auto end = high_resolution_clock::now();

    return duration<double, milli>(end - start).count();
}

int main() {
    int n;

    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu khong hop le!";
        return 0;
    }

    srand(time(0));

    vector<int> a(n);

    // Tao mang ngau nhien
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }

    // Thuc nghiem 4 thuat toan
    double t1 = doThoiGian(a, selectionSort);

    double t2 = doThoiGian(a, insertionSort);

    double t3 = doThoiGian(a, bubbleSort);

    double t4 = doThoiGian(a, [](vector<int>& b) {
        quickSort(b, 0, b.size() - 1);
    });

    // Xuat ket qua
    cout << "\n===== KET QUA THUC NGHIEM =====\n";

    cout << "So phan tu: " << n << endl;

    cout << "\nSelection Sort: " << t1 << " ms";
    cout << "\nInsertion Sort: " << t2 << " ms";
    cout << "\nBubble Sort:    " << t3 << " ms";
    cout << "\nQuick Sort:     " << t4 << " ms";

    cout << "\n\n===== SO SANH =====\n";

    if (t1 < t2 && t1 < t3 && t1 < t4)
        cout << "Selection Sort nhanh nhat.";
    else if (t2 < t1 && t2 < t3 && t2 < t4)
        cout << "Insertion Sort nhanh nhat.";
    else if (t3 < t1 && t3 < t2 && t3 < t4)
        cout << "Bubble Sort nhanh nhat.";
    else if (t4 < t1 && t4 < t2 && t4 < t3)
        cout << "Quick Sort nhanh nhat.";
    else
        cout << "Co nhieu thuat toan co thoi gian gan bang nhau.";

    cout << endl;

    return 0;
}
