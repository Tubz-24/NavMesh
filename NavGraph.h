// NavGraph.h
#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "NavNode.h"

class RIGPAPROGECT_API NavGraph
{
public:
    std::vector<NavNode> Nodes;

    bool LoadGraph();

    int DFS(int CurrentPos, int EndPos, std::vector<bool>& Visited, std::vector<int>& Path);

    std::vector<int> FindPathDFS(int StartPos, int EndPos);
};





