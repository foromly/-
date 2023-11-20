#include <iostream>
#include "邻接矩阵法头文件.h"
using namespace std;

int main() {
    // 声明并分配内存给图
    Map graph = new Graph;

    // 初始化图
    initializeGraph(graph);
    int choice,judge,length,type;
    char filename[100];
    char start[100];
    char wayPoint[100];
    char end[100];
    char avoidStart[100];
    char avoidEnd[100];
    char name[100];
    char info[100];

    do {
        cout<<"====== 校园导航系统菜单 ======"<<endl;
        cout<<"1. 给出校园游览线路"<<endl;
        cout<<"2. 绕行"<<endl;
        cout<<"3. 添加一个景点"<<endl;
		cout<<"4. 删除一个景点"<<endl;
		cout<<"5. 修改一个景点信息"<<endl; 
		cout<<"6. 增加一个新的路径"<<endl;
		cout<<"7. 删除一个路径" <<endl;
		cout<<"8. 选择最短路径"<<endl;
        cout<<"9. 退出"<<endl;
        cout<<"请输入您的选择：";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"请输入起点："<<endl;
                scanf("%s", start);
                cout<<"请输入途经点："<<endl;
                scanf("%s", wayPoint);
                cout<<"请输入终点："<<endl;
                scanf("%s", end);
                cout<<"请输入你选择游行的方式"<<endl;
                cin>>type;
                planTour(graph, start, wayPoint, end,type);
                break;
            case 2:
                cout<<"请输入要绕行的起点："<<endl;
                scanf("%s", avoidStart);
                cout<<"请输入要绕行的终点："<<endl;
                scanf("%s", avoidEnd);
                avoidPath(graph, avoidStart, avoidEnd);
                break;
            case 3:
            	cout<<"请输入要增加景点的名称"<<endl;
            	scanf("%s",name);
            	cout<<"请输入要增加景点的信息"<<endl;
				 scanf("%s",info);
				judge=addNewVertex(graph,name,info);
				if(judge=-1){
					cout<<"已超过景点最大数量无法添加"<<endl;
				}else{
                cout<<"增加成功"<<endl; 
                }
				break;
            case 4:
            	cout<<"请输入删除景点名称: "<<endl;
            	scanf("%s",name);
                judge=removeVertex(graph,name);
                if(judge==-1){
                	cout<<"景点不存在,删除失败"<<endl; 
				}else{
					cout<<"景点删除成功"<<endl;
				}
				break;
			case 5:
				cout<<"请输入要修改景点的名称"<<endl;
				 scanf("%s",name);
				updateVertexInfo(graph,name);
				break;
			case 6:
				cout<<"请输入起点"<<endl;
				 scanf("%s", start);
				 cout<<"请输入终点"<<endl;
				 scanf("%s", end);
				 cout<<"请输入路径长度"<<endl;
				 cin>>length;
				 cout<<"请输入路径类型" <<endl; 
				 cin>>type;
				addNewEdge(graph,start,end,length,type);
			case 7:
				cout<<"请输入起点"<<endl;
				 scanf("%s", start);
				 cout<<"请输入终点"<<endl;
				 scanf("%s", end);
				 cout<<"请输入你要选择删除的边的类型(1.走路，2.坐车)";
				 cin>>type;
				removeEdge(graph,start,end,type);
				break;
			case 8:
				cout<<"请输入起点"<<endl;
				 scanf("%s", start);
				 cout<<"请输入终点"<<endl;
				 scanf("%s", end);
				 cout<<"请输入你要选择游行的类型(1.走路，2.坐车)";
				 cin>>type;
				findShortestPath(graph, start, end,type); 
				break; 
            case 9:
                cout<<"谢谢使用，再见！";
                break;
            default:
                cout<<"无效的选择，请重新输入";
        }
    } while (choice != 9);

    // 释放图的内存
    //destroyGraph(graph);

    return 0;
}
