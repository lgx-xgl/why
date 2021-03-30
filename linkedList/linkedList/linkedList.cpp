#include "linkedList.h"

Status InitList(LinkedList* L) 									//L��һ��ָ��ָ���ָ��
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
Status InsertList(LNode* p, LNode* q) 								//p�ǲ����ǰһ���ڵ㣬q��Ҫ����Ľڵ�
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
Status DeleteList(LNode* p, ElemType* e) 							//ɾ��p����һ���ڵ㣬������ڵ��ֵ��e
{
	if (p == NULL) return ERROR;
	*e = p->next->data;
	LinkedList p_next;
	p_next = p->next;
	p->next = p_next->next;
	delete(p_next);
	return SUCCESS;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))			//LΪͷָ�룬�������visit�������������ʲô
{
	LinkedList p;
	p = L->next;													//ͷָ��û�Ŷ���
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
Status SearchList(LinkedList L, ElemType e)					//��L����e
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
Status ReverseList(LinkedList* L)									//�ǵݹ鷴ת
{
	LinkedList p=(*L)->next;										
	LNode* u;														//u���м����
	ElemType o;														//o�����жϵ��������Ƿ�ɹ�
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
Status reverseList(LinkedList* L,LinkedList L_last)									//�ݹ鷴ת
{
	if (!L_last->next) {													//�ݵ�����ˣ���ʼ��
		(*L)->next = L_last;												//����ʼ��ָ����������
		return SUCCESS;
	}
	reverseList(L, L_last->next);
	if (L_last == *L) return SUCCESS;
	L_last->next->next = L_last;										//��һ��飺��һ����ԭ���Ԫ�ص�next=�����ڶ���
	L_last->next = NULL;
	return SUCCESS;
}
Status IsLoopList(LinkedList L)										//�ɻ�����success
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
LNode* ReverseEvenList(LinkedList* L)								//�����Ի�
{
	LinkedList p=(*L)->next,p_next=p->next,o;						//oΪ�м����
	if (!p->next->next) return (*L);								//ֻ��һ���������
	(*L)->next = p_next;
	int i=1;
	while (1)
	{
		if (p_next && p_next->next && !p_next->next->next)			//�������Ի�ʣ����һ����ʱ
		{
			p->next = p_next->next;
			p_next->next = p;
			return (*L);
		}
		if (p_next && !p_next->next) {								//�������Ի�ʣ����������ʱ
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