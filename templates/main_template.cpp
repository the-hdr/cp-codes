// 君子之行，静以修身，俭以养德，非淡泊无以明志，非宁静无以致远。

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define float long double
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

#define whatis(x) (#x) << " = " << (x)
//#define cerr if(false)cerr

using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


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

int ceil (int a, int b)
{
    return (a + b - 1) / b;
}

void solve()
{
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    
    while (t--) solve();
    
    return 0;
}
