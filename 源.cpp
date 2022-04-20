#include<string.h>
#include<iostream>

using namespace std;

//ʱ��ṹ��
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

//��Ա��Ϣ�ṹ��
typedef struct Pers
{
	int n;
	char na[20];
	char sex;
	int age;
	char conta[12];
	Pers* next;
}Pers;

//������Ϣ�ṹ��
typedef struct Ing
{
	int no;
	char name[20];
	int price;
	int InNum;
	int Num;
	int OutNum;
	char keeper[20];
	Date intime;
	char info[50];
	Ing* next;
}Ing;

//������Ϣ�ṹ��
typedef struct Use
{
	int num;
	char user[20];
	int quan;
	Date date;
	Use* next;
}Use;

//��ʼ���˵�
void Menu()
{
	cout << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                          ��ӭʹ��С��ķɻ���Ƶ���������Ϲ���ϵͳ                          **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                                                                                              **" << endl;
	cout << "**                                          1. �����Ϣ                                         **" << endl;
	cout << "**                                          2. ��ʾ��Ϣ                                         **" << endl;
	cout << "**                                          3. ��ѯ��Ϣ                                         **" << endl;
	cout << "**                                          4. �޸���Ϣ                                         **" << endl;
	cout << "**                                          5. ��������                                         **" << endl;
	cout << "**                                                                                              **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                                     ����������ʹ�õĹ���                                     **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << endl ;
}

//�����Ϣ
void Input(Ing* headA, Use* headB, Pers* headC)
{
	Ing* p;
	Use* q;
	Pers* r;
	cout << "�����������Ϣ��" << endl;
	cout << "1. ������Ϣ" << " " << "2. ������Ϣ" << " " << "3. ��������Ϣ" << endl;
	int a,b;
	cin >> a;
	switch (a)
	{
	case 1://��Ӳ�����Ϣ
		while (headA->next != NULL) headA = headA->next;
		cout << "�����������Ϣ������" << endl;
		cin >> b;
		for (int i=0;i<b;i++)
		{
			p = new Ing;
			cout << "�����뵱ǰ���ϱ�ţ�" << endl;
			cin >> p->no;
			cout << "�����뵱ǰ�������ƣ�" << endl;
			cin >> p->name;
			cout << "�����뵱ǰ���ϼ۸�" << endl;
			cin >> p->price;
			cout << "���������������" << endl;
			cin >> p->InNum;
			cout << "���������������" << endl;
			cin >> p->OutNum;
			p->Num = p->InNum - p->OutNum;
			cout << "���������Ա����:" << endl;
			cin >> p->keeper;
			cout << "���������ʱ�䣺" << endl;
			cin >> p->intime.year >> p->intime.month >> p->intime.day;
			cout << "��ע��������20�֣���" << endl;
			cin >> p->info;
			headA->next = p;
			p->next = NULL;
			headA = p;
		}
		break;
	case 2://���������Ϣ
		while (headB->next != NULL) headB = headB->next;
		cout << "�����������Ϣ������" << endl;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			q = new Use;
			cout << "���������ò��ϱ�ţ�" << endl;
			cin >> q->num;
			for (;headA != NULL;)
			{
				if (headA->no == q->num)
				{
					cout << "�ɹ���������Ӧ��Ϣ��" << endl;
					break;
				}
				else if (headA->no != q->num && headA->next == NULL)
				{
					cout << "δ��������Ӧ��Ϣ������Ŀ¼��" << endl;
					return;
				}
				headA = headA->next;
			}
			cout << "������������������" << endl;
			cin >> q->user;
			cout << "����������������" << endl;
			cin >> q->quan;
			for (; headA != NULL;)
			{
				if (q->num == headA->no)
				{
					if (q->quan <= headA->Num)
					{
						int count = headA->Num;
						headA->Num = count - q->quan;
						headA->OutNum += q->quan;
						break;
					}
					else
					{
						cout << "�������������" << endl;
						return;
					}
				}
				headA = headA->next;
			}
			cout << "��������������" << endl;
			cin >> q->date.year >> q->date.month >> q->date.day;
			headB->next = q;
			q->next = NULL;
			headB = q;
		}
		break;
	case 3://�����������Ϣ
		while (headC->next != NULL) headC = headC->next;
		cout << "�����������Ϣ������" << endl;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			r = new Pers;
			cout << "�����������˱�ţ�" << endl;
			cin >> r->n;
			cout << "������������������" << endl;
			cin >> r->na;
			cout << "�������������Ա�" << endl;
			cin >> r->sex;
			cout << "���������������䣺" << endl;
			cin >> r->age;
			cout << "��������������ϵ��ʽ��" << endl;
			cin >> r->conta;
			headC->next = r;
			r->next = NULL;
			headC = r;
		}
		break;
	}
	cout << "����Ŀ¼��" << endl<<endl;
}

