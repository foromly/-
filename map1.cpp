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
        cout<<"1. 从文件中读入景点"<<endl;
        cout<<"2. 输出景点到文件"<<endl;
        cout<<"3. 计划校园游览线路"<<endl;
        cout<<"4. 绕行"<<endl;
        cout<<"5. 添加一个景点"<<endl;
		cout<<"6. 删除一个景点"<<endl;
		cout<<"7. 修改一个景点信息"<<endl; 
		cout<<"8. 增加一个新的路径"<<endl;
		cout<<"9. 删除一个路径" <<endl;
		cout<<"10. 备选路线"<<endl;
        cout<<"11. 退出"<<endl;
        cout<<"请输入您的选择：";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"请输入文件名："<<endl;
                scanf("%s", filename);
                loadVerticesFromFile(graph, filename);
                break;
            case 2:
                cout<<"请输入文件名："<<endl;
                scanf("%s", filename);
                saveVerticesToFile(graph, filename);
                break;
            case 3:
                cout<<"请输入起点："<<endl;
                scanf("%s", start);
                cout<<"请输入途经点："<<endl;
                scanf("%s", wayPoint);
                cout<<"请输入终点："<<endl;
                scanf("%s", end);
                planTour(graph, start, wayPoint, end);
                break;
            case 4:
                cout<<"请输入要绕行的起点："<<endl;
                scanf("%s", avoidStart);
                cout<<"请输入要绕行的终点："<<endl;
                scanf("%s", avoidEnd);
                avoidPath(graph, avoidStart, avoidEnd);
                break;
            case 5:
            	cout<<"请输入要增加景点的名称"<<endl;
            	scanf("%s",name);
            	cout<<"请输入要增加景点的信息"<<endl;
				 scanf("%s",info);
				addNewVertex(graph,name,info);
                cout<<"增加成功"<<endl; 
				break;
            case 6:
            	cout<<"请输入删除景点名称: "<<endl;
            	scanf("%s",name);
                judge=removeVertex(graph,name);
                if(judge==1){
                	cout<<"景点删除成功"<<endl; 
				}else{
					cout<<"景点删除失败"<<endl;
				}
				break;
			case 7:
				cout<<"请输入要修改景点的名称"<<endl;
				 scanf("%s",name);
				judge=updateVertexInfo(graph,name);
				if(judge==1){
                	cout<<"修改成功"<<endl; 
				}else{
					cout<<"未找到此景点"<<endl;
				}
				break;
			case 8:
				cout<<"请输入起点"<<endl;
				 scanf("%s", start);
				 cout<<"请输入终点"<<endl;
				 scanf("%s", end);
				 cout<<"请输入路径长度"<<endl;
				 cin>>length;
				 cout<<"请输入路径类型" <<endl; 
				 cin>>type;
				addNewEdge(graph,start,end,length,type);
				cout<<"添加成功" <<endl;
			case 9:
				cout<<"请输入起点"<<endl;
				 scanf("%s", start);
				 cout<<"请输入终点"<<endl;
				 scanf("%s", end);
				judge=removeEdge(graph,start,end);
				if(judge==1){
                	cout<<"路径删除成功"<<endl; 
				}else{
					cout<<"路径删除失败"<<endl;
				}
				break;
			case 10:
				
				break; 
            case 11:
                cout<<"谢谢使用，再见！\n";
                break;
            default:
                cout<<"无效的选择，请重新输入。\n";
        }
    } while (choice != 5);

    // 释放图的内存
    //destroyGraph(graph);

    return 0;
}

