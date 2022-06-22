#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

void f00() {
	
}

struct Coord {
	int x;
	int y;
	/*bool operator < (Coord& other) {
		return true;
	}*/
};

bool f01(Coord& a, Coord& b) {
	return a.x < b.x;
}

class Functor {
public:
	bool operator()(Coord& a, Coord& b) {
		return a.x < b.x;
	}
	
	/*template<typename T, typename... Args>
	T operator()(Args... args) {
		return T();
	}*/
};

class Fish {
public:
	/*Fish(){};
	Fish(std::string name, int age, int size) {
		name = fishName;
		age = fishAge;
		size = fishSize;
	}
	~Fish(){};*/

	std::string fishName;
	int fishAge;
	int fishSize;
	friend std::ostream& operator<<(std::ostream& out, const Fish& obj) {
		out << obj.fishName << " ";
		out << "age: " << obj.fishAge << " ";
		out << "size: " << obj.fishSize << "\n";
		return out;
	}
};

bool lessAge(const Fish& a, const Fish& b) {
	return a.fishAge < b.fishAge;
}

int main() {
	/*std::vector<Coord> cool{ {1,2}, {3,1}, {1,32}, {6,8} };
	std::vector<int> numbers{ 11, 56, 3, 2 , 2, 7,123 };
	void (*p)(void) = f00;
	std::function<void(void)> funtor = f00;
	Functor funct;
	std::sort(numbers.begin(), numbers.end());
	std::sort(cool.begin(), cool.end(), funct);*/

	std::vector<Fish> pound{ {"Shark", 20, 23}, {"Som", 9, 15}, {"Nemo", 15, 20} };
	for (const auto& fish : pound) {
		std::cout << fish;
	}
	std::sort(pound.begin(), pound.end(), [](const Fish& a, const Fish& b)->bool 
		{return a.fishAge < b.fishAge; });
	for (const auto& fish : pound) {
		std::cout << fish;
	}

	[/*захват контекста*/](/*аргументы*/) {/*тело функции*/};
	auto lam=
	[](const Fish& a, const Fish& b)->bool {return a.fishSize < b.fishSize;}; //лямбда
	std::function<bool(const Fish&, const Fish&)>  q = lam;
	std::sort(pound.begin(), pound.end(), lam);

	return 0;
}