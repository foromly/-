#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h> 
using namespace std;
#define MAX_NAME_LENGTH 100
#define MAX_VERTICES 100

#define ERROR -1
#define OK 0
#define MaxInt 1e7
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
    int numedge[2];//边的数量 
} Graph,*Map;


// 初始化图
void initializeGraph(Map& graph) {
    graph->numVertices = 0;
    for(int i=0;i<2;i++){
    graph->numedge[i] = 0;
}
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            for(int k=0;k<2;k++){
            graph->edges[i][j].length[k] = MaxInt;
            }
            graph->edges[i][j].type = -1;
        }
    }
    return ;
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

//增加一个新景点及其相关信息
void addNewVertex(Map& graph,char* name,char* info) {
    if(graph->numVertices>MAX_VERTICES){
       	cout<<"已超过景点最大数量无法添加"<<endl;
       	return ;
    }
    int u=findVertexIndex(graph,name);
	if(u!=-1){
		cout<<"已存在此景点，无法添加"<<endl;
		return ;
	}
    strcpy(graph->vertices[graph->numVertices].name, name);
    strcpy(graph->vertices[graph->numVertices].info, info);
    graph->numVertices++;
    cout<<"增加成功"<<endl; 
    return ;
}


// 从文件中读入景点
void loadVerticesFromFile(Map& graph, char* filename) {
    
}

// 输出景点到文件中
void saveVerticesToFile(Map& graph, char* filename) {
    
}


// 增加一条新的路径
void addNewEdge(Map& graph, char* start, char* end, int length, int type) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    if(graph->edges[u][v].length[type]!=MaxInt){
        //这里可以尝试询问一下是否要替换原始路径
        char choice;
        cout<<"已存在此路径，是否要替换(y/n)"<<endl;
		cin>>choice; 
		switch(choice){
			case 'y':
			    graph->edges[u][v].length[type]=length;
			    cout<<"替换成功"<<endl;
			    break;
			case 'n':
				cout<<"退出"<<endl; 
				break;
			default:
				cout<<"无效的选择,请重新输入"<<endl; 
		}
        return ;
    }
    graph->edges[u][v].length[type]=length;
    graph->numedge[type]++;
    cout<<"添加成功"<<endl;
    return ;
}


// 修改一个已有景点的相关信息
void updateVertexInfo(Map& graph, char* name) {
    int s=findVertexIndex(graph, name);
    if(s==-1){
    	cout<<"该景点不存在"<<endl;
        return ;
    }
    //用case或者if判断一下是要修改名字还是顶点信息
     int choice;
     char newName[MAX_NAME_LENGTH];
     char newInfo[MAX_NAME_LENGTH];
     cout<<"请输入你的选择"<<endl; 
     cout<<"1.修改景点名称"<<endl;
	 cout<<"2.修改景点信息"<<endl;
	 cout<<"3.修改景点名称和信息"<<endl;
	 cin>>choice;
	switch(choice){
		case 1:
			cout<<"请输入新的名称"<<endl;
			cin>>newName;
			strcpy(graph->vertices[s].name, newName);
			cout<<"修改名称成功"<<endl; 
			return ;
			break;
		case 2:
		    cout<<"请输入新的介绍"<<endl;
			cin>>newInfo;
			strcpy(graph->vertices[s].info, newInfo);
			cout<<"修改介绍成功"<<endl;
			return ;
			break;
		case 3:
			cout<<"请输入新的名称"<<endl;
			cin>>newName;
			cout<<"请输入新的介绍"<<endl;
			cin>>newInfo;	
			strcpy(graph->vertices[s].name, newName);
			strcpy(graph->vertices[s].info, newInfo);
			cout<<"修改名称和介绍成功"<<endl;
			return ;
			break;
		default:
                cout<<"无效的选择，请重新输入"<<endl;
            break;
}
     return ;
}
 
// 删除一个景点及其相关信息
int removeVertex(Map& graph, char* name) {
    int s=findVertexIndex(graph, name);
    if(s==-1){
        return ERROR;
    }
    
    
    for(int i=0;i<graph->numVertices;i++){
    	for(int j=0;j<2;j++){
    	if(graph->edges[s][i].length[j]<MaxInt){
    		graph->edges[s][i].length[j]=MaxInt;
    		graph->edges[i][s].length[j]=MaxInt;
		}
	}
	}
	 
    //删除这个顶点的话就把graph->vertices数组里面的顶点从当前位置开始把后面的往前挪一个
    for (int i = s; i < graph->numVertices - 1; i++) {
        strcpy(graph->vertices[i].name, graph->vertices[i + 1].name);
        strcpy(graph->vertices[i].info, graph->vertices[i + 1].info);
    }
    
    graph->numVertices--; // 顶点数量减一

    return OK;
}

