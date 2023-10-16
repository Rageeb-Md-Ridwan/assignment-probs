#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main()
{
    int n, e;
    cin >> n >> e;
    long long int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b] , w); //for mutliple edges
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] < INF && dis[k][j] < INF && dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    long long int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        if (dis[src][dst] == INF)
            cout << "-1" << endl;
        else
            cout << dis[src][dst] << endl;
    }
    return 0;
}
