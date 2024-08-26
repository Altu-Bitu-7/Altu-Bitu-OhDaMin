// 2271086 ���ٹ�

#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;// ����ڷκ��� N�� K�� �Է� �ޱ�

    // 1~N ���ڸ� ������ ���� people�� �ʱ�ȭ
    std::vector<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    // ���ŵ� ������� ������ ������ ���� result�� �ʱ�ȭ
    std::vector<int> result;
    int index = 0;

    while (!people.empty()) {// people ���Ͱ� empty�� �� ������ ����
        index = (index + k - 1) % people.size();
        result.push_back(people[index]);
        people.erase(people.begin() + index);
    }

    std::cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {// ������ ���Ұ� �ƴ� ��� ', '�� �߰�
            std::cout << ", ";
        }
    }
    std::cout << ">\n";

    return 0;
}
