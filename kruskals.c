#include<stdio.h>
#include<stdlib.h>
#define INF 999
int root[10] = {-1};

int find(int i)
{
	while(root[i])
	{
		i = root[i];
	}
	return i;
}

int uni(int i, int j)
{
	if(i != j)
	{
		root[j] = i;
		return 1;
	}
	return 0;
}

int main()
{
	int i,j, graph[10][10],v, edges=0, total=0;
	int min;
	int x,y,m,n;
	printf("Enter the no of vertices: ");
	scanf("%d",&v);
	printf("Enter adjacency matrix: \n");
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			scanf("%d", &graph[i][j]);
			if(graph[i][j] == 0){
				graph[i][j] = INF;
			}
		}
	}
	
	// Kruskal's algorithm start
	printf("Edges:\n");
	while(edges < v-1)
	{
		min = INF;
		for(i=0; i<v; i++)
		{
			for(j=0; j<v; j++)
			{
				if(graph[i][j] < min)
				{
					min = graph[i][j];
					x = i;
					y = j;
				}
			}
		}
		m = find(x);
		n= find(y);
		
		if(uni(m, n))
		{
			printf("%d - %d : %d\n", x,y, graph[x][y]);
			total += min;
			edges++;
		}
		
		graph[x][y] = INF;
		graph[y][x] = graph[x][y];
	}
	printf("Total Cost(minimum): %d", total);
	return 0;
}

















