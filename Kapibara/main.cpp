#include <iostream>
#include <cmath>
#include <functional>
#include <thread>

//передача функ в другие функ\
указатель на функцию\
шаблонная функцию\
функторы - объект класса, ведущий себя как функ\
предикаты - функ, возвращ логические значения


typedef int (*Sir_gay)(int, int);

using Ser_gay = int (*)(int, int);

using Sier_gay = std::function<int(int, int)>;

int Sum(int a, int b)
{
	return a + b;
}

int Substruct(int a, int b)
{
	return a - b;
}

int Multiply(int a, int b)
{
	return a * b;
}

int DoAction1(int a, int b, int(*func)(int, int));
int DoAction2(int a, int b, Sir_gay func)
{


	return func(a, b);
}
int DoAction3(int a, int b, Ser_gay func);
int DoAction4(int a, int b, std::function<int(int, int)> funk);



int main()
{
	std::cout << "Enter first number:\n";
	int first{};
	std::cin >> first;
	std::cout << "Enter second number:\n";
	int second{};
	std::cin >> second;
	//std::cout << Sum << " " << Substruct << " " << Multiply << "\n";
	////00007FF78B53117C 00007FF78B53107D 00007FF78B531145
	////int (*var)(int, int) = Sum;
	//std::function<int(int, int)> var = Sum;
	//Sir_gay var2 = Multiply;
	//Ser_gay arrFunk[] { Sum, Multiply, Substruct };
	//for (auto& i : arrFunk)
	//{
	//	std::cout << first << " and " << second << " = " << i(first, second);
	//	std::cout << "\n"; 

	//	
	//}
	//var(3, 6);
	std::cout << "Enter type of action:\n1 - sum\n2 - substruct\n3 - multyply\n";
	int key{};
	std::cin >> key;
	int answer{};
	switch (key)
	{
	case 1:
		answer = DoAction2(first, second, Sum);
		break;
	case 2:
		answer = DoAction2(first, second, Substruct);
		break;
	case 3:
		answer = DoAction2(first, second, Multiply);
		break;
	}
	std::cout << "Your result: " << answer << "\n";
	
	std::thread tr(Sum, 3, first);




	tr.join();
	//tr.detach();

	return 0;
}