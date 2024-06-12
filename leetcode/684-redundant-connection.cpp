/*
 *  Straight-forward DSU problem
 */
 
void make_set (int v, vector<int>& parent, vector<int>& size)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set (int v, vector<int>& parent, vector<int>& size)
{
    if (v == parent[v])
        return v;
    return find_set (parent[v], parent, size);
}

void union_sets (int a, int b, vector<int>& parent, vector<int>& size)
{
    a = find_set (a, parent, size);
    b = find_set (b, parent, size);
    
    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

class Solution
{
public:
    int getMaximumNodeValue (vector<vector<int>>& edges)
    {
        int r = -1;
        for (const auto& edge : edges)
        {
            for (const auto node : edge)
            {
                r = max (r, node);
            }
        }
        return r;
    }

    vector<int> findRedundantConnection (vector<vector<int>>& edges)
    {
        int numberOfNodes = getMaximumNodeValue (edges);
        vector<int> parent (numberOfNodes + 1, -1);
        vector<int> size (numberOfNodes + 1, -1);

        for (int currentNode = 1; currentNode <= numberOfNodes; ++currentNode)
        {
            make_set (currentNode, parent, size);
        }

        vector<int> r (2, -1);
        for (const auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            if (find_set (a, parent, size) == find_set (b, parent, size))
            {
                r = {a, b};
            }
            
            union_sets (a, b, parent, size);
        }
        
        return r;
    }
};
