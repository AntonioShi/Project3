#include <iostream>
#include <queue>
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Prim.h"

/* 带权图分为有向和无向，
 * 无向图的最短路径又叫做最小生成树，
 * 有prime算法和kruskal算法；
 * 有向图的最短路径算法有dijkstra算法和floyd算法。
 */
using namespace std ;

void Visit(DataType it) {
        cout  << it  << setw(4);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMatrix g1;
    vector <DataType > a ;
    for (int i = 0; i < 7; ++i) {
        a.push_back('A' + i) ;
    }
    RawColWeight rcw[] = {{0,1,50}, {1,0,50},
                          {0,2,60}, {2,0,60},
                          {1,3,65}, {3,1,65},
                          {1,4,40}, {4,1,40},
                          {2,3,52}, {3,2,52},
                          {2,6,45}, {6,2,45},
                          {3,4,50}, {4,3,50},
                          {3,5,30}, {5,3,30},
                          {3,6,42}, {6,3,42},
                          {4,5,70}, {5,4,70},
                          {5,6,50}, {6,5,50}
    };
    int n = 7, e = 22;
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
    graph.CreateGraph(v, n, rcw, e) ;

    graph.Display() ;
    cout << "邻接链表的深度优先遍历" << endl ;
    graph.DepthFirstSearch(Visit) ;
    cout << "\n邻接链表的广度优先遍历" << endl ;
    graph.BroadFirstSearch(Visit) ;


    cout << endl << endl ;
    MinSpanTree closeVertex[8] ;
    Prim(g1, closeVertex) ;
    cout << "初始顶点 = " << closeVertex[0].vertex << endl;
    for (int i = 1; i < 7; ++i) {
        cout << "顶点 = " << closeVertex[i].vertex << "   边的权值 = " << closeVertex[i].weight << endl ;
    }
    return 0;
}