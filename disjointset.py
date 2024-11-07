class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n  # Rank keeps track of the tree depth

    def find(self, x):
        # Path compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            # Union by rank
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1

# Example usage:
# Initialize a disjoint set with 5 elements (0 to 4)
ds = DisjointSet(5)
ds.union(0, 1)
ds.union(1, 2)
print(ds.find(2) == ds.find(0))  # True, since 0 and 2 are connected
print(ds.find(3) == ds.find(0))  # False, since 3 is not connected to 0
