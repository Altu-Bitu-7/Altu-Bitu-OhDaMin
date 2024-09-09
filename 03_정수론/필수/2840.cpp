#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// �Լ� ����
bool processCircle(vector<char>& circle, int& currentIndex, int n, int k);
void printResult(const vector<char>& circle, int n, int currentIndex);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<char> circle(n, '?'); // ���� ���¸� �����ϴ� ����
    int currentIndex = 0;

    // ���� ���¸� ó���ϴ� �Լ� ȣ��
    if (processCircle(circle, currentIndex, n, k)) {
        // ������ �ߺ��� Ȯ���ϴ� �迭
        vector<bool> chk(26, false);
        for (int i = 0; i < n; ++i) {
            if (circle[i] == '?') continue;
            if (chk[circle[i] - 'A']) {
                cout << "!" << endl;
                return 0;
            }
            chk[circle[i] - 'A'] = true;
        }

        // ���� ���� ���
        printResult(circle, n, currentIndex);
    }
    else {
        cout << "!" << endl;
    }

    return 0;
}

// ���� ���¸� ó���ϴ� �Լ�
bool processCircle(vector<char>& circle, int& currentIndex, int n, int k) {
    for (int i = 0; i < k; ++i) {
        int step;
        char ch;
        cin >> step >> ch;

        // ���� ��ġ���� step��ŭ �������� �̵�
        int nextIndex = ((currentIndex - step) % n + n) % n;

        if (circle[nextIndex] == '?') {
            circle[nextIndex] = ch;
        }
        else if (circle[nextIndex] != ch) {
            return false; // ��� -> false ��ȯ
        }

        currentIndex = nextIndex;
    }

    return true; // ��� �˻簡 ��� -> true ��ȯ
}

// ���� ���� ���
void printResult(const vector<char>& circle, int n, int currentIndex) {
    for (int i = 0; i < n; ++i) {
        cout << circle[(currentIndex + i) % n];
    }
    cout << endl;
}
