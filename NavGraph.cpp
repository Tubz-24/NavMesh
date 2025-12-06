#include "NavGraph.h"
#include "NavNode.h"
#include "NavEdge.h"
#include <vector>
bool NavGraph::LoadGraph()
{

    // creates a simple hard coded graph 
    const std::vector<std::pair<int, int>> edges =
    {
        {0,1}, {0,3},
        {1,2}, {1,4},
        {2,5},
        {3,4}, {3,6},
        {4,5}, {4,7},
        {5,8},
        {6,7},
        {7,8}
    };

    // looks at how many nodes we need 
    int maxId = -1;
    for (auto& e : edges)
        maxId = std::max(maxId, std::max(e.first, e.second));

    Nodes.clear();
    Nodes.resize(maxId + 1);

    // Initialize nodes
    for (int i = 0; i < Nodes.size(); i++)
    {
        Nodes[i].NodeIndex = i;
        Nodes[i].m_Position = FVector(i * 200.f, 0, 0); // temporary debug positions
    }

    // Add edges
    for (auto& e : edges)
    {
        Nodes[e.first].AdjacencyList.emplace_back(e.first, e.second);
        Nodes[e.second].AdjacencyList.emplace_back(e.second, e.first);
    }


    return true;

}

int NavGraph::DFS(int CurrentPos, int EndPos, std::vector<bool>& Visited, std::vector<int>& Path)
{
    if (CurrentPos == EndPos)
    {
        Path.push_back(CurrentPos);
        return true;
    }

    Visited[CurrentPos] = true;

    for (auto& edge : Nodes[CurrentPos].AdjacencyList)
    {
        int Next = edge.To;

        if (!Visited[Next])
        {
            if (DFS(Next, EndPos, Visited, Path))
            {
                Path.push_back(CurrentPos);
                return true;
            }
        }
    }

    return false;
}


std::vector<int> NavGraph::FindPathDFS(int StartPos, int EndPos)
{
    std::vector<int> Path;

    if (StartPos < 0 || EndPos < 0 ||
        StartPos >= Nodes.size() || EndPos >= Nodes.size())
        return Path;

    std::vector<bool> Visited(Nodes.size(), false);

    std::vector<int> ReversePath;
    if (DFS(StartPos, EndPos, Visited, ReversePath))
    {
        // DFS builds reversed
        std::reverse(ReversePath.begin(), ReversePath.end());
        Path = ReversePath;
    }

    return Path;
}


   