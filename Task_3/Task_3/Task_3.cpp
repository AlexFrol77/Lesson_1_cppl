#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <functional>
#include <Windows.h>

struct Source_num {

	Source_num(double degree, double pi, double angles) {
		this->degree = degree;
		this->pi = pi;
		this->angles = angles;
	}
	
	~Source_num() {};

	double get_degree() {
		return degree;
	}
	double get_pi() {
		return pi;
	}
	double get_angles() {
		return angles;
	}

private:

	double degree,
		   pi,
		   angles;
};

void convertor(std::vector<Source_num>& s_num, 
	std::function<void(double degree, double pi, double angles)> func_print_source, 
	std::function<void(double degree, double pi, double angles)> func_cos_sin) {
	std::cout << "[Входные данные]: ";
	for (auto &el : s_num) {
		func_print_source(el.get_degree(), el.get_pi(), el.get_angles());
	}
	std::cout << std::endl;
	std::cout << "[Выходные данные]: " << std::endl;
	for (auto &el : s_num) {
		func_cos_sin(el.get_degree(), el.get_pi(), el.get_angles());
	}
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Source_num num_1(30, 3.1415926, 180);
	Source_num num_2(60, 3.1415926, 180);
	Source_num num_3(90, 3.1415926, 180);
	
	std::vector <Source_num> vec_source = {num_1, num_2, num_3};

	std::function<void(double degree, double pi, double angles)> print_source;
	std::function<void(double degree, double pi, double angles)> cos_sin;

	print_source = [](auto degree, auto pi, auto angles) {
		std::cout << std::setprecision(8);
		std::cout << degree << " * " << pi << " / " << angles << ", ";
	};
	cos_sin = [](auto degree, auto pi, auto angles) {
		std::cout << std::setprecision(6);
		std::cout << (degree * (pi / angles)) << " " <<
			"sin: " << sin(degree * (pi / angles)) << " " <<
			"cos: " << cos(degree * (pi / angles)) << std::endl;
	};

	convertor(vec_source, print_source, cos_sin);

	return 0;
}


