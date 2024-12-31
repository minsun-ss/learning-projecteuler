#include <iostream>

using namespace std;

// If we list all natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, or 9 The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
int main() {

    int multiple_sum = 0;
    for (int i=1; i < 1000; i++) {
        if (i % 3 == 0) {
            multiple_sum += i;
        } else if (i % 5 == 0) {
            multiple_sum += i;
        }
    }
    cout << multiple_sum << "\n";
    return 0;

}
