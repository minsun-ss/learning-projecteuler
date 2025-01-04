#include "euler.hpp"

using namespace std;
using namespace euler;

long right_down_routes(long gridlength) {
    std::set<int> divisors;
    for (long i=2; i<=gridlength; i++) {
        divisors.insert(i);
    }

    long permutation = 1;
    for (long i=gridlength*2; i>gridlength; i--) {
        permutation *= i;

        std::set<int> remaining_divisors;
        for (const auto& i: divisors) {

            if (permutation % i == 0) {
                permutation /= i;
            } else {
                remaining_divisors.insert(i);
            }
        }
        divisors = remaining_divisors;
    }

    return permutation ;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(right_down_routes, 20);
    cout << "Number of routes: " << result << "\n";
    cout << "Duration: " << duration << "ns\n";
    return 0;
}
