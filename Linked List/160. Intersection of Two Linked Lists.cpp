#include<iostream>
using namespace std;

struct node {
	int val;
	node *next = NULL; //不设NULL则出现野指针
};

class MyLinkedList {
private:
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
		tail->next = NULL;
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

	node* getNode(int i)
	{
		if (i < 0)
		{
			return NULL;
		}
		node *p = head;
		int k = 0;
		while (p != NULL && k < i) //循环后自然找到第i个节点
		{
			p = p->next;
			k++;
		}
		return p;
	};

	int getSize()
	{
		return size;
	}

	void print()
	{
		node *p = head;
		while (p != NULL) 
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};

//得到两个链表的相交结点
//之后尝试将node*改为list&
node *getIntersectionNode(node *headA, node *headB)
{
	node *p1 = headA;
	node *p2 = headB;

	if (p1 == NULL || p2 == NULL) return NULL;

	while (p1 != NULL && p2 != NULL && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
		if (p1 == p2) return p1;
		if (p1 == NULL) p1 = headB;
		if (p2 == NULL) p2 = headA;
	}
	return p1;
}

int main()
{
	MyLinkedList linkedList_1;
	for (int i = 1; i <= 7; i++)
	{
		linkedList_1.addAtTail(i);
	}
	linkedList_1.print();


	node *headA = linkedList_1.getNode(0);
	cout << headA << endl;
	node *headB = linkedList_1.getNode(5);
	cout << headB << endl;

	node *p = getIntersectionNode(headA, headB);
	cout << p;
	return 0;
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