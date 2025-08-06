#include <Graph/Graph/Graph.h>
#include <set>
#include <stack>

namespace GraphNamespace {
    Graph::Graph(const IGraphContainerManager& graphContainerManager) :
        graphContainerManager(*graphContainerManager.clone()) {
    }

    AdjacencyListContainer Graph::getAdjacencyListContainer() const {
        return this->graphContainerManager.getAdjacencyListContainer();
    }
    int Graph::getVerticesCount() const {
        return this->graphContainerManager.getVerticesCount();
    }
    int Graph::getEdgesCount() const {
        return this->graphContainerManager.getEdgesCount();
    }
    VertexList Graph::getVertices() const {
        return this->graphContainerManager.getVertices();
    }
    bool Graph::hasVertex(int vertexId) const {
        return this->graphContainerManager.hasVertex(vertexId);
    }
    bool Graph::hasEdge(int edgeId) const {
        return this->graphContainerManager.hasEdge(edgeId);
    }
    EdgeIdList
    Graph::getEdgesFromTo(int sourceVertexId, int destinationVertexId) const {
        return this->graphContainerManager.getEdgesFromTo(
            sourceVertexId, destinationVertexId
        );
    }
    VertexList Graph::getAdjacentVertices(int vertexId) const {
        return this->graphContainerManager.getAdjacentVertices(vertexId);
    }
    EdgeIdList Graph::getIncidentEdges(int vertexId) const {
        return this->graphContainerManager.getIncidentEdges(vertexId);
    }

    bool Graph::addVertex(int vertexId) {
        return this->graphContainerManager.addVertex(vertexId);
    }
    bool Graph::removeVertex(int vertexId) {
        return this->graphContainerManager.removeVertex(vertexId);
    }
    int Graph::addEdgeAndGetItsIdOrResultStatus(
        int sourceVertexId,
        int destinationVertexId,
        bool createVertexIfNotExists = false
    ) {
        return this->graphContainerManager.addEdgeAndGetItsIdOrResultStatus(
            sourceVertexId, destinationVertexId, createVertexIfNotExists
        );
    }
    bool
    Graph::removeAllEdgesFromTo(int sourceVertexId, int destinationVertexId) {
        return this->graphContainerManager.removeAllEdgesFromTo(
            sourceVertexId, destinationVertexId
        );
    }
    bool Graph::removeEdge(int edgeId) {
        return this->graphContainerManager.removeEdge(edgeId);
    }
    void Graph::clear() {
        return this->graphContainerManager.clear();
    }

    VertexList Graph::getAllReachableVerticesFrom(int vertexId) const {
        VertexList vertexList;
        std::set<size_t> used;
        std::stack<size_t> stack;

        stack.push(vertexId);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (used.contains(v))
                continue;

            used.insert(v);
            vertexList.push_back(v);
            for (const auto& u : this->getAdjacentVertices(v)) {
                if (!used.contains(u)) {
                    stack.push(u);
                }
            }
        }
        return vertexList;
    }

    std::vector<VertexList> Graph::getConnectedComponents() const {
        std::vector<VertexList> connectedComponents;
        std::set<size_t> used;

        for (auto vertexId : this->getVertices()) {
            if (!used.contains(vertexId)) {
                connectedComponents.push_back({});

                std::stack<size_t> stack;
                stack.push(vertexId);

                while (!stack.empty()) {
                    auto v = stack.top();
                    stack.pop();

                    if (used.contains(v))
                        continue;

                    used.insert(v);
                    connectedComponents.back().push_back(v);
                    for (auto u : this->getAdjacentVertices(v)) {
                        if (!used.contains(u)) {
                            stack.push(u);
                        }
                    }
                }
            }
        }
        return connectedComponents;
    }
}; // namespace GraphNamespace