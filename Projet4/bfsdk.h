#ifndef BF4SDK_H
#define BF4SDK_H

#include "log.h"

//#include "FrostbiteStructDump.h"
//#include "FrostbiteClassDump.h" //en attente eastl.h

#define Vec3 Vector4
#define Vec2 Vector2 // ou 3?
#define Float32 float
#define Boolean bool
#define Uint32 unsigned __int32
#define Int32 __int32
#define Uint8  unsigned __int8
#define Int8	__int8
#define Uint16 unsigned __int16
#define Int16 __int16
#define Uint64 unsigned __int64
#define Int64 __int64

#define Pointer DWORD_PTR


class AxisAlignedBox
{
public:
	__declspec(align(16))Vec3 min;
	__declspec(align(16))Vec3 max;
};

////////////////////////////////////////////////////////////////////////////////////////////

class Main;
class Client;
class GameTime;
class ClientPlayerManager;
class BorderInputNode;
class ClientGameContext;

class BoneCollisionComponent;
class ClientAnimatedSoldierWeaponHandler;
class ClientAntAnimatableComponent;
class ClientCharacterEntity;
class ClientControllableEntity;
class ClientPlayer;
class ClientSoldierPrediction;
class ClientRagDollComponent;
class CharacterPhysicsData;
class CharacterPhysicEntity;
class ClientSoldierEntity;
class ClientVehicleEntity;
class ClientWeapon;
class ClientSoldierAimingEnvironment;
class ClientSoldierAimingSimulation;
class AimAssist;
class DxRenderer;
class GameRenderer;
class GameWorld;
class HavokPhysicsManager;
class IPhysicsRayCaster;
class RayCastHit;
class Screen;
class SoldierEntity;
class ShotConfigData;
class UpdatePoseResultData;
class WeaponModifier;
class WeaponSway;
class WorldRenderSettings;
class FOVTransitionData;
class ZoomLevelData;
class AxisAlignedBox;
class PhysicsEntityData;
class MaterialDecl;
class CharacterPhysicsData;
class CharacterPhysicEntity;
class EntryComponent;
class EntryComponentData;
class EmitterSystemSettings;
class MeshSettings;
class PhysicsSettings;
class SystemSettings;
class WeaponData;
class ToolData;
class GameObject;
class CObjectEntry;
class CObjectList;
class SoldierWeaponData;
class WeaponFiring;
class ExplosionEntityData;
class ExplosionPackTrigger;
class ClientExplosionPackEntity;
struct WeaponDispersion;
class GunSwayStanceZoomModifierData;
class VeniceSoldierCustomizationAsset;
class WeaponSwayData;
class GunSwayData;
class PhysicsEntity;
class GameAIEntryData;
class GameComponentData;
class EntryInputActionMapsData;
class InputActionMappingsData;
class EntryComponentHudData;
class EntryComponentSoundData;
class CapturePointEntityData;
class PoseConstraintsData;
class BoneComponentData;
class WeaponComponentData;
class WeaponFiringData;
class GameAIWeaponData;
class FloatPhysicsData;
class ProximityData;
class ComponentData;
class ClientGameComponent;
class ClientVehicleEntryListenerComponent;
class MeshAsset;

class ClientVaultComponent;
class OldVault;
class VaultComponentData;
class VaultBinding;
class UINodeData;

//class GunSwayDispersionModData;
//////////////////////////////////////////////////////////////
template< class T > class WeakPtr
{
private:
	T** m_ptr;

public:
	T* GetData()
	{
		if (!m_ptr)
			return NULL;

		if (!*m_ptr)
			return NULL;

		T* ptr = *m_ptr;

		return (T*)((DWORD64)ptr - 0x8);
	}
};

template <typename T>
class Array
{
private:
	T* m_firstElement;

public:
	T At(INT nIndex)
	{
		if (m_firstElement == NULL)
			return NULL;

		return *(T*)((DWORD)m_firstElement + (nIndex * sizeof(T)));
	};

	T operator [](INT index) { return At(index); }
};


namespace eastl
{
	class allocator
	{
	public:
		__forceinline allocator()
		{
		}

		__forceinline allocator(eastl::allocator *__formal)
		{
		}

		__forceinline void set_name(const char *__formal)
		{
		}

		__forceinline const char* get_name()
		{
			return "EASTL";
		}

		__forceinline void* allocate(unsigned int n, int flags)
		{
			return malloc(n);
		}

		__forceinline void deallocate(void *p, unsigned int __formal)
		{
			free(p);
		}
	};

	template <class T>
	class vector
	{
	private:
		T* m_firstElement;
		T* m_lastElement;
		T* m_arrayBound;
		void* vftable;
	public:
		size_t size()
		{
			return (((intptr_t)m_lastElement - (intptr_t)m_firstElement) / sizeof(void*));
		}

		T at(int nIndex)
		{
			return *(T*)((intptr_t)m_firstElement + (nIndex * sizeof(T)));
		}
		T operator [](int index)
		{
			return At(index);
		}
	};

	template <class T, INT Count, INT PadSize>
	class fixed_vector
	{
	private:
		T* m_firstElement;
		T* m_lastElement;
		T* m_arrayBound;
		//LPVOID m_pad[PadSize];
		T m_data[Count];

	public:
		fixed_vector() {
			m_firstElement = (T *)m_data;
			m_lastElement = (T *)m_data;
			m_arrayBound = (T *)&m_data[Count];
		}

		void push_back(T *const value) {
			if (m_lastElement > m_arrayBound) {

				return;
			}
			*m_lastElement = *value;
			m_lastElement = m_lastElement + 1;
		};

		void clear() {
			m_firstElement = m_data;
			m_lastElement = m_data;
		}

		UINT Size() {
			return m_lastElement - m_firstElement;
		}

		T At(INT nIndex) {
			return m_firstElement[nIndex];
		}

		T operator [](INT index) { return At(index); }
	};
}


/////////////////////////////////////////////////////////////
// mes classes inventées
/////////////////////////////////////////////////////////////
//OFFSET PRINCIPALE
class Current_Weapon
{
public:
	WeaponFiring* m_WeaponFiring; //0x0000 WeaponFiring*
	DWORD_PTR ClientPlayerEntryComponent_ptr_m_ClientPlayerEntryComponent; //0x0008 ClientPlayerEntryComponent*
	DWORD_PTR ClientCameraComponent_ptr_m_ClientCameraComponent; //0x0010 ClientCameraComponent on vehicle inside only chase & staticcamera
	DWORD_PTR unknownclass_ptr_m_ptrunknown; //0x0018 on vehicle only
	char _0x0020[8]; // zeros
	Matrix  matrice1; //0x0028 
	Matrix matrice2; //0x0068 s
	float m_angle1; //0x00A8 
	float m_angle2; //0x00AC 
	float m_angledeg; //0x00B0 
	float zero; //0x00B4 
	char _0x00B8[32];
	DWORD_PTR ClientCharacterSpawnEntity_ptr_m_ClientCharacterSpawnEntityselected; //0x00D8 ClientCharacterSpawnEntity selected
	DWORD_PTR ClientCharacterSpawnEntity_ptr_m_ClientCharacterSpawnEntityonmousemenu; //0x00E0 change on mouse
	DWORD_PTR onlydatas_ptr_m_ptrunkown; //0x00E8


	static Current_Weapon* GetInstance()
	{
		return (Current_Weapon*)(OFFSET_CURRENT_WEAPONFIRING);
	}
};//Size=0x0118
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GameTime
{
public:
	DWORD m_ticks; //0x0000 
	DWORD m_tickFrequency; //0x0004 
	DWORD m_tickIndexInFrame; //0x0008 
	DWORD m_lastTickIndexInFrame; //0x000C 
	DWORD m_tickCountInFrame; //0x0010 
	float m_deltaTime; //0x0014 
	float m_passedDeltaTimeInFrame; //0x0018 
};



class ClientGameView
{
public:
	virtual __int64 GetType(); //
	virtual void GetTransform(Matrix  &, Vec2 &); //
	virtual void GetLocalTransform(Matrix  &); //
	virtual void GetCurrentCameraTransform(Matrix  &); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void setActiveCamera(int id); //

	enum FreeCameraMode
	{
		Static = 0,
		Follow = 1,
		LookAt = 2
	};

	class FreeCamera
	{
	public:
		char _0x0000[16];
		Matrix m_transform; //0x0010
		Matrix m_transform2; //0x0050
		char _0x0090[24];
		float m_fov; //0x00A8
		float m_dofFocusDistance; //0x00AC
		char _0x00B0[104];
	};//Size=0x0118

	__int32 m_ActiveCamera; //0x0008
	char _0x000C[12];
	__int32 m_Camera; //0x0018
	char _0x001C[148];
	Vec3 m_cameraTargetDistance; //0x00B0
	__int64 m_freeCameraScene; //0x00C0
	FreeCamera* m_pFreeCamera; //0x00C8
	FreeCameraMode m_pFreeCameraMode; //0x00D0
	__int32 m_freeCameraPriority; //0x00D4
	BYTE m_cameraPosInitialized1; //0x00D8
	BYTE m_cameraPosInitialized2; //0x00D9
	BYTE m_cameraPosInitialized3; //0x00DA
	BYTE m_freeCameraActivated; //0x00DB
	char _0x00DC[4];
	__int64 m_cameraEntryTarget; //0x00E0 ClientEntryComponent *
	__int64 m_targetEntryUnSpawnCallback; //0x00E8
};//Size=0x00F0

class Client
{
public:
	char pad_0x0000[40];
	ClientGameContext* m_pGameContext; //0x0028
	__int64 m_pSettings; //0x0030 
	char pad_0x0038[8];
	ClientPlayerManager* m_pClientPlayerManager; //0x0040 
	char pad_0x0048[8];
	ClientGameView* m_pGameView; //0x0050
	char pad_0x0058[8];
	GameTime* m_pGameTime; //0x0060     
	BorderInputNode* m_pBorderInputNode; //0x0068 
};



class Main
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2(); // ExitServer/__vecDelDtor
	virtual void Function3();
	virtual void Function4();
	virtual void SetServerPauseState(bool);
	virtual bool IsPaused();
	virtual void JoinServerJob(bool);
	virtual void SetClientTitle(const char*);
	virtual void SetClientStatus(void*);
	virtual bool IsServerStarted();
	virtual bool IsServerLoaded();
	virtual bool Function12();
	virtual bool Function13();
	virtual bool Function14();
	virtual void Function15();
	virtual void Function16();
	virtual bool Function17();
	virtual bool Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void InitFileSystemPostSettings();
	virtual void StartBugSentry();
	virtual void Function36();
	virtual void Function37(); // nullsub
	virtual void InitSettings();
	virtual void Function39(); // nullsub
	virtual void Function40();
	virtual void Function41();
	virtual void Function42(); // nullsub
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46(); // nullsub
	virtual void InitPBPointers();
	virtual void InitPBFilesettings(); // Maybe findPbDirectory( )
	virtual void Function49(); // nullsub
	virtual void Function50(); // nullsub
	virtual void UpdatePunkbuster(); // -> fb::PunkbusterScreenshot::update( void )
	virtual void Function52(); // nullsub
	virtual void Function53();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual void Function57();
	virtual void Function58();
	virtual void Function59();
	virtual void SetServerTitle(const char*);
	virtual void SetServerStatus(void*);
	virtual void Function62(); // nullsub
	virtual void Function63();
	virtual void Function64();
	virtual void Function65();

	char pad_0x0000[24];
	BYTE m_IsDedicatedServer; //0x0020 
	BYTE m_IsDedicatedServerData; //0x0021 
	BYTE m_IsPaused; //0x0022 
	char _0x0023[37];
	__int64 m_pServer; //0x0048 
	Client* m_pClient; //0x0050 
	__int64 m_pFileSystem; //0x0058 
	//GameTimer* m_pSimulationGameTimer; //0x0060 
	//GameTimer* m_pUIGameTimer; //0x0068
	//char _0x0070[8];
	//ServerJobData m_ServerJobData; //0x0078
	//char _0x0120[24];
	//__int32 m_BuildId; //0x0138 
	//char _0x013C[68];

	static Main* GetInstance()
	{
		return *reinterpret_cast<Main**>(OFFSET_MAIN);
	}

	void ExecuteConsoleCommand(PCHAR szText)
	{
		typedef void(__thiscall* tExecuteConsole)(Main*, PCHAR szText);
		tExecuteConsole oExecuteConsole = reinterpret_cast<tExecuteConsole>(szText);

		oExecuteConsole(this, "render.drawscreeninfo 1");
	}
};

class WeaponSway
{
public:
	//char pad_0x0000[304];
	char _0x0000[8];
	GunSwayData* GunSwayData; //0x0008 GunSwayData
	char _0x0010[288];
	float m_deviationPitch; //0x0130 
	float m_deviationYaw; //0x0134 
	float m_deviationRoll; //0x0138 
	float m_deviationTransY; //0x013C 
	float m_timeSinceLastShot; //0x0140 
	DWORD m_cameraRecoilDeviation; //0x0144 
	Matrix m_cameraRecoilTransform; //0x0148 
	char pad_0x0188[24];
	float m_dispersionAngle; //0x01A0 
	float m_minDispersionAngle; //0x01A4 
	float m_crossHairDispersionFactor; //0x01A8 
	float m_currentDispersionPitch; //0x01AC 
	float m_currentDispersionYaw; //0x01B0 
	float m_currentDispersionRoll; //0x01B4 
	float m_currentDispersionTransY; //0x01B8 
}; // Size 0x0438

class MaterialDecl
{
public:
	unsigned int m_Packed; //+0x0
};

class SoundAsset
{
public:

	class SoundScopeData
	{
	public:

		class SoundScopeStrategyData
		{
		public:
			char _0x0000[16];
			char* m_Name; //0x0010 
			char* m_Stages; //0x0018 
			char _0x0020[32];
		};//Size=0x0040

		char _0x0000[16];
		char* m_Name; //0x0010 
		SoundScopeStrategyData* m_DefaultStrategy; //0x0018 
	};//Size=0x0020

	char _0x0000[24];
	SoundScopeData* m_Scope; //0x0018 
	SoundScopeData* m_ReferencedData; //0x0020 
};//Size=0x0028



class PropertyModificationListener : public ITypedObject
{
}; // size 0x08

// Flags:0x35 Size:0x8 Fields:0
// Warning: Missing fieldinfo data
/*class EntityBusPeer : public PropertyModificationListener
{
	//char aEntityBusPeer[8] //+0x00 Inherited
}; // size 0x08*/


////////////////////////////////////////
// ClassId:   00298
// RuntimeId: 05283
// TypeInfo:  0x00000001427C56A0
class EntityBusPeer
{
public:
	virtual TypeInfo* GetType(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual ComponentData* GetData(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void GetTransform(Matrix* mTransform); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual Vec3* GetVelocity(); //

	short GetID()
	{
		ClassInfo* pClassInfo = (ClassInfo*)GetType();

		if (pClassInfo)
			return pClassInfo->m_classId;

		return -1;
	}
};//Size=0x0008


/*#ifndef _EntityBusPeer_
#define _EntityBusPeer_
class EntityBusPeer
{
public:
	static __inline unsigned int ClassId()
	{
		return 298;
	}
	char _0x0000[8];
};//Size=0x0008
#endif*/

////////////////////////////////////////
// ClassId:   00586
// RuntimeId: 04809
// TypeInfo:  0x00000001427B9AE0
#ifndef _Entity_
#define _Entity_
class Entity : public EntityBusPeer
{
public:
	static __inline unsigned int ClassId()
	{
		return 586;
	}
	char _0x0008[24];
};//Size=0x0020
#endif


////////////////////////////////////////
// ClassId:   00611
// RuntimeId: 04537
// TypeInfo:  0x00000001427B23C0
#ifndef _MixerEntity_
#define _MixerEntity_
class MixerEntity : public Entity
{
public:
	static __inline unsigned int ClassId()
	{
		return 611;
	}
	char _0x0020[88];
};//Size=0x0078
#endif


////////////////////////////////////////
// ClassId:   00296
// RuntimeId: 05251
// TypeInfo:  0x0000000142791800
#ifndef _Component_
#define _Component_
class Component : public EntityBusPeer
{
public:
	static __inline unsigned int ClassId()
	{
		return 296;
	}
	Pointer ComponentCollection_ptr_m_collection;	// 0x08 ComponentCollection* ?
	ComponentData* m_data;				// 0x10 ComponentData*
	Pointer aucuneidee; // 0x18 voir typeinfo peutetre // ou pas un ptr ?
};//Size=0x0020
#endif

////////////////////////////////////////
// ClassId:   00297
// RuntimeId: 05707
// TypeInfo:  0x00000001427A0690
#ifndef _GameComponent_
#define _GameComponent_
class GameComponent : public Component
{
public:
	static __inline unsigned int ClassId()
	{
		return 297;
	}
	EntryComponent* m_EntryComponent; //0x0020
	char pad_0x28[0x30 - 0x28];
};//Size=0x0030
#endif

////////////////////////////////////////
// ClassId:   00298
// RuntimeId: 05667
// TypeInfo:  0x000000014279ED70
#ifndef _ClientGameComponent_
#define _ClientGameComponent_
class ClientGameComponent : public GameComponent
{
public:
	static __inline unsigned int ClassId()
	{
		return 298;
	}
	char _0x0030[8];
};//Size=0x0038
#endif

////////////////////////////////////////
// ClassId:   03619
// RuntimeId: 07605
// TypeInfo:  0x00000001427CC510
#ifndef _WeaponSuppressionData_
#define _WeaponSuppressionData_
#pragma pack(push, 8)
class WeaponSuppressionData : public DataContainer
{
public:
	static __inline WeaponSuppressionData* DefaultInstance()
	{
		return (WeaponSuppressionData*)0x00000000463C3110;
	}
	static __inline unsigned int ClassId()
	{
		return 3619;
	}
	float m_MaxMultiplier; //0x0010
	float m_MinMultiplier; //0x0014
	float m_MinDistance; //0x0018
	float m_MaxDistance; //0x001C
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01428
// RuntimeId: 03643
// TypeInfo:  0x000000014276D570
#ifndef _Asset_
#define _Asset_
#pragma pack(push, 8)
class Asset : public DataContainer
{
public:
	static __inline Asset* DefaultInstance()
	{
		return (Asset*)0x0000000046381D40;
	}
	static __inline unsigned int ClassId()
	{
		return 1428;
	}
	char* m_Name; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02127
// RuntimeId: 03699
// TypeInfo:  0x00000001427A1A60
#ifndef _GameDataContainer_
#define _GameDataContainer_
#pragma pack(push, 8)
class GameDataContainer : public DataContainer
{
public:
	static __inline GameDataContainer* DefaultInstance()
	{
		return (GameDataContainer*)0x0000000068B50840;
	}
	static __inline unsigned int ClassId()
	{
		return 2127;
	}
};//Size=0x0010
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02129
// RuntimeId: 03701
// TypeInfo:  0x00000001427A1A00
#ifndef _DataBusPeer_
#define _DataBusPeer_
#pragma pack(push, 8)
class DataBusPeer : public GameDataContainer
{
public:
	static __inline DataBusPeer* DefaultInstance()
	{
		return (DataBusPeer*)0x0000000068B509B0;
	}
	static __inline unsigned int ClassId()
	{
		return 2129;
	}
	Uint32 m_Flags; //0x0010
	char _0x0014[4];
};//Size=0x0018
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02130
// RuntimeId: 04973
// TypeInfo:  0x00000001427C1EA0
#ifndef _GameObjectData_
#define _GameObjectData_
#pragma pack(push, 8)
class GameObjectData : public DataBusPeer
{
public:
	static __inline GameObjectData* DefaultInstance()
	{
		return (GameObjectData*)0x0000000068B509E0;
	}
	static __inline unsigned int ClassId()
	{
		return 2130;
	}
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02164
// RuntimeId: 04979
// TypeInfo:  0x00000001427C1E40
#ifndef _EntityData_
#define _EntityData_
#pragma pack(push, 8)
class EntityData : public GameObjectData
{
public:
	static __inline EntityData* DefaultInstance()
	{
		return (EntityData*)0x0000000068B51F50;
	}
	static __inline unsigned int ClassId()
	{
		return 2164;
	}
};//Size=0x0018
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   03136
// RuntimeId: 03665
// TypeInfo:  0x000000014276D390
#ifndef _DynamicDataContainer_
#define _DynamicDataContainer_
#pragma pack(push, 8)
class DynamicDataContainer : public DataContainer
{
public:
	static __inline DynamicDataContainer* DefaultInstance()
	{
		return (DynamicDataContainer*)0x00000000463B8940;
	}
	static __inline unsigned int ClassId()
	{
		return 3136;
	}
	////////////////////////////////////////
	// RuntimeId: 03663
	// TypeInfo:  0x000000014276D1E8
	struct DataField
	{
		char* m_Value; //0x0000
		DataContainer* m_ValueRef; //0x0008
		__int32 m_Id; //0x0010
		FieldAccessType m_AccessType; //0x0014
	};//Size=0x0018


	Array<DataField> m_Fields; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   01776
// RuntimeId: 03667
// TypeInfo:  0x000000014276D330
#ifndef _DataBusData_
#define _DataBusData_
#pragma pack(push, 8)
class DataBusData : public Asset
{
public:
	static __inline DataBusData* DefaultInstance()
	{
		return (DataBusData*)0x0000000046389510;
	}
	static __inline unsigned int ClassId()
	{
		return 1776;
	}
	////////////////////////////////////////
	// RuntimeId: 03657
	// TypeInfo:  0x000000014276D228
	struct PropertyConnection
	{
		DataContainer* m_Source; //0x0000
		DataContainer* m_Target; //0x0008
		__int32 m_SourceFieldId; //0x0010
		__int32 m_TargetFieldId; //0x0014
		bool m_ShouldNetworkValue; //0x0018
		char _0x0019[7];
	};//Size=0x0020

	// RuntimeId: 03659
	// TypeInfo:  0x000000014276D208
	struct LinkConnection
	{
		DataContainer* m_Source; //0x0000
		DataContainer* m_Target; //0x0008
		__int32 m_SourceFieldId; //0x0010
		__int32 m_TargetFieldId; //0x0014
	};//Size=0x0018


	Array<PropertyConnection> m_PropertyConnections; //0x0018
	Array<LinkConnection> m_LinkConnections; //0x0020
	DynamicDataContainer* m_Interface; //0x0028
	unsigned __int16 m_Flags; //0x0030
	char _0x0032[6];
};//Size=0x0038
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01798
// RuntimeId: 04935
// TypeInfo:  0x00000001427C2380
#ifndef _EntityBusData_
#define _EntityBusData_
#pragma pack(push, 8)
class EntityBusData : public DataBusData
{
public:
	static __inline EntityBusData* DefaultInstance()
	{
		return (EntityBusData*)0x0000000068B495C0;
	}
	static __inline unsigned int ClassId()
	{
		return 1798;
	}

	////////////////////////////////////////
	// RuntimeId: 04873
	// TypeInfo:  0x000000014278B5C8
	struct EventSpec
	{
		__int32 m_Id; //0x0000
	};//Size=0x0004


	////////////////////////////////////////
	// RuntimeId: 04877
	// TypeInfo:  0x000000014278B748
	struct EventConnection
	{
		DataContainer* m_Source; //0x0000
		DataContainer* m_Target; //0x0008
		EventSpec m_SourceEvent; //0x0010
		EventSpec m_TargetEvent; //0x0014
		EventConnectionTargetType m_TargetType; //0x0018
		char _0x001C[4];
	};//Size=0x0020
	Array<EventConnection> m_EventConnections; //0x0038
};//Size=0x0040
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01799
// RuntimeId: 04937
// TypeInfo:  0x00000001427C2320
#ifndef _Blueprint_
#define _Blueprint_
#pragma pack(push, 8)
class Blueprint : public EntityBusData
{
public:
	static __inline Blueprint* DefaultInstance()
	{
		return (Blueprint*)0x0000000068B49620;
	}
	static __inline unsigned int ClassId()
	{
		return 1799;
	}
};//Size=0x0040
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01807
// RuntimeId: 04939
// TypeInfo:  0x00000001427C22C0
#ifndef _ObjectBlueprint_
#define _ObjectBlueprint_
#pragma pack(push, 8)
class ObjectBlueprint : public Blueprint
{
public:
	static __inline ObjectBlueprint* DefaultInstance()
	{
		return (ObjectBlueprint*)0x0000000068B49A60;
	}
	static __inline unsigned int ClassId()
	{
		return 1807;
	}
	GameObjectData* m_Object; //0x0040
};//Size=0x0048
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01820
// RuntimeId: 04903
// TypeInfo:  0x00000001427C26E0
#ifndef _EffectBlueprint_
#define _EffectBlueprint_
#pragma pack(push, 8)
class EffectBlueprint : public ObjectBlueprint
{
public:
	static __inline EffectBlueprint* DefaultInstance()
	{
		return (EffectBlueprint*)0x0000000068B49F50;
	}
	static __inline unsigned int ClassId()
	{
		return 1820;
	}
};//Size=0x0048
#pragma pack(pop)
#endif



////////////////////////////////////////
// RuntimeId: 03560
// TypeInfo:  0x00000001420DC850
struct LinearTransform
{
	Vec3 m_right; //0x0000
	Vec3 m_up; //0x0010
	Vec3 m_forward; //0x0020
	Vec3 m_trans; //0x0030
};//Size=0x0040


////////////////////////////////////////
// ClassId:   02375
// RuntimeId: 04981
// TypeInfo:  0x00000001427C1DE0
#ifndef _SpatialEntityData_
#define _SpatialEntityData_
#pragma pack(push, 16)
class SpatialEntityData : public EntityData
{
public:
	static __inline SpatialEntityData* DefaultInstance()
	{
		return (SpatialEntityData*)0x0000000068B56CC0;
	}
	static __inline unsigned int ClassId()
	{
		return 2375;
	}
	char _0x0018[8];
	LinearTransform m_Transform; //0x0020
};//Size=0x0060
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02385
// RuntimeId: 04985
// TypeInfo:  0x00000001427C1D20
#ifndef _ComponentEntityData_
#define _ComponentEntityData_
#pragma pack(push, 16)
class ComponentEntityData : public SpatialEntityData
{
public:
	static __inline ComponentEntityData* DefaultInstance()
	{
		return (ComponentEntityData*)0x0000000068B57320;
	}
	static __inline unsigned int ClassId()
	{
		return 2385;
	}
	Array<GameObjectData*> m_Components; //0x0060
	Uint8 m_ClientRuntimeComponentCount; //0x0068
	Uint8 m_ServerRuntimeComponentCount; //0x0069
	Uint8 m_ClientRuntimeTransformationCount; //0x006A
	Uint8 m_ServerRuntimeTransformationCount; //0x006B
	char _0x006C[4];
};//Size=0x0070
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02386
// RuntimeId: 04987
// TypeInfo:  0x00000001427C1CC0
#ifndef _GameComponentEntityData_
#define _GameComponentEntityData_
#pragma pack(push, 16)
class GameComponentEntityData : public ComponentEntityData
{
public:
	static __inline GameComponentEntityData* DefaultInstance()
	{
		return (GameComponentEntityData*)0x0000000068B573B0;
	}
	static __inline unsigned int ClassId()
	{
		return 2386;
	}
	Boolean m_Enabled; //0x0070
	char _0x0071[15];
};//Size=0x0080
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02398
// RuntimeId: 08017
// TypeInfo:  0x0000000142806970
#ifndef _GamePhysicsEntityData_
#define _GamePhysicsEntityData_
#pragma pack(push, 16)
class GamePhysicsEntityData : public GameComponentEntityData
{
public:
	static __inline GamePhysicsEntityData* DefaultInstance()
	{
		return (GamePhysicsEntityData*)0x0000000068B580E0;
	}
	static __inline unsigned int ClassId()
	{
		return 2398;
	}
	PhysicsEntityData* m_PhysicsData; //0x0080
	char _0x0088[8];
};//Size=0x0090
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02399
// RuntimeId: 07599
// TypeInfo:  0x0000000142800EC0
#ifndef _ProjectileEntityData_
#define _ProjectileEntityData_
#pragma pack(push, 16)
class ProjectileEntityData : public GamePhysicsEntityData
{
public:
	static __inline ProjectileEntityData* DefaultInstance()
	{
		return (ProjectileEntityData*)0x0000000068B58190;
	}
	static __inline unsigned int ClassId()
	{
		return 2399;
	}
	Float32 m_InitialSpeed; //0x0090
	Float32 m_TimeToLive; //0x0094
	Uint32 m_MaxCount; //0x0098
	Float32 m_InitMeshHideTime; //0x009C
	Float32 m_VisualConvergeDistance; //0x00A0
	Float32 m_VisualConvergenceDelay; //0x00A4
	Float32 m_VisualConvergenceDuration; //0x00A8
	Float32 m_ProxyVisualConvergenceDelay; //0x00AC
	Float32 m_ProxyVisualConvergenceDuration; //0x00B0
	char _0x00B4[4];
	ExplosionEntityData* m_Explosion; //0x00B8
	WeaponSuppressionData* m_SuppressionData; //0x00C0
	CString m_AmmunitionType; //0x00C8
	MaterialDecl m_MaterialPair; //0x00D0
	AntHitReactionWeaponType m_HitReactionWeaponType; //0x00D4
	Boolean m_DetonateOnTimeout; //0x00D8
	Boolean m_ServerProjectileDisabled; //0x00D9
	Boolean m_HideOnDetonation; //0x00DA
	char _0x00DB[5];
};//Size=0x00E0
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02401
// RuntimeId: 07603
// TypeInfo:  0x0000000142800E00
#ifndef _MeshProjectileEntityData_
#define _MeshProjectileEntityData_
#pragma pack(push, 16)
class MeshProjectileEntityData : public ProjectileEntityData
{
public:
	static __inline MeshProjectileEntityData* DefaultInstance()
	{
		return (MeshProjectileEntityData*)0x0000000068B583B0;
	}
	static __inline unsigned int ClassId()
	{
		return 2401;
	}
	Vec3 m_InitialAngularVelocity; //0x00E0
	MeshAsset* m_Mesh; //0x00F0
	EffectBlueprint* m_TrailEffect; //0x00F8
	Float32 m_InstantAttachableTestDistance; //0x0100
	Float32 m_InstantAttachableVisualConvergenceDelay; //0x0104
	Float32 m_InstantAttachableVisualConvergenceDuration; //0x0108
	Float32 m_MaxAttachableInclination; //0x010C
	Float32 m_UnspawnAfterDetonationDelay; //0x0110
	Boolean m_IsAttachable; //0x0114
	Boolean m_InstantAttachableTestUnderReticule; //0x0115
	Boolean m_ExtraDamping; //0x0116
	char _0x0117[9];
};//Size=0x0120
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02403
// RuntimeId: 07605
// TypeInfo:  0x0000000142800DA0
#ifndef _GhostedProjectileEntityData_
#define _GhostedProjectileEntityData_
#pragma pack(push, 16)
class GhostedProjectileEntityData : public MeshProjectileEntityData
{
public:
	static __inline GhostedProjectileEntityData* DefaultInstance()
	{
		return (GhostedProjectileEntityData*)0x0000000068B58680;
	}
	static __inline unsigned int ClassId()
	{
		return 2403;
	}
	Float32 m_ProxyConvergenceDelay; //0x0120
	Float32 m_ProxyConvergenceDuration; //0x0124
	Boolean m_ProxyConvergenceInstantOnAttach; //0x0128
	Boolean m_ForceProxyConvergence; //0x0129
	char _0x012A[6];
};//Size=0x0130
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02407
// RuntimeId: 09676
// TypeInfo:  0x000000014282A750
#ifndef _GrenadeEntityData_
#define _GrenadeEntityData_
#pragma pack(push, 16)
class GrenadeEntityData : public GhostedProjectileEntityData
{
public:
	static __inline GrenadeEntityData* DefaultInstance()
	{
		return (GrenadeEntityData*)0x0000000068B58D10;
	}
	static __inline unsigned int ClassId()
	{
		return 2407;
	}
	Float32 m_Gravity; //0x0130
	Float32 m_CollisionSpeedMultiplier; //0x0134
	Float32 m_MinBounceSpeed; //0x0138
	Float32 m_CollisionDamage; //0x013C
	GrenadeType m_GrenadeType; //0x0140
	char _0x0144[4];
	CString m_HudIndicatorIcon; //0x0148
	Boolean m_ShowHudIndicator; //0x0150
	char _0x0151[15];
};//Size=0x0160
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02402
// RuntimeId: 07607
// TypeInfo:  0x0000000142800D40
#ifndef _BulletEntityData_
#define _BulletEntityData_
#pragma pack(push, 16)
class BulletEntityData : public MeshProjectileEntityData
{
public:
	static __inline BulletEntityData* DefaultInstance()
	{
		return (BulletEntityData*)0x0000000068B584F0;
	}
	static __inline unsigned int ClassId()
	{
		return 2402;
	}
	SoundAsset* m_FlyBySound; //0x0120
	ExplosionEntityData* m_DudExplosion; //0x0128
	Float32 m_Gravity; //0x0130
	Float32 m_ImpactImpulse; //0x0134
	Float32 m_DetonationTimeVariation; //0x0138
	Float32 m_VehicleDetonationRadius; //0x013C
	Float32 m_VehicleDetonationActivationDelay; //0x0140
	Float32 m_FlyBySoundRadius; //0x0144
	Float32 m_FlyBySoundSpeed; //0x0148
	Float32 m_Stamina; //0x014C
	Float32 m_DistributeDamageOverTime; //0x0150
	Float32 m_StartDamage; //0x0154
	Float32 m_EndDamage; //0x0158
	Float32 m_DamageFalloffStartDistance; //0x015C
	Float32 m_DamageFalloffEndDistance; //0x0160
	Float32 m_TimeToArmExplosion; //0x0164
	Float32 m_FirstFrameTravelDistance; //0x0168
	Boolean m_HasVehicleDetonation; //0x016C
	Boolean m_InstantHit; //0x016D
	Boolean m_StopTrailEffectOnUnspawn; //0x016E
	char _0x016F[1];
};//Size=0x0170
#pragma pack(pop)
#endif




////////////////////////////////////////
// RuntimeId: 07573
// TypeInfo:  0x00000001427CBC70
struct InitialDirectionScaleByPitchData
{
	Vec3 m_InitialDirectionScale; //0x0000
	float m_Pitch; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07575
// TypeInfo:  0x00000001427CBC50
struct InitialSpeedScaleByPitchData
{
	Vec3 m_InitialSpeedScale; //0x0000
	float m_Pitch; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07577
// TypeInfo:  0x00000001427CBAD0
class ShotConfigData
{
public:
	Vec3 m_InitialPosition; //0x0000
	Vec3 m_InitialDirection; //0x0010
	Vec3 m_InitialSpeed; //0x0020
	Array<InitialDirectionScaleByPitchData> m_InitialDirectionScaleByPitch; //0x0030
	Array<InitialSpeedScaleByPitchData> m_InitialSpeedScaleByPitch; //0x0038
	float m_InheritWeaponSpeedAmount; //0x0040
	char _0x0044[4];
	ExplosionEntityData* m_MuzzleExplosion; //0x0048
	ProjectileEntityData* m_ProjectileData; //0x0050
	ProjectileEntityData* m_SecondaryProjectileData; //0x0058
	__int64 ProjectileBlueprint_ptr_m_Projectile; //0x0060
	__int64 ProjectileBlueprint_ptr_m_SecondaryProjectile; //0x0068
	float m_SpawnDelay; //0x0070
	unsigned __int32 m_NumberOfBulletsPerShell; //0x0074
	unsigned __int32 m_NumberOfBulletsPerShot; //0x0078
	unsigned __int32 m_NumberOfBulletsPerBurst; //0x007C
	bool m_RelativeTargetAiming; //0x0080
	bool m_ForceSpawnToCamera; //0x0081
	bool m_SpawnVisualAtWeaponBone; //0x0082
	bool m_ActiveForceSpawnToCamera; //0x0083
	char _0x0084[12];
};//Size=0x0090


////////////////////////////////////////
// RuntimeId: 07595
// TypeInfo:  0x00000001427CBA10
struct FireEffectData
{
	Vec3 m_Offset; //0x0000
	Vec3 m_Rotation; //0x0010
	Vec3 m_ZoomOffset; //0x0020
	Vec3 m_ZoomRotation; //0x0030
	__int64 EffectBlueprint_ptr_m_Effect; //0x0040
	bool m_UseZoomOffset; //0x0048
	bool m_UseZoomRotation; //0x0049
	bool m_DisableDuringZoom; //0x004A
	bool m_UpdateTransform; //0x004B
	bool m_StopLoopingEffects; //0x004C
	char _0x004D[3];
};//Size=0x0050


////////////////////////////////////////
// RuntimeId: 07597
// TypeInfo:  0x00000001427CB9F0
struct OverHeatData
{
	FireEffectData m_OverHeatEffect; //0x0000
	float m_HeatPerBullet; //0x0050
	float m_HeatDropPerSecond; //0x0054
	float m_OverHeatPenaltyTime; //0x0058
	float m_OverHeatThreshold; //0x005C
};//Size=0x0060


////////////////////////////////////////
// RuntimeId: 07579
// TypeInfo:  0x00000001427CBAB0
struct HoldAndReleaseData
{
	float m_MaxHoldTime; //0x0000
	float m_MinPowerModifier; //0x0004
	float m_MaxPowerModifier; //0x0008
	float m_PowerIncreasePerSecond; //0x000C
	float m_Delay; //0x0010
	float m_KilledHoldingPowerModifier; //0x0014
	bool m_ForceFireWhenKilledHolding; //0x0018
	char _0x0019[3];
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 07589
// TypeInfo:  0x00000001427CBA70
struct RecoilData
{
	float m_MaxRecoilAngleX; //0x0000
	float m_MinRecoilAngleX; //0x0004
	float m_MaxRecoilAngleY; //0x0008
	float m_MinRecoilAngleY; //0x000C
	float m_MaxRecoilAngleZ; //0x0010
	float m_MinRecoilAngleZ; //0x0014
	float m_MaxRecoilFov; //0x0018
	float m_MinRecoilFov; //0x001C
	bool m_RecoilFollowsDispersion; //0x0020
	char _0x0021[3];
};//Size=0x0024

////////////////////////////////////////
// RuntimeId: 07581
// TypeInfo:  0x00000001427CBA90
struct BoltActionData
{
	float m_BoltActionDelay; //0x0000
	float m_BoltActionTime; //0x0004
	bool m_HoldBoltActionUntilFireRelease; //0x0008
	bool m_HoldBoltActionUntilZoomRelease; //0x0009
	bool m_ForceBoltActionOnFireTrigger; //0x000A
	bool m_UnZoomOnBoltAction; //0x000B
	bool m_ReturnToZoomAfterBoltAction; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07591
// TypeInfo:  0x00000001427CBA50
struct FireLogicData
{
	HoldAndReleaseData m_HoldAndRelease; //0x0000
	BoltActionData m_BoltAction; //0x001C
	RecoilData m_Recoil; //0x002C
	__int32 m_FireInputAction; //0x0050
	__int32 m_ReloadInputAction; //0x0054
	__int32 m_CycleFireModeInputAction; //0x0058
	float m_TriggerPullWeight; //0x005C
	float m_RateOfFire; //0x0060
	float m_RateOfFireForBurst; //0x0064
	float m_ClientFireRateMultiplier; //0x0068
	float m_ReloadDelay; //0x006C
	float m_ReloadTime; //0x0070
	char _0x0074[4];
	Array<float> m_ReloadTimerArray; //0x0078
	float m_ReloadTimeBulletsLeft; //0x0080
	float m_ReloadThreshold; //0x0084
	float m_PreFireDelay; //0x0088
	float m_AutomaticDelay; //0x008C
	ReloadLogic m_ReloadLogic; //0x0090
	ReloadType m_ReloadType; //0x0094
	FireLogicType m_FireLogicType; //0x0098
	char _0x009C[4];
	Array<FireLogicType> m_FireLogicTypeArray; //0x00A0
	bool m_HoldOffReloadUntilFireRelease; //0x00A8
	bool m_HoldOffReloadUntilZoomRelease; //0x00A9
	bool m_ForceReloadActionOnFireTrigger; //0x00AA
	bool m_AlwaysAutoReload; //0x00AB
	char _0x00AC[4];
};//Size=0x00B0

////////////////////////////////////////
// RuntimeId: 07541
// TypeInfo:  0x00000001427CBB70
struct AmmoConfigData
{
	__int32 m_MagazineCapacity; //0x0000
	__int32 m_NumberOfMagazines; //0x0004
	unsigned __int32 m_TraceFrequency; //0x0008
	unsigned __int32 m_AmmoPickupMinAmount; //0x000C
	unsigned __int32 m_AmmoPickupMaxAmount; //0x0010
	float m_AutoReplenishDelay; //0x0014
	float m_AmmoBagPickupDelayMultiplier; //0x0018
	__int32 m_AmmoBagPickupAmount; //0x001C
	bool m_AutoReplenishMagazine; //0x0020
	char _0x0021[3];
};//Size=0x0024


////////////////////////////////////////
// RuntimeId: 07593
// TypeInfo:  0x00000001427CBA30
struct FiringDispersionData
{
	float m_MinAngle; //0x0000
	float m_MaxAngle; //0x0004
	float m_IncreasePerShot; //0x0008
	float m_DecreasePerSecond; //0x000C
};//Size=0x0010



////////////////////////////////////////
// RuntimeId: 03068
// TypeInfo:  0x00000001427918C0
struct UIWorldIconZoneFloats
{
	Float32 m_Interaction; //0x0000
	Float32 m_Critical; //0x0004
	Float32 m_Close; //0x0008
	Float32 m_Far; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03070
// TypeInfo:  0x00000001427918A0
struct UIWorldIconFadeConfiguration
{
	UIWorldIconZoneFloats m_ZoneFadeValues; //0x0000
	UIWorldIconZoneFloats m_ZoneLookAtFadeValues; //0x0010
};//Size=0x0020


////////////////////////////////////////
// RuntimeId: 07599
// TypeInfo:  0x00000001427CB9D0
struct WeaponDispersion
{
	FiringDispersionData m_StandDispersion; //0x0000
	FiringDispersionData m_CrouchDispersion; //0x0010
	FiringDispersionData m_ProneDispersion; //0x0020
	float m_JumpDispersionAngle; //0x0030
	float m_ProneTransitionDispersionAngle; //0x0034
	float m_MoveDispersionAngle; //0x0038
	float m_MoveZoomedDispersionAngle; //0x003C
	float m_DecreasePerSecond; //0x0040
};//Size=0x0044

////////////////////////////////////////
// ClassId:   03084
// RuntimeId: 07601
// TypeInfo:  0x00000001427CC570
#ifndef _FiringFunctionData_
#define _FiringFunctionData_
#pragma pack(push, 16)
class FiringFunctionData : public GameDataContainer
{
public:
	static __inline FiringFunctionData* DefaultInstance()
	{
		return (FiringFunctionData*)0x00000000463B6F00;
	}
	static __inline unsigned int ClassId()
	{
		return 3084;
	}
	FiringDispersionData* m_Dispersion; //0x0010 //Array<FiringDispersionData> m_Dispersion;
	WeaponDispersion m_WeaponDispersion; //0x0018
	char _0x005C[4];
	ShotConfigData m_ShotConfigData; //0x0060
	OverHeatData m_OverHeat; //0x00F0
	Array<FireEffectData> m_FireEffects1p; //0x0150
	Array<FireEffectData> m_FireEffects3p; //0x0158
	SoundAsset* m_Sound; //0x0160
	FireLogicData m_FireLogic; //0x0168
	AmmoConfigData m_Ammo; //0x0218
	float m_SelfHealTimeWhenDeployed; //0x023C
	bool m_UsePrimaryAmmo; //0x0240
	bool m_UnlimitedAmmoForAI; //0x0241
	char _0x0242[14];
};//Size=0x0250
#pragma pack(pop)
#endif


class PrimaryFire
{
public:
	BYTE pad00[0x10];                    // 0x0000
	FiringFunctionData* m_FiringData;    // 0x0010
};


////////////////////////////////////////
// ClassId:   02880
// RuntimeId: 04939
// TypeInfo:  0x000000014278D710
#ifndef _ComponentData_
#define _ComponentData_
#pragma pack(push, 16)
class ComponentData : public GameObjectData
{
public:
	static __inline ComponentData* DefaultInstance()
	{
		return (ComponentData*)0x00000000463ABBB0;
	}
	static __inline unsigned int ClassId()
	{
		return 2880;
	}
	Array<GameObjectData*> m_Components; //0x0018
	LinearTransform m_Transform; //0x0020
	bool m_Excluded; //0x0060
	char _0x0061[15];
};//Size=0x0070
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02915
// RuntimeId: 04941
// TypeInfo:  0x000000014278D6B0
#ifndef _GameComponentData_
#define _GameComponentData_
#pragma pack(push, 16)
class GameComponentData : public ComponentData
{
public:
	static __inline GameComponentData* DefaultInstance()
	{
		return (GameComponentData*)0x00000000463AD140;
	}
	static __inline unsigned int ClassId()
	{
		return 2915;
	}
};//Size=0x0070
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   02917
// RuntimeId: 06892
// TypeInfo:  0x00000001427BF590
#ifndef _BoneComponentData_
#define _BoneComponentData_
#pragma pack(push, 16)
class BoneComponentData : public GameComponentData
{
public:
	static __inline BoneComponentData* DefaultInstance()
	{
		return (BoneComponentData*)0x00000000463AD260;
	}
	static __inline unsigned int ClassId()
	{
		return 2917;
	}
};//Size=0x0070
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   00633
// RuntimeId: 05189
// TypeInfo:  0x00000001427C5240
#ifndef _SpatialEntity_
#define _SpatialEntity_
class SpatialEntity : public Entity
{
public:
	static __inline unsigned int ClassId()
	{
		return 633;
	}
	char _0x0020[8];
};//Size=0x0028
#endif


////////////////////////////////////////
// ClassId:   00746
// RuntimeId: 01043
// TypeInfo:  0x000000014275EAA0
#ifndef _ClientInteractionEntity_
#define _ClientInteractionEntity_
class ClientInteractionEntity : public SpatialEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 746;
	}
	char _0x0028[312];
};//Size=0x0160
#endif


////////////////////////////////////////
// ClassId:   00647
// RuntimeId: 05490
// TypeInfo:  0x00000001427CB060
#ifndef _ClientMapMarkerEntity_
#define _ClientMapMarkerEntity_
class ClientMapMarkerEntity : public SpatialEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 647;
	}
	char _0x0028[616];
};//Size=0x0290
#endif



////////////////////////////////////////
// ClassId:   01499
// RuntimeId: 06678
// TypeInfo:  0x00000001427ED2F0
#ifndef _UIWorldIconBehavior_
#define _UIWorldIconBehavior_
#pragma pack(push, 8)
class UIWorldIconBehavior : public Asset
{
public:
	static __inline UIWorldIconBehavior* DefaultInstance()
	{
		return (UIWorldIconBehavior*)0x0000000068B42DF0;
	}
	static __inline unsigned int ClassId()
	{
		return 1499;
	}
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01500
// RuntimeId: 03072
// TypeInfo:  0x00000001427942E0
#ifndef _BFUIWorldIconBehavior_
#define _BFUIWorldIconBehavior_
#pragma pack(push, 8)
class BFUIWorldIconBehavior : public UIWorldIconBehavior
{
public:
	static __inline BFUIWorldIconBehavior* DefaultInstance()
	{
		return (BFUIWorldIconBehavior*)0x0000000068B42E20;
	}
	static __inline unsigned int ClassId()
	{
		return 1500;
	}
	UIWorldIconFadeConfiguration m_IconFadeConfig; //0x0018
	UIWorldIconFadeConfiguration m_LabelFadeConfig; //0x0038
	UIWorldIconFadeConfiguration m_ProgressFadeConfig; //0x0058
	UIWorldIconFadeConfiguration m_DistanceFadeConfig; //0x0078
//	UIWorldZoneDistanceConfiguration m_CustomZoneDistanceConfig; //0x0098
	UIWorldZoneType m_ScaleZone; //0x00A0
	Float32 m_LowestScale; //0x00A4
	Float32 m_ScaleDistance; //0x00A8
	Boolean m_VisibleOnMinimap; //0x00AC
	Boolean m_MagneticToMinimap; //0x00AD
	Boolean m_VisibleOnScreen; //0x00AE
	Boolean m_MagneticToScreen; //0x00AF
	Boolean m_VisibleBehind; //0x00B0
	Boolean m_VisibleOnDeploy; //0x00B1
	Boolean m_ScaleOrderIcon; //0x00B2
	Boolean m_UseCustomZoneDistance; //0x00B3
	char _0x00B4[4];
};//Size=0x00B8
#pragma pack(pop)
#endif




/*class ClientExplosionPackEntity
{
public:
	virtual TypeInfo* GetType(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void GetTransform(Matrix* mTransform);

	char _0x0008[40];
	//ExplosionPackEntityData* pExplosionPackEntityData; //0x0030 ExplosionPackEntityData Rid  9619
	char _0x0038[512];
	ExplosionPackOwner* pExplosionPackOwner; //0x0238  Rid  5352
	char _0x0240[256];
	Vector4 m_position; //0x0340 
	char _0x0350[80];
	__int32 m_teamId; //0x03A0 
};*/










////////////////////////////////////////
// ClassId:   02376
// RuntimeId: 09565
// TypeInfo:  0x00000001427F6880
#ifndef _ExplosionPackEntityData_
#define _ExplosionPackEntityData_
#pragma pack(push, 16)
class ExplosionPackEntityData : public GhostedProjectileEntityData
{
public:
	static __inline ExplosionPackEntityData* DefaultInstance()
	{
		return (ExplosionPackEntityData*)0x00000000463983B0;
	}
	static __inline unsigned int ClassId()
	{
		return 2376;
	}

	Vec3 m_WorldIconOffset; //0x0130
	//SoldierDetonationData m_SoldierDetonationData; //0x0140
	char _0x0154[4];
	Array<ExplosionPackTrigger*> m_ExplosionPackTriggers; //0x0158
	float m_GravityScale; //0x0160
	float m_TimeToLiveOnPlayerDeath; //0x0164
	float m_Health; //0x0168
	float m_SpottedTime; //0x016C
	float m_DefuseRadius; //0x0170
	char _0x0174[4];
	char* m_IconName; //0x0178
	bool m_IsDestructible; //0x0180
	bool m_ReceivesExplosionDamage; //0x0181
	bool m_ShowInSpectatorUI; //0x0182
	char _0x0183[13];
};//Size=0x0190
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   00655
// RuntimeId: 05302
// TypeInfo:  0x00000001427C5EE0
#ifndef _ComponentEntity_
#define _ComponentEntity_
class ComponentEntity : public SpatialEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 655;
	}
	char _0x0028[8];
	ExplosionPackEntityData* pExplosionPackEntityData; //0x0030
	char _0x0038[8];
};//Size=0x0040
#endif


////////////////////////////////////////
// ClassId:   00656
// RuntimeId: 05759
// TypeInfo:  0x00000001427D4C80
#ifndef _GameComponentEntity_
#define _GameComponentEntity_
class GameComponentEntity : public ComponentEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 656;
	}
	char _0x0040[32];
};//Size=0x0060
#endif


////////////////////////////////////////
// ClassId:   00657
// RuntimeId: 05707
// TypeInfo:  0x00000001427D2CD0
#ifndef _ClientGameComponentEntity_
#define _ClientGameComponentEntity_
class ClientGameComponentEntity : public GameComponentEntity
{
public:

	static __inline unsigned int ClassId()
	{
		return 657;
	}
};//Size=0x0060
#endif


////////////////////////////////////////
// ClassId:   00660
// RuntimeId: 05709
// TypeInfo:  0x00000001427D2B90
#ifndef _ClientPhysicsEntity_
#define _ClientPhysicsEntity_
class ClientPhysicsEntity : public ClientGameComponentEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 660;
	}
	char _0x0060[8];
};//Size=0x0068
#endif


////////////////////////////////////////
// ClassId:   00672
// RuntimeId: 05508
// TypeInfo:  0x00000001427CB900
#ifndef _ClientProjectileEntity_
#define _ClientProjectileEntity_
class ClientProjectileEntity : public ClientPhysicsEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 672;
	}
	char _0x0068[136];
};//Size=0x00F0
#endif

