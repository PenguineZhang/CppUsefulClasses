#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <vector>
#include <unordered_map>

struct Point
{
    int x, y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

static bool operator==(const Point& lhs, const Point& rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

static bool operator!=(const Point& lhs, const Point& rhs){
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

class Trie
{
    public:
        Trie();
        ~Trie();
};



class DisjointSet
{
    struct hash_fn
    {   
        std::size_t operator() (const Point& p) const
        {
            std::size_t h1 = std::hash<int>()(p.x);
            std::size_t h2 = std::hash<int>()(p.y);
            return h1 ^ h2;
        }
    };

    public:
        DisjointSet() = delete;
        DisjointSet(std::vector<Point>& data);
        ~DisjointSet();
        Point Find(Point);
        void Union(Point, Point);

        

    private:
        std::unordered_map<Point, int, hash_fn> rank;
        std::unordered_map<Point, Point, hash_fn> parents;
};

#endif // DATA_STRUCTURES