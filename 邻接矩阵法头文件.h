#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h> 

#define MAX_NAME_LENGTH 100
#define MAX_VERTICES 100


// 边
typedef struct {
    int length; // 边的长度
    int type; // 边的类型(0是走路，1是坐车)
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
} Graph,*map;


// 初始化图
void initializeGraph(map& graph) {
    graph->numVertices = 0;
    graph->numedge = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->edges[i][j].length = 0;
            graph->edges[i][j].type = 0;
        }
    }
}


//增加一个新景点及其相关信息
void addNewVertex(map& graph,char* name,char* info) {
    
}

// 从文件中读入景点
void loadVerticesFromFile(map& graph, char* filename) {
    
}

// 输出景点到文件中
void saveVerticesToFile(map& graph, char* filename) {
    
}


// 增加一条新的路径
void addNewEdge(map& graph, char* start, char* end, int length, int type) {
    
}


// 修改一个已有景点的相关信息
void updateVertexInfo(map& graph, char* name, char* newInfo) {
    
}
 
// 删除一个景点及其相关信息
void removeVertex(map& graph, char* name) {
    
}

// 删除一条路径
void removeEdge(map& graph, char* start, char* end) {
    
}


// 校园游览线路
void planTour(map& graph, char* start, char* wayPoint, char* end) {
   
}


// 增加“绕行”功能
void avoidPath(map& graph, char* avoidStart, char* avoidEnd) {
    
}


// 查找顶点的索引
int findVertexIndex(map& graph, char* name) {
    
}

// 查找最短路径和给出备用路径 
void findShortestPath(map& graph, char* start, char* end) {
   

    
}

#endif /* GRAPH_H */
