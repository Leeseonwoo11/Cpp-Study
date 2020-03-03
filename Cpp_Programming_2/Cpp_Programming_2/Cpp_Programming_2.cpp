// Cpp_Programming_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>

using namespace std;

//const 참조자가 사용되는 예 
int Myadder(const int &a, const int &b)
{
	return a + b;
}
//잘못된 참조형 반환 함수 (지역변수 참조형으로 리턴(스택에 저장된 변수))
int& plus1(int &a)
{
	int temp = 1;
	temp += a;
	return temp;
}
// 잘된 참조형 반환 함수 (동적할당한 변수 참조형으로 리턴 (힙에 저장된 변수))
int & plus2(int &a)
{
	int* temp = new int;
	*temp = 2;
	*temp += a;
	return *temp;
}
// 참조자를 이용한 스왑
void Myswap1(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 포인터를 이용한 스왑
void Myswap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//책 문제

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point* temp = new Point;
	temp->xpos = p1.xpos + p2.xpos;
	temp->ypos = p1.ypos + p2.ypos;
	return *temp;
}
int main()
{
//참조자의 이해
//참조자는 변수의 별명같은것
	int a = 10;
	int &a1 = a;
	cout << a << " " << a1 << endl; // a1이 a를 참조한다. a1이 a의 별명이 된것
// 참조자는 변수만 참조할 수 있다.
// 하지만 const 참조자는 상수를 참조할 수 있다.
	const int & kk = 10; //  오류 안남
	int num1 = 10;
	int num2 = 20;
	cout << Myadder(num1, num2) << " " << Myadder(20, 30)<<endl; //const 참조자로 매개변수 선언을 한 함수는 별도의 변수를 만들어서 접근할 필요가 없다.(물론 이 함수의 매개변수를 일반 변수로 만들면 기능은 똑같다.)

	//잘못된 참조형 반환함수 이용하기
	int num3 = 11;
	int &num4 = plus1(num3);  // 지역변수를 참조함
	cout << plus1(num3) <<"이렇게 잘 나오기도 함"<<endl; //  잘못된 참조자 반환함수 이용함 그러나 결과는 제대로 나옴;
	cout << num4 <<" 쓰레기값이 리턴됨"<<endl; // num4가 참조하고있던 지역변수 temp가 사라지면서 쓰레기값이 리턴되었다.

	// 정상적인 결과가 나오기도 하지만 plus1함수의 temp 변수는 함수가 끝나면서 사라지는 지역변수이다.
	// 그래서 참조자를 반환하려면 지역변수의 참조형이 아니라 동적할당을 통해서 만든 변수를 반환하는것이 맞다.

	int num5 = 11;
	int &num6 = plus2(num5); // 동적할당을 통해 만들어진 변수를 참조함.
	cout << num6 <<"  잘됨"<< endl; // 잘됨 ..
	delete &num6;// 함수내에서 동적할당으로 만든 변수를 참조형으로 리턴하였고 num6라는 이름으로 이 변수를 참조하고 있으니 다 사용하였다면 delete로 지워준다.
				//지워줄 때 num6로 참조하고 있으니 num6의 주소로 delete하면 된다.


	// 포인터를 사용하지 않아도 call by refrence 형태의 함수호출이 가능하다.
	int s1 = 11;
	int s2 = 22;
	Myswap1(s1, s2); // 참조자를 이용한 스왑
	cout << " s1 : "<< s1 <<" s2 : " <<s2 << endl;
	Myswap2(&s1, &s2); // 포인터(주소값)를 이용한 스왑
	cout << " s1 : " << s1 << " s2 : " << s2 << endl;
	//call by refrence 의 의미는 주소값을 전달받아서 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출이다.
	// 주소를 불러왔다라는것이 중요한것이 아니라 불러온 주소를 이용해 외부의 변수에 접근하여 그 변수를 이용해서 무언가 처리를 했다면 call by refrence 가 되는 것이다. 
	// 주소를 불러와서 불러온 주소를 더하거나 빼거나 지우고 한다면 그것은 call by value이다. 주소를 불러왔다고 call by refrence가 아니다. 

	// 책 문제 2-3
	//2차원 평면 구조체가 있고 구조체를 기반으로 
	// Point& PntAdder(const Point &p1, const Point &p2); 의 형태로 두 점의 합을 계산하는 함수를 완성해라
	//구조체 관련 변수의 선언은 new로 선언하며 할당된 메모리 공간의 소멸도 철저히 한다.
	Point* A = new Point;
	Point* B = new Point;
	A->xpos = 10;
	A->ypos = 20;
	B->xpos = 1;
	B->ypos = 1;
	Point &Result = PntAdder(*A, *B);
	cout << endl;
	cout << "Ax " << A->xpos <<" Ay "<<A->ypos<< endl;
	cout << "Bx " << B->xpos << " By " << B->ypos << endl;
	cout << "Rx " << Result.xpos << " Ry " << Result.ypos << endl;
	delete A, B;
	delete &Result; // 함수내에서 동적할당된 변수롤 참조자를 통해서 소멸 


}

