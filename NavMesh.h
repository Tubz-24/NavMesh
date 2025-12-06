#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavMesh.generated.h"


class NavGraph;

UCLASS(Blueprintable)
class RIGPAPROGECT_API UNavMesh : public UObject
{
    GENERATED_BODY()

public:

    UNavMesh();

    UFUNCTION(BlueprintCallable, Category = "Navigation")
    bool BuildGraph();

    UFUNCTION(BlueprintCallable, Category = "Navigation")
    bool FindWorldPath(int StartNodeId, int EndNodeId, TArray<FVector>& OutPath);

    UFUNCTION(BlueprintCallable, Category = "Navigation")
    void DebugDraw(UWorld* World, float NodeSize = 25.f);

private:
    NavGraph* NavGraph; 
};