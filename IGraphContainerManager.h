#pragma once
#include "Containers.h"

namespace GraphNamespace {
    class IGraphContainerManager {
    public:
        virtual AdjacencyListContainer getAdjacencyListContainer() const = 0;
        virtual int getVerticesCount() const = 0;
        virtual int getEdgesCount() const = 0;
        virtual bool hasVertex(int vertexId) const = 0;
        virtual bool hasEdge(int edgeId) const = 0;
        virtual const EdgeIdList&
        getEdgesFromTo(int sourceVertexId, int destinationVertexId) const = 0;
        virtual const VertexList& getAdjacentVertices(int vertexId) const = 0;
        virtual const EdgeIdList& getIncidentEdges(int vertexId) const = 0;

        virtual bool addVertex(int vertexId) = 0;
        virtual bool removeVertex(int vertexId) = 0;
        virtual int addEdgeAndGetItsIdOrResultStatus(
            int sourceVertexId,
            int destinationVertexId
        ) = 0;
        virtual bool
        removeAllEdgesFromTo(int sourceVertexId, int destinationVertexId) = 0;
        virtual bool removeEdge(int edgeId) = 0;
        virtual void clear() = 0;
    };
}; // namespace GraphNamespace