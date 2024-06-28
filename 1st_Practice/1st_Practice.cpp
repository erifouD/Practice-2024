
#include <iostream>


class FFracture {
public:
	float Num = 1.f, Denum = -2.f;

	void Reset(float X) {
		Num = X;
		Denum = -2.f;
	}

	float Result() { return Num / Denum; }

	void Next(float X, float N) {
		Num = X * (abs(N - 1.5) + 0.5);
		Denum *= -2.f;
	}
};




int main()
{
	setlocale(0, "ru");
	
	float X, N, Presition, Sum = 0;
	std::cin >> X >> N >> Presition;
	FFracture Init, Previous;
	Init.Num *= X;

	for (int i = 2; i <= N; i++) {
		Previous = Init;
		Sum += Init.Result();
		std::cout << i - 1 << "-� ������� ����:" << Init.Result() << "\n";
		Init.Next(X, i);

		if ((abs(Init.Result() - Previous.Result()) <= Presition) || i == N) {
			Sum += Init.Result();
			std::cout 
				<< i 
				<< "-� ������� ����:" 
				<< Init.Result() 
				<< "\n����� ����: "
				<< Sum
				<< "\n����� ��������� ����: "
				<< i
				<< "\n";
			N = i;
			Init.Reset(X);
			Sum = 0;
			break;
		}
	}

	for (int i = 2; i <= N; i++) {
		if(!(i - 2))
			Sum += Init.Result();
		Previous = Init;
		Init.Next(X, i);
		Sum += Init.Result();
	}
	std::cout << "n-��� ����������� = " << Sum;
}