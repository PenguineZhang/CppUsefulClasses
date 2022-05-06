#include "DataStructures.hpp"

/*******************   Trie   *******************/
Trie::Trie()
{

}

Trie::~Trie()
{

}

/*******************   Union Find for std::pair data  *******************/
DisjointSet::DisjointSet(std::vector<std::pair<int, int>>& data)
{
    for(std::pair<int, int>& d: data){
        parents[d] = d;
        rank[d] = 0;
    }
}

DisjointSet::DisjointSet(std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash_fn>& data)
{
    parents = data;
}

DisjointSet::~DisjointSet()
{

}

std::pair<int, int> DisjointSet::Find(std::pair<int, int> x)
{
    if(x != parents[x]){
        parents[x] = Find(parents[x]);
    }

    return parents[x];
}

void DisjointSet::Union(std::pair<int, int> x, std::pair<int, int> y)
{
    std::pair<int, int> px = Find(x);
    std::pair<int, int> py = Find(y);

    if(rank[px] > rank[py]){
        parents[py] = px;
    }else if(rank[px] < rank[py]){
        parents[px] = py;
    }else{
        parents[py] = px;
        rank[px]++;
    }
}