class ExplosionPackOwner
{
public:
	__int64 ClientPlayerPlus8; //0x0000  Rid 29024
};

////////////////////////////////////////
// ClassId:   00677
// RuntimeId: 05506
// TypeInfo:  0x00000001427CBB80
#ifndef _ClientGhostProjectileEntity_
#define _ClientGhostProjectileEntity_
class ClientGhostProjectileEntity : public ClientProjectileEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 677;
	}
	char _0x00F0[0x238 - 0x00F0];
	ExplosionPackOwner* pExplosionPackOwner; //0x0238  Rid  5352
	char _0x240[0x260 - 0x240];
	Matrix missposition; //0x0260
	char _0x2A0[0x2E0 - 0x2A0];
};//Size=0x02E0
#endif


////////////////////////////////////////
// ClassId:   00682
// RuntimeId: 09318
// TypeInfo:  0x0000000142824770
#ifndef _ClientExplosionPackEntity_
#define _ClientExplosionPackEntity_
class ClientExplosionPackEntity : public ClientGhostProjectileEntity
{
public:
	class ExplosionPackOwner
	{
	public:
		__int64 ClientPlayerPlus8; //0x0000  Rid 29024
	};
	static __inline unsigned int ClassId()
	{
		return 682;
	}
	char _0x02E0[0x340 - 0x02E0];
	Vector4 m_position; //0x0340 
	char _0x0350[80];
	__int32 m_teamId; //0x03A0 
};//Size=0x03B0.
#endif



////////////////////////////////////////
// ClassId:   00684
// RuntimeId: 09324
// TypeInfo:  0x00000001428243B0
#ifndef _ClientSupplySphereEntity_
#define _ClientSupplySphereEntity_
class ClientSupplySphereEntity : public ClientExplosionPackEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 684;
	}
};//Size=0x03B0
#endif


////////////////////////////////////////
// ClassId:   00657
// RuntimeId: 05707
// TypeInfo:  0x00000001427D2CD0
#ifndef _ClientGameComponentEntity_
#define _ClientGameComponentEntity_
class ClientGameComponentEntity : public GameComponentEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 657;
	}
};//Size=0x0060
#endif


////////////////////////////////////////
// ClassId:   00678
// RuntimeId: 05507
// TypeInfo:  0x00000001427CB9A0
#ifndef _ClientMissileEntity_
#define _ClientMissileEntity_
class ClientMissileEntity : public ClientGhostProjectileEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 678;
	}
	char _0x02E0[576];
	Vector4 m_position; //0x0340 
	char _0x0350[80];
	__int32 m_teamId; //0x03A0 
};//Size=0x03B0
#endif


////////////////////////////////////////
// ClassId:   00679
// RuntimeId: 01054
// TypeInfo:  0x000000014275E3C0
#ifndef _VeniceClientMissileEntity_
#define _VeniceClientMissileEntity_
class VeniceClientMissileEntity : public ClientMissileEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 679;
	}
};//Size=0x0520
#endif


#ifndef _VeniceClientExplosionEntity_
#define _VeniceClientExplosionEntity_
class VeniceClientExplosionEntity : public ClientExplosionPackEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 679;
	}
};//Size=0x0520

#endif


////////////////////////////////////////
// ClassId:   00685
// RuntimeId: 05505
// TypeInfo:  0x00000001427CBC20
#ifndef _ClientBulletEntity_
#define _ClientBulletEntity_
class ClientBulletEntity : public ClientProjectileEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 678;
	}
	char _0x02E0[576];
	Vector4 m_position; //0x0340 
	char _0x0350[544];
	__int32 m_teamId; //0x0570
	
};//Size=0x03B0
#endif

#ifndef _VeniceClientBulletEntity_
#define _VeniceClientBulletEntity_
class VeniceClientBulletEntity : public ClientBulletEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 679;
	}
};//Size=0x0520

#endif


////////////////////////////////////////
// ClassId:   00659
// RuntimeId: 09279
// TypeInfo:  0x00000001428229E0
#ifndef _ClientPickupEntity_
#define _ClientPickupEntity_
class ClientPickupEntity : public ClientGameComponentEntity
{
public:
	static __inline unsigned int ClassId()
	{
		return 659;
	}
	char _0x0060[1008];
};//Size=0x0450
#endif

class VehicleAimerSettings
{
public:
	char _0x0000[24];
};
/*
class LockingControllerData
{
public:
	char _0x0000[24];
	float m_LockTime; //0x0018
	float m_UnLockTime; //0x001C
	float m_ReleaseTime; //0x0020
	float m_ReleaseOnNewTargetTime; //0x0024
	float m_SampleRate; //0x0028
	float m_HoldStillThreshold; //0x002C
	float m_CheckVisibilityLength; //0x0030
	float m_RayLength; //0x0034
	float m_AcceptanceAngle; //0x0038
	float m_AngleConstant; //0x003C
	float m_DistanceConstant; //0x0040
	float m_Sensitivity; //0x0044
	float m_MinimumLockTime; //0x0048
	char _0x004C[12];
	BYTE m_LockOnVisibleTargetsOnly; //0x0058
	BYTE m_RequireAmmoToLock; //0x0059
	BYTE m_PositionOnly; //0x005A
	BYTE m_LockOnWorldSpacePos; //0x005B
	BYTE m_LockOnEmptyVehicles; //0x005C
	BYTE m_LockOnCharacters; //0x005D
	BYTE m_IgnoreHeigthLockDistance; //0x005E
	BYTE m_LockInCombatAreaOnly; //0x005F
	char _0x0060[8];
};
*/
class LockingControllerData : public DataContainer
{
public:
	class LockingAndHomingData
	{
	public:
		WarnTarget m_WarnLock; //+0x0
		bool m_IsHoming; //+0x4
		bool m_IsGuided; //+0x5
		bool m_IsGuidedWhenZoomed; //+0x6
		bool m_IsGuidedHoming; //+0x7
		bool m_FireOnlyWhenLockedOn; //+0x8
	};

	DataContainer* m_ZoomLevelLock; //+0x10
	float m_LockTime; //+0x18
	float m_UnLockTime; //+0x1C
	float m_ReleaseTime; //+0x20
	float m_ReleaseOnNewTargetTime; //+0x24
	float m_SampleRate; //+0x28
	float m_HoldStillThreshold; //+0x2C
	float m_CheckVisibilityLength; //+0x30
	float m_RayLength; //+0x34
	float m_AcceptanceAngle; //+0x38
	float m_AngleConstant; //+0x3C
	float m_DistanceConstant; //+0x40
	float m_Sensitivity; //+0x44
	float m_MinimumLockTime; //+0x48
	LockingAndHomingData m_LockingWeaponData; //+0x4C
	bool m_LockOnVisibleTargetsOnly; //+0x58
	bool m_RequireAmmoToLock; //+0x59
	bool m_PositionOnly; //+0x5A
	bool m_LockOnWorldSpacePos; //+0x5B
	bool m_LockOnEmptyVehicles; //+0x5C
	bool m_LockOnCharacters; //+0x5D
	bool m_IgnoreHeigthLockDistance; //+0x5E
	bool m_LockInCombatAreaOnly; //+0x5F
};

class LockingWeaponData
{
public:
	char _0x0000[32];
	LockingControllerData* m_LockingController; //0x0020
	char _0x0028[8];
	__int32 m_WarnLock; //0x0030 WarnTarget
	BYTE m_OverrideLockingControllerSettings; //0x0034
	BYTE m_IsHoming; //0x0035
	BYTE m_IsGuided; //0x0036
	BYTE m_IsGuidedWhenZoomed; //0x0037
	BYTE m_IsGuidedHoming; //0x0038
	BYTE m_FireOnlyWhenLockedOn; //0x0039
	BYTE m_GuideOnlyWhenLockedOn; //0x003A
	char _0x003B[13];
};

class VisionModifier
{
public:
	char _0x0000[16];
	float m_SensingConeRange; //0x0010
	float m_SensingConeRangeWhenAlerted; //0x0014
	float m_SensingConeAngle; //0x0018
	float m_SensingConeAngleWhenAlerted; //0x001C
	float m_SensingConeAngleAbove; //0x0020
	float m_SensingConeAngleBelow; //0x0024
	__int64 m_FlashlightModifier; //0x0028
	BYTE m_AlwaysSeeHuman; //0x0030
	char _0x0031[7];
};//Size=0x0038

class BFAIWeaponData
{
public:
	char _0x0000[16];
	char* m_AssetName; //0x0010
	char _0x0018[8];
	float m_WeaponRange; //0x0020
	float m_MinimumUsageDistance; //0x0024
	float m_MaximumUsageDistance; //0x0028
	char _0x002C[52];
	__int64 m_pVehicleAimerSettings; //0x0060 VehicleAimerSettings
	VisionModifier* m_VisionModifier; //0x0068
	char _0x0070[8];
};


////////////////////////////////////////
// ClassId:   02920
// RuntimeId: 07405
// TypeInfo:  0x00000001427C7060
#ifndef _WeaponComponentData_
#define _WeaponComponentData_
#pragma pack(push, 16)
class WeaponComponentData : public BoneComponentData
{
public:
	static __inline WeaponComponentData* DefaultInstance()
	{
		return (WeaponComponentData*)0x00000000463AD530;
	}
	static __inline unsigned int ClassId()
	{
		return 2920;
	}
	Vec3 m_ProjectileSpawnOffset; //0x0070
	Vec3 m_TargetPositionOverride; //0x0080
	MeshAsset* m_WeaponMesh; //0x0090
	WeaponFiringData* m_WeaponFiring; //0x0098
	char* m_DamageGiverName; //0x00A0
	GameAIWeaponData* m_AIData; //0x00A8
	WeaponData* m_CustomWeaponType; //0x00B0
	float m_ImpulseStrength; //0x00B8
	WeaponClassification m_Classification; //0x00BC
	float m_ReloadTimeMultiplier; //0x00C0
	float m_DamageMultiplier; //0x00C4
	float m_ExplosionDamageMultiplier; //0x00C8
	float m_OverheatDropPerSecondMultiplier; //0x00CC
	float m_LockTimeMultiplier; //0x00D0
	float m_LockingAcceptanceAngleMultiplier; //0x00D4
	unsigned __int32 m_WeaponItemHash; //0x00D8
	bool m_SequentialFiring; //0x00DC
	char _0x00DD[3];
};//Size=0x00E0
#pragma pack(pop)
#endif



class WeaponCollection
{
public:
	WeaponComponentData m_Weapons[5]; //0x0000
};

class ClientWeaponComponent
{
public:
	char _0x0000[16];
	WeaponCollection* m_pWeaponComponents; //0x0010 Make this WeaponComponentData**
	char _0x0018[56];
	__int64 m_pDynamicPhysicsEntity; //0x0050 DynamicPhysicsEntity*
	char _0x0058[56];
	ClientWeapon* m_pWeapon; //0x0090
	char _0x0098[112];
};

class FiringHolderData //  SoldierWeaponData (when on foots) ou  WeaponComponentData (when on vehicles) (inventé)
{
public:
	virtual TypeInfo* GetType();
};

class WeaponFiring
{
public:
	char pad_0x0000[120];
	WeaponSway* m_pSway; //0x0078 
	char pad_0x0080[168];
	PrimaryFire* m_pPrimaryFire; //0x0128 
	char pad_0x0130[24];
	DWORD m_weaponState; //0x0148 
	DWORD m_lastWeaponState; //0x014C 
	DWORD m_nextWeaponState; //0x0150 
	char pad_0x0154[8];
	Float32 m_timeToWait; //0x015C 
	Float32 m_reloadTimer; //0x0160 
	Float32 m_holdReleaseMinDelay; //0x0164 
	Float32 m_recoilTimer; //0x0168 
	Float32 m_recoilAngleX; //0x016C 
	Float32 m_recoilAngleY; //0x0170 
	Float32 m_recoilAngleZ; //0x0174 
	Float32 m_recoilFovAngle; //0x0178 
	Float32 m_recoilTimeMultiplier; //0x017C 
	Float32 m_overheatDropMultiplier; //0x0180 
	Int32 m_primaryAmmoToFill; //0x0184 
	Int32 m_reloadStage; //0x0188 
	//Pointer m_pCharacterMeleeEntity; //0x018C 
	char pad_0x018c[8]; // Why ?
	Int32 m_externalPrimaryMagazineCapacity; //0x0194 
	char pad_0x0198[8];
	Int32 m_projectilesLoaded; //0x01A0 
	Int32 m_projectilesInMagazines; //0x01A4 
	Int32 m_numberOfProjectilesToFire; //0x01A8 
	Boolean m_hasStoppedFiring; //0x01AC 
	Boolean m_primaryFireTriggeredLastFrame; //0x01AD 
	Boolean m_isOverheated; //0x01AE 
	Boolean m_unknown; //0x01AF 
	char pad_0x01B0[8];
	DWORD m_tickCounter; //0x01B8 
	Int32 m_fireMode; //0x01BC 
	char pad_0x01C0[8];
	__int64 m_pFiringHolderData; //0x01C8  // FiringHolderData* m_pFiringHolderData; SoldierWeaponData (when on foots) ou  WeaponComponentData (when on vehicles)
};

class WeaponModifier
{
public:
	char pad_0x0000[64];
	BYTE m_breathControl; //0x0040 
	BYTE m_supportedShooting; //0x0041 
	BYTE m_unZoomOnBoltAction; //0x0042 Fixes unzoom when sniping
	BYTE m_holdBoltActionUntilZoomRelease; //0x0043 
};

class ClientWeapon
{
public:

	class ControllableFinder
	{
	public:

		class ControllableResult
		{
		public:
			char pad_0x0000[112];
			Vec3 m_Collision; //0x0070 
		};

		__int64 vtable; //0x0950 
		char pad_0x0958[88];
		Vec3 m_lastRayBegin; //0x09B0 
		Vec3 m_lastRayEnd; //0x09C0
		char pad_0x09CC[84];
		ControllableResult* m_pControllableResult; //0x0A28 
	};

	char pad_0x0000[24];
	PrimaryFire* m_pWeaponFiring;
	WeaponModifier* m_pModifier; //0x0020 
	char pad_0x0028[8];
	Vec3 m_moveSpeed; //0x0030 
	Matrix m_shootSpace; //0x0040 
	Matrix m_shootSpaceIdentity; //0x0080 
	char pad_0x00C0[464];
	float m_cameraFov; //0x0290 
	float m_weaponFov; //0x0294 
	float m_fovScaleFactor; //0x0298 
	char pad_0x029C[20];
	DWORD m_zoomLevel; //0x02B0 
	char pad_0x02B4[1692];
	ControllableFinder m_controllableFinder; //0x0950 
};

class ClientSoldierAimingEnvironment
{
public:
	char _0x0000[8];
	ClientSoldierEntity* m_soldier; //0x0008 
};//Size=0x0010

class AimAssist
{
public:
	__int64 m_data; //0x0000 
	char _0x0008[12];
	float m_yaw; //0x0014 
	float m_pitch; //0x0018 

};//Size=0x001C

class FOVTransitionData
{
public:
	enum FOVTransitionType
	{
		FOVTransitionType_Linear = 0,
		FOVTransitionType_Smooth = 1,
		FOVTransitionType_Count = 2,
	};

	char aDataContainer[16]; //+0x00 Inherited
	FOVTransitionType m_TransitionType; //+0x10
	float m_Shape; //+0x14
	float m_StartDelay; //+0x18
	float m_StartJump; //+0x1C	
	float m_EndEarly; //+0x20
	bool m_Invert; //+0x24
};

class ZoomLevelData
{
public:
	enum ZoomLevelActivateEventType
	{
		ZoomLevelActivateEventType_Disable = 0,
		ZoomLevelActivateEventType_Enable = 1,
		ZoomLevelActivateEventType_ToggleOnLightSwitch = 2,
	};
	char aDataContainer[16]; //+0x00 Inherited
	float m_FieldOfView; //+0x10
	float m_FieldOfViewSP; //+0x14
	FOVTransitionData m_FieldOfViewTransition; //+0x18
	float m_LookSpeedMultiplier; //+0x20
	float m_SprintLookSpeedMultiplier; //+0x24
	float m_MoveSpeedMultiplier; //+0x28
	float m_SwayPitchMagnitude; //+0x2C
	float m_SwayYawMagnitude; //+0x30
	float m_SupportedSwayPitchMagnitude; //+0x34
	float m_SupportedSwayYawMagnitude; //+0x38
	float m_SuppressedSwayPitchMagnitude; //+0x3C
	float m_SuppressedSwayYawMagnitude; //+0x40
	float m_SuppressedSwayMinFactor; //+0x44
	float m_TimePitchMultiplier; //+0x48
	float m_TimeYawMultiplier; //+0x4C
	float m_DispersionMultiplier; //+0x50
	float m_DispersionRotation; //+0x54
	float m_RecoilMultiplier; //+0x58
	float m_RecoilFovMultiplier; //+0x5C
	float m_CameraImpulseMultiplier; //+0x60
	float m_StartFadeToBlackAtTime; //+0x64
	float m_FadeToBlackDuration; //+0x68
	float m_StartFadeFromBlackAtTime; //+0x6C
	float m_FadeFromBlackDuration; //+0x70
	float m_ScreenExposureAreaScale; //+0x74
	ZoomLevelActivateEventType m_OnActivateEventType; //+0x78
	float m_AttractYawStrength; //+0x7C
	float m_AttractPitchStrength; //+0x80
	bool m_AllowFieldOfViewScaling; //+0x84
	bool m_FadeToBlackInZoomTransition; //+0x85
	bool m_UseFovSpecialisation; //+0x86
	bool m_UseWeaponMeshZoom1p; //+0x87
};

////////////////////////////////////////
// RuntimeId: 09488
// TypeInfo:  0x00000001427F5338
struct AimingPoseData
{
	float m_MinimumPitch; //0x0000
	float m_MaximumPitch; //0x0004
	float m_TargetingFov; //0x0008
	float m_AimSteadiness; //0x000C
	float m_SpeedMultiplier; //0x0010
	float m_RecoilMultiplier; //0x0014
};//Size=0x0018

class SoldierAimAssistData
{
public:
	char pad_0x00[0x10]; //+0x00
	__int64 m_InputPolynomial; //+0x10
	__int64 m_ZoomedInputPolynomial; //+0x18
	Vec3 m_StickyBoxScale; //+0x20
	Vec3 m_StickyDistanceScale; //+0x30
	Vec3 m_SnapBoxScale; //+0x40
	Vec3 m_SnapDistanceScale; //+0x50
	Vec3 m_EyePosOffset; //+0x60
	float m_AccelerationInputThreshold; //+0x70
	float m_AccelerationMultiplier; //+0x74
	float m_AccelerationDamping; //+0x78
	float m_AccelerationTimeThreshold; //+0x7C
	float m_SquaredAcceleration; //+0x80
	Vec2 m_MaxAcceleration; //+0x84
	float m_YawSpeedStrength; //+0x8C
	float m_PitchSpeedStrength; //+0x90
	Vec2 m_AttractDistanceFallOffs; //+0x94
	float m_AttractSoftZone; //+0x9C
	float m_AttractUserInputMultiplier; //+0xA0
	float m_AttractUserInputMultiplier_NoZoom; //+0xA4
	float m_AttractOwnSpeedInfluence; //+0xA8
	float m_AttractTargetSpeedInfluence; //+0xAC
	float m_AttractOwnRequiredMovementForMaximumAttract; //+0xB0
	float m_AttractStartInputThreshold; //+0xB4
	float m_AttractMoveInputCap; //+0xB8
	float m_AttractYawStrength; //+0xBC
	float m_AttractPitchStrength; //+0xC0
	float m_MaxToTargetAngle; //+0xC4
	float m_MaxToTargetXZAngle; //+0xC8
	float m_ViewObstructedKeepTime; //+0xCC
	float m_SnapZoomLateralSpeedLimit; //+0xD0
	float m_SnapZoomTime; //+0xD4
	float m_SnapZoomPostTimeNoInput; //+0xD8
	float m_SnapZoomPostTime; //+0xDC
	unsigned int m_SnapZoomReticlePointPriority; //+0xE0
	float m_SnapZoomAutoEngageTime; //+0xE4
	float m_SnapZoomBreakTimeAtMaxInput; //+0xE8
	float m_SnapZoomBreakMaxInput; //+0xEC
	float m_SnapZoomBreakMinAngle; //+0xF0
	float m_SnapZoomSpamGuardTime; //+0xF4
	__int64 m_SoldierBackupSkeletonCollisionData; //+0xF8
	float m_CheckBoneCenterOnlyDistance; //+0x100
	float m_DisableForcedTargetRecalcDistance; //+0x104
	float m_OverrideAimingRange; //+0x108
	float m_OverrideAimingRangeCrouch; //+0x10C
	float m_OverrideAimingRangeProne; //+0x110
	bool m_UseYawAcceleration; //+0x114
	bool m_UsePitchAcceleration; //+0x115
	bool m_SnapZoomUserShorterWeaponTime; //+0x116
	bool m_SnapZoomPostTimeDynamicPoint; //+0x117
	bool m_ForceSoldierBackupSkeletonCollisionUse; //+0x118
};

class SoldierAimingSimulationData
{
public:
	char aGameDataContainer[16]; //+0x00 Inherited
	ZoomLevelData** m_ZoomLevels; //+0x10
	bool m_ReturnToZoomAfterReload; //+0x90
	SoldierAimAssistData* m_AimAssist; //+0x18
	AimingPoseData m_StandPose; //+0x20
	AimingPoseData m_CrouchPose; //+0x38
	AimingPoseData m_PronePose; //+0x50
	float m_ZoomTransitionTime; //+0x68
	float m_ZoomTransitionTimeArray; //+0x70
	float m_FovDelayTime; //+0x78
	float m_FovTransitionTime; //+0x7C
	float m_AimingRange; //+0x80
	float m_LockAimToTargetSpeed; //+0x84
	float m_Modifiers; //+0x88
};

class ClientSoldierAimingSimulation
{
public:
	SoldierAimingSimulationData* m_data; //0x0000 
	ClientSoldierAimingEnvironment* m_environment; //0x0008 
	AimAssist* m_fpsAimer; //0x0010 
	float m_yaw; //0x0018 
	float m_pitch; //0x001C 
	float m_aimYawTimer; //0x0020 
	float m_aimPitchTimer; //0x0024 
	Vec2 m_sway; //0x0028 
	float m_DeltaTime; //0x0030 
	char _0x0034[8];
	Vec2 m_ViewDelta; //0x003C 
	char _0x0044[44];
	Matrix m_Transform; //0x0070 
	Vec3 m_Position; //0x00B0 
	Vec3 m_View; //0x00C0 
	Vec3 m_Velocity; //0x00D0 
	char _0x00E0[88];
	float m_Fov; //0x0138 
	char _0x013C[28];
	ITypeInfo* m_RayResult; //0x0158 fb::ClientSoldier, fb::ClientVehicle, Terrain etc..
	Vec3 m_RayEnd; //0x0160 
	__int32 m_RayLength; //0x0170 999 Maybe?
	float m_Unk; //0x0174 1.0f 
	float m_Unk2; //0x0178 1.0f
	char _0x017C[188];
	__int64 m_ZoomLevelData1; //0x0238 
	__int64 m_ZoomLevelData2; //0x0240

};//0x0240





////////////////////////////////////////
// RuntimeId: 07603
// TypeInfo:  0x00000001427CB9B0
struct RumbleFiringData
{
	float m_LowRumble; //0x0000
	float m_HighRumble; //0x0004
	float m_RumbleDuration; //0x0008
};//Size=0x000C


////////////////////////////////////////
// ClassId:   03085
// RuntimeId: 07609
// TypeInfo:  0x00000001427CC4B0
#ifndef _WeaponFiringData_
#define _WeaponFiringData_
#pragma pack(push, 8)
class WeaponFiringData : public GameDataContainer
{
public:
	static __inline WeaponFiringData* DefaultInstance()
	{
		return (WeaponFiringData*)0x00000000463B7170;
	}
	static __inline unsigned int ClassId()
	{
		return 3085;
	}
	FiringFunctionData* m_PrimaryFire; //0x0010
	float m_DeployTime; //0x0018
	float m_ReactivateCooldownTime; //0x001C
	float m_DisableZoomOnDeployTime; //0x0020
	float m_AltDeployTime; //0x0024
	__int32 m_AltDeployId; //0x0028
	char _0x002C[4];
	WeaponSwayData* m_WeaponSway; //0x0030
	RumbleFiringData m_Rumble; //0x0038
	float m_SupportDelayStand; //0x0044
	float m_SupportDelayProne; //0x0048
	bool m_UseAutoAiming; //0x004C
	bool m_InflictSelfDamage; //0x004D
	bool m_ShowEnemyNametagOnAim; //0x004E
	bool m_ReloadWholeMags; //0x004F
	bool m_DisableReloadWhileSprinting; //0x0050
	bool m_AbortReloadOnSprint; //0x0051
	char _0x0052[6];
};//Size=0x0058
#pragma pack(pop)
#endif



class ToolData : public DataContainer
{
public:
	bool m_IsAlwaysActive; //+0x10
};

class WeaponData : public ToolData
{
public:
	bool m_ShowLaserPaintedVehicles; //+0x18
};


class GameAIWeaponData
{
public:
	char aAsset[24]; //+0x00 Inherited
};


