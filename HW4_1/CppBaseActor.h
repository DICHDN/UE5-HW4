// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "CppBaseActor.generated.h"

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrientRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurientScale = FVector(1.0f, 1.0f, 1.0f);


};


class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

UCLASS()
class HW4_1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	//функции
	UFUNCTION(BlueprintCallable)
	void ShowInformation();
	UFUNCTION(BlueprintCallable)
	float SinMovement(float var1);

	virtual void BeginPlay() override;
	//переменные
	UPROPERTY(EditInstanceOnly)
	FString PlayerName = "Netologiya";
	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 20;
	UPROPERTY(EditInstanceOnly)
	float CurrentHealth = 100;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditAnywhere)
	float Amplitude; // амплитуда
	UPROPERTY(EditAnywhere)
	float Frequency; // частота
	UPROPERTY(EditAnywhere)
	FVector MovementAxis; // положение

	float RunningTime; // переменная для времени
	//видимость
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh; //тело объекта	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
};
