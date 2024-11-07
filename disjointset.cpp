#include <vector>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> parent, rank;

public:
    // Initialize the DSU with `n` elements
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Union by rank
    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
            } else {
                parent[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }
};

// Example usage:
// DisjointSetUnion dsu(5);
// dsu.union_sets(0, 1);
// dsu.union_sets(1, 2);
// bool connected = (dsu.find(0) == dsu.find(2)); // true since 0 and 2 are connected