////////////////////////////////////////
// ClassId:   02366
// RuntimeId: 09524
// TypeInfo:  0x00000001427F6CA0
#ifndef _WeaponEntityData_
#define _WeaponEntityData_
#pragma pack(push, 16)
class WeaponEntityData : public GameComponentEntityData
{
public:
	class StringPtr
	{
	public:
		char * m_chars;    //0000 
	};
	static __inline WeaponEntityData* DefaultInstance()
	{
		return (WeaponEntityData*)0x00000000463977C0;
	}
	static __inline unsigned int ClassId()
	{
		return 2366;
	}
	WeaponClassEnum m_WeaponClass; //0x0080
	char _0x0084[4];
	Pointer WeaponStateData_ptr_m_WeaponStateData; //Array<WeaponStateData> m_WeaponStates; //0x0088
	WeaponFiringData* m_WeaponFiring; //0x0090
	WeaponData* m_CustomWeaponType; //0x0098 // MeleeWeaponData WeaponData* ZeroingWeaponData(arme primaire) LockingWeaponData (missile)?
	GameAIWeaponData* m_AIData; //0x00A0 GameAIWeaponData* (uniquement avec arme primaire)
	char _0x00A8[136];
	StringPtr m_name; //0x0130  
};//Size=0x00B0
#pragma pack(pop)
#endif




// Flags:0x29 Size:0x70 Fields:8
class HudData
{
public:
	Float32 m_CrosshairScaleMin; //+0x0
	Float32 m_CrosshairScaleMax; //+0x4
	Float32 m_CrosshairOpacityMin; //+0x8
	Float32 m_CrosshairOpacityMax; //+0xC
	Float32 m_CrosshairOpacityModifier; //+0x10
	CString m_CrosshairTypeId; //+0x18
	Pointer CrosshairTypeAsset_ptr_m_CrosshairType; //+0x20 CrosshairTypeAsset*
	Pointer LockingTypeAsset_ptr_m_LockingType; //+0x28 LockingTypeAsset*
	CString m_WeaponClass; //+0x30
	Float32 m_LowAmmoWarning; //+0x38
	Float32 m_ReloadPrompt; //+0x3C
	Int32 m_RenderTargetIndex; //+0x40
	char tosee[4];
	Pointer UIPartPropertyList_ptr_m_HudPropertyList; //+0x48 UIPartPropertyList*
	Float32 m_SeaLevelAltFreq; //+0x50
	Float32 m_CameraShakeModifier; //+0x54
	CString m_HudIcon; //+0x58
	Boolean m_ShowMinimap; //+0x60
	Boolean m_HideAmmo; //+0x61
	Boolean m_InfiniteAmmo; //+0x62
	Boolean m_HideCrosshairWhenAimOnFriend; //+0x63
	Boolean m_UseRenderTarget; //+0x64
	Boolean m_UseRangeMeter; //+0x65
	Boolean m_UseAimWarning; //+0x66
	Boolean m_UsePredictedSight; //+0x67
	Boolean m_UseWeaponOrientations; //+0x68
	Boolean m_UseVelocityVectorMarker; //+0x69
	Boolean m_UseLockingController; //+0x6A
	Boolean m_UseThrust; //+0x6B
	Boolean m_UseGForce; //+0x6C
	Boolean m_UseSkidSlip; //+0x6D
	Boolean m_UseClimbRate; //+0x6E
	char pad_0x6F[0x70 - 0x6F];
}; // size 0x70


// Flags:0x8029 Size:0x20 Fields:16
class PickupSettingsData
{
public:
	Vec3 m_MeshRenderOffset; //+0x0
	Vec3 m_MeshRenderRotation; //+0x10
}; // size 0x20

// Flags:0x8029 Size:0x50 Fields:16
class CustomizationAccessoryPivots
{
public:
	Vec3 m_BasePivotPos; //+0x0
	Vec3 m_OpticPivotPos; //+0x10
	Vec3 m_BarrelPivotPos; //+0x20
	Vec3 m_AccessoryPivotPos; //+0x30
	Vec3 m_UnderBarrelPivotPos; //+0x40
}; // size 0x50


////////////////////////////////////////
// RuntimeId: 09554
// TypeInfo:  0x00000001428299E8
struct WeaponLagEffectForceData
{
	Vec3 m_OffsetForce; //0x0000
	Vec3 m_RotationForce; //0x0010
};//Size=0x0020


////////////////////////////////////////
// RuntimeId: 09550
// TypeInfo:  0x0000000142829A28
struct WeaponLagEffectSpringData
{
	Float32 m_Constant; //0x0000
	Float32 m_Damping; //0x0004
};//Size=0x0008


////////////////////////////////////////
// RuntimeId: 09552
// TypeInfo:  0x0000000142829A08
struct WeaponLagEffectSpringVector
{
	WeaponLagEffectSpringData m_SpringX; //0x0000
	WeaponLagEffectSpringData m_SpringY; //0x0008
	WeaponLagEffectSpringData m_SpringZ; //0x0010
};//Size=0x0018


////////////////////////////////////////
// ClassId:   03622
// RuntimeId: 09556
// TypeInfo:  0x000000014282B530
#ifndef _WeaponLagSpringEffectData_
#define _WeaponLagSpringEffectData_
#pragma pack(push, 16)
class WeaponLagSpringEffectData : public DataContainer
{
public:
	static __inline WeaponLagSpringEffectData* DefaultInstance()
	{
		return (WeaponLagSpringEffectData*)0x0000000068B83180;
	}
	static __inline unsigned int ClassId()
	{
		return 3622;
	}
	WeaponLagEffectSpringVector m_OffsetSprings; //0x0010
	char _0x0028[8];
	WeaponLagEffectForceData m_JumpForces; //0x0030
	WeaponLagEffectForceData m_LandForces; //0x0050
	WeaponLagEffectForceData m_PoseUpForces; //0x0070
	WeaponLagEffectForceData m_PoseDownForces; //0x0090
	WeaponLagEffectSpringVector m_RotationSprings; //0x00B0
	Float32 m_ZoomForceModifier; //0x00C8
	char _0x00CC[4];
};//Size=0x00D0
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02033
// RuntimeId: 09558
// TypeInfo:  0x000000014282B4D0
#ifndef _FirstPersonCameraData_
#define _FirstPersonCameraData_
#pragma pack(push, 16)
class FirstPersonCameraData : public DataContainer
{
public:
	static __inline FirstPersonCameraData* DefaultInstance()
	{
		return (FirstPersonCameraData*)0x0000000068B4E900;
	}
	static __inline unsigned int ClassId()
	{
		return 2033;
	}
	WeaponLagSpringEffectData* m_WeaponSpringEffect; //0x0010
	WeaponLagSpringEffectData* m_CameraSpringEffect; //0x0018
	Vec3 m_Offset; //0x0020
	Vec3 m_WeaponBaseOffset; //0x0030
	Vec3 m_WeaponLagRotationOffset; //0x0040
	Vec3 m_Rotation; //0x0050
	Float32 m_MoveStrafeModifier; //0x0060
	Float32 m_MoveForwardModifier; //0x0064
	Float32 m_RotateYawModifier; //0x0068
	Float32 m_RotatePitchModifier; //0x006C
	Float32 m_RotateRollModifier; //0x0070
	Float32 m_ZoomMoveStrafeModifier; //0x0074
	Float32 m_ZoomMoveForwardModifier; //0x0078
	Float32 m_ZoomRotateYawModifier; //0x007C
	Float32 m_ZoomRotatePitchModifier; //0x0080
	Float32 m_ZoomRotateRollModifier; //0x0084
	Float32 m_ReleaseModifier; //0x0088
	Float32 m_ReleaseModifierPitch; //0x008C
	Float32 m_ReleaseModifierYaw; //0x0090
	Float32 m_ReleaseModifierRoll; //0x0094
	Float32 m_OffsetReleaseModifier; //0x0098
	Float32 m_ZoomReleaseModifierPitch; //0x009C
	Float32 m_ZoomReleaseModifierYaw; //0x00A0
	Float32 m_ZoomReleaseModifierRoll; //0x00A4
	Float32 m_ZoomOffsetReleaseModifier; //0x00A8
	Float32 m_RotationAdditionToOffset; //0x00AC
};//Size=0x00B0
#pragma pack(pop)
#endif

// vérifié ok 02042014
// Flags:0x35 Size:0x210 Fields:16
class SoldierWeaponData : public WeaponEntityData
{
public:
	// Flags:0xC089 Size:0x4 Fields:1
	enum QuickThrowTypeEnum
	{
		QttHand = 0,
		QttBag = 1
	}; // size 0x4

	// Flags:0xC089 Size:0x4 Fields:1
	enum WeaponAnimBaseSetEnum
	{
		wabsRif = 0,
		wabsPstl = 1,
		wabsHgr = 2,
		wabsAT = 3,
		wabsShg = 4,
		wabsLMG = 5,
		wabsBag = 6,
		wabsSnp = 7,
		wabsCount = 8,
		wabsNone = 9
	}; // size 0x4
	//char aWeaponEntityData[176] //+0x00 Inherited
	PickupSettingsData m_PickupSettings; //+0xB0
	Vec3 m_InteractionOffset; //+0xD0
	CustomizationAccessoryPivots m_CustomizationAccessoryPivots; //+0xE0
	CString m_DamageGiverName; //+0x130 AWS
	CString m_ZoomLevels; //+0x138
	CString m_WeaponModifierData; //+0x140
	Pointer SoldierAimingSimulationData_ptr_m_AimingController; //+0x148 SoldierAimingSimulationData*
	FirstPersonCameraData* m_FirstPersonCamera; //+0x150 FirstPersonCameraData*
	HudData m_Hud; //+0x158
	WeaponAnimBaseSetEnum m_AnimBaseSet; //+0x1C8
	QuickThrowTypeEnum m_QuickThrowType; //+0x1CC
	Pointer SoldierWeaponBlueprint_ptr_m_SoldierWeaponBlueprint; //+0x1D0 SoldierWeaponBlueprint*
	CString ptr_m_PersistenceId; //+0x1D8
	__int64 m_SecondaryActionInputAction; //+0x1E0
	Pointer EntityVoiceOverInfo_ptr_m_VoiceOverInfo; //+0x1E8 EntityVoiceOverInfo*
	Float32 m_WeaponFloatParam; //+0x1F0
	Float32 m_MaxRangeMeterDistance; //+0x1F4
	Pointer CustomizationAccessoryPivots_ptr_m_SocketsInWeapon; //+0x1F8 CustomizationAccessoryPivots*
	Boolean m_HideWhenOutOfAmmo; //+0x200
	Boolean m_AllowSwitchingToWeaponOutOfAmmo; //+0x201
	Boolean m_AllowSwitchingToWeaponReloading; //+0x202
	Boolean m_SwitchToPrimaryWhenOutOfAmmo; //+0x203
	Boolean m_WaitForFireBeforeSwitchToPrimaryWhenOutOfAmmo; //+0x204
	Boolean m_FireAndSwitchBackToPrevSupported; //+0x205
	Boolean m_AllowSwitchingToWeaponInVehicles; //+0x206
	Boolean m_AllowSwitchingToWeaponInWater; //+0x207
	Boolean m_LowerOnOwnTeam; //+0x208
	Boolean m_RedeployWhenSwitchingWeaponStates; //+0x209
	Boolean m_UseQuickThrowOnAutomaticSwitchback; //+0x20A
	Boolean m_EnableBreathControl; //+0x20B
	Boolean m_CanBeInSupportedShooting; //+0x20C
	Boolean m_UseDetailedRangeMeterQuery; //+0x20D
	Boolean m_IsSilenced; //+0x20E
	Boolean m_SkipFirstZoomLevel; //+0x20F

}; // Size:0x210


class ClientSoldierWeapon
{
public:
	char _0x0000[48];
	WeaponEntityData* m_data; //0x0030 
	char _0x0038[18768];
	ClientSoldierAimingSimulation* m_authorativeAiming;    //0x4988 
	char _0x4990[24];
	ClientWeapon* m_pWeapon;                            //0x49A8  
	char pad_0x49B0[16];                                //0x49B0 
	WeaponFiring* m_pPrimary;                            //0x49C0 
};

/*
class ClientSoldierWeaponsComponent
{
public:

	class ClientAnimatedSoldierWeaponHandler
	{
	public:
		ClientSoldierWeapon* m_WeaponList[7]; //0x0000 
	};

	enum WeaponSlot
	{
		M_PRIMARY = 0,
		M_SECONDARY = 1,
		M_GADGET = 2,
		M_GRENADE = 6,
		M_KNIFE = 7
	};

	char pad_0x0000[208];
	Matrix m_weaponTransform; //0x00D0 
	char pad_0x0110[1680];
	ClientAnimatedSoldierWeaponHandler* m_handler; //0x07A0 
	char pad_0x07A8[32];
	ClientAntAnimatableComponent* m_animatableComponent[2]; //0x07C8 
	ClientSoldierEntity* m_soldier; //0x07D8 
	char pad_0x07E0[456];
	WeaponSlot m_activeSlot; //0x09A8
	WeaponSlot m_lastActiveSlot; //0x09AC 
	WeaponSlot m_lastActiveWeaponSlot; //0x09B0 
	char pad_0x09B4[28];
	int m_currentZoomLevel; //0x09D0 
	int m_zoomLevelMax; //0x09D4 
	int m_zeroingDistanceLevel; //0x09D8 
	BYTE m_noMagnifierAccessory; //0x09DC 
	char pad_0x09DD[779];
	float m_timeSinceLastShot; //0x0CE8 

	ClientSoldierWeapon* GetActiveSoldierWeapon()
	{
		if (!IsValidPtr(m_handler))
			return NULL;

	//	if (m_activeSlot == 0 || m_activeSlot == 1)
			return m_handler->m_WeaponList[m_activeSlot];
	//	else
	//		return NULL;
	};
	int GetSlot()
	{
		return m_activeSlot;
		//0 or 1 is primary or secondary
	}
};

*/


class  ClientSoldierWeaponsComponent
{
public:
	class ClientAnimatedSoldierWeaponHandler
	{
	public:
		ClientSoldierWeapon* m_WeaponList[7]; //0x0000
	};

	enum WeaponSlot
	{
		M_PRIMARY = 0,
		M_SECONDARY = 1,
		M_GADGET = 2,
		M_GRENADE = 6,
		M_KNIFE = 7
	};


	char _0x0000[16];
	__int64 m_pSoldierWeaponsComponentData; //0x0010 SoldierWeaponsComponentData* Rid  9576
	char _0x0018[8];
	__int64 m_pClientPlayerEntryComponent; //0x0020 ClientPlayerEntryComponent* Rid  5562
	char _0x0038[0x0D0 - 0x038];
	Matrix m_weaponTransform; //0x00D0 
	char _0x0110[1760];
	ClientAnimatedSoldierWeaponHandler* m_handler; //0x07F0  Rid 4294938624
	char _0x07F8[32];
	ClientAntAnimatableComponent* m_animatableComponent[2]; //0x0818 ClientAntAnimatableComponent* Rid  5730
	ClientSoldierEntity* m_soldier; //0x0828 ClientSoldierEntity Rid  9280
	char _0x0830[200];
	__int64 m_pClientAimingConstraintsEntity; //0x08F8 ClientAimingConstraintsEntity* Rid  1056
	char _0x0900[248];
	__int32 m_activeSlot; //0x09F8 
	__int32 m_lastActiveSlot; //0x09FC 
	__int32 m_lastActiveWeaponSlot; //0x0A00 
	char _0x0A04[28];
	__int32 m_currentZoomLevel; //0x0A20 
	__int32 m_zoomLevelMax; //0x0A24 
	__int32 m_zeroingDistanceLevel; //0x0A28 
	BYTE m_noMagnifierAccessory; //0x0A2C 
	char _0x0A2D[779];
	float m_timeSinceLastShot; //0x0D38 

	ClientSoldierWeapon* GetActiveSoldierWeapon()
	{
		if (!IsValidPtr(m_handler))
			return NULL;

		//	if (m_activeSlot == 0 || m_activeSlot == 1)
		return m_handler->m_WeaponList[m_activeSlot];
		//	else
		//		return NULL;
	};
	int GetSlot()
	{
		return m_activeSlot;
		//0 or 1 is primary or secondary
	}
};




class Animatable
{
public:
	char pad_001[408];
	bool m_isActiveDebug;
	int     m_fovLayoutIndex;
	int     m_cameraFovSlotIndex;
	int     m_weaponFovSlotIndex;
};

class UpdatePoseResultData
{
public:

	enum BONES
	{
		BONE_HEAD = 104,
		BONE_NECK = 142,
		BONE_SPINE2 = 7,
		BONE_SPINE1 = 6,
		BONE_SPINE = 5,
		BONE_LEFTSHOULDER = 9,
		BONE_RIGHTSHOULDER = 109,
		BONE_LEFTELBOWROLL = 11,
		BONE_RIGHTELBOWROLL = 111,
		BONE_LEFTHAND = 15,
		BONE_RIGHTHAND = 115,
		BONE_LEFTKNEEROLL = 188,
		BONE_RIGHTKNEEROLL = 197,
		BONE_LEFTFOOT = 184,
		BONE_RIGHTFOOT = 198
	};

	class QuatTransform
	{
	public:
		Vec3 m_TransAndScale; // 0x0000
		Vec3 m_Rotation;  // 0x0010
	}; // Size 0x0020

	QuatTransform* m_LocalTransform;  // 0x0000
	QuatTransform* m_WorldTransform; // 0x0008
	QuatTransform* DB00147A; // 0x0010
	QuatTransform* DB00147B; // 0x0018
	QuatTransform* DB00147D; // 0x0020
	QuatTransform* m_ActiveWorldTransforms; // 0x0028
	QuatTransform* m_ActiveLocalTransforms; // 0x0030
	int m_Slot; // 0x0038
	int m_ReaderIndex;  // 0x003C
	BYTE m_ValidTransforms; // 0x0040
	BYTE m_PoseUpdateEnabled; // 0x0041
	BYTE m_PoseNeeded; // 0x0042
	BYTE pad44[0x01]; // 0x0044
};

class GameAnimatable
{
public:
	BYTE pad[0xD4];
	bool m_hadVisualUpdate;  // 0xD4 
};

class ClientAntAnimatableComponent
	// :public ClientGameComponent
{
public:
	BYTE pad00[0x68];
	GameAnimatable* m_handler;    //0x68
};

class ClientRagDollComponent
{
public:
	char pad_0x0000[136];
	UpdatePoseResultData m_ragdollTransforms; //0x0088 
	char pad_0x0090[1344];
	Matrix m_Transform; //0x05D0 
};

class BoneCollisionComponent
{
public:

	class BoneTransformInfo
	{
	public:
		Matrix transform;    // 0x00
		Vec3 position;    // 0x40
	};

	char pad_0x0000[80];
	__int64 m_skeleton; //0x0050 
	BoneTransformInfo* m_boneCollisionTransforms; //0x0058 
};



////////////////////////////////////////
// ClassId:   02393
// RuntimeId: 06551
// TypeInfo:  0x00000001427B96B0
#ifndef _ControllableEntityData_
#define _ControllableEntityData_
#pragma pack(push, 16)
class ControllableEntityData : public GamePhysicsEntityData
{
public:
	static __inline ControllableEntityData* DefaultInstance()
	{
		return (ControllableEntityData*)0x0000000046399AF0;
	}
	static __inline unsigned int ClassId()
	{
		return 2393;
	}
	TeamId m_DefaultTeam; //0x0090
	float m_LowHealthThreshold; //0x0094
	MaterialDecl m_MaterialPair; //0x0098
	bool m_UsePrediction; //0x009C
	bool m_ResetTeamOnLastPlayerExits; //0x009D
	bool m_Immortal; //0x009E
	bool m_FakeImmortal; //0x009F
	bool m_ForceForegroundRendering; //0x00A0
	char _0x00A1[15];
};//Size=0x00B0
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01742
// RuntimeId: 04945
// TypeInfo:  0x000000014278D5F0
#ifndef _DataContainerPolicyAsset_
#define _DataContainerPolicyAsset_
#pragma pack(push, 8)
class DataContainerPolicyAsset : public Asset
{
public:
	static __inline DataContainerPolicyAsset* DefaultInstance()
	{
		return (DataContainerPolicyAsset*)0x0000000046388600;
	}
	static __inline unsigned int ClassId()
	{
		return 1742;
	}
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01759
// RuntimeId: 07371
// TypeInfo:  0x00000001427C7540
#ifndef _UnlockUserDataBase_
#define _UnlockUserDataBase_
#pragma pack(push, 8)
class UnlockUserDataBase : public DataContainerPolicyAsset
{
public:
	static __inline UnlockUserDataBase* DefaultInstance()
	{
		return (UnlockUserDataBase*)0x0000000046388DD0;
	}
	static __inline unsigned int ClassId()
	{
		return 1759;
	}
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01744
// RuntimeId: 07375
// TypeInfo:  0x00000001427C74E0
#ifndef _UnlockAssetBase_
#define _UnlockAssetBase_
#pragma pack(push, 8)
class UnlockAssetBase : public DataContainerPolicyAsset
{
public:
	
	BYTE Pad_000[0x10];
	char* m_name; //Example: Gameplay/Camo/U_DICECamo
	UnlockUserDataBase* m_UnlockUserData; //0x0018
	char* m_DebugUnlockId; //0x0020 //Example: U_DICECamo
	unsigned __int32 m_Identifier; //0x0028
	unsigned __int32 m_UnlockScore; //0x002C
	UnlockAssetBase* m_NextLevelUnlockAsset; //0x0030
	UnlockAvailability m_AvailableForPlayer; //0x0038
	bool m_AutoAvailable; //0x003C
	bool m_HiddenInProgression; //0x003D
	char _0x003E[2];
};//Size=0x0040
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01775
// RuntimeId: 07435
// TypeInfo:  0x00000001427FBA10
#ifndef _UnlockAsset_
#define _UnlockAsset_
#pragma pack(push, 8)
class UnlockAsset : public UnlockAssetBase
{
public:
	static __inline UnlockAsset* DefaultInstance()
	{
		return (UnlockAsset*)0x0000000068B48BC0;
	}
	static __inline unsigned int ClassId()
	{
		return 1775;
	}
};//Size=0x0040
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01769
// RuntimeId: 07437
// TypeInfo:  0x00000001427FB9B0
#ifndef _MultiUnlockAsset_
#define _MultiUnlockAsset_
#pragma pack(push, 8)
class MultiUnlockAsset : public UnlockAssetBase
{
public:
	static __inline MultiUnlockAsset* DefaultInstance()
	{
		return (MultiUnlockAsset*)0x0000000068B48940;
	}
	static __inline unsigned int ClassId()
	{
		return 1769;
	}
	Array<UnlockAssetBase*> m_Unlocks; //0x0040
};//Size=0x0048
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 07100
// TypeInfo:  0x00000001427F24C0
struct CustomizeVisual
{
	Array<UnlockAsset*> m_Visual; //0x0000
};//Size=0x0008


////////////////////////////////////////
// ClassId:   01893
// RuntimeId: 07102
// TypeInfo:  0x00000001427F2A40
#ifndef _CustomizeCharacterData_
#define _CustomizeCharacterData_
#pragma pack(push, 8)
class CustomizeCharacterData : public Asset
{
public:
	static __inline CustomizeCharacterData* DefaultInstance()
	{
		return (CustomizeCharacterData*)0x0000000068B4B8A0;
	}
	static __inline unsigned int ClassId()
	{
		return 1893;
	}
	Array<CustomizeVisual> m_VisualGroups; //0x0018
	Array<UnlockAssetBase*> m_Unlocks; //0x0020
	Float32 m_OverrideMaxHealth; //0x0028
	Float32 m_OverrideCriticalHealthThreshold; //0x002C
	Boolean m_RestoreToOriginalVisualState; //0x0030
	Boolean m_ClearVisualState; //0x0031
	char _0x0032[6];
};//Size=0x0038
#pragma pack(pop)
#endif

class Guid
{
public:
	unsigned long m_Data1; //0x0000
	unsigned short m_Data2; //0x0004
	unsigned short m_Data3; //0x0006
	unsigned char m_Data4[8]; //0x0008
};//Size=0x0010


////////////////////////////////////////
// ClassId:   03017
// RuntimeId: 07024
// TypeInfo:  0x00000001427F3520
#ifndef _UnlockComponentData_
#define _UnlockComponentData_
#pragma pack(push, 16)
class UnlockComponentData : public GameComponentData
{
public:
	static __inline UnlockComponentData* DefaultInstance()
	{
		return (UnlockComponentData*)0x0000000068B71C20;
	}
	static __inline unsigned int ClassId()
	{
		return 3017;
	}
	UnlockAssetBase* m_UnlockAsset; //0x0070
	Guid m_UnlockAssetGuid; //0x0078
	char _0x0078[16];
	Uint32 m_UnlockIdentifier; //0x0088
	Uint32 m_UnlockDataKey; //0x008C
	Boolean m_InvertUnlockTest; //0x0090
	Boolean m_UnlockableFromAllEntries; //0x0091
	Boolean m_DeactivateCheckOnEnteringEntry; //0x0092
	char _0x0093[13];
};//Size=0x00A0
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 02489
// TypeInfo:  0x000000014275BB48
enum BattlepackItemType
{
	BattlepackItemType_Accessory, //0x0000
	BattlepackItemType_Boost, //0x0001
	BattlepackItemType_Camo, //0x0002
	BattlepackItemType_Dogtag, //0x0003
	BattlepackItemType_Emblem, //0x0004
	BattlepackItemType_Icon, //0x0005
	BattlepackItemType_Paint, //0x0006
	BattlepackItemType_Knife, //0x0007
	BattlepackItemType_Battlelog, //0x0008
	BattlepackItemType_Mixed //0x0009
};


////////////////////////////////////////
// RuntimeId: 03243
// TypeInfo:  0x0000000142767F90
enum ScoringBucket
{
	ScoringBucket_General, //0x0000
	ScoringBucket_Rank, //0x0001
	ScoringBucket_Teamwork, //0x0002
	ScoringBucket_Bonus, //0x0003
	ScoringBucket_Squad, //0x0004
	ScoringBucket_Conquest, //0x0005
	ScoringBucket_Rush, //0x0006
	ScoringBucket_Deathmatch, //0x0007
	ScoringBucket_Obliteration, //0x0008
	ScoringBucket_Domination, //0x0009
	ScoringBucket_Elimination, //0x000A
	ScoringBucket_AirSuperiority, //0x000B
	ScoringBucket_CarrierAssault, //0x000C
	ScoringBucket_Award, //0x000D
	ScoringBucket_VehicleMBT, //0x000E
	ScoringBucket_VehicleIFV, //0x000F
	ScoringBucket_VehicleAA, //0x0010
	ScoringBucket_VehicleAttackHeli, //0x0011
	ScoringBucket_VehicleScoutHeli, //0x0012
	ScoringBucket_VehicleAttackJet, //0x0013
	ScoringBucket_VehicleStealthJet, //0x0014
	ScoringBucket_VehicleAttackBoat, //0x0015
	ScoringBucket_VehicleDrone, //0x0016
	ScoringBucket_VehicleBomber, //0x0017
	ScoringBucket_KitAssault, //0x0018
	ScoringBucket_KitEngineer, //0x0019
	ScoringBucket_KitRecon, //0x001A
	ScoringBucket_KitSupport, //0x001B
	ScoringBucket_SinglePlayer, //0x001C
	ScoringBucket_Cooperation, //0x001D
	ScoringBucket_CoopIndivid, //0x001E
	ScoringBucket_Unlock, //0x001F
	ScoringBucket_AssaultRifles, //0x0020
	ScoringBucket_Carbines, //0x0021
	ScoringBucket_SniperRifles, //0x0022
	ScoringBucket_LMGs, //0x0023
	ScoringBucket_Shotguns, //0x0024
	ScoringBucket_PDWs, //0x0025
	ScoringBucket_DMRs, //0x0026
	ScoringBucket_Handguns, //0x0027
	ScoringBucket_RocketLaunchers, //0x0028
	ScoringBucket_HandGranades, //0x0029
	ScoringBucket_UnderslungLaunchers, //0x002A
	ScoringBucket_Commander, //0x002B
	ScoringBucket_CaptureTheFlag, //0x002C
	ScoringBucket_LastScoringBucketItem //0x002D
};


////////////////////////////////////////
// RuntimeId: 03350
// TypeInfo:  0x000000014279CCF8
struct ScoringBucketModifierData
{
	ScoringBucket m_Bucket; //0x0000
	Float32 m_Modifier; //0x0004
};//Size=0x0008

////////////////////////////////////////
// ClassId:   01490
// RuntimeId: 02632
// TypeInfo:  0x00000001427984E0
#ifndef _BoostData_
#define _BoostData_
#pragma pack(push, 8)
class BoostData : public Asset
{
public:
	static __inline BoostData* DefaultInstance()
	{
		return (BoostData*)0x0000000068B42B30;
	}
	static __inline unsigned int ClassId()
	{
		return 1490;
	}
	CString m_Key; //0x0018
	Float32 m_ScoreModifier; //0x0020
	char _0x0024[4];
	Array<ScoringBucketModifierData> m_ScoringBucketModifiers; //0x0028
	Uint32 m_Identifier; //0x0030
	char _0x0034[4];
};//Size=0x0038
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   01917
// RuntimeId: 02626
// TypeInfo:  0x0000000142798540
#ifndef _BattlepackPool_
#define _BattlepackPool_
#pragma pack(push, 8)
class BattlepackPool : public Asset
{
public:
	static __inline BattlepackPool* DefaultInstance()
	{
		return (BattlepackPool*)0x0000000068B4C2E0;
	}
	static __inline unsigned int ClassId()
	{
		return 1917;
	}
	CString m_Key; //0x0018
	CString m_Label; //0x0020
	CString m_Description; //0x0028
	RarenessLevel m_RarenessLevel; //0x0030
	BattlepackItemType m_BattlepackItemType; //0x0034
	Array<UnlockAssetBase*> m_BattlepackItems; //0x0038
	Array<BoostData*> m_Boosts; //0x0040
};//Size=0x0048
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03201
// RuntimeId: 07039
// TypeInfo:  0x00000001427BE510
#ifndef _CustomizationUnlockParts_
#define _CustomizationUnlockParts_
#pragma pack(push, 8)
class CustomizationUnlockParts : public DataContainer
{
public:
	BYTE Pad_000[0x10];
	char* m_UICategorySid;
	DWORD m_defaultSelectionIndex;
	Array<DWORD_PTR> m_SelectableUnlocks;
	/*
	//Array<DWORD_PTR> m_SelectableUnlocks;
	//ou
	char _0x001C[4];
	Array<UnlockAssetBase*> m_SelectableUnlocks;
	*/
};//Size=0x0028
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   03542
// RuntimeId: 07037
// TypeInfo:  0x00000001427BE570
#ifndef _CustomizationTable_
#define _CustomizationTable_
#pragma pack(push, 8)
class CustomizationTable : public DataContainer
{
public:
	static __inline CustomizationTable* DefaultInstance()
	{
		return (CustomizationTable*)0x00000000463C1710;
	}
	static __inline unsigned int ClassId()
	{
		return 3542;
	}
	Array<CustomizationUnlockParts*> m_UnlockParts; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01766
// RuntimeId: 07043
// TypeInfo:  0x00000001427BE4B0
#ifndef _VehicleCustomizationAsset_
#define _VehicleCustomizationAsset_
#pragma pack(push, 8)
class VehicleCustomizationAsset : public DataContainerPolicyAsset
{
public:
	static __inline VehicleCustomizationAsset* DefaultInstance()
	{
		return (VehicleCustomizationAsset*)0x0000000046388F80;
	}
	static __inline unsigned int ClassId()
	{
		return 1766;
	}
	CustomizationTable* m_Customization; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01733
// RuntimeId: 08090
// TypeInfo:  0x00000001427D60E0
#ifndef _TextureBaseAsset_
#define _TextureBaseAsset_
#pragma pack(push, 8)
class TextureBaseAsset : public Asset
{
public:
	static __inline TextureBaseAsset* DefaultInstance()
	{
		return (TextureBaseAsset*)0x00000000463883A0;
	}
	static __inline unsigned int ClassId()
	{
		return 1733;
	}
	// unhandled basic type ResourceRef m_Resource; //0x0018
	char _0x0018[8];
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01734
// RuntimeId: 08092
// TypeInfo:  0x00000001427D6080
#ifndef _TextureAsset_
#define _TextureAsset_
#pragma pack(push, 8)
class TextureAsset : public TextureBaseAsset
{
public:
	static __inline TextureAsset* DefaultInstance()
	{
		return (TextureAsset*)0x00000000463883E0;
	}
	static __inline unsigned int ClassId()
	{
		return 1734;
	}
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 07471
// TypeInfo:  0x00000001427C5D60
struct VehicleHudData
{
	Vec3 m_CustomizationOffset; //0x0000
	VehicleCustomizationAsset* m_Customization; //0x0010
	UIHudIcon m_MinimapIcon; //0x0018
	char _0x001C[4];
	char* m_IconName; //0x0020
	TextureAsset* m_Texture; //0x0028
	unsigned __int32 m_VehicleItemHash; //0x0030
	bool m_RotateInMap; //0x0034
	bool m_ShowHealth; //0x0035
	char _0x0036[10];
};//Size=0x0040


////////////////////////////////////////
// ClassId:   03851
// RuntimeId: 07881
// TypeInfo:  0x00000001427D2DA0
#ifndef _Curve2D_
#define _Curve2D_
#pragma pack(push, 8)
class Curve2D : public DataContainer
{
public:
	static __inline Curve2D* DefaultInstance()
	{
		return (Curve2D*)0x00000000463C8940;
	}
	static __inline unsigned int ClassId()
	{
		return 3851;
	}
	Array<Vec2> m_Curve; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif

////////////////////////////////////////
// RuntimeId: 07473
// TypeInfo:  0x00000001427C5D40
struct VehicleHealthZoneData
{
	float m_MaxHealth; //0x0000
	float m_MaxShieldHealth; //0x0004
	float m_MinDamageAngle; //0x0008
	float m_DamageAngleMultiplier; //0x000C
	Curve2D* m_DamageAngleMultiplierCurve; //0x0010
	float m_VerticalFactor; //0x0018
	bool m_UseDamageAngleCalculation; //0x001C
	char _0x001D[3];
};//Size=0x0020


////////////////////////////////////////
// ClassId:   01727
// RuntimeId: 08131
// TypeInfo:  0x00000001427DA390
#ifndef _MeshLodGroup_
#define _MeshLodGroup_
#pragma pack(push, 8)
class MeshLodGroup : public Asset
{
public:
	static __inline MeshLodGroup* DefaultInstance()
	{
		return (MeshLodGroup*)0x0000000046388010;
	}
	static __inline unsigned int ClassId()
	{
		return 1727;
	}
	float m_Lod1Distance; //0x0018
	float m_Lod2Distance; //0x001C
	float m_Lod3Distance; //0x0020
	float m_Lod4Distance; //0x0024
	float m_Lod5Distance; //0x0028
	float m_Lod6Distance; //0x002C
	float m_ShadowDistance; //0x0030
	float m_CullScreenArea; //0x0034
	char* m_RuntimeShortName; //0x0038
};//Size=0x0040
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02098
// RuntimeId: 08135
// TypeInfo:  0x00000001427DA330
#ifndef _ProceduralAnimationTypeSimple_
#define _ProceduralAnimationTypeSimple_
#pragma pack(push, 8)
class ProceduralAnimationTypeSimple : public DataContainer
{
public:
	static __inline ProceduralAnimationTypeSimple* DefaultInstance()
	{
		return (ProceduralAnimationTypeSimple*)0x00000000463905E0;
	}
	static __inline unsigned int ClassId()
	{
		return 2098;
	}
	float m_BendMultiplier; //0x0010
	float m_WiggleSpeedMultiplier; //0x0014
	float m_WindInfluenceMultiplier; //0x0018
	char _0x001C[4];
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01465
// RuntimeId: 08249
// TypeInfo:  0x00000001427D9910
#ifndef _SurfaceShaderBaseAsset_
#define _SurfaceShaderBaseAsset_
#pragma pack(push, 8)
class SurfaceShaderBaseAsset : public Asset
{
public:
	static __inline SurfaceShaderBaseAsset* DefaultInstance()
	{
		return (SurfaceShaderBaseAsset*)0x0000000046382A00;
	}
	static __inline unsigned int ClassId()
	{
		return 1465;
	}
};//Size=0x0018
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03540
// RuntimeId: 08251
// TypeInfo:  0x00000001427D98B0
#ifndef _SurfaceShaderInstanceData_
#define _SurfaceShaderInstanceData_
#pragma pack(push, 8)
class SurfaceShaderInstanceData : public DataContainer
{
public:
	static __inline SurfaceShaderInstanceData* DefaultInstance()
	{
		return (SurfaceShaderInstanceData*)0x00000000463C1670;
	}
	static __inline unsigned int ClassId()
	{
		return 3540;
	}
	SurfaceShaderBaseAsset* m_Shader; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03135
// RuntimeId: 08153
// TypeInfo:  0x00000001427DA090
#ifndef _MeshMaterial_
#define _MeshMaterial_
#pragma pack(push, 8)
class MeshMaterial : public DataContainer
{
public:
	static __inline MeshMaterial* DefaultInstance()
	{
		return (MeshMaterial*)0x00000000463B88B0;
	}
	static __inline unsigned int ClassId()
	{
		return 3135;
	}
	
	////////////////////////////////////////
	// RuntimeId: 08241
	// TypeInfo:  0x00000001427D9548
	struct BoolShaderParameter
	{
		char* m_ParameterName; //0x0000
		bool m_Value; //0x0008
		char _0x0009[7];
	};//Size=0x0010

	////////////////////////////////////////
	// RuntimeId: 03554
	// TypeInfo:  0x00000001420DC810
	struct Vec4
	{
		float m_x; //0x0000
		float m_y; //0x0004
		float m_z; //0x0008
		float m_w; //0x000C
	};//Size=0x0010

	// RuntimeId: 08243
	// TypeInfo:  0x00000001427D9528
	struct VectorShaderParameter
	{
		Vec4 m_Value; //0x0000
		char* m_ParameterName; //0x0010
		ShaderParameterType m_ParameterType; //0x0018
		char _0x001C[4];
	};//Size=0x0020


	
	////////////////////////////////////////
	// RuntimeId: 08247
	// TypeInfo:  0x00000001427D94E8
	struct VectorArrayShaderParameter
	{
		char* m_ParameterName; //0x0000
		ShaderParameterType m_ParameterType; //0x0008
		char _0x000C[4];
		Array<Vec4> m_Values; //0x0010
	};//Size=0x0018


	////////////////////////////////////////
	// RuntimeId: 08245
	// TypeInfo:  0x00000001427D9508
	struct TextureShaderParameter
	{
		char* m_ParameterName; //0x0000
		TextureBaseAsset* m_Value; //0x0008
	};//Size=0x0010

	////////////////////////////////////////
	// RuntimeId: 08253
	// TypeInfo:  0x00000001427D9388
	struct SurfaceShaderInstanceDataStruct
	{
		SurfaceShaderBaseAsset* m_Shader; //0x0000
		Array<BoolShaderParameter> m_BoolParameters; //0x0008
		Array<VectorShaderParameter> m_VectorParameters; //0x0010
		Array<VectorArrayShaderParameter> m_VectorArrayParameters; //0x0018
		Array<TextureShaderParameter> m_TextureParameters; //0x0020
	};//Size=0x0028



