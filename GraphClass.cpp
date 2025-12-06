// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphClass.h"
#include <vector>

bool Graph::LoadGraph()
{
	Nodes.clear();

	
	const std::vector<std::pair<int, int>> edges = {
		{0,1}, {0,3},
		{1,2}, {1,4},
		{2,5},
		{3,4}, {3,6},
		{4,5}, {4,7},
		{5,8},
		{6,7},
		{7,8}
	};

	int maxNodeIndex = -1;
	for (const auto& e : edges)
	maxNodeIndex = std::max(maxNodeIndex, std::max(e.first, e.second));
	int N = (maxNodeIndex >= 0) ? (maxNodeIndex + 1) : 0;
	 
	Nodes.clear();
	Nodes.resize(N);
	for (int i = 0; i < N; ++i)
		Nodes[i].NodeIndex = i;

	auto addUndirectedEdge = [this](int u, int v)
		{
			Nodes[u].AdjacencyList.emplace_back(u, v);
			Nodes[v].AdjacencyList.emplace_back(v, u);
		};

	for (const auto& e : edges)
		addUndirectedEdge(e.first, e.second);

	return true;
}

int Graph::DFS(int CurrentPos, int EndPos, std::vector<bool>& Visited, std::vector<int>& Path)
{
	if (CurrentPos < 0 || CurrentPos >= static_cast<int>(Nodes.size()))
		return 0;

	Visited[CurrentPos] = true;
	Path.push_back(CurrentPos);

	if (CurrentPos == EndPos)
		return 1;

	for (const NavEdge& edge : Nodes[CurrentPos].AdjacencyList)
	{
		int neighbor = edge.To; // neighbor index (matches the usage in LoadGraph)
		if (neighbor < 0 || neighbor >= static_cast<int>(Nodes.size())) continue;
		if (!Visited[neighbor])
		{
			if (DFS(neighbor, EndPos, Visited, Path))
				return 1;
		}
	}

	Path.pop_back(); // backtrack
	return 0;
}
