/**
 *    author:  Tanbin_Hasan
 *    created: 18.08.2021 18:22:53
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(101);
bitset<101> vis, taken;

void DFS(int node) {
  vis[node] = 1;
  bool ok = true;
  for (auto &child : adj[node]) {
    ok = !taken[child];
    if (!ok) break;
  }
  taken[node] = ok;
  for (auto &child : adj[node]) {
    if (vis[child]) continue;
    DFS(child);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    while (cin >> x && x) {
      adj[i].push_back(x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      DFS(i);
    }
  }
  vector<int> grp;
  for (int i = 1; i <= n; ++i) {
    if (taken[i]) {
      grp.push_back(i);
    }
  }
  cout << (int)grp.size() << '\n';
  for (auto &i : grp) {
    cout << i << ' ';
  }
  return 0;
}