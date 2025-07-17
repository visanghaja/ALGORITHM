#include <iostream>

int main()
{
	int count = 0;
	int n, num;
	int distinction = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num != 1) {
			for (int i = 1; i < num + 1; i++) {
				if (num % i == 0) {
					distinction += 1;
					if (distinction > 2) break;
				}
			}
		}
		if (distinction == 2) ++count;
		distinction = 0;
	}

	std::cout << count;

	return 0;
}