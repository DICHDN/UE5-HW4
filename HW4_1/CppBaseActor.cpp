// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

// #include "CppHubActor.h" // есть подозрения что он нужен для кода из лекции "Blueprints и С++. Часть 2" не рабочий

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
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &ACppBaseActor::OnTimeToSpawn, TimerRate, true); // строчка кода из лекции "Blueprints и С++. Часть 2" не рабочий
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Увеличиваем время, прошедшее с начала движения
	RunningTime += DeltaTime;

	// Вычисляем изменение положения с использованием синуса
	float DeltaMovement = Amplitude * FMath::Sin(Frequency * RunningTime);

	// Получаем текущее положение объекта
	FVector NewLocation = GetActorLocation();

	// Применяем движение по выбранной оси
	NewLocation += MovementAxis * DeltaMovement * DeltaTime;

	// Устанавливаем новое положение объекта
	SetActorLocation(NewLocation);
}

float ACppBaseActor::SinMovement(float var1)
{

	return FMath::Sin(var1);

}

void ACppBaseActor::ShowInformation()
{
	// UE_LOG(LogTemp, Display, TEXT("Cpp is here"));//простая надпись в логе
	// UE_LOG(LogTemp, Warning, TEXT("Cpp класс ошибся")); //Желтая надпись в логе
	// UE_LOG(LogTemp, Error, TEXT("Cpp критическая ошибка"));//красная надпись в логе

	UE_LOG(LogTemp, Warning, TEXT("PlayerName: %s"), *PlayerName); // для визуального выделения блока данных в выводимом логе
	// GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));//выводит на игровой экран имена
	// из PlayerName из всех объектов этого класса в сцене

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth); // можно закомментировать что бы удовлетворяло катринке из ДЗ
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}


//Ниже код который был описан в лекции "Blueprints и С++. Часть 2" не рабочий

//void ACppHubActor::OnTimeToSpawn()
//{
//	const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.0f, 1000.0f), FMath::FRandRange(200.0f, 1000.0f), 0.0f);
//	const FRotator Rotation = FRotator::ZeroRotator;
//	ACppBaseActor* SpawnObject = GetWorld()->SpawnActor<ACppBaseActor>(CppClass, Location, Rotation);
//	if (SpawnObject)
//	{
//		SpawnObjects.Add(SpawnObject);
//	}
//	else
//	{
//		GetWorldTimerMeneger().ClearTimer(SpawnTimerHandle);
//		for (int i = TotalTimerCount; i >= 1; --i)
//		{
//			GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &ACppHubActor::OnTimeDestroy, DestroyTimerRate, true);
//		}
//	}
//}

//void ACppHubActor::OnTimeToDestroy()
//{
//	if (!SpawnObjects.IsEmpty())
//	{
//		SpawnObjects.Top()->Destroy();
//		SpawnObjects.Pop();
//	}
//	else
//	{
//		GetWorldTimerMeneger().ClearTimer(DestroyTimerHandle);
//	}
//}