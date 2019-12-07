#include<stdint.h>
#include<iostream>
#include<string>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct
	{
		int number;//���λ
		int cost;//�ڵ�����
		int dis;//�ڵ������ľ���
	}node;
typedef struct
	{
		int from;//�ߵ����
		int end;//�ߵ��յ�
		int e;//�ߵľ���
	}edge;
class post
{
	const int inf;//����֮����ͨ·
	int finishflag;
	int d[1005];
	int t[1005];
	int point[100];
	int pf[100];
	int minedge[100];
	int tmpedge[100];
	int ps[100];
	int n;//��ĸ���
	int m;//�ߵĸ���
	int te, op;//�ܵı�����Ϊ�����ĵ����
	int needaddnum, mincount, edgenum;//��Ҫ��ӱߵĸ���
	int top;
	node map[100][100];
	edge odde[100];
public:
	post();
	~post();
	int find(int x);
	void floyd();
	void searche(int c,int s);
	void dijkstraae(int s,int e);
	void extende(int an);
	void searchp(int s);
	void display();
};
post::post():inf(0x7fffffff), finishflag(0)
{
	cout << "���ù��캯��" << endl;
}
post::~post()
{
	cout << "������������" << endl;
}
int post::find(int x)
{
	if (t[x]==-1)
	{
		return x;
	}
	else
	{
		int temp = find(t[x]);
		t[x] = temp;
		return temp;
	}
}
void post::floyd()
{
	int i, j, k;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			if (map[i][k].dis != inf)
			{
				for (j = 1; j < n; j++)
					if (map[k][j].dis != inf)
						map[i][j].dis = map[j][i].dis = min(map[i][j].dis, map[i][k].dis + map[k][j].dis);
			}
		}
	}
}
void post::searche(int c, int s)
{
	if (s == needaddnum)
	{
		if (c < mincount)
		{
			for (int i = 0; i < needaddnum; i++)
			{
				minedge[i] = tmpedge[i];
			}
			mincount = c;
		}
	}
	int i, a, b, d;
	for (i = 0; i < edgenum; i++)
	{
		 a = odde[i].from;
		 b = odde[i].end;
d = odde[i].e;
int pf[100];

if (pf[a] == 1 && pf[b] == 1)
{
	pf[a] = pf[b] = 0;
	tmpedge[s] = i;
	searche(c + d, s + 1);
	pf[a] = pf[b] = 1;
}
	}

}
void post::dijkstraae(int s, int e)
{
	int i, dis[100], u[100], pre[100];
	memset(u, 0, sizeof(u));
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[s] = 0;
	while (1)
	{
		int v = -1;
		for (i = 1; i <= n; i++)
		{
			if (!u[i] && (v == -1 || dis[i] < dis[v]))
			{
				v = i;
			}
		}
		if (v == e || v == -1)
		{
			break;
		}
		u[v] = 1;
		for (i = 1; i <= n; i++)
		{
			if (map[v][i].cost < inf && (dis[v] + map[v][i].cost) < dis[i])
			{
				pre[i] = v;
				dis[i] = dis[v] + map[v][i].cost;
			}
		}
	}
	int v = e;
	int pren = e;
	while (pren != s)
	{
		pren = pre[v];
		++map[pren][v].number;
		++map[v][pren].number;
	}
}
void post::extende(int an)
{
	int i, j;
	needaddnum = an;
	memset(pf, 0, sizeof(pf));
	edgenum = 0;
	for (i = 1; i < n; i++)
	{
		if ((point[i] & 0x1) == 1)
		{
			for (j = i + 1; j <= n; j++)
			{
				if ((point[j] & 0x1) == 1 && map[i][j].dis < inf)
				{
					pf[i] = pf[j] = 1;
					odde[edgenum].from = i;
					odde[edgenum].end = j;
					odde[edgenum].e = map[i][j].dis;
					edgenum++;
				}
			}
		}
	}
	mincount = inf;
	searche(0, 0);
	if (mincount < inf)
	{
		int a, b;
		for (i = 0; i < needaddnum; i++)
		{
			int k = minedge[i];
			a = odde[k].from;
			b = odde[k].end;
			dijkstraae(a, b);
			point[a] = point[b] = 0;
		}
		op -= an * 2;
		te += an;
	}
	else
	{
		exit(-1);
	}
}
void post::searchp(int s)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (map[s][i].number > 0)
		{
			--map[s][i].number;
			--map[i][s].number;
			ps[top++] = i;
			if (top == (te + 1))
			{
				finishflag = 1;
			}
			searchp(i);
			if (finishflag)
			{
				return;
			}
			++map[s][i].number;
			++map[i][s].number;
			--top;

		}
	}
}
void post::display()
{
	int i, j;

	cout << "�����붥������ͱߵ�����:" << endl;
	cin >> n >> m;

	while ((n&m) != EOF)
	{
		memset(t, -1, sizeof(t));
		memset(d, 0, sizeof(d));
		memset(point, 0, sizeof(point));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				map[i][j].cost = map[i][j].dis = inf;
		te = 0;
		cout << "�����붥��ͱߵĹ�ϵ:" << endl;
		int a, b, c;
		for (i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			int tempa = find(a);
			int tempb = find(b);
			if (tempa != tempb)
				t[tempa] = tempb;
			d[a]++;                
			d[b]++;
			map[a][b].cost = map[b][a].cost = c;
			map[a][b].dis = map[b][a].dis = c;
			map[a][b].number = map[b][a].number= 1;
			++point[a];
			++point[b];
			++te;
		}

		int flag = 0;
		int as = 0;
		for (i = 1; i <= n; i++) //�ж���ͨ��
		{     
			if (t[i] == -1)
				as++;
		}
		for (i = 1; i <= n; i++)  //�ж϶���
		{   
			if (d[i] % 2) {
				flag = 1;
				break;
			}
		}
		if (as > 1 || flag)
		{
			cout << "����ŷ����·" << endl;
		}
		else
			cout << "��ŷ����·" << endl;
		op= 0;
		for (i = 1; i <= n; i++)              // �жϵ��Ƿ�Ϊ���
		{
			if ((point[i] & 0x1) == 1)
			{
				op++;
			}
		}

		int firstid = 1;    // �����ʾֵ�λ�� 1��ΪA
		if (op > 2)
		{
			floyd();
			extende(op / 2);
		}

		top = 0;
		if (op == 2)                             //���ܹ��ɻ�·��ֱ���˳�����
		{
			for (i = 1; i <= n; i++)
			{
				if ((point[i] & 0x1) == 1)
				{
					firstid = i;
					break;
				}

			}
			if (firstid != 1)
			{
				exit(-2);
			}
		}

		ps[top++] = firstid;
		searchp(firstid);
		char vex;                 // ������·��
		for (i = 0; i <= te; i++)
		{
			vex = ps[i] + 'A' - 1;
			cout << vex << endl;
			if (i < te)
			{
				cout << "=>" <<endl;
			}
		}
	}
}

int main()
{
	post A;
	A.display();
	system("pause");
	return 0;
}