// 2271086 ���ٹ�

#include <iostream>
#include <stack>
#include <string>

int main() {
    while (true) {
        std::string line;
        std::getline(std::cin, line);

        // �Է� ���� ����
        if (line == ".") {
            break;
        }

        // ���� �Ǵ��� ���� stack ����
        std::stack<char> bracket_stack;
        bool is_balanced = true;

        for (char ch : line) {
            if (ch == '(' || ch == '[') {
                // ���� ��ȣ -> �߰�
                bracket_stack.push(ch);
            }
            else if (ch == ')' || ch == ']') {
                // ������ ��ȣ ->
                if (bracket_stack.empty()) {
                    // ������ ����ִٸ� -> ¦�� ���� x
                    is_balanced = false;
                    break;
                }

                // ������ top�� ���� ��ȣ�� ¦�� �´��� Ȯ��
                char top = bracket_stack.top();
                bracket_stack.pop();

                if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
                    // ¦�� ���� �ʴ� ���
                    is_balanced = false;
                    break;
                }
            }
        }

        // �����ִ� ���� ��ȣ�� �ִٸ� -> ������ ���� x
        if (!bracket_stack.empty()) {
            is_balanced = false;
        }

        // ��� ���
        if (is_balanced) {
            std::cout << "yes\n";
        }
        else {
            std::cout << "no\n";
        }
    }

    return 0;
}