	SurfaceShaderInstanceData* m_ShaderInstance; //0x0010
	SurfaceShaderInstanceDataStruct m_Shader; //0x0018
	ShaderTessellationType m_TessellationType; //0x0040
	float m_TessellationTriangleSize; //0x0044
	float m_TessellationMaxDistance; //0x0048
	float m_BackFaceCullEpsilon; //0x004C
	float m_ShapeFactor; //0x0050
	char _0x0054[4];
	TextureAsset* m_DisplacementMap; //0x0058
	float m_DisplacementScale; //0x0060
	float m_DisplacementBias; //0x0064
	unsigned __int32 m_DisplacementMapTexCoord; //0x0068
	bool m_SmoothEdgeVertices; //0x006C
	char _0x006D[3];
};//Size=0x0070
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01432
// RuntimeId: 08145
// TypeInfo:  0x00000001427DA210
#ifndef _MeshAsset_
#define _MeshAsset_
#pragma pack(push, 8)
class MeshAsset : public Asset
{
public:
	static __inline MeshAsset* DefaultInstance()
	{
		return (MeshAsset*)0x0000000046381E10;
	}
	static __inline unsigned int ClassId()
	{
		return 1432;
	}
	MeshLodGroup* m_LodGroup; //0x0018
	// unhandled basic type ResourceRef m_MeshSetResource; //0x0020
	char _0x0020[8];
	// unhandled basic type ResourceRef m_OccluderMeshResource; //0x0028
	char _0x0028[8];
	float m_LodScale; //0x0030
	float m_CullScale; //0x0034
	float m_CoverageValue; //0x0038
	EnlightenType m_EnlightenType; //0x003C
	ProceduralAnimationTypeSimple* m_ProceduralAnimation; //0x0040
	Array<MeshMaterial*> m_Materials; //0x0048
	unsigned __int32 m_NameHash; //0x0050
	bool m_StreamingEnable; //0x0054
	bool m_OccluderMeshEnable; //0x0055
	bool m_OccluderHighPriority; //0x0056
	bool m_OccluderIsConservative; //0x0057
	bool m_DestructionMaterialEnable; //0x0058
	char _0x0059[7];
};//Size=0x0060
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01435
// RuntimeId: 08151
// TypeInfo:  0x00000001427DA0F0
#ifndef _CompositeMeshAsset_
#define _CompositeMeshAsset_
#pragma pack(push, 8)
class CompositeMeshAsset : public MeshAsset
{
public:
	static __inline CompositeMeshAsset* DefaultInstance()
	{
		return (CompositeMeshAsset*)0x0000000046381FB0;
	}
	static __inline unsigned int ClassId()
	{
		return 1435;
	}
};//Size=0x0060
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02394
// RuntimeId: 07487
// TypeInfo:  0x00000001427C6640
#ifndef _VehicleEntityData_
#define _VehicleEntityData_
#pragma pack(push, 16)
class VehicleEntityData : public ControllableEntityData
{
public:
	static __inline VehicleEntityData* DefaultInstance()
	{
		return (VehicleEntityData*)0x0000000046399BC0;
	}
	static __inline unsigned int ClassId()
	{
		return 2394;
	}

	////////////////////////////////////////
	// RuntimeId: 07475
	// TypeInfo:  0x00000001427C5D20
	struct MPModeData
	{
		__int32 m_VehiclePoints; //0x0000
	};//Size=0x0004

	////////////////////////////////////////
	// RuntimeId: 07477
	// TypeInfo:  0x00000001427C5D00
	struct AngleOfImpactData
	{
		float m_Zone12Delimiter; //0x0000
		float m_Zone23Delimiter; //0x0004
		float m_Zone1Multiplier; //0x0008
		float m_Zone2Multiplier; //0x000C
		float m_Zone3Multiplier; //0x0010
		bool m_Enabled; //0x0014
		char _0x0015[3];
	};//Size=0x0018

	////////////////////////////////////////
	// RuntimeId: 07479
	// TypeInfo:  0x00000001427C5CE0
	struct VehicleLockableInfoData
	{
		float m_HeatSignature; //0x0000
		float m_RadarSignature; //0x0004
		float m_LowAltitudeHeight; //0x0008
		float m_LowAltitudeHeatSignature; //0x000C
	};//Size=0x0010


	Vec3 m_CriticallyDamagedEffectPosition; //0x00B0
	Vec3 m_PreExplosionEffectPosition; //0x00C0
	VehicleHudData m_HudData; //0x00D0
	Vec3 m_FLIRKeyColor; //0x0110
	Vec3 m_InteractionOffset; //0x0120
	char* m_ControllableType; //0x0130
	float m_DisabledDamageThreshold; //0x0138
	float m_ClearDisabledDamageThreshold; //0x013C
	float m_PreDestructionDamageThreshold; //0x0140
	char _0x0144[4];
	VehicleHealthZoneData m_FrontHealthZone; //0x0148
	VehicleHealthZoneData m_RearHealthZone; //0x0168
	VehicleHealthZoneData m_LeftHealthZone; //0x0188
	VehicleHealthZoneData m_RightHealthZone; //0x01A8
	VehicleHealthZoneData m_TopHealthZone; //0x01C8
	float m_TopHitHeight; //0x01E8
	float m_TopHitAngle; //0x01EC
	float m_RegenerationDelay; //0x01F0
	float m_RegenerationRate; //0x01F4
	float m_ArmorMultiplier; //0x01F8
	float m_RegenerationDelayMultiplier; //0x01FC
	float m_RegenerationRateMultiplier; //0x0200
	float m_EmergencyRepairHealth; //0x0204
	float m_DecayDelay; //0x0208
	float m_DecayRate; //0x020C
	EffectBlueprint* m_CriticallyDamagedEffect; //0x0210
	float m_CriticalDamageTime; //0x0218
	char _0x021C[4];
	EffectBlueprint* m_PreExplosionEffect; //0x0220
	float m_PreExplosionTime; //0x0228
	char _0x022C[4];
	ExplosionEntityData* m_Explosion; //0x0230
	CompositeMeshAsset* m_Mesh; //0x0238
	ObjectBlueprint* m_CockpitMesh; //0x0240
	char* m_NameSid; //0x0248
	__int32 m_MaxPlayersInVehicle; //0x0250
	float m_MinSpeedForMineActivation; //0x0254
	float m_UpsideDownDamage; //0x0258
	float m_UpsideDownDamageDelay; //0x025C
	float m_UpsideDownAngle; //0x0260
	float m_WaterDamage; //0x0264
	float m_BelowWaterDamageDelay; //0x0268
	float m_WaterDamageOffset; //0x026C
	float m_VelocityDamageThreshold; //0x0270
	float m_VelocityDamageMagnifier; //0x0274
	float m_RepairRateModifier; //0x0278
	float m_KillSoldierCollisionSpeedThreshold; //0x027C
	float m_ExitSpeedThreshold; //0x0280
	float m_ExitDirectionSpeedThreshold; //0x0284
	float m_FLIRValue; //0x0288
	MPModeData m_MPMode; //0x028C
	float m_ExitCameraSwitchDelay; //0x0290
	AngleOfImpactData m_AngleOfImpact; //0x0294
	float m_LockingTimeMultiplier; //0x02AC
	VehicleLockableInfoData m_VehicleLockableInfo; //0x02B0
	float m_HighAltitudeLockHeight; //0x02C0
	char _0x02C4[4];
	__int64 VehicleSoundData_ptr_m_Sound; //0x02C8 VehicleSoundData*
	__int64 EntityVoiceOverInfo_ptr_m_VoiceOverInfo; //0x02D0 EntityVoiceOverInfo*
	float m_NametagHeightScale; //0x02D8
	float m_SpottingFovScale; //0x02DC
	bool m_AllowVehicleOutsideCombatAreas; //0x02E0
	bool m_UseTopZone; //0x02E1
	bool m_HealthZonesShareDamage; //0x02E2
	bool m_UseProtectedShields; //0x02E3
	bool m_ShowPlayerHealth; //0x02E4
	bool m_ForegroundRenderCockpitMesh; //0x02E5
	bool m_MotionBlurMask; //0x02E6
	bool m_SuppressDamageByPassengers; //0x02E7
	bool m_IsAffectedByEMP; //0x02E8
	bool m_CanTakeDynamicFireDamage; //0x02E9
	bool m_ThrowOutSoldierInsideOnWaterDamage; //0x02EA
	bool m_IgnoreSoldierCollisionNormal; //0x02EB
	bool m_ChoseExitPointByDirection; //0x02EC
	bool m_ExitAllowed; //0x02ED
	bool m_EnableGroundmapLighting; //0x02EE
	bool m_UseAsTeamSpawner; //0x02EF
	bool m_IsLockable; //0x02F0
	bool m_NeverReportVehicleAsEmpty; //0x02F1
	bool m_UseLowAltitudeHeatSignature; //0x02F2
	bool m_UseSpottingTargetComponentForRaycast; //0x02F3
	bool m_EquipmentFakeVehicle; //0x02F4
	bool m_ExplosionPacksAttachable; //0x02F5
	bool m_DamageGiverOverrideOwnerVehicle; //0x02F6
	char _0x02F7[9];
};//Size=0x0300
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01724
// RuntimeId: 07941
// TypeInfo:  0x00000001427D2620
#ifndef _HavokAsset_
#define _HavokAsset_
#pragma pack(push, 8)
class HavokAsset : public Asset
{
public:
	static __inline HavokAsset* DefaultInstance()
	{
		return (HavokAsset*)0x0000000046387F10;
	}
	static __inline unsigned int ClassId()
	{
		return 1724;
	}
	Array<__int32> m_NumShapeKeysInContactPointProperties; //0x0018
	// unhandled basic type ResourceRef m_Resource; //0x0020
	char _0x0020[8];
	Array<DataContainer*> m_ExternalAssets; //0x0028
};//Size=0x0030
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02517
// RuntimeId: 07985
// TypeInfo:  0x00000001427D2140
#ifndef _RigidBodyData_
#define _RigidBodyData_
#pragma pack(push, 16)
class RigidBodyData : public EntityData
{
public:
	static __inline RigidBodyData* DefaultInstance()
	{
		return (RigidBodyData*)0x000000004639FD80;
	}
	static __inline unsigned int ClassId()
	{
		return 2517;
	}
	RigidBodyType m_RigidBodyType; //0x0018
	char _0x001C[4];
	Vec3 m_InertiaModifier; //0x0020
	LinearTransform m_Transform; //0x0030
	LinearTransform m_KeyframeTransform; //0x0070
	float m_Mass; //0x00B0
	float m_Friction; //0x00B4
	float m_Restitution; //0x00B8
	float m_AngularVelocityDamping; //0x00BC
	float m_LinearVelocityDamping; //0x00C0
	unsigned __int32 m_InteractionToolkitCollisionVolumeId; //0x00C4
	RigidBodyMotionType m_MotionType; //0x00C8
	RigidBodyQualityType m_QualityType; //0x00CC
	RigidBodyCollisionLayer m_CollisionLayer; //0x00D0
	char _0x00D4[4];
	Array<unsigned __int32> m_PartIndices; //0x00D8
	FloatPhysicsData* m_FloatPhysics; //0x00E0
	bool m_IsRootController; //0x00E8
	char _0x00E9[7];
};//Size=0x00F0
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02792
// RuntimeId: 07987
// TypeInfo:  0x00000001427D20E0
#ifndef _PhysicsConstraintData_
#define _PhysicsConstraintData_
#pragma pack(push, 16)
class PhysicsConstraintData : public EntityData
{
public:
	static __inline PhysicsConstraintData* DefaultInstance()
	{
		return (PhysicsConstraintData*)0x00000000463A9B40;
	}
	static __inline unsigned int ClassId()
	{
		return 2792;
	}
	float m_BreakThreshold; //0x0018
	char _0x001C[4];
	LinearTransform m_Transform; //0x0020
	Realm m_Realm; //0x0060
	bool m_IsBreakable; //0x0064
	bool m_Stabilized; //0x0065
	bool m_EnableContinuousSimulation; //0x0066
	char _0x0067[9];
};//Size=0x0070
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03735
// RuntimeId: 07995
// TypeInfo:  0x00000001427D1F60
#ifndef _FloatPhysicsData_
#define _FloatPhysicsData_
#pragma pack(push, 8)
class FloatPhysicsData : public DataContainer
{
public:
	static __inline FloatPhysicsData* DefaultInstance()
	{
		return (FloatPhysicsData*)0x00000000463C6100;
	}
	static __inline unsigned int ClassId()
	{
		return 3735;
	}
	float m_Density; //0x0010
	float m_FilledDensity; //0x0014
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02817
// RuntimeId: 07953
// TypeInfo:  0x00000001427D24A0
#ifndef _PhysicsEntityData_
#define _PhysicsEntityData_
#pragma pack(push, 16)
class PhysicsEntityData : public EntityData
{
public:
	static __inline PhysicsEntityData* DefaultInstance()
	{
		return (PhysicsEntityData*)0x00000000463AA400;
	}
	static __inline unsigned int ClassId()
	{
		return 2817;
	}
	HavokAsset* m_Asset; //0x0018
	Vec3 m_InertiaModifier; //0x0020
	Array<RigidBodyData*> m_RigidBodies; //0x0030
	FloatPhysicsData* m_FloatPhysics; //0x0038
	float m_Mass; //0x0040
	float m_Friction; //0x0044
	float m_Restitution; //0x0048
	float m_AngularVelocityDamping; //0x004C
	float m_LinearVelocityDamping; //0x0050
	char _0x0054[4];
	ProximityData* m_Proximity; //0x0058
	Array<PhysicsConstraintData*> m_Constraints; //0x0060
	bool m_MovableParts; //0x0068
	bool m_IsComposite; //0x0069
	char _0x006A[6];
};//Size=0x0070
#pragma pack(pop)
#endif


class Tempclass
{
public:
	virtual DWORD_PTR GetType(); //
};//Size=0x0040

class Components
{
public:
	__int64 unk1; //0x0000 
	__int64 unk2; //0x0008 
	char _0x0010[16];
	Tempclass** m_ppComponents; //0x0020 
	char _0x0028[76];
	float m_timeElapsed; //0x0074 

	void Dump()
	{
		int sectionCount = 0;
		int numSections = 0;

		for (int i = 0; i < 281; i++)
		{
			if (m_ppComponents[i])
			{
				printf("Object %p", m_ppComponents[i]); // Pointer
				printf(" Type: %I64X", m_ppComponents[i]->GetType());
				printf(" (%s)\n", **(char***)m_ppComponents[i]->GetType());
				sectionCount++;
			}
			else {
				printf("--section size: %d\n\n", sectionCount);
				sectionCount = 0;
				numSections++;
			}
		}

		printf("TOTAL SECTIONS: %d\n", numSections);
	}
};


class ClientControllableEntity
{
public:
	class HealthComponent
	{
	public:
		char _0x0000[32];
		float m_Health; //0x0020 
		float m_MaxHealth; //0x0024 
		char _0x0028[16];
		float m_vehicleHealth; //0x0038 
	};//Size=0x003C

	virtual TypeInfo* GetType();
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual VehicleEntityData* GetData(); // jd62
	virtual Components* GetComponents(); // jd62
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void GetTransform(Matrix* mTransform);
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27();
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual PhysicsEntity* GetPhysiscsEntity(); //physics
	virtual Vec3* GetVelocity(); //velocity
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //

	char _0x0008[40];
	//Components* m_pComponents; //0x0028 
	VehicleEntityData* m_data; //0x0030 
	char _0x0038[28];
	byte presenceInsideVehicle; //0x0054 si un ou plusieur dans le vehicle 1 sinon 0
	char _0x0055[143];
	int vehicleLiveBarShowBool; //0x00E4 visible 1 invisible 0
	char _0x00E8[88];
	HealthComponent* m_pHealthComponent; //0x0140 
	char _0x0148[12];
	byte positioninsideVehicle; // 0x154 (0 driver 1 gunner >2 passengers etc....) 
	char _0x0155[51];
};//Size=0x0188

class ClientCharacterEntity : public ClientControllableEntity
{
public:
	char pad_0x0188[80]; //72 with vt? 0x30
	//CharacterPhysicsEntity* m_PhysicsEnt;//0x1b8
	//char pad_0x1C0[0x18];
	ClientPlayer* m_pPlayer; //0x01D8 
	ClientAntAnimatableComponent* m_animatableComponent[2]; //0x01E0 
	__int64 m_pCharacterCameraComponent; //0x01F0 
	char pad_0x01F8[136];
};

////////////////////////////////////////
// ClassId:   03329
// RuntimeId: 07821
// TypeInfo:  0x00000001427D3520
#ifndef _CharacterSprintData_
#define _CharacterSprintData_
#pragma pack(push, 8)
class CharacterSprintData : public DataContainer
{
public:
	static __inline CharacterSprintData* DefaultInstance()
	{
		return (CharacterSprintData*)0x00000000463BCDB0;
	}
	static __inline unsigned int ClassId()
	{
		return 3329;
	}
	float m_SprintPowerDecreasePerSecond; //0x0010
	float m_SprintPowerIncreasePerSecond; //0x0014
	float m_SprintMinimumPower; //0x0018
	bool m_AllowContinousSprinting; //0x001C
	char _0x001D[3];
};//Size=0x0020
#pragma pack(pop)
#endif


/******************************************************************************************/
#define OFFSET_SIG_TABLE 0x9CC08

class PBScanSignature
{
public:
	BYTE m_Byte1; //0x0000
	BYTE m_Byte2; //0x0001 
	BYTE m_Byte3; //0x0002 
	BYTE m_Byte4; //0x0003 
	DWORD m_Offset; //0x0004 
	WORD m_ScanType; //0x0008 
	WORD m_ScanLength; //0x000A
	WORD m_Signature[128]; //0x0C
	DWORD m_Arg1; //0x10C
	DWORD m_Arg2; //0x110
	DWORD m_Arg3; //0x114
	DWORD m_Enabled; //0x118
	DWORD m_Arg5; //0x11C
};//Size=0x0120

class PBSigTable
{
public:
	__int64  qwSigBase; //0x0000
	DWORD    dwTableSize; //0x0004 
	DWORD    dwSigSize; //0x0008

	static PBSigTable* GetInstance()
	{
		__int64 qwPBCLd64 = (__int64)GetModuleHandle("pbcl.d64");

		if (qwPBCLd64)
			return (PBSigTable*)(qwPBCLd64 + OFFSET_SIG_TABLE);
		else
			return NULL;
	}

	PBScanSignature* GetScanSignature(unsigned int sigID)
	{
		PBScanSignature* pSig = NULL;

		if (sigID >= 0)
		{
			if (sigID < this->qwSigBase)
				pSig = (PBScanSignature*)(this->qwSigBase + sigID * this->dwSigSize);
		}
		return pSig;
	}
};


class TeamData
{
public:
	BYTE Pad_000[0x10];
	char* m_name;
	DWORD_PTR m_soldier;
	DWORD m_faction;
	Array<VeniceSoldierCustomizationAsset*> m_soldierCustomization;
	Array<DWORD_PTR> m_vehicleCustomization;
};



////////////////////////////////////////
// ClassId:   03532
// RuntimeId: 04096
// TypeInfo:  0x00000001427AFAA0
#ifndef _VoiceOverLabel_
#define _VoiceOverLabel_
#pragma pack(push, 8)
class VoiceOverLabel : public DataContainer
{
public:
	static __inline VoiceOverLabel* DefaultInstance()
	{
		return (VoiceOverLabel*)0x0000000068B812A0;
	}
	static __inline unsigned int ClassId()
	{
		return 3532;
	}
	CString m_Name; //0x0010
	Uint32 m_NameHash; //0x0018
	char _0x001C[4];
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01790
// RuntimeId: 07093
// TypeInfo:  0x00000001427F26E0
#ifndef _CharacterCustomizationAsset_
#define _CharacterCustomizationAsset_
#pragma pack(push, 8)
class CharacterCustomizationAsset : public DataContainerPolicyAsset
{
public:
	static __inline CharacterCustomizationAsset* DefaultInstance()
	{
		return (CharacterCustomizationAsset*)0x0000000068B490C0;
	}
	static __inline unsigned int ClassId()
	{
		return 1790;
	}
	UIHudIcon m_UIHudIcon; //0x0018
	char _0x001C[4];
	CString m_UIKitIconName; //0x0020
	CString m_LabelSid; //0x0028
	CustomizationTable* m_VisualTable; //0x0030
	CustomizationTable* m_SpecializationTable; //0x0038
	Array<VoiceOverLabel*> m_VoiceOverLabels; //0x0040
};//Size=0x0048
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01486
// RuntimeId: 08309
// TypeInfo:  0x000000014280DF00
#ifndef _ShaderGraph_
#define _ShaderGraph_
#pragma pack(push, 8)
class ShaderGraph : public SurfaceShaderBaseAsset
{
public:
	static __inline ShaderGraph* DefaultInstance()
	{
		return (ShaderGraph*)0x0000000068B42A30;
	}
	static __inline unsigned int ClassId()
	{
		return 1486;
	}
	Uint32 m_MaxSubMaterialCount; //0x0018
	Boolean m_GammaCorrectionEnable; //0x001C
	char _0x001D[3];
};//Size=0x0020
#pragma pack(pop)
#endif
////////////////////////////////////////
// ClassId:   03423
// RuntimeId: 07443
// TypeInfo:  0x00000001427FB8F0
#ifndef _UnlockValuePair_
#define _UnlockValuePair_
#pragma pack(push, 8)
class UnlockValuePair : public DataContainer
{
public:
	static __inline UnlockValuePair* DefaultInstance()
	{
		return (UnlockValuePair*)0x0000000068B7EC30;
	}
	static __inline unsigned int ClassId()
	{
		return 3423;
	}
	CString m_Id; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   03426
// RuntimeId: 07445
// TypeInfo:  0x00000001427FB890
#ifndef _FloatUnlockValuePair_
#define _FloatUnlockValuePair_
#pragma pack(push, 8)
class FloatUnlockValuePair : public UnlockValuePair
{
public:
	static __inline FloatUnlockValuePair* DefaultInstance()
	{
		return (FloatUnlockValuePair*)0x0000000068B7ECE0;
	}
	static __inline unsigned int ClassId()
	{
		return 3426;
	}
	Float32 m_DefaultValue; //0x0018
	Float32 m_UnlockedValue; //0x001C
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01791
// RuntimeId: 09416
// TypeInfo:  0x000000014282C370
#ifndef _SoldierCustomizationAsset_
#define _SoldierCustomizationAsset_
#pragma pack(push, 8)
class SoldierCustomizationAsset : public CharacterCustomizationAsset
{
public:
	static __inline SoldierCustomizationAsset* DefaultInstance()
	{
		return (SoldierCustomizationAsset*)0x0000000068B49120;
	}
	static __inline unsigned int ClassId()
	{
		return 1791;
	}
	CustomizationTable* m_WeaponTable; //0x0048
};//Size=0x0050
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01792
// RuntimeId: 02158
// TypeInfo:  0x0000000142787D20
#ifndef _VeniceSoldierCustomizationAsset_
#define _VeniceSoldierCustomizationAsset_
#pragma pack(push, 8)
class VeniceSoldierCustomizationAsset : public SoldierCustomizationAsset
{
public:
	BYTE Pad_000[0x10];
	char* m_name; //0x010
	BYTE Pad_018[0x30];
	CustomizationTable* m_weaponTable; //0x048
	//CustomizationTable* m_ClassSpecializationTable; //0x0050
};//Size=0x0058
#pragma pack(pop)
#endif
/*****************************************************************************************************************/


////////////////////////////////////////
// ClassId:   01770
// RuntimeId: 07433
// TypeInfo:  0x00000001427FBA70
#ifndef _WeaponUnlockAsset_
#define _WeaponUnlockAsset_
#pragma pack(push, 8)
class WeaponUnlockAsset : public UnlockAssetBase
{
public:
	static __inline WeaponUnlockAsset* DefaultInstance()
	{
		return (WeaponUnlockAsset*)0x0000000068B489A0;
	}
	static __inline unsigned int ClassId()
	{
		return 1770;
	}
};//Size=0x0040
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01783
// RuntimeId: 09538
// TypeInfo:  0x000000014282B6B0
#ifndef _SoldierWeaponCustomizationAsset_
#define _SoldierWeaponCustomizationAsset_
#pragma pack(push, 8)
class SoldierWeaponCustomizationAsset : public DataContainerPolicyAsset
{
public:
	static __inline SoldierWeaponCustomizationAsset* DefaultInstance()
	{
		return (SoldierWeaponCustomizationAsset*)0x0000000068B48EE0;
	}
	static __inline unsigned int ClassId()
	{
		return 1783;
	}
	CustomizationTable* m_Customization; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 09532
// TypeInfo:  0x0000000142829F08
struct UnlockToBlueprintBundle
{
	Guid m_UnlockAssetGuid; //0x0000
	char _0x0000[16];
	CString m_BundleName; //0x0010
	Boolean m_IsFirstPersonOnly; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09530
// TypeInfo:  0x0000000142829A88
struct StoredWeaponData
{
	Int32 m_WeaponClass; //0x0000
	Int32 m_MagCount; //0x0004
	Int32 m_MagCapacity; //0x0008
	Boolean m_SwitchToPrimaryWhenOutOfAmmo; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// ClassId:   01771
// RuntimeId: 09534
// TypeInfo:  0x000000014282A090
#ifndef _SoldierWeaponUnlockAsset_
#define _SoldierWeaponUnlockAsset_
#pragma pack(push, 8)
class SoldierWeaponUnlockAsset : public WeaponUnlockAsset
{
public:
	static __inline SoldierWeaponUnlockAsset* DefaultInstance()
	{
		return (SoldierWeaponUnlockAsset*)0x0000000068B48A00;
	}
	static __inline unsigned int ClassId()
	{
		return 1771;
	}
	CString m_WeaponBundleName; //0x0040
	CString m_Weapon1pBundleName; //0x0048
	Blueprint* m_NonStreamedBlueprint; //0x0050
	SoldierWeaponCustomizationAsset* m_Customization; //0x0058
	UnlockAssetBase* m_Extra; //0x0060
	Uint32 m_WeaponIdentifier; //0x0068
	Uint32 m_Category; //0x006C
	StoredWeaponData m_WeaponData; //0x0070
	Array<UnlockToBlueprintBundle> m_UnlockToBlueprintBundle; //0x0080
};//Size=0x0088
#pragma pack(pop)
#endif

////////////////////////////////////////
// RuntimeId: 09536
// TypeInfo:  0x0000000142829A68
struct UnlockWeaponAndSlot
{
	SoldierWeaponUnlockAsset* m_Weapon; //0x0000
	WeaponSlot m_Slot; //0x0008
	char _0x000C[4];
	Array<UnlockAssetBase*> m_CustomizationUnlockAssets; //0x0010
	Array<UnlockAssetBase*> m_UnlockAssets; //0x0018
};//Size=0x0020


////////////////////////////////////////
// ClassId:   02416
// RuntimeId: 09440
// TypeInfo:  0x000000014282C0D0
#ifndef _PickupEntityData_
#define _PickupEntityData_
#pragma pack(push, 16)
class PickupEntityData : public GamePhysicsEntityData
{
public:
	static __inline PickupEntityData* DefaultInstance()
	{
		return (PickupEntityData*)0x0000000068B599C0;
	}
	static __inline unsigned int ClassId()
	{
		return 2416;
	}
	ObjectBlueprint* m_PhysicsBlueprint; //0x0090
	MeshAsset* m_Mesh; //0x0098
	Float32 m_TimeToShowWeaponMesh; //0x00A0
	Uint32 m_PreferredWeaponSlot; //0x00A4
	Float32 m_TimeToLive; //0x00A8
	char _0x00AC[4];
	CString m_IconName; //0x00B0
	Int32 m_MinRandomSpareAmmoPercent; //0x00B8
	Int32 m_MaxRandomSpareAmmoPercent; //0x00BC
	Int32 m_MinRandomClipAmmoPercent; //0x00C0
	Int32 m_MaxRandomClipAmmoPercent; //0x00C4
	PickupPlayerEnum m_RandomizeAmmoOnDropForPlayer; //0x00C8
	Float32 m_InteractionRadius; //0x00CC
	Float32 m_DisplayWithinRadius; //0x00D0
	Float32 m_TacticalRadius; //0x00D4
	Boolean m_UseWeaponMesh; //0x00D8
	Boolean m_UnspawnOnPickup; //0x00D9
	Boolean m_UnspawnOnAmmoPickup; //0x00DA
	Boolean m_ContentIsStatic; //0x00DB
	Boolean m_PositionIsStatic; //0x00DC
	Boolean m_AllowPickup; //0x00DD
	Boolean m_IgnoreNullWeaponSlots; //0x00DE
	Boolean m_ForceWeaponSlotSelection; //0x00DF
	Boolean m_DisplayInMiniMap; //0x00E0
	Boolean m_HasAutomaticAmmoPickup; //0x00E1
	Boolean m_ReplaceAllContent; //0x00E2
	Boolean m_RemoveWeaponOnDrop; //0x00E3
	Boolean m_UseDisplayWithinRadius; //0x00E4
	Boolean m_KeepAmmoState; //0x00E5
	char _0x00E6[10];
};//Size=0x00F0
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01794
// RuntimeId: 09448
// TypeInfo:  0x000000014282BFB0
#ifndef _PickupEntityAsset_
#define _PickupEntityAsset_
#pragma pack(push, 8)
class PickupEntityAsset : public DataContainerPolicyAsset
{
public:
	static __inline PickupEntityAsset* DefaultInstance()
	{
		return (PickupEntityAsset*)0x0000000068B493D0;
	}
	static __inline unsigned int ClassId()
	{
		return 1794;
	}
	PickupEntityData* m_Data; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02418
// RuntimeId: 09446
// TypeInfo:  0x000000014282C010
#ifndef _KitPickupEntityData_
#define _KitPickupEntityData_
#pragma pack(push, 16)
class KitPickupEntityData : public PickupEntityData
{
public:
	static __inline KitPickupEntityData* DefaultInstance()
	{
		return (KitPickupEntityData*)0x0000000068B59BF0;
	}
	static __inline unsigned int ClassId()
	{
		return 2418;
	}
	Boolean m_KeepAdditionalWeapons; //0x00F0
	char _0x00F1[15];
};//Size=0x0100
#pragma pack(pop)
#endif

////////////////////////////////////////
// RuntimeId: 09442
// TypeInfo:  0x000000014282A048
struct WeaponUnlockPickupData
{
	UnlockWeaponAndSlot m_UnlockWeaponAndSlot; //0x0000
	Int32 m_AltWeaponSlot; //0x0020
	Int32 m_LinkedToWeaponSlot; //0x0024
	Uint32 m_MinAmmo; //0x0028
	Uint32 m_MaxAmmo; //0x002C
	Boolean m_UnlimitedAmmoPickup; //0x0030
	char _0x0031[7];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09450
// TypeInfo:  0x000000014282A028
struct DynamicWeaponPickupSlotData
{
	Uint32 m_WeaponSlot; //0x0000
	Int32 m_AltWeaponSlot; //0x0004
	Int32 m_LinkedToWeaponSlot; //0x0008
};//Size=0x000C


////////////////////////////////////////
// RuntimeId: 03702
// TypeInfo:  0x000000014276DC40
struct AntRef
{
	Guid m_AssetGuid; //0x0000
	char _0x0000[16];
	__int32 m_ProjectId; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09424
// TypeInfo:  0x0000000142829C08
struct HitReactionComponentBinding
{
	AntRef m_Hit; //0x0000
	AntRef m_HitByAIPlayer; //0x0014
	AntRef m_AllowKillFromAnimation; //0x0028
	AntRef m_Direction; //0x003C
	AntRef m_FiringDistance; //0x0050
	AntRef m_BoneType; //0x0064
	AntRef m_ImpactType; //0x0078
	AntRef m_Immortal; //0x008C
	AntRef m_RandomAnimationIndex; //0x00A0
};//Size=0x00B4

////////////////////////////////////////
// ClassId:   02419
// RuntimeId: 09444
// TypeInfo:  0x000000014282C070
#ifndef _WeaponUnlockPickupEntityData_
#define _WeaponUnlockPickupEntityData_
#pragma pack(push, 16)
class WeaponUnlockPickupEntityData : public PickupEntityData
{
public:
	static __inline WeaponUnlockPickupEntityData* DefaultInstance()
	{
		return (WeaponUnlockPickupEntityData*)0x0000000068B59D10;
	}
	static __inline unsigned int ClassId()
	{
		return 2419;
	}
	Array<WeaponUnlockPickupData> m_Weapons; //0x00F0
	Boolean m_UseForPersistence; //0x00F8
	char _0x00F9[7];
};//Size=0x0100
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02417
// RuntimeId: 09452
// TypeInfo:  0x000000014282BF50
#ifndef _DynamicWeaponPickupEntityData_
#define _DynamicWeaponPickupEntityData_
#pragma pack(push, 16)
class DynamicWeaponPickupEntityData : public PickupEntityData
{
public:
	static __inline DynamicWeaponPickupEntityData* DefaultInstance()
	{
		return (DynamicWeaponPickupEntityData*)0x0000000068B59AD0;
	}
	static __inline unsigned int ClassId()
	{
		return 2417;
	}
	Array<DynamicWeaponPickupSlotData> m_WeaponSlots; //0x00F0
	char _0x00F8[8];
};//Size=0x0100
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02170
// RuntimeId: 09436
// TypeInfo:  0x000000014282C130
#ifndef _WeaponStateEntityData_
#define _WeaponStateEntityData_
#pragma pack(push, 8)
class WeaponStateEntityData : public EntityData
{
public:
	static __inline WeaponStateEntityData* DefaultInstance()
	{
		return (WeaponStateEntityData*)0x0000000068B520E0;
	}
	static __inline unsigned int ClassId()
	{
		return 2170;
	}
	Realm m_Realm; //0x0018
	Int32 m_WeaponSlot; //0x001C
	Int32 m_Ammo; //0x0020
	Int32 m_AmmoInMags; //0x0024
};//Size=0x0028
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02335
// RuntimeId: 09434
// TypeInfo:  0x000000014282C190
#ifndef _StateEventGateEntityData_
#define _StateEventGateEntityData_
#pragma pack(push, 8)
class StateEventGateEntityData : public EntityData
{
public:
	static __inline StateEventGateEntityData* DefaultInstance()
	{
		return (StateEventGateEntityData*)0x0000000068B55B90;
	}
	static __inline unsigned int ClassId()
	{
		return 2335;
	}
	EventGateState m_CheckedState; //0x0018
	char _0x001C[4];
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02218
// RuntimeId: 09430
// TypeInfo:  0x000000014282C1F0
#ifndef _CoverPrepareFireEntityData_
#define _CoverPrepareFireEntityData_
#pragma pack(push, 8)
class CoverPrepareFireEntityData : public EntityData
{
public:
	static __inline CoverPrepareFireEntityData* DefaultInstance()
	{
		return (CoverPrepareFireEntityData*)0x0000000068B53210;
	}
	static __inline unsigned int ClassId()
	{
		return 2218;
	}
};//Size=0x0018
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02214
// RuntimeId: 09428
// TypeInfo:  0x000000014282C250
#ifndef _PlayerLookAtEntityData_
#define _PlayerLookAtEntityData_
#pragma pack(push, 16)
class PlayerLookAtEntityData : public EntityData
{
public:
	static __inline PlayerLookAtEntityData* DefaultInstance()
	{
		return (PlayerLookAtEntityData*)0x0000000068B53090;
	}
	static __inline unsigned int ClassId()
	{
		return 2214;
	}
	char _0x0018[8];
	LinearTransform m_TargetTransform; //0x0020
};//Size=0x0060
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03075
// RuntimeId: 09426
// TypeInfo:  0x000000014282C2B0
#ifndef _HitReactionComponentData_
#define _HitReactionComponentData_
#pragma pack(push, 16)
class HitReactionComponentData : public GameComponentData
{
public:
	static __inline HitReactionComponentData* DefaultInstance()
	{
		return (HitReactionComponentData*)0x0000000068B75200;
	}
	static __inline unsigned int ClassId()
	{
		return 3075;
	}
	HitReactionComponentBinding m_HitReactionBinding; //0x0070
	Boolean m_Enabled; //0x0124
	char _0x0125[11];
};//Size=0x0130
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01894
// RuntimeId: 09498
// TypeInfo:  0x000000014282BA70
#ifndef _CustomizeSoldierData_
#define _CustomizeSoldierData_
#pragma pack(push, 8)
class CustomizeSoldierData : public CustomizeCharacterData
{
public:
	static __inline CustomizeSoldierData* DefaultInstance()
	{
		return (CustomizeSoldierData*)0x0000000068B4B8F0;
	}
	static __inline unsigned int ClassId()
	{
		return 1894;
	}
	Array<UnlockWeaponAndSlot> m_Weapons; //0x0038
	WeaponSlot m_ActiveSlot; //0x0040
	char _0x0044[4];
	PickupEntityAsset* m_DeathPickup; //0x0048
	Boolean m_KeepCurrentActiveSlot; //0x0050
	Boolean m_RemoveAllExistingWeapons; //0x0051
	Boolean m_DisableDeathPickup; //0x0052
	char _0x0053[5];
};//Size=0x0058
#pragma pack(pop)
#endif

////////////////////////////////////////
// RuntimeId: 07441
// TypeInfo:  0x00000001427FA790
struct UnlockAssetPair
{
	UnlockAssetBase* m_Second; //0x0000
	UnlockAssetBase* m_Result; //0x0008
};//Size=0x0010

////////////////////////////////////////
// ClassId:   03423
// RuntimeId: 07443
// TypeInfo:  0x00000001427FB8F0
#ifndef _UnlockValuePair_
#define _UnlockValuePair_
#pragma pack(push, 8)
class UnlockValuePair : public DataContainer
{
public:
	static __inline UnlockValuePair* DefaultInstance()
	{
		return (UnlockValuePair*)0x0000000068B7EC30;
	}
	static __inline unsigned int ClassId()
	{
		return 3423;
	}
	CString m_Id; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   01773
// RuntimeId: 07451
// TypeInfo:  0x00000001427FB770
#ifndef _ValueUnlockAsset_
#define _ValueUnlockAsset_
#pragma pack(push, 8)
class ValueUnlockAsset : public UnlockAssetBase
{
public:
	static __inline ValueUnlockAsset* DefaultInstance()
	{
		return (ValueUnlockAsset*)0x0000000068B48B00;
	}
	static __inline unsigned int ClassId()
	{
		return 1773;
	}
	Array<UnlockValuePair*> m_UnlockValues; //0x0040
};//Size=0x0048
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 09598
// TypeInfo:  0x0000000142829E48
struct BulletHitInfo
{
	Vec3 m_Direction; //0x0000
	Vec3 m_SpawnPosition; //0x0010
	Vec3 m_HitPosition; //0x0020
	UnlockAssetBase* m_WeaponUnlockAsset; //0x0030
	AntHitReactionWeaponType m_WeaponType; //0x0038
	Int32 m_BoneType; //0x003C
	Int32 m_ShooterPlayerId; //0x0040
	Boolean m_ShooterIsAIPlayer; //0x0044
	char _0x0045[11];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 07097
// TypeInfo:  0x00000001427F24E0
struct CamoUnlockSelection
{
	Int32 m_Category; //0x0000
	char _0x0004[4];
	UnlockAssetBase* m_Asset; //0x0008
};//Size=0x0010

////////////////////////////////////////
// ClassId:   01782
// RuntimeId: 09528
// TypeInfo:  0x000000014282B710
#ifndef _SoldierWeaponMultiUnlock_
#define _SoldierWeaponMultiUnlock_
#pragma pack(push, 8)
class SoldierWeaponMultiUnlock : public UnlockUserDataBase
{
public:
	static __inline SoldierWeaponMultiUnlock* DefaultInstance()
	{
		return (SoldierWeaponMultiUnlock*)0x0000000068B48EA0;
	}
	static __inline unsigned int ClassId()
	{
		return 1782;
	}
	UnlockAssetBase* m_First; //0x0018
	Array<UnlockAssetPair> m_UnlockAssetPairs; //0x0020
};//Size=0x0028
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02011
// RuntimeId: 07815
// TypeInfo:  0x00000001427D35E0
#ifndef _CharacterPoseData_
#define _CharacterPoseData_
#pragma pack(push, 16)
class CharacterPoseData : public DataContainer
{
public:
	static __inline CharacterPoseData* DefaultInstance()
	{
		return (CharacterPoseData*)0x000000004638E8D0;
	}
	static __inline unsigned int ClassId()
	{
		return 2011;
	}

