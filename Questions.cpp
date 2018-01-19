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
/*Implement a template function IsDerivedFrom() that takes class C and class P as template parameters.
 * It should return true when class C is derived from class P and false otherwise.
 */

template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };

    static Yes Test( B* );
    static No Test( ... );

public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

};


template <class C, class P>
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}

class A {};

class B : public A {};


/***********************************************************************************/

/*Implement a template boolean IsSameClass() that takes class A and B as template parameters.
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


template <class A, class B>
bool IsSameClass() {
    return is_same<A, B>::value;
}


int main()
{

	std::cout << IsDerivedFrom<A,B>() << std::endl;
	std::cout << IsDerivedFrom<B,A>() << std::endl;

	std::cout << IsSameClass<A,A>()<< std::endl;
	std::cout << IsSameClass<A,B>()<< std::endl;



	return 0;
}

