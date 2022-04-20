#include<string.h>
#include<iostream>

using namespace std;

//时间结构体
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

//人员信息结构体
typedef struct Pers
{
	int n;
	char na[20];
	char sex;
	int age;
	char conta[12];
	Pers* next;
}Pers;

//材料信息结构体
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

//领用信息结构体
typedef struct Use
{
	int num;
	char user[20];
	int quan;
	Date date;
	Use* next;
}Use;

//初始化菜单
void Menu()
{
	cout << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                          欢迎使用小李的飞机设计地面试验材料管理系统                          **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                                                                                              **" << endl;
	cout << "**                                          1. 添加信息                                         **" << endl;
	cout << "**                                          2. 显示信息                                         **" << endl;
	cout << "**                                          3. 查询信息                                         **" << endl;
	cout << "**                                          4. 修改信息                                         **" << endl;
	cout << "**                                          5. 结束运行                                         **" << endl;
	cout << "**                                                                                              **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << "**                                     请输入所需使用的功能                                     **" << endl;
	cout << "**************************************************************************************************" << endl;
	cout << endl ;
}

//添加信息
void Input(Ing* headA, Use* headB, Pers* headC)
{
	Ing* p;
	Use* q;
	Pers* r;
	cout << "请输入添加信息：" << endl;
	cout << "1. 材料信息" << " " << "2. 领用信息" << " " << "3. 领用人信息" << endl;
	int a,b;
	cin >> a;
	switch (a)
	{
	case 1://添加材料信息
		while (headA->next != NULL) headA = headA->next;
		cout << "请输入添加信息条数：" << endl;
		cin >> b;
		for (int i=0;i<b;i++)
		{
			p = new Ing;
			cout << "请输入当前材料编号：" << endl;
			cin >> p->no;
			cout << "请输入当前材料名称：" << endl;
			cin >> p->name;
			cout << "请输入当前材料价格：" << endl;
			cin >> p->price;
			cout << "请输入入库数量：" << endl;
			cin >> p->InNum;
			cout << "请输入出库数量：" << endl;
			cin >> p->OutNum;
			p->Num = p->InNum - p->OutNum;
			cout << "请输入管理员姓名:" << endl;
			cin >> p->keeper;
			cout << "请输入进货时间：" << endl;
			cin >> p->intime.year >> p->intime.month >> p->intime.day;
			cout << "备注（不超过20字）：" << endl;
			cin >> p->info;
			headA->next = p;
			p->next = NULL;
			headA = p;
		}
		break;
	case 2://添加领用信息
		while (headB->next != NULL) headB = headB->next;
		cout << "请输入添加信息条数：" << endl;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			q = new Use;
			cout << "请输入领用材料编号：" << endl;
			cin >> q->num;
			for (;headA != NULL;)
			{
				if (headA->no == q->num)
				{
					cout << "成功搜索到对应信息！" << endl;
					break;
				}
				else if (headA->no != q->num && headA->next == NULL)
				{
					cout << "未搜索到对应信息，返回目录！" << endl;
					return;
				}
				headA = headA->next;
			}
			cout << "请输入领用人姓名：" << endl;
			cin >> q->user;
			cout << "请输入领用数量：" << endl;
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
						cout << "超出库存数量！" << endl;
						return;
					}
				}
				headA = headA->next;
			}
			cout << "请输入领用日期" << endl;
			cin >> q->date.year >> q->date.month >> q->date.day;
			headB->next = q;
			q->next = NULL;
			headB = q;
		}
		break;
	case 3://添加领用人信息
		while (headC->next != NULL) headC = headC->next;
		cout << "请输入添加信息条数：" << endl;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			r = new Pers;
			cout << "请输入领用人编号：" << endl;
			cin >> r->n;
			cout << "请输入领用人姓名：" << endl;
			cin >> r->na;
			cout << "请输入领用人性别：" << endl;
			cin >> r->sex;
			cout << "请输入领用人年龄：" << endl;
			cin >> r->age;
			cout << "请输入领用人联系方式：" << endl;
			cin >> r->conta;
			headC->next = r;
			r->next = NULL;
			headC = r;
		}
		break;
	}
	cout << "返回目录！" << endl<<endl;
}

