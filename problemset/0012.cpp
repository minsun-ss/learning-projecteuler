#include "euler.hpp"

using namespace std;
using namespace euler;

long triangle_number(long n) {
    if (n==1) {
        return 1;
    } else {
        return n * (n+1) / 2;
    }
}

size_t divisors(long n) {
   std::vector<long> divisors = {1, n};
   for (int i=2; i <= pow(n,0.5); i++) {
       if (n%i == 0) {
           divisors.push_back(i);
           divisors.push_back(n/i);
       }
   }
   return divisors.size();
}

long divisors_500() {
    long counter = 10;
    while (true) {
        long tn = triangle_number(counter);
        if (divisors(tn)>=500) {
            return tn;
        }
        counter ++;
    }
}

int main(int, char**) {
    cout << "Over 500 divisors: " << divisors_500() << "\n";
    return 0;
}
