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
# include "../include/Map.hpp"
# include "../include/Queue.hpp"
# include "../include/Stack.hpp"

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

void check(std::string name, bool good);

#endif