#pragma once
#include "../IGraphContainerManager.h"

namespace GraphNamespace {
    class Graph {
        IGraphContainerManager& graphContainerManager;

    public:
        explicit Graph();
        explicit Graph(const IGraphContainerManager& graphContainerManager);

        AdjacencyListContainer getAdjacencyListContainer() const;
        int getVerticesCount() const;
        int getEdgesCount() const;
        VertexList getVertices() const;
        bool hasVertex(int vertexId) const;
        bool hasEdge(int edgeId) const;
        EdgeIdList
        getEdgesFromTo(int sourceVertexId, int destinationVertexId) const;
        VertexList getAdjacentVertices(int vertexId) const;
        EdgeIdList getIncidentEdges(int vertexId) const;

        bool addVertex(int vertexId);
        bool removeVertex(int vertexId);
        int addEdgeAndGetItsIdOrResultStatus(
            int sourceVertexId,
            int destinationVertexId,
            bool createVertexIfNotExists
        );
        bool removeAllEdgesFromTo(int sourceVertexId, int destinationVertexId);
        bool removeEdge(int edgeId);
        void clear();

        VertexList getAllReachableVerticesFrom(int vertexId) const;
        std::vector<VertexList> getConnectedComponents() const;
    };
}; // namespace GraphNamespace