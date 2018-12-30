//standard I/O
#include<stdio.h>
//console I/O like getch()
#include<conio.h>
//for socket address to get TTL
#include <sys/socket.h>


int main()
{
  //int sd;
  //sd = socket(AF_INET, SOCK_DGRAM, 0);
  //if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse)) < 0)
  // variable assignment
  int v,i,j,min,current,nv,source,dest,y,x,T;
  //mw-maximum weight(infinity)
  int mw=1000;                         
  int visited[10],path[10],distance[10];
  //Cost Adjacency Matrix  , Last art of IP Address
  int adj[10][10],ip[1000];
  //To Store the Half IP address
  char s1[100];
  //Clear Previos Outputted Result
  clrscr();
  //Get The Number of Vertices of The Graph
  printf("Enter no. of vertices in the graph: ");
  scanf("%d",&v);
  //Get The Starting IP Address like   192.168.43
  printf("Enter Common IP Address Except Last 3 Digit\t");
  scanf("%s",&s1);
  //Get The last 3 Digit of IP Address of Given Number of Vertices
  for(i=1;i<=v;i++){
    printf("Enter IP Address of %d Vertex: \t",i);
    scanf("%s",&ip[i]);
  }
  printf("-------------------------------------------------------------");
  //Getting Cost Ajacency Matrix
  printf("\nEnter Weight Matrix:\n"); 
  for(i=1;i<=v;i++){
    for(j=1;j<=v;j++){
     scanf("%d",&adj[i][j]);
    }
  }
  //Initial Values
  for(i=1;i<=v;i++){
    visited[i]=0;
    path[i]=0;
    distance[i]=mw;
  }
  //Getting Source Vertex From The User to calculated The Distance To Other Vertices
  printf("\nEnter Source Vertex: ");
  scanf("%d",&source);
  //User Input as Source
  current=source;
  //Since Source as Taked From The Used so It is Taken as Visited
  visited[current]=1;
  //nv= nnumber of vertices visited
  nv=1;
  //T=total shortest distance of current node of previous paths
  T=0;
  //vertices not visited
  while(nv!=v){
    //checking for all the vertices V
    for(i=1;i<=v;i++)
      //checking if the adjacency matrix of source vertex is not set to 0
      if(adj[current][i]!=0)
        //checked if it is not visited
        if(visited[i]!=1)
          //if the distace is less assign to DISTANCE and store it into PATH
          if(distance[i]>adj[current][i]+T){
            distance[i]=adj[current][i]+T;
            path[i]=current;
          }
    //minimum is maximum weight which is 1000
    min=mw;
    for(i=1;i<=v;i++)
      if(visited[i]!=1)
        //check distance is not crossing the limit
        if(distance[i]<min){
          min=distance[i];
          current=i;
        }
    //since current vertex is visited then it set to 1
    visited[current]=1;
    //Increment the VISITED nodes
    nv=nv+1;
    //getting distance of currently visited vertex
    T=distance[current];
  }
  //printf("Enter Destination Vertex: ");
  //scanf("%d",&dest);
  //Printing the source and Destination Vertices and IP addresses
  for(dest=1; dest<=v; dest++){
    if(dest!=source){
      printf("\n\nShortest distance from Vertex %d( %s.%s ) to %d ( %s.%s ) is %d", source, &s1,&ip[source], dest,&s1,&ip[dest], distance[dest]);
      printf("\nShortest path is as follows: ");
      y=dest;
      do{
        x=path[y];
        printf("\nVertex %d of host %s.%s is connected to vertex %d of host %s.%s",y,&s1,&ip[y],x,&s1,&ip[x]);
        y=x;
      }while(y!=source);
    }
  }
  getch();
  return 0;
}
