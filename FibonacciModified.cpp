#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;

/*

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
 */

void fft(vector<base> &a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        double ang = 2*M_PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    size_t n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);

    fft(fa, false), fft(fb, false);
    for (size_t i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = int(fa[i].real() + 0.5);
    int carry = 0;
    for (size_t i = 0; i < n; ++i) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
}

void sumv(const vector<int> &a, vector<int> &res) {
    int i, carry = 0, val = 0;
    for (i = 0; i < a.size(); ++i) {
        val = res[i] + a[i] + carry;
        res[i] = val % 10;
        carry = val / 10;
    }
    while (carry != 0) {
        val = res[i] + carry;
        res[i] = val % 10;
        carry = val / 10;
    }
}

int mainfm() {
    vector<int> a, b;
    int aa, bb, n;
    cin >> aa >> bb >> n;
    a.push_back(aa);
    b.push_back(bb);
    vector<int> res;

    int i = 2;
    while (i++ != n) {
        multiply(b, b, res);
        sumv(a, res);
        a = b;
        b = res;
    }
    int check = true;
    for (int i = res.size() - 1; i >= 0; --i) {
        if(res[i]==0 && check)continue;
        else check = false;
        cout << res[i];
    }
}