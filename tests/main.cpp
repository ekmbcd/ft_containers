#include "tests.hpp"

void check(std::string name, bool good)
{
	std::string margin(30 - name.length(), ' ');
	if (good)
		std::cout << name << margin << GOOD << std::endl;
	else
		std::cout << name << margin << FAIL << std::endl;
};

int main()
{
	// test_map();
	ft::Map<int, int> m;
	std::cout << m.size() << std::endl;

	m.insert(std::make_pair(0, 1));
	m.insert(std::make_pair(-5, 0));
	m.insert(std::make_pair(1, 4));
	m.insert(std::make_pair(8, 0));
	m.insert(std::make_pair(9, 0));

	ft::MapIterator<int, int> it = m.begin();

	while (it != m.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}
	


	// std::cout << m.size() << std::endl;
	// std::cout << "m[0] " << m[0] << std::endl;
	// m[0] = 43;
	
	// std::cout <<"m[0] " <<  m[0] << std::endl;
	// m[6] = 6;
	// std::cout <<"m[6] " <<  m[6] << std::endl;
	// std::cout << m.size() << std::endl;
	// m.print();
	// m.erase(--m.end());
	// std::cout <<"now\n";
	// m.print();
	// std::cout << m.size() << std::endl;


	


}