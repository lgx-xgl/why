#include "linkedList.h"

Status InitList(LinkedList* L) 									//L是一个指向指针的指针
{
	if (L == NULL) return ERROR;
	*L = new LNode;
	(*L)->next = NULL;
	return SUCCESS;
}
void DestroyList(LinkedList* L) 
{
	LinkedList L_next;
	while ( *L ) {
		L_next = (*L)->next;
		delete(*L);
		L = &L_next;
	}
	return;
}
LNode* InsertList_find_place(int num,LinkedList L)
{
	int t=1;
	LinkedList p = L;
	while (t != num&&p->next)
	{
		++t;
		p = p->next;
	}
	if (t==num) return p;
	else return NULL;
}
Status InsertList(LNode* p, LNode* q) 								//p是插入的前一个节点，q是要插入的节点
{
	if (p == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
LNode* Deletelist_find_node(LinkedList L, ElemType e)
{
	LinkedList p=L;
	while (p->next)
	{
		if (p->next->data == e) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
Status DeleteList(LNode* p, ElemType* e) 							//删掉p的下一个节点，把这个节点的值给e
{
	if (p == NULL) return ERROR;
	*e = p->next->data;
	LinkedList p_next;
	p_next = p->next;
	p->next = p_next->next;
	delete(p_next);
	return SUCCESS;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))			//L为头指针，你可以在visit这个函数里做点什么
{
	LinkedList p;
	p = L->next;													//头指针没放东西
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	return;
}
void COUTLIST(ElemType e)
{
	cout << e << " ";
	return;
}
Status SearchList(LinkedList L, ElemType e)					//在L里找e
{
	while (L->next)
	{
		L = L->next;
		if (e==L->data) 
		{
			return SUCCESS;
		}
	}
	return ERROR;
}
Status ReverseList(LinkedList* L)									//非递归反转
{
	LinkedList p=(*L)->next;										
	LNode* u;														//u是中间变量
	ElemType o;														//o用来判断单个调换是否成功
	while (p->next)
	{
		u = new LNode;
		u->data = p->next->data;
		DeleteList(p, &o);
		InsertList(*L, u);
		if (o == (*L)->next->data) cout << "success" << " ";
	}
	return SUCCESS;
}
Status reverseList(LinkedList* L,LinkedList L_last)									//递归反转
{
	if (!L_last->next) {													//递到最后了，开始归
		(*L)->next = L_last;												//将开始的指针连到最后的
		return SUCCESS;
	}
	reverseList(L, L_last->next);
	if (L_last == *L) return SUCCESS;
	L_last->next->next = L_last;										//第一层归：第一个（原最后）元素的next=倒数第二个
	L_last->next = NULL;
	return SUCCESS;
}
Status IsLoopList(LinkedList L)										//成环返回success
{
	LinkedList slow=L, fast=L;
	while (fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) return SUCCESS;
	}
	return ERROR;
}
LNode* ReverseEvenList(LinkedList* L)								//两两对换
{
	LinkedList p=(*L)->next,p_next=p->next,o;						//o为中间变量
	if (!p->next->next) return (*L);								//只有一个数的情况
	(*L)->next = p_next;
	int i=1;
	while (1)
	{
		if (p_next && p_next->next && !p_next->next->next)			//当两两对换剩下了一个数时
		{
			p->next = p_next->next;
			p_next->next = p;
			return (*L);
		}
		if (p_next && !p_next->next) {								//当两两对换剩下了两个数时
			p_next->next = p;
			p->next = NULL;
			return (*L);
		}
		p->next = p_next->next->next;
		o = p;
		p = p_next->next;
		p_next->next = o;
		if (!p||!p->next||!p_next->next) return (*L);
		p_next = p->next;
	}
	return (*L);
}
LNode* FindMidNode(LinkedList* L)
{
	LinkedList slow = (*L)->next, fast = (*L)->next;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}