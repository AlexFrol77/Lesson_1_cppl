#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <Windows.h>

std::variant <int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::variant <int, std::string, std::vector<int>> my_variant = get_variant();

	if (std::holds_alternative<int>(my_variant)) {
		int temp = std::get<int>(my_variant);
		std::cout << "Это число умноженное на 2: " << temp * 2 << std::endl;
	}
	if (std::holds_alternative<std::string>(my_variant)) {
		auto temp = std::get<std::string>(my_variant);
		std::cout << "Это строка: " << temp << std::endl;
	}
	if (std::holds_alternative<std::vector<int>>(my_variant)) {
		auto temp = std::get<std::vector<int>>(my_variant);
		std::cout << "Это вектор: ";
		for (const auto& el : temp) {
			std::cout << el << " " << std::endl;
		}
	}

	return 0;
}