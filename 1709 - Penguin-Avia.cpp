/**
 *    author:  Tanbin_Hasan
 *    created: 18.08.2021 16:16:49
**/
#include <bits/stdc++.h>

using namespace std;

vector<string> vs;
vector<vector<int>> adj;
bitset<101> vis;

void DFS(int node, int par) {
  vis[node] = 1;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    if (vis[child]) {
      vs[node][child] = vs[child][node] = 'd';
      continue;
    } 
    DFS(child, node);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vs.assign(n, string(n, '0'));
  adj.assign(n, {});
  int d, a;
  cin >> d >> a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      if (ch == '1') {
        adj[i].push_back(j);
      }
    }
  }
  DFS(0, -1);
  for (int i = 1; i < n; ++i) {
    if (!vis[i]) {
      vs[i][0] = vs[0][i] = 'a';
      DFS(i, -1);
    }
  }
  int64_t cost = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vs[i][j] == 'd') {
        cost += d;
      } else if (vs[i][j] == 'a') {
        cost += a;
      }
    }
  }
  cout << cost / 2 << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << vs[i][j];
    }
    cout << '\n';
  }
  return 0;
}