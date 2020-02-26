// Cpp_Programing_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

void myfunc()
{
	cout << "void func" << endl;
}
void myfunc(char c)
{
	cout << c << "charfunc" << endl;
}
void myfunc(int i, int j)
{
	cout << i+j << "intfunc" << endl;
}

void myswap(char *a, char *b)
{
	char k = *a;
	*a = *b;
	*b = k;
}
void myswap(int *a, int *b)
{
	int k = *a;
	*a = *b;
	*b = k;
}
void myswap(float *a, float *b)
{
	float k = *a;
	*a = *b;
	*b = k;
}
void myswap(double *a, double *b)
{
	double k = *a;
	*a = *b;
	*b = k;
}
//인라인함수
inline int SQUARE2(int x)
{
	return x * x;
}
namespace nk
{
	int a= 2;
}
namespace nj
{
	int a = 3;
}

int main()
{
	std::cout << "Hello World!\n"; 

	int a;
	cout << "int 형 숫자 입력 후 엔터 ";
	cin >> a;
	cout << a << "가 출력 됩니다." << endl;

	//-------------------------------------------------
	// 숫자 두개입력후 두 수의 사잇값들의 합.
	int num1, num2;
	int result = 0;
	cout << "두개의 정수입력" << endl;
	cin >> num1 >> num2;
	if (num1 > num2)
	{
		for (int i = num2; i <= num1; i++)
		{
			result += i;
		}
		cout << "두 수를 포함한 사이의 숫자의 합은 " << result << endl;

	}
	else if (num1 < num2)
	{
		for (int i = num1; i <= num2; i++)
		{
			result += i;
		}
		cout << "두 수를 포함한 사이의 숫자의 합은 " << result << endl;
	}
	else
	{
		cout << "두 수는 같아요" << endl;
	}
	//-------------------------------------------------
	//배열기반의 문자열 입출력
	char name[100];
	char lang[200];
	cout << "이름은 무었입니까" << endl;
	cin >> name;
	cout << "좋아하는 언어는 무었입니까" << endl;
	cin >> lang;

	cout << "제 이름은 " << name << "이고 " << lang << "을 사용합니다." << endl;
	//-------------------------------------------------
	//함수 오버로딩
	myfunc();
	myfunc('a');
	myfunc(1, 2);
	char aa = 'a';
	char bb = 'b';
	int aa2 = 1;
	int bb2 = 2;
	float aa3 = 1.1;
	float bb3 = 2.2;
	double aa4 = 1.11;
	double bb4 = 2.22;
	myswap(&aa, &bb);
	myswap(&aa2, &bb2);
	myswap(&aa3, &bb3);
	myswap(&aa4, &bb4);

	cout << aa << " " << bb << endl;
	cout << aa2 << " " << bb2 << endl;
	cout << aa3 << " " << bb3 << endl;
	cout << aa4 << " " << bb4 << endl;

	//-------------------------------------------------
	//매크로함수
#define SQUARE(x) ((x)*(x))
	cout <<"매크로함수 실행 "<< SQUARE(5.1) << endl;
	//-------------------------------------------------
	//인라인함수 실행
	cout << "인라인함수 실행 " << SQUARE2(2.2) << endl;

	cout <<"네임스페이스로 구분한 변수들 합 " <<nk::a + nj::a << endl;
}
