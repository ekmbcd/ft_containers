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

	std::list<int>::iterator st = a.begin();
	std::list<int>::iterator en = a.end();

	
	std::list<int> d(10, 10);
	std::list<int> e(3, 3);

	e = d;
	std::list<int>::iterator i = e.begin();
	while (i != e.end())
	{
		std::cout << *i << " ";
		++i;
	}
	std::list<int>::const_iterator z = a.begin();



	std::cout << *z << std::endl;	
	++z;
	std::cout << *z << std::endl;

}