//
// Created by antonio on 17-12-21.
//

#include "AdjMatrix.h"


void AdjMatrix::CreatGraph(vector<DataType >V, RawColWeight E[], int e) {
    int i, k ;
    Initiate(edge, V.size()) ;

    for (vector<DataType >::iterator it = V.begin(); it != V.end(); it ++) {
        InsertVertex(*it) ;
    }

    for (int k = 0; k < e; ++k) {
        InsertEdge(E[k].raw, E[k].col, E[k].weight) ;
    }

}

void AdjMatrix::InsertEdge(int v1, int v2, int weight) {
    if (v1 < 0 || v1 > vList.size()){
        cout << "参数v1, 或者v2越界啦" << endl ;
        exit(0) ;
    }
    edge[v1][v2] = weight ;
    numOfEdges ++ ;
}

void AdjMatrix::InsertVertex(DataType vertex) {
    vList.push_back(vertex) ;
}

void AdjMatrix::Initiate(int **edge, int n) {


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                edge[i][j] = 0 ;
            else
                edge[i][j] = MaxWeight ;//MaxWeight视为无穷大
        }
    }
    numOfEdges = 0 ;//边的条数0
}

int AdjMatrix::GetFirstVex(int v) {
    if (v < 0 || v > vList.size()){
        cout << "参数v1, 或者v2越界啦" << endl ;
        exit(0) ;
    }

    for (int col = 0; col <= vList.size(); ++col) {
        if (edge[v][col] > 0 && edge[v][col] < MaxWeight)
            return col ;
    }
    return -1 ;
}

int AdjMatrix::GetNextVex(int v1, int v2) {
    //在图中寻找V1顶点的邻接顶点V2的下一个邻接顶点
    //如果这样的邻接顶点存在，则返回该邻接顶点的序号，否则返回-1
    if (v1 < 0 || v1 > vList.size() || v2 < 0 || v2 > vList.size()){
        cout << "参数v1, 或者v2越界啦" << endl ;
        exit(0) ;
    }

    for (int col = v2 + 1; col <= vList.size(); ++col) {
        if (edge[v1][col] > 0 && edge[v1][col] < MaxWeight)
            return col ;
    }
    return -1 ;
}

void AdjMatrix::DeleteEdge(int v1, int v2) {
    //在图中取消一条有向边
    if(v1 < 0 || v1 > vList.size() || v2 < 0
       ||  v2 > v1 > vList.size() || v1 == v2) {
        printf("参数v1或v2越界出错!\n");
        exit(1);
    }

    if(edge[v1][v2] == MaxWeight || v1 == v2) {
        printf("该边不存在!\n");
        exit(0);
    }

    edge[v1][v2] = MaxWeight;
    numOfEdges--;
}

void AdjMatrix::DepthFSearch(int v, int visited[], void Visit(DataType item)) {
    //从v为起始点，w作为v的第一个临接顶点，
    // visited数组标记相应顶点是否已被访问（0未访问 1已访问）
    Visit(vList[v]) ;//访问v顶点
    visited[v] = 1 ;

    int w = GetFirstVex(v) ;//取第一个临接顶点

    while (w != -1){//存在性问题
        if (! visited[w]){//如果未访问，则访问
            DepthFSearch(w, visited, Visit) ;//递归
        }
        w = GetNextVex(v, w) ;//取下一个临接顶点
    }
}

void AdjMatrix::DepthFirstSearch(void (*Visit)(DataType)) {
    int *visited = (int *)malloc(sizeof(int) * vList.size()) ;
    int i ;
    for (i = 0; i < vList.size(); ++i) {
        visited[i] = 0 ;//访问标记初始为0
    }
    for (i = 0; i < vList.size(); ++i) {
        if (! visited[i]){//未访问
            DepthFSearch(i, visited, Visit) ;//以每个顶点为初始顶点进行调用
        }
    }
    free(visited) ;//
}

void AdjMatrix::BroadFSearch(int v, int *visited, void (*Visit)(DataType)) {
    int  w ;
    int u ;
    queue<int > cqueue ;
    Visit(vList[v]) ;//访问v
    visited[v] = 1 ;//访问标记

    cqueue.push(v) ;

    while (cqueue.empty()){//若队列非空
        u = cqueue.front() ;
        cqueue.pop();//出队列u
        w = GetFirstVex(u) ;//取u的第一个临接顶点w

        while (w != -1){//若w存在
            if (! visited[w]){//且没有被访问过

                Visit(vList[w]) ;//访问
                visited[w] = 1 ;//标记
                cqueue.push(w) ;//添加w入队
            }
            w = GetNextVex(u, w) ;//取下一个临接顶点
        }
    }
}

void AdjMatrix::BroadFirstSearch(void (*Visit)(DataType)) {
    int i ;
    int *visited = (int *)malloc(sizeof(int) * vList.size()) ;

    for (i = 0; i < vList.size(); ++i) {
        visited[i] = 0 ;//未访问标记
    }
    for (i = 0; i < vList.size(); ++i) {
        if (! visited[i])//未访问
            BroadFSearch(i, visited, Visit) ;//可耻的调用连通图的广度优先，嘿嘿
    }
    free(visited) ;
}

void AdjMatrix::Display() {
    int i, j;
    printf("顶点集合为：");
    for(i = 0; i < vList.size(); i++)
        cout << setw(4) << vList[i] ;
    printf("\n");
    printf("权值集合为：\n");

    for(i = 0; i < vList.size(); i++) {
        for(j = 0; j < vList.size(); j++)
            cout << setw(6) << edge[i][j] ;
        printf("\n");
    }
}

int **AdjMatrix::GetEdge() {
    return edge;
}

int AdjMatrix::GetMaxWeight() {
    return MaxWeight;
}


int AdjMatrix::GetNumOfEdges() {
    return numOfEdges   ;
}


vector<DataType> AdjMatrix::Getvec() {
    return vector<DataType>(vList);
}



