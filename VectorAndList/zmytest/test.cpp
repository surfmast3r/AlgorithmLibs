#include <iostream>

#include "../vector/vector.hpp"
/* ************************************************************************** */

using namespace std;


void createRandomVector(){
	std::cout<< "new vector";
	lasd::Vector<long> vec(3);
	vec[0]=13;
	cout<<vec[0];
};
