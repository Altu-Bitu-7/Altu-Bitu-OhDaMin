// 2271086 ���ٹ�

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b;

    // �� ū ���� ���ڿ��� �Է¹��� <= �־����� ���� A, B���� �ſ� ũ�Ƿ� C++�� �⺻ ���������δ� ó���� �� ����.
    std::cin >> a >> b;

    // �� ���ڿ� �� ���̰� ª�� �� �տ� 0�� �߰��Ͽ� �� ���ڿ��� ���̸� ������
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    std::string result = "";// ����� ������ ���ڿ� result
    int carry = 0;

    // �ڿ������� �� �ڸ� ���ڸ� �����ִ� �κ�
    for (int i = a.length() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;  // ���� �ڸ��� ���� ����
        result += (sum % 10) + '0';  // ���� �ڸ��� �� ����
    }

    // ������ �ø����� �����ִٸ� �߰����ֱ�
    if (carry > 0) {
        result += carry + '0';
    }

    // ���� ����� �����̹Ƿ� reverse ����
    std::reverse(result.begin(), result.end());

    std::cout << result << std::endl;// ���� ��� ���

    return 0;
}