//显示已存信息
void Show(Ing* head1, Use* head2,Pers* head3)
{
	int a;
	cout << "请输入需要显示的内容编号：" << endl;
	cout << "1. 材料表" << " " << "2. 材料领用表" << " " << "3. 领用人信息表" << endl;
	cin >> a;
	switch (a) 
	{
	case 1://显示材料表信息
		for (int i=1; head1->next != NULL;i++)
	    {
		    head1 = head1->next;
		    cout << "材料" << i << ":" << endl;
		    cout << "编号：" << head1->no << " " << "名称：" << head1->name << " " << "单价：" << head1->price << endl;
		    cout << "入库数量：" << head1->InNum << " " << "出库数量：" << head1->OutNum << " " << "库存：" << head1->Num << endl;
		    cout << "管理员：" << head1->keeper << endl;
		    cout << "入库时间：" << head1->intime.year << "." << head1->intime.month << "." << head1->intime.day << endl;
		    cout << "备注：" << head1->info << endl;
	    }
		  break; 
	case 2://显示材料领用信息
		for (int i = 1; head2->next != NULL; i++)
		{
			head2 = head2->next;
			cout << "领用记录" << i << ":" << endl;
			cout << "材料编号：" << head2->num << " " << "领用人：" << head2->user << " " << "领用数量：" << head2->quan << endl;
			cout << "领用时间：" << head2->date.year << "." << head2->date.month << "." << head2->date.day << endl;
		}
		break;
	case 3://显示领用人信息
		for (int i = 1; head3->next != NULL; i++)
		{
			head3 = head3->next;
			cout << "领用人" << i << ":" << endl;
			cout << "编号：" << head3->n << " " << "姓名：" << head3->na << " " << "性别：" << head3->sex << " " << "年龄：" << head3->age << " " << "联系方式：" << head3->conta << endl;
		}
		break;
	default:
		cout << "输入范围为1-3，请重新输入！"<<endl<<endl;
		break;
	}
	cout << "返回目录！"<<endl<<endl;
}

