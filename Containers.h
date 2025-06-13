#pragma once
#include <stdlib.h>
#include <vector>

namespace GraphNamespace {
    typedef std::vector<size_t> VertexList;
    typedef std::vector<size_t> EdgeIdList;

    typedef std::vector<std::pair<size_t, size_t>> EdgeListContainer;
    typedef std::vector<std::vector<size_t>> AdjacencyMatrixContainer;
    typedef std::vector<VertexList> AdjacencyListContainer;
    typedef std::vector<std::vector<size_t>> IncidenceMatrixContainer;
    typedef std::vector<EdgeIdList> IncidenceListContainer;
} // namespace GraphNamespace