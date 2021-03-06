//leetcode上的链表均没有头结点
#include<iostream>
using namespace std;

struct node {
	int val;
	node *next = NULL; //不设NULL则出现野指针
};

class MyLinkedList {
private:
	node * head; //头指针
	node *tail; //尾指针
	int size;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	MyLinkedList(MyLinkedList& L)
	{
		int value;
		node *p = L.getNode(0);
		tail = head = new node;
		if (size == 0)
		{
			head->val = p->val;
			//head = p;
			size++;
		}
		while (p->next != NULL)
		{
			value = p->next->val;
			tail->next = new node;
			tail->next->val = value;
			p = p->next;
			tail = tail->next;
			size++;
		}
		tail->next = NULL;
	};


	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= size || index < 0) return -1;
		node *cur = new node;
		cur = head;
		for (int i = 0; i < index; ++i) {
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
		tail = tail->next;
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
		while (p != NULL && k < i) //循环后自然找到第i个结点
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

	void Reverse()
	{
		node *p = NULL, *q = head;
		while (q != NULL) {
			head = q->next;  //  保留下一个结点；
			q->next = p;
			p = q;
			q = head;        //  移动到下一个结点；
		}
		head = p;            //  指向逆置后的头结点；
	}

};
bool isPalindrome(node* head) {
	MyLinkedList linkedList_11;
	while (head != NULL)
	{
		linkedList_11.addAtTail(head->val);
		head = head->next;
	}
	MyLinkedList linkedList_22(linkedList_11);
	linkedList_22.Reverse(); //翻转函数
	int s = linkedList_11.getSize() / 2; //链表的半长
	for (int i = 0; i < s; i++)
	{
		if (linkedList_11.getNode(i)->val != linkedList_22.getNode(i)->val)
		{
			return false;
		}
	}
	return true;
}

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
//因为是单链表，只要丢弃掉相应的结点即可
node* removeElements(node* head, int val) {
	while (head != NULL && head->val == val)
	{
		head = head->next;
	}
	if (head == nullptr)    return nullptr;

	node *p = head->next;
	node *prev = head;
	while (p != NULL) {
		if (p->val == val) {
			prev->next = p->next;
			p = p->next;
		}
		else {
			prev = p;
			p = p->next;
		}
	}
	return head;
}

bool hasCycle(node *head)
{
	node *fast = head; //快指针
	node *slow = head; //慢指针
	while (fast != NULL && slow != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}

node* deleteDuplicates(node *head)
{
	node *cur = head;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->val == cur->next->val)
		{
			cur->next = cur->next->next;
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}

node* mergeTwoLists(node* l1, node* l2) 
{
	node *l3 = new node, *head;
	head = l3;
	if (l1 == NULL && l2 == NULL)return NULL;
	if (l1 == NULL || l2 == NULL)return l1 == NULL ? l2 : l1;
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			l3->next = l1;
			l1 = l1->next;
			l3 = l3->next;
		}
		else {
			l3->next = l2;
			l2 = l2->next;
			l3 = l3->next;
		}
	}
	if (l1 != NULL)
	{//just point to the left nodes if there have.
		l3->next = l1;
	}
	if (l2 != NULL)
	{
		l3->next = l2;
	}
	return head->next;
}

//将p的下一个结点复制到p，然后删除p的下一个结点
void deleteNode(node* p) 
{
	if (p == NULL) return;
	node *tmp = p->next;
	p->val = tmp->val;
	p->next = tmp->next;
	delete tmp;
}

node* reverseList(node* head)
{
	node *temp = NULL, *nextNode = NULL;
	while (head) 
	{
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp;
}

node* middleNode(node* head)
{
	node *slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main()
{
	MyLinkedList linkedList_1;
	for (int i = 1; i <= 7; i++)
	{
		linkedList_1.addAtTail(i);
	}
	linkedList_1.print();
	node *p = middleNode(linkedList_1.getNode(0));
	cout << p->val <<endl;
	return 0;
}