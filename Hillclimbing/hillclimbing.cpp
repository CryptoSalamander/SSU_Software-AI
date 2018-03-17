#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <deque>//���� STL �ڷᱸ���� ��Ŭ����մϴ�.
#include <algorithm>//sort �Լ��� ��� ���
using namespace std;

class mynode
{
public:
	int id;//���ĺ�������� 0~19�� id�� �������� �Ͽ����ϴ�.
	mynode* parentnode;//�θ����Դϴ�.
	int gn;//�������������� �ش��忡 ���µ� ���� �ʿ��� Cost�Դϴ�.
	int fn;//���Լ��Դϴ�.
	int hn;//Bucharest������ �����Ÿ��Դϴ�.
public:
	mynode(int myid, mynode myparentnode)//mynode��� Ŭ������ �����Ͽ����ϴ�.
	{
		id = myid;
		parentnode = &myparentnode;
		
	}
	mynode()
	{

	}
	bool operator <(const mynode &a) const//sort�� ���� ������ �����ε��Դϴ�.
	{
		return this->fn < a.fn;
	}
};
void numtocity(int i)//���ڸ� �޾ƿ� �����̸����� ��ȯ���ִ� �Լ��Դϴ�.
{
	switch (i)
	{
	case 0:
		printf("Arad ");
		break;
	case 1:
		printf("Bucharest ");
		break;
	case 2:
		printf("Craiova ");
		break;
	case 3:
		printf("Dobreta ");
		break;
	case 4:
		printf("Eforie ");
		break;
	case 5:
		printf("Giurgiu ");
		break;
	case 6:
		printf("Hirsova ");
		break;
	case 7:
		printf("Iasi ");
		break;
	case 8:
		printf("Lugoj ");
		break;
	case 9:
		printf("Mehadia ");
		break;
	case 10:
		printf("Neamt ");
		break;
	case 11:
		printf("Oradea ");
		break;
	case 12:
		printf("Pitesti ");
		break;
	case 13:
		printf("RimnicuVilcea ");
		break;
	case 14:
		printf("Sibiu ");
		break;
	case 15:
		printf("Timisoara ");
		break;
	case 16:
		printf("Urziceni ");
		break;
	case 17:
		printf("Vaslui ");
		break;
	case 18:
		printf("Yagaras ");
		break;
	case 19:
		printf("Zerind ");
		break;
	}
}
void printmynode(deque<mynode> myopen, deque<mynode> myclose)//Open�� Close�� ����ϴ� �Լ��Դϴ�.
{
	printf("Open : [ ");
	while (!myopen.empty())
	{
		numtocity(myopen.front().id);
		printf(" ");
		myopen.pop_front();
	}
	printf("]\n");
	printf("Close : [ ");
	while (!myclose.empty())
	{
		numtocity(myclose.front().id);
		myclose.pop_front();
	}
	printf("]\n");
}
int main()
{
	int i;
	int distance[20][20] =//���ð��� �Ÿ��� �׷����������� ǥ���� �迭�Դϴ�. 0�ϰ�� ���� ���ٴ� �ǹ��Դϴ�.
	{
		//0  1  2  3  4  5  6  7  8  9 10 11 12 13  14  15 16 17 18  19
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,140,118, 0, 0, 0, 75 },//0
		{ 0, 0, 0, 0, 0,90, 0, 0, 0, 0, 0, 0, 101,0, 0, 0, 85, 0,211, 0 },//1
		{ 0, 0, 0,120,0, 0, 0, 0, 0, 0, 0, 0,138,146,0, 0,  0, 0, 0,  0 },//2
		{ 0, 0,120,0, 0, 0, 0, 0, 0,75, 0, 0,  0, 0, 0, 0,  0, 0, 0,  0 },//3
		{ 0, 0, 0, 0, 0, 0,86, 0, 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0 , 0 },//4
		{ 0,90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0,  0, 0 ,0,  0 },//5
		{ 0, 0, 0, 0,86, 0, 0, 0, 0, 0, 0 ,0,  0, 0, 0, 0, 98, 0, 0,  0 },//6
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,87, 0,  0, 0, 0, 0, 0, 92, 0,  0 },//7
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,70, 0, 0,  0, 0, 0,111,0,  0, 0,  0 },//8
		{ 0, 0, 0,75, 0, 0, 0, 0,70, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,  0 },//9
		{ 0, 0, 0, 0, 0, 0, 0,87, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,  0 },//10
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,151,0, 0,  0, 0, 71 },//11
		{ 0,101,138,0,0, 0, 0, 0, 0, 0, 0, 0,  0,97, 0, 0, 0,  0, 0,  0 },//12
		{ 0, 0,146, 0,0, 0, 0, 0, 0, 0, 0, 0, 97, 0,80, 0, 0,  0, 0,  0 },//13
		{ 140,0, 0, 0,0, 0, 0, 0, 0, 0, 0,151,0, 80, 0, 0, 0,  0,99,  0 },//14
		{ 118,0, 0, 0,0, 0, 0, 0,111,0, 0, 0, 0,  0 ,0, 0, 0,  0, 0,  0 },//15
		{ 0, 85, 0, 0,0, 0,98, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0,142, 0,  0 },//16
		{ 0, 0, 0, 0, 0, 0, 0,92, 0, 0, 0, 0, 0,  0, 0, 0,142, 0, 0,  0 },//17
		{ 0,211,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 99,0,  0, 0, 0,  0 },//18
		{ 75, 0, 0,  0,  0,  0, 0,  0,  0,  0,  0,  71, 0,  0 ,0,  0,  0,  0 ,0, 0 }//19
	 // { 366,0,160,242,161,77,151,226,244,241,234,380,98,193,253,329,80,199,178,374 }
	};
	int hnlist[20] = { 366,0,160,242,161,77,151,226,244,241,234,380,98,193,253,329,80,199,178,374 };
	deque<mynode> open;
	deque<mynode> close;
	deque<mynode> tmpopen;
	deque<mynode> tmpclose;//open�� close�� ����ϸ� ������ open�� close�� �ջ�ǹǷ� �ӽ� ������ �����Ͽ����ϴ�.
	mynode parent[1000];
	mynode tmpnode;
	mynode nextnode;
	mynode startnode;//�ӽ� �����Դϴ�.
	startnode.id = 15;//��ŸƮ����� Timisoara�� ���ĺ� 15���� �����̹Ƿ� 15�� �ְ� �����մϴ�.
	open.push_front(startnode);
	bool check[20] = { false };//�鷶�� ������ üũ�ϱ� ���� bool�迭�Դϴ�.
	bool find = false;//��ǥ��带 ã�Ҵ��� üũ�ϱ� ���� �����Դϴ�.
	int n = 0;
	int plus = 0;
	int nodenum =0;
	deque<mynode>::iterator iter;//sort�� ���� �ݺ����Դϴ�.
	while (!open.empty())//distance �迭�� ���� Hillclimbing������� ť�� open�� close�� ���� �����մϴ�.
	{
		printf("\n");
		printf("iteration : %d\n", ++n);
		mynode tmpmy;
		iter = open.begin();
		tmpmy = *iter;
		for (i = 1; i < nodenum; i++)
		{
			//tmpmy = *iter;
			iter++;
			//printf("id : %d\n", tmpmy.id);
		}
		sort(open.begin(), iter+1);//���ε����Ե� �ڽĳ�常 �����մϴ�.(������ �ִ� ���� ���ڸ� ����)
		nodenum = 0;
		tmpopen = open;
		tmpclose = close;

		printmynode(tmpopen, tmpclose);
		tmpnode = open.front();
		if (tmpnode.id == 1)
			break;
		check[tmpnode.id] = true;
		open.pop_front();
		close.push_front(tmpnode);
		for (i = 19; i >= 0; i--)
		{
			if (distance[tmpnode.id][i] != 0)//�ڽĳ�带 �߰��մϴ�.
			{
				if (check[i] == false)
				{
					nextnode.id = i;
					parent[plus++] = tmpnode;
					nextnode.parentnode = &parent[plus - 1];
					nextnode.hn = hnlist[i];
					nextnode.gn = parent[plus - 1].gn + distance[tmpnode.id][i];//�θ��� gn�� distance�� ���� �� �Ÿ��� ���մϴ�.
					nextnode.fn = nextnode.hn + nextnode.gn;//���Լ�fn�� ���� �ֽ��ϴ�.
					open.push_front(nextnode);
					check[i] = true;//�����°��̶�� ǥ���մϴ�.
					if (i == 1)
						find = true;//��ǥ��Ʈ�� ã�Ҵ��� üũ�մϴ�.
					nodenum++;//�� ��� �ڽĳ�尡 ���������� ����, �̸� ���� ���� ���� ��常 �����մϴ�.
				}
			}
		}
	}

	printf("\n");
	printf("Iteration : Final\n");
	tmpopen = open;
	tmpclose = close;
	printmynode(tmpopen, tmpclose);
	stack<mynode> path;
	while (open.front().id != 1)
	{
		open.pop_front();
	}
	tmpnode = open.front();
	if (find = true)
	{
		int cost = tmpnode.gn;
		printf("\n");
		printf("Path : [ ");
		while (tmpnode.id != 15)
		{
			path.push(tmpnode);
			tmpnode = *tmpnode.parentnode;
		}
		path.push(tmpnode);
		while (!path.empty())
		{
			numtocity(path.top().id);
			path.pop();
		}
		printf(" ]");
		printf("\nCost : %d", cost);
	}
	else
	{
		printf("���ã�� ����!");
	}
	getchar();

}