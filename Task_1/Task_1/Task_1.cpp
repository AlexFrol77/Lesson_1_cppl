#include <iostream>
#include <vector>
#include <Windows.h>

void print_vec(std::vector <int> my_vec) {
	for (const auto& el : my_vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <int> my_vec = { 4, 7, 9, 14, 12 };

	std::cout << "Входные данные: ";
	print_vec(my_vec);

	auto num_div = [&my_vec]() {
		for (auto& el : my_vec) {
			if (el % 2 != 0) {
				el *= 3;
			}
		}
	};
	num_div();

	std::cout << "Выходные данные: ";
	print_vec(my_vec);

	return 0;
}