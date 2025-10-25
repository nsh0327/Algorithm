#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sorted_data = { 1, 2, 3, 5, 7 };
    std::vector<int> unsorted_data = { 5, 1, 9, 3 };

    bool is_sorted_1 = std::is_sorted(sorted_data.begin(), sorted_data.end());
    std::cout << "������ {1, 2, 3, 5, 7}�� ���ĵǾ��°�? "
        << (is_sorted_1 ? "True" : "False") << std::endl;

    bool is_sorted_2 = std::is_sorted(unsorted_data.begin(), unsorted_data.end());
    std::cout << "������ {5, 1, 9, 3}�� ���ĵǾ��°�? "
        << (is_sorted_2 ? "True" : "False") << std::endl;

    std::vector<int> descending_data = { 9, 7, 5, 3, 1 };
    bool is_descending_sorted = std::is_sorted(
        descending_data.begin(),
        descending_data.end(),
        std::greater<int>() 
    );
    std::cout << "������ {9, 7, 5, 3, 1}�� �������� ���ĵǾ��°�? "
        << (is_descending_sorted ? "True" : "False") << std::endl;

    return 0;
}