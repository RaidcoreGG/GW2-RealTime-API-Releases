///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - All rights reserved.
///
/// Name         :  RTAPI.hpp
/// Description  :  Definitions for public-facing real-time API.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#ifndef RTAPI_H
#define RTAPI_H

#define DL_RTAPI                      "RTAPI"
#define EV_RTAPI_GROUP_MEMBER_JOINED  "RTAPI_GROUP_MEMBER_JOINED"
#define EV_RTAPI_GROUP_MEMBER_LEFT    "RTAPI_GROUP_MEMBER_LEFT"
#define EV_RTAPI_GROUP_MEMBER_UPDATED "RTAPI_GROUP_MEMBER_UPDATED"

#include <cstdint>

namespace RTAPI
{
	///----------------------------------------------------------------------------------------------------
	/// EGameState Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EGameState : uint32_t
	{
		CharacterSelection,
		CharacterCreation,
		Cinematic,
		LoadingScreen,
		Gameplay
	};

	///----------------------------------------------------------------------------------------------------
	/// EGameLanguage Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EGameLanguage : uint32_t
	{
		English,
		Korean,
		French,
		German,
		Spanish,
		Chinese
	};

	///----------------------------------------------------------------------------------------------------
	/// ETimeOfDay Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class ETimeOfDay : uint32_t
	{
		Dawn,
		Day,
		Dusk,
		Night
	};

	///----------------------------------------------------------------------------------------------------
	/// ECharacterState Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class ECharacterState : uint32_t
	{
		IsAlive      = 1 << 0,
		IsDowned     = 1 << 1,
		IsInCombat   = 1 << 2,
		IsSwimming   = 1 << 3, // aka. Is on water surface
		IsUnderwater = 1 << 4, // aka. Is diving
		IsGliding    = 1 << 5,
		IsFlying     = 1 << 6
	};

	///----------------------------------------------------------------------------------------------------
	/// EMapType Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EMapType : uint32_t
	{
		AutoRedirect,
		CharacterCreation,
		PvP,
		GvG,
		Instance,
		Public,
		Tournament,
		Tutorial,
		UserTournament,
		WvW_EternalBattlegrounds,
		WvW_BlueBorderlands,
		WvW_GreenBorderlands,
		WvW_RedBorderlands,
		WVW_FortunesVale,
		WvW_ObsidianSanctum,
		WvW_EdgeOfTheMists,
		Public_Mini,
		BigBattle,
		WvW_Lounge
	};

	///----------------------------------------------------------------------------------------------------
	/// EGroupType Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EGroupType : uint32_t
	{
		None,
		Party,
		RaidSquad,
		Squad
	};

	///----------------------------------------------------------------------------------------------------
	/// GroupMember Struct
	///----------------------------------------------------------------------------------------------------
	typedef struct GroupMember
	{
		char     AccountName[32];
		char     CharacterName[20];
		int32_t  Subgroup;            // 0 for parties, 1-15 according to the squad's subgroup
		int32_t  Profession;          // 0-9 = Profession; -1 Unknown -> e.g. on loading screen or logged out
		int32_t  EliteSpecialization; // Third Spec ID, not necessarily elite; or -1 Unknown -> e.g. on loading screen or logged out
		uint32_t IsSelf       : 1;
		uint32_t IsInInstance : 1;    // Is in the same map instance as the player.
		uint32_t IsCommander  : 1;
		uint32_t IsLieutenant : 1;
	} GroupMember;

	///----------------------------------------------------------------------------------------------------
	/// RealTimeData Struct
	///----------------------------------------------------------------------------------------------------
	typedef struct RealTimeData
	{
		/* Game Data */
		int32_t         GameBuild;
		EGameState      GameState;
		EGameLanguage   Language;
		/* Instance/World Data */
		ETimeOfDay      TimeOfDay;
		int32_t         MapID;
		EMapType        MapType;
		char            IPAddress[4];
		float           Cursor[3];          // Location of cursor in the world
		float           SquadMarkers[8][3]; // Locations of squad markers
		EGroupType      GroupType;
		uint32_t        GroupMemberCount;
		uint32_t        RESERVED2;

		/* Player Data */
		uint32_t        RESERVED1;
		char            AccountName[32];
		char            CharacterName[20];
		float           CharacterPosition[3];
		float           CharacterFacing[3];
		int32_t         Profession;
		int32_t         EliteSpecialization;
		int32_t         MountIndex;
		ECharacterState CharacterState;

		/* Camera Data */
		float           CameraPosition[3];
		float           CameraFacing[3];
		float           CameraFOV;
		uint32_t        IsActionCamera : 1;
	} RealTimeData;
}

#endif
