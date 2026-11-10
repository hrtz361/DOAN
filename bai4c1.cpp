#include <iostream>

using namespace std;

// Cau truc mo phong mot khung ham de quy
struct Frame {
    int val;    // Gia tri du lieu
    int state;  // Trang thai thuc thi hien tai cua ham

    // Constructor mac dinh va constructor khoi tao
    Frame() : val(0), state(0) {}
    Frame(int _val, int _state) : val(_val), state(_state) {}
};

// Cau truc Stack tu dinh nghia bang mang 1 chieu
struct MyStack {
    Frame items[1000]; // Mang luu tru cac phan tu
    int topIndex;      // Chi so cua phan tu tren dinh ngan xip

    // Khoi tao Stack rong
    MyStack() {
        topIndex = -1;
    }

    // Kiem tra Stack rong
    bool empty() {
        return topIndex == -1;
    }

    // Ðay mot phan tu vào Stack
    void push(Frame f) {
        topIndex++;
        items[topIndex] = f;
    }

    // Xóa phan tu tren dinh Stack
    void pop() {
        if (!empty()) {
            topIndex--;
        }
    }

    // Lay tham chieu den phan tu tren dinh Stack
    Frame& top() {
        return items[topIndex];
    }
};

// Ham khu de quy dung Stack tu dinh nghia
void processWithStack(int n) {
    MyStack S; // Khai bao Stack tu tao

    // Ðay trang thai ban dau vao Stack
    S.push(Frame(n, 0));

    while (!S.empty()) {
        Frame &top = S.top();

        // Ðiem dung: Khi bai toan dat kich thuoc nho nhat
        if (top.val == 1) {
            cout << top.val << " ";
            S.pop(); // Giai phong khoi Stack
        } else {
            // Buoc 1: Goi bai toan con nho hon
            if (top.state == 0) {
                top.state = 1; // Ðanh dau da chuyen sang buoc ke tiep
                S.push(Frame(top.val - 1, 0)); // Ðay bai toan con vao Stack
            } 
            // Bu?c 2: Hoàn tat xu ly sau khi bai toan con thuc thi xong
            else if (top.state == 1) {
                cout << top.val << " ";
                S.pop(); // Giai phong khoi Stack
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "[LOI] n phai la so nguyen duong!" << endl;
        return 1;
    }

    cout << "Ket qua khu de quy bang Stack tu dinh nghia cho n = " << n << ":" << endl;
    processWithStack(n);

    return 0;
}
