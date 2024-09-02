#include<stdio.h>
#include<stdlib.h>
#define INF 99999
#define MAX 10
int V;

void print(int dist[MAX][MAX])
{
	int i,j;
	printf("The shortest distance between all pair of vertices: \n");
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			if(dist[i][j] == INF){
				printf("%4s","INF");
			}
			else{
				printf("%4d",dist[i][j]);
			}
		}
		printf("\n");
	}
}

void floyd_warshall(int dist[MAX][MAX])
{
	int i,j,k;
	for(k=0; k<V; k++)
	{
		for(i=0; i<V; i++)
		{
			for(j=0; j<V; j++)
			{
				if(dist[i][j] > dist[i][k]+dist[k][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	print(dist);
}

int main()
{
	int graph[MAX][MAX], i,j;
	printf("Enter the no of vertices: ");
	scanf("%d",&V);
	printf("Enter adjacency matrix: \n");
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			scanf("%d", &graph[i][j]);
			if(graph[i][j] == 0  &&  i != j)
			{
				graph[i][j] = INF;
			}
		}
	}
	
	floyd_warshall(graph);
	return 0;
}
