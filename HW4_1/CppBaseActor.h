// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	virtual void BeginPlay() override;

	// Функции
	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UFUNCTION(BlueprintCallable)
	float SinMovement(float Time);

	// Переменные
	UPROPERTY(EditInstanceOnly)
	FString PlayerName = "Netologiya";

	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 20;

	UPROPERTY(EditInstanceOnly)
	float CurrentHealth = 100;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditAnywhere)
	float Amplitude; // Амплитуда

	UPROPERTY(EditAnywhere)
	float Frequency; // Частота

	UPROPERTY(EditAnywhere)
	FVector MovementAxis; // Ось движения

	float RunningTime; // Время, прошедшее с начала движения

	// Видимость
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh; // Тело объекта

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
};