#include "euler.hpp"
#include <gmpxx.h>

using namespace std;

int distinctPowers(int n) {
    std::set<mpz_class> powers;
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            mpz_class val = 1;
            for (int k=0; k < j; k++) {
                val *= i;
            }

            if (powers.find(val) == powers.end()) {
                powers.insert(val);
            } else {
                powers.insert(val);
            }
        }
    }
    return powers.size();
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(distinctPowers, 100);

    cout << "Distinct power numbers: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
