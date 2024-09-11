#include<iostream>

using namespace std;

template<typename T>
struct Node
{
	Node* next;
	T data;

	Node(T data): data(data), next(nullptr) {}
};
template<typename T>
class Stack {
private:
	Node<T>* head;
public:
	Stack();
	~Stack();
	void push_back(T data);
	void pop_back();
	void ist_empty() const;
	void print() const;
};


template<typename T>
Stack<T>::Stack() : head(nullptr){}


template<typename T>
Stack<T>::~Stack()
{
	Node<T>* temp = head;
	while (temp) {
		temp = temp->next;
		delete head;
		head = temp;
	}
}

template<typename T>
void Stack<T>::push_back(T data)
{
	Node<T>* temp = new Node<T>(data);
	temp->next = head;
	head = temp;
}

template<typename T>
void Stack<T>::pop_back()
{
	Node<T>* temp = head;
	temp = temp->next;
	delete head;
	head = temp;
}

template<typename T>
void Stack<T>::ist_empty() const
{
	if (head == nullptr)
		return true;
	else
		false;
}

template<typename T>
void Stack<T>::print() const
{
	Node<T>* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
	void main()
	{
		Stack<int> myStack;
		myStack.push_back(10);
		myStack.push_back(15);
		myStack.push_back(25);

		myStack.pop_back();

		//myStack.~Stack();
		myStack.print();

	}

