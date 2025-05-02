#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Function to find the first occurrence of a substring in a string
int strStr(string haystack, string needle) {
    if (haystack.length()<needle.length()) return -1;
    string temp;
    int result = -1;
    for (int i = 0; i<haystack.length(); i++){
        temp = "";
        for (int j = i; j<haystack.length() && temp.length() < needle.length(); j++){
            temp.push_back(haystack[j]);
        }
        if(temp == needle) {
            result = i;
            break;
        }
    }
    return result;
}
int main() {
    string haystack = "hello";
    string needle = "ll";
    int index = strStr(haystack, needle);
    cout << "The first occurrence of \"" << needle << "\" in \"" << haystack << "\" is at index: " << index << endl; // Output: 2
    return 0;
}
// Output: The first occurrence of "ll" in "hello" is at index: 2
// Explanation: The function strStr iterates through the haystack string and checks for the first occurrence of the needle string. If found, it returns the starting index; otherwise, it returns -1. The example input "hello" and "ll" results in an output of 2, indicating that "ll" starts at index 2 in "hello".
// The function uses a nested loop to compare substrings, which is not the most efficient approach. A more efficient solution would involve using string search algorithms like KMP or Rabin-Karp for larger strings.