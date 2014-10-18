#include <iostream>


template <typename T>
class KQueue{

private:
	struct Node{
		Node * next;
		T data;
	};
	
	Node * head;
	Node * tail;
	size_t size;

public:
	KQueue(){
		size = 0;
	}
	~KQueue(){}

	void enqueue(T data){
		if ((int)size == 0){
			head = new Node;
			tail = head;
			head->data = data;
		}
		else{
			tail->next = new Node;
			tail = tail->next;
			tail->data = data;
		}
		++size;
	}
	
	T dequeue(){
		T data = head->data;
		Node * temp = head;
		if ((int)size != 0){
			head = head->next;
			--size;
		}
		else{
			delete head;
		}
		delete temp;
		return data;
	}

	bool isEmpty(){ size > 0 ? false : true;  }



};