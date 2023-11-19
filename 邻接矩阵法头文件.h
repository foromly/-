#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h> 
uisng namespace std;
#define MAX_NAME_LENGTH 100
#define MAX_VERTICES 100

#define ERROR -1
#define OK 0
#define MaxInt 1e9;
// 边
typedef struct {
    int length[2]; // 走路或者坐车的长度(0为走路，1为坐车)
    int type; // 边的类型(0为走路，1为坐车)
} Edge;

// 顶点
typedef struct {
    char name[MAX_NAME_LENGTH]; // 顶点名称
    char info[MAX_NAME_LENGTH]; // 顶点信息
} Vertex;

// 图
typedef struct {
    Vertex vertices[MAX_VERTICES]; // 顶点数组
    Edge edges[MAX_VERTICES][MAX_VERTICES]; // 边的二维数组
    int numVertices; // 顶点数量
    int numedge;//边的数量 
} Graph,*Map;


// 初始化图
void initializeGraph(Map& graph) {
    graph->numVertices = 0;
    graph->numedge = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            for(int k=0;k<2;k++){
            graph->edges[i][j].length[k] = MaxInt;
            }
            graph->edges[i][j].type = -1;
        }
    }
}


//增加一个新景点及其相关信息
int addNewVertex(Map& graph,char* name,char* info) {
    if(graph->numVertices>MAX_VERTICES){
           return ERROR;
    }
    cin>>name;
    cin>>info;
    graph->vertices[numVertices]->name=name;
    graph->vertices[numVertices]->info=info;
    numVertices++;
    return OK;
}


// 从文件中读入景点
void loadVerticesFromFile(Map& graph, char* filename) {
    
}

// 输出景点到文件中
void saveVerticesToFile(Map& graph, char* filename) {
    
}


// 增加一条新的路径
int addNewEdge(Map& graph, char* start, char* end, int length, int type) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    if(graph->edges[u][v]->length[type]!=MaxInt){
        //这里可以尝试询问一下是否要替换原始路径
        return ERROR;
    }
    graph->edge[u][v]->length[type]=length;
    graph->numedge++;
    return OK;
}


// 修改一个已有景点的相关信息
int updateVertexInfo(Map& graph, char* name) {
    int s=findVertexIndex(graph, name);
    if(s==-1){
        return ERROR;
    }
     char name[MAX_NAME_LENGTH]; // 顶点名称
     char info[MAX_NAME_LENGTH]; // 顶点信息
    
    //用case或者if判断一下是要修改名字还是顶点信息
    
}
 
// 删除一个景点及其相关信息
int removeVertex(Map& graph, char* name) {
    int s=findVertexIndex(graph, name);
    if(s==-1){
        return ERROR;
    }
    //删除这个顶点的话就把graph->vertices数组里面的顶点从当前位置开始把后面的往前挪一个
    
}

// 删除一条路径
int removeEdge(Map& graph, char* start, char* end) {
    
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    if(u!=-1&&v!=-1){
        //说明没有这两个景点
        else if(u==-1){
            cout<<start<<"该点不存在，不需要删除路径！";
        }
        else if(v==-1){
            cout<<end<<"该点不存在，不需要删除路径！";
        }
	    else if(!isEdge(G,u,v)){
		cout<<start<<"和"<<end<<"这两个景点之间不存在路径，不需要再删除路径！";	
	}
	int temp=G.edge[u][v];
	G.e--;
	G.edge[u][v]=INF;
	G.edge[v][u]=INF;
	printf("已成功删除从%s到%s的路径。\n",start,end);	
	
    
   
    //有这两个景点的话就直接把这两条边的的值和类型都变为初始值
    //变为跟init函数里面一样
    
}


//给出从起始到结束的所有景点   校园游览线路
void planTour(Map& graph, char* start,char* halfway, char* end) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    int w=findVertexINdex(graph,halfway);

	//dfs

	
}


// 增加“绕行”功能
void avoidPath(Map& graph, char* avoidStart, char* avoidEnd) {
    
}


// 查找顶点的索引
int findVertexIndex(Map& graph, char* name) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// 查找最短路径和
void findShortestPath(Map& graph, char* start, char* end,int type) {
    int dist[MAX_VERTICES]; // 存储起点到各个顶点的最短距离
    int prev[MAX_VERTICES]; // 存储最短路径中各个顶点的前驱顶点
    bool visited[MAX_VERTICES]; // 标记顶点是否已访问

    int startIdx = findVertexIndex(graph, start);
    int endIdx = findVertexIndex(graph, end);

    // 初始化
    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = graph->edges[startIdx][i].length[type];
        prev[i] = startIdx;
        visited[i] = false;
    }
    dist[startIdx] = 0;
    visited[startIdx] = true;

    // 计算最短路径
    for (int i = 1; i < graph->numVertices; i++) {
        int minDist = INF;
        int u = startIdx;
        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        visited[u] = true;
        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->edges[u][j].length[type] < INF) {
                if (dist[u] + graph->edges[u][j].length[type] < dist[j]) {
                    dist[j] = dist[u] + graph->edges[u][j].length[type];
                    prev[j] = u;
                }
            }
        }
    }

    // 输出最短路径
    int path[MAX_VERTICES];
    int pathLength = 0;
    int current = endIdx;
    while (current != startIdx) {
        path[pathLength++] = current;
        current = prev[current];
    }
    path[pathLength++] = startIdx;
    printf("Shortest Path from %s to %s: ", start, end);
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%s ", graph->vertices[path[i]].name);
    }
    printf("\n");
}

#endif /* GRAPH_H */
