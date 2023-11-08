#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h> 

#define MAX_NAME_LENGTH 100
#define MAX_VERTICES 100

// 边的类型
enum EdgeType {
    ROAD,
    STAIRS,
    ELEVATOR
};

// 边
typedef struct {
    int length; // 边的长度
    enum EdgeType type; // 边的类型
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
} Graph;

// 初始化图
void initializeGraph(Graph* graph) {
    
}

//增加一个新景点及其相关信息
void addNewVertex(Graph* graph, const char* name, const char* info) {
    
}

// 从文件中读入景点
void loadVerticesFromFile(Graph* graph, const char* filename) {
    
}

// 输出景点到文件中
void saveVerticesToFile(Graph* graph, const char* filename) {
    
}


// 增加一条新的路径
void addNewEdge(Graph* graph, const char* start, const char* end, int length, int type) {
    
}


// 修改一个已有景点的相关信息
void updateVertexInfo(Graph* graph, const char* name, const char* newInfo) {
    
}
 
// 删除一个景点及其相关信息
void removeVertex(Graph* graph, const char* name) {
    
}

// 删除一条路径
void removeEdge(Graph* graph, const char* start, const char* end) {
    
}


// 校园游览线路
void planTour(Graph* graph, const char* start, const char* wayPoint, const char* end) {
   
}


// 增加“绕行”功能
void avoidPath(Graph* graph, const char* avoidStart, const char* avoidEnd) {
    
}


// 查找顶点的索引
int findVertexIndex(Graph* graph, const char* name) {
    
}

// 查找最短路径和给出备用路径 
void findShortestPath(Graph* graph, const char* start, const char* end) {
   

    
}

#endif /* GRAPH_H */

