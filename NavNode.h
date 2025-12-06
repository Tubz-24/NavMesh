// NavNode.h
#pragma once

#include "CoreMinimal.h"
#include "NavEdge.h"
#include <vector>

class RIGPAPROGECT_API NavNode
{
public:
    int NodeIndex;
    FVector m_Position;
    std::vector<NavEdge> AdjacencyList;

    NavNode()
        : NodeIndex(-1),
        m_Position(FVector::ZeroVector),
        AdjacencyList()
    {
    }

    NavNode(int InIndex, const FVector& InPosition)
        : NodeIndex(InIndex),
        m_Position(InPosition),
        AdjacencyList()
    {
    }

    ~NavNode() = default;
};
