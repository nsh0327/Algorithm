#include <iostream>
#include <vector>
#include <algorithm>

void print_nth_result(const std::vector<int>& vec, int n) {
    std::cout << "N��° ��Һ��� ����: ";
    for (int i = 0; i < n; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "| " << vec[n] << " (N=" << n << "��° ���) | ";
    std::cout << "N��° ��Һ��� ŭ: ";
    for (size_t i = n + 1; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = { 5, 1, 9, 3, 7, 2, 8, 4 };
    int n_index = 3;

    std::cout << "���� ������: 5 1 9 3 7 2 8 4\n";

    auto nth = data.begin() + n_index;
    std::nth_element(data.begin(), nth, data.end());

    std::cout << "std::nth_element �� (N=3��° ��� ã��): ";
    print_nth_result(data, n_index);

    return 0;
}