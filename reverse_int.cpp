#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;
// Hàm đảo ngược số nguyên
int reverse(int x) {
    string result = "";
    if (x == 0)
        return 0;
    if (x < 0 && x > numeric_limits<int>::min()) {
        x = -x;
        result.push_back('-');
    }
    int n = 0;
    while (x > 0) {
        int a = x % 10;
        x = x / 10;
        result.push_back(a + '0');
    }
    long long kq = 0;
    try {
        kq = stoll(result); // Dùng stoll để chuyển chuỗi thành số
    } catch (const std::invalid_argument& e) {
        return 0; // Trả về 0 khi có lỗi
    } catch (const std::out_of_range& e) {
        return 0; // Trả về 0 khi số quá lớn
    }
    if (kq < numeric_limits<int>::min() || kq > numeric_limits<int>::max()) {
        return 0; // Nếu tràn, trả về 0
    }
    return (int)kq;
}
int main() {
    int x = 1234567890;
    cout << reverse(x) << endl; // Output: 987654321
    return 0;
}