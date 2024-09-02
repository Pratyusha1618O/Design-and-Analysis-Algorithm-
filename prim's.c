#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define INF 99999

void prims(int graph[MAX][MAX]);
void print(int parent[],int graph[MAX][MAX]);

int v;

void prims(int graph[MAX][MAX])
{
	int key[v];
	int parent[v];
	bool mstvisited[v];
	int i,j,k;
	for(i=0;i<v;i++)
	{
		key[i]=INF;
		mstvisited[i]=false;
		parent[i]=-1;
	}
	key[0]=0;
	parent[0]=-1;
	for(i=0;i<v-1;i++)
	{
		int min=INF;
		int u;
		//finds the minimum node
		for(k=0;k<v;k++)
		{

			if(mstvisited[k]==false && key[k]<min)
			{
				min=key[k];
				u=k;//minimum node
			}
		}
		mstvisited[u]=true;
		
		for(j=0;j<v;j++)
		{
			if(graph[u][j]!=0 && mstvisited[j]==false && graph[u][j]<key[j])
			{
				key[j]=graph[u][j];
				parent[j]=u;
			}
		}
	}
	print(parent,graph);
}
void print(int parent[],int graph[MAX][MAX])
{
	int totalcost=0,i;
	printf("Edge \tWeight\n");
    for (i=1;i<v;i++)
    {
	 printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
	 totalcost+=graph[i][parent[i]];
	}
	printf("\nTotal cost of MST is %d", totalcost);
}
int main()
{
	int graph[MAX][MAX];
	int i,j;
	printf("\nEnter the no. of vertices:");
	scanf("%d",&v);
	printf("\nEnter the adjacency matrix:");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}

	prims(graph);
	return 0;
}

/*


Enter the no. of vertices:5

Enter the adjacency matrix:
0 3 0 3 1
3 0 3 0 1
0 3 0 3 2
3 0 3 0 0
1 1 2 0 0
Edge    Weight
4 - 1   1
4 - 2   2
0 - 3   3
0 - 4   1

Total cost of MST is 7
--------------------------------
Process exited after 34.91 seconds with return value 0
Press any key to continue . . .


*/

