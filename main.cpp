#include "DataStructures.hpp"
#include <map>
#include <iostream>

int manhattanceDistance(Point& a, Point& b){
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

int main(int argc, char** argv)
{
    std::vector<Point> points;
    // points.emplace_back(0, 0);
    // points.emplace_back(2, 2);
    // points.emplace_back(3, 10);
    // points.emplace_back(5, 2);
    // points.emplace_back(7, 0);
    
    points.emplace_back(3, 12);
    points.emplace_back(-2, 5);
    points.emplace_back(-4, 1);
    

    DisjointSet ds(points);
    
    std::map<int, std::vector<std::vector<Point>>> dist;
    for(int i = 0; i < points.size(); ++i){
        for(int j = i+1; j < points.size(); ++j){
            int d = manhattanceDistance(points[i], points[j]);
            dist[d].push_back({points[i], points[j]});
        }
    }

    int cost = 0;
    for(auto& e: dist){
        for(auto& v: e.second){
            Point p1 = ds.Find(v[0]);
            Point p2 = ds.Find(v[1]);
            
            if(p1 != p2){
                ds.Union(v[0], v[1]);
                cost += e.first;
            }
        }
    }

    std::cout << "cost = " << cost << "\n";

    return 0;
}