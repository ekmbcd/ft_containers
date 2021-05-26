#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <utility>

int main()
{
	std::map<int, std::string> m;

	m.insert(std::pair<int, std::string>(1, "ff"));
	m.insert(std::pair<int, std::string>(1, "ciao"));

	m.insert(std::pair<int, std::string>(2, "ciao"));
	m.insert(std::pair<int, std::string>(9, "ciao"));


// std::map<int, std::string>::iterator it = m.end();
// it--;
	for(std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

		std::cout << m.end()->first << " " << m.end()->second << std::endl;


}