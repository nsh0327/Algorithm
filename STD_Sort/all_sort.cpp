#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 
#include <string>
#include <iterator>


void print_vector(const std::string& title, const std::vector<int>& vec) {
    std::cout << title << ": ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}
//�������� ���� �Լ�
void run_std_sort(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
    print_vector("1. std::sort (��������)", data);
}

//���� ������ ������ ä�� ���ο� ���ؿ� ���� ���� �Լ�
void run_std_stable_sort(std::vector<int>& data) {
    std::stable_sort(data.begin(), data.end());
    print_vector("2. std::stable_sort", data);
}
//N��°������ ���� �� �������� ���� X �Լ�
void run_std_partial_sort(std::vector<int>& data, int k) {
    auto middle = data.begin() + k;
    std::partial_sort(data.begin(), middle, data.end());

    std::cout << "3. std::partial_sort (���� ���� " << k << "��): ";
    for (int i = 0; i < k; ++i) {
        std::cout << "[" << data[i] << "] ";
    }
    for (size_t i = k; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}
//�迭 ��ü ���� X, N��° ��Ҹ� ���ڸ��� ��ġ ���� �Լ�
void run_std_nth_element(std::vector<int>& data, int n_index) {
    auto nth = data.begin() + n_index;
    std::nth_element(data.begin(), nth, data.end());

    std::cout << "4. std::nth_element (N=" << n_index << "��° ��� ã��): ";
    std::cout << "[Nth ���: " << data[n_index] << "] ";

    std::cout << " | ���� ����: ";
    for (int i = 0; i < n_index; ++i) std::cout << data[i] << " ";
    std::cout << " | ū ����: ";
    for (size_t i = n_index + 1; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << "\n";
}

//�̹� ���ĵǾ� �ִ��� Ȯ���ϴ� ���� �Լ�
void run_std_is_sorted(const std::vector<int>& data, const std::string& label) {
    bool is_sorted = std::is_sorted(data.begin(), data.end());
    std::cout << "5. std::is_sorted (" << label << "): "
        << (is_sorted ? "���ĵ�(True)" : "���� �ȵ�(False)") << "\n";
}


int main() {
    std::vector<int> original_data = { 15, 30, 25, 10, 30, 5, 20 };
    print_vector("���� ������", original_data);
    std::cout << "------------------------------------------\n";

    std::vector<int> data_for_sort = original_data;
    run_std_sort(data_for_sort);
    std::cout << "------------------------------------------\n";

    std::vector<int> data_for_stable_sort = original_data;
    run_std_stable_sort(data_for_stable_sort);
    std::cout << "------------------------------------------\n";

    std::vector<int> data_for_partial_sort = original_data;
    run_std_partial_sort(data_for_partial_sort, 3);
    std::cout << "------------------------------------------\n";

    std::vector<int> data_for_nth_element = original_data;
    run_std_nth_element(data_for_nth_element, 4); 
    std::cout << "------------------------------------------\n";

    run_std_is_sorted(original_data, "���� ������");
    run_std_is_sorted(data_for_sort, "���ĵ� ������");

    return 0;
}