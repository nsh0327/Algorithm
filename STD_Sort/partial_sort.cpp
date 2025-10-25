#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 

void print_vector_partial(const std::vector<int>& vec, int k) {
    for (int i = 0; i < k; ++i) {
        std::cout << vec[i] << " (정렬됨) ";
    }
    for (size_t i = k; i < vec.size(); ++i) {
        std::cout << vec[i] << " (미정렬) ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = { 5, 1, 9, 3, 7, 2, 8, 4 };
    int k = 3; 

    std::cout << "원래 데이터: 5 1 9 3 7 2 8 4\n";

    auto middle = data.begin() + k;
    std::partial_sort(data.begin(), middle, data.end());

    std::cout << "std::partial_sort 후 (가장 작은 3개): ";
    print_vector_partial(data, k);

    return 0;
}