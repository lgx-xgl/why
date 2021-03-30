#include "duLinkedList.h"
int main()
{
	DuLinkedList L = NULL;
	DuLNode* Node;
	ElemType k, o;
	int p, JUDGE;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.制作一个链表" << endl
			<< "       2.插入一个elemtype(向后插入)" << endl
			<< "       3.插入一个elemtype（向前插入）" << endl
			<< "       4.删掉一个elemtype（靠前的）" << endl
			<< "       5.遍历一次链表（输出链表元素）" << endl
			<< "       6.删表" << endl << endl;
		cin >> JUDGE;
		switch (JUDGE)
		{
		case(1):
			DestroyList_DuL(&L);
			InitList_DuL(&L);
			cout << "创立成功";
			break;
		case(2):
			cout << endl << endl << "请输入你想插入的k，以及插入的位置p(int)（在你输入的位置插入 如p=1 则放在第一位上）" << endl;
			cin >> k >> p;
			Node = new DuLNode;
			Node->data = k;
			if (InsertAfterList_DuL(InsertList_find_place(p, L), Node)) cout << "插入成功";
			else cout << "插入失败";
			break;
		case(3):
			cout << endl << endl << "请输入你想插入的k，以及插入的位置p(int)（在你输入的位置之前插入 如p=2 则放在第一位上）" << endl;
			cin >> k >> p;
			Node = new DuLNode;
			Node->data = k;
			if (InsertBeforeList_DuL(InsertList_find_place(p, L), Node)) cout << "插入成功";
			else cout << "插入失败";
			break;
		case(4):
			cout << endl << endl << "请输入你想删除的内容k" << endl << endl;
			cin >> k;
			DeleteList_DuL(Deletelist_find_node(L, k), &o);						//o是用来判断是否删对了
			if (o == k) cout << "Success";
			else cout << "Error";
			break;
		case(5):
			cout << endl << endl << "你可以选择遍历一次链表" << endl << endl;
			TraverseList_DuL(L, COUTLIST);
			break;
		case(6):
			DestroyList_DuL(&L);											
			L = NULL;															//在DestroyList_Dul中delete后，L还是会有分配空间，这里把L初始化，防止出错
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}