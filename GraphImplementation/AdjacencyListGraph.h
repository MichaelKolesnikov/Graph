#pragma once
#include "../GraphContainerManagerImplementations/AdjacencyListContainerManager.h"
#include "../IGraph.h"

namespace GraphNamespace {
    class AdjacencyListGraph final : IGraph {
        AdjacencyListContainerManager adjacencyListContainerManager;

    public:
        explicit AdjacencyListGraph();
        explicit AdjacencyListGraph(int verticesCount);
        explicit AdjacencyListGraph(
            const AdjacencyListContainer& adjacencyListContainer
        );
        explicit AdjacencyListGraph(
            const AdjacencyListContainerManager& adjacencyListContainerManager
        );

        AdjacencyListContainer getAdjacencyListContainer() const;
        virtual int getVerticesCount() const override;
        virtual int getEdgesCount() const override;
        virtual bool hasVertex(int vertexId) const override;
        virtual bool hasEdge(int edgeId) const override;
        virtual EdgeIdList getEdgesFromTo(
            int sourceVertexId,
            int destinationVertexId
        ) const override;
        virtual VertexList getAdjacentVertices(int vertexId) const override;
        virtual EdgeIdList getIncidentEdges(int vertexId) const override;

        virtual bool addVertex(int vertexId) override;
        virtual bool removeVertex(int vertexId) override;
        virtual int addEdgeAndGetItsIdOrResultStatus(
            int sourceVertexId,
            int destinationVertexId
        ) override;
        virtual bool removeAllEdgesFromTo(
            int sourceVertexId,
            int destinationVertexId
        ) override;
        virtual bool removeEdge(int edgeId) override;
        virtual void clear() override;
    };
}; // namespace GraphNamespace