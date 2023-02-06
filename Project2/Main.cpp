#include<iostream>
#include<string>

class Car {
public:
	virtual void superCar() {
		std::cout << "superCar\n";
	}
	virtual ~Car(){}
};

class Van : public Car {
public:
	void superCar() override {
		std::cout << "Van superCar\n";
	}
	void superVan() {
		std::cout << "superVan\n";
	}
};

int main() {

	setlocale(LC_ALL, "ru");

	// Task 1
	double i = 32200030001.1;
	std::cout << "double i = " << i << '\n';
	int a = static_cast<int> (i);
	std::cout << "int a = " << a << '\n'; // -2147483648 т.к double i больше int Max, то int Max + 1

	// Task 2
	double c = 6.3;
	const double* pC = &c;
	double* ppC = const_cast<double*>(pC);
	std::cout << "===================\n";
	std::cout << *ppC << '\n';
	*ppC = 4.5;
	std::cout << *ppC << ' ' << c << '\n';

	// Task 3
	Car car;
	Van van;
	// upcast
	Car* pCar = &van;
	// downcast
	Van* pVan = (Van*)pCar;
	pCar->superCar();
	pVan->superCar();
	// Van* pVan = (Van*)&car - неуспешный downcast со ссылкой

	return 0;
}