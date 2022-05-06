#include <vector>
#include <unordered_map>
#include <utility>


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
            template <typename T1, typename T2>
            std::size_t operator() (const std::pair<T1, T2>& p) const
            {
                std::size_t h1 = std::hash<T1>()(p.first);
                std::size_t h2 = std::hash<T2>()(p.second);
                return h1 ^ h2;
            }
        };

    public:
        DisjointSet() = delete;
        DisjointSet(std::vector<std::pair<int, int>>& data);
        DisjointSet(std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash_fn>&);
        ~DisjointSet();
        std::pair<int, int> Find(std::pair<int, int>);
        void Union(std::pair<int, int>, std::pair<int, int>);

        

    private:
        std::unordered_map<std::pair<int, int>, int, hash_fn> rank;
        std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash_fn> parents;
};