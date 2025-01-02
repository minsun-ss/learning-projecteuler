#include "euler.hpp"

using namespace std;
using namespace euler;

int pythagorean_triplet_product(int sum) {
    // woah this is ugly
    // a - c = -b^2/sum-b
    // a + b + c = sum
    // a^2 + b^2 = c^2
    for (int a=1; a<sum; a++) {
        for (int c=1; c < sum; c++) {
            if ((a+c) < sum) {
                int b = sum - a - c;
                if ((pow(b, 2) * -1 / (sum-b)) == a-c) {
                    // cout << a << " " << b << " " << c << "\n";
                    return a * b * c;
                }
            }
        }
    }
    return -1;
}

int main(int, char**) {
    int p = pythagorean_triplet_product(1000);
    cout << "pythagorean triplet product: " <<  p << "\n";
    return 0;
}
