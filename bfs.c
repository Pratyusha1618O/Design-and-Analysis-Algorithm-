#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX] = {0}; // visited array
int queue[MAX]; //array to implement queue

int front=0, rear=0;
int n, start; // n = no. of vertices, start = starting vertex

void bfs(int n)
{
	int i;
	// mark the starting vertex as visited and add to queue
	visited[start] = 1;
	queue[rear++] = start;
	printf("Visited nodes are: \n");
	int current;
	while(front < rear)// loop runs till the queue is empty
	{
		current = queue[front++]; //dequeues a vertex from queue
		printf("%d ", current);
		//gets the adjacent vertices of dequeued vertex
		for(i=0; i<n; i++)
		{
			//if an adjacent vertex is not visited then it will be
			//visited and enqueued
			if(graph[current][i] && !visited[i])
			{
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}
}

int main()
{
	int i,j;
	do{
		printf("Enter no of vertices: ");
		scanf("%d", &n);
	}while(n>MAX);

	printf("Enter adjacency matrix\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter starting vertex: ");
	scanf("%d",&start);

	bfs(n); // calling bfs with no of vertices
	return 0;
}









