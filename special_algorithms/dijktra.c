#include<stdio.h>
#include<conio.h>
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()
{
	//Aqu� se agrega los valores de edge_weight de processing
	int G[MAX][MAX]={{0,2,999,10,999,999},
	{2,0,5,999,999,999},
	{999,5,0,1,999,4},
	{10,999,1,0,1,999},
	{999,999,999,1,0,1},
	{999,999,4,999,1,0}};
	
	int n, u, valor=1;
	
	char graph_name[10][28] = {"Escarcega", "Merida", "Valladolid", "Tulum", "Playa del carmen", "Cancun"};
	printf("Ingrese el n�mero de v�rtices:");
	scanf("%d",&n);
	printf("\nv�rtice: Ciudad\n");
	//Imprime el n�mero del v�rtice para cada ciudad
	for(int i=0; i<10; i++){
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
	dijkstra(G,n,u);
	
	return 0;
}
//Funci�n de Dijkstra
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
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
			
	//Imprime la ruta y la distancia para cada v�rtice
	for(i=0;i<n;i++){
		if(i!=startnode){
			printf("\n\nDistancia del nodo %d a %d = %d",startnode, i,distance[i]);
			printf("\nRuta=%d",i);
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
		}
	}
}