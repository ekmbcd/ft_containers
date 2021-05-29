#include "./tests.hpp"

template <typename T>
bool operator==(ft::Vector<T> & a, std::vector<T> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

static void default_constructor()
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	int test[] = {0, 1, 2, 3};
	ft::Vector<int> v1;
	std::vector<int> v2;
	check("default", v1 == v2);
	ft::Vector<int> l3((size_t)10);
	std::vector<int> l4((size_t)10);
	check("fill with default value", l3 == l4);
	ft::Vector<int> l5((size_t)10, 42);
	std::vector<int> l6((size_t)10, 42);
	check("fill", l5 == l6);
	ft::Vector<int> l7(test, test + 4);
	std::vector<int> l8(test, test + 4);
	check("range", l7 == l8);
	ft::Vector<int> l9(l7);
	std::vector<int> l10(l8);
	check("copy", l9 == l10);
}

static void copy_operator()
{
	std::cout << BLUE << "\n>Operator =" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft::Vector<int> v3;
	std::vector<int> v4;
	v3 = v1;
	v4 = v2;
	check("source", (v1 == v3));
	check("copy", (v2 == v4));
	v1.push_back(42);
	check("modified source", (v1 != v3));
}

static void push_pop()
{
	std::cout << BLUE << "\n>Push / Pop" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("push back", v1 == v2);
	v1.pop_back();
	v2.pop_back();
	check("pop back", (v1 == v2));
	v1.pop_back();
	v2.pop_back();
	v1.pop_back();
	v2.pop_back();
	check("pop empty", (v1 == v2));
}

static void max_size()
{
	std::cout << BLUE << "\n>Max size" << RESET << std::endl;
	ft::Vector<std::string> v1;
	std::vector<std::string> v2;
	check("string", v1.max_size() == v2.max_size());
	ft::Vector<int> v3;
	std::vector<int> v4;
	check("int", v3.max_size() == v4.max_size());
}

static void resize()
{
	std::cout << BLUE << "\n>Resize" << RESET << std::endl;
	ft::Vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(10, "test");
	v2.resize(10, "test");
	check("longer", (v1 == v2));
	v1.resize(2, "42");
	v2.resize(2, "42");
	check("shorter", (v1 == v2));
}

static void access_operator()
{
	std::cout << BLUE << "\n>Operator [], at()" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("test 1", v1[0] == v2[0]);
	check("test 2", v1[2] == v2[2]);
	try
	{
		std::cout << "over: " << v1.at(100) << " :" << FAIL << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::string(8, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "negative: "<< v1.at(-1) << ": " << FAIL  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::string(4, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
}

static void front_back()
{
	std::cout << BLUE << "\n>Front / Back" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("front", v1.front() == v2.front());
	check("back", v1.front() == v2.front());
}

static void assign()
{
	std::cout << BLUE << "\n>Assign" << RESET << std::endl;
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::Vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	check("range", v1 == v2);
	v1.assign(10, "?");
	v2.assign(10, "?");
	check("fill", v1 == v2);
}

static void insert()
{
	std::cout << BLUE << "\n>Insert" << RESET << std::endl;
	int test[] = {1, 2, 3};
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 42);
	v1.insert(v1.end(), 21);
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin() + 1, 11);
	v2.insert(v2.begin(), 42);
	v2.insert(v2.end(), 21);
	v2.insert(v2.begin(), 10);
	v2.insert(v2.begin() + 1, 11);
	check("single element", v1 == v2);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	check("fill", v1 == v2);
	v1.insert(v1.begin() + 1, test, test + 3);
	v2.insert(v2.begin() + 1, test, test + 3);
	check("range", v1 == v2);
}

static void erase()
{
	std::cout << BLUE << "\n>Erase / Clear" << RESET << std::endl;
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::Vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	check("erase", v1 == v2);
	v1.clear();
	v2.clear();
	check("clear", v1 == v2);
}

static void swap()
{
	std::cout << BLUE << "\n>Swap" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	ft::Vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(42);
	v3.push_back(43);
	v4.push_back(42);
	v4.push_back(43);
	v1.swap(v3);
	v2.swap(v4);
	check("first vector", v1 == v2);
	check("second vector", v3 == v4);
}

static void operators()
{
	std::cout << BLUE << "\n>Operators" << RESET << std::endl;
	ft::Vector<int> v1;
	std::vector<int> v2;
	ft::Vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3 = v1;
	v4 = v2;
	check("==", (v1 == v3) == (v2 == v4));
	check("!=", (v1 != v3) == (v2 != v4));
	check(">", (v1 > v3) == (v2 > v4));
	check("<", (v1 < v3) == (v2 < v4));
	check(">=", (v1 >= v3) == (v2 >= v4));
	check("<=", (v1 <= v3) == (v2 <= v4));
}

void	test_vector()
{
	std::cout << MAGENTA << BOLD << "\n------------- VECTOR ------------" << RESET << std::endl;

	default_constructor();
	copy_operator();
	push_pop();
	max_size();
	resize();
	access_operator();
	front_back();
	assign();
	insert();
	erase();
	swap();
	operators();
}