#include "tests.hpp"

void check(std::string name, bool good)
{
	std::string margin(32 - name.length(), ' ');
	if (good)
		std::cout << name << margin << GOOD << std::endl;
	else
		std::cout << name << margin << FAIL << std::endl;
};

int main()
{
	test_list();
	test_vector();
	test_map();
	test_stack();
	test_queue();
}