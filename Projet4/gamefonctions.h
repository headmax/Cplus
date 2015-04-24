#include "memory.h"
class ClientVaultInterface;
int PlayerInLiveOnMap;
bool gameDead = false;

bool IsIamAlive()
{

	// check if my local soldier is valid
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return false;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return false;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return false;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return false;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalClientPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return false;

	if (!IsValidPtr(pLocalSoldier) || pLocalSoldier->m_pHealthComponent->m_Health <= 0.017f){
	//	FILE_LOG(logINFO) << "IM DEAD";
		gameDead = true;
		return false;
	}
	else{
		//FILE_LOG(logINFO) << "IM ALIVE";
		gameDead = false;
		return true;
	}
}


bool booltestIsAlive(){

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return false;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;

	if (IsIamAlive()){
		//FILE_LOG(logINFO) << "VIVANT";
		//sschamDelete = false;
		return true;
	}
	else{
		//FILE_LOG(logINFO) << "MORT";
		sschamDelete = true;
		return false;
	}
	//FILE_LOG(logINFO) << "ddddddddddddddddddddd";
	return false;
}


void deleteAllChams(bool end){
	sschamDelete = true;
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;

	//FILE_LOG(logINFO) << "UNCHAM VEHICLE START";
	//delete vehicles chams
	chams* UnChamVehicleEntity = new chams(pPlayerManager, pPlayerManager->m_maxPlayerCount, IsIamAlive());
	UnChamVehicleEntity->deleteAllVehicleChams();

	sschamDelete = true;
	for (unsigned int i = 0; i < pPlayerManager->m_maxPlayerCount; i++)
	{
		ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(i);
		if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) continue; // if no player or player is me

		ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
		if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) continue;

		if (pSoldier->m_pHealthComponent->m_Health <= 0.01f) continue;

		if (pPlayer->m_teamId != pPlayerManager->m_pLocalPlayer->m_teamId){
		//	FILE_LOG(logINFO) << "UNCHAM SOLDIER START";
			chams* UnChamSoldierEntity = new chams(pPlayerManager, pPlayerManager->m_maxPlayerCount, IsIamAlive());
			UnChamSoldierEntity->deleteSoldierCham(i, pSoldier);

			pPatchSoldier[i] = false;
			pUnPatchSoldier[i] = true;
		}
		sschamDelete = true;
	}

	if (end == true)
	sschamDelete = true;
}


bool IsPlayerAliveAndNotMe(int id)
{
	// check if a player is valid
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return false;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return false;
	ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(id);
	if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) return false; // if no player or player is me
	ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
	if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) return false;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return false;
	
	if (pSoldier->m_pHealthComponent->m_Health <= 0.017f){
		return false;
	} else{
		chams unChamSoldier = chams(pPlayerManager, pPlayerManager->m_maxPlayerCount, IsIamAlive());
		unChamSoldier.unactiveSoldierChams(pSoldier, id);
		return true;
	}
}



/*
bool MaxJump(ClientSoldierEntity* pSoldier){

	Sleep(50);
	
	pSoldier->m_pClientVaultComponent->pVaultComponentData->m_StartHeightMax = 300000.0f;
	FILE_LOG(logINFO) << "pSoldier at 0x" << std::hex << pSoldier;
	FILE_LOG(logINFO) << "pSoldier mdata at 0x" << std::hex << pSoldier->m_data;
	FILE_LOG(logINFO) << "VaultComponent at 0x" << std::hex << pSoldier->m_pClientVaultComponent;
	FILE_LOG(logINFO) << "VaultComponentData at 0x" << std::hex << pSoldier->m_pClientVaultComponent->pVaultComponentData;
	FILE_LOG(logINFO) << "VaultComponentData Maxheight at 0x" << std::hex << pSoldier->m_pClientVaultComponent->pVaultComponentData->m_StartHeightMax;

	std::MemPatchSafe(0x1403630f8, (BYTE*)"\x90\x90\x90", 3); //JUMPA 
	std::MemPatchSafe(0x140363074, (BYTE*)"\x90\x90\x90", 3); //JUMPB


	pSoldier->m_pClientVaultComponent->m_VaultState = 1;

	std::MemPatchSafe(0x1403630f8, (BYTE*)"\x89\x73\x48", 3);
	std::MemPatchSafe(0x140363074, (BYTE*)"\x89\x73\x48", 3);

	pSoldier->m_pClientVaultComponent->m_VaultState = 0;

	Sleep(1000);
	return 0;
}
*/



