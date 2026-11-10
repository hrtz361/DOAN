#include <iostream>
#include <fstream>

using namespace std;

int n;
int x[100];         
bool used[100];     


void backtrack(int i, ofstream &outFile) {
    for (int j = 1; j <= n; j++) {
       
        if (!used[j]) {
            x[i] = j;        
            used[j] = true; 

            if (i == n) {
               
                for (int k = 1; k <= n; k++) {
                    outFile << x[k] << (k == n ? "" : " ");
                }
                outFile << "\n";
            } else {
                
                backtrack(i + 1, outFile);
            }

            used[j] = false;
        }
    }
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

    int testCase = 0;

    while (inFile >> n) {
        testCase++;
        if (n <= 0 || n > 10) {
            outFile << "TestCase " << testCase << ": N = " << n << " khong hop le (nen tu 1 den 10).\n";
            continue;
        }

        outFile << "--- CAC HOAN VI CUA N = " << n << " ---\n";
        
        for (int i = 1; i <= n; i++) {
            used[i] = false;
        }

        backtrack(1, outFile);
        outFile << "\n";
    }

    inFile.close();
    outFile.close();

    cout << "==> Da liet ke xong tat ca hoan vi va ghi vao file output.txt!" << endl;
    return 0;
}
