/*
 * Questions.cpp
 *
 *  Created on: Jan 19, 2018
 *      Author: ondra
 */

#include "Questions.h"
#include <iostream>

Questions::Questions() {
	// TODO Auto-generated constructor stub

}

Questions::~Questions() {
	// TODO Auto-generated destructor stub
}

/***********************************************************************************/
/* 1. Implement a template function IsDerivedFrom() that takes class C and class P as template parameters.
 * It should return true when class C is derived from class P and false otherwise.
 */

template<typename D, typename Derived>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };

    static Yes Test( Derived* );
    static No Test( ... );

public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

};


template <class C, class P>
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}

class Base {};

class Derived : public Base {};


/***********************************************************************************/

/*2. Implement a template boolean IsSameClass() that takes class A and B as template parameters.
 It should compare class A and B and return false when they are different classes and true if they are the same class.
*/

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};


template <class Base, class Derived>
bool IsSameClass() {
    return is_same<Base, Derived>::value;
}

/***********************************************************************************/
/* 3.What is the problem with the following code? */

class A
{
public:
A() {}
virtual ~A(){ std::cout << "destructor A" << std::endl; }
};

class B: public A
{
public:
B():A(){}
virtual ~B(){ std::cout << "destructor B" << std::endl;}
};

/***********************************************************************************/

/* 4 What will be the output of the following program?*/

struct X
{
    int data[2];

    X(int x, int y) : data{x, y} {}
    virtual void f() {}
};

/***********************************************************************************/
/* 5. virtual method
 *
 */


class Shape
{
public:
	double getArea() { return 0; }
	Shape() {}
	virtual ~Shape() {}
	virtual void draw() { std::cout << "Shape" << std::endl; }
};

class Triangle : public Shape
{
public:
	double getArea() { return 10; }
	Triangle() {}
	virtual ~Triangle() {}
	virtual void draw() {  std::cout << "Triangle" << std::endl; }
};

/***********************************************************************************/
/*6. Implement a void function F that takes pointers to two arrays of integers (A and B) and a size N as parameters.
  It then populates B where B[i] is the product of all A[j] where j != i.
  For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}.
  */

void F(int *A, int *B, int N)
{
	for (int i=0;i<N;++i)
	{
		int res = 1;
		for (int j=0;j<N;++j) {
			if (i !=j)
				res = res*A[j];
		}
		B[i] = res;
	}
}



/***********************************************************************************/
//7.
class BaseC {
    virtual void method() {std::cout << "from BaseC" << std::endl;}
public:
    virtual ~BaseC() {method();}
    void baseMethod() {method();}
};

class AC : public BaseC {
    void method() {std::cout << "from A" << std::endl;}
public:
    ~AC() {method();}
};


int main()
{
	// 1.
	std::cout << IsDerivedFrom<Base,Derived>() << std::endl;
	std::cout << IsDerivedFrom<Derived,Base>() << std::endl;

	// 2.
	std::cout << IsSameClass<Base,Base>()<< std::endl;
	std::cout << IsSameClass<Base,Derived>()<< std::endl;

	// 3.
	A* a = new B();
	delete a;

	// 4.
	X x(22, 33);

	int *arr = (int *) &x;
	std::cout << arr[0] << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << arr[2] << std::endl;

	//5

	Shape *s = new Triangle();
	std::cout << s->getArea() << std::endl;
	s->draw();

	//6
	int A[] = {2,1,5,9};
	int B[4];
	F(A,B,4);

	for (int i=0;i<4;++i) {
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;

	//7
	BaseC* base = new AC;
	base->baseMethod();
	delete base;

	return 0;
}