	////////////////////////////////////////
	// RuntimeId: 07813
	// TypeInfo:  0x00000001427D1EB8
	struct PoseTransitionTime
	{
		CharacterPoseType m_ToPose; //0x0000
		float m_TransitionTime; //0x0004
	};//Size=0x0008

	////////////////////////////////////////
	// RuntimeId: 07805
	// TypeInfo:  0x00000001427D1DD8
	struct LookConstraintsData
	{
		float m_MinLookYaw; //0x0000
		float m_MaxLookYaw; //0x0004
		float m_MinLookPitch; //0x0008
		float m_MaxLookPitch; //0x000C
	};//Size=0x0010

	Array<Vec2> m_ThrottleModifierCurve; //0x0010
	float m_StepHeight; //0x0018
	char _0x001C[4];
	Vec3 m_EyePosition; //0x0020
	Vec3 m_CollisionBoxMinExpand; //0x0030
	Vec3 m_CollisionBoxMaxExpand; //0x0040
	float m_Height; //0x0050
	char _0x0054[4];
	Array<PoseTransitionTime> m_TransitionTimes; //0x0058
	LookConstraintsData m_LookConstraints; //0x0060
	CharacterPoseType m_PoseType; //0x0070
	CharacterPoseCollisionType m_CollisionType; //0x0074
	char _0x0078[8];
};//Size=0x0080
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03456
// RuntimeId: 07819
// TypeInfo:  0x00000001427D3580
#ifndef _CharacterStatePoseInfo_
#define _CharacterStatePoseInfo_
#pragma pack(push, 8)
class CharacterStatePoseInfo : public DataContainer
{
public:
	static __inline CharacterStatePoseInfo* DefaultInstance()
	{
		return (CharacterStatePoseInfo*)0x00000000463BFC30;
	}
	static __inline unsigned int ClassId()
	{
		return 3456;
	}
	////////////////////////////////////////
	// RuntimeId: 07817
	// TypeInfo:  0x00000001427D1DB8
	struct SpeedModifierData
	{
		float m_ForwardConstant; //0x0000
		float m_BackwardConstant; //0x0004
		float m_LeftConstant; //0x0008
		float m_RightConstant; //0x000C
	};//Size=0x0010


	CharacterPoseType m_PoseType; //0x0010
	float m_Velocity; //0x0014
	float m_AccelerationGain; //0x0018
	float m_DecelerationGain; //0x001C
	float m_SprintGain; //0x0020
	float m_SprintMultiplier; //0x0024
	SpeedModifierData m_SpeedModifier; //0x0028
	float m_ShallowWaterMultiplier; //0x0038
	char _0x003C[4];
};//Size=0x0040
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   01967
// RuntimeId: 07825
// TypeInfo:  0x00000001427D34C0
#ifndef _CharacterStateData_
#define _CharacterStateData_
#pragma pack(push, 8)
class CharacterStateData : public DataContainer
{
public:
	static __inline CharacterStateData* DefaultInstance()
	{
		return (CharacterStateData*)0x000000004638DA30;
	}
	static __inline unsigned int ClassId()
	{
		return 1967;
	}
	Array<CharacterStatePoseInfo*> m_PoseInfo; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01827
// RuntimeId: 07845
// TypeInfo:  0x00000001427D3100
#ifndef _CharacterPhysicsData_
#define _CharacterPhysicsData_
#pragma pack(push, 8)
class CharacterPhysicsData : public Asset
{
public:
	static __inline CharacterPhysicsData* DefaultInstance()
	{
		return (CharacterPhysicsData*)0x000000004638A710;
	}
	static __inline unsigned int ClassId()
	{
		return 1827;
	}
	Array<CharacterPoseData*> m_Poses; //0x0018
	Array<CharacterStateData*> m_States; //0x0020
	CharacterStateType m_DefaultState; //0x0028
	char _0x002C[4];
	CharacterSprintData* m_Sprint; //0x0030
	MaterialDecl m_MaterialPair; //0x0038
	__int32 m_PushableObjectWeight; //0x003C
	float m_Mass; //0x0040
	float m_MaxAscendAngle; //0x0044
	float m_PhysicalRadius; //0x0048
	float m_EnterSwimStateDepth; //0x004C
	float m_ExitSwimStateDepth; //0x0050
	float m_InputAcceleration; //0x0054
	float m_LadderAcceptAngle; //0x0058
	float m_LadderAcceptAnglePitch; //0x005C
	float m_JumpPenaltyTime; //0x0060
	float m_JumpPenaltyFactor; //0x0064
	float m_RadiusToPredictCollisionOnCharacters; //0x0068
	bool m_AllowPoseChangeDuringTransition; //0x006C
	bool m_AutoPushAwayFromWallsInProne; //0x006D
	char _0x006E[2];
};//Size=0x0070
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03855
// RuntimeId: 09421
// TypeInfo:  0x00000001427F75A0
#ifndef _SoldierSprintSettingsData_
#define _SoldierSprintSettingsData_
#pragma pack(push, 8)
class SoldierSprintSettingsData : public DataContainer
{
public:
	static __inline SoldierSprintSettingsData* DefaultInstance()
	{
		return (SoldierSprintSettingsData*)0x00000000463C8A40;
	}
	static __inline unsigned int ClassId()
	{
		return 3855;
	}
	float m_Fov; //0x0010
	float m_FovInDelay; //0x0014
	float m_FovInTime; //0x0018
	float m_FovOutDelay; //0x001C
	float m_FovOutTime; //0x0020
	float m_RecoverTime; //0x0024
	float m_SprintToProneRecoverTime; //0x0028
	char _0x002C[4];
	Array<__int32> m_InterruptingActions; //0x0030
};//Size=0x0038
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   02395
// RuntimeId: 06871
// TypeInfo:  0x00000001427BF8F0
#ifndef _CharacterEntityData_
#define _CharacterEntityData_
#pragma pack(push, 16)
class CharacterEntityData : public ControllableEntityData
{
public:
	static __inline CharacterEntityData* DefaultInstance()
	{
		return (CharacterEntityData*)0x0000000046399EE0;
	}
	static __inline unsigned int ClassId()
	{
		return 2395;
	}
	float m_MaxHealth; //0x00B0
	PersonViewMode m_DefaultViewMode; //0x00B4
	PlayerSpawnType m_PlayerSpawnType; //0x00B8
	char _0x00BC[4];
	Pointer EntityVoiceOverInfo_ptr_m_VoiceOverInfo; //0x00C0 EntityVoiceOverInfo*
	Pointer CharacterSoundData_ptr_m_Sound; //0x00C8 CharacterSoundData*
	bool m_CharacterLightingEnable; //0x00D0
	char _0x00D1[15];
};//Size=0x00E0
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03580
// RuntimeId: 07785
// TypeInfo:  0x00000001427CF4C0
#ifndef _FakePhysicsData_
#define _FakePhysicsData_
#pragma pack(push, 8)
class FakePhysicsData : public DataContainer
{
public:
	static __inline FakePhysicsData* DefaultInstance()
	{
		return (FakePhysicsData*)0x00000000463C2520;
	}
	static __inline unsigned int ClassId()
	{
		return 3580;
	}
	FakePhysicsData* m_ChildFakePhysics; //0x0010
	float m_StartSpeed; //0x0018
	float m_GravityModifier; //0x001C
	float m_StartDampening; //0x0020
	float m_EndDampening; //0x0024
	float m_MinSpeed; //0x0028
	float m_MaxSpeed; //0x002C
	float m_Mass; //0x0030
	char _0x0034[4];
};//Size=0x0038
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03574
// RuntimeId: 07633
// TypeInfo:  0x00000001427CC0F0
#ifndef _BoneFakePhysicsData_
#define _BoneFakePhysicsData_
#pragma pack(push, 8)
class BoneFakePhysicsData : public DataContainer
{
public:
	static __inline BoneFakePhysicsData* DefaultInstance()
	{
		return (BoneFakePhysicsData*)0x00000000463C2310;
	}
	static __inline unsigned int ClassId()
	{
		return 3574;
	}
	FakePhysicsData* m_FakePhysics; //0x0010
	char* m_BoneName; //0x0018
	__int32 m_BoneId; //0x0020
	char _0x0024[4];
};//Size=0x0028
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03202
// RuntimeId: 09411
// TypeInfo:  0x00000001427F7660
#ifndef _SoldierAutoAimData_
#define _SoldierAutoAimData_
#pragma pack(push, 8)
class SoldierAutoAimData : public DataContainer
{
public:
	static __inline SoldierAutoAimData* DefaultInstance()
	{
		return (SoldierAutoAimData*)0x00000000463BA130;
	}
	static __inline unsigned int ClassId()
	{
		return 3202;
	}
	////////////////////////////////////////
	// RuntimeId: 09409
	// TypeInfo:  0x00000001427F58D8
	struct AutoAimData
	{
		Vec3 m_AutoAimOuterBoxOffset; //0x0000
		Vec3 m_AutoAimOuterBoxExtends; //0x0010
		Vec3 m_AutoAimInnerBoxOffset; //0x0020
		Vec3 m_AutoAimInnerBoxExtends; //0x0030
		CharacterPoseType m_PoseType; //0x0040
		char _0x0044[12];
	};//Size=0x0050


	Array<AutoAimData> m_Poses; //0x0010
};//Size=0x0018
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   03200
// RuntimeId: 09403
// TypeInfo:  0x00000001427F7720
#ifndef _SoldierAimingConstraintsData_
#define _SoldierAimingConstraintsData_
#pragma pack(push, 8)
class SoldierAimingConstraintsData : public DataContainer
{
public:
	static __inline SoldierAimingConstraintsData* DefaultInstance()
	{
		return (SoldierAimingConstraintsData*)0x00000000463BA0B0;
	}
	static __inline unsigned int ClassId()
	{
		return 3200;
	}

	////////////////////////////////////////
	// RuntimeId: 07723
	// TypeInfo:  0x00000001427CDBB0
	struct AimingConstraintsData
	{
		float m_MinYaw; //0x0000
		float m_MaxYaw; //0x0004
		float m_MinPitch; //0x0008
		float m_MaxPitch; //0x000C
	};//Size=0x0010


	AimingConstraintsData m_SwimmingConstraints; //0x0010
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03183
// RuntimeId: 09415
// TypeInfo:  0x00000001427F7600
#ifndef _SoldierHeadCollisionData_
#define _SoldierHeadCollisionData_
#pragma pack(push, 8)
class SoldierHeadCollisionData : public DataContainer
{
public:
	static __inline SoldierHeadCollisionData* DefaultInstance()
	{
		return (SoldierHeadCollisionData*)0x00000000463B9880;
	}
	static __inline unsigned int ClassId()
	{
		return 3183;
	}
	////////////////////////////////////////
	// RuntimeId: 09413
	// TypeInfo:  0x00000001427F58B8
	struct SoldierHeadCollisionPoseData
	{
		Vec3 m_IdleOffset; //0x0000
		Vec3 m_MovingForwardOffset; //0x0010
	};//Size=0x0020

	float m_HeadRadius; //0x0010
	char _0x0014[4];
	Array<SoldierHeadCollisionPoseData> m_PoseStates; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01433
// RuntimeId: 08149
// TypeInfo:  0x00000001427DA150
#ifndef _SkinnedMeshAsset_
#define _SkinnedMeshAsset_
#pragma pack(push, 16)
class SkinnedMeshAsset : public MeshAsset
{
public:
	static __inline SkinnedMeshAsset* DefaultInstance()
	{
		return (SkinnedMeshAsset*)0x0000000046381E90;
	}
	static __inline unsigned int ClassId()
	{
		return 1433;
	}
	Vec3 m_BoundingBoxPositionOffset; //0x0060
	Vec3 m_BoundingBoxSizeOffset; //0x0070
};//Size=0x0080
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   01996
// RuntimeId: 09431
// TypeInfo:  0x00000001427F7420
#ifndef _SoldierHealthModuleData_
#define _SoldierHealthModuleData_
#pragma pack(push, 8)
class SoldierHealthModuleData : public DataContainer
{
public:
	static __inline SoldierHealthModuleData* DefaultInstance()
	{
		return (SoldierHealthModuleData*)0x000000004638E270;
	}
	static __inline unsigned int ClassId()
	{
		return 1996;
	}
};//Size=0x0010
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03847
// RuntimeId: 09429
// TypeInfo:  0x00000001427F7480
#ifndef _BreathControlData_
#define _BreathControlData_
#pragma pack(push, 8)
class BreathControlData : public DataContainer
{
public:
	static __inline BreathControlData* DefaultInstance()
	{
		return (BreathControlData*)0x00000000463C87F0;
	}
	static __inline unsigned int ClassId()
	{
		return 3847;
	}
	float m_BreathControlTime; //0x0010
	float m_BreathControlReleaseTime; //0x0014
	float m_BreathControlPenaltyMultiplier; //0x0018
	float m_BreathControlPenaltyTimeout; //0x001C
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03459
// RuntimeId: 09427
// TypeInfo:  0x00000001427F74E0
#ifndef _CollisionData_
#define _CollisionData_
#pragma pack(push, 8)
class CollisionData : public DataContainer
{
public:
	static __inline CollisionData* DefaultInstance()
	{
		return (CollisionData*)0x00000000463BFD10;
	}
	static __inline unsigned int ClassId()
	{
		return 3459;
	}
	////////////////////////////////////////
	// RuntimeId: 09425
	// TypeInfo:  0x00000001427F5878
	struct ValueAtX
	{
		float m_X; //0x0000
		float m_Value; //0x0004
	};//Size=0x0008


	Array<ValueAtX> m_DamageAtVerticalVelocity; //0x0010
	Array<ValueAtX> m_DamageAtHorizVelocity; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   02396
// RuntimeId: 09433
// TypeInfo:  0x00000001427F73C0
#ifndef _SoldierEntityData_
#define _SoldierEntityData_
#pragma pack(push, 16)
class SoldierEntityData : public CharacterEntityData
{
public:
	static __inline SoldierEntityData* DefaultInstance()
	{
		return (SoldierEntityData*)0x0000000046399FE0;
	}
	static __inline unsigned int ClassId()
	{
		return 2396;
	}
	////////////////////////////////////////
	// RuntimeId: 09417
	// TypeInfo:  0x00000001427F5898
	struct HidableSoldierMeshWeaponPart
	{
		SkinnedMeshAsset* m_WeaponMesh; //0x0000
		ObjectBlueprint* m_WeaponMeshBlueprint; //0x0008
		char* m_BoneName; //0x0010
		bool m_HideAlways; //0x0018
		bool m_HideInVehicleEntries; //0x0019
		char _0x001A[6];
	};//Size=0x0020


	Vec3 m_FLIRKeyColor; //0x00E0
	MaterialDecl m_FootMaterialPair; //0x00F0
	MaterialDecl m_HeadMaterialPair; //0x00F4
	Array<BoneFakePhysicsData*> m_BoneFakePhysics; //0x00F8
	SoldierAutoAimData* m_AutoAim; //0x0100
	SoldierAimingConstraintsData* m_AimingConstraints; //0x0108
	SoldierHeadCollisionData* m_HeadCollision; //0x0110
	CharacterPhysicsData* m_CharacterPhysics; //0x0118
	SoldierSprintSettingsData* m_SprintSettings; //0x0120
	Array<HidableSoldierMeshWeaponPart> m_HidableMeshParts; //0x0128
	float m_ImpulseReactionTime; //0x0130
	char _0x0134[4];
	SoldierHealthModuleData* m_HealthModule; //0x0138
	Array<__int32> m_AbortSpawnInvisibilityInputs; //0x0140
	Array<BreathControlData*> m_BreathControl; //0x0148
	CollisionData* m_CollisionInfo; //0x0150
	float m_FLIRValue; //0x0158
	float m_ExplosionDamageModifier; //0x015C
	float m_RegenerationDelayModifier; //0x0160
	float m_FallDamageThreshold; //0x0164
	bool m_UseSpineXRotation; //0x0168
	bool m_ShowWeaponWhenDead; //0x0169
	bool m_EnableGroundmapLighting; //0x016A
	bool m_LowerGunOnOwnTeam; //0x016B
	bool m_ProximityCheck; //0x016C
	bool m_FreeSpaceCheck; //0x016D
	bool m_CollisionEnabled; //0x016E
	bool m_PhysicsControlled; //0x016F
	bool m_IsPushable; //0x0170
	bool m_HumanPlayerControlled; //0x0171
	bool m_InteractiveManDownAllowed; //0x0172
	bool m_ShowNametag; //0x0173
	char _0x0174[12];
};//Size=0x0180
#pragma pack(pop)
#endif


class SoldierEntity
{
public:
	class CharacterPhysicsEntity_CharacterInput
	{
		Vec3 m_forwardVector;                            //0x0090 //3d Model, not camera
		Vec3 m_upVector;                                 //0x00A0
		Vec3 m_characterGravity;                         //0x00B0
		float m_waterLevel_2;                                   //0x00C0
		float m_waterSpeed_2;                                   //0x00С4
		float m_speedScale;                                     //0x00C8
		float m_yaw;                                            //0x00CC
		float m_pitch;                                          //0x00D0
		float m_forwardInput;                                   //0x00D4 /  1 fwd, -1 bwd
		float m_strafeInput;                                    //0x00D8 / -1 left, 1 right
		float m_sprintMultiplier;                               //0x00DC
		char pad_0x00E0[4];                                     //0x00E0
		bool m_tryJump_1;                                       //0x00E4
		bool bUnkn_1;                                           //0x00E5
		bool m_tryJump_2;                                       //0x00E6
		bool m_sprint;                                          //0x00E7
		char pad_0x00E8[24];                                    //0x00E8
	};

	virtual BoneCollisionComponent* boneCollisionComponent(); // not tested
	virtual Matrix& soldierTransform();
	virtual bool SoldierEntity_funct2();
	virtual bool SoldierEntity_funct3();
	virtual bool isFiring();
	virtual bool isReloading();
	virtual bool SoldierEntity_funct6();
	virtual WeaponSway* getWeaponSway();
	virtual WeaponFiring* getCurrentWeaponFiring();
	virtual void* getCurrentWeaponFiringData();     // PrimaryFire* m_pPrimaryFire == WeaponFiringData* ;
	virtual bool SoldierEntity_funct10();
	virtual float moveSpeedMultiplier();


	SoldierEntityData* m_pSoldierData; //0x0008 
	char pad_0x0010[44];                                    //0x0010
	float m_headRotationSpeed;                              //0x003C <?> - 5.0
	bool m_allowedToMoveEyes;                              //0x0040 <?> - true (bool = 4bits)
	char pad_0x0041[39];                                    //0x0041 (pad = +1bit)
	__int64 ptrUnkn_1;                                      //0x0068 (_int64 = 8)
	__int64 ptrUnkn_2;                                      //0x0070
	__int64 ptrUnkn_3;                                      //0x0078
	char pad_0x0080[16];									//0x0080
	CharacterPhysicsEntity_CharacterInput m_CharInputClass; //0x0090 
	__int64 m_pBoneCollisionComponent; //0x0100
	float m_moveSpeedMultiplier; //0x0108 
	float m_sprintSpeedMultiplier; //0x010C 
	float m_jumpHeightMultiplier; //0x0110 
	float m_lookSpeedMultiplier; //0x0114 
	float m_waterLevel; //0x0118 
	float m_waterSpeed; //0x011C 
	char pad_0x0120[8];
	__int64 m_pCharacterEntity; //0x0128 
};

class CharacterPhysicsEntityCollisionShapes
{
public:
	__int64 hkpShape_ptr_m_shapes[CharacterPoseType::CharacterPoseTypeCount]; //0x0000 hkpShape* (TODO)
	char _0x0018[8];
	AxisAlignedBox m_aabbs[CharacterPoseType::CharacterPoseTypeCount]; //0x0020
};

class CharacterPoseConstraints
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	WORD m_validPoses[4];	// 0x08
}; //


class CharacterPhysicsEntity
{
public:
	virtual TypeInfo* getType();
	virtual void deconstructor(); //
	virtual void addToWorld(); //
	virtual void removeFromWorld(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //

	char  pad_0x0008[128];            //00 
	void* m_pad;                //88 
	Matrix* m_gameWorldTransform;        //90 
	void* m_pad2;                //98 
	int   m_Unk1;                    //A0 
	CharacterPoseType  m_currentPose; //0x00A4 
	CharacterPoseType   m_changingToPose; //0x00A8 
	float m_poseTransitionTimer; //0x00AC 
	CharacterPhysicsEntityCollisionShapes* m_collisionShapes; //0x00B0  Rid 10496
	CharacterPoseConstraints* m_poseConstraints; //0x00B8  Rid     0
	BYTE m_enabled; //0x00C0 
	BYTE m_isPhysicsControlled; //0x00C1 
	BYTE m_aiBodyAddedToWorld; //0x00C2 
	BYTE unkn; //0x00C3 
	char _0x00C4[12];
	Vec3 m_currentLocalEyePosition; //0x00D0 
	float m_mass; //0x00E0 
	char _0x00E4[4];
	CharacterPhysicsData* m_data; //0x00E8 

	__forceinline Vec3 worldEyePosition()
	{
		if (!m_gameWorldTransform)
			return Vec3(0, 0, 0,0);

	/*	DirectX::XMFLOAT3 Trans = DirectX::XMFLOAT3
			(m_gameWorldTransform->_41, // 41
			m_gameWorldTransform->_42,
			m_gameWorldTransform->_43);

		return DirectX::XMFLOAT3(
			(Trans.x + m_currentLocalEyePosition.x),
			(Trans.y + m_currentLocalEyePosition.y),
			(Trans.z + m_currentLocalEyePosition.z));*/
	}
};//Size=0x00F0

class ClientSoldierPrediction
{
public:
	virtual void            function_0();
	virtual Vec3		getPosition();
	virtual void            setPosition(Vec3);

	CharacterPhysicsEntity* m_characterPhyEntity; //0x0008 
	char _0x0010[16]; //+10
	Vec3 m_ParachuteRotation; //0x0020 
	Vec3 m_Position; //0x0030 
	Vec3 surfaceVelocity; //0x0040 
	Vec3 m_Velocity; //0x0050 
	Vec3 groundNormal; //0x0060 
	int groundSupported; //0x0070 
	int groundMaterialIndex; //0x0074 
	int m_state; //0x0078 
	BYTE m_Pose; //0x007C 
	char _0x007D[3]; //0x007F
	BYTE m_ChangingToPose; //0x0080 
	char _0x0081[23];
	int Event; //0x0098 
	BYTE PlayerState; //0x009C 
};//Size=0x009D

// Flags:0x35 Size:0x290 Fields:0
// Warning: Missing fieldinfo data
class ClientVehicleEntryListenerComponent : public ClientGameComponent
{
public:
};

/*
class ClientSoldierEntity : public ClientCharacterEntity,    // +0x000
	public SoldierEntity            // +0x280
{
public:

	class BreathControlHandler
	{
	public:
 		char _0x0000[56]; //+38 (octale to decimal)
		float m_breathControlTimer; //0x0038  
		float m_breathControlMultiplier; //0x003C  
		float m_breathControlPenaltyTimer; //0x0040  
		float m_breathControlpenaltyMultiplier; //0x0044  
		float m_breathControlActive; //0x0048  
		float m_breathControlInput; //0x004C  
		float m_breathActive; //0x0050  
		char _0x0054[4]; // + 4
		float m_Enabled; //0x0058  
	};

	class SprintInputHandler
	{
	public:
		int m_currentState; //0x0000 
		float m_doubleTapTimer; //0x0004 
		float m_sprintReleaseTimer; //0x0008 
		int m_waitForSprintRelease; //0x000C 
	};

	char pad_0x03B0[216];
	__int64 m_pVehicleEntry; //0x0488 
	ClientSoldierPrediction* m_pPredictedController; //0x0490 
	char pad_0x0498[64]; //0x04D0 +40
	float m_authorativeYaw; //0x04D8 
	float m_authorativePitch; //0x04DC 
	int m_aimingEnabled; //0x04E0 
	float m_cachedPitch; //0x04E4 
	__int64 m_soldierSound; //0x04E8 
	int m_poseType; //0x04F0 
	char pad_0x04F4[92]; //+58 0x0548
	ClientSoldierWeaponsComponent* m_soldierWeaponsComponent; //0x0550 
	__int64 m_bodyComponent; //0x0558 
	ClientRagDollComponent* m_ragdollComponent; //0x0560 
	BreathControlHandler* m_breathControlHandler; //0x0568 
	ClientVehicleEntryListenerComponent* m_VehicleEntryListenerComponent; //0x0570
	char pad_0x0578[8];
	SprintInputHandler* m_sprintInputHandler; //0x0580 
	int padThis; //0x0588 
	float m_timeSinceLastSprinted; //0x058C 
	BYTE m_sprinting; //0x0590 
	BYTE m_occluded; //0x0591 
	ClientCharacterEntity* m_pClientCharacterEntity; //0x06B0 
	//char pad_0x06B8[416];
	//char pad_0x06B8[0xCB8 - 0x6B8];
	char pad_0x06B8[1544];
	ClientVaultComponent* clVaultComp; //0x0CC0

	bool isVisible()
	{
		return !m_occluded;
	}

	ClientSoldierWeapon* GetActiveWeapon()
	{
		if (!m_soldierWeaponsComponent)
			return NULL;

		if ((DWORD_PTR)m_soldierWeaponsComponent > 0xFFFFFFFF)
			return NULL;

		if (IsBadReadPtr(m_soldierWeaponsComponent, 8))
			return NULL;

		if (!IsValidPtr(m_soldierWeaponsComponent))
			return NULL;

		return m_soldierWeaponsComponent->GetActiveSoldierWeapon();
	}

	SoldierEntityData* GetSoldierEntityData()
	{
		return (SoldierEntityData*)this + 0x08;
	}
};

*/

class MissileLaunchEntity{
public:
	MissileLaunchEntity(){

	}
	bool bMissLaunch(){
		bool a = (this) ? true : false;
		return a;
	}
	char _0x0000[72];
	VeniceClientMissileEntity* pVeniceClientMissileEntity; //0x0048
};;//Size=0x0050



////////////////////////////////////////
// ClassId:   00689
// RuntimeId: 09280
// TypeInfo:  0x0000000142822760
class ClientSoldierEntity : public ClientCharacterEntity,    // +0x000
	public SoldierEntity            // +0x280
{
public:

	class BreathControlHandler
	{
	public:
		char _0x0000[56]; // + 0x38
		float m_breathControlTimer; //0x0038  
		float m_breathControlMultiplier; //0x003C  
		float m_breathControlPenaltyTimer; //0x0040  
		float m_breathControlpenaltyMultiplier; //0x0044  
		float m_breathControlActive; //0x0048  
		float m_breathControlInput; //0x004C  
		float m_breathActive; //0x0050  
		char _0x0054[4]; //+0x0054
		float m_Enabled; //0x0058  
	};

	class SprintInputHandler
	{
	public:
		int m_currentState; //0x0000 
		float m_doubleTapTimer; //0x0004 
		float m_sprintReleaseTimer; //0x0008 
		int m_waitForSprintRelease; //0x000C 
	};

	char pad_0x03B0[0x428 - 0x3B0]; //216
	MissileLaunchEntity* m_pSoldMissile; // 0x428 // jd62
	char _0x0430[0x488 - 0x430];
	__int64 m_pVehicleEntry; //0x0488
	ClientSoldierPrediction* m_pPredictedController; //0x0490 
	char pad_0x0498[64];
	float m_authorativeYaw; //0x04D8 
	float m_authorativePitch; //0x04DC 
	int m_aimingEnabled; //0x04E0 
	float m_cachedPitch; //0x04E4 
	__int64 m_soldierSound; //0x04E8 
	int m_poseType; //0x04F0 
	byte orange; //0x4F4;
	char pad_0x04F5[91];
	ClientSoldierWeaponsComponent* m_soldierWeaponsComponent; //0x0550 
	__int64 m_bodyComponent; //0x0558 
	ClientRagDollComponent* m_ragdollComponent; //0x0560 
	BreathControlHandler* m_breathControlHandler; //0x0568 
	char pad_0x0570[16];
	SprintInputHandler* m_sprintInputHandler; //0x0580 
	int padThis; //0x0588 
	float m_timeSinceLastSprinted; //0x058C 
	BYTE m_sprinting; //0x0590 
	BYTE m_occluded; //0x0591 
	char pad_0x0592[286];
	ClientCharacterEntity* m_pClientCharacterEntity; //0x06B0 
	//char pad_0x06B8[416];
	BYTE pad22[0x618];
	ClientVaultComponent* m_pClientVaultComponent; //0x0CD0 ClientVaultComponent

	bool isVisible()
	{
		return !m_occluded;
	}

	ClientSoldierWeapon* GetActiveWeapon()
	{
		if (!m_soldierWeaponsComponent)
			return NULL;

		if ((DWORD_PTR)m_soldierWeaponsComponent > 0xFFFFFFFF)
			return NULL;

		if (IsBadReadPtr(m_soldierWeaponsComponent, 8))
			return NULL;

		if (!IsValidPtr(m_soldierWeaponsComponent))
			return NULL;

		return m_soldierWeaponsComponent->GetActiveSoldierWeapon();
	}

	SoldierEntityData* GetSoldierEntityData()
	{
		return (SoldierEntityData*)this + 0x08;
	}
};



////////////////////////////////////////
// ClassId:   02460
// RuntimeId: 06313
// TypeInfo:  0x00000001427E89E0
#ifndef _MapMarkerEntityData_
#define _MapMarkerEntityData_
#pragma pack(push, 16)
class MapMarkerEntityData : public SpatialEntityData
{
public:
	static __inline MapMarkerEntityData* DefaultInstance()
	{
		return (MapMarkerEntityData*)0x0000000068B5C230;
	}
	static __inline unsigned int ClassId()
	{
		return 2460;
	}
	Vec3 m_BaseTransform; //0x0060
	LinearTransform m_VisualTransform; //0x0070
	CString m_Sid; //0x00B0
	CString m_NameLetter; //0x00B8
	Int32 m_NrOfPassengers; //0x00C0
	Int32 m_NrOfEntries; //0x00C4
	Float32 m_ShowRadius; //0x00C8
	Float32 m_HideRadius; //0x00CC
	Float32 m_BlinkTime; //0x00D0
	MapMarkerType m_MarkerType; //0x00D4
	TeamId m_VisibleForTeam; //0x00D8
	TeamId m_OwnerTeam; //0x00DC
	UIHudIcon m_HudIcon; //0x00E0
	char _0x00E4[4];
	CString m_IconName; //0x00E8
	UIWorldIconBehavior* m_IconBehavior; //0x00F0
	Float32 m_VerticalOffset; //0x00F8
	Float32 m_FocusPointRadius; //0x00FC
	Int32 m_FocusPriority; //0x0100
	Float32 m_ProgressTime; //0x0104
	Float32 m_Progress; //0x0108
	Uint32 m_TrackedPlayersInRange; //0x010C
	Float32 m_TrackingPlayerRange; //0x0110
	Float32 m_InstantFlagReturnRadius; //0x0114
	Float32 m_ProgressPlayerSpeedUpPercentage; //0x0118
	Float32 m_ProgressTime1Player; //0x011C
	Float32 m_ProgressMinTime; //0x0120
	Boolean m_IsVisible; //0x0124
	Boolean m_ShowAirTargetBox; //0x0125
	Boolean m_IsFocusPoint; //0x0126
	Boolean m_Snap; //0x0127
	Boolean m_OnlyShowSnapped; //0x0128
	Boolean m_UseMarkerTransform; //0x0129
	Boolean m_ServerControlledPosition; //0x012A
	Boolean m_PositionStatic; //0x012B
	Boolean m_Enabled; //0x012C
	Boolean m_ShowDistanceInText; //0x012D
	Boolean m_ShowProgress; //0x012E
	char _0x012F[1];
};//Size=0x0130
#pragma pack(pop)
#endif


class ClientChassisComponent
{
public:
	char _0x0000[448];
	Vec3 m_Velocity; //0x01C0 
};//Size=0x0200


class PhysicsEntityBase
{
public:

}; //Size=0x0070


/*
class DynamicBitSet
{
public:
	LPVOID data;		// 0x00
	INT bitCount;		// 0x08
}; // 0x08

class PhysicsEntityParts
{
public:
	DynamicBitSet m_enabled;			// 0x00
	LinearTransform* m_base;			// 0x08
	EntityBusPeer** m_transformNodes;	// 0x0C
	hkpShape** m_detailShapes;			// 0x10
	LPBYTE m_transformIndices;			// 0x14
}
*/

// Flags:0x35 Size:0xE0 Fields:0
class PhysicsEntity
{
public:
	char aPhysicsEntityBase[112]; //+0x00 Inherited (// Flags:0x35 Size:0x70 Fields:0)
	AxisAlignedBox m_rbAabb;			// 0x70
	__int64 bitSetMask; // 0x90
	Uint32 bitCount; // 0x98
	char pad_0x9C[0xA0 - 0x9C];
	LinearTransform* m_GameWorldTransformBase; //0xA0
	EntityBusPeer** m_transformNodes;	// 0xA8  // not sure (a list of ClientPartCompent or ClientChassisComponent , size of bitCount perhaps witt bitsetmask)
	char unknpad_0xA8[0xC0 - 0xA8];
	PhysicsEntityData* m_PhysData; //0xC0 
	Pointer m_pHavokPhysicsData; //0xC8
	char unknpad_0xD0[0xE0 - 0xD0];
};

// Flags:0x35 Size:0x100 Fields:0
// Warning: Missing fieldinfo data
class SimplePhysicsEntity : public PhysicsEntity
{
public:
	//char aPhysicsEntity[224]; //+0x00 Inherited
	char unknpad[0x100 - 0xE0]; // 0xF8 a RigidBody
};

// Flags:0x35 Size:0x120 Fields:0
// Warning: Missing fieldinfo data
class DynamicPhysicsEntity : public SimplePhysicsEntity
{
public:
	//char aSimplePhysicsEntity[256]; //+0x00 Inherited
	char unknpad[0x120 - 0x100];
};


////////////////////////////////////////
// ClassId:   00426
// RuntimeId: 05564
// TypeInfo:  0x00000001427CDC40
#ifndef _ClientUnlockComponent_
#define _ClientUnlockComponent_
class ClientUnlockComponent : public ClientGameComponent
{
public:
	static __inline unsigned int ClassId()
	{
		return 426;
	}
	char _0x0038[72];
};//Size=0x0080
#endif

class ClientVehicleEntity : public ClientControllableEntity
{
public:
	char _0x0188[0x238 - 0x188];
	DynamicPhysicsEntity* m_pDynamicPhysicsEntity; //0x0238 DynamicPhysicsEntity* Rid  8011
	Float32 m_waterLevel; //0x0240 
	Float32 m_terrainLevel; //0x0244 
	Float32 m_waterLevelUpdateTimer; //0x0248 
	Float32 m_terrainLevelUpdateTime; //0x024C 
	AxisAlignedBox m_childrenAABB; //0x0250 
	char _0x0270[0x280 - 0x270];
	Vec3 m_Velocity; //0x0280 
	Vec3 m_prevVelocity; //0x0290 
	char _0x02A0[0x3E0 - 0x2A0];
	ClientChassisComponent* m_Chassis; //0x03E0
	char _0x3E8[91];
	BYTE orange; //0x443
};//Size=0x03E0


 



class ClientPlayer
{
public:
	class ClientPlayerView
	{
	public:
		char _0x0000[248];
		ClientPlayer* m_Owner; //0x00F8  
		char _0x0100[272];
	};//Size=0x0210

	virtual ~ClientPlayer();
	virtual DWORD_PTR GetCharacterEntity(); // ClientSoldierEntity + 188 
	virtual DWORD_PTR GetCharacterUserData(); // PlayerCharacterUserData
	virtual EntryComponent* GetEntryComponent();
	virtual bool InVehicle();
	virtual unsigned int getId();
	virtual bool hasUnlockAsset(LPVOID, bool);
	virtual void getUnlockAssets(eastl::vector<LPVOID> *);
	virtual bool isUnlocked(LPVOID);

	Pointer PlayerData_ptr_m_PlayerData; //0x0008 PlayerData*
	char _0x0010[48];
	char szName[16]; //0x0040 
	char _0x0050[2920];
	Pointer UnlockAsset_ptr_m_pUnlockAsset; //0x0BB8 UnlockAsset*
	char _0x0BC0[2060];
	Int32 m_teamId; //0x13CC 
	char _0x13D0[240];

	ClientSoldierEntity* m_pAttachedControllable;    //0x14C0  ClientVehicleEntity
	char _0x14C8[8];
	ClientSoldierEntity* m_pControlledControllable;   //0x14D0 ClientSoldierEntity
	__int64 m_EntryID; //0x14D8 
	Pointer m_input; //0x14E0 
	char _0x14E8[16];
	Int32 m_Id; //0x14F8 
	Int32 m_ConnectionId; //0x14FC 
	Int32 m_lastTeamHit; //0x1500 
	Int32 m_inputNetworkId; //0x1504 
	Pointer ClientEntryComponent_ptr_m_oldEntry; //0x1508 ClientEntryComponent* ou ClientPlayerEntryComponent?
	void* m_pPlayerManager; //0x1510 PlayerManager*
	ClientPlayerView* m_ownPlayerView; //0x1518 ClientPlayerView*
	ClientPlayerView* m_PlayerView; //0x1520 ClientPlayerView*
	Int32 m_customHead; //0x1528 
	char _0x152C[0x1530 - 0x1528];
	void* m_InputActionMap; //0x1530 
	void* m_InputTranslator; //0x1538 
	char _0x1540[0x1548 - 0x1540];
	struct
	{
		bool m_Visible : 1; //0x1548
		bool m_HasInput : 1; //0x1548
		bool m_IsDeleted : 1; //0x1548
		bool m_IsLocal : 1; //0x1548
		bool m_FlipY : 1; //0x1548
		bool m_FlipCameraY : 1; //0x1548
		bool m_ExternalInputStateValid : 1; //0x1548
		bool m_ExternalInputStateOverride : 1; //0x1548
	};

