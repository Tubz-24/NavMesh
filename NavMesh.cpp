#include "NavMesh.h"
#include "DrawDebugHelpers.h"
#include "NavGraph.h"
#include "NavNode.h"
#include "NavEdge.h"
#include <algorithm>

UNavMesh::UNavMesh()
{
    NavGraph = nullptr;
}

bool UNavMesh::BuildGraph()
{
    if (!NavGraph)
        NavGraph = new NavGraph();

    return NavGraph->LoadGraph();
}

bool UNavMesh::FindWorldPath(int StartNodeId, int EndNodeId, TArray<FVector>& OutPath)
{
    OutPath.Empty();

    if (!NavGraph)
        return false;

    std::vector<int> PathIndices = NavGraph->FindPathDFS(StartNodeId, EndNodeId);

    if (PathIndices.empty())
        return false;

    std::reverse(PathIndices.begin(), PathIndices.end());

    for (int NodeIndex : PathIndices)
    {
        if (NodeIndex >= 0 && NodeIndex < NavGraph->Nodes.size())
        {
            OutPath.Add(NavGraph->Nodes[NodeIndex].m_Position);
        }
    }

    return OutPath.Num() > 0;
}

void UNavMesh::DebugDraw(UWorld* World, float NodeSize)
{
    if (!NavGraph || !World)
        return;

    for (const NavNode& Node : NavGraph->Nodes)
    {
        FVector P = Node.m_Position;

        DrawDebugSphere(World, P, NodeSize, 12, FColor::Green, false, -1, 0, 2);

        for (const NavEdge& Edge : Node.AdjacencyList)
        {
            int Neighbor = Edge.To;

            if (Neighbor >= 0 && Neighbor < NavGraph->Nodes.size())
            {
                FVector Q = NavGraph->Nodes[Neighbor].m_Position;
                DrawDebugLine(World, P, Q, FColor::Blue, false, -1, 0, 1);
            }
        }
    }
}