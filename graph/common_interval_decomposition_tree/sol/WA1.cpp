#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
#include "permutation_tree.hpp"

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &p[i]);
    perm_tree<int> pt(p);
    auto root = pt.get();
    using np = decltype(root);
    vector<tuple<int, int, int, string>> v;
    auto dfs = [&](auto dfs, np t, int par) -> void
    {
        int now = v.size();
        for (auto e : t->ch)
        {
            dfs(dfs, e, now);
        }
        v.emplace_back(par, t->l, t->r, (t->is_join ? "linear" : "prime"));
    };
    dfs(dfs, root, -1);
    printf("%zu\n", v.size());
    for (auto [par, l, r, s] : v)
    {
        printf("%d %d %d %s\n", par, l, r - 1, s.c_str());
    }
}