// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	// Инициализация параметров движения
	RunningTime = 0.0f;
	MovementAxis = FVector(0.0f, 0.0f, 1.0f); // По умолчанию движение по оси Z
	Amplitude = 50.0f;						  // Амплитуда по умолчанию
	Frequency = 1.0f;						  // Частота по умолчанию
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Увеличиваем время, прошедшее с начала движения
	RunningTime += DeltaTime;

	// Вычисляем изменение положения с использованием метода SinMovement
	float DeltaMovement = SinMovement(RunningTime);

	// Получаем текущее положение объекта
	FVector NewLocation = GetActorLocation();

	// Применяем движение по выбранной оси
	NewLocation += MovementAxis * DeltaMovement * DeltaTime;

	// Устанавливаем новое положение объекта
	SetActorLocation(NewLocation);
}

float ACppBaseActor::SinMovement(float Time) 
{
	return this -> Amplitude * FMath::Sin(this->Frequency * Time);
}

void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerName: %s"), *PlayerName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}