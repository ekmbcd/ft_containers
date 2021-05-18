namespace ft
{
	template<typename T>
	struct Node
	{
		T value;
		struct Node * next;
		struct Node * prev;
	};
} // namespace ft
