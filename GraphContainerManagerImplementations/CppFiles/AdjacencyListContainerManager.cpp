#include "../AdjacencyListContainerManager.h"

namespace GraphNamespace {
    AdjacencyListContainerManager::AdjacencyListContainerManager() {
    }
    AdjacencyListContainerManager::AdjacencyListContainerManager(
        int verticesCount
    ) {
        this->adjacencyListContainer.resize(verticesCount);
    }
    AdjacencyListContainerManager::AdjacencyListContainerManager(
        const AdjacencyListContainer& adjacencyListContainer
    ) {
        for (const auto& vertices : adjacencyListContainer) {
            for (auto vertexId : vertices) {
                if (vertexId >= adjacencyListContainer.size()) {
                    // TODO
                    throw 0;
                }
            }
            this->edgesCount += vertices.size();
        }
        this->adjacencyListContainer = adjacencyListContainer;
    }

    AdjacencyListContainer
    AdjacencyListContainerManager::getAdjacencyListContainer() const {
        return this->adjacencyListContainer;
    }

    int AdjacencyListContainerManager::getVerticesCount() const {
        return this->adjacencyListContainer.size() -
            this->removedVertices.size();
    };
    int AdjacencyListContainerManager::getEdgesCount() const {
        return this->edgesCount;
    };
    bool AdjacencyListContainerManager::hasVertex(int vertexId) const {
        return vertexId < this->adjacencyListContainer.size() &&
            this->removedVertices.find(vertexId) ==
            std::end(this->removedVertices);
    }
    bool AdjacencyListContainerManager::hasEdge(int edgeId) const {
        throw 0;
    }
    const EdgeIdList& AdjacencyListContainerManager::getEdgesFromTo(
        int sourceVertexId,
        int destinationVertexId
    ) const {
        throw 0;
    }
    const VertexList&
    AdjacencyListContainerManager::getAdjacentVertices(int vertexId) const {
        return this->adjacencyListContainer[vertexId];
    }
    const EdgeIdList&
    AdjacencyListContainerManager::getIncidentEdges(int vertexId) const {
        throw 0;
    }

    bool AdjacencyListContainerManager::addVertex(int vertexId) {
        if (this->hasVertex(vertexId)) {
            return false;
        }
        this->removedVertices.erase(vertexId);
        if (vertexId >= this->adjacencyListContainer.size()) {
            this->adjacencyListContainer.resize(vertexId + 1);
        }
        return true;
    }
    bool AdjacencyListContainerManager::removeVertex(int vertexId) {
        if (!this->hasVertex(vertexId)) {
            return false;
        }
        for (auto& vertices : this->adjacencyListContainer) {
            std::erase(vertices, vertexId);
        }
        this->removedVertices.insert(vertexId);
        return true;
    }
    int AdjacencyListContainerManager::addEdgeAndGetItsIdOrResultStatus(
        int sourceVertexId,
        int destinationVertexId
    ) {
        if (!this->hasVertex(sourceVertexId) ||
            !this->hasVertex(destinationVertexId)) {
            return -1;
        }
        this->adjacencyListContainer[sourceVertexId].push_back(
            destinationVertexId
        );
        return 1;
    }
    bool AdjacencyListContainerManager::removeAllEdgesFromTo(
        int sourceVertexId,
        int destinationVertexId
    ) {
        return this->hasVertex(sourceVertexId)
            ? std::erase(
                  this->adjacencyListContainer[sourceVertexId],
                  destinationVertexId
              )
            : false;
    }
    bool AdjacencyListContainerManager::removeEdge(int edgeId) {
        throw 0;
    }
    void AdjacencyListContainerManager::clear() {
        this->edgesCount = 0;
        this->adjacencyListContainer.clear();
    }

}; // namespace GraphNamespace