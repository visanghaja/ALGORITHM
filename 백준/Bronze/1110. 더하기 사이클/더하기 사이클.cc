#include <iostream>

int main() {
    int cnt = 0;
    int n;
    std::cin >> n;
    int first_n = n;

    while (true)
    {
        int left = n / 10;
        int right = n % 10;
        int sum = left + right;
        n = (right * 10) + (sum % 10);  // 새로운 수

        cnt++;

        if (n == first_n) {
            std::cout << cnt;
            break;
        }
    }

    return 0;
}
