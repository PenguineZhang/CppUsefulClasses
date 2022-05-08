#include "DataStructures.hpp"


/*******************   Trie   *******************/
Trie::Trie()
{

}

Trie::~Trie()
{

}

/*******************   Union Find for Point data  *******************/
DisjointSet::DisjointSet(std::vector<Point>& data)
{
    for(Point& d: data){
        parents[d] = d;
        rank[d] = 0;
    }
}

DisjointSet::~DisjointSet()
{

}

Point DisjointSet::Find(Point x)
{
    if(x != parents[x]){
        parents[x] = Find(parents[x]);
    }

    return parents[x];
}

void DisjointSet::Union(Point x, Point y)
{
    Point px = Find(x);
    Point py = Find(y);

    if(rank[px] > rank[py]){
        parents[py] = px;
    }else if(rank[px] < rank[py]){
        parents[px] = py;
    }else{
        parents[py] = px;
        rank[px]++;
    }
}