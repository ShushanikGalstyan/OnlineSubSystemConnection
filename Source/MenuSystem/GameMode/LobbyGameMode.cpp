// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameMode/LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers ));
		}
		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (IsValid(PlayerState))
		{
			FString PlayerName = PlayerState->GetPlayerName();
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,
				                                 FString::Printf(TEXT("Players name: %s"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers));
		}
	}
	APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
	if (IsValid(PlayerState))
	{
		FString PlayerName = PlayerState->GetPlayerName();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,
			                                 FString::Printf(TEXT("Players exited: %s"), *PlayerName));
		}
	}
}
