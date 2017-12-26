//
// Created by antonio on 17-12-26.
//

#ifndef PROJECT3_PRIM_H
#define PROJECT3_PRIM_H

#include "AdjMatrix.h"
using namespace std ;

//普里姆算法的时间复杂度为n*n，实际运行时间与点的个数有关，与边无关

typedef struct {
    int weight ;
    DataType vertex ;//顶点
}MinSpanTree;

//普里姆算法生成最小生成树的关键是：从两个点的集合中找权值对小的边
void Prim(AdjMatrix G, MinSpanTree closeVertex[]){
    //用普里姆算法建立带权图G的最小生成树closeVertex
    DataType x ;
    vector <DataType > vList = G.Getvec();//dian
    int **edge = G.GetEdge() ;//bian
    int n= vList.size(), k = 0, MaxWeight = G.GetMaxWeight();
    int minCost ;//min weight index
    int *lowCost = new int [n];

    for (int i = 1; i < n; ++i) {
        lowCost[i] = edge[0][i] ;//初始化
    }
    x = vList[0] ;//

    closeVertex[0].vertex = x ;//保存顶点
    lowCost[0] = -1 ;//标记顶点

    for (int i = 1; i < n; ++i) {
        minCost = MaxWeight ;//最大权值
        for (int j = 1; j < n; ++j) {
            if (lowCost[j] < minCost && lowCost[j] > 0){
                minCost = lowCost[j] ;
                k = j ;
            }
        }

        x = vList[k];

        closeVertex[i].vertex = x ;//
        closeVertex[i].weight = minCost ;//
        lowCost[k] = -1 ;//
        //
        for (int j = 1; j < n; ++j) {//根据加入集合U的顶点k修改lowCost中的数值
            if (edge[k][j] < lowCost[j])
                lowCost[j] = edge[k][j] ;
        }
    }
}
#endif //PROJECT3_PRIM_H
