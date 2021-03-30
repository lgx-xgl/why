#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
	(*L) = new DuLNode;
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList L_now = (*L);
	if ((*L) == NULL) return;
	while ((*L)->next)
	{
		(*L) = (*L)->next;
		delete(L_now);
		L_now = (*L);
	}
	delete (*L);
	return;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
DuLNode* InsertList_find_place(int num, DuLinkedList L)
{
	int t = 1;
	DuLinkedList p = L;
	while (t != num && p->next )
	{
		++t;
		p = p->next;
	}
	if (t == num) return p;
	else return NULL;
}
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (p == NULL|| q == NULL) return ERROR;
	p->prior->next = q;
	q->prior = p->prior;
	p->prior = q;
	q->next = p;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {							//q是要插入的
	if (p == NULL || q == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None0
 */
DuLNode* Deletelist_find_node(DuLinkedList L, ElemType e)
{
	DuLinkedList p = L;
	while (p->next)
	{
		if (p->next->data == e) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (p == NULL) return ERROR;
	(*e) = p->next->data;
	DuLinkedList o = p->next;
	p->next = p->next->next;
	o->next->prior = p;
	delete(o);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void COUTLIST(ElemType e)																		//输出遍历时的元素
{
	cout << e << " ";
	return;
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return;
}
