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

	

	float RunningTime; // Время, прошедшее с начала движения

	// Видимость
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh; // Тело объекта

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Переменные
	UPROPERTY(EditInstanceOnly, Category = "Cpp Base Actor")
	FString PlayerName = "Netologiya";

	UPROPERTY(EditInstanceOnly, Category = "Cpp Base Actor")
	int EnemyNum = 20;

	UPROPERTY(EditInstanceOnly, Category = "Cpp Base Actor")
	float CurrentHealth = 100;

	UPROPERTY(EditInstanceOnly, Category = "Cpp Base Actor")
	bool IsAlive = true;

	UPROPERTY(EditInstanceOnly, Category = "Cpp Base Actor")
	float Amplitude = 0; // Амплитуда

	UPROPERTY(EditInstanceOnly,Category = "Cpp Base Actor")
	float Frequency = 0; // Частота

	UPROPERTY(EditInstanceOnly)
	FVector MovementAxis = FVector(1.0f, 1.0f, 1.0f); // Ось движения

private:
};