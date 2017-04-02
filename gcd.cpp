#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}
int gcd_fast(int a, int b){
	if (b == 0)
		return a;
	else
		return gcd_fast(b, a%b);
}
void test_solution() {
	int a = 0, b = 0;
	assert(gcd_naive(50, 45) == 5);
	assert(gcd_fast(45, 100) == 5);
	for (int n = 0; n < 100; ++n)
		a = rand() % 1000;
	b = rand() % 1000;
	assert(gcd_naive(a, b) == gcd_fast(a, b));
}

int main() {
	int a, b;

	std::cin >> a >> b;
	std::cout << gcd_fast(a, b) << std::endl;
	/*while (true){
	int a, b;

	std::cin >> a >> b;

	std::cout <<"gcd_naive (" <<a<<","<<b<<") ="<< gcd_naive(a, b) << std::endl;
	std::cout << "gcd_fast (" << a << "," << b << ") =" << gcd_fast(a, b) << std::endl;
	}*/
	//test_solution();
	//system("pause");
	return 0;
}
