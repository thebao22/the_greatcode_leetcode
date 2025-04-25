#include<iostream>
using namespace std;
char c[1000][1000];
string convert(string s, int numRows) {
    char zz[1000][1000] = {};
    int i = 0, j = 0, k = 0;
    int size = s.size();
    int maxCol = 0;

    if (numRows == 1) {
        for (k = 0; k < size; k++) {
            zz[0][k] = s[k];
        }
        maxCol = size - 1;
    } else {
        while (k < size) {
            // Đi xuống
            for (i = 0; i < numRows && k < size; ++i) {
                zz[i][j] = s[k++];
            }
            i -= 2;
            j++;
            // Đi chéo lên
            while (i > 0 && k < size) {
                zz[i][j] = s[k++];
                i--;
                j++;
            }
        }
        maxCol = j; // cập nhật số cột thực sự dùng
    }

    string result;
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c <= maxCol; ++c) {
            if (zz[r][c] != '\0') {
                result += zz[r][c];
            }
        }
    }

    return result;
}
using namespace std;
int main(){    
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl; // Output: "PAHNAPLSIIGYIR"
    return 0;
}
