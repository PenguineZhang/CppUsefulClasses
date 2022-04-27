#include <vector>

class Trie
{
    public:
        Trie();
        ~Trie();
};

template <typename T>
class DisjointSet
{
    public:
        DisjointSet();
        ~DisjointSet();
        T Find(T);
        void Union();

        struct Node{
            T val;
            T* parent;
        };

    private:
        std::vector<int> ranks;
        std::vector<T> parents;
};