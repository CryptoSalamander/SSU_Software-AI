#include <iostream>
#include <vector>
#include <queue>
#include <stack>//���� STL �ڷᱸ���� ��Ŭ����մϴ�.
using namespace std;

class mynode
{
public :
	int id;//���ĺ�������� 0~19�� id�� �������� �Ͽ����ϴ�.
	mynode* parentnode;//�θ����Դϴ�.
	int gn;//�������������� �ش��忡 ���µ� ���� �ʿ��� Cost�Դϴ�.
public :
	mynode(int myid, mynode myparentnode)//mynode��� Ŭ������ �����Ͽ����ϴ�.
	{
		id = myid;
		parentnode = &myparentnode;
	}
	mynode()
	{

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
void printmynode(queue<mynode> myopen,queue<mynode> myclose)//Open�� Close�� ����ϴ� �Լ��Դϴ�.
{
	printf("Open : [ ");
	while (!myopen.empty())
	{
		numtocity(myopen.front().id);
		printf(" ");
		myopen.pop();
	}
	printf("]\n");
	printf("Close : [ ");
	while (!myclose .empty())
	{
		numtocity(myclose.front().id);
		myclose.pop();
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
		{ 75, 0, 0, 0,0, 0, 0, 0, 0, 0, 0,71, 0,  0 ,0, 0,  0, 0 ,0,  0 }//19
	};
	queue<mynode> open;
	queue<mynode> close;
	queue<mynode> tmpopen;
	queue<mynode> tmpclose;//open�� close�� ����ϸ� ������ open�� close�� �ջ�ǹǷ� �ӽ� ������ �����Ͽ����ϴ�.
	mynode parent[1000];//�θ��带 �����ϱ� ���� �����Դϴ�.
	mynode tmpnode;
	mynode nextnode;
	mynode startnode;//�ӽ� �����Դϴ�.
	startnode.id = 15;//��ŸƮ����� Timisoara�� ���ĺ� 15���� �����̹Ƿ� 15�� �ְ� �����մϴ�.
	open.push(startnode);
	bool check[20] = { false };//�鷶�� ������ üũ�ϱ� ���� bool�迭�Դϴ�.
	bool find = false;//��ǥ��带 ã�Ҵ��� üũ�ϱ� ���� �����Դϴ�.
	int n = 0;
	int plus = 0;
	while (!open.empty())//distance �迭�� ���� BreadthFirst������� ť�� open�� close�� ���� �����մϴ�.
	{
		printf("Iteration : %d\n", ++n);
		tmpopen = open;
		tmpclose = close;
		printmynode(tmpopen, tmpclose);
		tmpnode = open.front();
		if (tmpnode.id == 1)//open��忡�� �������� Bucharest�� ������ break�մϴ�.
			break;
		check[tmpnode.id] = true;
		open.pop();
		close.push(tmpnode);
		for (i = 0; i < 20; i++)
		{
			if (distance[tmpnode.id][i] != 0)//�ڽĳ�带 �߰��մϴ�.
			{
				if (check[i] == false)
				{
					nextnode.id = i;
					parent[plus++] = tmpnode;
					nextnode.parentnode = &parent[plus - 1];
					nextnode.gn = parent[plus - 1].gn + distance[tmpnode.id][i];
					open.push(nextnode);
					check[i] = true;
					if (i == 1)
						find = true;//��ǥ��带 ã�Ҵ��� üũ�մϴ�.
				}
			}
		}
	}
	printf("Iteration : Final\n");
	tmpopen = open;
	tmpclose = close;
	printmynode(tmpopen, tmpclose);
	stack<mynode> path;
	while (open.front().id != 1)
	{
		open.pop();
	}
	tmpnode = open.front();
	if (find = true)//��ǥ��带 ã�Ҵٸ� ��θ� ����մϴ�.
	{
		int cost = tmpnode.gn;
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
	else//��� ��ã������ �޼��� ���
	{
		printf("���ã�� ����!");
	}
	getchar();
	
}