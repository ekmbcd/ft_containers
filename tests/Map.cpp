#include "tests.hpp"
#include <map>

template <typename T, typename S>
inline bool operator==(ft::Map<T, S> & a, std::map<T, S> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::Map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

static void constructors(void)
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::Map<int, int> m1;
	std::map<int, int> m2;
	check("default", (m1 == m2));
	ft::Map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	check("range", (m3 == m4));
	ft::Map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	check("copy", (m5 == m6));
}

static void copy_operator()
{
	std::cout << BLUE << "\n>Operator =" << RESET << std::endl;
	ft::Map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	ft::Map<int, int> m1;
	std::map<int, int> m2;
	m1 = m7;
	m2 = m8;
	check("source", (m7 == m8));
	check("copy", (m1 == m2));
	m1[3] = 1;
	check("modified source", (m7 == m8));
}

static void max_size(void)
{
	std::cout << BLUE << "\n>Max size" << RESET << std::endl;
	ft::Map<int, int> m1;
	std::map<int, int> m2;
	check("int, int", m1.max_size() == m2.max_size());
	ft::Map<std::string, int> m3;
	std::map<std::string, int> m4;
	check("string, int", m3.max_size() == m4.max_size());
}

static void empty_size()
{
	std::cout << BLUE << "\n>Empty / Size" << RESET << std::endl;
	ft::Map<int, int> m7;
	std::map<int, int> m8;
	check("empty (true)", m7.empty() == m8.empty());
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	check("empty (false)", m7.empty() == m8.empty());
	check("size", m7.size() == m8.size());


}

static void access_operator(void)
{
	std::cout << BLUE << "\n>Operator []" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	check("get", m1["c"] == m2["c"]);
	check("assign", m1 == m2);
	check("double assign", m1["d"] == m2["d"]);
}

static void insert(void)
{
	std::cout << BLUE << "\n>Insert" << RESET << std::endl;
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::Map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(std::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(std::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));
	check("single element", m1 == m2);
	m1.insert(++m1.begin(), std::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	check("range", m1 == m2);
	m1.insert(--m1.end(), std::make_pair(12, 0));
	m2.insert(--m2.end(), std::make_pair(12, 0));
	check("hint", m1 == m2);
}

static void erase(void)
{
	std::cout << BLUE << "\n>Erase" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;
	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;
	m1.erase(++m1.begin());
	m2.erase(++m2.begin());
	check("iterator", m1 == m2);
	m1.erase("a");
	m2.erase("a");
	check("key", m1 == m2);
	m1.erase(++m1.begin(), --m1.end());
	m2.erase(++m2.begin(), --m2.end());
	check("range", m1 == m2);
}

static void swap(void)
{
	std::cout << BLUE << "\n>swap" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::Map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	check("first map", m1 == m2);
	check("second map", m3 == m4);
}

static void clear(void)
{
	std::cout << BLUE << "\n>Clear" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	check("clear", m1 == m2);
}

static void find(void)
{
	std::cout << BLUE << "\n>Find" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	check("success", m1.find("b")->second == m2.find("b")->second);
	check("fail", m1.find("d") == m1.end());
}

static void count(void)
{
	std::cout << BLUE << "\n>Count" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	check("success", m1.count("a") == m2.count("a"));
	check("fail", m1.count("z") == m2.count("z"));
}

static void bounds()
{
	std::cout << BLUE << "\n>Bounds" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	std::string one;
	std::string two;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	check("lower", m1.lower_bound("c")->first == m2.lower_bound("c")->first);
	check("upper", m1.upper_bound("a")->first == m2.upper_bound("a")->first);
}

static void range(void)
{
	std::cout << BLUE << "\n>Equal Range" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	std::pair<ft::Map<std::string, int>::iterator, ft::Map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	check("first", a.first->first == b.first->first);
	check("second", a.second->first == b.second->first);
}

static void operators_comp(void)
{
	std::cout << BLUE << "\n>Operators" << RESET << std::endl;
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::Map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	check("==", (m1 == m3) == (m2 == m4));
	check("!=", (m1 != m3) == (m2 != m4));
	check(">", (m1 > m3) == (m2 > m4));
	check("<", (m1 < m3) == (m2 < m4));
	check(">=", (m1 >= m3) == (m2 >= m4));
	check("<=", (m1 <= m3) == (m2 <= m4));
}

void test_map(void)
{
	std::cout << MAGENTA << BOLD << "\n-------------- MAP --------------" << RESET << std::endl;
	constructors();
	copy_operator();
	empty_size();
	max_size();
	access_operator();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	range();
	operators_comp();
}