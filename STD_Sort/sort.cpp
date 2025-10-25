#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int>& vec) {
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = { 5, 1, 9, 3, 7, 2 };
    std::cout << "���� ������: ";
    print_vector(data);

    std::sort(data.begin(), data.end());

    std::cout << "std::sort �� (��������): ";
    print_vector(data);

    std::sort(data.begin(), data.end(), std::greater<int>());
    std::cout << "std::sort �� (��������): ";
    print_vector(data);

    return 0;
}