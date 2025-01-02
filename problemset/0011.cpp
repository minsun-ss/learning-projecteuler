#include "euler.hpp"

using namespace std;
using namespace euler;

std::vector<std::vector<int>> make_grid(string grid) {
    std::vector<std::vector<int>> num_grid;
    auto g = euler::split(grid, "\n");
    for (auto& i: g) {
        std::vector<int> num_row;
        for (auto& j: euler::split(i, " ")) {
            if (j != "") {
            num_row.push_back(std::stoi(j));
            }
        }
        if (num_row.size() > 0) {
            num_grid.push_back(num_row);
        }
    }
    return num_grid;
}


long largest_product_in_grid(std::vector<std::vector<int>>& grid) {
    long largest_product = 0;
    for (size_t col = 0; col < grid.size(); col++) {
        for (size_t row = 0; row < grid[0].size(); row++) {
            // vertical
            if ((col + 4) < grid.size()) {
                long product = grid[col][row] * grid[col+1][row] * grid[col+2][row] * grid[col+3][row];
                if (product > largest_product) {
                    largest_product = product;
                }
            }

            // horizontal
            if ((row + 4) < grid[0].size()) {
                long product = grid[col][row] * grid[col][row+1] * grid[col][row+2] * grid[col][row+3];
                if (product > largest_product) {
                    largest_product = product;
                }
            }

            if ((col + 4) < grid.size() && (row+4) < grid[0].size()) {
                long product = grid[col][row] * grid[col+1][row+1] * grid[col+2][row+2] * grid[col+3][row+3];
                if (product > largest_product) {
                    largest_product = product;
                }
                product = grid[col+3][row] * grid[col+2][row+1] * grid[col+1][row+2] * grid[col][row+3];
                if (product > largest_product) {
                    largest_product = product;
                }
            }
        }
    }
    return largest_product;
}

int main(int, char**) {
    auto gtext = euler::read("problemset/0011.txt");
    auto g = make_grid(gtext);
    auto p = largest_product_in_grid(g);

    cout << "Largest 4 digit product in grid: " <<  p << "\n";
    return 0;
}
