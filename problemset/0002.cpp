#include <iostream>
#include <vector>

using namespace std;

// By considering the terms in the Fibonacci sequence whose values do not
// exceed 4mm, find sum of the event valued terms

// turns out I don't really need to do this recursively since I only need to do
// this once
long fibonacci(long max) {
    long even_sum = 0;
    long i = 2;

    std::vector<int> last_two = std::vector{1, 1};

    while (true) {
        int fib_sum = last_two[0] + last_two[1];
        if (fib_sum > max) {
            break;
        }
        // move the sum to even_sum if i is even
        if (fib_sum % 2 == 0) {
            even_sum += fib_sum;
        }

        last_two[0] = last_two[1];
        last_two[1] = fib_sum;

        i++;
    }
    return even_sum;
}

int main() {
    cout << fibonacci(4000000) << "\n";
    return 0;
}
