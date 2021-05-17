#include <iostream>
#include <list>

int main()
{
	std::list<int> a;
	std::cout << "SIZE = " << a.size() << std::endl;
	a.push_front(1);
	std::cout << "SIZE = " << a.size() << std::endl;
	a.push_front(2);
	a.push_front(3);
	a.push_front(4);


	std::cout << "SIZE = " << a.size() << std::endl;
	//std::list<int>::iterator i = ;
	std::cout << "start: " << *(a.begin()) << std::endl;
	//std::list<int>::iterator c = ;
	std::cout <<  "end: " << *(a.end()) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

}