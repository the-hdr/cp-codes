void make_set (int v, vector<int>& parent, vector<int>& size)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set (int v, const vector<int>& parent, const vector<int>& size)
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
            swap (a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
