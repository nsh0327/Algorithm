#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 

void print_stable_vector(const std::vector<std::pair<int, int>>& vec) {
    for (const auto& p : vec) {
      
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::pair<int, int>> data = {
        {5, 0}, {2, 1}, {9, 2}, {3, 3}, {2, 4} 
    };
    std::cout << "원래 데이터 (값, 인덱스): ";
    print_stable_vector(data);

    std::stable_sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; 
        });

    std::cout << "std::stable_sort 후 (값 기준): ";
    print_stable_vector(data);

    return 0;
}