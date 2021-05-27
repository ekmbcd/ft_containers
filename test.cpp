#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <utility>

int main()
{
	std::map<int, int> m;

	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(2,2));
	m.insert(std::pair<int, int>(3,3));
	m.insert(std::pair<int, int>(-1, -1));
	m.insert(std::pair<int, int>(-2, -2));
	m.insert(std::pair<int, int>(0,0));
	// m.insert(std::pair<int, std::string>(1, "ciao"));

	// m.insert(std::pair<int, std::string>(2, "ciao"));
	// m.insert(std::pair<int, std::string>(9, "ciao"));


// std::map<int, std::string>::iterator it = m.end();
// it--;
	for(std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	std::map<int, int>::iterator it = m.begin();
	std::cout << it->first << " " << it->second << std::endl;
	it = m.end();
	std::cout << it->first << " " << it->second << std::endl;

	//std::cout << m.end()->first << " " << m.end()->second << std::endl;


}