//��ʾ�Ѵ���Ϣ
void Show(Ing* head1, Use* head2,Pers* head3)
{
	int a;
	cout << "��������Ҫ��ʾ�����ݱ�ţ�" << endl;
	cout << "1. ���ϱ�" << " " << "2. �������ñ�" << " " << "3. ��������Ϣ��" << endl;
	cin >> a;
	switch (a) 
	{
	case 1://��ʾ���ϱ���Ϣ
		for (int i=1; head1->next != NULL;i++)
	    {
		    head1 = head1->next;
		    cout << "����" << i << ":" << endl;
		    cout << "��ţ�" << head1->no << " " << "���ƣ�" << head1->name << " " << "���ۣ�" << head1->price << endl;
		    cout << "���������" << head1->InNum << " " << "����������" << head1->OutNum << " " << "��棺" << head1->Num << endl;
		    cout << "����Ա��" << head1->keeper << endl;
		    cout << "���ʱ�䣺" << head1->intime.year << "." << head1->intime.month << "." << head1->intime.day << endl;
		    cout << "��ע��" << head1->info << endl;
	    }
		  break; 
	case 2://��ʾ����������Ϣ
		for (int i = 1; head2->next != NULL; i++)
		{
			head2 = head2->next;
			cout << "���ü�¼" << i << ":" << endl;
			cout << "���ϱ�ţ�" << head2->num << " " << "�����ˣ�" << head2->user << " " << "����������" << head2->quan << endl;
			cout << "����ʱ�䣺" << head2->date.year << "." << head2->date.month << "." << head2->date.day << endl;
		}
		break;
	case 3://��ʾ��������Ϣ
		for (int i = 1; head3->next != NULL; i++)
		{
			head3 = head3->next;
			cout << "������" << i << ":" << endl;
			cout << "��ţ�" << head3->n << " " << "������" << head3->na << " " << "�Ա�" << head3->sex << " " << "���䣺" << head3->age << " " << "��ϵ��ʽ��" << head3->conta << endl;
		}
		break;
	default:
		cout << "���뷶ΧΪ1-3�����������룡"<<endl<<endl;
		break;
	}
	cout << "����Ŀ¼��"<<endl<<endl;
}

