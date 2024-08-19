#include <iostream>
#include <cmath>
using namespace std;

typedef pair<int, int> ci;

// ���̾�Ʈ ���� �� ü�߰� ���� ��緮�� ����ϴ� �Լ�
ci diet(int D, int W0, int I, int I0, int T, int A) {
    while (D--) {
        int dailyEnergyExpenditure = I0 + A; // ���� ������ �Һ�
        W0 += (I - dailyEnergyExpenditure); // ü�� ��ȭ

        // ���� ��緮 ��ȭ ���
        if (abs(I - dailyEnergyExpenditure) > T) {
            I0 += floor((double)(I - dailyEnergyExpenditure) / 2);
        }

        // ��� ���� Ȯ��
        if (W0 <= 0 || I0 <= 0) {
            return ci(0, 0);
        }
    }
    return ci(W0, I0);
}

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T; // ���̾�Ʈ �� ü��(W0), ���� ������ ���뷮(I0), ���� ��緮(I0), ���� ��緮 ��ȭ ��ġ(T)
    cin >> D >> I >> A; // ���̾�Ʈ �Ⱓ(D), ���̾�Ʈ �Ⱓ ���� ������ ���뷮(I), ���� Ȱ�� ��緮(A)

    // 1) ���� ��緮 ��ȭ�� ������� ���� ���
    int finalWeightWithoutChange = W0 + (I - (I0 + A)) * D;
    if (finalWeightWithoutChange <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << finalWeightWithoutChange << " " << I0 << "\n";
    }

    // 2) ���� ��緮 ��ȭ�� ����� ���
    ci result = diet(D, W0, I, I0, T, A);
    if (result.first <= 0 || result.second <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        // ��� ���θ� Ȯ��
        string yoYo = (I0 > result.second) ? "YOYO" : "NO";
        cout << result.first << " " << result.second << " " << yoYo << "\n";
    }

    return 0;
}
