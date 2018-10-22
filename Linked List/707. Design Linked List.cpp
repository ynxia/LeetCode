#include<iostream>
using namespace std;

class MyLinkedList {
private:
	struct node {
		int val;
		node *next;
	};
	node *head; //头结点
	node *tail; //尾结点
	int size;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= size || index < 0) return -1;
		node *cur = new node;
		cur = head;
		for (int i = 0;i < index; ++i) {
			cur = cur->next;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		node *temp = new node;
		temp->val = val;
		temp->next = head;
		head = temp;
		if (size == 0) tail = temp;
		++size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		node *temp = new node;
		temp->val = val;
		if (size == 0) {
			tail = temp;
			head = temp;
		}
		tail->next = temp;
		tail = temp;
		++size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index>size || index < 0) return;
		else if (index == 0) {
			addAtHead(val);
			return;
		}
		else if (index == size) {
			addAtTail(val);
			return;
		}
		node *cur = new node;
		cur = head;
		for (int i = 0; i < index - 1; ++i) {
			cur = cur->next;
		}
		node *temp = new node;
		temp->val = val;
		temp->next = cur->next;
		cur->next = temp;
		++size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= size || index < 0) return;
		else if (index == 0) {
			head = head->next;
			--size;
			return;
		}
		node *cur = new node;
		cur = head;
		for (int i = 0; i<index - 1; ++i) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		if (index == size - 1) tail = cur;
		--size;
	}

	void print()
	{
		node *p = head;
		while (p != NULL) {
			cout << p->val << endl;
			p = p->next;
		}
	}
};

int main()
{
	MyLinkedList linkedList;
	linkedList.addAtHead(1);
	//linkedList.print();

	linkedList.addAtTail(3);
	//linkedList.print();

	linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
	//linkedList.print();

	linkedList.get(1);            //返回2
	linkedList.deleteAtIndex(1);  //现在链表是1-> 3
	linkedList.get(1);            //返回3
}


/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAthead_(val);
* obj.addAttail_(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/