//��ѯ
void Search(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	int a;
	cout << "�������ѯ���ݣ�" << endl;
	cout << "1. ���ϱ�" << "  " << "2. ���ü�¼" << " " << "3. ��������Ϣ" << endl;
	cin >> a;
	switch (a)
	{
	case 1://���ϲ�ѯ
		cout << "��������Ϣ��" << endl;
		cout << "1. ���ϱ��" << " " << "2. ������" << " " << "3. ������" << " " << "4. ����ʱ��" << endl;
		int l;
		cin >> l;
		if (l == 1)//��֪���
		{
			int n;
			cin >> n;
			for (; headA != NULL;)
			{
				if (headA->no == n)
				{
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else
					headA = headA->next;
			}
		}
		else if (l == 2)//��֪������
		{
			char na[20];
			cin >> na;
			for (; headA != NULL;)
			{
				if (strcmp(headA->name, na) == 0)
				{
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else
					headA = headA->next;
			}
		}
		else if (l == 3)//��֪������
		{
			char stuff[20];
			cin >> stuff;
			for (; headA != NULL;)
			{
				if (strcmp(headA->keeper, stuff) == 0)
				{
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
				}
				headA = headA->next;
			}
		}
		else if (l == 4)//��֪����ʱ��
		{
			Date time;
			cin >> time.year >> time.month >> time.day;
			for (; headA != NULL;)
			{
				if (headA->intime.year == time.year && headA->intime.month == time.month && headA->intime.day == time.day)
				{
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
				}
				headA = headA->next;
			}
		}
		else cout << "���뷶ΧΪ1-4�����������룡" << endl;
		break;
	case 2://��ѯ������Ϣ
		cout << "��������Ϣ��" << endl;
		cout << "1. ���ϱ��" << " " << "2. ������" << " " << "3. ��������" << endl;
		int m;
		cin >> m;
		if (m == 1)//��֪���ϱ��
		{
			int b;
			cin >> b;
			for (; headB != NULL;)
			{
				if (headB->num == b)
				{
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else if (m == 2)//��֪������
		{
			char name[20];
			cin >> name;
			for (; headB != NULL;)
			{
				if (strcmp(headB->user, name) == 0)
				{
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else if (m == 3)//��֪����ʱ��
		{
			Date time;
			cin >> time.year >> time.month >> time.day;
			for (; headB != NULL;)
			{
				if (headB->date.year == time.year && headB->date.month == time.month && headB->date.day == time.day)
				{
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else cout << "���뷶ΧΪ1-3�����������룡" << endl;
		break;
	case 3://��ѯ������
		cout << "��������Ϣ��" << endl;
		cout << "1. ���" << " " << "2. ����" << endl;
		int n;
		cin >> n;
		if (n == 1)//��֪���
		{
			int c;
			cin >> c;
			for (; headC != NULL;)
			{
				if (headC->n == c)
				{
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					for (; headB != NULL;)
					{
						if (strcmp(headC->na, headB->user) == 0)
							cout << "���û����ù���" << headB->num << "�Ų���" << endl;
						headB = headB->next;
					}
					break;
				}
				else
					headC = headC->next;
			}
		}
		else if (n == 2)//��֪����
		{
			char Name[20];
			cin >> Name;
			for (; headC != NULL;)
			{
				if (strcmp(headC->na, Name) == 0)
				{
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					for (; headB != NULL;)
					{
						if (strcmp(headC->na, headB->user) == 0)
							cout << "���û����ù���" << headB->num << "�Ų���" << endl;
						headB = headB->next;
					}
					break;
				}
				else
					headC = headC->next;
			}
		}
		else cout << "���뷶ΧΪ1-2�����������룡" << endl;
		break;
	default:
		cout << "���뷶ΧΪ1-3�����������룡" << endl<<endl;
		break;
	}
	cout << "����Ŀ¼��" << endl<<endl;
}

//�޸�
void Mod(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	int a;
	int No;//���
	cout << "��������޸���Ŀ��" << endl;
	cout << "1. ���ϱ�" << " " << "2. �������ñ�" << " " << "3. ��������Ϣ��" << endl;
	cin >> a;
	switch (a)
	{
		int b;
	case 1:
		cout << "1. ���" << " " << "2. ����" << " " << "3. ����" << " " << "4. �������" << " " << "5.���" << " " << "6. ��������" << " " << "7. ����Ա" << " " << "8. ����ʱ��" << " " << "9.��ע" << endl;
		cin >> b;
		if (headA == NULL)
		{
			cout << "������������ݣ�" << endl;
			break;
		}
		if (b == 1)//�޸ı��
		{
			cout << "������ԭ��ţ�" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "�������޸ĺ��ţ�" << endl;
					cin >> No;
					headA->no = No;
					cout << "�޸ĺ���Ϊ��" << endl;
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headA = headA->next;
			}
		}
		else if (b == 2)//�޸�����
		{
			cout << "�����뵱ǰ���ϱ�ţ�" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "�������޸ĺ����ƣ�" << endl;
					char c[20];
					cin >> c;
					strcpy_s(headA->name,c);
					cout << "�޸ĺ���Ϊ��" << endl;
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headA = headA->next;
			}
		}
		else if (b == 3)//�޸ĵ���
		{
			cout << "�����뵱ǰ���ϱ�ţ�" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "�������޸ĺ󵥼ۣ�" << endl;
					int c;
					cin >> c;
					headA->price = c;
					cout << "�޸ĺ���Ϊ��" << endl;
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headA = headA->next;
			}
		}
		else if (b == 4)//�޸��������
		{
			cout << "�����뵱ǰ���ϱ�ţ�" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "�������޸ĺ����������" << endl;
					int c;
					cin >> c;
					headA->InNum = c;
					cout << "�޸ĺ���Ϊ��" << endl;
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headA = headA->next;
			}
		}
		else if (b == 5)//�޸Ŀ��
		{
		    cout << "�����뵱ǰ���ϱ�ţ�" << endl;
		    cin >> No;
		    for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "�������޸ĺ��棺" << endl;
				    int c;
				    cin >> c;
				    headA->Num = c;
				    cout << "�޸ĺ���Ϊ��" << endl;
				    cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
				    cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
				    cout << "����Ա��" << headA->keeper << endl;
				    cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
				    cout << "��ע��" << headA->info << endl;
				    break;
			    }
			    else if (headA->next == NULL && headA->no != No)
				    cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
			    headA = headA->next;
		    }
		}
		else if (b == 6)//�޸ĳ�������
		{
		    cout << "�����뵱ǰ���ϱ�ţ�" << endl;
		    cin >> No;
		    for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "�������޸ĺ����������" << endl;
				    int c;
				    cin >> c;
				    headA->OutNum = c;
			    	cout << "�޸ĺ���Ϊ��" << endl;
			    	cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
		    		cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
		    		cout << "����Ա��" << headA->keeper << endl;
		    		cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
		    		cout << "��ע��" << headA->info << endl;
		    		break;
		    	}
		     	else if (headA->next == NULL && headA->no != No)
				    cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
			    headA = headA->next;
		    }
		}
		else if (b == 7)//����Ա
		{
		    cout << "�����뵱ǰ���ϱ�ţ�" << endl;
		    cin >> No;
		    for (; headA != NULL;)
	    	{
		    	if (headA->no == No)
		    	{
		    		cout << "�������޸ĺ����Ա������" << endl;
		    		char c[20];
			    	cin >> c;
				    strcpy_s(headA->keeper ,c);
					cout << "�޸ĺ���Ϊ��" << endl;
					cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
					cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
					cout << "����Ա��" << headA->keeper << endl;
					cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "��ע��" << headA->info << endl;
    				break;
	    		}
	    		else if (headA->next == NULL && headA->no != No)
    				cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
	    		headA = headA->next;
		    }
		}
		else if (b == 8)//�޸Ľ�������
		{
		cout << "�����뵱ǰ���ϱ�ţ�" << endl;
		cin >> No;
		for (; headA != NULL;)
		{
			if (headA->no == No)
			{
				cout << "�������޸ĺ�������ڣ�" << endl;
				Date Indate;
				cin >> Indate.year >>Indate.month >>Indate.day ;
				headA->intime .year =Indate.year ;
				headA->intime.month = Indate.month;
				headA->intime.day = Indate.day;
				cout << "�޸ĺ���Ϊ��" << endl;
				cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
				cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
				cout << "����Ա��" << headA->keeper << endl;
				cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
				cout << "��ע��" << headA->info << endl;
				break;
			}
			else if (headA->next == NULL && headA->no != No)
				cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
			headA = headA->next;
		}
		}
		else if (b == 9)//�޸ı�ע
		{
    		cout << "�����뵱ǰ���ϱ�ţ�" << endl;
	    	cin >> No;
	    	for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "�������޸ĺ�ע��������20�֣���" << endl;
			    	char c[50];
			    	cin >> c;
				    strcpy_s(headA->keeper, c);
		    		cout << "�޸ĺ���Ϊ��" << endl;
			    	cout << "��ţ�" << headA->no << " " << "���ƣ�" << headA->name << " " << "���ۣ�" << headA->price << endl;
    				cout << "���������" << headA->InNum << " " << "����������" << headA->OutNum << " " << "��棺" << headA->Num << endl;
	    			cout << "����Ա��" << headA->keeper << endl;
		    		cout << "���ʱ�䣺" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
			    	cout << "��ע��" << headA->info << endl;
			    	break;
    			}
	    		else if (headA->next == NULL && headA->no != No)
		    		cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
			    headA = headA->next;
	    	}
		}
		break;
	case 2:
		cout << "1. ���ϱ��" << " " << "2. ������" << " " << "3. ��������" << " " << "4. ��������" << endl;
		cin >> b;
		if (headB == NULL)
		{
			cout << "������������ݣ�" << endl;
			break;
		}
		if (b == 1)//�޸Ĳ��ϱ��
		{
			cout << "������ԭ��ţ�" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "�������޸ĺ��ţ�" << endl;
					cin >> No;
					headB->num = No;
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headB = headB->next;
			}
		}
		else if (b == 2)//�޸�������
		{
			cout << "������ԭ��ţ�" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "�������޸ĺ�������������" << endl;
					char c[20];
					cin >> c;
					strcpy_s(headB->user,c);
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headB = headB->next;
			}
		}
		else if (b == 3)//�޸���������
		{
			cout << "������ԭ��ţ�" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "�������޸ĺ�����������" << endl;
					int  c;
					cin >> c;
					headB->num = c;
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headB = headB->next;
			}
		}
		else if (b == 4)//�޸���������
		{
			cout << "������ԭ��ţ�" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "�������޸ĺ��������ڣ�" << endl;
					Date Indate;
					cin >> Indate.year >> Indate.month >> Indate.day;
					headB->date.year = Indate.year;
					headB->date.month = Indate.month;
					headB->date.day = Indate.day;
					cout << "��ţ�" << headB->num << " " << "�����ˣ�" << headB->user << " " << "����������" << headB->quan << endl;
					cout << "����ʱ�䣺" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headB = headB->next;
			}
		}
		break;
	case 3:
		cout << "1. ���" << " " << "2. ����" << " " << "3. �Ա�" << " " << "4. ����" << " " << "5. ��ϵ��ʽ" << endl;
		cin >> b;
		if (headB == NULL)
		{
			cout << "������������ݣ�" << endl;
			break;
		}
		if (b == 1)//�޸ı��
		{
			cout << "������ԭ��Ա��ţ�" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "�������޸ĺ��ţ�" << endl;
					cin >> No;
					headC->n = No;
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headC = headC->next;
			}
		}
		else if(b == 2)//�޸�����
		{
			cout << "��������Ա��ţ�" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "�������޸ĺ�������" << endl;
					char name[20];
					cin >> name;
					strcpy_s(headC->na ,name);
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headC = headC->next;
			}
		}
		else if (b == 3)//�޸��Ա�
		{
			cout << "��������Ա��ţ�" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "�������޸ĺ��Ա�" << endl;
					char Sex;
					cin >> Sex;
					headC->sex = Sex;
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headC = headC->next;
			}
		}
		else if (b == 4)//�޸�����
		{
			cout << "��������Ա��ţ�" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "�������޸ĺ����䣺" << endl;
					int age;
					cin >> age;
					headC->age = age;
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headC = headC->next;
			}
		}
		else if (b == 5)//�޸���ϵ��ʽ
		{
			cout << "��������Ա��ţ�" << endl;
			cin >> No;
			cout << "��������Ա��ţ�" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "�������޸ĺ���ϵ��ʽ��" << endl;
					char mean[12];
					cin >> mean;
					strcpy_s(headC->conta, mean);
					cout << "��ţ�" << headC->n << " " << "������" << headC->na << " " << "�Ա�" << headC->sex << " " << "���䣺" << headC->age << " " << "��ϵ��ʽ��" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "δ�ҵ���Ӧ��Ϣ��" << endl;
				headC = headC->next;
			}
		}
		break;
	default:
		cout << "���뷶ΧΪ1-3�����������룡" << endl<<endl;
		break;
	}
	cout << "����Ŀ¼��" << endl<<endl;
}

