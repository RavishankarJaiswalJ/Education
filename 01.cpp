// #include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1.empty() || s2.empty()) {
        cout << 0 << endl; // If any string is empty, result is 0
        return 0;
    }

    vector<int> a;
    for (char c : s1) {
        a.push_back((int)c);
    }
    sort(a.begin(), a.end()); // Sort the ASCII values of characters in s1

    int res = 0; 
    int prev = a[0]; // Initialize `prev` to the smallest ASCII value in `a`

    for (char c : s2) {
        int b = (int)c; // ASCII value of current character in s2
        int l = 0, r = a.size() - 1;
        int closest = -1;
        int min_diff = INT_MAX;

        while (l <= r) {
            int mid = (l + r) / 2;

            int diff = abs(a[mid] - b);
            if (diff < min_diff || (diff == min_diff && abs(a[mid] - prev) < abs(closest - prev))) {
                closest = a[mid];
                min_diff = diff;
            }

            if (a[mid] == b) {
                break; // Exact match found
            } else if (a[mid] < b) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        res += min_diff;
        prev = closest; // Update `prev` to the closest value
    }

    cout << res << endl;
    return 0;
}