//查询
void Search(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	int a;
	cout << "请输入查询内容：" << endl;
	cout << "1. 材料表" << "  " << "2. 领用记录" << " " << "3. 领用人信息" << endl;
	cin >> a;
	switch (a)
	{
	case 1://材料查询
		cout << "请输入信息：" << endl;
		cout << "1. 材料编号" << " " << "2. 材料名" << " " << "3. 保管人" << " " << "4. 进货时间" << endl;
		int l;
		cin >> l;
		if (l == 1)//已知编号
		{
			int n;
			cin >> n;
			for (; headA != NULL;)
			{
				if (headA->no == n)
				{
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else
					headA = headA->next;
			}
		}
		else if (l == 2)//已知材料名
		{
			char na[20];
			cin >> na;
			for (; headA != NULL;)
			{
				if (strcmp(headA->name, na) == 0)
				{
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else
					headA = headA->next;
			}
		}
		else if (l == 3)//已知保管人
		{
			char stuff[20];
			cin >> stuff;
			for (; headA != NULL;)
			{
				if (strcmp(headA->keeper, stuff) == 0)
				{
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
				}
				headA = headA->next;
			}
		}
		else if (l == 4)//已知领用时间
		{
			Date time;
			cin >> time.year >> time.month >> time.day;
			for (; headA != NULL;)
			{
				if (headA->intime.year == time.year && headA->intime.month == time.month && headA->intime.day == time.day)
				{
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
				}
				headA = headA->next;
			}
		}
		else cout << "输入范围为1-4，请重新输入！" << endl;
		break;
	case 2://查询领用信息
		cout << "请输入信息：" << endl;
		cout << "1. 材料编号" << " " << "2. 领用人" << " " << "3. 领用日期" << endl;
		int m;
		cin >> m;
		if (m == 1)//已知材料编号
		{
			int b;
			cin >> b;
			for (; headB != NULL;)
			{
				if (headB->num == b)
				{
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else if (m == 2)//已知领用人
		{
			char name[20];
			cin >> name;
			for (; headB != NULL;)
			{
				if (strcmp(headB->user, name) == 0)
				{
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else if (m == 3)//已知领用时间
		{
			Date time;
			cin >> time.year >> time.month >> time.day;
			for (; headB != NULL;)
			{
				if (headB->date.year == time.year && headB->date.month == time.month && headB->date.day == time.day)
				{
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
				}
				headB = headB->next;
			}
		}
		else cout << "输入范围为1-3，请重新输入！" << endl;
		break;
	case 3://查询领用人
		cout << "请输入信息：" << endl;
		cout << "1. 编号" << " " << "2. 姓名" << endl;
		int n;
		cin >> n;
		if (n == 1)//已知编号
		{
			int c;
			cin >> c;
			for (; headC != NULL;)
			{
				if (headC->n == c)
				{
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					for (; headB != NULL;)
					{
						if (strcmp(headC->na, headB->user) == 0)
							cout << "该用户领用过：" << headB->num << "号材料" << endl;
						headB = headB->next;
					}
					break;
				}
				else
					headC = headC->next;
			}
		}
		else if (n == 2)//已知姓名
		{
			char Name[20];
			cin >> Name;
			for (; headC != NULL;)
			{
				if (strcmp(headC->na, Name) == 0)
				{
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					for (; headB != NULL;)
					{
						if (strcmp(headC->na, headB->user) == 0)
							cout << "该用户领用过：" << headB->num << "号材料" << endl;
						headB = headB->next;
					}
					break;
				}
				else
					headC = headC->next;
			}
		}
		else cout << "输入范围为1-2，请重新输入！" << endl;
		break;
	default:
		cout << "输入范围为1-3，请重新输入！" << endl<<endl;
		break;
	}
	cout << "返回目录！" << endl<<endl;
}

//修改
void Mod(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	int a;
	int No;//编号
	cout << "请输入待修改项目：" << endl;
	cout << "1. 材料表" << " " << "2. 材料领用表" << " " << "3. 领用人信息表" << endl;
	cin >> a;
	switch (a)
	{
		int b;
	case 1:
		cout << "1. 编号" << " " << "2. 名称" << " " << "3. 单价" << " " << "4. 入库数量" << " " << "5.库存" << " " << "6. 出库数量" << " " << "7. 管理员" << " " << "8. 进货时间" << " " << "9.备注" << endl;
		cin >> b;
		if (headA == NULL)
		{
			cout << "所查表中无内容！" << endl;
			break;
		}
		if (b == 1)//修改编号
		{
			cout << "请输入原编号：" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "请输入修改后编号：" << endl;
					cin >> No;
					headA->no = No;
					cout << "修改后结果为：" << endl;
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "未找到对应信息！" << endl;
				headA = headA->next;
			}
		}
		else if (b == 2)//修改名称
		{
			cout << "请输入当前材料编号：" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "请输入修改后名称：" << endl;
					char c[20];
					cin >> c;
					strcpy_s(headA->name,c);
					cout << "修改后结果为：" << endl;
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "未找到对应信息！" << endl;
				headA = headA->next;
			}
		}
		else if (b == 3)//修改单价
		{
			cout << "请输入当前材料编号：" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "请输入修改后单价：" << endl;
					int c;
					cin >> c;
					headA->price = c;
					cout << "修改后结果为：" << endl;
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "未找到对应信息！" << endl;
				headA = headA->next;
			}
		}
		else if (b == 4)//修改入库数量
		{
			cout << "请输入当前材料编号：" << endl;
			cin >> No;
			for (; headA != NULL;)
			{
				if (headA->no == No)
				{
					cout << "请输入修改后入库数量：" << endl;
					int c;
					cin >> c;
					headA->InNum = c;
					cout << "修改后结果为：" << endl;
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
					break;
				}
				else if (headA->next == NULL && headA->no != No)
					cout << "未找到对应信息！" << endl;
				headA = headA->next;
			}
		}
		else if (b == 5)//修改库存
		{
		    cout << "请输入当前材料编号：" << endl;
		    cin >> No;
		    for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "请输入修改后库存：" << endl;
				    int c;
				    cin >> c;
				    headA->Num = c;
				    cout << "修改后结果为：" << endl;
				    cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
				    cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
				    cout << "管理员：" << headA->keeper << endl;
				    cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
				    cout << "备注：" << headA->info << endl;
				    break;
			    }
			    else if (headA->next == NULL && headA->no != No)
				    cout << "未找到对应信息！" << endl;
			    headA = headA->next;
		    }
		}
		else if (b == 6)//修改出库数量
		{
		    cout << "请输入当前材料编号：" << endl;
		    cin >> No;
		    for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "请输入修改后出库数量：" << endl;
				    int c;
				    cin >> c;
				    headA->OutNum = c;
			    	cout << "修改后结果为：" << endl;
			    	cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
		    		cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
		    		cout << "管理员：" << headA->keeper << endl;
		    		cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
		    		cout << "备注：" << headA->info << endl;
		    		break;
		    	}
		     	else if (headA->next == NULL && headA->no != No)
				    cout << "未找到对应信息！" << endl;
			    headA = headA->next;
		    }
		}
		else if (b == 7)//管理员
		{
		    cout << "请输入当前材料编号：" << endl;
		    cin >> No;
		    for (; headA != NULL;)
	    	{
		    	if (headA->no == No)
		    	{
		    		cout << "请输入修改后管理员姓名：" << endl;
		    		char c[20];
			    	cin >> c;
				    strcpy_s(headA->keeper ,c);
					cout << "修改后结果为：" << endl;
					cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
					cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
					cout << "管理员：" << headA->keeper << endl;
					cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
					cout << "备注：" << headA->info << endl;
    				break;
	    		}
	    		else if (headA->next == NULL && headA->no != No)
    				cout << "未找到对应信息！" << endl;
	    		headA = headA->next;
		    }
		}
		else if (b == 8)//修改进货日期
		{
		cout << "请输入当前材料编号：" << endl;
		cin >> No;
		for (; headA != NULL;)
		{
			if (headA->no == No)
			{
				cout << "请输入修改后进货日期：" << endl;
				Date Indate;
				cin >> Indate.year >>Indate.month >>Indate.day ;
				headA->intime .year =Indate.year ;
				headA->intime.month = Indate.month;
				headA->intime.day = Indate.day;
				cout << "修改后结果为：" << endl;
				cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
				cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
				cout << "管理员：" << headA->keeper << endl;
				cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
				cout << "备注：" << headA->info << endl;
				break;
			}
			else if (headA->next == NULL && headA->no != No)
				cout << "未找到对应信息！" << endl;
			headA = headA->next;
		}
		}
		else if (b == 9)//修改备注
		{
    		cout << "请输入当前材料编号：" << endl;
	    	cin >> No;
	    	for (; headA != NULL;)
		    {
			    if (headA->no == No)
			    {
				    cout << "请输入修改后备注（不超过20字）：" << endl;
			    	char c[50];
			    	cin >> c;
				    strcpy_s(headA->keeper, c);
		    		cout << "修改后结果为：" << endl;
			    	cout << "编号：" << headA->no << " " << "名称：" << headA->name << " " << "单价：" << headA->price << endl;
    				cout << "入库数量：" << headA->InNum << " " << "出库数量：" << headA->OutNum << " " << "库存：" << headA->Num << endl;
	    			cout << "管理员：" << headA->keeper << endl;
		    		cout << "入库时间：" << headA->intime.year << "." << headA->intime.month << "." << headA->intime.day << endl;
			    	cout << "备注：" << headA->info << endl;
			    	break;
    			}
	    		else if (headA->next == NULL && headA->no != No)
		    		cout << "未找到对应信息！" << endl;
			    headA = headA->next;
	    	}
		}
		break;
	case 2:
		cout << "1. 材料编号" << " " << "2. 领用人" << " " << "3. 领用数量" << " " << "4. 领用日期" << endl;
		cin >> b;
		if (headB == NULL)
		{
			cout << "所查表中无内容！" << endl;
			break;
		}
		if (b == 1)//修改材料编号
		{
			cout << "请输入原编号：" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "请输入修改后编号：" << endl;
					cin >> No;
					headB->num = No;
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "未找到对应信息！" << endl;
				headB = headB->next;
			}
		}
		else if (b == 2)//修改领用人
		{
			cout << "请输入原编号：" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "请输入修改后领用人姓名：" << endl;
					char c[20];
					cin >> c;
					strcpy_s(headB->user,c);
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "未找到对应信息！" << endl;
				headB = headB->next;
			}
		}
		else if (b == 3)//修改领用数量
		{
			cout << "请输入原编号：" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "请输入修改后领用数量：" << endl;
					int  c;
					cin >> c;
					headB->num = c;
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "未找到对应信息！" << endl;
				headB = headB->next;
			}
		}
		else if (b == 4)//修改领用日期
		{
			cout << "请输入原编号：" << endl;
			cin >> No;
			for (; headB != NULL;)
			{
				if (headB->num == No)
				{
					cout << "请输入修改后领用日期：" << endl;
					Date Indate;
					cin >> Indate.year >> Indate.month >> Indate.day;
					headB->date.year = Indate.year;
					headB->date.month = Indate.month;
					headB->date.day = Indate.day;
					cout << "编号：" << headB->num << " " << "领用人：" << headB->user << " " << "领用数量：" << headB->quan << endl;
					cout << "领用时间：" << headB->date.year << "." << headB->date.month << "." << headB->date.day << endl;
					break;
				}
				else if (headB->next == NULL && headB->num != No)
					cout << "未找到对应信息！" << endl;
				headB = headB->next;
			}
		}
		break;
	case 3:
		cout << "1. 编号" << " " << "2. 姓名" << " " << "3. 性别" << " " << "4. 年龄" << " " << "5. 联系方式" << endl;
		cin >> b;
		if (headB == NULL)
		{
			cout << "所查表中无内容！" << endl;
			break;
		}
		if (b == 1)//修改编号
		{
			cout << "请输入原人员编号：" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "请输入修改后编号：" << endl;
					cin >> No;
					headC->n = No;
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "未找到对应信息！" << endl;
				headC = headC->next;
			}
		}
		else if(b == 2)//修改姓名
		{
			cout << "请输入人员编号：" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "请输入修改后姓名：" << endl;
					char name[20];
					cin >> name;
					strcpy_s(headC->na ,name);
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "未找到对应信息！" << endl;
				headC = headC->next;
			}
		}
		else if (b == 3)//修改性别
		{
			cout << "请输入人员编号：" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "请输入修改后性别：" << endl;
					char Sex;
					cin >> Sex;
					headC->sex = Sex;
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "未找到对应信息！" << endl;
				headC = headC->next;
			}
		}
		else if (b == 4)//修改年龄
		{
			cout << "请输入人员编号：" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "请输入修改后年龄：" << endl;
					int age;
					cin >> age;
					headC->age = age;
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "未找到对应信息！" << endl;
				headC = headC->next;
			}
		}
		else if (b == 5)//修改联系方式
		{
			cout << "请输入人员编号：" << endl;
			cin >> No;
			cout << "请输入人员编号：" << endl;
			cin >> No;
			for (; headC != NULL;)
			{
				if (headC->n == No)
				{
					cout << "请输入修改后联系方式：" << endl;
					char mean[12];
					cin >> mean;
					strcpy_s(headC->conta, mean);
					cout << "编号：" << headC->n << " " << "姓名：" << headC->na << " " << "性别：" << headC->sex << " " << "年龄：" << headC->age << " " << "联系方式：" << headC->conta << endl;
					break;
				}
				else if (headC->next == NULL && headC->n != No)
					cout << "未找到对应信息！" << endl;
				headC = headC->next;
			}
		}
		break;
	default:
		cout << "输入范围为1-3，请重新输入！" << endl<<endl;
		break;
	}
	cout << "返回目录！" << endl<<endl;
}