//�����ļ�
void InFile(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	FILE* fp;
	fopen_s(&fp, "info.txt", "w");
	for (; headA != NULL;)
	{
		fprintf(fp, "��ţ�%d  ���ƣ�%s  ���ۣ�%d  ���������%d  ��棺%d  ����������%d  ����Ա��%s  ���ʱ�䣺%d.%d.%d  ��ע��%s\n", headA->no, headA->name, headA->price, headA->InNum, headA->Num, headA->OutNum, headA->keeper, headA->intime.year, headA->intime.month, headA->intime.day, headA->info);
		headA = headA->next;
	}
	for (; headB != NULL;)
	{
		fprintf(fp, "���ϱ�ţ�%d  �����ˣ�%s  ����������%d  ����ʱ�䣺%d.%d.%d\n", headB->num, headB->user, headB->quan, headB->date.year, headB->date.month, headB->date.day);
		headB = headB->next;
	}
	for (; headC != NULL;)
	{
		fprintf(fp, "��ţ�%d  ������%s  �Ա�%c  ���䣺%d  ��ϵ��ʽ��%s\n", headC->n, headC->na, headC->sex, headC->age, headC->conta);
		headC = headC->next;
	}
	fclose(fp);
}

int main()
{
	Ing* head1=(Ing*)malloc(sizeof(Ing));
	head1->next = NULL;
	Use* head2=(Use*)malloc(sizeof(Use));
	head2->next = NULL;
	Pers* head3=(Pers*)malloc(sizeof(Pers));
	head3->next = NULL;
	int a;
	while (1)
	{
		Menu();
		cin >> a;
		switch (a)
		{
		case 1:
			Input(head1, head2, head3);
			break;
		case 2:
			Show(head1, head2, head3);
			break;
		case 3:
			Search(head1, head2, head3);
			break;
		case 4:
			Mod(head1, head2, head3);
			break;
		case 5:
			InFile(head1, head2, head3);
			return 0;
		default:
			cout << "���뷶ΧΪ1-5�����������룡" << endl << endl << endl;
		}
	}
}