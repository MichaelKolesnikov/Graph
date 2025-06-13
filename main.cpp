#include "GraphImplementation/AdjacencyListGraph.h"
#include <iostream>
#include <stack>
using namespace std;
using namespace GraphNamespace;

void printVertexList(const VertexList& vertexList, bool needSize = false) {
    if (needSize) {
        cout << vertexList.size() << endl;
    }
    for (int i : vertexList) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int u, v, n, m;
    cin >> n >> m;
    AdjacencyListGraph g(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g.addEdgeAndGetItsIdOrResultStatus(u, v);
        g.addEdgeAndGetItsIdOrResultStatus(v, u);
    }
    VertexList vertexList;
    vector<bool> used(n, false);
    std::stack<int> stack;

    stack.push(0);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (used[v])
            continue;

        used[v] = true;
        vertexList.push_back(v + 1);
        const auto& neighbors = g.getAdjacentVertices(v);
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            int u = *it;
            if (!used[u]) {
                stack.push(u);
            }
        }
    }
    std::sort(std::begin(vertexList), std::end(vertexList));
    printVertexList(vertexList, true);
}