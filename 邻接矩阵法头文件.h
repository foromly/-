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
        
    }
    //有这两个景点的话就直接把这两条边的的值和类型都变为初始值
    //变为跟init函数里面一样
    
}


//给出从起始到结束的所有景点   校园游览线路
void planTour(Map& graph, char* start, char* end) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    //bfs
    queue<Vertex>q;
    q.push(graph->vertices[u]);
    while(!q.empty()){
        
    }
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
void findShortestPath(Map& graph, char* start, char* end) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);

    int D[MAX_VERTICES];
    bool S[MAX_VERTICES];

    memset(S,false,sizeof(S));

    for(int i=0;i<graph->numVertices;i++){
        D[i]=graph->edges[u][i]->length;
    }

    int D[u]=0,w;
    bool S[u]=true;

    for(int i=0;i<graph->numVertices;i++){
       int min=MaxInt;
        for(int j=0;j<graph->numVertices;i++){
            if(!S[j]&&D[j]<MaxInt){
                min=D[j];
                S[j]=true;
            }
        w=j;
    }
    for(int j=0;j<graph->numVertices;j++){
        if(!S[j]&&min+graph->edges[w][j]<D[j]){
            D[j]=min+graph->edges[w][j];
        }
    }
}

#endif /* GRAPH_H */