bool IsVisible(Vec3 vFrom, Vec3 vTo, bool& visible)
{
	__try{



		if (!IsValidPtr(&vFrom) || !IsValidPtr(&vTo))
			return false;

		ClientGameContext* p_GameContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(p_GameContext))
			return false;

		HavokPhysicsManager* pPhysicsManager = p_GameContext->m_pPhysicsManager;
		if (!IsValidPtr(pPhysicsManager))
			return false;

		GameWorld* pGameWorld = pPhysicsManager->m_GameWorld;
		if (!IsValidPtr(pGameWorld))
			return false;

		IPhysicsRayCaster* pRayCaster = pGameWorld->m_RayCaster;
		if (!IsValidPtr(pRayCaster))
			return false;

		bool bReturn = false;
		RayCastHit m_ray;
		Vec3 dir = ((vTo - vFrom) / 1000);

		while ((bReturn = pRayCaster->PhysicsRayQuery("ControllableFinder", &vFrom, &vTo, &m_ray, IPhysicsRayCaster::AimbotFlags, NULL))
			&& ((m_ray.m_material.isSeeThrough() || m_ray.m_material.isPenetrable()))){
			if (!m_ray.m_rigidBody)
				break;

			vFrom = (m_ray.m_position + dir);
		}

		return !bReturn;
	}
	__except (1){
		return FALSE;
	}
}


/************************************************************************/

enum EntityTypes
{
	ENT_INVALID = -1,
	ENT_VEHICLE = 1,
	ENT_EXPLOSIVE,
	ENT_SUPPLYBOX,
	ENT_PICKUP
};

typedef char* string;
std::map< int, string > entity_map;





void AllowClass(char* ClassName, int ID)
{
	entity_map[ID] = ClassName;
}


void AddObjectList()
{
	AllowClass("ClientVehicleEntity", ENT_VEHICLE);
	AllowClass("ClientSupplySphereEntity", ENT_SUPPLYBOX);
	AllowClass("ClientPickupEntity", ENT_PICKUP);
	AllowClass("ClientExplosionPackEntity", ENT_EXPLOSIVE);
}

int IsClassAllowed(char* it)//returns our intern class id
{
	FILE_LOG(logINFO) << "TEST IsClassAllowed";
	for (std::map< int, string >::iterator it = entity_map.begin(); it != entity_map.end(); it++)
	{
		FILE_LOG(logINFO) << "TEST bool it._Ptr = " << it._Ptr;
		if (it._Ptr)
			return it->first;
	}
	FILE_LOG(logINFO) << "TEST bool it._Ptr PAS BON ";
	return -1;
}

bool IsValidEntityClass(void* ClassPointer, int& iType)
{
	ITypedObject* pEntity = reinterpret_cast< ITypedObject* >(ClassPointer);
	if (IsValidPtr(pEntity))
	{
		bool isGetType = false;
		DWORD_PTR* pss = reinterpret_cast< DWORD_PTR* >(pEntity);
		if (IsValidPtr(pss) && IsValidPtr((void*)pss[0]))
		{
			DWORD_PTR* vtable = (DWORD_PTR*)pss[0];
			if (IsValidPtr((void*)vtable))
			{
				if (IsValidPtr((void*)vtable[0]))
				{
					BYTE bA = *(BYTE*)(vtable[0]);
					BYTE bB = *(BYTE*)(vtable[0] + 1);
					BYTE bC = *(BYTE*)(vtable[0] + 2);
					BYTE bD = *(BYTE*)(vtable[0] + 7);

					if (bA == 0x48 && bB == 0x8D && bC == 0x05 && bD == 0xC3)
						isGetType = true;
				}
			}
		}

		if (isGetType)
		{
			TypeInfo *type = pEntity->GetType();
			if (IsValidPtr(type))
			{
				if (TypeInfo::TypeInfoData *typeInfoData = type->getTypeInfoData())
				{
					if (IsValidPtr(typeInfoData))
					{
						FILE_LOG(logINFO) << "TEST VALID PRT OK";
						FILE_LOG(logINFO) << "TEST typeInfoData->m_name = " << typeInfoData->m_name;
						iType = IsClassAllowed(typeInfoData->m_name);
						if (iType > 0) return true;
					}
				}
			}
		}
	}
	return false;
}