// 删除一条路径
void removeEdge(Map& graph, char* start, char* end,int type) {
    int u=findVertexIndex(graph, start);
    int v=findVertexIndex(graph, end);
    if(u==-1&&v==-1){
        //说明没有这两个景点
        cout<<"没有这两个景点"<<endl;
        return ;
    }else if(u==-1){
        cout<<"不存在"<<start<<endl;
        return ;
    }else if(v==-1){
        cout<<"不存在"<<end<<endl;
        return ;
    }else if(graph->edges[u][v].length[type]==MaxInt){
    	cout<<"不存在此路径"<<endl;
    	return ;
	}
    //有这两个景点的话就直接把这两条边的的值和类型都变为初始值
    //变为跟init函数里面一样
    graph->edges[u][v].length[type] = MaxInt;
    graph->numedge[type]--;
    cout<<"删除此路径成功"<<endl;
    return ;
}

//dfs遍历图
void dfs(Map& graph, int vertexIndex, char* end, bool visited[],int type) {
    visited[vertexIndex] = true;
    // 如果当前顶点是终点，则找到了游览线路
    if (strcmp(graph->vertices[vertexIndex].name, end) == 0) {
        cout<<graph->vertices[vertexIndex].name<<endl;
        cout<<"景点介绍"<<graph->vertices[vertexIndex].info<<endl;
        return;
    }
    cout<< graph->vertices[vertexIndex].name<<endl;
    cout<<"景点介绍"<<graph->vertices[vertexIndex].info<<endl;
    // 遍历当前顶点的邻接顶点
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[vertexIndex][i].length[type] != MaxInt && !visited[i]) {
            dfs(graph, i, end, visited,type);
        }
    }
}

//给出从起始到结束的所有景点   校园游览线路
void planTour(Map& graph, char* start,char* halfway ,char* end,int type) {
   int u = findVertexIndex(graph, start);
   int w= findVertexIndex(graph,halfway);
   int v = findVertexIndex(graph, end); 
   bool visited[MAX_VERTICES] = {false};
    printf("路线从起点 %s 途经 %s 到终点 %s: ", start, halfway,end)<<endl; 
	dfs(graph, u, halfway, visited,type); 
	dfs(graph,w,end,visited,type);
	cout<<endl; 
}



// 修改后的深度优先搜索
void dfsAvoidPath(Map& graph, int vertexIndex, char* end, bool visited[], int avoidStart, int avoidEnd,int type) {
    visited[vertexIndex] = true;
    if (strcmp(graph->vertices[vertexIndex].name, end) == 0) {
        cout<<graph->vertices[vertexIndex].name<<endl;
        cout<<"景点介绍"<<graph->vertices[vertexIndex].info<<endl;
        return;
    }
    cout<<graph->vertices[vertexIndex].name<<endl;
    cout<<"景点介绍"<<graph->vertices[vertexIndex].info<<endl;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[vertexIndex][i].length[type] != MaxInt && !visited[i] && (vertexIndex != avoidStart || i != avoidEnd) && (i != avoidStart || vertexIndex != avoidEnd)) {
            dfsAvoidPath(graph, i, end, visited, avoidStart, avoidEnd,type);
        }
    }
}

// 避开路径的校园游览线路规划
void planTourAvoidPath(Map& graph, char* start, char* end, char* avoid1, char* avoid2,int type) {
    int startIdx = findVertexIndex(graph, start);
    int endIdx = findVertexIndex(graph, end);
    int avoid1Idx = findVertexIndex(graph, avoid1);
    int avoid2Idx = findVertexIndex(graph, avoid2);
    bool visited[MAX_VERTICES] = {false};
    printf("游行起点从%s 到 %s 避免路径 %s 到 %s: ", start, end, avoid1, avoid2)<<endl;
    dfsAvoidPath(graph, startIdx, end, visited, avoid1Idx, avoid2Idx,type);
    cout<<endl;
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
        int minDist = MaxInt;
        int u = startIdx;
        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        visited[u] = true;
        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->edges[u][j].length[type] < MaxInt) {
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
    printf("最短路径从 %s 到 %s: ", start, end)<<endl;
    for (int i = pathLength - 1; i >= 0; i--) {
        cout<<graph->vertices[path[i]].name<<endl;
        cout<<"景点介绍"<<graph->vertices[path[i]].info<<endl;
    }
    cout<<endl;
}

#endif /* GRAPH_H */
