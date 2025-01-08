#include "euler.hpp"

using namespace std;
using namespace euler;

int again_fibonacci(int n) {
    // again and again with the fibonacci
    vector<int> av(n-1, 0);
    vector<int> bv(n-1, 0);
    vector<int> cv(n-1, 0);
    av[0] = 1;
    bv[0] = 1;

    int count = 2;
    while (true) {
        int carry = 0;
        for (size_t j=0; j < av.size(); j++) {
            int c = av[j] + bv[j] + carry;
            if (c>=10) {
                carry = 1;
                if (j == av.size()-1) {
                    return count+1;
                }
                c -= 10;
                cv[j] = c;
            } else {
                carry = 0;
                cv[j] = c;
            }
        }
        av = bv;
        bv = cv;
        count += 1;
    }
    return 0;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(again_fibonacci, 1000);
    cout << "Fibonacci: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
