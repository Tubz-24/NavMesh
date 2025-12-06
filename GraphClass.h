// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "NavNode.h"

/**
 * 
 */
class Graph
{
public:
	std::vector<NavNode> Nodes;

	bool LoadGraph();

	int DFS(int CurrentPos, int EndPos, std::vector<bool>& Visited, std::vector<int>& Path);



	std::vector<int> FindPathDFS(int StartPos, int EndPos);



};