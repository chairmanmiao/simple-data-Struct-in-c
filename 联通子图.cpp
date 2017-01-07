#include "stdio.h"
#define True 1 
#define False 0 
#define Error -1 
#define OK 1 
typedef struct ArcNode{
	int adj; 
}ArcNode;
//定义图结构
typedef struct{
	char vertex[20];
	int arcs[20][20];
	int vexnum,arcnum;
}AdjMatrix;
int visited[20];
void visit(AdjMatrix g,int vexIndex){
	printf("%c",g.vertex[vexIndex]); 
}
//链接矩阵遍历图结构
void  depth(AdjMatrix g,int v0){
	visit(g,v0);
	visited[v0]=1;
	for(int vj=0;vj<g.vexnum;vj++){
		if(!visited[vj]&&g.arcs[v0][vj]==1) depth(g,vj);
	}
}
//访问临邻节点存在函数
int FirstAdjVertex(AdjMatrix g,int v0){
	int vj=0;
	for(vj=0;vj<g.vexnum;vj++){
			if(!visited[vj]&&g.arcs[v0][vj]==1){
				return(vj);
				 break;
			}//else return -1;
			
			
		}
	
}
//访问下一个邻节点函数
int NextAdjVertex(AdjMatrix g,int v0,int w){
	int vj=0;
	for(vj=0;vj<g.vexnum;vj++){
		if(!visited[vj]&&g.arcs[v0][vj]==1) {
				return vj;
			}
			else if(v0==w) return(-1);
			else return (v0);
			break;
	}
		
}
//深度优先遍历v0所在的连通子图函数
void DepthFirstSearch(AdjMatrix g,int v0){
	visit(g,v0);
	visited[v0]=True;
	int w=FirstAdjVertex(g,v0);
	while(w!=-1){
		if(!visited[w]) DepthFirstSearch(g,w);
		w=NextAdjVertex(g,v0,w);
	}
}
//深度优先遍历图函数
//void TraverseGraph(AdjMatrix g){
//	int vi;
	//for(vi=0;vi<g.vexnum;vi++) visited[vi]=False;
	//for(vi=0;vi<g.vexnum;vi++)
	//if(!visited[vi]) depth(g,vi);
//}
int main(){
	AdjMatrix g={{'A','B','C','D','E',},{
	{0,1,1,0,0},
	{1,0,0,1,1},
	{1,0,0,1,0},
	{0,1,0,0,1},
    {0,1,0,1,0},
    
	},5,6};
	//depth(g,2);
	//TraverseGraph(g);
	//printf("\n");
	DepthFirstSearch(g,0);
	//printf("%d",a);
	return 0;
}
