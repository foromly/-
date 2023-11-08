#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h> 

#define MAX_NAME_LENGTH 100
#define MAX_VERTICES 100

// �ߵ�����
enum EdgeType {
    ROAD,
    STAIRS,
    ELEVATOR
};

// ��
typedef struct {
    int length; // �ߵĳ���
    enum EdgeType type; // �ߵ�����
} Edge;

// ����
typedef struct {
    char name[MAX_NAME_LENGTH]; // ��������
    char info[MAX_NAME_LENGTH]; // ������Ϣ
} Vertex;

// ͼ
typedef struct {
    Vertex vertices[MAX_VERTICES]; // ��������
    Edge edges[MAX_VERTICES][MAX_VERTICES]; // �ߵĶ�ά����
    int numVertices; // ��������
} Graph;

// ��ʼ��ͼ
void initializeGraph(Graph* graph) {
    
}

//����һ���¾��㼰�������Ϣ
void addNewVertex(Graph* graph, const char* name, const char* info) {
    
}

// ���ļ��ж��뾰��
void loadVerticesFromFile(Graph* graph, const char* filename) {
    
}

// ������㵽�ļ���
void saveVerticesToFile(Graph* graph, const char* filename) {
    
}


// ����һ���µ�·��
void addNewEdge(Graph* graph, const char* start, const char* end, int length, int type) {
    
}


// �޸�һ�����о���������Ϣ
void updateVertexInfo(Graph* graph, const char* name, const char* newInfo) {
    
}
 
// ɾ��һ�����㼰�������Ϣ
void removeVertex(Graph* graph, const char* name) {
    
}

// ɾ��һ��·��
void removeEdge(Graph* graph, const char* start, const char* end) {
    
}


// У԰������·
void planTour(Graph* graph, const char* start, const char* wayPoint, const char* end) {
   
}


// ���ӡ����С�����
void avoidPath(Graph* graph, const char* avoidStart, const char* avoidEnd) {
    
}


// ���Ҷ��������
int findVertexIndex(Graph* graph, const char* name) {
    
}

// �������·���͸�������·�� 
void findShortestPath(Graph* graph, const char* start, const char* end) {
   

    
}

#endif /* GRAPH_H */

