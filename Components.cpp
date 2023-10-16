#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int level[N];
vector<int> ans;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    int cnt = 1;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int c : v[p])
        {
            if (!vis[c])
            {
                q.push(c);
                vis[c] = true;
                cnt++;
            }
        }
    }
    if (cnt > 1)
        ans.push_back(cnt);
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e-- && e <= 1000)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