//存入文件
void InFile(Ing* head1, Use* head2, Pers* head3)
{
	Ing* headA = head1->next;
	Use* headB = head2->next;
	Pers* headC = head3->next;
	FILE* fp;
	fopen_s(&fp, "info.txt", "w");
	for (; headA != NULL;)
	{
		fprintf(fp, "编号：%d  名称：%s  单价：%d  入库数量：%d  库存：%d  出库数量：%d  管理员：%s  入库时间：%d.%d.%d  备注：%s\n", headA->no, headA->name, headA->price, headA->InNum, headA->Num, headA->OutNum, headA->keeper, headA->intime.year, headA->intime.month, headA->intime.day, headA->info);
		headA = headA->next;
	}
	for (; headB != NULL;)
	{
		fprintf(fp, "材料编号：%d  领用人：%s  领用数量：%d  领用时间：%d.%d.%d\n", headB->num, headB->user, headB->quan, headB->date.year, headB->date.month, headB->date.day);
		headB = headB->next;
	}
	for (; headC != NULL;)
	{
		fprintf(fp, "编号：%d  姓名：%s  性别：%c  年龄：%d  联系方式：%s\n", headC->n, headC->na, headC->sex, headC->age, headC->conta);
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
			cout << "输入范围为1-5，请重新输入！" << endl << endl << endl;
		}
	}
}