	ClientSoldierEntity* GetClientSoldier()
	{
		if (this->InVehicle())
			return (ClientSoldierEntity*)(this->GetCharacterUserData() - 0x290);

		if (m_pControlledControllable)
			return m_pControlledControllable;

		return NULL;
	}

	ClientVehicleEntity* GetClientVehicleEntity()
	{
		if (this->InVehicle())
			return (ClientVehicleEntity*)m_pAttachedControllable;

		return NULL;
	}

};

class PlayerData
{
public:
};


class ClientPlayerManager
{
public:
	virtual void function();
	virtual eastl::vector<ClientPlayer*>* getPlayers();
	virtual eastl::vector<ClientPlayer*>* getSpectators();
	PlayerData* playerdata; //0x0008 PlayerData Rid  6428
	Uint32 m_maxPlayerCount; //0x0010 
	char _0x0014[0x540-0x014];
	ClientPlayer*    m_pLocalPlayer;        //0x0540
	ClientPlayer**    m_ppPlayers;        //0x0548

	ClientPlayer* GetPlayerById(unsigned int id)
	{
		if (id < 70)
			return this->m_ppPlayers[id];

		return NULL;
	}
};

class _Material
{
public:

	enum MaterialFlag// from bf3 :S 
	{
		MfPenetrable = 0x1000000,
		MfClientDestructible = 0x2000000,
		MfBashable = 0x4000000,
		MfSeeThrough = 0x8000000,
		MfNoCollisionResponse = 0x10000000,
		MfNoCollisionResponseCombined = 0x20000000,
		MfIndexMask = 0xFFFFFF
	};

	ULONG64 m_flagsAndIndex;

	__forceinline bool isPenetrable()
	{
		return !!(m_flagsAndIndex & 0x80000000);
	};

	__forceinline bool isSeeThrough()
	{
		return !!(m_flagsAndIndex & 0x20000000);
	};

	__forceinline bool isClientDestructible()
	{
		return !!(m_flagsAndIndex & 0x40000000);
	};

	__forceinline bool isBashable(void)
	{
		return !!(m_flagsAndIndex & MfBashable);
	};

	__forceinline bool NoCollisionResponse(void)
	{
		return !!(m_flagsAndIndex & MfNoCollisionResponse);
	};

	__forceinline bool NoCollisionResponseCombined(void)
	{
		return !!(m_flagsAndIndex & MfNoCollisionResponseCombined);
	}
};

class RayCastHit
{
public:
	Vec3 m_position;        // 0x00 
	Vec3 m_normal;        // 0x10 
	void* m_rigidBody;        // 0x20 
	_Material m_material;    // 0x28 
	DWORD m_part;            // 0x30 
	FLOAT m_lambda;            // 0x34 
	char _pad[56];            // 0x38 
}; // 0x70 


class IPhysicsRayCaster
{
public:

	enum RayCastFlags
	{
		CheckDetailMesh = 0x1,
		IsAsyncRaycast = 0x2,
		DontCheckWater = 0x4,
		DontCheckTerrain = 0x8,
		DontCheckRagdoll = 0x10,
		DontCheckCharacter = 0x20,
		DontCheckGroup = 0x40,
		DontCheckPhantoms = 0x80,
		FORCE32BIT = 0x7FFFFFFF,
		AimbotFlags = (0x4 | 0x10 | 0x20 | 0x80)
	};

	virtual bool PhysicsRayQuery(const char* identifier, Vec3* from, Vec3* to, RayCastHit* hit, int flag, eastl::fixed_vector<PhysicsEntity const*, 8, 0>* PhysicsEntityList);
//	virtual bool PhysicsRayQuery(const char* identifier, Vec3* from, Vec3* to, RayCastHit* hit, int flag, void* PhysicsEntityList);
	virtual void* asyncPhysicsRayQuery(const char* identifier, Vec3* from, Vec3* to, int flag, void* PhysicsEntityList);

};

class GameWorld
{
public:
	BYTE pad00[0x58];    // 0x00
	IPhysicsRayCaster* m_RayCaster;  // 0x0058
};

#ifndef _ClientGameWorld_
#define _ClientGameWorld_
class ClientGameWorld : public GameWorld, public IPhysicsRayCaster
{
public:

};
#endif

//OFFSET PRINCIPALE
class WorldRenderSettings
{
public:
	char pad_0x0000[120];
	float m_motionBlurScale; //0x0078 
	float m_motionBlurMax; //0x007C 
	float m_motionBlurNoiseScale; //0x0080 
	DWORD m_motionBlurQuality; //0x0084 
	DWORD m_dynamicEnvmapResolution; //0x0088 
	DWORD m_maxDecalVolumeCount; //0x008C 
	DWORD m_motionBlurMaxSampleCount; //0x0090 
	DWORD m_motionBlurFrameAverageCount; //0x0094 
	float m_motionBlurMaxFrameTime; //0x0098 
	float m_forceMotionBlurDepthCutoff; //0x009C 
	float m_forceMotionBlurCutoffGradientScale; //0x00A0 
	DWORD m_multisampleCount; //0x00A4 
	float m_multisampleThreshold; //0x00A8 
	DWORD m_maxSpotLightShadowCount; //0x00AC 
	DWORD m_reflectionEnvmapSize; //0x00B0 
	float m_spotLightNearPlane; //0x00B4 
	float m_subSurfaceRolloff; //0x00B8 
	DWORD m_unk0; //0x00BC 
	DWORD m_maxSpotLightCount; //0x00C0 
	DWORD m_spotLightShadowmapResolution; //0x00C4 
	DWORD m_spotLightShadowmapQuality; //0x00C8 
	char pad_0x00CC[105];
	BYTE m_drawSky; //0x0135 
	BYTE m_drawSunRays; //0x0136 
	BYTE m_drawFog; //0x0137 
	BYTE m_drawSunBlur; //0x0138 
	char pad_0x0139[285];
	BYTE m_drawSunRays2; //0x0256 

	static WorldRenderSettings* GetInstance()
	{
		return *(WorldRenderSettings**)OFFSET_WORLDRENDERSETTINGS;
	}
};

class HavokPhysicsManager
{
public:
	BYTE pad00[0x120];            // 0x00
	GameWorld* m_GameWorld;        // 0x120
};


//POINTER PRINCIPAL
class ClientGameContext
{
public:
	BYTE pad00[0x20];                        // 0x00
	DWORD_PTR m_GameTime;                    // 0x20
	HavokPhysicsManager* m_pPhysicsManager;    // 0x28
	BYTE pad30[0x30];                        // 0x30
	ClientPlayerManager* m_pPlayerManager;    // 0x60

	static ClientGameContext* GetInstance()
	{
		return *(ClientGameContext**)(OFFSET_GAMECONTEXT);
	}
};

class RenderView
{
public:
	char _0x0000[64];
	Matrix m_Transform; //0x0040 
	char _0x0080[52];
	float m_FovY; //0x00B4 
	float defualtFovY; //0x00B8 
	float nearPlane; //0x00BC 
	float farPlane; //0x00C0 
	float m_Aspect; //0x00C4 
	float orthoWidth; //0x00C8 
	float orthoHeight; //0x00CC 
	char _0x00D0[384];
	float m_FovX; //0x0250 
	float depthHeightRatio; //0x0254 
	float fovScale; //0x0258 
	float fovScaleSqr; //0x025C 
	Matrix m_viewMatrix; //0x0260 
	Matrix m_viewMatrixTranspose; //0x02A0 
	Matrix m_viewMatrixInverse; //0x02E0 
	Matrix m_ProjectionMatrix; //0x0320 
	Matrix m_viewMatrixAtOrigin; //0x0360 
	Matrix m_ProjectionTranspose; //0x03A0 
	Matrix m_ProjectionInverse; //0x03E0 
	Matrix m_ViewProj; //0x0420 
	Matrix m_ViewProjTranspose; //0x0460 
	Matrix m_ViewProjInverse; //0x04A0 
	Matrix m_UnknMatrix; //0x04E0   
	Matrix m_Transform2; //0x0520 
	Matrix m_UnknMatrix2; //0x0560 
};

class GameRenderSettings : public DataContainer
{
public:
	unsigned int m_InactiveSkipFrameCount; //+0x10
	float m_ResolutionScale; //+0x14
	unsigned int m_XenonRingBufferSize; //+0x18
	unsigned int m_XenonLinearFrameBufferSize; //+0x1C
	unsigned int m_XenonPresentImmediateThreshold; //+0x20
	unsigned int m_XenonGammaRampType; //+0x24
	float m_Ps3VideoGamma; //+0x28
	unsigned int m_Ps3FrameMainBufferSize; //+0x2C
	unsigned int m_Ps3FrameLocalBufferSize; //+0x30
	unsigned int m_Ps3VSyncMethod; //+0x34
	float m_CameraCutMaxFrameTranslation; //+0x38
	float m_NearPlane; //+0x3C
	float m_ViewDistance; //+0x40
	float m_ForceFov; //+0x44
	float m_FovMultiplier; //+0x48
	float m_ForceOrthoViewSize; //+0x4C
	float m_EdgeModelScreenAreaScale; //+0x50
	float m_EdgeModelViewDistance; //+0x54
	int m_EdgeModelForceLod; //+0x58
	float m_EdgeModelLodScale; //+0x5C
	unsigned int m_EdgeModelMaxVisibleInstanceCount; //+0x60
	float m_StaticModelPartOcclusionMaxScreenArea; //+0x64
	unsigned int m_StaticModelCullJobCount; //+0x68
	unsigned int m_SplitScreenTestViewCount; //+0x6C
	unsigned int m_SplitScreenTestCase; //+0x70
	float m_ForceBlurAmount; //+0x74
	float m_ForceWorldFadeAmount; //+0x78
	float m_StereoCrosshairMaxHitDepth; //+0x7C
	float m_StereoCrosshairRadius; //+0x80
	float m_StereoCrosshairDampingFactor; //+0x84
	bool m_Enable; //+0x88
	bool m_NullRendererEnable; //+0x89
	bool m_JobEnable; //+0x8A
	bool m_BuildJobSyncEnable; //+0x8B
	bool m_EarlyGpuSyncEnable; //+0x8C
	bool m_DrawDebugInfo; //+0x8D
	bool m_DrawScreenInfo; //+0x8E
	bool m_Fullscreen; //+0x8F
	bool m_ForceVSyncEnable; //+0x90
	bool m_MovieVSyncEnable; //+0x91
	bool m_VSyncFlashTestEnable; //+0x92
	bool m_MantleEnable; //+0x93
	bool m_XenonBufferTwoFramesEnable; //+0x94
	bool m_XenonRes1280x704Enable; //+0x95
	bool m_Ps3LinearFrameCmdBufEnable; //+0x96
	bool m_Ps3CellMemoryTexturesEnable; //+0x97
	bool m_GcmHudEnable; //+0x98
	bool m_Ps3Res1280x704Enable; //+0x99
	bool m_Gen4bColorRemap; //+0x9A
	bool m_GpuTextureCompressorEnable; //+0x9B
	bool m_EmittersEnable; //+0x9C
	bool m_EntityRenderEnable; //+0x9D
	bool m_DebugRendererEnable; //+0x9E
	bool m_DebugRenderServiceEnable; //+0x9F
	bool m_InitialClearEnable; //+0xA0
	bool m_GpuProfilerEnable; //+0xA1
	bool m_ForceOrthoViewEnable; //+0xA2
	bool m_ForceSquareOrthoView; //+0xA3
	bool m_DestructionVolumeDrawEnable; //+0xA4
	bool m_EdgeModelsEnable; //+0xA5
	bool m_EdgeModelCastShadowsEnable; //+0xA6
	bool m_EdgeModelDepthBiasEnable; //+0xA7
	bool m_EdgeModelShadowDepthBiasEnable; //+0xA8
	bool m_EdgeModelSpuInstancingEnable; //+0xA9
	bool m_EdgeModelUseMainLodEnable; //+0xAA
	bool m_EdgeModelUseLodBox; //+0xAB
	bool m_EdgeModelCullEnable; //+0xAC
	bool m_EdgeModelFrustumCullEnable; //+0xAD
	bool m_EdgeModelOcclusionCullEnable; //+0xAE
	bool m_EdgeModelDrawBoxes; //+0xAF
	bool m_EdgeModelDrawStats; //+0xB0
	bool m_StaticModelEnable; //+0xB1
	bool m_StaticModelMeshesEnable; //+0xB2
	bool m_StaticModelZPassEnable; //+0xB3
	bool m_StaticModelPartCullEnable; //+0xB4
	bool m_StaticModelPartFrustumCullEnable; //+0xB5
	bool m_StaticModelPartOcclusionCullEnable; //+0xB6
	bool m_StaticModelPartShadowCullEnable; //+0xB7
	bool m_StaticModelDrawBoxes; //+0xB8
	bool m_StaticModelDrawStats; //+0xB9
	bool m_StaticModelCullSpuJobEnable; //+0xBA
	bool m_StaticModelSurfaceShaderTerrainAccessEnable; //+0xBB
	bool m_LockView; //+0xBC
	bool m_ResetLockedView; //+0xBD
	bool m_SecondaryStreamingViewEnable; //+0xBE
	bool m_FadeEnable; //+0xBF
	bool m_FadeWaitingEnable; //+0xC0
	bool m_BlurEnable; //+0xC1
};


//POINTER PRINCIPALE
class GameRenderer
{
public:
	char _0x0000[72];
	GameRenderSettings* m_GameRenderSettings; //0x0048 
	char _0x0050[16];
	RenderView* m_pRenderView;        // 0x60

	static GameRenderer* GetInstance()
	{
		return *(GameRenderer**)(OFFSET_GAMERENDERER);
	}
};


////////////////////////////////////////
// ClassId:   03687
// RuntimeId: 03653
// TypeInfo:  0x000000014276D450
#ifndef _SystemSettings_
#define _SystemSettings_
#pragma pack(push, 8)
class SystemSettings : public DataContainer
{
public:
	static __inline SystemSettings* DefaultInstance()
	{
		return (SystemSettings*)0x00000000463C42B0;
	}
	static __inline unsigned int ClassId()
	{
		return 3687;
	}
	char* m_Name; //0x0010
	GamePlatform m_Platform; //0x0018
	char _0x001C[4];
};//Size=0x0020
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03716
// RuntimeId: 08040
// TypeInfo:  0x00000001427D6320
#ifndef _DxDisplaySettings_
#define _DxDisplaySettings_
#pragma pack(push, 8)
class DxDisplaySettings : public SystemSettings
{
public:
	static __inline DxDisplaySettings* DefaultInstance()
	{
		return (DxDisplaySettings*)0x00000000463C58A0;
	}
	static __inline unsigned int ClassId()
	{
		return 3716;
	}
	Array<__int32> m_DebugBreakIgnoredIDs; //0x0020
	unsigned __int32 m_FullscreenHeight; //0x0028
	unsigned __int32 m_FullscreenWidth; //0x002C
	float m_FullscreenRefreshRate; //0x0030
	__int32 m_FullscreenOutputIndex; //0x0034
	__int32 m_PresentInterval; //0x0038
	unsigned __int32 m_PresentImmediateThreshold; //0x003C
	__int32 m_RenderAheadLimit; //0x0040
	float m_StereoDepth; //0x0044
	float m_StereoConvergenceScale; //0x0048
	float m_StereoSeparationScale; //0x004C
	float m_StereoSoldierZoomConvergenceScale; //0x0050
	unsigned __int32 m_NvidiaMinDriverVersion; //0x0054
	char* m_AmdMinDriverVersion; //0x0058
	float m_LowResDisplayPlaneScale; //0x0060
	bool m_NullDriverEnable; //0x0064
	bool m_RefDriverEnable; //0x0065
	bool m_WarpDriverEnable; //0x0066
	bool m_Dx10Dot0Enable; //0x0067
	bool m_Dx10Dot1Enable; //0x0068
	bool m_Dx10PlusEnable; //0x0069
	bool m_Dx11Enable; //0x006A
	bool m_Dx11Dot1Enable; //0x006B
	bool m_Dx11Dot1RuntimeEnable; //0x006C
	bool m_CreateMinimalWindow; //0x006D
	bool m_DriverInternalThreadingEnable; //0x006E
	bool m_DxDiagDriverDetectionEnable; //0x006F
	bool m_DebugInfoEnable; //0x0070
	bool m_DebugInfoOutputEnable; //0x0071
	bool m_DebugBreakOnErrorEnable; //0x0072
	bool m_DebugBreakOnWarningEnable; //0x0073
	bool m_DebugBreakOnInfoEnable; //0x0074
	bool m_FullscreenModeEnable; //0x0075
	bool m_Fullscreen; //0x0076
	bool m_WindowBordersEnable; //0x0077
	bool m_VSyncEnable; //0x0078
	bool m_TripleBufferingEnable; //0x0079
	bool m_NvApiEnable; //0x007A
	bool m_NvPerfHudEnable; //0x007B
	bool m_AnnotationInterfaceEnable; //0x007C
	bool m_StereoEnable; //0x007D
	bool m_StereoSplitScreenEnable; //0x007E
	bool m_MinDriverRequired; //0x007F
	bool m_AmdQuadsEnable; //0x0080
	bool m_DepthBoundsExtensionEnable; //0x0081
	bool m_MultiGpuValidationEnable; //0x0082
	bool m_DiscardFrameTempBuffersEnable; //0x0083
	bool m_PixProfilingEnable; //0x0084
	bool m_AsyncCmdListExecutionEnable; //0x0085
	bool m_VideoOutSrgbFullEnable; //0x0086
	bool m_VideoOutSrgbToRec709Enable; //0x0087
	bool m_EndFrameJobEnable; //0x0088
	bool m_LowResDisplayPlaneEnable; //0x0089
	bool m_ForceRenderTargetInEsramTest; //0x008A
	char _0x008B[5];
};//Size=0x0090
#pragma pack(pop)
#endif



class Mouse
{
public:

	class MouseDevice
	{
	public:

		class MouseState
		{
		public:
			long x; //0x0000
			long y; //0x0004
			long z; //0x0008
			unsigned char buttons[0x8]; //0x000C
		};

		virtual void Function0(); // 0x0000
		virtual void Read(float SampleTime, bool VisualFrame); //0x0008 
		virtual const char* Name(void); //0x0010 
		virtual const char* Name(unsigned int); // 0x0018 
		virtual unsigned int ControlCount(); // 0x0020 
		virtual bool IsConnected(); // 0x0028
		virtual bool IsAnalogue(unsigned int); // 0x0030
		virtual float GetValue(unsigned int);    // 0x0038

		char _0x0008[144];
		__int64 m_HWND; //0x0098 
		__int64 m_pWindowProcedure; //0x00A0 
		char _0x00A8[40];
		BYTE m_CursorMode; //0x00D0 
		BYTE m_UIOwnsInput; //0x00D1 
		BYTE m_ShowCursor; //0x00D2 
		BYTE m_CursorConfined; //0x00D3 
		BYTE m_HasOverflowed; //0x00D4 
		BYTE m_UseRawMouseInput; //0x00D5 
		BYTE m_WindowActive; //0x00D6 
		char _0x00D7[25];
		MouseState m_Current; //0x00F0
		MouseState m_Buffer; //0x0104
		char _0x0118[24];

	}; //Size = 0x0130

	char _0x0000[16];
	MouseDevice* m_pDevice; // 0x0010

}; //Size = 0x0100

class Keyboard
{
public:

	class KeyboardDevice
	{
	public:
		virtual void Function0(); // 0x0000
		virtual void Read(float SampleTime, bool VisualFrame); //0x0008 
		virtual const char* Name(unsigned int); //0x0010 
		virtual const char* Name(void); // 0x0018 
		virtual unsigned int ControlCount(); // 0x0020 
		virtual bool IsConnected(); // 0x0028
		virtual bool IsAnalogue(unsigned int); // 0x0030
		virtual float GetValue(unsigned int);    // 0x0038

		char _0x0008[144];
		__int64 m_HWND; //0x0098 
		__int64 m_pWindowProcedure; //0x00A0 fb::WindowProcedure( ) 
		unsigned char m_Current[0x100]; //0x00A8
		unsigned char m_Buffer[0x100]; //0x01A8
		BYTE m_TypingMode; //0x02A8 
		BYTE m_HasOverflowed; //0x02A9 
		__int32 m_CodePage; //0x02AA 
		char _0x02AE[2];
	}; //Size = 0x02B0

	class KeyboardActionData
	{
	public:
		char _0x0000[16];
		BYTE m_IsAnalog; //0x0010 
		BYTE m_NegateValue; //0x0011 
		char _0x0012[14];
	}; //Size = 0x0020

	char _0x0000[8];
	KeyboardDevice* m_pDevice; //0x0008 
	char _0x0010[136];
	KeyboardActionData* m_pActionData; //0x0098
	char _0x00A0[24];
}; //Size = 0x00B8



//OFFSET PRINCIPALE
class BorderInputNode
{
public:

	class InputCache
	{
	public:
		char pad_0x0000[4];
		float flInputBuffer[223];
	};

	virtual void init();
	virtual void exit();

	InputCache* m_inputCache; //0x0008 
	char _0x0010[48];
	__int64 m_pInputNode; //0x0040 
	//InstanceInputNode* m_pInputNode; //0x0040 
	char _0x0048[8];
	Keyboard* m_pKeyboard; //0x0050 
	Mouse* m_pMouse; //0x0058

	static BorderInputNode* GetInstance()
	{
		return *(BorderInputNode**)(OFFSET_BORDERINPUTNODE);
	}
};


////////////////////////////////////////
// ClassId:   03717
// RuntimeId: 08762
// TypeInfo:  0x00000001427E5B10
//OFFSET PRINCIPALE
#ifndef _EnlightenRuntimeSettings_
#define _EnlightenRuntimeSettings_
#pragma pack(push, 16)
class EnlightenRuntimeSettings : public SystemSettings
{
public:
	static __inline EnlightenRuntimeSettings* DefaultInstance()
	{
		return (EnlightenRuntimeSettings*)0x00000000463C5990;
	}
	static __inline unsigned int ClassId()
	{
		return 3717;
	}
	Vec3 m_AlbedoDefaultColor; //0x0020
	float m_TemporalCoherenceThreshold; //0x0030
	float m_SkyBoxScale; //0x0034
	float m_MaxPerFrameSolveTime; //0x0038
	unsigned __int32 m_MinSystemUpdateCount; //0x003C
	unsigned __int32 m_JobCount; //0x0040
	unsigned __int32 m_CubeMapMaxUpdateCount; //0x0044
	unsigned __int32 m_CubeMapConvolutionSampleCount; //0x0048
	float m_CubeMapForceGlobalScale; //0x004C
	unsigned __int32 m_LightProbeMaxSourceSolveCount; //0x0050
	unsigned __int32 m_LightProbeMaxInstanceUpdateCount; //0x0054
	unsigned __int32 m_LightProbeLookupTableGridRes; //0x0058
	float m_LocalLightForceRadius; //0x005C
	__int32 m_DrawDebugSystemDependenciesEnable; //0x0060
	__int32 m_DrawDebugSystemBoundingBoxEnable; //0x0064
	float m_DrawDebugLightProbeSize; //0x0068
	bool m_Enable; //0x006C
	bool m_ForceDynamic; //0x006D
	bool m_ForceUpdateStaticLightingBuffersEnable; //0x006E
	bool m_SaveRadiosityTexturesEnable; //0x006F
	bool m_JobsEnable; //0x0070
	bool m_ShadowsEnable; //0x0071
	bool m_SpotLightShadowsEnable; //0x0072
	bool m_CubeMapsEnable; //0x0073
	bool m_CubeMapMip0OnlyEnable; //0x0074
	bool m_CubeMapCpuMipMapGenerationEnable; //0x0075
	bool m_CubeMapConvolutionEnable; //0x0076
	bool m_CompensateSunShadowHeightScale; //0x0077
	bool m_LightMapsEnable; //0x0078
	bool m_LightProbeEnable; //0x0079
	bool m_LightProbeNewSamplingEnable; //0x007A
	bool m_LightProbeForceUpdate; //0x007B
	bool m_LightProbeJobsEnable; //0x007C
	bool m_LocalLightsEnable; //0x007D
	bool m_LocalLightCullingEnable; //0x007E
	bool m_LocalLightCustumFalloff; //0x007F
	bool m_DrawDebugCubeMaps; //0x0080
	bool m_DrawDebugEntities; //0x0081
	bool m_DrawDebugSystemsEnable; //0x0082
	bool m_DrawDebugLightProbes; //0x0083
	bool m_DrawDebugLightProbeGrid; //0x0084
	bool m_DrawDebugLightProbeOcclusion; //0x0085
	bool m_DrawDebugLightProbeStats; //0x0086
	bool m_DrawDebugLightProbeBoundingBoxes; //0x0087
	bool m_DrawSolveTaskPerformance; //0x0088
	bool m_DrawDebugColoringEnable; //0x0089
	bool m_DrawDebugTextures; //0x008A
	bool m_DrawDebugBackFaces; //0x008B
	bool m_DrawDebugTargetMeshes; //0x008C
	bool m_DrawWarningsEnable; //0x008D
	bool m_AlbedoForceUpdateEnable; //0x008E
	bool m_AlbedoForceColorEnable; //0x008F
	bool m_TerrainMapEnable; //0x0090
	bool m_EmissiveEnable; //0x0091
	char _0x0092[14];

	static EnlightenRuntimeSettings* Singleton()
	{
		return *(EnlightenRuntimeSettings**)OFFSET_ENLIGHTENRUNTIMESETTINGS;
	}

};//Size=0x00A0
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03417
// RuntimeId: 03604
// TypeInfo:  0x000000014276BE30

//OFFSET PRINCIPALE
#ifndef _DebugRenderSettings_
#define _DebugRenderSettings_
#pragma pack(push, 8)
class DebugRenderSettings : public DataContainer
{
public:
	static __inline DebugRenderSettings* DefaultInstance()
	{
		return (DebugRenderSettings*)0x00000000463BEBB0;
	}
	static __inline unsigned int ClassId()
	{
		return 3417;
	}
	float m_TextViewDistance; //0x0010
	unsigned __int32 m_TextQueueMaxLineCount; //0x0014
	float m_TextQueueTimeVisible; //0x0018
	__int32 m_ProcessJobCount; //0x001C
	unsigned __int32 m_Ps3SpuFrameBufferSize; //0x0020
	unsigned __int32 m_DxMaxVertexCount; //0x0024
	bool m_Enable; //0x0028
	bool m_DrawStatsEnable; //0x0029
	bool m_TextQueueLocationTop; //0x002A
	bool m_Ps3SpuEnable; //0x002B
	bool m_DxLine2dAntialiasingEnable; //0x002C
	bool m_DxLine3dAntialiasingEnable; //0x002D
	char _0x002E[2];

	static DebugRenderSettings* Singleton()
	{
		return *(DebugRenderSettings**)OFFSET_DEBUGRENDERSETTINGS;
	}
};//Size=0x0030
#pragma pack(pop)
#endif


class EntryComponent {
public:
	class WeaponInfo {
	public:
		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual WeaponFiring* GetWeaponFiring();
		virtual ClientWeapon* GetWeapon();
		virtual bool ActiveInStance(int stance);
		virtual void* GetWeaponComponent(); //WeaponComponent
	};

	class FiringCallbacks {
	public:
		virtual void Function0();
		char __0x0004[0x4];
		WeaponInfo* weapon_info;
	};

	virtual int GetActiveStance();
	virtual bool isCharacterControlEntry();
	virtual void /*struct fb::AnimTreeDataAsset */animTree();
	virtual void onPrimaryStartedFiring(EntryComponent::WeaponInfo *);
	virtual void onPrimaryFire(EntryComponent::WeaponInfo *);
	virtual void onPrimaryFireRelease(EntryComponent::WeaponInfo *);
	virtual void onPrimaryFireShotSpawned(EntryComponent::WeaponInfo *, float);
	virtual void onPrimaryFireAutomaticBegin(EntryComponent::WeaponInfo *);
	virtual void onPrimaryFireAutomaticEnd(EntryComponent::WeaponInfo *);
	virtual void onPrimaryStoppedFiring(EntryComponent::WeaponInfo *);
	virtual void onReload(EntryComponent::WeaponInfo *);
	virtual EntryComponentData *GetEntryComponentData();
	virtual void onSwitchStance();
	virtual bool isStanceAvailable(int);

	eastl::vector<FiringCallbacks*> weapons;
	eastl::vector<void *> m_subscribers;
	void *m_turretComponent;
	boolean m_underExternalControl;
	byte placeholder;
	__int16 m_inputModifierCacheSize;
	//EntryComponent::InputModifier *m_inputModifierCache;
};





////////////////////////////////////////
// ClassId:   00339
// RuntimeId: 05511
// TypeInfo:  0x0000000142799B50
#ifndef _ClientEntryComponent_
#define _ClientEntryComponent_
class ClientEntryComponent : public ClientGameComponent
{
public:
	static __inline unsigned int ClassId()
	{
		return 339;
	}
	char _0x0038[680];
};//Size=0x02E0
#endif

////////////////////////////////////////
// ClassId:   00342
// RuntimeId: 05512
// TypeInfo:  0x00000001427998D0
#ifndef _ClientPlayerEntryComponent_
#define _ClientPlayerEntryComponent_
class ClientPlayerEntryComponent : public ClientEntryComponent
{
public:
	static __inline unsigned int ClassId()
	{
		return 342;
	}
	char _0x02E0[864];
};//Size=0x0640
#endif


////////////////////////////////////////
// ClassId:   03344
// RuntimeId: 07971
// TypeInfo:  0x00000001427D2200

//OFFSET PRINCIPALE
#ifndef _PhysicsSettings_
#define _PhysicsSettings_
#pragma pack(push, 8)
class PhysicsSettings : public DataContainer
{
public:
	static __inline PhysicsSettings* DefaultInstance()
	{
		return (PhysicsSettings*)0x00000000463BD3D0;
	}
	static __inline unsigned int ClassId()
	{
		return 3344;
	}
	unsigned __int32 m_ClientEffectWorldThreadCount; //0x0010
	unsigned __int32 m_ClientClothWorldThreadCount; //0x0014
	unsigned __int32 m_ClientWorldThreadCount; //0x0018
	unsigned __int32 m_ServerWorldThreadCount; //0x001C
	unsigned __int32 m_IntegrateJobCount; //0x0020
	unsigned __int32 m_CollideJobCount; //0x0024
	unsigned __int32 m_ClothJobCount; //0x0028
	float m_WindManagerAwakeningRadius; //0x002C
	unsigned __int32 m_ClientWorldWorkerThreadCount; //0x0030
	unsigned __int32 m_ServerWorldWorkerThreadCount; //0x0034
	unsigned __int32 m_EffectWorldWorkerThreadCount; //0x0038
	bool m_Enable; //0x003C
	bool m_EnableClothInterpolationJobs; //0x003D
	bool m_EnableClothUpdateJob; //0x003E
	bool m_EnableAIRigidBody; //0x003F
	bool m_ForestEnable; //0x0040
	bool m_EnableJobs; //0x0041
	bool m_RemoveRagdollWhenWoken; //0x0042
	bool m_RemoveFromWorldOnCollisionOverflow; //0x0043
	bool m_SingleStepCharacter; //0x0044
	bool m_ForceSingleStepCharacterInSP; //0x0045
	bool m_EnableFollowWheelRaycasts; //0x0046
	bool m_EnableClientWheelRaycasts; //0x0047
	bool m_EnableASyncWheelRaycasts; //0x0048
	bool m_UseDelayedWakeUpClient; //0x0049
	bool m_UseDelayedWakeUpServer; //0x004A
	bool m_SuppressDebrisSpawnUntilReady; //0x004B
	bool m_EnablePlayerVSAICollisions; //0x004C
	char _0x004D[3];

	static PhysicsSettings* Singleton()
	{
		return *(PhysicsSettings**)OFFSET_PHYSICSSETTINGS;
	}
};//Size=0x0050
#pragma pack(pop)
#endif

//OFFSET PRINCIPALE
class MeshSettings : public DataContainer
{
public:
	char* m_OverrideShadersShaderName; //+0x10
	char* m_OverrideShadersMeshName; //+0x18
	int m_ForceLod; //+0x20
	float m_GlobalLodScale; //+0x24
	float m_ShadowDistanceScale; //+0x28
	float m_TessellationMaxFactor; //+0x2c
	float m_TessellationForceTessellationFactor; //+0x30
	float m_TessellationMaxDistance; //+0x34
	float m_TessellationMaxDistanceFade; //+0x38
	QualityLevel m_CastSunShadowQualityLevel; //+0x3c
	QualityLevel m_CastDynamicEnvmapQualityLevel; //+0x40
	QualityLevel m_CastPlanarReflectionQualityLevel; //+0x44
	bool m_LoadingEnabled; //+0x48
	bool m_TessellationEnable; //+0x49
	bool m_TessellationBackFaceCullingEnable; //+0x4a
	bool m_TessellationScreenSpaceAdativeEnable; //+0x4b

	static MeshSettings* Singleton()
	{
		return *(MeshSettings**)OFFSET_MESHSETTINGS;
	}
};



////////////////////////////////////////
// ClassId:   03410
// RuntimeId: 04758
// TypeInfo:  0x0000000142784810

//OFFSET PRINCIPALE
#ifndef _EmitterSystemSettings_
#define _EmitterSystemSettings_
#pragma pack(push, 8)
class EmitterSystemSettings : public DataContainer
{
public:
	static __inline EmitterSystemSettings* DefaultInstance()
	{
		return (EmitterSystemSettings*)0x00000000463BE950;
	}
	static __inline unsigned int ClassId()
	{
		return 3410;
	}
	unsigned __int32 m_SkipUpdateMaxCount; //0x0010
	__int32 m_ForceJobCount; //0x0014
	float m_TimeScale; //0x0018
	float m_GlobalResetStartTimeInterval; //0x001C
	unsigned __int32 m_CollisionRayCastMaxCount; //0x0020
	unsigned __int32 m_ProximityPhysicsEntitiesMaxCount; //0x0024
	QualityLevel m_EmitterQualityLevel; //0x0028
	float m_TemplateTimeoutTime; //0x002C
	float m_ScreenAreaCullingStart; //0x0030
	float m_ScreenAreaCullingEnd; //0x0034
	float m_ScreenAreaCullingMinTotalArea; //0x0038
	float m_ScreenAreaCullingMaxTotalArea; //0x003C
	float m_ScreenAreaCullingMaxMultiplier; //0x0040
	float m_ProcessJobYieldTime; //0x0044
	float m_VisibleJobYieldTime; //0x0048
	unsigned __int32 m_DrawStats; //0x004C
	unsigned __int32 m_DrawBoundingBoxes; //0x0050
	float m_MinScreenArea; //0x0054
	unsigned __int32 m_DrawDebugAtlasMiplevel; //0x0058
	__int32 m_DrawDebugAtlasTextureIndex; //0x005C
	__int32 m_QuadTechnique; //0x0060
	float m_QuadNearFadeDistance; //0x0064
	unsigned __int32 m_QuadMaxCount; //0x0068
	float m_MeshCullingDistance; //0x006C
	unsigned __int32 m_MeshDrawCountLimit; //0x0070
	float m_MeshStreamingPriorityMultiplier; //0x0074
	unsigned __int32 m_MeshMaxCount; //0x0078
	bool m_Enable; //0x007C
	bool m_UpdateJobEnable; //0x007D
	bool m_EnableFixedTimeStep; //0x007E
	bool m_EnableFixedDelta; //0x007F
	bool m_EnableJobs; //0x0080
	bool m_CollisionRayCastEnable; //0x0081
	bool m_DrawDebugRayCastCollision; //0x0082
	bool m_EnableRendering; //0x0083
	bool m_ZBufferCullEnable; //0x0084
	bool m_DrawProjectedBoxes; //0x0085
	bool m_DrawTransforms; //0x0086
	bool m_DrawDebugBaseAtlas; //0x0087
	bool m_DrawDebugNormalAtlas; //0x0088
	bool m_QuadClipScaleEnable; //0x0089
	bool m_QuadEnableRendering; //0x008A
	bool m_QuadNiceRenderingEnable; //0x008B
	bool m_QuadSimpleRenderingEnable; //0x008C
	bool m_QuadEnableOpaque; //0x008D
	bool m_QuadEnableCustomShader; //0x008E
	bool m_QuadColorShaderCostsEnable; //0x008F
	bool m_QuadEnableSorting; //0x0090
	bool m_QuadEnableWireframe; //0x0091
	bool m_QuadHalfResEnable; //0x0092
	bool m_QuadGroupsJoinAll; //0x0093
	bool m_QuadGroupsJoinNone; //0x0094
	bool m_QuadGroupsJoinNiceAndSimple; //0x0095
	bool m_QuadVertexShadowsEnable; //0x0096
	bool m_QuadCloudVertexShadowsEnable; //0x0097
	bool m_QuadPlanarReflectionEnable; //0x0098
	bool m_QuadPointLightsEnable; //0x0099
	bool m_QuadSpotLightsEnable; //0x009A
	bool m_QuadResourceSyncJobEnable; //0x009B
	bool m_MeshRenderingEnable; //0x009C
	bool m_MeshDrawTransforms; //0x009D
	bool m_MeshDrawBoundingBoxes; //0x009E
	bool m_MeshShadowEnable; //0x009F
	bool m_MeshPlanarReflectionEnable; //0x00A0
	bool m_MeshDrawCullStats; //0x00A1
	char _0x00A2[6];

	static EmitterSystemSettings* Singleton()
	{
		return *(EmitterSystemSettings**)OFFSET_EMITTERSYSTEMSETTINGS;
	}
};//Size=0x00A8
#pragma pack(pop)
#endif

//OFFSET PRINCIPALE SUB
class OcclusionSettings : public DataContainer
{
public:
	bool m_Enable; //+0x10
	bool m_CoverageEnable; //+0x11
	bool m_DrawShadowZbuffer; //+0x12
	bool m_DrawZbuffer; //+0x13
	bool m_DrawSplitView; //+0x14
	bool m_DrawBinaryBuffer; //+0x15
	bool m_DrawCoverageBuffer; //+0x16

	static OcclusionSettings* Singleton()
	{
		return *(OcclusionSettings**)OFFSET_OCCLUSIONSETTINGS;
	}
};


//OFFSET PRINCIPALE
class EntitySettings : public SystemSettings
{
public:
	char* m_Name; //+0x10
	GamePlatform m_Platform; //+0x18
	int m_ExecutionMode; //+0x20
	unsigned int m_OutOfEntityBusNetworkIdThreshold; //+0x24
	bool m_EditorGameViewEnable; //+0x28
	bool m_SpawnSubLevelsFromLogic; //+0x29

	static EntitySettings* Singleton()
	{
		return *(EntitySettings**)OFFSET_ENTITYSETTINGS;
	}
};


class DxTexture
{
public:

	class TextureHeader
	{
	public:
		char _0x0000[12];
		__int32 flags; //0x000C 
		__int16 width; //0x0010 
		__int16 height; //0x0012 
		__int16 depth; //0x0014 
		__int16 sliceCount; //0x0016 
		__int16 unused0; //0x0018 
		BYTE mipmapCount; //0x001A 
		BYTE mipmapBaseIndex; //0x001B 
	};//Size=0x001C

