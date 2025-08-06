#include <Graph/Graph/Graph.h>
#include <Graph/GraphContainerManager/AdjacencyListContainerManager.h>
#include <iostream>
#include <stack>
using namespace std;
using namespace GraphNamespace;

void printVertexList(const VertexList& vertexList, bool needSize = false) {
    if (needSize) {
        cout << vertexList.size() << '\n';
    }
    for (int i : vertexList) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int u, v, n, m;
    cin >> n >> m;

    auto g = Graph(AdjacencyListContainerManager(n + 1));
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g.addEdgeAndGetItsIdOrResultStatus(u, v, false);
        g.addEdgeAndGetItsIdOrResultStatus(v, u, false);
    }
    g.removeVertex(0);
    auto connectedComponents = g.getConnectedComponents();
    cout << connectedComponents.size() << '\n';
    for (const auto& vertexList : connectedComponents) {
        printVertexList(vertexList, true);
    }
}