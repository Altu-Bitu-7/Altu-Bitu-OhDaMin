#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ����� ū ũ���� ��� ����. �ִ밪�� ���� ���� ��ġ�� ���.
const int MAX_PRIME_LIST_SIZE = 1000000;

// Ȧ���� ���� �Ҽ� ���θ� �����ϴ� ����. 
// �ε��� i�� ���� (2*i + 3)�� ������.
vector<bool> prime_num_list(MAX_PRIME_LIST_SIZE / 2, true);

// �־��� �ִ� ���� ���� �Ҽ� ����Ʈ�� �����ϴ� �Լ�
void makePrimeNumList(int max_value) {
    // 3���� �����Ͽ� max_value�� �����ٱ��� �ݺ�
    for (int i = 3; i * i < max_value; i += 2) {
        // i�� �Ҽ��� ���, i�� ����� (Ȧ��)�� ���� �Ҽ� ���θ� false�� ����
        if (prime_num_list[i / 2]) {
            for (int j = i * i; j < max_value; j += 2 * i) {
                prime_num_list[j / 2] = false;
            }
        }
    }
}

// �־��� ���ڰ� �Ҽ����� ���θ� Ȯ���ϴ� �Լ�
bool isPrime(int number) {
    if (number <= 1) return false; // 1 ������ ���ڴ� �Ҽ��� �ƴ�
    if (number == 2 || number == 3) return true; // 2�� 3�� �Ҽ�
    if (number % 2 == 0) return false; // ¦���� �Ҽ��� �ƴ�
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false; // ����������� �Ҽ��� �ƴ�
    }
    return true; // �Ҽ���
}

// �־��� ���ڿ� ���� Goldbach's conjecture�� ���� �� �Ҽ��� ������ ǥ���Ǵ��� Ȯ���ϴ� �Լ�
void findPrimeNumPair(int n) {
    // 3 ~ n/2 loop
    for (int i = 3; i <= n / 2; i += 2) {
        // i�� n-i�� ��� prime
        if (prime_num_list[i / 2] && prime_num_list[(n - i) / 2]) {
            cout << n << " = " << i << " + " << n - i << '\n'; // ���
            return;
        }
    }
    // no pair
    cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); // C++ ǥ�� ����°��� ����ȭ ��Ȱ��ȭ
    cin.tie(NULL); // cin�� cout�� ����ȭ ��Ȱ��ȭ
    cout.tie(NULL); // cout�� cin�� ����ȭ ��Ȱ��ȭ

    int input_value;
    vector<int> inputs; // �Էµ� ���ڵ��� �����ϴ� ����
    int max_value = 0;  // �Էµ� ���ڵ� �� �ִ밪�� �����ϴ� ����

    // �Է��� �о inputs ���Ϳ� �����ϰ�, �ִ밪�� ����
    while (cin >> input_value && input_value != 0) {
        inputs.push_back(input_value);
        if (input_value > max_value) {
            max_value = input_value;
        }
    }

    // �Էµ� �ִ밪���� ū ���ڿ� ���ؼ��� �Ҽ� ����Ʈ�� ����
    if (max_value > 2) {
        makePrimeNumList(max_value);
    }

    // �� �Է� ���� ���� �Ҽ� ���� ã�� ����� ���
    for (int value : inputs) {
        findPrimeNumPair(value);
    }

    return 0;
}
