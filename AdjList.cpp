//
// Created by antonio on 17-12-23.
//
#include <queue>
#include <iomanip>
#include "AdjList.h"

using namespace std;

void AdjList::AdjInitiate() {

    for (int i = 0; i < MaxVertices; ++i) {
        adjGraph[i].source = i;//弧头下标
    }
}

void AdjList::InsertVertex(int i, DataType vertex) {
    AdjGraph adj;
    adj.data = vertex;

    if (i >= 0 && i < MaxVertices) {
        adjGraph.push_back(adj);
        numOfVerts++;
    } else
        printf("顶点越界!");
    return ;
}

void AdjList::InsertEdge(int v1, int v2, int weight) {

    if (v1 < 0 || v1 > numOfVerts || v2 < 0 || v2 > numOfVerts) {
        printf("参数v1或v2出错!");
        return;
    }
    Edge adjNode;
    adjNode.arcHead = v2;
    adjNode.weight = weight;

    list<Edge>::iterator p;
    p = adjGraph[v1].adjEdge.begin();
    //遍历链表，找出插入点
    while (p != adjGraph[v1].adjEdge.end()) {
        if (p->arcHead > v2) {
            break;
        }
        p++;
    }
    adjGraph[v1].adjEdge.insert(p, adjNode);
    numOfEdges++;
}


void AdjList::DeleteEdge(int v1, int v2) {
    list<Edge>::iterator p;

    p = adjGraph[v1].adjEdge.begin();

    while (p != adjGraph[v1].adjEdge.end()) {
        if (p->arcHead == v2) {
            adjGraph[v1].adjEdge.erase(p);
            break;
        }
        p++;
    }
}

int AdjList::GetFirstVex(int v) {
    if (v < 0 || v > numOfVerts) {
        printf("顶点越界!");
        return -1;

    }
    list<Edge>::iterator p = adjGraph[v].adjEdge.begin();

    if (p != adjGraph[v].adjEdge.end())
        return p->arcHead;
    else return -1;
}

int AdjList::GetNextVex(int v1, int v2) {
    if (v1 < 0 || v1 > numOfVerts || v2 < 0 || v2 > numOfVerts) {
        printf("越界");
        return -1;
    }
    list<Edge>::iterator p = adjGraph[v1].adjEdge.begin();

    while (p != adjGraph[v1].adjEdge.end()) {
        if (p->arcHead != v2) {
            p++;
            continue;
        } else
            break;
    }

    p++;
    if (p != adjGraph[v1].adjEdge.end())
        return p->arcHead;
    else
        return -1;
}

void AdjList::AdjDestroy() {
    int i;
    list<Edge>::iterator p, q;

    for (i = 0; i < numOfVerts; i++) {
        p = adjGraph[i].adjEdge.begin();
        while (p != adjGraph[i].adjEdge.end()) {
            q = p;
            p++;
            adjGraph[i].adjEdge.erase(q);

        }
    }
}

void AdjList::CreateGraph(DataType *v, int n, RawColWeight *d, int e) {
    for (int i = 0; i < n; ++i) {
        InsertVertex(i, v[i]);
    }
    for (int j = 0; j < n; ++j) {
        InsertEdge(d[j].raw, d[j].col, d[j].weight);//
    }

}

void AdjList::Display() {
    list<Edge>::iterator p;
    printf("顶点集合为：");
    for (int i = 0; i < numOfVerts; ++i) {
        printf("%c ", adjGraph[i].data);
    }
    printf("\n");
    printf("权值集合：\n");
    for (int i = 0; i < numOfVerts; ++i) {
        p = adjGraph[i].adjEdge.begin();
        while (p != adjGraph[i].adjEdge.end()) {
            cout << setw(4) << p->weight;
            p++;
        }
    }
    cout << endl ;
}

void AdjList::DepthFSearch(int v, int *visited, void (*Visit)(DataType)) {
    Visit(adjGraph[v].data);
    visited[v] = 1;

    int w = GetFirstVex(v);
    while (w != -1) {
        if (!visited[w]) {
            DepthFSearch(w, visited, Visit);
        }
        w = GetNextVex(v, w);
    }
}

void AdjList::DepthFirstSearch(void (*Visit)(DataType)) {
    int *visited = new int[numOfVerts];

    for (int i = 0; i < numOfVerts; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < numOfVerts; ++i) {
        if (!visited[i]) {
            DepthFSearch(i, visited, Visit);
        }

    }
    //delete visited ;
}

void AdjList::BroadFSearch(int v, int *visited, void (*Visit)(DataType)) {
    int u, w;
    queue<int> cqueue;
    Visit(adjGraph[v].data);//访问v
    visited[v] = 1;//访问标记

    cqueue.push(v);

    while (cqueue.empty()) {//若队列非空
        u = cqueue.front();
        cqueue.pop();//出队列u
        w = GetFirstVex(u);//取u的第一个临接顶点w

        while (w != -1) {//若w存在
            if (!visited[w]) {//且没有被访问过

                Visit(adjGraph[w].data);//访问
                visited[w] = 1;//标记
                cqueue.push(w);//添加w入队
            }
            w = GetNextVex(u, w);//取下一个临接顶点
        }
    }
}

void AdjList::BroadFirstSearch(void (*Visit)(DataType)) {
    int i;
    int *visited = new int[numOfVerts];

    for (i = 0; i < numOfVerts; ++i) {
        visited[i] = 0;//未访问标记
    }
    for (i = 0; i < numOfVerts; ++i) {
        if (!visited[i])//未访问
            BroadFSearch(i, visited, Visit);//可耻的调用连通图的广度优先，嘿嘿
    }
    delete visited;
}

int AdjList::GetVerx() {
    return numOfVerts;
}

int AdjList::GetEdge() {
    return numOfEdges;
}

