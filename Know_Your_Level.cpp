#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int level[N];
vector<int> ans;

void bfs(int src, int l)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

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
                level[c] = level[p] + 1;

                if (level[c] == l)
                    ans.push_back(c);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int l;
    cin >> l;

    bfs(0, l);

    sort(ans.begin(), ans.end());

    if (!ans.empty())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
