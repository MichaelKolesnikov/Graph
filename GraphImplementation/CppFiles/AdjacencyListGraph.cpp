#include "../AdjacencyListGraph.h"

namespace GraphNamespace {
    AdjacencyListGraph::AdjacencyListGraph() {
    }
    AdjacencyListGraph::AdjacencyListGraph(int verticesCount) :
        adjacencyListContainerManager(verticesCount) {
    }
    AdjacencyListGraph::AdjacencyListGraph(
        const AdjacencyListContainer& adjacencyListContainer
    ) : adjacencyListContainerManager(adjacencyListContainer) {
    }
    AdjacencyListGraph::AdjacencyListGraph(
        const AdjacencyListContainerManager& adjacencyListContainerManager
    ) : adjacencyListContainerManager(adjacencyListContainerManager) {
    }

    AdjacencyListContainer
    AdjacencyListGraph::getAdjacencyListContainer() const {
        return this->adjacencyListContainerManager.getAdjacencyListContainer();
    }
    int AdjacencyListGraph::getVerticesCount() const {
        return this->adjacencyListContainerManager.getVerticesCount();
    }
    int AdjacencyListGraph::getEdgesCount() const {
        return this->adjacencyListContainerManager.getEdgesCount();
    }
    bool AdjacencyListGraph::hasVertex(int vertexId) const {
        return this->adjacencyListContainerManager.hasVertex(vertexId);
    }
    bool AdjacencyListGraph::hasEdge(int edgeId) const {
        return this->adjacencyListContainerManager.hasEdge(edgeId);
    }
    EdgeIdList AdjacencyListGraph::getEdgesFromTo(
        int sourceVertexId,
        int destinationVertexId
    ) const {
        return this->adjacencyListContainerManager.getEdgesFromTo(
            sourceVertexId, destinationVertexId
        );
    }
    VertexList AdjacencyListGraph::getAdjacentVertices(int vertexId) const {
        return this->adjacencyListContainerManager.getAdjacentVertices(vertexId);
    }
    EdgeIdList AdjacencyListGraph::getIncidentEdges(int vertexId) const {
        return this->adjacencyListContainerManager.getIncidentEdges(vertexId);
    }

    bool AdjacencyListGraph::addVertex(int vertexId) {
        return this->adjacencyListContainerManager.addVertex(vertexId);
    }
    bool AdjacencyListGraph::removeVertex(int vertexId) {
        return this->adjacencyListContainerManager.removeVertex(vertexId);
    }
    int AdjacencyListGraph::addEdgeAndGetItsIdOrResultStatus(
        int sourceVertexId,
        int destinationVertexId
    ) {
        return this->adjacencyListContainerManager
            .addEdgeAndGetItsIdOrResultStatus(
                sourceVertexId, destinationVertexId
            );
    }
    bool AdjacencyListGraph::removeAllEdgesFromTo(
        int sourceVertexId,
        int destinationVertexId
    ) {
        return this->adjacencyListContainerManager.removeAllEdgesFromTo(
            sourceVertexId, destinationVertexId
        );
    }
    bool AdjacencyListGraph::removeEdge(int edgeId) {
        return this->adjacencyListContainerManager.removeEdge(edgeId);
    }
    void AdjacencyListGraph::clear() {
        return this->adjacencyListContainerManager.clear();
    }
}; // namespace GraphNamespace