#include "linkedList.h"
int main()
{
	LinkedList L = NULL;
	LNode* Node;
	ElemType k,o;
	int p,JUDGE;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.����һ������" << endl
			<< "       2.����һ��elemtype" << endl
			<< "       3.����һ��elemtype" << endl
			<< "       4.ɾ��һ��elemtype����ǰ�ģ�" << endl
			<< "       5.����һ��������û����;��" << endl
			<< "       6.��תһ������ǰ��ת�ǵݹ飩" << endl
			<< "       7.��תһ������ǰ��ת�ݹ飩" << endl
			<< "       8.�鿴�����Ƿ�ɻ�" << endl
			<< "       9.����������" << endl
			<< "       10.���м���" << endl 
			<< "       11.ɾ��"<<endl<<endl;
		cin >> JUDGE;
		switch (JUDGE)
		{
		case(1):
			InitList(&L);
			cout << "�����ɹ�";
			break;
		case(2):
			cout <<endl<<endl<< "��������������k���Լ������λ��p(int)"<<endl;
			cin >> k >> p;
			Node = new LNode;
			Node->data = k;
			InsertList(InsertList_find_place(p, L), Node);
			break;
		case(3):
			cout << endl << endl << "�������������ص�k"<<endl;
			cin >> k;
			if (SearchList(L, k))cout << "Yes" << endl << endl;
			else cout << "NO" << endl << endl;
			break;
		case(4):
			cout << endl << endl << "����������ɾ��������k" << endl << endl;
			cin >> k;
			DeleteList(Deletelist_find_node(L, k), &o);						//o�������ж��Ƿ�ɾ����
			if (o == k) cout << "Success";
			else cout << "Error";
			break;
		case(5):
			cout << endl << endl << "�����ѡ�����һ������" << endl << endl;
			TraverseList(L, COUTLIST);
			break;
		case(6):
			if (ReverseList(&L)) cout << endl << endl << "��ת�ɹ�" << endl << endl;
			break;
		case(7):
			if (reverseList(&L,L)) cout << endl << endl << "��ת�ɹ�" << endl << endl;
			break;
		case(8):
			if (IsLoopList(L)) cout << endl << endl << "�������ǳɻ���" << endl << endl;
			else cout << endl << endl << "�������ɻ�" << endl << endl;
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