	class TextureCreateDesc
	{
	public:
		char _0x0000[24];
		__int32 type; //0x0018 
		__int32 format; //0x001C 
		__int32 width; //0x0020 
		__int32 height; //0x0024 
		__int32 depth; //0x0028 
		__int32 mipmapCount; //0x002C 
		__int32 sampleCount; //0x0030 
		__int32 sRgb; //0x0034 
		char _0x0038[12];
		__int32 bindFlags; //0x0044 
		__int32 subResourceCount; //0x0048 
		char _0x004C[4];
		__int64 m_pDxRenderBuffer; //0x0050 DxRenderBuffer
		char _0x0058[24];
	};//Size=0x0070

	// fb::ITypedObject

	virtual __int64 GetType();

	// fb::IResourceObject

	virtual int AddRef();
	virtual int Release();

	// fb::IRenderResource

	virtual const char* GetDebugName(); // fb::IRenderResource
	virtual unsigned int GetMemorySize();
	virtual unsigned int GetMemoryFlags();
	virtual int GetUsage(); // enum RenderResourceUsage

	// fb::ITexture

	virtual int GetFormat(); // enum fb::TextureFormat
	virtual int GetTextureType();    // enum fb::TextureType
	virtual void Function9();
	virtual void Function10(); //
	virtual unsigned int GetWidth();
	virtual unsigned int GetHeight();
	virtual unsigned int GetDepth();
	virtual unsigned int GetMipmapCount();
	virtual unsigned int GetSampleCount();
	virtual void Function16();
	virtual TextureHeader* GetStreamingHeader();
	virtual void Function18();
	virtual unsigned short GetHandle();
	virtual void SetHandle(unsigned short);

	char _0x0000[8];
	TextureCreateDesc m_desc; //0x0010 
	__int32 m_handle; //0x0080 
	__int32 m_bindFlags; //0x0084 
	__int32 m_resourceFormat; //0x0088 
	__int32 m_shaderFormat; //0x008C 
	TextureHeader* m_pStreamingHeader; //0x0090
	ID3D11Resource* m_pResource; //0x0098
	char _0x00A0[8];
	ID3D11Texture2D* m_pTexture2d; //0x00A8
	ID3D11Texture3D* m_pTexture3d; //0x00B0
	__int32 m_ownsResource; //0x00B8 
	char _0x00BC[4];
};


//OFFSET PRINCIPALE
class VisualTerrainSettings : public DataContainer
{
public:
	QualityLevel m_MeshScatteringQualityLevel; //+0x10
	TerrainRenderMode m_RenderMode; //+0x14		
	float m_TriangleSizeMin; //+0x18
	float m_LodScale; //+0x1C
	float m_LodCenterExtrapolationDistanceMax; //+0x20
	float m_LodCenterExtrapolationTime; //+0x24
	float m_TextureSkipMipSpeed; //+0x28
	float m_DxTessellatedTriWidth; //+0x2C
	float m_DxTessellationPatchShrink; //+0x30
	unsigned int m_DxTessellationPatchFacesPerSide; //+0x34
	unsigned int m_TextureAtlasSampleCountXFactor; //+0x38
	unsigned int m_TextureAtlasSampleCountYFactor; //+0x3C
	float m_TextureSamplesPerMeterMax; //+0x40
	float m_TextureDetailFalloffFactor; //+0x44
	float m_TextureDetailFalloffDistance; //+0x48
	float m_TextureDetailFalloffCurve; //+0x4C
	float m_TextureInvisibleDetailReductionFactor; //+0x50
	float m_TextureOccludedDetailReductionFactor; //+0x54
	unsigned int m_TextureRenderJobCount; //+0x58
	unsigned int m_TextureRenderJobsLaunchedPerFrameCountMax; //+0x5C
	unsigned int m_TextureTileSamplesPerSide; //+0x60
	unsigned int m_TextureTileBorderWidth; //+0x64
	int m_TextureLevelOffset; //+0x68
	unsigned int m_TextureClodFrameCount; //+0x6C
	float m_TextureClodCutoffPriority; //+0x70
	unsigned int m_TextureStreamableTextureInstanceBufferSize; //+0x74
	unsigned int m_TextureCompressJobCount; //+0x78
	int m_TextureCompressionQuality; //+0x7C
	float m_TextureDetailSlopeBoost; //+0x80
	float m_TextureGenerationMipBias; //+0x84
	float m_TextureDirtyRetryRate; //+0x88
	int m_TextureForceDrawPass; //+0x8C
	unsigned int m_TextureQuadsPerTileLevel; //+0x90
	float m_DecalZPassDrawDistance; //+0x94
	float m_DecalOffsetY; //+0x98
	float m_Decal3dFarDrawDistanceScaleFactor; //+0x9C
	int m_DrawQuadtreeZoomIndex; //+0xA0
	float m_PatchErrorFov; //+0xA4
	float m_ZPassDistance; //+0xA8
	float m_DebugOverlayGridSize; //+0xAC
	float m_DebugOverlayIsolineSpacing; //+0xB0
	unsigned int m_SlotReuseWaitCount; //+0xB4
	unsigned int m_BuildJobCount; //+0xB8
	float m_DynamicMaskDecalWidthScale; //+0xBC
	unsigned int m_MaxNonVisibleTextureUpdateCount; //+0xC0
	unsigned int m_PatchFacesPerSide; //+0xC4
	unsigned int m_TessellationFacesPerSideMin; //+0xC8
	unsigned int m_PatchSlotCount; //+0xCC
	unsigned int m_OccluderJobCount; //+0xD0
	unsigned int m_OccluderPatchFacesPerSide; //+0xD4
	float m_OccluderLodScale; //+0xD8
	float m_OccludedMinDistance; //+0xDC
	unsigned int m_MeshScatteringCellPoolCapacity; //+0xE0
	unsigned int m_MeshScatteringTreeNodePoolCapacity; //+0xE4
	float m_MeshScatteringInvisibleCellFovFactor; //+0xE8
	unsigned int m_MeshScatteringCullRecordCount; //+0xEC
	unsigned int m_MeshScatteringBuildChannelCount; //+0xF0
	unsigned int m_MeshScatteringBuildChannelsLaunchedPerFrameCountMax; //+0xF4
	unsigned int m_MeshScatteringClodFrameCount; //+0xF8
	float m_MeshScatteringWindSpeed; //+0xFC
	unsigned int m_MeshScatteringInstancesPerCellMax; //+0x100
	float m_MeshScatteringDensityMarginFactor; //+0x104
	float m_MeshScatteringPregenerationDistanceRatio; //+0x108
	float m_MeshScatteringKeepDistanceRatio; //+0x10C
	int m_MeshScatteringVirtualTextureBlurriness; //+0x110
	float m_MeshScatteringDistanceScaleFactor; //+0x114
	unsigned int m_MeshScatteringInstanceCullJobCount; //+0x118
	unsigned int m_MeshScatteringInstanceCullListCount; //+0x11C
	float m_MeshScatteringSnappingGridMultiplierVertical; //+0x120
	float m_MeshScatteringSnappingGridMultiplierHorizontal; //+0x124
	bool m_WireframeEnable; //+0x128
	bool m_Enable; //+0x129
	bool m_EditServiceEnable; //+0x12A
	bool m_DxDisplacementMappingEnable; //+0x12B
	bool m_DxDensityMapEnable; //+0x12C
	bool m_VertexBufferHeightsEnable; //+0x12D
	bool m_DrawVertexYTextureEnable; //+0x12E
	bool m_TextureVtIndirectionJobEnable; //+0x12F
	bool m_TextureVtIndirectionSpuJobEnable; //+0x130
	bool m_TextureStreamingPrioritizationJobEnable; //+0x131
	bool m_TextureStreamingPrioritizationSpuJobEnable; //+0x132
	bool m_TextureClodEnable; //+0x133
	bool m_TextureForceUpdateEnable; //+0x134
	bool m_TextureCompressFastAlgorithmEnable; //+0x135
	bool m_TextureCompressSpuJobsEnable; //+0x136
	bool m_DrawTextureDebugColors; //+0x137
	bool m_TextureDrawTerrainLayersEnable; //+0x138
	bool m_TextureKeepPoolFullEnable; //+0x139
	bool m_TextureLayerCullingEnable; //+0x13A
	bool m_GpuTextureCompressionEnable; //+0x13B
	bool m_TextureStreamingPrioritizationEnable; //+0x13C
	bool m_DetailTextureStreamingPrioritizationEnable; //+0x13D
	bool m_MeshScatteringMeshStreamingPrioritizationEnable; //+0x13E
	bool m_PrioritizationSpuJobEnable; //+0x13F
	bool m_PrioritizationOcclusionEnable; //+0x140
	bool m_DrawEnable; //+0x141
	bool m_DrawPatchesEnable; //+0x142
	bool m_DetailOverlayEnable; //+0x143
	bool m_DecalEnable; //+0x144
	bool m_ForceDecalReducedQuality; //+0x145
	bool m_DrawDecal2dEnable; //+0x146
	bool m_DrawDecal3dEnable; //+0x147
	bool m_DrawDecalZPassEnable; //+0x148
	bool m_DrawOnlyDecalZPassEnable; //+0x149
	bool m_DrawPatchBoxesEnable; //+0x14A
	bool m_DrawBadPatchesEnable; //+0x14B
	bool m_DrawTextureTileBoxesEnable; //+0x14C
	bool m_DrawDebugTextEnable; //+0x14D
	bool m_DrawDebugTexturesEnable; //+0x14E
	bool m_DrawQuadtreesEnable; //+0x14F
	bool m_DrawQuadtreeStatsEnable; //+0x150
	bool m_DrawQuadtreeAtlasTexturesEnable; //+0x151
	bool m_DrawDestructionMask; //+0x152
	bool m_DrawWaterEnable; //+0x153
	bool m_PatchErrorFovEnable; //+0x154
	bool m_DebugOverlayGridEnable; //+0x155
	bool m_DebugOverlayIsolinesEnable; //+0x156
	bool m_DebugOverlayWireframeEnable; //+0x157
	bool m_DebugOverlaySketchTextureEnable; //+0x158
	bool m_DebugOverlayBrushEnable; //+0x159
	bool m_ForceGraphicsDriverCrash; //+0x15A
	bool m_ForcePatchRebuildEnable; //+0x15B
	bool m_DestroyAll; //+0x15C
	bool m_SlotDebugOutputEnable; //+0x15D
	bool m_UpdateJobsEnable; //+0x15E
	bool m_CullSpuJobEnable; //+0x15F
	bool m_PrepareBuildSpuJobEnable; //+0x160
	bool m_BuildSpuJobEnable; //+0x161
	bool m_RegenerateTexturesEnable; //+0x162
	bool m_DynamicMaskEnable; //+0x163
	bool m_PatchLodTransitionsEnable; //+0x164
	bool m_PatchMaterialSortingEnable; //+0x165
	bool m_CullSampleBoundingBoxHeightEnable; //+0x166
	bool m_CastShadowsEnable; //+0x167
	bool m_CastPlanarReflectionEnable; //+0x168
	bool m_CastEnvmapReflectionEnable; //+0x169
	bool m_CastDecal3dPlanarReflectionEnable; //+0x16A
	bool m_CastDecal3dEnvmapReflectionEnable; //+0x16B
	bool m_GlobalColormapEnable; //+0x16C
	bool m_OccluderEnable; //+0x16D
	bool m_OccluderJobEnable; //+0x16E
	bool m_OccluderSpuJobEnable; //+0x16F
	bool m_OccludedEnable; //+0x170
	bool m_MeshScatteringEnable; //+0x171
	bool m_MeshScatteringJobsEnable; //+0x172
	bool m_MeshScatteringCastShadowsEnable; //+0x173
	bool m_DrawMeshScatteringEnable; //+0x174
	bool m_DrawMeshScatteringCellBoxesEnable; //+0x175
	bool m_DrawMeshScatteringBatchBoxesEnable; //+0x176
	bool m_DrawMeshScatteringNodeBoxesEnable; //+0x177
	bool m_DrawMeshScatteringCulledCellBoxesEnable; //+0x178
	bool m_DrawMeshScatteringDebugMaskScaleTexturesEnable; //+0x179
	bool m_DrawMeshScatteringStatsEnable; //+0x17A
	bool m_DrawMeshScatteringQuadtreeEnable; //+0x17B
	bool m_MeshScatteringForceUpdateEnable; //+0x17C
	bool m_MeshScatteringBuildVisibleFirst; //+0x17D
	bool m_MeshScatteringCullSpuJobEnable; //+0x17E
	bool m_MeshScatteringMergeInstanceLists; //+0x17F
	bool m_MeshScatteringInstanceCullSpuJobEnable; //+0x180
	bool m_MeshScatteringPrioritizationSpuJobEnable; //+0x181
	bool m_MeshScatteringSpuJobEnable; //+0x182
	bool m_MeshScatteringInstanceCullBoxTestEnable; //+0x183
	bool m_MeshScatteringInstanceNewCodeEnable; //+0x184
	bool m_MeshScatteringInstanceFrustumCullEnable; //+0x185
	bool m_MeshScatteringInstanceOcclusionCullEnable; //+0x186
	bool m_MeshScatteringInstanceAdditionalCullEnable; //+0x187
	bool m_DrawMeshScatteringInstanceBoxesEnable; //+0x188
	bool m_MeshScatteringInstanceCullDynamicAllocEnable; //+0x189
	bool m_Ps3MeshScatteringInstanceCellMemoryEnable; //+0x18A
	bool m_MeshScatteringWindEnable; //+0x18B

	static VisualTerrainSettings* Singleton()
	{
		return *(VisualTerrainSettings**)OFFSET_VISUALTERRAINDATA;
	}
};


//OFFSET PRINCIPALE SUB
class InputConfigurationAsset
{
public:

	class EntryInputActionMapsData
	{
	public:
		char aAsset[24]; //+0x00 Inherited
		int m_ActionMapSettingsScheme; //+0x18
		int m_DefaultInputActionMap; //+0x1C
		int m_InputActionMaps; //+0x20
	};

	char aAsset[24]; //+0x00 Inherited
	EntryInputActionMapsData* m_DefaultInputConceptDefinition; //+0x18
	EntryInputActionMapsData* m_DefaultExclusiveInputConcepts; //+0x20
	__int64 m_EntryInputActionBindings; //+0x28
	__int64 m_UserConfigurableActionMaps; //+0x30
	int m_TogglePoseAction; //+0x38
	int m_CrouchAction; //+0x3C
	int m_CrouchAndHoldAction; //+0x40
	int m_PickupInteractionAction; //+0x44
	int m_PickupInteractionActionKeyboard; //+0x48
	float m_SprintReleaseTime; //+0x4C
	float m_ThrottleInputRequiredForSprint; //+0x50
	float m_VehicleBoostIsToggleMinInput; //+0x54
	float m_EnterVehicleHoldTime; //+0x58
	bool m_FiringDisablingTransitions; //+0x60
	bool m_ProneToStandOnJump; //+0x68
	bool m_StandAutomaticallyIfSprinting; //+0x69
	bool m_DisableCrouch; //+0x6A
	bool m_DisableProne; //+0x6B
	bool m_DisableCrawlingWhileFiring; //+0x6C
	bool m_DisableCrawlingWhileReloading; //+0x6D
	bool m_DisableFiringWhileDeployingBipod; //+0x6E
	bool m_DisableFiringWhileJumping; //+0x6F
	bool m_DisableSprintingWhileReloading; //+0x70
	bool m_EnableSprintToCrouchTransition; //+0x71
	bool m_StopSprintingWhenReleasingThrottle; //+0x72
	bool m_StopSprintingWhenReleasingSprint; //+0x73
	bool m_WaitForSprintReleaseBeforeSprintAgain; //+0x74
	bool m_VehicleBoostIsToggle; //+0x75
	bool m_InputCurvesEnabled; //+0x76

	static InputConfigurationAsset* Singleton()
	{
		return *(InputConfigurationAsset**)OFFSET_INPUTCONFIGASSET;
	}
};

class DecalSettings : public SystemSettings
{
public:
	char* m_Name; //+0x10
	GamePlatform m_Platform; //+0x18
	unsigned int m_DecalImpactLifetimeMs; //+0x20
	unsigned int m_DecalImpactPoolSize; //+0x24
	unsigned int m_StaticBufferMaxVertexCount; //+0x28
	unsigned int m_RingBufferMaxVertexCount; //+0x2c
	bool m_Enable; //+0x30
	bool m_DrawEnable; //+0x31
	bool m_SystemEnable; //+0x32
	bool m_SystemEnable2; //+0x33
	bool m_DrawDecalReflectionOnBreakableModelEnable; //+0x34
	bool m_DebugMemUsageEnable; //+0x35
	bool m_DebugWarningsEnable; //+0x36
	bool m_NvidiaStreamOutputWorkaroundEnable; //+0x37

	static DecalSettings* Singleton()
	{
		return *(DecalSettings**)0x14242F6A8;
	}
};


//OFFSET PRINCIPALE SUB
class TextureSettings : public DataContainer
{
public:
	unsigned int m_SkipMipmapCount; //+0x10
	bool m_LoadingEnabled; //+0x14
	bool m_RenderTexturesEnabled; //+0x15

	static TextureSettings* Singleton()
	{
		return *(TextureSettings**)OFFSET_TEXTURESETTINGS;
	}
};


//OFFSET PRINCIPALE SUB
class WindowSettings
{
public:
	char inheritedSystemSettings[0x10]; //+0x00
	char* m_Name; //+0x10
	GamePlatform m_Platform; //+0x18
	__int32 m_PosX; //+0x20
	__int32 m_PosY; //+0x24
	unsigned __int32 m_Width; //+0x28
	unsigned __int32 m_Height; //+0x2c
	bool m_AutoSize; //+0x30
	bool m_FullscreenAutoSize; //+0x31
	bool m_EnableEscape; //+0x32
	bool m_EnableInputOnActivate; //+0x33
	bool m_HibernateOnClose; //+0x34
	bool m_Hidden; //+0x35
	bool m_Minimized; //+0x36

	static WindowSettings* Singleton()
	{
		return *(WindowSettings**)OFFSET_WINDOWSETTINGS;
	}
};

class UISettings : public SystemSettings
{
public:
	class UIBundlesAsset
	{
	public:
		char aAsset[24]; //+0x00 Inherited
		void* m_UIBundleAssetStateList; //+0x18 Asset
		void* m_FontCollectionLookups; //+0x20
		char* m_RootMovieClipPath; //+0x28
	};

	class ProfileOptionsAsset
	{
	public:
		char aAsset[24]; //+0x00 Inherited
		char* m_FileName; //+0x18
		char* m_ContentName; //+0x20
		unsigned int m_FileSize; //+0x28
		bool m_Options; //+0x30
		bool m_OptionsPs3; //+0x38
		bool m_OptionsXenon; //+0x40
		bool m_OptionsGen4a; //+0x48
		bool m_OptionsGen4b; //+0x50
		bool m_OptionsWin; //+0x58
		bool m_AutoSaveOnQuit; //+0x60
	};

	char* m_Name; //+0x10
	GamePlatform m_Platform; //+0x18
	UISystemType m_System; //+0x20
	UIBundlesAsset m_Bundles; //+0x28
	ProfileOptionsAsset* m_ProfileOptions; //+0x30
	LanguageFormat m_Language; //+0x38
	bool m_OneBundlePerGraph; //+0x3c
	bool m_DrawEnable; //+0x3d
};
class ExplosiveEntity
{
public:
	virtual TypeInfo* GetType(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void GetTransform(Matrix* mTransform);
};

class CObjectEntry
{
public:
	__int64 func1; //0x0000  
	__int64 func2; //0x0008  
	__int64 func3; //0x0010  
	__int64 func4; //0x0018  
	BYTE m_EntityType; //0x0020 is sometimes 1 or 3 and 0 if no valid shit 
	char N3F2B6DC1[7]; //0x0021  
	Vec3 m_position; //0x0028  
	Vec3 m_vec; //0x0038   
	GameObject* m_pEntity; //0x0048 
};//Size=0x0050

class GameObject
{
public:
	ClientPlayer* LocalPlayer; //0x0000 valid for vehicle invalid for explosive
	void* Ptr1;                   //0x08 char*: reads explosive or gadgets.explosives for explosive entity || pickups.medbag or pickups.ammobag for other 
	ClientPlayer* PlayerInVehicle; //0x0010 valid for vehicle if occupied not if empty
	void* Ptr2;                        //0x0018 valid for explosive, this is the actual explosive ptr      
	ClientVehicleEntity* pClientVehicle; //0x0020 vehicle ptr
	void* Ptr3; //0x0028 
	char _0x0030[16];
	char* m_name1; //0x0040 
	char _0x0048[40];
	char* m_name2; //0x0070 // name for vehicle, just a valid ptr for explosive no char*
};//Size=0x0078


//OFFSET PRINCIPALE
class CObjectList
{
public:
	char _0x0000[0x8];
	CObjectEntry m_Collection[1000]; //0x0058  
	char N3F1631D5[40]; //0x13888  
	__int32 size; //0x138B0  
	char _0x138B4[196];//

	int Size()
	{
		return size;
	}

	GameObject* GetGameObject(int ID)
	{
		if (ID >= 0 && ID <= Size())
			return m_Collection[ID].m_pEntity;
		return NULL;
	}
	static CObjectList* GetInstance()
	{
		return (CObjectList*)(OFFSET_ENTITYSIZE - 0x138B0);
	}
};//Size=0x0E60



class ExplosionEntityData :public SpatialEntityData
{
public:
	void* m_DetonationEffect; //+0x60 EffectBlueprint
	void* m_DetonationEffectForFriendlies; //+0x68 EffectBlueprint
	void* m_MaskVolume; //+0x70 MaskVolumeEntityData
	void* m_DestructionMaskVolume; //+0x78 DestructionMaskVolumeEntityData
	MaterialDecl m_MaterialPair; //+0x80
	MaterialDecl m_SecondaryMaterialPair; //+0x84
	DamageIndicationType m_DamageIndicationType; //+0x88
	float m_EmpTime; //+0x8C
	float m_MaxOcclusionRaycastRadius; //+0x90
	float m_InnerBlastRadius; //+0x94
	float m_BlastDamage; //+0x98
	float m_BlastRadius; //+0x9C
	float m_BlastImpulse; //+0xA0
	float m_ShockwaveDamage; //+0xA4
	float m_ShockwaveRadius; //+0xA8
	float m_ShockwaveImpulse; //+0xAC
	float m_ShockwaveTime; //+0xB0
	float m_CameraShockwaveRadius; //+0xB4
	float m_SpawnDelay; //+0xB8
	bool m_NoFriendliesEffectOnEnabledFriendlyFire; //+0xBC
	bool m_UseEntityTransformForDetonationEffect; //+0xBD
	bool m_SecondaryMaterialsActive; //+0xBE
	bool m_HasStunEffect; //+0xBF
	bool m_DisableOcclusion; //+0xC0
	bool m_DisableStaticEntityOcclusion; //+0xC1
	bool m_TriggerImpairedHearing; //+0xC2
	bool m_Enabled; //+0xC3
};

////////////////////////////////////////
// ClassId:   00298
// RuntimeId: 05283
// TypeInfo:  0x00000001427C56A0



class MissileEntityData
{
public:
	class MissileUnguidedData
	{
	public:
		Vec2 m_StaticPosition; //+0x0
		Vec2 m_TargetPositionOffset; //+0x8
		bool m_UseStaticPosition; //+0x10
		bool m_UseTargetPosition; //+0x11
	};

	class MissileLockableInfoData
	{
	public:
		float m_HeatSignature; //+0x0
		float m_RadarSignature; //+0x4
	};

	class NearTargetDetonationData
	{
	public:
		float m_DetonationRadius; //+0x0
		float m_MaxDetonationDelay; //+0x4
		float m_MinDetonationDelay; //+0x8
		bool m_DetonateNearTarget; //+0xC
	};

	char aGhostedProjectileEntityData[304]; //+0x00 Inherited
	void* m_EngineEffect; //+0x130 EffectBlueprint
	ExplosionEntityData* m_DudExplosion; //+0x138 ExplosionEntityData
	SoundAsset* m_FlyBySound; //+0x140
	float m_EngineStrength; //+0x148
	float m_MaxSpeed; //+0x14C
	float m_EngineTimeToIgnition; //+0x150
	float m_EngineTimeToLive; //+0x154
	float m_TimeToActivateGuidingSystem; //+0x158
	float m_TimeToArm; //+0x15C
	float m_MaxTurnAngle; //+0x160
	float m_MinTurnAngle; //+0x164
	float m_TurnAngleMultiplier; //+0x168
	float m_Drag; //+0x16C
	float m_Gravity; //+0x170
	float m_FlyBySoundRadius; //+0x174
	float m_FlyBySoundSpeed; //+0x178
	float m_ImpactImpulse; //+0x17C
	float m_Damage; //+0x180
	TeamId m_DefaultTeam; //+0x184
	WarnTarget m_WarnTarget; //+0x188
	LockingControllerData* m_LockingController; //+0x190
	MissileLockableInfoData m_LockableInfo; //+0x198 could be ptr
	MissileUnguidedData m_UnguidedData; //+0x1A0
	NearTargetDetonationData m_NearTargetDetonation; //+0x1B4
	float m_MaxBankAngle; //+0x1C4
	float m_BankingSpeed; //+0x1C8
	char* m_Icon; //+0x1D0
	char* m_TargetIcon; //+0x1D8
	char* m_TargetIconEnemy; //+0x1E0
	float m_MinGhostFrequency; //+0x1E8
	bool m_ApplyGravityWhenGuided; //+0x1EC
	bool m_WarnOnPointingMissile; //+0x1ED
	bool m_EnableBanking; //+0x1EE
};


//OFFSET PRINCIPALE
class SyncedBFSettings
{
public:

	class SystemSettings : public DataContainer
	{
	public:

		enum GamePlatform
		{
			GamePlatform_Ps3 = 0,
			GamePlatform_Win32 = 1,
			GamePlatform_Xenon = 2,
			GamePlatform_Gen4a = 3,
			GamePlatform_Gen4b = 4,
			GamePlatform_Any = 5,
			GamePlatform_Invalid = 6,
			GamePlatformCount = 7
		};
		char* m_Name; //0x0010 char*
		GamePlatform m_Platform; //0x0018 
		char pad_0x001C[4];
	}; //Size=0x0020

	enum ServerTypeValues
	{
		ServerType_OFFICIAL = 0,
		ServerType_RANKED = 1,
		ServerType_UNRANKED = 2,
		ServerType_PRIVATE = 3
	};

	SystemSettings m_Settings; //0x0000
	float m_GameModeCounterModifier; //0x0020 
	float m_RoundTimeLimit; //0x0024 
	__int64 m_JesusModeForPlayerTag; //0x0028 char* 0x00 
	__int32 m_Team1Faction; //0x0030 
	__int32 m_Team2Faction; //0x0034 
	__int32 m_Team3Faction; //0x0038 
	__int32 m_Team4Faction; //0x003C 
	__int64 m_CommanderSize; //0x0040 alignment to 8 
	char* m_FieldSpecLevels; //0x0048 char*
	ServerTypeValues m_ServerType; //0x0050 
	BYTE m_AllUnlocksUnlocked; //0x0054 
	BYTE m_NoMinimap; //0x0055 
	BYTE m_NoHud; //0x0056 
	BYTE m_NoMinimapSpotting; //0x0057 
	BYTE m_No3dSpotting; //0x0058 
	BYTE m_NoNameTag; //0x0059 
	BYTE m_OnlySquadLeaderSpawn; //0x005A 
	BYTE m_TeamSwitchingAllowed; //0x005B 
	BYTE m_RevertBackToBF3KillerCamera; //0x005C 
	BYTE m_DisableHitIndicators; //0x005D 
	BYTE m_DisableVehicleCommanderActions; //0x005E 
	BYTE m_CommanderEnabled; //0x005F 
	BYTE m_FieldUpgradeSystemActive; //0x0060 

	static SyncedBFSettings* GetInstance()
	{
		return *(SyncedBFSettings**)(OFFSET_SYNCEDSETTINGS);
	}
};


//OFFSET PRINCIPALE
class AntSettings :public DataContainer
{
public:
	float m_ForceLodDistance; //0x0010 
	__int32 m_MaxAnimatablesPerPoseJob; //0x0014 
	float m_ReducedInterpolationDistance; //0x0018 
	float m_TrajectoryInterpolationDistance; //0x001C 
	__int32 m_MaxInterpolationSlots; //0x0020 
	__int32 m_MaxSingleBoneInterpolationSlots; //0x0024 
	float m_CheckGiantSoldiers; //0x0028 
	float m_LeanSignalScale; //0x002C 
	float m_LeanSignalClamp; //0x0030 
	float m_DetailedCollisionSpeedLimit; //0x0034 
	float m_MaxInterpolationDistance; //0x0038 
	__int32 m_MaxInterpolationTicks; //0x003C 
	__int32 m_AutoCullPixelSize; //0x0040 
	__int8 m_UsePA; //0x0044 
	__int8 m_UseHIK; //0x0045 
	__int8 m_BlockOnJobs; //0x0046 
	__int8 m_InterpolatePoses; //0x0047 
	__int8 m_AllowVariableTickLength; //0x0048 
	__int8 m_UseWeaponFov; //0x0049 
	__int8 m_ForcePoseUpdate; //0x004A 
	__int8 m_UseCameraFov; //0x004B 
	__int8 m_EnablePA; //0x004C 
	__int8 m_ClientEmulatesServer; //0x004D 
	__int8 m_UpdateEnable; //0x004E 
	__int8 m_EnablePackageCache; //0x004F 
	__int8 m_EnableDebugLogFile; //0x0050 
	__int8 m_EnablePoseJobs; //0x0051 
	__int8 m_DisableAILodFeature; //0x0052 
	__int8 m_DisableModelAnimationCulling; //0x0053 
	__int8 m_EnableJobs; //0x0054 
	__int8 m_RunAsHighPriority; //0x0055 
	__int8 m_UpdateLoddingEnable; //0x0056 
	static AntSettings* GetInstance()
	{
		return *(AntSettings**)(OFFSET_AntSettings);
	}
};//Size=0x0057


//OFFSET PRINCIPALE SUB
class ServerMetricsSettings :public DataContainer
{
public:
	CString m_ReportName; //+0x10
	CString m_LogSettingsPrefix; //+0x18
	bool m_Enabled; //+0x20
	bool m_DbxReportEnabled; //+0x21
	bool m_TickTelemetryEnabled; //+0x22
	bool m_DevelopmentTelemetryEnabled; //+0x23
	bool m_PerformanceTelemetryEnabled; //+0x24
	bool m_JuiceTelemetryEnabled; //+0x25
	bool m_PerformanceProfileStateEnabled; //+0x26
	bool m_TransactionTelemetryEnabled; //+0x27
	bool m_CompressTransactions; //+0x28
	static ServerMetricsSettings* GetInstance()
	{
		return *(ServerMetricsSettings**)(OFFSET_ServerMetricsSettings);
	}
};


//OFFSET PRINCIPALE
class ScreenshotModule
{
public:
	__int64 MemoryArena_m_arena; //0x0000         
	bool m_autoRenderEnable; //0x0008 
	char pad_0x09[0x3]; //0x0009 
	__int32 m_delayFrame; //0x000C 
	__int32 m_resolutionFrameIndex; //0x0010 
	__int32 m_antialiasFrameIndex; //0x0014 
	__int32 m_lineCount; //0x0018 
	char pad_0x1C[0x4]; //0x001C 
	char* m_tempPath; //0x0020 
	char* m_outputPath; //0x0028 
	__int64 SmartRef_m_fileSystem; //0x0030 
	__int64 SmartPtr_m_averageData; //0x0038 
	__int32 m_counter; //0x0040 
	__int32 m_degreeCount; //0x0044 
	__int32 m_framesSinceLastScreen; //0x0048 
	DWORD m_source; //0x004C 
	DWORD m_explicitFilename; //0x0050 
	char pad_0x54[0x5C]; //0x0054
	void* m_changesWithScreen; //0x00B0 
	char pad_0xB8[0xC]; //0x00B8  
	__int32 ScreenshotFormat_m_format; //0x00C4 
	__int32 m_alphaEnable; //0x00C8 
	__int32 m_orthoEnable; //0x00CC 
	__int32 m_width; //0x00D0 
	__int32 m_height; //0x00D4
	char pad_0xD8[0x10]; //0x00D8

	static ScreenshotModule* Singleton()
	{
		return *(ScreenshotModule**)SSMODULE;
	}
};


class Screen
{
public:
	BYTE pad00[0x58];				//0x00
	unsigned int m_Width;			//0x58
	unsigned int m_Height;			//0x5C
	unsigned int m_WindowWidth;			//0x60
	unsigned int m_WindowHeight;		//0x64
	BYTE pad01[0x88];				//0x68
	IDXGISwapChain* m_pSwapChain;		//0xF0
};


//POINTER PRINCIPALE
class DxRenderer
{
public:
	BYTE pad00[0x38];                    // 0x00
	Screen* m_pScreen;                    // 0x38
	BYTE pad40[0xC0];                    // 0x40
	ID3D11Device* m_pDevice;            // 0x100
	ID3D11DeviceContext* m_pContext;    // 0x108
	char _0x0110[192];
	__int64 DxDisplaySettings_m_settings; //0x01D0 
public:
	static DxRenderer* GetInstance()
	{
		return *(DxRenderer**)(OFFSET_DXRENDERER);
	}
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////
// RuntimeId: 09668
// TypeInfo:  0x00000001427F8B98
class GunSwayDispersionModData
{
public:
	float m_MinAngleModifier; //0x0000
	float m_MaxAngleModifier; //0x0004
	float m_IncreasePerShotModifier; //0x0008
	float m_DecreasePerSecondModifier; //0x000C
};//Size=0x0010


////////////////////////////////////////
// RuntimeId: 09688
// TypeInfo:  0x00000001427F8A98
class GunSwayStanceZoomModifierData
{
public:
	GunSwayDispersionModData m_DispersionMod; //0x0000
	GunSwayDispersionModData m_MovingDispersionMod; //0x0010
	GunSwayDispersionModData m_SprintingDispersionMod; //0x0020
	float m_RecoilMagnitudeMod; //0x0030
	float m_RecoilAngleMod; //0x0034
	float m_FirstShotRecoilMod; //0x0038
	float m_LagYawMod; //0x003C
	float m_LagPitchMod; //0x0040
};//Size=0x0044

////////////////////////////////////////
// ClassId:   01857
// RuntimeId: 09690
// TypeInfo:  0x00000001427F8DC0
#ifndef _GunSwayModifierData_
#define _GunSwayModifierData_
#pragma pack(push, 8)
class GunSwayModifierData : public Asset
{
public:
	static __inline GunSwayModifierData* DefaultInstance()
	{
		return (GunSwayModifierData*)0x000000004638B190;
	}
	static __inline unsigned int ClassId()
	{
		return 1857;
	}
	GunSwayStanceZoomModifierData m_StandZoomModifier; //0x0018
	GunSwayStanceZoomModifierData m_StandNoZoomModifier; //0x005C
	GunSwayStanceZoomModifierData m_CrouchZoomModifier; //0x00A0
	GunSwayStanceZoomModifierData m_CrouchNoZoomModifier; //0x00E4
	GunSwayStanceZoomModifierData m_ProneZoomModifier; //0x0128
	GunSwayStanceZoomModifierData m_ProneNoZoomModifier; //0x016C
	bool m_OnlyInSupportedShooting; //0x01B0
	bool m_OnlyOnWeaponLightEnabled; //0x01B1
	char _0x01B2[6];
};//Size=0x01B8
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 09692
// TypeInfo:  0x00000001427F8BF8
class GunSwayModifierUnlock
{
public:
	Guid m_UnlockAssetGuid; //0x0000
	char _0x0000[16];
	GunSwayModifierData* m_Modifier; //0x0010
};//Size=0x0018



////////////////////////////////////////
// RuntimeId: 09666
// TypeInfo:  0x00000001427F8BB8
class GunSwayDispersionData
{
public:
	float m_MinAngle; //0x0000
	float m_MaxAngle; //0x0004
	float m_IncreasePerShot; //0x0008
	float m_DecreasePerSecond; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09674
// TypeInfo:  0x00000001427F8B58
class GunSwayRecoilData
{
public:
	float m_RecoilAmplitudeMax; //0x0000
	float m_RecoilAmplitudeIncPerShot; //0x0004
	float m_HorizontalRecoilAmplitudeIncPerShotMin; //0x0008
	float m_HorizontalRecoilAmplitudeIncPerShotMax; //0x000C
	float m_HorizontalRecoilAmplitudeMax; //0x0010
	float m_RecoilAmplitudeDecreaseFactor; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09670
// TypeInfo:  0x00000001427F8B78
class GunSwayLagData
{
public:
	float m_MoveStrafeModifier; //0x0000
	float m_MoveForwardModifier; //0x0004
	float m_RotateYawModifier; //0x0008
	float m_RotatePitchModifier; //0x000C
	float m_ReleaseModifier; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09680
// TypeInfo:  0x00000001427F8B18
class GunSwayBaseMoveData
{
public:
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayDispersionData m_Moving; //0x0010
	GunSwayRecoilData m_Recoil; //0x0020
	GunSwayLagData m_GunSwayLag; //0x0038
};//Size=0x004C

////////////////////////////////////////
// RuntimeId: 09678
// TypeInfo:  0x00000001427F8C18
class GunSwayBaseData
{
public:
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayRecoilData m_Recoil; //0x0010
	GunSwayLagData m_GunSwayLag; //0x0028
};//Size=0x003C

////////////////////////////////////////
// RuntimeId: 09676
// TypeInfo:  0x00000001427F8B38
class GunSwayStanceTransition
{
public:
	GunSwayDispersionData m_MaxPenaltyValue; //0x0000
	float m_CoolDown; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09682
// TypeInfo:  0x00000001427F8AF8
class GunSwayBaseMoveJumpData
{
public:
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayDispersionData m_Moving; //0x0010
	GunSwayDispersionData m_Jumping; //0x0020
	GunSwayDispersionData m_Sprinting; //0x0030
	GunSwayDispersionData m_VaultingSmallObject; //0x0040
	GunSwayDispersionData m_VaultingMediumObject; //0x0050
	GunSwayRecoilData m_Recoil; //0x0060
	GunSwayLagData m_GunSwayLag; //0x0078
};//Size=0x008C

////////////////////////////////////////
// RuntimeId: 09684
// TypeInfo:  0x00000001427F8AD8
class GunSwayStandData
{
public:
	GunSwayBaseMoveJumpData m_NoZoom; //0x0000
	GunSwayBaseMoveJumpData m_Zoom; //0x008C
};//Size=0x0118



////////////////////////////////////////
// RuntimeId: 09686
// TypeInfo:  0x00000001427F8AB8
class GunSwayCrouchProneData
{
public:
	GunSwayBaseMoveData m_NoZoom; //0x0000
	GunSwayBaseMoveData m_Zoom; //0x004C
};//Size=0x0098


////////////////////////////////////////
// ClassId:   03451
// RuntimeId: 07667
// TypeInfo:  0x00000001427CBCD0
#ifndef _WeaponSwayData_
#define _WeaponSwayData_
#pragma pack(push, 8)
class WeaponSwayData : public DataContainer
{
public:
	static __inline WeaponSwayData* DefaultInstance()
	{
		return (WeaponSwayData*)0x00000000463BF790;
	}
	static __inline unsigned int ClassId()
	{
		return 3451;
	}
};//Size=0x0010
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03251
// RuntimeId: 09672
// TypeInfo:  0x00000001427F8E20
#ifndef _CameraRecoilData_
#define _CameraRecoilData_
#pragma pack(push, 8)
class CameraRecoilData : public DataContainer
{
public:
	static __inline CameraRecoilData* DefaultInstance()
	{
		return (CameraRecoilData*)0x00000000463BB290;
	}
	static __inline unsigned int ClassId()
	{
		return 3251;
	}
	float m_SpringConstant; //0x0010
	float m_SpringDamping; //0x0014
	float m_SpringMinThresholdAngle; //0x0018
	char _0x001C[4];
};//Size=0x0020
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03452
// RuntimeId: 09694
// TypeInfo:  0x00000001427F8D60
#ifndef _GunSwayData_
#define _GunSwayData_
#pragma pack(push, 8)
class GunSwayData : public WeaponSwayData
{
public:
	static __inline GunSwayData* DefaultInstance()
	{
		return (GunSwayData*)0x00000000463BF7C0;
	}
	static __inline unsigned int ClassId()
	{
		return 3452;
	}
	GunSwayStandData m_Stand; //0x0010
	GunSwayCrouchProneData m_Crouch; //0x0128
	GunSwayCrouchProneData m_Prone; //0x01C0
	GunSwayStanceTransition m_ProneToCrouch; //0x0258
	GunSwayStanceTransition m_ProneToStand; //0x026C
	GunSwayStanceTransition m_CrouchToProne; //0x0280
	GunSwayStanceTransition m_CrouchToStand; //0x0294
	GunSwayStanceTransition m_StandToProne; //0x02A8
	GunSwayStanceTransition m_StandToCrouch; //0x02BC
	GunSwayStanceZoomModifierData m_SuppressionModifierUnzoomed; //0x02D0
	GunSwayStanceZoomModifierData m_SuppressionModifierZoomed; //0x0314
	Array<GunSwayModifierUnlock> m_ModifierUnlocks; //0x0358
	float m_DeviationScaleFactorZoom; //0x0360
	float m_GameplayDeviationScaleFactorZoom; //0x0364
	float m_DeviationScaleFactorNoZoom; //0x0368
	float m_GameplayDeviationScaleFactorNoZoom; //0x036C
	float m_ShootingRecoilDecreaseScale; //0x0370
	float m_FirstShotRecoilMultiplier; //0x0374
	CameraRecoilData* m_CameraRecoil; //0x0378
};//Size=0x0380
#pragma pack(pop)
#endif



class ClientCapturePointEntity
{
public:
	virtual __int64 GetType();
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void GetTransform(Matrix* mTransform);

