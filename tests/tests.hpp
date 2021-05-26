#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>
# include "../include/Vector.hpp"
# include "../include/List.hpp"
// # include "../include/Map.hpp"
// # include "../include/Queue.hpp"
// # include "../include/Stack.hpp"

#define RESET "\e[0m"
#define GREEN "\e[92m"
#define BLUE "\e[94m"
#define MAGENTA "\e[35m"
#define BOLD "\e[1m"

#define GOOD "✅"
#define FAIL "❌"

void	test_vector();
void	test_list();
void	test_map();
void	test_stack();
void	test_queue();

// inline void print_header(std::string str)
// {
// 	int margin = (40 - str.length()) / 2;
// 	int width = (margin * 2 + str.length()) + 2;
// 	std::cout << BLUE << std::endl;
// 	std::cout << std::string(width, '*') << std::endl;
// 	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
// 	std::cout << std::string(width, '*') << std::endl;
// 	std::cout << RESET;
// };

// template <typename T>
// inline void check(std::string name, T a, T b)
// {
// 	std::string margin(38 - name.length(), ' ');
// 	if (a == b)
// 		std::cout << name << ": " << margin << GOOD << std::endl;
// 	else
// 		std::cout << name << ": " << margin << FAIL << std::endl;
// };

inline void check(std::string name, bool good)
{
	std::string margin(30 - name.length(), ' ');
	if (good)
		std::cout << name << margin << GOOD << std::endl;
	else
		std::cout << name << margin << FAIL << std::endl;
};

// template <typename T, typename S>
// inline bool operator==(ft::Map<T, S> &a, std::map<T, S> &b)
// {
// 	if (a.size() != b.size())
// 		return (false);
// 	if (a.empty() != b.empty())
// 		return (false);
// 	typename ft::Map<T, S>::iterator it = a.begin();
// 	typename std::map<T, S>::iterator it2 = b.begin();
// 	while (it != a.end())
// 	{
// 		if (it->first != it2->first || it->second != it2->second)
// 			return (false);
// 		++it;
// 		++it2;
// 	}
// 	return (true);
// };

#endif