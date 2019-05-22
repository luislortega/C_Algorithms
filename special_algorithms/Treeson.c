#include<stdio.h>
#include<conio.h>
#define MAX 20
//Prototipo de la funci�n
void dijkstra(int G[MAX][MAX],int n,int startnode, int f,char graph_name[MAX][28]);

int main()
{
	//Aqu� se agrega graph_connections de Processing
	int G[MAX][MAX]={{0,1,1,0,0,0,0,0,0,0,0,0},
	{1,0,0,1,1,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,1,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,1,1,0,0},
	{0,0,1,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,0,0,0}};;
	//Identificadores
	int n, f, u, valor=1;
	//Nombres de los nodos
	char graph_name[MAX][28] = {"Bisabuelo", "hijo 1", "hijo 2", "hijo 1.1", "hijo 1.2", "hijo 1.3", 
	"hijo 2.1", "hijo 1.1.1(T�)", "hijo 1.3.1", "hijo 1.3.2", "hijo 2.1.1", "hijo 2.1.2"};
	printf("Ingrese el n�mero de v�rtices:");
	scanf("%d",&n);
	printf("\nv�rtice: Sujeto\n");
	//Imprime un peque�o listado del los nodos y los n�meros que les corresponden
	for(int i=0; i<n; i++){
		if(graph_name[i][0]!=0){
			printf("%i: ", i);
		}else{
			valor=0;
		}
		for(int j=0; j<28; j++){
			if(graph_name[i][j]!=0){
				printf("%c", graph_name[i][j]);
			}
		}
		if(valor==1){
			printf("\n");
		}
	}
	//Ingresa el v�rtice de donde desea salir
	printf("\nIngrese el v�rtice inicial:");
	scanf("%d",&u);
	printf("\nIngrese el v�rtice final:");
	scanf("%d",&f);
	dijkstra(G,n,u,f, graph_name);
	
	return 0;
}
//Funci�n de Dijkstra
void dijkstra(int G[MAX][MAX],int n,int startnode, int f, char graph_name[MAX][28])
{
	//IDENTIFICADORES
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j]==0){
				cost[i][j]=999;
			}else{
				cost[i][j]=G[i][j];
			}
		}
	}
			
	//Inicializa pred[],distance[] and visited[]
	for(i=0;i<n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
			
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
			
	while(count<n-1){
		mindistance=999;
		
		//nextnode nos da el nodo con la distancia m�nima
		for(i=0;i<n;i++){
			if(distance[i]<mindistance&&visited[i]!=1){
			mindistance=distance[i];
			nextnode=i;
			}
		}	
		//Verifica si existe un mejor camino al siguiente nodo			
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(visited[i]!=1){
				if(mindistance+cost[nextnode][i]<distance[i]){
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
			
	//Imprime la ruta y la distancia del nodo inicial al final
	for(i=f;i<f+1;i++){
		if(i!=startnode){
			printf("\n\nDistancia del nodo %d a %d = %d",startnode, f,distance[i]);
			printf("\nRuta=");
			for(int k=0; k<MAX; k++){
				if(graph_name[f][k]!=0){
					printf("%c", graph_name[f][k]);
				}
			}
			j=i;
			do
			{
				j=pred[j];
				printf("<-");
				for(int k=0; k<MAX; k++){
					if(graph_name[j][k]!=0){
						printf("%c", graph_name[j][k]);
					}
				}
			}while(j!=startnode);
		}
	}
}
