#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF 99999
int V;

print(int dist[], int src)
{
	printf("Vertex \t Distance from source\n");
	int i;
	for(i=0; i<V; i++)
	{
		printf("%d -> %d \t %d\n", src, i, dist[i]);
	}
}

int minDistance(int dist[], int sptSet[])
{
	int min = INF, min_index;
	
	int v; // adjacent vertex
	for(v=0; v<V; v++)
	{
		if(sptSet[v] == 0  &&  dist[v] <= min )
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void dijkstra(int graph[MAX][MAX], int src)
{
	int dist[V]; // output array to hold shortest distance 
	int sptSet[V]; // shortest path tree set
	
	//initialize all distances as infinite and sptSet as false
	int i;
	for(i=0; i<V; i++)
	{
		dist[i] = INF;
		sptSet[i] = 0;
	}
	
	//distance from source to itself always 0
	dist[src] = 0;
	
	//Calculate the shortest path for all vertices
	int count;
	for(count=0; count<V-1; count++)
	{
		int u = minDistance(dist, sptSet); //get the vertex with minimum distance 
		sptSet[u] = 1; //mark the picked vertex in the shortest path tree
		
		//update distance value of adjacent vertices of picked vertex
		int v; //adjacent vertex
		for(v=0; v<V; v++)
		{
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	
	print(dist, src);
}

int main()
{
	int graph[MAX][MAX];
	int i,j, src;
	printf("Enter the no of vertices: ");
	scanf("%d",&V);
	printf("Enter adjacency matrix: \n");
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter the source node: ");
	scanf("%d", &src);
	
	dijkstra(graph, src);
	return 0;
}











