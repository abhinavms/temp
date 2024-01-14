#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adjList, int &end, vector<bool> &visited, int node, int previous, set<int> &outputNodes) {
    if(node == end) {
        outputNodes.insert(previous);
        return;
    } else {
        visited[node] = true;
    }
    
    for(auto &i: adjList[node]) {
        if(!visited[i]) {
            dfs(adjList, end, visited, i, node, outputNodes);
        }
    }
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
    vector<vector<int>> adjList(n);
    for (int i = 0; i < e; ++i) {
        int follower, following;
        cin >> follower >> following;
        follower = valueToIndex[follower];
        following = valueToIndex[following];
        adjList[follower].push_back(following);
    }

    int a, b;
    cin >> a;
    cin >> b;
    a = valueToIndex[a];
    b = valueToIndex[b];

    vector<bool> visited(n, false);
    
    set<int> outputNodes;
    dfs(adjList, b, visited, a, -1, outputNodes);
    
    for(auto &i: outputNodes) {
        cout << indexToValue[i] << " ";
    }
}
