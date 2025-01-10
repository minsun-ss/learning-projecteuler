#include "euler.hpp"

using namespace std;
using namespace euler;

int spiral(int n) {
    int counter = 2;
    int left;
    int right = 1;
    int sumSpiral = 1;
    for (int i=0; i<n-1; i++) {
        // cout << sumSpiral << "\n";
        if (i==0) {
            left = 5;
        }  else {
            left += (i+2)/2*4;
        }
        right += counter;
        sumSpiral += right;
        sumSpiral += left;

        counter += 2;
    }

    return sumSpiral;
}
int main(int, char**) {
    auto [result, duration] = euler::ntime(spiral, 1001);
    cout << "Diagonal sum: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
