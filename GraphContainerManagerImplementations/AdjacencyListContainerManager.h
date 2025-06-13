#pragma once
#include "../IGraphContainerManager.h"
#include <algorithm>
#include <set>

namespace GraphNamespace {
    class AdjacencyListContainerManager final : public IGraphContainerManager {
        int edgesCount;
        AdjacencyListContainer adjacencyListContainer;
        std::set<int> removedVertices;

    public:
        explicit AdjacencyListContainerManager();
        explicit AdjacencyListContainerManager(int verticesCount);
        explicit AdjacencyListContainerManager(
            const AdjacencyListContainer& adjacencyListContainer
        );

        virtual AdjacencyListContainer
        getAdjacencyListContainer() const override;
        virtual int getVerticesCount() const override;
        virtual int getEdgesCount() const override;
        virtual bool hasVertex(int vertexId) const override;
        virtual bool hasEdge(int edgeId) const override;
        virtual const EdgeIdList& getEdgesFromTo(
            int sourceVertexId,
            int destinationVertexId
        ) const override;
        virtual const VertexList&
        getAdjacentVertices(int vertexId) const override;
        virtual const EdgeIdList& getIncidentEdges(int vertexId) const override;

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
} // namespace GraphNamespace