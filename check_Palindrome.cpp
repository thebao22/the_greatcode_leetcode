#include <iostream>
#include <string>   
using namespace std;
bool isPalindrome(int s) {
    int reversed = 0, original = s;
    while (s > 0) {
        int digit = s % 10;
        reversed = reversed * 10 + digit;
        s /= 10;
    }
    return original == reversed;
}
int main() {
    int s = 121;
    if (isPalindrome(s)) {
        cout << s << " is a palindrome." << endl;
    } else {
        cout << s << " is not a palindrome." << endl;
    }
    return 0;
}