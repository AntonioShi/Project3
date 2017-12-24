//
// Created by antonio on 17-12-23.
//

#ifndef PROJECT3_ADJLIST_H
#define PROJECT3_ADJLIST_H

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "RawColWeight.h"
using namespace std ;

typedef char DataType ;

typedef struct Node {
    int arcHead;	           //弧头顶点序号
    int weight ;                /*权值*/
} Edge;		            /*邻接边单链表的结点结构体*/

typedef struct {
    DataType data;		/*顶点数据元素*/
    int source;		    /*邻接边的弧尾顶点序号*/
    list <Edge> adjEdge;	/*邻接边*/
} AdjGraph;	     	/*数组的数据元素类型结构体*/


class AdjList{
private:
    int MaxVertices ;
    const int MaxWeight ;
    vector <AdjGraph> adjGraph;		/*邻接表*/
    vector <AdjGraph> ::iterator it ;
    int numOfVerts;			/*顶点个数*/
    int numOfEdges;			/*边个数*/

public:
    AdjList():MaxWeight(1000){
        MaxVertices = 8 ;//
        numOfEdges = 0 ;
        numOfVerts = 0 ;
        it = adjGraph.begin() ;//
    }
    ~AdjList(){
        MaxVertices = 0 ;//
        numOfEdges = 0 ;
        numOfVerts = 0 ;
    }

    void AdjInitiate() ;

    void InsertVertex(int i, DataType vertex) ;

    void InsertEdge(int v1, int v2, int weight) ;

    void DeleteEdge(int v1, int v2) ;

    int GetFirstVex(int v) ;

    int GetNextVex(int v1, int v2) ;

    void AdjDestroy() ;

    void CreateGraph(DataType v[], int n, RawColWeight d[], int e) ;

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

#endif //PROJECT3_ADJLIST_H
