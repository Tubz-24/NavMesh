// NavEdge.h.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RIGPAPROGECT_API NavEdge
{
public:

	
	int From;
	int To;

	NavEdge() : From(-1), To(-1) {}
	NavEdge(int InFrom, int InTo) : From(InFrom), To(InTo) {}


	~NavEdge() = default;
};
