#include "linkedList.h"
int main()
{
	LinkedList L = NULL;
	LNode* Node;
	ElemType k,o;
	int p,JUDGE;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.制作一个链表" << endl
			<< "       2.插入一个elemtype" << endl
			<< "       3.搜素一个elemtype" << endl
			<< "       4.删掉一个elemtype（靠前的）" << endl
			<< "       5.遍历一次链表（还没有用途）" << endl
			<< "       6.反转一个链表（前后反转非递归）" << endl
			<< "       7.反转一个链表（前后反转递归）" << endl
			<< "       8.查看链表是否成环" << endl
			<< "       9.两两个调换" << endl
			<< "       10.找中间数" << endl 
			<< "       11.删表"<<endl<<endl;
		cin >> JUDGE;
		switch (JUDGE)
		{
		case(1):
			InitList(&L);
			cout << "创立成功";
			break;
		case(2):
			cout <<endl<<endl<< "请输入你想插入的k，以及插入的位置p(int)"<<endl;
			cin >> k >> p;
			Node = new LNode;
			Node->data = k;
			InsertList(InsertList_find_place(p, L), Node);
			break;
		case(3):
			cout << endl << endl << "请输入你想搜素的k"<<endl;
			cin >> k;
			if (SearchList(L, k))cout << "Yes" << endl << endl;
			else cout << "NO" << endl << endl;
			break;
		case(4):
			cout << endl << endl << "请输入你想删除的内容k" << endl << endl;
			cin >> k;
			DeleteList(Deletelist_find_node(L, k), &o);						//o是用来判断是否删对了
			if (o == k) cout << "Success";
			else cout << "Error";
			break;
		case(5):
			cout << endl << endl << "你可以选择遍历一次链表" << endl << endl;
			TraverseList(L, COUTLIST);
			break;
		case(6):
			if (ReverseList(&L)) cout << endl << endl << "反转成功" << endl << endl;
			break;
		case(7):
			if (reverseList(&L,L)) cout << endl << endl << "反转成功" << endl << endl;
			break;
		case(8):
			if (IsLoopList(L)) cout << endl << endl << "此链表是成环的" << endl << endl;
			else cout << endl << endl << "此链表不成环" << endl << endl;
			break;
		case(9):
			ReverseEvenList(&L);
			TraverseList(L, COUTLIST);
			break;
		case(10):
			cout<<FindMidNode(&L)->data;
			break;
		case(11):
			DestroyList(&L);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	/*InitList(&L);
	DestroyList(&L);
	InitList(&L);
	LNode* E;
	int n = 100;
	for (int i = 1; i <= n; ++i) {
		E = new LNode;
		E->data = i;
		InsertList(L, E);
	}
	if (SearchList(L, 110)) cout << "Yes"; else cout << "No";*/
	return 0;
}