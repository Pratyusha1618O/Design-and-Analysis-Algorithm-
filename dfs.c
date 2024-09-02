#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

void dfs(int graph[MAX][MAX], int start, int visited[MAX], int n)
{
	visited[start] = true;
	printf("%d ", start);
	int i;
	for(i=0; i<n; i++)
	{
		if(graph[start][i] && !visited[i])
		{
			dfs(graph, i, visited, n);
		}
	}
}



int main()
{
	int i,j, n, start, graph[MAX][MAX];
	int visited[MAX];
	do{
		printf("Enter the no of vertices: ");
		scanf("%d",&n);
	}while(n > MAX);

	printf("Enter adjacency matrix:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter starting vertex: ");
	scanf("%d",&start);

	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}

	printf("DFS Traversal of graph: \n");
	dfs(graph, start, visited, n);

	return 0;

}