	char _0x0008[40];
	CapturePointEntityData* m_data; //0x0030
	char _0x0038[24];
	__int32 m_teamId; //0x0050
	__int32 m_attackingTeamId; //0x0054
	char _0x0058[112];
	__int32 m_Team; //0x00C8
	float N0B1345F2; //0x00CC
	char _0x00D0[44];
	float m_CapturedPercentage; //0x00FC
	float m_CaptureRate; //0x0100
	float m_Captured; //0x0104 1.0f = captured
}; //Size=0x0108

class CapturePointEntityData
{
public:
	char _0x0000[96];
	__int64 m_FlagTemplates; //0x0060
	char _0x0068[8];
	__int32 m_InitialOwnerTeam; //0x0070
	float m_CaptureRadius; //0x0074
	__int32 m_AreaValue; //0x0078
	char _0x007C[4];
	__int64 m_AreaValues; //0x0080
	__int32 m_TimeToGetControl; //0x0088
	__int32 m_TimeToLoseControl; //0x008C
	float m_ReturnMultiplier; //0x0090
	__int32 m_OnlyTakeableByTeam; //0x0094
	__int32 m_MinNrToTakeControl; //0x0098
	__int32 m_MaxCaptureMultiplier; //0x009C
	float m_AddedMultiplierPerPlayer; //0x00A0
	__int32 m_EnemyTicketLossWhenCaptured; //0x00A4
	__int32 m_SpawnMenuListOrdinal; //0x00A8
	char _0x00AC[4];
	char* m_IntruderWarningSID; //0x00B0
	__int32 m_CapturableType; //0x00B8 fb::CapturableType
	float m_ShowRadius; //0x00BC
	float m_HideRadius; //0x00C0
	__int32 m_UiType; //0x00C4 CapturePointUIType
	float m_VerticalOffset; //0x00C8
	char _0x00CC[4];
	__int64 m_IconBehaviour; //0x00D0 fb::UIWorldIconBehavior
	__int64 m_LocationNameSid; //0x00D8
	__int64 m_LocationTextSid; //0x00E0
	char _0x00E8[16];
	BYTE m_Enabled; //0x00F8
	BYTE m_IsCapturedInUpperSphere; //0x00F9
	BYTE m_UseAreaValuesPerTeam; //0x00FA
	BYTE m_IntruderWarning; //0x00FB
	BYTE m_DisableIfEnemyInside; //0x00FC
	BYTE m_DisableWhenLosingControl; //0x00FD
	BYTE m_LoseControlWhenNotClose; //0x00FE
	BYTE m_IsVisible; //0x00FF
	BYTE m_ShowOnMinimap; //0x0100
	BYTE m_DrawBaseAsForwardBase; //0x0101
	BYTE m_HoistFlag; //0x0102
	BYTE m_StartAtBottom; //0x0103
	BYTE m_RemoveWhenCaptured; //0x0104
	BYTE m_SeesawCapturing; //0x0105
	BYTE m_ForceSpawnAtVehicle; //0x0106
	BYTE m_UseMirroredVehicleLayout; //0x0107
	BYTE m_ForcedBlink; //0x0108
	BYTE m_CTFBase; //0x0109
};//Size=0x010A


////////////////////////////////////////
// RuntimeId: 08279
// TypeInfo:  0x000000014280DA78
struct PoissonRadialBlurData
{
	Float32 m_BlendFactor; //0x0000
	Vec2 m_PoissonDiscScale; //0x0004
	Float32 m_RadialScale; //0x000C
	Float32 m_RadialExponent; //0x0010
};//Size=0x0014


////////////////////////////////////////
// RuntimeId: 08277
// TypeInfo:  0x000000014280DA98
struct ColorTintData
{
	Vec3 m_Contrast; //0x0000
	Vec3 m_Brightness; //0x0010
	Vec3 m_Saturation; //0x0020
	Float32 m_Hue; //0x0030
	char _0x0034[12];
};//Size=0x0040


////////////////////////////////////////
// ClassId:   03888
// RuntimeId: 08281
// TypeInfo:  0x000000014280E140
#ifndef _ViewFxData_
#define _ViewFxData_
#pragma pack(push, 16)
class ViewFxData : public DataContainer
{
public:
	static __inline ViewFxData* DefaultInstance()
	{
		return (ViewFxData*)0x0000000068B89360;
	}
	static __inline unsigned int ClassId()
	{
		return 3888;
	}
	PoissonRadialBlurData m_PoissonRadialBlur; //0x0010
	Float32 m_BlurAdd; //0x0024
	char _0x0028[8];
	ColorTintData m_ColorTint; //0x0030
	Boolean m_PoissonRadialBlurEnable; //0x0070
	Boolean m_ColorTintEnable; //0x0071
	char _0x0072[14];
};//Size=0x0080
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03105
// RuntimeId: 06869
// TypeInfo:  0x00000001427F46C0
#ifndef _CameraData_
#define _CameraData_
#pragma pack(push, 16)
class CameraData : public GameObjectData
{
public:
	static __inline CameraData* DefaultInstance()
	{
		return (CameraData*)0x0000000068B76AA0;
	}
	static __inline unsigned int ClassId()
	{
		return 3105;
	}
	Float32 m_PreFadeTime; //0x0018
	char _0x001C[4];
	Vec3 m_OcclusionRayOffset; //0x0020
	Float32 m_FadeTime; //0x0030
	Float32 m_FadeWaitTime; //0x0034
	ViewFxData* m_ViewFx; //0x0038
	Float32 m_NearPlane; //0x0040
	Float32 m_ShadowViewDistanceScale; //0x0044
	Float32 m_SoundOcclusion; //0x0048
	Float32 m_SoundListenerRadius; //0x004C
	Float32 m_ShakeFactor; //0x0050
	Boolean m_StayFadedWhileStreaming; //0x0054
	char _0x0055[11];
};//Size=0x0060
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03108
// RuntimeId: 06873
// TypeInfo:  0x00000001427F4660
#ifndef _TargetCameraData_
#define _TargetCameraData_
#pragma pack(push, 16)
class TargetCameraData : public CameraData
{
public:
	static __inline TargetCameraData* DefaultInstance()
	{
		return (TargetCameraData*)0x0000000068B76C60;
	}
	static __inline unsigned int ClassId()
	{
		return 3108;
	}
	HudData m_Hud; //0x0060
};//Size=0x00D0
#pragma pack(pop)
#endif

////////////////////////////////////////
// RuntimeId: 06863
// TypeInfo:  0x00000001427F26A0
struct CameraSineCurveData
{
	Float32 m_Frequency; //0x0000
	Float32 m_Amplitude; //0x0004
	Float32 m_PhaseShift; //0x0008
};//Size=0x000C


////////////////////////////////////////
// RuntimeId: 00140
// TypeInfo:  0x000000014274C350
struct UavCameraPointData
{
	Float32 m_MinTime; //0x0000
	Float32 m_MaxTime; //0x0004
	Float32 m_Speed; //0x0008
	Float32 m_AccelerationTime; //0x000C
};//Size=0x0010

////////////////////////////////////////
// ClassId:   03115
// RuntimeId: 00142
// TypeInfo:  0x000000014274EAD0
#ifndef _UavCameraData_
#define _UavCameraData_
#pragma pack(push, 16)
class UavCameraData : public TargetCameraData
{
public:
	static __inline UavCameraData* DefaultInstance()
	{
		return (UavCameraData*)0x0000000068B77560;
	}
	static __inline unsigned int ClassId()
	{
		return 3115;
	}
	Float32 m_ViewDistance; //0x00D0
	char _0x00D4[4];
	Array<CameraSineCurveData> m_ViewDistanceCurve; //0x00D8
	Float32 m_ViewAngle; //0x00E0
	char _0x00E4[4];
	Array<CameraSineCurveData> m_ViewAngleCurve; //0x00E8
	Float32 m_RotationSpeed; //0x00F0
	char _0x00F4[4];
	Array<CameraSineCurveData> m_RotationSpeedCurve; //0x00F8
	Float32 m_ZoomFov; //0x0100
	Float32 m_ZoomDelay; //0x0104
	Float32 m_ZoomTransitionTime; //0x0108
	Float32 m_Fov; //0x010C
	UavCameraPointData m_FocusPoint; //0x0110
	UavCameraPointData m_CenterPoint; //0x0120
	Float32 m_UpWeightDistance; //0x0130
	char _0x0134[12];
};//Size=0x0140
#pragma pack(pop)
#endif

////////////////////////////////////////
// ClassId:   03681
// RuntimeId: 06663
// TypeInfo:  0x00000001427B8930
#ifndef _InputCurveData_
#define _InputCurveData_
#pragma pack(push, 8)
class InputCurveData : public DataContainer
{
public:
	static __inline InputCurveData* DefaultInstance()
	{
		return (InputCurveData*)0x00000000463C40F0;
	}
	static __inline unsigned int ClassId()
	{
		return 3681;
	}
	Array<__int32> m_AffectedInputs; //0x0010
	Array<Vec2> m_InputModifierCurve; //0x0018
	bool m_HandleMultipleInputsAsSquare; //0x0020
	char _0x0021[7];
};//Size=0x0028
#pragma pack(pop)
#endif




////////////////////////////////////////
// ClassId:   03022
// RuntimeId: 06906
// TypeInfo:  0x00000001427BF470
#ifndef _EntryComponentData_
#define _EntryComponentData_
#pragma pack(push, 16)
class EntryComponentData : public GameComponentData
{
public:
	static __inline EntryComponentData* DefaultInstance()
	{
		return (EntryComponentData*)0x00000000463B3660;
	}
	static __inline unsigned int ClassId()
	{
		return 3022;
	}
	////////////////////////////////////////
	// RuntimeId: 06898
	// TypeInfo:  0x00000001427BDDB0
	struct EntryComponentHudData
	{
		__int32 m_Index; //0x0000
		EntrySeatType m_SeatType; //0x0004
		bool m_Frustum; //0x0008
		bool m_Visible; //0x0009
		bool m_MaximizeMiniMapOnEntry; //0x000A
		char _0x000B[1];
	};//Size=0x000C

	////////////////////////////////////////
	// RuntimeId: 07807
	// TypeInfo:  0x00000001427D1ED8
	struct CharacterPoseConstraintsData
	{
		bool m_StandPose; //0x0000
		bool m_CrouchPose; //0x0001
		bool m_PronePose; //0x0002
	};//Size=0x0003

	////////////////////////////////////////
	// RuntimeId: 07725
	// TypeInfo:  0x00000001427CDB90
	struct PoseConstraintsData
	{
		bool m_StandPose; //0x0000
		bool m_CrouchPose; //0x0001
		bool m_PronePose; //0x0002
	};//Size=0x0003



	Vec3 m_SoldierOffset; //0x0070
	EntryClass m_EntryClass; //0x0080
	char _0x0084[4];
	GameAIEntryData* m_AIData; //0x0088
	EntryInputActionMapsData* m_InputConceptDefinition; //0x0090
	InputActionMappingsData* m_InputMapping; //0x0098
	Array<InputCurveData*> m_InputCurves; //0x00A0
	EntryComponentHudData m_HudData; //0x00A8
	__int32 m_EntryOrderNumber; //0x00B4
	float m_EnterImpulse; //0x00B8
	float m_EntryRadius; //0x00BC
	float m_SoldierTransitionInvisbleTime; //0x00C0
	__int32 m_NumberOfStances; //0x00C4
	EntrySpottingSettings m_EntrySpottingSettings; //0x00C8
	char _0x00CC[4];
	EntryComponentSoundData* m_EntryComponentSound; //0x00D0
	__int32 m_TriggerEventOnKey; //0x00D8
	bool m_ForbiddenForHuman; //0x00DC
	bool m_IsAllowedToExitInAir; //0x00DD
	bool m_IsShielded; //0x00DE
	bool m_LockSoldierAimingToEntry; //0x00DF
	bool m_ShowSoldierInEntry; //0x00E0
	bool m_Show1pSoldierInEntry; //0x00E1
	bool m_StancesEnabled; //0x00E2
	bool m_ShowSoldierWeaponInEntry; //0x00E3
	bool m_Show1pSoldierInEntryForPlayerOnly; //0x00E4
	bool m_Show3pSoldierWeaponInEntry; //0x00E5
	bool m_ShowSoldierGearInEntry; //0x00E6
	PoseConstraintsData m_PoseConstraints; //0x00E7
	bool m_AllowRagdollFromEntry; //0x00EA
	char _0x00EB[5];
};//Size=0x00F0
#pragma pack(pop)
#endif



////////////////////////////////////////
// ClassId:   03250
// RuntimeId: 07731
// TypeInfo:  0x00000001427CDCB0
#ifndef _AntEnumeration_
#define _AntEnumeration_
#pragma pack(push, 8)
class AntEnumeration : public DataContainer
{
public:
	static __inline AntEnumeration* DefaultInstance()
	{
		return (AntEnumeration*)0x00000000463BB250;
	}
	static __inline unsigned int ClassId()
	{
		return 3250;
	}
	AntRef m_AntAsset; //0x0010
	__int32 m_Value; //0x0024
};//Size=0x0028
#pragma pack(pop)
#endif


////////////////////////////////////////
// ClassId:   03023
// RuntimeId: 06911
// TypeInfo:  0x00000001427BF410
#ifndef _PlayerEntryComponentData_
#define _PlayerEntryComponentData_
#pragma pack(push, 16)
class PlayerEntryComponentData : public EntryComponentData
{
public:
	static __inline PlayerEntryComponentData* DefaultInstance()
	{
		return (PlayerEntryComponentData*)0x00000000463B3770;
	}
	static __inline unsigned int ClassId()
	{
		return 3023;
	}
	Vec3 m_AnimationAccelerationMultiplier; //0x00F0
	char* m_AntEntryID; //0x0100
	AntEntryIdEnum m_AntEntryId; //0x0108
	char _0x010C[4];
	AntEnumeration* m_AntEntryEnumeration; //0x0110
	char _0x0118[8];
};//Size=0x0120
#pragma pack(pop)
#endif

//CLientVault
class VaultBinding
{
public:
	char _0x0000[140];

};//Size=0x008C
class VaultComponentData
{
public:
	char _0x0000[112];
	float m_StartHeightMax; //0x0070 
	float m_StartHeightMin; //0x0074 
	VaultBinding m_Binding; //0x0078 
	char _0x0104[1864];
	Matrix N03302725; //0x084C 

};//Size=0x088C


/*class OldVault{
public:
	char _0x0000[48];
	Vec3 teleportVector; //0x30
};*/

class OldVault
{
public:
	char _0x0000[32];
	BYTE vaultReset; //0x0020 
	char _0x0021[15];
	Vec3 teleportVector; //0x0030 

};//Size=0x0040

class ClientVaultComponent
{
public:
	char _0x0000[16];
	VaultComponentData* pVaultComponentData; //0x0010 VaultComponentData
	char _0x0018[8];
	DWORD_PTR* m_ClientPlayerEntryComponent; //0x0020 ClientPlayerEntryComponent
	char _0x0028[200];
	BYTE m_VaultState; //0x00F0 
	char _0x00F1[0x19];
	OldVault* m_oldvault; //0x110
	char _0x0118[0x68];
	Vec3 OldPosition; //0x0180 
	float height_vaulted; //0x0190 
	char _0x0194[12];
	Vec3 NewPosition; //0x01A0 
	char _0x01B0[160];
	Vec3 m_TeleportVector; //0x0250 
	char _0x0260[24];

};//Size=0x0278


/*class ClientVaultComponent
{
public:
	char _0x0000[16];
	VaultComponentData* pVaultComponentData; //0x0010 
	char _0x0018[8];
	DWORD_PTR* m_ClientPlayerEntryComponent; //0x0020 
	char _0x0024[180];
	BYTE Inpulse; //0x00D8 
	char _0x00D9[11];
	BYTE Inpulse2; //0x00E4 
	char _0x00E5[11];
	BYTE m_VaultState; //0x00F0 
	BYTE N00915115; //0x00F1 
	BYTE N00920A45; //0x00F2 
	char _0x00F3[1];
	BYTE m_VaultState2; //0x00F4 
	char _0x00F5[27];
	OldVault* m_oldvault; //0x0110 
	char _0x0118[104];
	Vec3 OldPosition; //0x0180 
	float height_vaulted; //0x0190 
	char _0x0194[12];
	Vec3 NewPosition; //0x01A0 
	char _0x01B0[160];
	Vec3 m_TeleportVector; //0x0250 
	char _0x0260[24];
	
};//Size=0x0278*/

/*class TargetBulletImpact{
	std::unique_ptr<DirectX::SpriteFont> m_SpriteFont = NULL;
	std::unique_ptr<DirectX::SpriteBatch> m_SpriteBatch = NULL;
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_PrimitiveBatch = NULL;
	std::unique_ptr<DirectX::BasicEffect> m_BasicEffect = NULL;
	std::unique_ptr<DirectX::GeometricPrimitive> g_Shape = NULL;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
	namespace tk
	{

		bool initSpriteFont()
		{
			if (!m_SpriteFont)
			{
				HRSRC hRsrc = FindResource(inj_hModule, MAKEINTRESOURCE(IDR_TKFONT1), "tkfont");
				if (hRsrc)
				{
					HGLOBAL hGlob = NULL;
					if (HGLOBAL hGlob = LoadResource(inj_hModule, hRsrc))
					{
						DWORD dwResSize = SizeofResource(inj_hModule, hRsrc);
						FILE_LOG(logINFO) << "Ressource Found size 0x" << std::hex << dwResSize;
						LPVOID pRes = LockResource(hGlob);
						FILE_LOG(logINFO) << "Ressource Found at 0x" << std::hex << pRes;
						m_SpriteBatch = std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
						//m_SpriteFont = std::unique_ptr<DirectX::SpriteFont>(new DirectX::SpriteFont(DxRenderer::GetInstance()->m_pDevice, L"C:\\out\\wingdings.spritefont"));
						m_SpriteFont = std::unique_ptr<DirectX::SpriteFont>(new DirectX::SpriteFont(DxRenderer::GetInstance()->m_pDevice, (const uint8_t *)pRes, dwResSize));
						return true;
					}
					else return false;
				}
				else return false;
			}
			else return true;
		}
		bool initPrimitiveBatch()
		{
			if (!m_PrimitiveBatch)
			{
				m_BasicEffect = std::unique_ptr<DirectX::BasicEffect>(new DirectX::BasicEffect(DxRenderer::GetInstance()->m_pDevice));
				m_PrimitiveBatch = std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>(new DirectX::PrimitiveBatch<DirectX::VertexPositionColor>(DxRenderer::GetInstance()->m_pContext));
				m_BasicEffect->SetVertexColorEnabled(true);
				void const* shaderByteCode;
				size_t byteCodeLength;
				m_BasicEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
				DxRenderer::GetInstance()->m_pDevice->CreateInputLayout(DirectX::VertexPositionColor::InputElements, DirectX::VertexPositionColor::InputElementCount, shaderByteCode, byteCodeLength, inputLayout.GetAddressOf());
				return true;
			}
			else return true;
		}
		void drawText(int x, int y, Color color, wchar_t* text, float scale)
		{
			initSpriteFont();
			//std::wstring name(L"hello, world!");
			//const wchar_t* wcstring = name.c_str();
			//Vector2 textOrigin = m_SpriteFont->MeasureString(wcstring);
			m_SpriteBatch->Begin();
			m_SpriteFont->DrawString(m_SpriteBatch.get(), text, Vector2(x, y));
			m_SpriteBatch->End();
		}

		void drawLine2d(float x1, float y1, float x2, float y2, Color color)
		{

		}

		void drawLineRect2d(float x1, float y1, float x2, float y2, Color color)
		{

		}

		void drawRect2d(float x1, float y1, float x2, float y2, Color color)
		{

		}

		void drawBox2d(float x1, float y1, float x2, float y2, float width, Color color) {
			drawRect2d(x1, y1, x2, y1 + width, color);
			drawRect2d(x1, y2 - width, x2, y2, color);
			drawRect2d(x1, y1 + width, x1 + width, y1 - width, color);
			drawRect2d(x2 - width, y1 + width, x2, y2 - width, color);
		}

		void drawSphere(Vec3 &pos, float radius, Color color, bool renderLines, bool scalesmall)
		{

		};

		void cdrawCircle2d(float x, float y, float radius, Color color)
		{
			const int NUMPOINTS = 8 * 2;
			float X, Y;
			float PX = x + radius;
			float PY = y;
			float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
			WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
			for (int i = 0; i <= NUMPOINTS; i++)
			{
				Theta = i * WedgeAngle;
				X = (float)(x + radius * cos(Theta));
				Y = (float)(y - radius * sin(Theta));
				drawLine2d(PX, PY, X, Y, color);
				PX = X;
				PY = Y;
			}
		}
		void cdrawLine3d(Vector4 start, Vector4 end, Color color)
		{
			initPrimitiveBatch();
			Matrix pWorld = pWorld.Identity();
			m_BasicEffect.get()->SetWorld(pWorld);
			m_BasicEffect.get()->SetView(GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix);
			m_BasicEffect.get()->SetProjection(GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix);

			m_BasicEffect->Apply(DxRenderer::GetInstance()->m_pContext);
			DxRenderer::GetInstance()->m_pContext->IASetInputLayout(inputLayout.Get());

			m_PrimitiveBatch->Begin();
			DirectX::VertexPositionColor Vertex1;
			DirectX::VertexPositionColor Vertex2;
			Vertex1.color = color;
			Vertex2.color = color;
			Vertex1.position = (Vector3)start;
			Vertex2.position = (Vector3)end;

			m_PrimitiveBatch->DrawLine(Vertex1, Vertex2);
			m_PrimitiveBatch->End();
		}

		void cdrawCircle3d(Vector4 point, float radius, Color color, unsigned int segment)
		{
			const int NUMPOINTS = 8 * 2;
			float X, Y;
			float PX = point.x + radius;
			float PY = point.y;
			float Theta, WedgeAngle; //Size of angle between two points on the circle (single wedge)
			WedgeAngle = (float)(DirectX::XM_2PI / NUMPOINTS);
			for (int i = 0; i <= NUMPOINTS; i++)
			{
				Theta = i * WedgeAngle;
				X = (float)(point.x + radius * cos(Theta));
				Y = (float)(point.y - radius * sin(Theta));
				cdrawLine3d({ PX, PY, point.z, 0 }, { X, Y, point.z, 0 }, color);
				PX = X;
				PY = Y;
			}
		}
		void cdrawSphere3d(Vector4 point, float radius, Color color, unsigned int segment)
		{
			unsigned int i = 0;
			Vector4 start;
			Vector4 end;
			end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x, point.y + radius * cos(float(i) / segment * DirectX::XM_2PI), point.z + radius * sin(float(i) / segment * DirectX::XM_2PI), 0 };
				cdrawLine3d(start, end, color);
			}

			i = 0;
			end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x + radius * sin(float(i) / segment *  DirectX::XM_2PI), point.y + radius * cos(float(i) / segment *  DirectX::XM_2PI), point.z, 0 };
				cdrawLine3d(start, end, color);
			}

			i = 0;
			end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
			for (i = 1; i <= segment; i++)
			{
				start = end;
				end = { point.x + radius * sin(float(i) / segment * DirectX::XM_2PI), point.y, point.z + radius * cos(float(i) / segment * DirectX::XM_2PI), 0 };
				cdrawLine3d(start, end, color);
			}
		}
		void cdrawAabb3d(Vector4 vPosition, Vector4 vMin, Vector4 vMax, Matrix mTransform, Color color)
		{
			Vector4 vcrnr3d[9];
			vcrnr3d[1] = { vMin.x, vMin.y, vMin.z, 0 };
			vcrnr3d[2] = { vMax.x, vMin.y, vMin.z, 0 };
			vcrnr3d[3] = { vMax.x, vMin.y, vMax.z, 0 };
			vcrnr3d[4] = { vMin.x, vMin.y, vMax.z, 0 };
			vcrnr3d[5] = { vMin.x, vMax.y, vMax.z, 0 };
			vcrnr3d[6] = { vMin.x, vMax.y, vMin.z, 0 };
			vcrnr3d[7] = { vMax.x, vMax.y, vMin.z, 0 };
			vcrnr3d[8] = { vMax.x, vMax.y, vMax.z, 0 };

			for (int coin = 1; coin <= 8; coin++)
			{
				vcrnr3d[coin] = XMVector4Transform(vcrnr3d[coin], mTransform);
				vcrnr3d[coin] += vPosition;
			}
			//    .5------8
			// .'  |    .'|
			// 6---+--7'  |
			// |   |  |   |
			// |  ,4--+---3
			// |.'    | .'
			// 1------2'
			cdrawLine3d(vcrnr3d[1], vcrnr3d[2], color);
			cdrawLine3d(vcrnr3d[6], vcrnr3d..
				[16:54 : 26] Headmax...: j'ai du temps en ce moment du mois le soir
				[16:54 : 39] jean dupont : cdrawLine3d(vcrnr3d[4], vcrnr3d[3], color);
			cdrawLine3d(vcrnr3d[5], vcrnr3d[8], color);
			cdrawLine3d(vcrnr3d[4], vcrnr3d[5], color);
			cdrawLine3d(vcrnr3d[3], vcrnr3d[8], color);

			cdrawLine3d(vcrnr3d[4], vcrnr3d[1], color);
			cdrawLine3d(vcrnr3d[5], vcrnr3d[6], color);
			cdrawLine3d(vcrnr3d[2], vcrnr3d[3], color);
			cdrawLine3d(vcrnr3d[7], vcrnr3d[8], color);
		}
		void drawteapot(Matrix mTransform, Color color, float scale)
		{
			g_Shape = DirectX::GeometricPrimitive::CreateTeapot(DxRenderer::GetInstance()->m_pContext, scale);
			Matrix pWorld = pWorld.Identity();
			Vector3 Scale, Translation;
			Quaternion Rotation;
			mTransform.Decompose(Scale, Rotation, Translation);

			Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);
			g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, color); //DirectX::Colors::CornflowerBlue
		}
		void drawwiresphere(Matrix mTransform, Color color, float scale)
		{
			g_Shape = DirectX::GeometricPrimitive::CreateSphere(DxRenderer::GetInstance()->m_pContext, scale);
			Matrix pWorld = pWorld.Identity();
			Vector3 Scale, Translation;
			Quaternion Rotation;
			mTransform.Decompose(Scale, Rotation, Translation);

			Matrix local = pWorld * Matrix::CreateScale(Scale) * Matrix::CreateFromQuaternion(Rotation) *Matrix::CreateTranslation(Translation);
			g_Shape->Draw(local, GameRenderer::GetInstance()->m_pRenderView->m_viewMatrix, GameRenderer::GetInstance()->m_pRenderView->m_ProjectionMatrix, color, nullptr, true); //DirectX::Colors::CornflowerBlue
		}
	}
}*/

class GameEntity
{
public:
	virtual TypeInfo* GetType(); // 
	virtual void Function1(); // 
	virtual void Function2(); // 
	virtual void Function3(); // 
	virtual void Function4(); // 
	virtual void Function5(); // 
	virtual void Function6(); // 
	virtual void Function7(); // 
	virtual void Function8(); // 
	virtual void Function9(); // 
	virtual void Function10(); // 
	virtual void Function11(); // 
	virtual void Function12(); // 
	virtual void Function13(); // 
	virtual void Function14(); // 
	virtual void Function15(); // 
	virtual void Function16(); // 
	virtual void Function17(); // 
	virtual void Function18(); // 
	virtual void Function19(); // 
	virtual void Function20(); // 
	virtual void Function21(); // 
	virtual void Function22(); // 
	virtual void GetTransform(Matrix* mTransform);
	//ExplosionPackEntity the hell teamid where are you???
};


////////////////////////////////////////
// RuntimeId: 09549
// TypeInfo:  0x00000001427F51F8
struct SoldierDetonationData
{
	float m_Angle; //0x0000
	float m_Radius; //0x0004
	float m_SoldierDetonationActivationDelay; //0x0008
	float m_MinSpeedForActivation; //0x000C
	bool m_HasSoldierDetonation; //0x0010
	bool m_UseAngle; //0x0011
	char _0x0012[2];
};//Size=0x0014  


////////////////////////////////////////
// ClassId:   03677
// RuntimeId: 09609
// TypeInfo:  0x000000014282B1D0
#ifndef _ExplosionPackTrigger_
#define _ExplosionPackTrigger_
#pragma pack(push, 8)
class ExplosionPackTrigger : public DataContainer
{
public:
	static __inline ExplosionPackTrigger* DefaultInstance()
	{
		return (ExplosionPackTrigger*)0x0000000068B84160;
	}
	static __inline unsigned int ClassId()
	{
		return 3677;
	}
};//Size=0x0010
#pragma pack(pop)
#endif


////////////////////////////////////////
// RuntimeId: 08629
// TypeInfo:  0x0000000142815788
struct UIAudioEventMapping
{
	CString m_EventName; //0x0000
	SoundAsset* m_SoundAsset; //0x0008
};//Size=0x0010

////////////////////////////////////////
// ClassId:   01493
// RuntimeId: 08631
// TypeInfo:  0x0000000142816610
#ifndef _UIAudioEventAsset_
#define _UIAudioEventAsset_
#pragma pack(push, 8)
class UIAudioEventAsset : public Asset
{
public:
	static __inline UIAudioEventAsset* DefaultInstance()
	{
		return (UIAudioEventAsset*)0x0000000068B42C10;
	}
	static __inline unsigned int ClassId()
	{
		return 1493;
	}
	Array<UIAudioEventMapping> m_AudioEventMappings; //0x0018
};//Size=0x0020
#pragma pack(pop)
#endif

/*
	struct IVehicle
	{
		virtual ~IVehicle();
		void setInitialWorldPosition(Vec3 *);
		virtual void *createState(void *, unsigned __int64, unsigned __int64 *);
	//	virtual void *createState(MemoryArena *);
		virtual void setState(void *);
		virtual void getState(void *);
		virtual void stateToStream(LPVOID, void *, void *, LPVOID);
		virtual void streamToState(LPVOID, void *, void *, LPVOID);
		virtual void update(float);
		virtual void setTransform(LinearTransform *, bool);
		virtual LinearTransform *transform(LinearTransform *);
		virtual Quaternion *orientation(Quaternion *);
		virtual Vec3 *position(Vec3 *);
		virtual void* vehicleMode();
		virtual void setVehicleMode(LPVOID);
		virtual bool enterVehicle(bool);
		virtual bool startVehicle();
		virtual bool stopVehicle(bool);
		virtual bool leaveVehicle();
		virtual bool wantsUpdate();
		virtual void setInitialState(LPVOID);
	//	virtual VehicleInput *input();
		virtual void setThrottle(float);
		virtual float throttle();
		virtual void setBrake(float);
		virtual float brake();
		virtual void setHandBrake(float);
		virtual void setYaw(float);
		virtual void setPitch(float);
		virtual void setStrafe(float);
		virtual void setRoll(float);
		virtual void setBoost(bool);
		virtual float boost();
		virtual void setCrawl(bool);
		virtual void setUseInputFilter(bool);
		virtual void setBoostToggle(bool);
		virtual bool getBoostToggle();
		virtual void *data();
		virtual SimplePhysicsEntity *body();
		virtual void addEngine(void*);
		virtual void removeEngine(void*);
		virtual unsigned int numEngines();
		virtual void *engine(unsigned int);
		virtual void setGearbox(void *);
		virtual void *gearbox();
		virtual void addWheel(void *);
		virtual void removeWheel(void *);
		virtual unsigned int numWheels();
		virtual void *wheel(unsigned int);
		virtual void addWing(void*);
		virtual void removeWing(void*);
		virtual Vec3 *velocity();
		virtual bool isBoostActive();
		virtual bool hasContact();
		virtual Vec3 *getReplicatedAngularVelocity();
		virtual void setReplicatedAngularVelocity(Vec3 *);
		virtual void *motorbikePhysics();
		virtual Vec3 *getAngularMomentum(Vec3 *result);
		virtual void setAngularMomentum(Vec3 *);
		virtual Vec3 *getAngularVelocity();
		virtual void setAngularVelocity(Vec3 *);
		virtual void *floatPhysics();
		virtual void *aeroDynamicPhysics();
		virtual void *getStabilizer();
		virtual void *getAeroDynamicPhysics();
		virtual bool getIsAirborne();
		virtual bool getIsGroundVehicle();
		virtual void onSpawn();
		virtual bool isClientSimulationEnabled();
		virtual unsigned int clientSimulationTicks();
		virtual void disableClientSimulation();
		virtual void setWaterHeight(float);
		virtual float getWaterHeight();
		virtual bool isInWater();
		virtual void setLandingGearDeployed(bool);
		virtual bool landingGearDeployed();
		virtual void setReplicatedVelocity(Vec3 *);
		virtual Vec3 *getReplicatedVelocity();
		virtual void addWorldSpaceForce(Vec3 *, Vec3 *, float);
		virtual void addBodySpaceForce(Vec3 *, Vec3 *, float);
		//some more 7 tables follow.
	};
	*/

class BotPlayerRayInfo
{
public:
	bool is_soldier_ray_visible = false;
	bool is_vehicle_ray_visible = false;
};

class BotData
{
public:
	int mode = -1; //	a soldat ou en  vehicle

	int enemyChoosenID = -1;
	int previousEnemyChoosenID = -1;
	int sameenemyChoosenIDcount = 1; // 1 sinon risque de division par 0 dans le calcul du smooth
	float enemyDistanceCrossair2d = 9999.0;
	float enemyDistance3d = 9999.0;
	int boneSoldierIndex = -1;
	int boneVehicleIndex = -1;

	int armeValidAgainst = -1; // vehicle / soldat etc...

	// variable de debug pour l'esp (enemi choisi par l'aimbot)
	Vector2 bonePos2d = { 0, 0 };
	Vector2 boneCorrectedPos2d = { 0, 0 };

	BotPlayerRayInfo PlayersRayInfo[70];
};


BotData aimbotData;

class TrailPointResult
{
public:
	bool TrailPointToDraw = false;
	bool isValidPlayer = false;
	Vector4 TrailPosition;
};

/***************************************************************************/

  

class ClientLevel
{
public:

	class LevelSetupOption
	{
	public:
		char* m_Criterion; //0x0000 
		char* m_Value; //0x0008 
	}; //Size = 0x0010

	char _0x0000[56];
/*	LevelData* m_pLevelData; //0x0038 
	TeamInfo* m_pTeamInfo; //0x0040 */
	char _0x0048[8];
	LevelSetupOption* m_pLevelOption; //0x0050 
	__int32 m_DifficultyIndex; //0x0058 
	char _0x005C[196];
	HavokPhysicsManager* m_pPhysicsManager; //0x0120 
	char _0x0128[8];
	GameWorld* m_pGameWorld; //0x0130 

}; //Size=0x0148  

template <class T> class EntityIterator
{
public:
	class Element
	{
	public:

		Element* m_pFlink;
		Element* m_pBlink;
		__int32  m_Unk1;
		__int32  m_Unk2;

		T* getObject()
		{
			intptr_t pObject = reinterpret_cast<intptr_t>(this);
			pObject -= 0x40;

			return reinterpret_cast<T*>(pObject);
		}
	};

	Element* m_pFirst;
	Element* m_pCurrent;

	EntityIterator(GameWorld* pGameWorld, intptr_t pTypeInfo)
	{
		typedef Element* (__thiscall* tGetEntityList)(intptr_t pTypeInfo, GameWorld* pThis);
		tGetEntityList lpGetEntityList = reinterpret_cast<tGetEntityList>(OFFSET_GETENTITYLIST);

		this->m_pFirst = lpGetEntityList(pTypeInfo, pGameWorld);
		this->m_pCurrent = this->m_pFirst;
	}



	bool hasNext()
	{
		if (m_pCurrent && m_pCurrent->m_pFlink)
			return true;

		return false;
	}

	Element* first()    { return m_pFirst; }
	Element* front()    { return m_pCurrent; }
	Element* next()
	{
		if (!m_pFirst)
			return nullptr;

		m_pCurrent = m_pCurrent->m_pFlink;

		return m_pCurrent;
	}
};
#endif