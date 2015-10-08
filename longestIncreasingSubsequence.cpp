#include<bits/stdc++.h>

using namespace std;

void LongestIncreasingSubSeq(vector<int> arr) {
    int n = (int) arr.size();
    vector<int> q(n, 1);
    vector<int> sol(n);
    for (int k = 0; k < n; ++k) sol[k] = k;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (q[j] + 1 > q[i]) {
                    q[i] = q[j] + 1;
                    sol[i] = j;
                }
            }
        }
    }
    int maxe = 0;
    for (int l = 0; l < n; ++l) {
        if (sol[l] > sol[maxe])
            maxe = l;
    }
    cout << sol[maxe] << "\n";
    int t = maxe, newt = maxe;
    stack<int> lis;
    do {
        t = newt;
        lis.push(arr[t]);
        newt = sol[t];
    } while (t != newt);
    while (!lis.empty()) {
        cout << lis.top() << " ";
        lis.pop();
    }
}

int mainlis() {

    vector<int> arr{-7, 10, 9, 2, 3, 8, 8, 1};
    LongestIncreasingSubSeq(arr);
    return 0;
}