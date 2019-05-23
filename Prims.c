#include <stdio.h>

visited[10];

int main(void)
{
	int cost[10][10],i,j,min,mincost=0,n,ne=1,a,b,u,v;
	
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	printf("Enter Adjacency Matrix: ");
	for(i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        scanf("%d",&cost[i][j]);
	    }
	}
	visited[1]=1;
	
	while(ne<n)
	{
	    min=999;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            if(cost[i][j]<min)
	            {
	                if(visited[i]!=0)
	                {
    	                min=cost[i][j];
    	                a=u=i;
    	                b=v=j;
	                }
	            }
	        }
	    }
	    
	    if(!visited[u] || !visited[v])
	    {
	        printf("\n%d edge (%d -> %d) = %d",ne++,a,b,min);
	        mincost += min;
	        visited[b]=1;
	    }
	    cost[a][b]=cost[b][a]=999;
	}
	printf("\nMin. Cost=%d",mincost);
	return 0;
}

