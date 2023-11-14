#include <iostream>
#include "�ڽӾ���ͷ�ļ�.h"
using namespace std;

int main() {
    // �����������ڴ��ͼ
    Map graph = new Graph;

    // ��ʼ��ͼ
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
        cout<<"====== У԰����ϵͳ�˵� ======"<<endl;
        cout<<"1. ���ļ��ж��뾰��"<<endl;
        cout<<"2. ������㵽�ļ�"<<endl;
        cout<<"3. �ƻ�У԰������·"<<endl;
        cout<<"4. ����"<<endl;
        cout<<"5. ���һ������"<<endl;
		cout<<"6. ɾ��һ������"<<endl;
		cout<<"7. �޸�һ��������Ϣ"<<endl; 
		cout<<"8. ����һ���µ�·��"<<endl;
		cout<<"9. ɾ��һ��·��" <<endl;
		cout<<"10. ��ѡ·��"<<endl;
        cout<<"11. �˳�"<<endl;
        cout<<"����������ѡ��";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"�������ļ�����"<<endl;
                scanf("%s", filename);
                loadVerticesFromFile(graph, filename);
                break;
            case 2:
                cout<<"�������ļ�����"<<endl;
                scanf("%s", filename);
                saveVerticesToFile(graph, filename);
                break;
            case 3:
                cout<<"��������㣺"<<endl;
                scanf("%s", start);
                cout<<"������;���㣺"<<endl;
                scanf("%s", wayPoint);
                cout<<"�������յ㣺"<<endl;
                scanf("%s", end);
                planTour(graph, start, wayPoint, end);
                break;
            case 4:
                cout<<"������Ҫ���е���㣺"<<endl;
                scanf("%s", avoidStart);
                cout<<"������Ҫ���е��յ㣺"<<endl;
                scanf("%s", avoidEnd);
                avoidPath(graph, avoidStart, avoidEnd);
                break;
            case 5:
            	cout<<"������Ҫ���Ӿ��������"<<endl;
            	scanf("%s",name);
            	cout<<"������Ҫ���Ӿ������Ϣ"<<endl;
				 scanf("%s",info);
				addNewVertex(graph,name,info);
                cout<<"���ӳɹ�"<<endl; 
				break;
            case 6:
            	cout<<"������ɾ����������: "<<endl;
            	scanf("%s",name);
                judge=removeVertex(graph,name);
                if(judge==1){
                	cout<<"����ɾ���ɹ�"<<endl; 
				}else{
					cout<<"����ɾ��ʧ��"<<endl;
				}
				break;
			case 7:
				cout<<"������Ҫ�޸ľ��������"<<endl;
				 scanf("%s",name);
				judge=updateVertexInfo(graph,name);
				if(judge==1){
                	cout<<"�޸ĳɹ�"<<endl; 
				}else{
					cout<<"δ�ҵ��˾���"<<endl;
				}
				break;
			case 8:
				cout<<"���������"<<endl;
				 scanf("%s", start);
				 cout<<"�������յ�"<<endl;
				 scanf("%s", end);
				 cout<<"������·������"<<endl;
				 cin>>length;
				 cout<<"������·������" <<endl; 
				 cin>>type;
				addNewEdge(graph,start,end,length,type);
				cout<<"��ӳɹ�" <<endl;
			case 9:
				cout<<"���������"<<endl;
				 scanf("%s", start);
				 cout<<"�������յ�"<<endl;
				 scanf("%s", end);
				judge=removeEdge(graph,start,end);
				if(judge==1){
                	cout<<"·��ɾ���ɹ�"<<endl; 
				}else{
					cout<<"·��ɾ��ʧ��"<<endl;
				}
				break;
			case 10:
				
				break; 
            case 11:
                cout<<"ллʹ�ã��ټ���\n";
                break;
            default:
                cout<<"��Ч��ѡ�����������롣\n";
        }
    } while (choice != 5);

    // �ͷ�ͼ���ڴ�
    //destroyGraph(graph);

    return 0;
}

