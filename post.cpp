#include<stdint.h>
#include<iostream>
#include<string>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct
	{
		int number;//标记位
		int cost;//节点间距离
		int dis;//节点间最近的距离
	}node;
typedef struct
	{
		int from;//边的起点
		int end;//边的终点
		int e;//边的距离
	}edge;
class post
{
	const int inf;//两点之间无通路
	int finishflag;
	int d[1005];
	int t[1005];
	int point[100];
	int pf[100];
	int minedge[100];
	int tmpedge[100];
	int ps[100];
	int n;//点的个数
	int m;//边的个数
	int te, op;//总的边数，为奇数的点的数
	int needaddnum, mincount, edgenum;//需要添加边的个数
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
	cout << "调用构造函数" << endl;
}
post::~post()
{
	cout << "调用析构函数" << endl;
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

	cout << "请输入顶点个数和边的条数:" << endl;
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
		cout << "请输入顶点和边的关系:" << endl;
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
		for (i = 1; i <= n; i++) //判断连通性
		{     
			if (t[i] == -1)
				as++;
		}
		for (i = 1; i <= n; i++)  //判断度数
		{   
			if (d[i] % 2) {
				flag = 1;
				break;
			}
		}
		if (as > 1 || flag)
		{
			cout << "不是欧拉回路" << endl;
		}
		else
			cout << "是欧拉回路" << endl;
		op= 0;
		for (i = 1; i <= n; i++)              // 判断点是否为奇点
		{
			if ((point[i] & 0x1) == 1)
			{
				op++;
			}
		}

		int firstid = 1;    // 设置邮局的位置 1即为A
		if (op > 2)
		{
			floyd();
			extende(op / 2);
		}

		top = 0;
		if (op == 2)                             //不能构成环路，直接退出程序
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
		char vex;                 // 输出最短路线
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