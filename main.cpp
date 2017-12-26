#include <iostream>
#include <queue>
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Prim.h"

using namespace std ;

void Visit(DataType it) {
        cout  << it  << setw(4);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMatrix g1;
    vector <DataType > a ;
    for (int i = 0; i < 8; ++i) {
        a.push_back('A' + i) ;
    }
    RawColWeight rcw[] = {{0,1,10}, {0,4,20}, {1,3,30}, {2,1,40},
                          {3,2,50}, {1,4,30}, {2,3,40}, {3,4,50}};
    int n = 8, e = 8;
    g1.CreatGraph(a, rcw, e);

    g1.Display() ;
    cout << endl ;
    cout << "邻接矩阵深度优先遍历" << endl ;
    g1.DepthFirstSearch(Visit) ;
    cout << "\n邻接矩阵广度优先遍历" << endl ;
    g1.BroadFirstSearch(Visit) ;

    cout << endl << endl ;

    AdjList graph ;
    DataType v[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    graph.CreateGraph(v, 8, rcw, 8) ;

    graph.Display() ;
    cout << "邻接链表的深度优先遍历" << endl ;
    graph.DepthFirstSearch(Visit) ;
    cout << "\n邻接链表的广度优先遍历" << endl ;
    graph.BroadFirstSearch(Visit) ;

    cout << endl << endl ;
    MinSpanTree closeVertex[8] ;
    Prim(g1, closeVertex) ;
    cout << "初始顶点 = " << closeVertex[0].vertex << endl;
    for (int i = 1; i < 8; ++i) {
        cout << "顶点 = " << closeVertex[i].vertex << "   边的权值 = " << closeVertex[i].weight << endl ;
    }
    return 0;
}