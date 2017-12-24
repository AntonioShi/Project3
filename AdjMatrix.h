//
// Created by antonio on 17-12-21.
//

#ifndef PROJECT3_ADJMGRAPH_H
#define PROJECT3_ADJMGRAPH_H
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include "RawColWeight.h"

typedef char DataType ;
using namespace std ;


//邻接矩阵的类
class AdjMatrix{
private:
        vector<DataType> vList ;//点的列表
        int **edge;//边的二维数组

        const int MaxWeight ;
        int MaxVertices ;
        vector <DataType > ::iterator it ;//迭代器
        int numOfEdges ;//边数

public:

    AdjMatrix() :MaxWeight(1000){
        //初始化
        edge = new int *[MaxVertices] ;
        for (int i = 0; i < MaxVertices; ++i) {
            edge[i] = new int [MaxVertices] ;
        }
        it = vList.begin() ;
        MaxVertices = 8 ;//8个点
        numOfEdges = 0 ;//0条边
    }
    ~AdjMatrix() {
        numOfEdges = 0 ;
        for (int i = 0; i < MaxVertices; i++)
        {
            delete[] edge[i];
            edge[i] = nullptr;
        }
        delete[] edge;
        edge = nullptr;
    }

    void Initiate(int **edge, int n) ;

    void InsertVertex(DataType vertex) ;

    void InsertEdge(int v1, int v2, int weight) ;

    void CreatGraph(vector<DataType >V, RawColWeight E[], int e) ;

    void DeleteEdge(int v1, int v2) ;

    int GetFirstVex(int v) ;

    int GetNextVex(int v1, int v2) ;


    //连通图G以v为初始顶点、访问操作为Visit（）的深度优先遍历
    void DepthFSearch(int v, int visited[], void Visit(DataType item)) ;

    //非连通图的深度优先遍历
    //可能存在孤立点等连通分支
    //考虑情况比较复杂
    //非连通图的深度优先 可耻的调用了连通图的深度优先访问
    void DepthFirstSearch(void Visit(DataType item)) ;

    //连通图的广度优先遍历
    //图的广度优先遍历是一个分层搜索的过程
    void BroadFSearch(int v, int visited[], void Visit(DataType item)) ;

    //非连通图的广度优先遍历
    void BroadFirstSearch(void Visit(DataType item)) ;

    void Display() ;
};

#endif //PROJECT3_ADJMGRAPH_H
