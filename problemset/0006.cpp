#include "euler.hpp"

using namespace std;
using namespace euler;

// Sum of squares (1^2 + 2^2... 10^2) = 385
// Square of sum (1 + 2...10)^2 = 3025
//
// Diff = 3025 - 385 = 2640.
// What is diff of first 100 numbers?
//
// sum of squares = (x^2 + (x+1)^2... (x+n)^n) = n(n+1)(2n+1)/6
// square of sum = (x + (x+1)... (x+n))^2 =   (n(n+1)/2)^2

int squares_diff(int n) {
    int square_of_sums = pow((n * (n+1))/2,2);
    int sum_of_squares = (n * (n+1) * (2*n+1))/6;

    return square_of_sums - sum_of_squares;
}

int main() {
    int rtime = euler::ntime(squares_diff, 100);
    cout << "Diff for numbers 1-100: " << squares_diff(100) << "\n";
    cout << "Time to run: " << rtime << "ns\n";
    return 0;
}
