#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &adjList, int n, int source, int target) {
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while(!pq.empty()) {
        auto [currentDistance, node] = pq.top();
        pq.pop();
        for(auto &i: adjList[node]) {
            int v = i.first;
            int w = i.second;
            if(currentDistance + w < distance[v]) {
                distance[v] = currentDistance + w;
                pq.push({distance[v], v});
            }
        }
    }
    return distance[target];
}

int main() {
    int n, e;
    cin >> n;

    vector<int> indexToValue(n);
    unordered_map<int, int> valueToIndex;
    for (int i = 0; i < n; ++i) {
        int memberId;
        cin >> memberId;
        indexToValue[i] = memberId;
        valueToIndex[memberId] = i;
    }

    cin >> e;
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < e; ++i) {
        int x, y, time;
        cin >> x >> y >> time;
        x = valueToIndex[x];
        y = valueToIndex[y];
        adjList[x].push_back({y, time});
    }

    int a, b;
    cin >> a;
    cin >> b;
    a = valueToIndex[a];
    b = valueToIndex[b];

    cout << dijkstra(adjList, n, a, b);
}