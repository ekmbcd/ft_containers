#include "tests.hpp"

template <typename T>
bool operator==(ft::Queue<T> & a, std::queue<T> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	ft::Queue<T> a2(a);
	std::queue<T> b2(b);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a2.front() != b2.front())
			return (false);
		a2.pop();
		b2.pop();
	}
	return (true);
};

static void constructors(void)
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	ft::Queue<int> q1;
	std::queue<int> q2;
	check("default", q1 == q2);
	q1.push(42);
	q1.push(24);
	q2.push(42);
	q2.push(24);
	ft::Queue<int> q3(q1);
	std::queue<int> q4(q2);
	check("copy", q1 == q2);
}

static void empty_size()
{
	std::cout << BLUE << "\n>Empty / Size" << RESET << std::endl;
	ft::Queue<int> q1;
	std::queue<int> q2;
	check("empty", q1.empty() == q2.empty());
	check("size 0", q1.size() == q2.size());
	q1.push(42);
	q1.push(42);
	q1.push(24);
	q2.push(42);
	q2.push(42);
	q2.push(24);
	check("size n", q1.size() == q2.size());
}

static void push_pop()
{
	std::cout << BLUE << "\n>Push / Pop" << RESET << std::endl;
	ft::Queue<int> q1;
	std::queue<int> q2;
	q1.push(42);
	q1.push(42);
	q1.push(24);
	q2.push(42);
	q2.push(42);
	q2.push(24);
	check("push", q1 == q2);
	q1.pop();
	q1.pop();
	q2.pop();
	q2.pop();
	check("pop", q1 == q2);
}

static void front_back(void)
{
	std::cout << BLUE << "\n>Front / Back" << RESET << std::endl;
	ft::Queue<std::string> q1;
	std::queue<std::string> q2;
	q1.push("hey");
	q1.push("what's");
	q1.push("up");
	q2.push("hey");
	q2.push("what's");
	q2.push("up");
	check("front", q1.front() == q2.front());
	check("back", q1.back() == q2.back());
}

static void operators()
{
	std::cout << BLUE << "\n>Operators" << RESET << std::endl;
	ft::Queue<int> v1;
	std::queue<int> v2;
	ft::Queue<int> v3;
	std::queue<int> v4;
	v1.push(1);
	v1.push(2);
	v1.push(3);
	v2.push(1);
	v2.push(2);
	v2.push(3);
	v3 = v1;
	v4 = v2;
	check("==", (v1 == v3) == (v2 == v4));
	check("!=", (v1 != v3) == (v2 != v4));
	check(">", (v1 > v3) == (v2 > v4));
	check("<", (v1 < v3) == (v2 < v4));
	check(">=", (v1 >= v3) == (v2 >= v4));
	check("<=", (v1 <= v3) == (v2 <= v4));
}

void test_queue(void)
{
	std::cout << MAGENTA << BOLD << "\n---------- QUEUE ----------" << RESET << std::endl;
	constructors();
	push_pop();
	empty_size();
	front_back();
	operators();
}