DirectX::XMFLOAT3 RotMatrixToEuler(Matrix rotmatrix)
{
	DirectX::XMFLOAT3 angles;
	if (rotmatrix._31 != 1 && rotmatrix._31 != -1)
	{
		angles.x = -asin(rotmatrix._31);
		angles.y = atan2(rotmatrix._32 / cos(angles.x), rotmatrix._33 / cos(angles.x));
		angles.z = atan2(rotmatrix._21 / cos(angles.x), rotmatrix._11 / cos(angles.x));
	}
	else
	{
		angles.z = 0;
		if (rotmatrix._31 == -1)
		{
			angles.x = DirectX::XM_PI / 2;
			angles.y = atan2(rotmatrix._12, rotmatrix._13);
		}
		else
		{
			angles.x = -DirectX::XM_PI / 2;
			angles.y = atan2(-rotmatrix._12, -rotmatrix._13);
		}
	}
	return angles;
}

int GetPlayerInLiveOnMap(ClientPlayerManager* pPlayerManager){
	int validPlayer = 1;
	for (unsigned int i = 0; i < pPlayerManager->m_maxPlayerCount; i++)
	{
		ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(i);
		if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) continue; // if no player or player is me
		if (IsPlayerAliveAndNotMe(i)) PlayerInLiveOnMap = validPlayer++;
	}

	PlayerInLiveOnMap = (PlayerInLiveOnMap == 0) ? pPlayerManager->m_maxPlayerCount : PlayerInLiveOnMap;

	return (int)PlayerInLiveOnMap;
}

void ObjectIteration(ClientPlayer* pPlayer, ClientSoldierEntity* pSoldier)
{
	/*if (!IsValidPtr(m_GameContext) || !IsValidPtr(m_GameRenderer) || !IsValidPtr(m_DxRenderer))
		return;*/

	if (!IsValidPtr(pPlayer) || !IsValidPtr(pSoldier))
		return;
	FILE_LOG(logINFO) << "PTR SOLDIER ET PLAYER OK";

	CObjectList* pList = CObjectList::GetInstance();

	if (IsValidPtr(pList))
	{
		FILE_LOG(logINFO) << "PTR pList OK";
		FILE_LOG(logINFO) << "pList NOMBRE = " << pList->Size();
		for (int i = 0; i <= pList->Size(); i++)
		{
			CObjectEntry* Entity = &pList->m_Collection[i];
			if (!IsValidPtrEh(Entity)) continue;
			FILE_LOG(logINFO) << "PTR Entity OK";
			GameObject* pObject = Entity->m_pEntity;

			if (pObject)
			{
				FILE_LOG(logINFO) << "PTR pObject OK";

				void* pEntity = NULL;
				int iObjectType;

				if (!IsValidPtrEh(pObject->Ptr1)) continue;
					FILE_LOG(logINFO) << "PTR pObject->Ptr1 OK";
					pEntity = pObject->Ptr1;
					FILE_LOG(logINFO) << "IsValidEntityClass TEST PTR1 = " << IsValidEntityClass(pEntity, iObjectType);

				if (!IsValidPtrEh(pObject->Ptr2)) continue;
					FILE_LOG(logINFO) << "PTR pObject->Ptr2 OK";
					pEntity = pObject->Ptr2;
					FILE_LOG(logINFO) << "IsValidEntityClass TEST PTR2 = " << IsValidEntityClass(pEntity, iObjectType);

				if (IsValidEntityClass(pEntity, iObjectType))
				{
					FILE_LOG(logINFO) << "CLASS VALID";

					GameEntity* pGameEntity = reinterpret_cast< GameEntity* >(pEntity);

					if (IsValidPtrEh(pGameEntity))//checking it again, paranoia
					{
						FILE_LOG(logINFO) << "pGameEntity VALID";
						FILE_LOG(logINFO) << "iObjectType = " << iObjectType;
						Matrix mEntityTransform;
						pGameEntity->GetTransform(&mEntityTransform);
						Vec3 vEntityPos = mEntityTransform.Translation();

						switch (iObjectType)
						{
						case ENT_VEHICLE:
							FILE_LOG(logINFO) << "COUNT I = " << i;
							break;
						case ENT_EXPLOSIVE:
							FILE_LOG(logINFO) << "COUNT I = " << i;
							break;
						case ENT_SUPPLYBOX:
							FILE_LOG(logINFO) << "COUNT I = " << i;
							break;
						case ENT_PICKUP:
							FILE_LOG(logINFO) << "COUNT I = " << i;
							break;
						case ENT_INVALID:
						default: break;
						}
						FILE_LOG(logINFO) << "COUNT I = " << i;
					}
				}
			}
		}
	}
}