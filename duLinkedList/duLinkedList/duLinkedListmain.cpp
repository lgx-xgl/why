#include "duLinkedList.h"
int main()
{
	DuLinkedList L = NULL;
	DuLNode* Node;
	ElemType k, o;
	int p, JUDGE;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.����һ������" << endl
			<< "       2.����һ��elemtype(������)" << endl
			<< "       3.����һ��elemtype����ǰ���룩" << endl
			<< "       4.ɾ��һ��elemtype����ǰ�ģ�" << endl
			<< "       5.����һ�������������Ԫ�أ�" << endl
			<< "       6.ɾ��" << endl << endl;
		cin >> JUDGE;
		switch (JUDGE)
		{
		case(1):
			DestroyList_DuL(&L);
			InitList_DuL(&L);
			cout << "�����ɹ�";
			break;
		case(2):
			cout << endl << endl << "��������������k���Լ������λ��p(int)�����������λ�ò��� ��p=1 ����ڵ�һλ�ϣ�" << endl;
			cin >> k >> p;
			Node = new DuLNode;
			Node->data = k;
			if (InsertAfterList_DuL(InsertList_find_place(p, L), Node)) cout << "����ɹ�";
			else cout << "����ʧ��";
			break;
		case(3):
			cout << endl << endl << "��������������k���Լ������λ��p(int)�����������λ��֮ǰ���� ��p=2 ����ڵ�һλ�ϣ�" << endl;
			cin >> k >> p;
			Node = new DuLNode;
			Node->data = k;
			if (InsertBeforeList_DuL(InsertList_find_place(p, L), Node)) cout << "����ɹ�";
			else cout << "����ʧ��";
			break;
		case(4):
			cout << endl << endl << "����������ɾ��������k" << endl << endl;
			cin >> k;
			DeleteList_DuL(Deletelist_find_node(L, k), &o);						//o�������ж��Ƿ�ɾ����
			if (o == k) cout << "Success";
			else cout << "Error";
			break;
		case(5):
			cout << endl << endl << "�����ѡ�����һ������" << endl << endl;
			TraverseList_DuL(L, COUTLIST);
			break;
		case(6):
			DestroyList_DuL(&L);											
			L = NULL;															//��DestroyList_Dul��delete��L���ǻ��з���ռ䣬�����L��ʼ������ֹ����
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}