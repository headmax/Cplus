/********************************************************************************/
/*                    HKPRESENT HOOK + SAVE ALL SS                              */
/********************************************************************************/
unsigned int g_cleanFramesPass[5];
unsigned int g_oldCleanFrameCaptured[5];


/********************************************************************************/
/*                    C4 MODULE PARAMETRAGES                                    */
/********************************************************************************/
#define MAX_C4_INMAP 100
#define MAX_C4_BOOMDISTANCE 5
Vector4 g_C4location[MAX_C4_INMAP];
//ClientPlayer * g_C4owner[MAX_C4_INMAP];
unsigned int g_C4poses = 0;
unsigned int g_C4time = 0;
float g_pInputBuffersa[64];
float g_pInputBuffersb[64];
bool init_view_destination_C4d = false;

RayCastHit gmRayHit;
bool gmRayHitresult;

/********************************************************************************/
/*                    NEW TEST  PARAMETRAGES                                    */
/********************************************************************************/
DWORD64 g_dwBase, g_dwSize;
ModuleAppz* mAppEXEGame = new ModuleAppz(NULL, &g_dwBase, &g_dwSize);


int r, g, b, a;

TrailPointResult g_TrailPointResult;


/********************************************************************************/
/*                   F : GetDistance (metre)                                    
/*******************************************************************************/
/*	+@type float
	+@arg1 = ptr* class ClientPlayer
	+@return float
*******************************************************************************/

float GetDistance(ClientPlayer* pPlayer)
{
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return 0;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return 0;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return 0;
		ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
		if (!IsValidPtr(pLocalSoldier) || (!IsValidPtr(pLocalSoldier->m_pPredictedController) && !IsValidPtr(pPlayer->GetClientSoldier()->m_pPredictedController))) return 0;
		
		float xD = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.x - pLocalSoldier->m_pPredictedController->m_Position.x;
		float yD = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.y - pLocalSoldier->m_pPredictedController->m_Position.y;
		float zD = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.z - pLocalSoldier->m_pPredictedController->m_Position.z;

	return sqrt(xD * xD + yD * yD + zD * zD);
}



/********************************************************************************/
/*                   F : Distance2d (metre)
/*******************************************************************************/
/*	+@type float
	+@arg1 = Vec2
	+@arg2 = Vec2
	+@return float
*******************************************************************************/

float Distance2d(Vector2 Vec1, Vector2 Vect2)
{
	float xDistance = Vect2.x - Vec1.x;
	float yDistance = Vect2.y - Vec1.y;
	float Distance = sqrt(xDistance*xDistance + yDistance*yDistance);
	return Distance;
}


/********************************************************************************/
/*                   F : Distance3d (metre)
/*******************************************************************************/
/*	+@type float
	+@arg1 = DirectX::XMFLOAT4
	+@arg2 = DirectX::XMFLOAT4
	+@return float
*******************************************************************************/

float Distance3d(DirectX::XMFLOAT4 Vec1, DirectX::XMFLOAT4 Vect2)
{
	float xDistance = Vect2.x - Vec1.x;
	float yDistance = Vect2.y - Vec1.y;
	float zDistance = Vect2.z - Vec1.z;
	float Distance = sqrt(xDistance*xDistance + yDistance*yDistance + zDistance*zDistance);
	return Distance;
}


/********************************************************************************/
/*                   F : vDistance3d (metre)
/*******************************************************************************/
/*	+@type float
	+@arg1 = Vec4
	+@arg2 = Vec4
	+@return float
*******************************************************************************/

float vDistance3d(Vector4 Vec1, Vector4 Vect2)
{
	Vector3 Diff = (Vect2 - Vec1);
	return Diff.Length();
}


/********************************************************************************/
/*                   F : relativeBoxPersonView (Vec3)
/*******************************************************************************/
/*	+@type Vec3
	+@arg1 = PTR* Class ClientSoldierEntity
	+@arg2 = Bool
	+@return Vec3
*******************************************************************************/

Vec3 relativeBoxPersonView(ClientSoldierEntity* pSoldier, bool showstate){
	
	Vec3 NullVec;
	NullVec.x = 0; NullVec.y = 0; NullVec.z = 0;
	if (!IsValidPtrEh(pSoldier)) return NullVec;

	ClientSoldierWeapon* pSoldierWeapon = pSoldier->GetActiveWeapon();

	Vec3 rayPos = pSoldier->GetActiveWeapon()->m_authorativeAiming->m_RayEnd;

	if (showstate == true)
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(rayPos, 0.1f, fb::Color32(255, 255, 0, 200), 20);

		Matrix mat;
		pSoldier->GetTransform(&mat);
		Vec3 TPpos = mat.Translation(); //r[3]
		TPpos.x = rayPos.x;
		TPpos.y = rayPos.y;
		TPpos.z = rayPos.z;

		return TPpos;
}



/********************************************************************************/
/*                   F : relativeBoxPersonViewC4d (Vec3)
/*******************************************************************************/
/*	+@type Vec3
	+@arg1 = PTR* Class ClientSoldierEntity
	+@arg2 = PTR* Class CObjectEntry
	+@arg3 = bool
	+@return Vec3
*******************************************************************************/

Vec3 relativeBoxPersonViewC4d(ClientSoldierEntity* pSoldier, CObjectEntry* Entity, bool showstate){
	Vec3 NullVec;
	NullVec.x = 0; NullVec.y = 0; NullVec.z = 0;

	ClientSoldierWeapon* pSoldierWeapon = pSoldier->GetActiveWeapon();

	Vec3 rayPos = pSoldier->GetActiveWeapon()->m_authorativeAiming->m_RayEnd;

	if (showstate == true)
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(rayPos, 0.1f, fb::Color32(255, 255, 0, 200), 20);

	Matrix mat;
	//	pSoldier->GetTransform(&mat);
	Vec3 TPpos = Entity->m_position; //r[3]
	TPpos.x = rayPos.x;
	TPpos.y = rayPos.y;
	TPpos.z = rayPos.z;

	return TPpos;
}



/********************************************************************************/
/*                   F : checkBoxViewC4d (Vec3)
/*******************************************************************************/
/*	+@type Vec3
	+@arg1 = PTR* Class CObjectEntry
	+@arg2 = PTR* Class ClientSoldierEntity
	+@return Vec3
*******************************************************************************/

Vec3 checkBoxViewC4d(CObjectEntry* Entity, ClientSoldierEntity* pLocalSoldier){
	Vec3 TPpos;
	if (g_Keyb_VK_X)
		init_view_destination_C4d = (init_view_destination_C4d) ? false : true;

	if (init_view_destination_C4d){
		TPpos = relativeBoxPersonViewC4d(pLocalSoldier, Entity, true);
	}
	else{
		TPpos = relativeBoxPersonViewC4d(pLocalSoldier, Entity, false);
	}
	return TPpos;
}



/********************************************************************************/
/*                   F : relativeDestinationJumpView (Vec3)
/*******************************************************************************/
/*	+@type Vec3
	+@arg1 = PTR* Class ClientSoldierEntity
	+@arg2 = bool
	+@arg3 = Vec3
	+@return Vec3
*******************************************************************************/
Vec3 relativeDestinationJumpView(ClientSoldierEntity* pSoldier, bool showstate, Vec3 rayPos){

	Matrix mat;
	pSoldier->GetTransform(&mat);
	Vec3 TPpos = (Vec3)mat.Translation(); //r[3]
	TPpos.x = rayPos.x;
	TPpos.y = rayPos.y;
	TPpos.z = rayPos.z;

	return TPpos;
}



/********************************************************************************/
/*                   F : MatrixToAngles (bool)
/*******************************************************************************/
/*	+@type bool
+@arg1 = Matrix
+@arg2 = float
+@arg3 = float
+@arg4 = float
+@return bool
*******************************************************************************/

bool MatrixToAngles(Matrix matrice, float *Yaw, float *Pitch, float *Roll)
{

	if (matrice._11 == 1.0f)
	{
		*Yaw = atan2f(matrice._13, matrice._34);
		*Pitch = 0; *Roll = 0;
	}
	else if (matrice._11 == -1.0f)
	{
		*Yaw = atan2f(matrice._13, matrice._34);
		*Pitch = 0; *Roll = 0;
	}
	else {
		*Yaw = atan2(-matrice._31, matrice._11);
		*Pitch = asin(matrice._21);
		*Roll = atan2(-matrice._23, matrice._22);
	}

	if (*Yaw < 0) *Yaw = *Yaw + (DirectX::XM_PI * 2); // du n'importe quoi mais semble ok
	if (*Pitch < 0) *Pitch = *Pitch + (DirectX::XM_PI * 2); //
	if (*Roll < 0) *Roll = *Roll + (DirectX::XM_PI * 2); //


	/*
	*Yaw = DirectX::XMScalarModAngle(*Yaw);
	*Pitch = DirectX::XMScalarModAngle(*Pitch);
	*Roll = DirectX::XMScalarModAngle(*Roll);
	*/
	return true;
}

/*
void Teleport(){

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pClientPlayer)) return;
	ClientSoldierEntity* pSoldier = pClientPlayer->GetClientSoldier();

	Vec3 pDestination = relativeBoxPersonView(pSoldier,true);

	if (pDestination.x != 0 && pDestination.y != 0 && pDestination.z != 0){
		//pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector = pDestination;

		if (GetAsyncKeyState(VK_F7) & 0x8000){

			//Beep(9000, 30);

			if (IsValidPtr(pSoldier->GetActiveWeapon()))
			{
			if (IsValidPtr(pSoldier->GetActiveWeapon()->m_authorativeAiming))
			{
			//Vec3 TPpos = pSoldier->GetActiveWeapon()->m_authorativeAiming->m_RayEnd;

				FILE_LOG(logINFO) << "rayPos.x: " << rayPos.x;
			FILE_LOG(logINFO) << "rayPos.z: " << rayPos.z;
			FILE_LOG(logINFO) << "rayPos.y: " << rayPos.y;



			std::MemPatchSafe(0x1403630f8, (BYTE*)"\x90\x90\x90", 3);
			std::MemPatchSafe(0x140363074, (BYTE*)"\x90\x90\x90", 3);

			std::MemPatchSafe(((DWORD_PTR)pSoldier->m_pClientVaultComponent->m_oldvault + 0x30), (BYTE*)&pDestination, 12);

			//pSoldier->m_pClientVaultComponent->m_VaultState = 1;

			std::MemPatch((DWORD_PTR)pSoldier->m_pClientVaultComponent + 0xD8, (BYTE*)"\x01\x01", 2);
			std::MemPatch((DWORD_PTR)pSoldier->m_pClientVaultComponent + 0xD8, (BYTE*)"\x00\x00", 2);

			std::MemPatchSafe((DWORD_PTR)pSoldier->m_pClientVaultComponent + 0xF0, (BYTE*)"\x01", 1);
			//std::writeByte((DWORD_PTR)pSoldier->m_pClientVaultComponent + 0xF0, 1);
			Sleep(1200);


			//pSoldier->m_pClientVaultComponent->m_oldvault->vaultState = 1;

			std::MemPatchSafe(0x1403630f8, (BYTE*)"\x89\x73\x48", 3);
			std::MemPatchSafe(0x140363074, (BYTE*)"\x89\x73\x48", 3);

			DWORD_PTR teleport = (DWORD_PTR)pSoldier->m_pClientVaultComponent->m_oldvault + 0x30;
			FILE_LOG(logINFO) << "VECTORTELEPORT (oldvault + 30): " << std::hex << teleport;
			std::MemPatchSafe((teleport), (BYTE*)"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 12);
			//pSoldier->m_pClientVaultComponent->m_VaultState = 1;
			std::MemPatchSafe((DWORD_PTR)pSoldier->m_pClientVaultComponent + 0xF0, (BYTE*)"\x01", 1);
			}
			}

			//std::write(((DWORD_PTR)pSoldier->m_pClientVaultComponent->m_oldvault + 0x30), &pDestination, sizeof(Vec3));

			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent at 0x" << std::hex << pSoldier->m_pClientVaultComponent;
			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent->m_oldvault at 0x" << std::hex << pSoldier->m_pClientVaultComponent->m_oldvault;
			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent->pVaultComponentData at 0x" << std::hex << pSoldier->m_pClientVaultComponent->pVaultComponentData;

			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector at x = " << pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector.x;
			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector at y = " << pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector.y;
			FILE_LOG(logINFO) << "pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector at z = " << pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector.z;
		}
	}

}
*/


/********************************************************************************/
/*                   F : GetVehicleName (std::string)
/*******************************************************************************/
/*	+@type std::string
	+@arg1 = PTR* ClientVehicleEntity
	+@return std::string
*******************************************************************************/

std::string GetVehicleName(ClientVehicleEntity* pVehicle)
{
	if (!IsValidPtr(pVehicle)) return "None";
	VehicleEntityData* pVehicleEntityData = pVehicle->GetData();
	if (!IsValidPtr(pVehicleEntityData)) return "None";

	std::string str = std::string(pVehicle->m_data->m_NameSid);
	str = str.substr(11, strlen(pVehicle->m_data->m_NameSid) - 1);
	/*FILE_LOG(logINFO) << "pClientVehicle at 0x" << std::hex << pVehicle;
	FILE_LOG(logINFO) << "pClientVehicledata at 0x" << std::hex << pVehicle->m_data;
	FILE_LOG(logINFO) << "name: " << str;*/
	return str;
}



/********************************************************************************/
/*                   F : GetSpectators (void)
/*******************************************************************************/
/*	+@type void
	+@return void
*******************************************************************************/

void GetSpectators()
{
	if (!IsIamAlive()) return;

	ClientGameContext* pGameContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGameContext)) return;

	ClientPlayerManager* pPlayerManager = pGameContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;

	ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalPlayer)) return;

	eastl::vector<ClientPlayer*>* Spectators = pPlayerManager->getSpectators();
	if (!IsValidPtr(Spectators)) return;

	for (unsigned int i = 0; i < Spectators->size(); i++)
	{
		ClientPlayer* pPlayer = Spectators->at(i);
		if (!IsValidPtr(pPlayer)) continue;

		ClientPlayer::ClientPlayerView* pView = pPlayer->m_PlayerView;

		char temp[512];
		if (IsValidPtr(pLocalPlayer) && IsValidPtr(pView) && pView->m_Owner == pLocalPlayer)
		{
			//ChamOff();
			sprintf_s(temp, "Bot or Spectator %s\n Is Watching You!", pPlayer->szName);
			fb::DebugRenderer2::Singleton()->drawText(0, 200 + (20 * i), fb::Color32(255, 0, 0, 255), temp, 2.0f);
		}
		else{
			//ChamOff();
			sprintf_s(temp, "Bot or Spectator %s\n", pPlayer->szName);
			fb::DebugRenderer2::Singleton()->drawText(0, 200 + (20 * i), fb::Color32(240, 240, 250, 255), temp, 2.0f);
		}

	}
}



/********************************************************************************/
/*                   F : forceBoneUpdate (void)
/*******************************************************************************/
/*	+@type void
	+@arg1 = PTR* ClientSoldierEntity
	+@return void
*******************************************************************************/

void forceBoneUpdate(ClientSoldierEntity* targetSoldier)
{
	if (IsValidPtr(targetSoldier))
	{
		ClientSoldierWeaponsComponent* m_soldierWeaponsComponent = targetSoldier->m_soldierWeaponsComponent;

		if (IsValidPtr(m_soldierWeaponsComponent))
		{
			ClientAntAnimatableComponent* m_animatableComponent = m_soldierWeaponsComponent->m_animatableComponent[0];
			if (IsValidPtr(m_animatableComponent))
			{
				GameAnimatable* pGameAnimatable = m_animatableComponent->m_handler;
				if (IsValidPtr(pGameAnimatable)) pGameAnimatable->m_hadVisualUpdate = true;
			}

			m_animatableComponent = m_soldierWeaponsComponent->m_animatableComponent[1];
			if (IsValidPtr(m_animatableComponent))
			{
				GameAnimatable* pGameAnimatable = m_animatableComponent->m_handler;
				if (IsValidPtr(pGameAnimatable)) pGameAnimatable->m_hadVisualUpdate = true;
			}
		}
	}
}



/********************************************************************************/
/*                   F : GetSoldierBoneVector (bool)
/*******************************************************************************/
/*	+@type bool
	+@arg1 = PTR* ClientSoldierEntity
	+@arg2 = int
	+@arg3 = Vector4 or Vec3
	+@return bool
*******************************************************************************/

bool GetSoldierBoneVector(ClientSoldierEntity* pClientSoldier, int BoneID, Vector4 *BoneVectorOut)
{
	if (IsValidPtr(pClientSoldier) && BoneID > 0 && BoneID < 230)
	{
		ClientRagDollComponent* pRagdollComp = pClientSoldier->m_ragdollComponent;
		if (IsValidPtr(pRagdollComp))
		{
			UpdatePoseResultData pPoseResultData = pRagdollComp->m_ragdollTransforms;
			if (pPoseResultData.m_ValidTransforms == 1)
			{
				UpdatePoseResultData::QuatTransform* pQuatTransform = pPoseResultData.m_ActiveWorldTransforms;
				if (IsValidPtr(pQuatTransform))
				{
					*BoneVectorOut = pQuatTransform[BoneID].m_TransAndScale;
					return true;
				}
			}
		}
	}
	return false;
}




/********************************************************************************/
/*                   F : DrawVehicleAABB (bool)
/*******************************************************************************/
/*	+@type bool
	+@arg1 = PTR* ClientSoldierEntity
	+@arg2 = fb::Color32
	+@return bool
*******************************************************************************/

bool DrawVehicleAABB(ClientVehicleEntity* pClientVehicle, fb::Color32 dwColor)
{
	if (IsValidPtr(pClientVehicle))
	{
		/* test bones vehicles
		if (g_Keyb_VK_TAB)
		{
		//FILE_LOG(logINFO) << "pClientVehicle at 0x" << std::hex << pClientVehicle;
		DynamicPhysicsEntity* pDynamicPhysicsEntity = pClientVehicle->m_pDynamicPhysicsEntity;
		FILE_LOG(logINFO) << "DrawVehicleAABB: pDynamicPhysicsEntity at 0x" << std::hex << pDynamicPhysicsEntity;
		for (unsigned int i = 0; i <70 ; i++) //pDynamicPhysicsEntity->bitCount
		{
		LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
		transform = transform + (i);
		//FILE_LOG(logINFO) << "transform at 0x" << std::hex << transform << "add: " << std::hex << (i * 0x20);
		Vector4 transformpos = transform->m_trans;
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(transformpos, 0.1f, fb::Color32(255, 0, 0, 200), 20);

		}
		for (unsigned int i = 0; i < pDynamicPhysicsEntity->bitCount; i++) //pDynamicPhysicsEntity->bitCount
		{
		LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
		transform = transform + (i);
		//FILE_LOG(logINFO) << "transform at 0x" << std::hex << transform << "add: " << std::hex << (i * 0x20);
		Vector4 transformpos = transform->m_trans;
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(transformpos, 0.1f, fb::Color32(255, 255, 0, 200), 20);
		}
		}
		*/

		// Get AABB
		Vector4 vmin, vmax;
		vmin = pClientVehicle->m_childrenAABB.min;
		vmax = pClientVehicle->m_childrenAABB.max;

		// Get position
		Matrix mTransform;
		pClientVehicle->GetTransform(&mTransform);
		Vector4 vectorPosition = mTransform.Translation();     //.r[3];

		fb::DebugRenderer2::Singleton()->cdrawAabb3d(vectorPosition, vmin, vmax, mTransform, dwColor);
		return true;
	}
	return false;
}




/********************************************************************************/
/*                   F : GetBone (bool)
/*******************************************************************************/
/*	+@type bool
	+@arg1 = PTR* ClientSoldierEntity
	+@arg2 = Vec3
	+@arg3 = Enum UpdatePoseResultData::BONES
	+@return bool
*******************************************************************************/

bool GetBone(ClientSoldierEntity* pEnt, Vec3 *vOut, UpdatePoseResultData::BONES BoneId)
{
	ClientRagDollComponent* pRag = pEnt->m_ragdollComponent;
	if (!IsValidPtr(pRag))
		return false;

	UpdatePoseResultData PoseResult = pRag->m_ragdollTransforms;
	if (PoseResult.m_ValidTransforms)
	{
		UpdatePoseResultData::QuatTransform* pQuat = PoseResult.m_ActiveWorldTransforms;
		if (!IsValidPtr(pQuat))
			return false;

		Vec3 Temp = pQuat[BoneId].m_TransAndScale;

		vOut->x = Temp.x;
		vOut->y = Temp.y;
		vOut->z = Temp.z;
		return true;
	}
	else{
		return false;
	}
}




/********************************************************************************/
/*                   F : soldierC4dLancer (void)
/*******************************************************************************/
/*	+@type void
	+@return void
*******************************************************************************/

void soldierC4dLancer(){
	//FILE_LOG(logINFO) << "STEP1";
	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return;
	//FILE_LOG(logINFO) << "STEP2";
	SoldierWeaponData* pSoldierWeaponData = reinterpret_cast<SoldierWeaponData*>(pWeaponFiring->m_pFiringHolderData);
	if (!IsValidPtr(pSoldierWeaponData)) return;
	//FILE_LOG(logINFO) << "STEP3";
	if (pSoldierWeaponData->m_WeaponClass == wcC4)
	{
	//	FILE_LOG(logINFO) << "STEP4";
	//	FILE_LOG(logINFO) << "NoRecoilSoldier C4 pSoldierWeaponData: at 0x" << std::hex << pSoldierWeaponData;
		FiringFunctionData *pFiringFunctionData = pWeaponFiring->m_pPrimaryFire->m_FiringData;
		if (!IsValidPtr(pFiringFunctionData)) return;
		pFiringFunctionData->m_ShotConfigData.m_InitialSpeed = { 0.0f, 0.0f, 20.0f, 0.0 };
	}
}




/********************************************************************************/
/*                   F : DrawSoldierSkeleton (bool)
/*******************************************************************************/
/*	+@type bool
	+@arg1 = PTR* ClientSoldierEntity
	+@arg2 = fb::Color32
	+@return bool
*******************************************************************************/

bool DrawSoldierSkeleton(ClientSoldierEntity* pClientSoldier, fb::Color32 dwColor)
{
	/*ClientPlayer* pPlayer;
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return 0;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return 0;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return 0;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || (!IsValidPtr(pLocalSoldier->m_pPredictedController) && !IsValidPtr(pPlayer->GetClientSoldier()->m_pPredictedController))) return 0;
	*/


	if (IsValidPtr(pClientSoldier))
	{
		int iSkeletonBones[23] = { 4, 6, 8, 9, 11, 15, 61, 63, 104, 109, 111, 115, 182, 183, 184, 185, 196, 197, 198, 199, 46, 96, NULL };//those are bone ID's
		Vector2 iSkeletonBones2d[23]; 
		ZeroMemory(&iSkeletonBones2d, sizeof(iSkeletonBones2d));

		Vector4 iSkeletonBones3d[23]; 
		ZeroMemory(&iSkeletonBones3d, sizeof(iSkeletonBones3d));

		for (int BoneIndex = 0; BoneIndex < 23 - 1; BoneIndex++)
		{
			if (!GetSoldierBoneVector(pClientSoldier, iSkeletonBones[BoneIndex], &iSkeletonBones3d[BoneIndex])) return false;
			if (!WorldToScreen(iSkeletonBones3d[BoneIndex], &iSkeletonBones2d[BoneIndex])) return false;
		}
		/*
		int iSpine[] = { 0, 1, 2 };//Spine
		int iR_Arm[] = { 2, 9, 10, 11 };//RightArm
		int iL_Arm[] = { 2, 3, 4, 5 };//LeftArm
		int iR_Foot[] = { 0, 16, 17, 18, 19 };//RightFoot
		int iL_Foot[] = { 0, 12, 13, 14, 15 };//LeftFoot
		*/


		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[0].x, iSkeletonBones2d[0].y, iSkeletonBones2d[1].x, iSkeletonBones2d[1].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[1].x, iSkeletonBones2d[1].y, iSkeletonBones2d[2].x, iSkeletonBones2d[2].y, dwColor);
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[2].x, iSkeletonBones2d[2].y, iSkeletonBones2d[9].x, iSkeletonBones2d[9].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[9].x, iSkeletonBones2d[9].y, iSkeletonBones2d[10].x, iSkeletonBones2d[10].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[10].x, iSkeletonBones2d[10].y, iSkeletonBones2d[11].x, iSkeletonBones2d[11].y, dwColor);
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[2].x, iSkeletonBones2d[2].y, iSkeletonBones2d[3].x, iSkeletonBones2d[3].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[3].x, iSkeletonBones2d[3].y, iSkeletonBones2d[4].x, iSkeletonBones2d[4].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[4].x, iSkeletonBones2d[4].y, iSkeletonBones2d[5].x, iSkeletonBones2d[5].y, dwColor);
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[0].x, iSkeletonBones2d[0].y, iSkeletonBones2d[16].x, iSkeletonBones2d[16].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[16].x, iSkeletonBones2d[16].y, iSkeletonBones2d[17].x, iSkeletonBones2d[17].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[17].x, iSkeletonBones2d[17].y, iSkeletonBones2d[18].x, iSkeletonBones2d[18].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[18].x, iSkeletonBones2d[18].y, iSkeletonBones2d[19].x, iSkeletonBones2d[19].y, dwColor);
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[0].x, iSkeletonBones2d[0].y, iSkeletonBones2d[12].x, iSkeletonBones2d[12].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[12].x, iSkeletonBones2d[12].y, iSkeletonBones2d[13].x, iSkeletonBones2d[13].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[13].x, iSkeletonBones2d[13].y, iSkeletonBones2d[14].x, iSkeletonBones2d[14].y, dwColor); 
		fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[14].x, iSkeletonBones2d[14].y, iSkeletonBones2d[15].x, iSkeletonBones2d[15].y, dwColor);

		float eye_r = Distance2d(iSkeletonBones2d[21], iSkeletonBones2d[6]);
		float head_r = Distance2d(iSkeletonBones2d[8], iSkeletonBones2d[20]);
		//#include "SpriteBatch.h"
		/*std::unique_ptr<DirectX::SpriteBatch>   m_SpriteBatch = std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
		
		Vector4 screenPosition;
		GetBone(pClientSoldier, &screenPosition, UpdatePoseResultData::BONE_HEAD);
		ID3D11ShaderResourceView* m_Texture;

		float dist = Distance3d(pPlayer->GetClientSoldier()->m_pPredictedController->m_Position, pLocalSoldier->m_pPredictedController->m_Position);
		float Scale = 2 / dist;


		if (!m_SpriteBatch)
		{
			m_SpriteBatch = std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
			DirectX::CreateDDSTextureFromFile(DxRenderer::GetInstance()->m_pDevice, L"D:\\out\\pic.dds", nullptr, &m_Texture);
		}

		if (WorldToScreen(screenPosition, &(Vec2)screenPosition))
		{
			m_SpriteBatch->Begin();
			m_SpriteBatch->Draw(m_Texture, Vector2(screenPosition.x - 400 / 2 * Scale, screenPosition.y - 400 / 2 * Scale), nullptr, DirectX::Colors::White, 0.0f, Vector2(0.0f, 0.0f), Scale, DirectX::SpriteEffects::SpriteEffects_None, 0.0f);
			m_SpriteBatch->End();
		}*/



		fb::DebugRenderer2::Singleton()->cdrawCircle2d(iSkeletonBones2d[6].x, iSkeletonBones2d[6].y, eye_r, dwColor);
		fb::DebugRenderer2::Singleton()->cdrawCircle2d(iSkeletonBones2d[7].x, iSkeletonBones2d[7].y, eye_r, dwColor);

		fb::DebugRenderer2::Singleton()->cdrawCircle2d(iSkeletonBones2d[8].x, iSkeletonBones2d[8].y, head_r, dwColor);

		//fb::DebugRenderer2::Singleton()->cdrawCircle3d(iSkeletonBones3d[8], vDistance3d(iSkeletonBones3d[8], iSkeletonBones3d[20]), dwColor, 20);

		return true;
	}
	return false;
}




/********************************************************************************/
/*                   F : DrawBalloon (void)
/*******************************************************************************/
/*	+@type void
	+@arg1 = PTR* [pPlayer || NULL]
	+@arg2 = int r
	+@arg3 = int g
	+@arg4 = int b
	+@arg5 = int a
	+@arg6 = Vec3 (start)
	+@arg7 = Vec3 (end)
	+@return void
*******************************************************************************/
void DrawBalloon(ClientPlayer* pPlayer, int r, int g, int b, int a, Vec3 bgPosStart = (Vec3)0.0, Vec3 bgPosEnd = (Vec3)0.0)
{
	if (bgPosStart == (Vec3)0.0 && bgPosEnd == (Vec3)0.0){
		Vec3 vBallPos = pPlayer->m_pControlledControllable->m_pPredictedController->m_Position;
		Vec3 bgPosStart = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position;
		Vec3 bgPosEnd = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position;
	}

	bgPosEnd.y = bgPosEnd.y + 10;

	fb::DebugRenderer2::Singleton()->cdrawLine3d(bgPosStart, bgPosEnd, fb::Color32(r, g, b, a));
	fb::DebugRenderer2::Singleton()->cdrawSphere3d(bgPosEnd, 0.1f, fb::Color32(r, g, b, a), 20);
}

void DrawBalloon(int r, int g, int b, int a, Vec3 bgPosStart = (Vec3)0.0, Vec3 bgPosEnd = (Vec3)0.0)
{
	if (bgPosStart != (Vec3)0.0 && bgPosEnd != (Vec3)0.0){
		bgPosEnd.y = bgPosEnd.y + 10;

		fb::DebugRenderer2::Singleton()->cdrawLine3d(bgPosStart, bgPosEnd, fb::Color32(r, g, b, a));
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(bgPosEnd, 0.1f, fb::Color32(r, g, b, a), 20);
	}
}



/********************************************************************************/
/*                   F : ZoneDamage (void)
/*******************************************************************************/
/*	+@type void
	+@arg1 =DWORD_PTR*
	+@arg2 = PTR* Class [ClientExplosionPackEntity || CObjectEntry ]
	+@arg3 = PTR* Class ClientPlayer
	+@arg4 = int r
	+@arg5 = int g
	+@arg6 = int b
	+@arg7 = int a
	+@arg8 = Vec3 
	+@arg9 = float (radius)
	+@arg10 = count (i) instance player
	+@return void
*******************************************************************************/

void ZoneDamage(DWORD_PTR *entityObject, ClientExplosionPackEntity* entity, ClientPlayer* pPlayer, int r, int g, int b, int a, Vec3 bgPosStart = (Vec3)0.0, float radius = (float)3.0f, int i=0)
{

	wchar_t ouput[255];
	sphere* firstObj[200];
	if (IsValidPtrEh(entity)){

	//	const wchar_t* ptrExplosif = (const wchar_t*)&entity;
	//	wprintf(*ouput);
		swprintf(ouput, 100, L"ExplosionPackEntity = 0x%p", &*entityObject);

		//Color couleur = { 0.0, 1.0, 0.0, 0.5 };
		//couleur.RGBA()
		Matrix pWorld = pWorld.Identity();
		Matrix matrix = Matrix::CreateTranslation((Vector3)entity->m_position);
		Matrix scale = Matrix::CreateScale((Vector3)entity->m_position);
		Quaternion _rotationQ = Quaternion();
		Matrix rotation = Matrix::CreateFromQuaternion(_rotationQ);
		float local = matrix.Decompose((Vector3)entity->m_position, _rotationQ, (Vector3)entity->m_position);




	//	Matrix pWorld = pWorld.Identity();
	//	Vector3 Scale, Translation;
	//	Quaternion Rotation;
	//	matrix.mTransform.Decompose(Scale, rotation, Translation);

	//	Matrix local = pWorld * Matrix::CreateScale((Vec3)scale) * Matrix::CreateFromQuaternion((Vec3)scale) *Matrix::CreateTranslation(matrix);



		//create sphere
		firstObj[i] = new sphere(matrix, r, g, b, a, radius);
		firstObj[i]->drawwiresphere();
		
		//debug draw text
		/*
		if (worldToScreen2(bgPosStart, &bgPosStart))
		{
			tk::drawText(ouput, bgPosStart, r, g, b, a);
			//DrawText(pos.x, pos.y, "Vehicule");
			//fb::DebugRenderer2::Singleton()->drawText((int)bgPosStart.x, (int)bgPosStart.y, fb::Color32::Color32(r, g, b, a), output, (float)2);
		}*/
	}

}

void ZoneDamage(DWORD_PTR *entityObject, CObjectEntry* entity, ClientPlayer* pPlayer, int r, int g, int b, int a, Vec3 bgPosStart = (Vec3)0.0, float radius = (float)3.0f, int i = 0)
{

	wchar_t ouput[255];
	sphere* firstObj[200];
	if (IsValidPtrEh(entity)){

		//	const wchar_t* ptrExplosif = (const wchar_t*)&entity;
		//	wprintf(*ouput);
		swprintf(ouput, 100, L"ExplosionPackEntity = 0x%p", &*entityObject);

		//Color couleur = { 0.0, 1.0, 0.0, 0.5 };
		//couleur.RGBA()
		Matrix pWorld = pWorld.Identity();
		Matrix matrix = Matrix::CreateTranslation((Vector3)entity->m_position);
		Matrix scale = Matrix::CreateScale((Vector3)entity->m_position);
		Quaternion _rotationQ = Quaternion();
		Matrix rotation = Matrix::CreateFromQuaternion(_rotationQ);
		float local = matrix.Decompose((Vector3)entity->m_position, _rotationQ, (Vector3)entity->m_position);




		//	Matrix pWorld = pWorld.Identity();
		//	Vector3 Scale, Translation;
		//	Quaternion Rotation;
		//	matrix.mTransform.Decompose(Scale, rotation, Translation);

		//	Matrix local = pWorld * Matrix::CreateScale((Vec3)scale) * Matrix::CreateFromQuaternion((Vec3)scale) *Matrix::CreateTranslation(matrix);



		//create sphere
		firstObj[i] = new sphere(matrix, r, g, b, a, radius);
		firstObj[i]->drawwiresphere();


		if (worldToScreen2(bgPosStart, &bgPosStart))
		{
			tk::drawText(ouput, bgPosStart, r, g, b, a);
			//DrawText(pos.x, pos.y, "Vehicule");
			//fb::DebugRenderer2::Singleton()->drawText((int)bgPosStart.x, (int)bgPosStart.y, fb::Color32::Color32(r, g, b, a), output, (float)2);
		}
	}

}




/********************************************************************************/
/*                   F : bfIsInAxisAlignedBox (bool)
/*******************************************************************************/
/*	+@type bool
	+@arg1 = Vector4
	+@arg2 = PTR Class [AxisAlignedBox]
	+@arg3 = Matrix (M_Transform)
	+@arg4 = Vector4 (position)
	+@return bool
*******************************************************************************/

bool bfIsInAxisAlignedBox(Vector4 PointWorld, AxisAlignedBox Aabb, Matrix M_Transform, Vector4 Position)
{
	Aabb.min = DirectX::XMVector4Transform(Aabb.min, M_Transform);
	Aabb.max = DirectX::XMVector4Transform(Aabb.max, M_Transform);

	Aabb.min = Aabb.min + Position;
	Aabb.max = Aabb.max + Position;

	if (PointWorld.x >= Aabb.min.x  &&  PointWorld.x <= Aabb.max.x  &&
		PointWorld.y >= Aabb.min.y  &&  PointWorld.y <= Aabb.max.y  &&
		PointWorld.z >= Aabb.min.z  &&  PointWorld.z <= Aabb.max.z) return true;
	else
		return false;
}



/********************************************************************************/
/*                   F : DrawWorldObjects (bool)
/*******************************************************************************/
/*	+@type bool
	+@return bool
*******************************************************************************/





/********************************************************************************/
/*                   F : ESPColorimetrie void)
/*******************************************************************************/
/*	+@type void
	+@arg4 = PTR* class [ClientPlayer]
	+@return void
*******************************************************************************/

void ESPColorimetrie(ClientPlayer* pPlayer){
	//declaration des couleurs enemies:
	float Distance = GetDistance(pPlayer);

	if (!pPlayer->m_Visible) // enemy invisible?
	{
		if (Distance < 50.00){
			if (Distance <= 20){
				r = 242; g = 98; b = 16;  //orange brain
			}
			else{
				r = 255; g = 194; b = 102;  //orange clair
			}
		}
		else{
			if (Distance > 100.00){
				r = 254; g = 250; b = 205;  //yellow pale
			}
			else{
				r = 255; g = 223; b = 0;  //yellow
			}
		}
	}
	else // enemy visible
	{
		r = 255; g = 0; b = 0; //red              
	}
	//DrawBalloon(pPlayer, r, g, b, 255);
	//DrawBarHealt(pPlayer, r, g, b);
}



/********************************************************************************/
/*                   F : DrawCenterLine (void)
/*******************************************************************************/
/*	+@type void
	+@arg4 = PTR* class [ClientPlayer]
	+@return void
*******************************************************************************/

void DrawCenterLine(ClientPlayer* pPlayer){
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier)) return;
	ClientSoldierWeapon* pSoldierWeapon = pLocalSoldier->GetActiveWeapon();

	//pSoldierWeapon->m_authorativeAiming->m_RayEnd

	fb::DebugRenderer2::Singleton()->cdrawLine3d(pLocalSoldier->m_pPredictedController->m_Position, pPlayer->GetClientSoldier()->m_pPredictedController->m_Position, fb::Color32(r, g, b, 255));
	//fb::DebugRenderer2::Singleton()->drawLine2d(iSkeletonBones2d[0].x, iSkeletonBones2d[0].y, iSkeletonBones2d[1].x, iSkeletonBones2d[1].y, dwColor);
}



/********************************************************************************/
/*                   F : DrawCenterLine (void)
/*******************************************************************************/
/*	+@type void
+@arg4 = PTR* class [ClientPlayer]
+@return void
 +@goal = This is a function to simplify usage of sending keys 
/********************************************************************************/

void GenerateKey(int vk, BOOL bExtended) {

	KEYBDINPUT  kb = { 0 };
	INPUT       Input = { 0 };

	/* Generate a "key down" */
	if (bExtended) { kb.dwFlags = KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));

	/* Generate a "key up" */
	ZeroMemory(&kb, sizeof(KEYBDINPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	kb.dwFlags = KEYEVENTF_KEYUP;
	if (bExtended) { kb.dwFlags |= KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));

	return;
}



/********************************************************************************/
/*                   F : RayresultDebug3 (void)
/*******************************************************************************/
/*	+@type void
	+@return void
*******************************************************************************/
void RayresultDebug()
{
	if (!IsIamAlive()) return;

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	// get my position
	ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalPlayer)) return; // if no localplayer
	ClientSoldierEntity* pLocalSoldier = pLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.1f) return;


	ClientSoldierWeapon* pClientSoldierWeapon = pLocalSoldier->GetActiveWeapon();
	if (!IsValidPtr(pClientSoldierWeapon)) return;

	ClientWeapon* pClientWeapon = pClientSoldierWeapon->m_pWeapon;
	if (!IsValidPtr(pClientWeapon)) return;

	ClientSoldierAimingSimulation* pClientSoldierAimingSimulation = pClientSoldierWeapon->m_authorativeAiming;
	if (!IsValidPtr(pClientSoldierAimingSimulation)) return;

	if (!IsValidPtr((PVOID)pClientSoldierAimingSimulation->m_RayResult)) return;

	Tempclass* pTempclass = reinterpret_cast<Tempclass*>(pClientSoldierAimingSimulation->m_RayResult);
	if (!IsValidPtr(pTempclass)) return;
	TypeInfo* pTypeInfo = (TypeInfo*)pTempclass->GetType();
	if (!IsValidPtr(pTypeInfo)) return;
	MemberInfo::MemberInfoData* pMemberInfo = pTypeInfo->m_infoData;
	if (!IsValidPtr(pMemberInfo)) return;

	char TexteEntity[255];
	Vec2 Pos2d;
	sprintf_s(TexteEntity, "%p %s", pClientSoldierAimingSimulation->m_RayResult, pMemberInfo->m_name);

	if (WorldToScreen(pClientSoldierAimingSimulation->m_RayEnd, &Pos2d))
	{
		fb::DebugRenderer2::Singleton()->drawText((int)Pos2d.x, (int)Pos2d.y, fb::Color32(255, 0, 0, 200), TexteEntity, 1.0);
	}
}

void RayresultDebug2()
{
	if (!IsIamAlive()) return;


	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	// get my position
	ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalPlayer)) return; // if no localplayer
	ClientSoldierEntity* pLocalSoldier = pLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.1f) return;

	ClientSoldierWeaponsComponent* pClientSoldierWeaponsComponent = pLocalSoldier->m_soldierWeaponsComponent;
	if (!IsValidPtr(pClientSoldierWeaponsComponent)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pClientSoldierWeaponsComponent at 0x" << std::hex << pClientSoldierWeaponsComponent;


	ClientSoldierWeapon* pClientSoldierWeapon = pLocalSoldier->GetActiveWeapon();
	if (!IsValidPtr(pClientSoldierWeapon)) return;



	ClientWeapon* pClientWeapon = pClientSoldierWeapon->m_pWeapon;
	if (!IsValidPtr(pClientWeapon)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pClientWeapon at 0x" << std::hex << pClientWeapon;
	//EntryComponent* pPlayerEntryComponent = pLocalPlayer->GetEntryComponent();
	//if (!IsValidPtr(pPlayerEntryComponent)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pPlayerEntryComponent at 0x" << std::hex << pPlayerEntryComponent;

	ClientSoldierAimingSimulation* pClientSoldierAimingSimulation = pClientSoldierWeapon->m_authorativeAiming;
	if (!IsValidPtr(pClientSoldierAimingSimulation)) return;

	if (!IsValidPtr((PVOID)pClientSoldierAimingSimulation->m_RayResult)) return;

	Tempclass* pTempclass = reinterpret_cast<Tempclass*>(pClientSoldierAimingSimulation->m_RayResult);
	if (!IsValidPtr(pTempclass)) return;
	TypeInfo* pTypeInfo = (TypeInfo*)pTempclass->GetType();
	if (!IsValidPtr(pTypeInfo)) return;
	MemberInfo::MemberInfoData* pMemberInfo = pTypeInfo->m_infoData;
	if (!IsValidPtr(pMemberInfo)) return;

	char TexteEntity[255];
	Vec2 Pos2d;
	sprintf_s(TexteEntity, "%p %s", pClientSoldierAimingSimulation->m_RayResult, pMemberInfo->m_name);

	if (WorldToScreen(pClientSoldierAimingSimulation->m_RayEnd, &Pos2d))
	{
		fb::DebugRenderer2::Singleton()->drawText((int)Pos2d.x, (int)Pos2d.y, fb::Color32(255, 0, 0, 200), TexteEntity, 2.0);
	}


	///////
	if (strstr(pMemberInfo->m_name, "ClientVehicleEntity"))
	{
		FILE_LOG(logINFO) << "RayresultDebug";
		ClientVehicleEntity* pClientVehicleEntity = reinterpret_cast<ClientVehicleEntity*>(pClientSoldierAimingSimulation->m_RayResult);
		if (!IsValidPtr(pClientVehicleEntity)) return;

		DynamicPhysicsEntity* pDynamicPhysicsEntity = pClientVehicleEntity->m_pDynamicPhysicsEntity;
		if (!IsValidPtr(pDynamicPhysicsEntity)) return;

		Vector4 firsttransformpos;
		for (int BoneIndex = 0; BoneIndex < 70; BoneIndex++)
		{
			LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
			transform = transform + (BoneIndex);
			Vector4 transformpos = transform->m_trans;
			Vector4 forward = transform->m_forward;
			forward = transformpos + forward *5.0f;

			if (BoneIndex == 0) // n'utilise pas le premier point (position)
			{
				firsttransformpos = transformpos;
				continue;
			}
			if (vDistance3d(transformpos, firsttransformpos)<0.5f) continue;

			char Texte[255];
			Vec2 Pos2d;
			sprintf_s(Texte, "%2d", BoneIndex);

			if (WorldToScreen(transformpos, &Pos2d))
			{
				fb::DebugRenderer2::Singleton()->drawText((int)Pos2d.x, (int)Pos2d.y, fb::Color32(255, 0, 0, 200), Texte, 1.0);
				tk::cdrawLine3d(transformpos, forward, { 0.0, 1.0, 0.0, 0.2f });
			}
		}
	}
}

void RayresultDebug3()
{
	if (!IsIamAlive()) return;


	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	// get my position
	ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalPlayer)) return; // if no localplayer
	ClientSoldierEntity* pLocalSoldier = pLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.1f) return;

	ClientSoldierWeaponsComponent* pClientSoldierWeaponsComponent = pLocalSoldier->m_soldierWeaponsComponent;
	if (!IsValidPtr(pClientSoldierWeaponsComponent)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pClientSoldierWeaponsComponent at 0x" << std::hex << pClientSoldierWeaponsComponent;


	ClientSoldierWeapon* pClientSoldierWeapon = pLocalSoldier->GetActiveWeapon();
	if (!IsValidPtr(pClientSoldierWeapon)) return;



	ClientWeapon* pClientWeapon = pClientSoldierWeapon->m_pWeapon;
	if (!IsValidPtr(pClientWeapon)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pClientWeapon at 0x" << std::hex << pClientWeapon;
	//EntryComponent* pPlayerEntryComponent = pLocalPlayer->GetEntryComponent();
	//if (!IsValidPtr(pPlayerEntryComponent)) return;
	//FILE_LOG(logINFO) << "RayresultDebug pPlayerEntryComponent at 0x" << std::hex << pPlayerEntryComponent;

	ClientSoldierAimingSimulation* pClientSoldierAimingSimulation = pClientSoldierWeapon->m_authorativeAiming;
	if (!IsValidPtr(pClientSoldierAimingSimulation)) return;

	if (!IsValidPtr((PVOID)pClientSoldierAimingSimulation->m_RayResult)) return;

	Tempclass* pTempclass = reinterpret_cast<Tempclass*>(pClientSoldierAimingSimulation->m_RayResult);
	if (!IsValidPtr(pTempclass)) return;
	TypeInfo* pTypeInfo = (TypeInfo*)pTempclass->GetType();
	if (!IsValidPtr(pTypeInfo)) return;
	MemberInfo::MemberInfoData* pMemberInfo = pTypeInfo->m_infoData;
	if (!IsValidPtr(pMemberInfo)) return;


	if (strstr(pMemberInfo->m_name, "ClientStaticModelGroupEntity"))
	{
		EntityBusPeer* pTempclass = reinterpret_cast<EntityBusPeer*>(pClientSoldierAimingSimulation->m_RayResult);
		if (!IsValidPtr(pTempclass)) return;
		TypeInfo* pTypeInfo = (TypeInfo*)pTempclass->GetType();
		if (!IsValidPtr(pTypeInfo)) return;
		MemberInfo::MemberInfoData* pMemberInfo = pTypeInfo->m_infoData;
		if (!IsValidPtr(pMemberInfo)) return;
		char TexteEntity[255];
		Vec2 Pos2d;
		sprintf_s(TexteEntity, "%p %s", pClientSoldierAimingSimulation->m_RayResult, pMemberInfo->m_name);
		FILE_LOG(logINFO) << "PICKUP";

	}

	char TexteEntity[255];
	Vec2 Pos2d;
	sprintf_s(TexteEntity, "%p %s", pClientSoldierAimingSimulation->m_RayResult, pMemberInfo->m_name);
	

	if (WorldToScreen(pClientSoldierAimingSimulation->m_RayEnd, &Pos2d))
	{
		fb::DebugRenderer2::Singleton()->drawText((int)Pos2d.x, (int)Pos2d.y, fb::Color32(255, 0, 0, 200), TexteEntity, 2.0);
	}


	///////
	if (strstr(pMemberInfo->m_name, "ClientVehicleEntity"))
	{
		//FILE_LOG(logINFO) << "RayresultDebug";
		ClientVehicleEntity* pClientVehicleEntity = reinterpret_cast<ClientVehicleEntity*>(pClientSoldierAimingSimulation->m_RayResult);
		if (!IsValidPtr(pClientVehicleEntity)) return;

		DynamicPhysicsEntity* pDynamicPhysicsEntity = pClientVehicleEntity->m_pDynamicPhysicsEntity;
		if (!IsValidPtr(pDynamicPhysicsEntity)) return;

		Matrix m_Transform; pClientVehicleEntity->GetTransform(&m_Transform);
		Vector4 m_Position = m_Transform.Translation();

		tk::cdrawAabb3d(m_Position, pClientVehicleEntity->m_childrenAABB.min, pClientVehicleEntity->m_childrenAABB.max, m_Transform, { 1.0f, 0.0f, 0.0f, 1.0f });

		DirectX::BoundingBox box;


		Vector4 firsttransformpos = pDynamicPhysicsEntity->m_GameWorldTransformBase->m_trans;
		Vector4 lastseentransformpos;
		for (int BoneIndex = 0; BoneIndex < 200; BoneIndex++)
		{
			LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
			transform = transform + (BoneIndex);
			Vector4 transformpos = transform->m_trans;
			Vector4 forward = transform->m_forward;
			forward = transformpos + forward *5.0f;

			if (vDistance3d(transformpos, firsttransformpos)<0.5f) continue; // n'utilise pas le premier point (position)
			if (transformpos == lastseentransformpos) continue; // filtre les doublons
			lastseentransformpos = transformpos;

			if (bfIsInAxisAlignedBox(transformpos, pClientVehicleEntity->m_childrenAABB, m_Transform, m_Position)) continue;

			wchar_t Texte[255];
			Vec2 Pos2d = { 0, 0 };
			swprintf(Texte, 100, L"%2d", BoneIndex);

			if (WorldToScreen(transformpos, &Pos2d))
			{
				tk::drawText((int)Pos2d.x, (int)Pos2d.y, { 1.0, 1.0, 0.0, 0.2f }, Texte, 0.1f);
				if (BoneIndex == 84 || BoneIndex == 86 || BoneIndex == 88 || BoneIndex == 90 || BoneIndex == 92 || BoneIndex == 94 || BoneIndex == 96 || BoneIndex == 104 || BoneIndex == 105 || BoneIndex == 108 || BoneIndex == 109 || BoneIndex == 112 || BoneIndex == 114 || BoneIndex == 116){
					fb::DebugRenderer2::Singleton()->cdrawSphere3d(transformpos, 0.3f, fb::Color32(0, 255, 0, 255), 30);
				} else{
					if (BoneIndex == 101){
						sphere* firstObj;
						firstObj = new sphere(m_Transform, 100, 100, 255, 255, 1.0);
						firstObj->drawwiresphere();

					}
					else{
						tk::cdrawLine3d(transformpos, forward, { 0.0, 1.0, 0.0, 0.2f });
					}
					
				}
			}
		}
	}
}

void TestingStuffs()
{
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pClientCharacterEntity = (ClientCharacterEntity*)pLocalSoldier->m_pClientCharacterEntity;
	if (!IsValidPtr(pClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.01f) return;
	CharacterPhysicsEntity* pCharacterPhysicsEntity = (CharacterPhysicsEntity*)pClientCharacterEntity->GetPhysiscsEntity();
	if (!IsValidPtr(pCharacterPhysicsEntity)) return;

	if (!g_Keyb_VK_TAB) return;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// aabb soldats
	AxisAlignedBox &aabb = pCharacterPhysicsEntity->m_collisionShapes->m_aabbs[pCharacterPhysicsEntity->m_currentPose];

	Vector4 MyPos = DirectX::XMLoadFloat4(&pLocalSoldier->m_pPredictedController->m_Position);
	Matrix MyTransform; pLocalSoldier->GetTransform(&MyTransform);

	fb::DebugRenderer2::Singleton()->cdrawAabb3d(MyPos, DirectX::XMLoadFloat4(&aabb.min), DirectX::XMLoadFloat4(&aabb.max), MyTransform, fb::Color32(255, 0, 0, 200));

	if (g_Keyb_VK_UP)
	{
		FILE_LOG(logINFO) << "TestingStuffs: pClientCharacterEntity at 0x" << std::hex << pClientCharacterEntity;
		FILE_LOG(logINFO) << "TestingStuffs: pCharacterPhysicsEntity at 0x" << std::hex << pCharacterPhysicsEntity;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	ClientVehicleEntity* pClientVehicleEntity = pLocalClientPlayer->GetClientVehicleEntity();
	if (!IsValidPtr(pClientVehicleEntity)) return;

	DynamicPhysicsEntity* pDynamicPhysicsEntity = pClientVehicleEntity->m_pDynamicPhysicsEntity;

	AxisAlignedBox &aabbv = pDynamicPhysicsEntity->m_rbAabb;
	fb::DebugRenderer2::Singleton()->cdrawAabb3d(MyPos, DirectX::XMLoadFloat4(&aabbv.min), DirectX::XMLoadFloat4(&aabbv.max), MyTransform, fb::Color32(255, 255, 0, 200));

	if (g_Keyb_VK_UP)
	{
		FILE_LOG(logINFO) << "TestingStuffs: pDynamicPhysicsEntity at 0x" << std::hex << pDynamicPhysicsEntity << " nb count: " << pDynamicPhysicsEntity->bitCount;
	}

}

void testCamedraFirstPerson(ClientSoldierEntity* pLocalSoldier){
	// get current weapon 
	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return;
	FiringHolderData* tempclass = (FiringHolderData*)pWeaponFiring->m_pFiringHolderData;

	SoldierWeaponData* swd = (SoldierWeaponData*)(FiringHolderData*)pWeaponFiring->m_pFiringHolderData;

	FILE_LOG(logINFO) << "FIRSTCAMERA = 0x" << &swd;

}

void TestServerNewObjectStuff(){
	/*	if (!IsValidPtr(pPlayer) || pPlayer != pPlayerManager->m_pLocalPlayer) continue;*/
	/***********************************************************************************/

	/*		serventity* pserventity = serventity::GetInstance();

	if (!IsValidPtrEh(pserventity)) return;
	FILE_LOG(logINFO) << "AutoC4ESP: pserventity at 0x " << std::hex << pserventity;

	for (int j = 0; j < 250; j++)
	{
	servobj1* pservobj1 = &pserventity->debarray1[j];
	if (!IsValidPtrEh(pservobj1)) continue;
	FILE_LOG(logINFO) << std::hex << &pserventity->debarray2[j];


	Entity* pEntity = pservobj1->m_pEntity;
	if (!IsValidPtrEh(pEntity)) continue;


	DWORD64 ptrteteentity = *(DWORD64*)(pEntity);
	if (ptrteteentity <= g_dwBase) continue;
	if (ptrteteentity >= (g_dwBase + g_dwSize)) continue;

	TypeInfo* pTypeInfo = pEntity->GetType();
	if (!IsValidPtrEh(pTypeInfo)) continue;
	FILE_LOG(logINFO) << std::hex << pTypeInfo->m_infoData->m_name;
	if (strcmp(pTypeInfo->m_infoData->m_name, "ClientExplosionPackEntity") != 0) continue;

	ClientExplosionPackEntity* pClientExplosionPackEntity = (ClientExplosionPackEntity*)pEntity;
	if (!IsValidPtrEh(pClientExplosionPackEntity)) continue;
	//	FILE_LOG(logINFO) << "TEST TEST TEST " << std::hex << pEntity;

	Matrix matrix = Matrix::CreateTranslation((Vector3)pClientExplosionPackEntity->m_position);
	//Matrix matrix;
	//pEntity->GetTransform(matrix);
	ZoneDamage((DWORD_PTR*)&*pClientExplosionPackEntity, pClientExplosionPackEntity, pPlayer, 20, 100, 40, 255, pClientExplosionPackEntity->m_position, 3.0f);
	DrawBalloon(100, 210, 100, 255, pClientExplosionPackEntity->m_position, pClientExplosionPackEntity->m_position);
	}*/

	/***********************************************************************************/
}

void TestWeaponUnlock(ClientPlayer* csw){
	/*
	CustomizeCharacterData* CCD;
	GameComponentData gcd = &(SoldierAimingConstraintsData::DataContainer)csw->GetEntryComponent;*/
	//::ClientGameContext* g_pGameContext = (fb::ClientGameContext*) 0x23022E0;
	VeniceSoldierCustomizationAsset* vsca = (VeniceSoldierCustomizationAsset*)0x11C104E0;
	vsca->m_name = "Gameplay / Kits / CHAssault";
	vsca->m_UIHudIcon = UIHudIcon_KitAssault;
	vsca->m_LabelSid = "ID_M_ASSAULT";
	//vsca->m_VisualTable->
	
	CustomizationTable* m_visualTable = vsca->m_VisualTable;
	CustomizationTable* m_specialisationTable = vsca->m_SpecializationTable;
	
	
}

void testDrawBulletVehicle(){
	/*Matrix vehicleBulletMatrix;
	ObjectBlueprint* obp = (ObjectBlueprint*)0x9F650870;
	obp->m_Name = "Gameplay/Vehicles/VehicleProjectileShield/VehicleProjectileShield_24m";
	obp->m_Object->m_flags = 511870682;
	obp->GetTransform(&vehicleBulletMatrix);
	Vector4 voPosVehBullet = vehicleBulletMatrix.Translation();

	//ZoneDamage((DWORD_PTR*)&*obp, pClientExplosionPackEntity, pLocalClientPlayer, 140, 210, 100, 255, Entity->m_position, 3.0f, g_C4poses);
	DrawBalloon(140, 210, 100, 255, voPosVehBullet, voPosVehBullet);*/
}

void testDrawProjectileWeapon(){
	//MeshLodGroup* mlg = (MeshLodGroup*)0x
}

void testDrawSimpleTriangle(){
	ShaderGraph* sg = (ShaderGraph*)0x0DBE7AF0;
	FILE_LOG(logINFO) << "NAME1 = " << sg->m_Name;
	sg->m_Name = "Venice/Objects/SimpleTriangle/SimpleTriangleBase";
	FILE_LOG(logINFO) << "NAME2 = " << sg->m_Name;
	sg->m_MaxSubMaterialCount = 8;
	sg->m_GammaCorrectionEnable = true;
}

void testVehicle(){
/*	Matrix voTestVehicleMatrix;
	MeshLodGroup* mlg = (MeshLodGroup*)0x0000000;
	mlg->m_Lod1Distance = 30.0;
	mlg->m_Lod2Distance = 50.0;
	mlg->m_Lod3Distance = 80.0;
	mlg->m_Lod4Distance = 130.0;
	mlg->m_Lod5Distance = 200.0;
	mlg->m_Lod6Distance = 1025.0;
	mlg->m_ShadowDistance = 0.0;
	mlg->m_CullScreenArea = (float)0.00999999977648;
	mlg->m_RuntimeShortName = "Venice_Vehicle_Standard_Missiles";
	mlg->GetTransform(&voTestVehicleMatrix);
	Vec3 posVehicle = voTestVehicleMatrix.Translation();

	DrawBalloon(140, 210, 100, 255, posVehicle, posVehicle);*/
}


void testActionDefibrillatorSpeed(){
	/*ValueUnlockAsset* vua = (ValueUnlockAsset*)0x9C6FB1E0;
	vua->m_Name = "Gameplay/Gadgets/Defibrillator/CoopDefibrillatorSpeedModifier";
	vua->m_UnlockUserData = 0;
	vua->m_DebugUnlockId = "CoopDefibrillatorSpeedModifier";
	vua->m_Identifier = 2234929298;
	vua->m_UnlockScore = 0;
	vua->m_NextLevelUnlockAsset = 0;
	vua->m_AvailableForPlayer = UnlockAvailability_HumanPlayerOnly;
	vua->m_AutoAvailable = false;
	vua->m_HiddenInProgression = false;
	vua->m_UnlockValues.At(0);
	FloatUnlockValuePair* fuvp = (FloatUnlockValuePair*)0x9C6FB238;
	fuvp->m_Id = "DefibrillatorSpeed";
	fuvp->m_DefaultValue = 1.0;
	fuvp->m_UnlockedValue = 6.0;*/

}


void testNoRecoilling(){
	if (GetAsyncKeyState(0x51) & 1)//this is q
	{

		ClientGameContext* pGameContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGameContext))
			return;

		ClientPlayerManager* pPlayermanager = pGameContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayermanager))
			return;

		ClientPlayer* pClientPlayer = pPlayermanager->m_pLocalPlayer;
		if (!IsValidPtr(pClientPlayer))
			return;

		ClientSoldierEntity* ClientSoldier = pClientPlayer->GetClientSoldier();
		if (!IsValidPtr(ClientSoldier))
			return;

		if (!IsValidPtr(ClientSoldier) || !IsValidPtr(ClientSoldier->m_pPredictedController)) return;


		WeaponSway* pWeaponSway = ClientSoldier->getWeaponSway();
		if (!IsValidPtr(pWeaponSway)) return;

		if (ClientSoldier->m_soldierWeaponsComponent->m_activeSlot == 0 || ClientSoldier->m_soldierWeaponsComponent->m_activeSlot == 1)
		{
			GunSwayData* pGunSwayData = (GunSwayData*)pWeaponSway->GunSwayData;
			if (!IsValidPtr(pGunSwayData)) return;
			FILE_LOG(logINFO) << "GunSwayData: 0x" << std::hex << pGunSwayData;


			/*************/
			ClientSoldierWeaponsComponent * listWeapons = ClientSoldier->m_soldierWeaponsComponent;


			pGunSwayData->m_DeviationScaleFactorNoZoom = 0.0f;
			pGunSwayData->m_DeviationScaleFactorZoom = 0.0f;
			pGunSwayData->m_FirstShotRecoilMultiplier = 0.0f;
			pGunSwayData->m_GameplayDeviationScaleFactorNoZoom = 0.0f;
			pGunSwayData->m_GameplayDeviationScaleFactorZoom = 0.0f;
			pGunSwayData->m_ShootingRecoilDecreaseScale = 100.0f;



			Beep(500, 300);
		}
	}
}

/**************************************************************************************/


/*void DrawBarHealt(ClientPlayer* pPlayer, int r, int g, int b){
	Vec3 vBarHelt = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position;

	float w = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.w;

	FILE_LOG(logINFO) << "Player w : " << w << "\n";
	FILE_LOG(logINFO) << "Color g : " << g << "\n";
	FILE_LOG(logINFO) << "Color b : " << b << "\n";
	FILE_LOG(logINFO) << "Color a : " << a << "\n";
}*/



/*
void DrawCenterLine(ClientPlayer* pPlayer){
	//x + w / 2, y + h, 1, color

	Vec2 vposl, vposr;

	vposl.x = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.x + posl[0];
	vposl.y = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.y + posl[2];
	vposl.z = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.z + posl[1];
	vposr.x = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.x + posr[0];
	vposr.y = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.y + posr[2];
	vposr.z = pPlayer->GetClientSoldier()->m_pPredictedController->m_Position.z + posr[1];
}
*/



/************************************************************************************************/


	// utilise la liste des missiles
	void CheckForConceptFireCountermeasureNeeded2()
	{

		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pLocalClientPlayer)) return;
		ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();

		Matrix MyTransForm;
		pLocalSoldier->GetTransform(&MyTransForm);

		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (phkVeniceClientMissileEntityTAB[i] != 0)
			{
				VeniceClientMissileEntity* pVeniceClientMissileEntity = phkVeniceClientMissileEntityTAB[i];


				ExplosionPackOwner* plocMissilePackOwner = (ExplosionPackOwner*)pVeniceClientMissileEntity->pExplosionPackOwner;
				if (!IsValidPtrEh(plocMissilePackOwner)) continue;
				__int64 pvMissileClientPlayer = plocMissilePackOwner->ClientPlayerPlus8 - 0x8;
				ClientPlayer* pMissileClientPlayer = (ClientPlayer*)pvMissileClientPlayer;
				if (!IsValidPtrEh(pMissileClientPlayer)) continue;

				Matrix MissileTransForm;
				pVeniceClientMissileEntity->GetTransform(&MissileTransForm);
				Vec3 posMissile = MissileTransForm.Translation();

				DrawBalloon(10, 10, 10, 255, posMissile, posMissile);

				if (vDistance3d((Vector4)MyTransForm.Translation(), (Vector4)MissileTransForm.Translation()) < 15.0f)
				{
					g_pInputBuffersb[ConceptFireCountermeasure] = 1.0f;
					FILE_LOG(logINFO) << "CheckForConceptFireCountermeasureNeeded: pLocalSoldier: 0x" << std::hex << pLocalSoldier;
				}
			}
		}
	}


	// utilise la liste des missiles
	DWORD g_TimeSinceLasetVehicleCounterMesure = 0;
	void CheckForConceptFireCountermeasureNeeded()
	{
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pLocalClientPlayer)) return;
		ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
		if (!IsValidPtr(pLocalSoldier)) return;
		EntryComponent* pPlayerEntryComponent = (EntryComponent*)pLocalClientPlayer->GetEntryComponent();
		if (!IsValidPtr(pPlayerEntryComponent)) return;
		EntryComponentData* pPlayerEntryComponentData = (EntryComponentData*)pPlayerEntryComponent->GetEntryComponentData(); // PlayerEntryComponentData
		if (!IsValidPtr(pPlayerEntryComponentData)) return;
		if (!pLocalClientPlayer->InVehicle() || !pPlayerEntryComponentData->m_HudData.m_SeatType == EST_Driver) return; // uniquement conducteurs peuvent lancer contres mesures

		ClientVehicleEntity* pClientVehicleEntity = pLocalClientPlayer->GetClientVehicleEntity();
		if (!IsValidPtr(pClientVehicleEntity)) return;



		Matrix MyVehicleTransForm;
		pClientVehicleEntity->GetTransform(&MyVehicleTransForm);
		AxisAlignedBox MyVehicleAABB = pClientVehicleEntity->m_childrenAABB;
		Vector4 MyVehiclePosition = MyVehicleTransForm.Translation();
		//MyVehicleAABB.min = MyVehicleAABB.min*4.0f;
		//MyVehicleAABB.max = MyVehicleAABB.max*4.0f;

		//fb::DebugRenderer2::Singleton()->cdrawAabb3d((Vector4)MyVehicleTransForm.Translation(), MyVehicleAABB.min, MyVehicleAABB.max, MyVehicleTransForm, fb::Color32(255, 0, 0, 200));

		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (phkVeniceClientMissileEntityTAB[i] != 0)
			{
				VeniceClientMissileEntity* pVeniceClientMissileEntity = phkVeniceClientMissileEntityTAB[i];

				MissileEntityData* plocMissilePackOwner = (MissileEntityData*)pVeniceClientMissileEntity->pExplosionPackEntityData;
				//ExplosionPackOwner* plocMissilePackOwner = (ExplosionPackOwner*)pVeniceClientMissileEntity->pExplosionPackOwner;
				if (!IsValidPtr(plocMissilePackOwner)) continue;
				__int64 pvMissileClientPlayer = *plocMissilePackOwner->aGhostedProjectileEntityData - 0x8;
				ClientPlayer* pMissileClientPlayer = (ClientPlayer*)pvMissileClientPlayer;
				if (!IsValidPtr(pMissileClientPlayer)) continue;


				if (pMissileClientPlayer != pLocalClientPlayer && pMissileClientPlayer->m_teamId != pLocalClientPlayer->m_teamId)
				{
					Matrix MissileTransForm;
					pVeniceClientMissileEntity->GetTransform(&MissileTransForm);
					MissileEntityData* pMissileEntityData = (MissileEntityData*)pVeniceClientMissileEntity->GetData();
					//FILE_LOG(logINFO) << "CheckForConceptFireCountermeasureNeeded: pMissileEntityData: MaxSpeed :" << pMissileEntityData->m_MaxSpeed;
					// faudrait recuperer l'aabb du vehicle l'agrandir et faire un test de contenant 
					Vector4 EstimatedMissilePosIn2seconds = MissileTransForm.Translation() + (MissileTransForm.Forward() * (pMissileEntityData->m_MaxSpeed * 2.0f));
					if (bfIsInAxisAlignedBox(EstimatedMissilePosIn2seconds, MyVehicleAABB, MyVehicleTransForm, MyVehiclePosition))
					{
						if (GetTickCount() > g_TimeSinceLasetVehicleCounterMesure + 10000) // en vehicle ne lance les contres mesures que toutes les 10 secondes (a voir)
						{
							g_pInputBuffersa[ConceptFireCountermeasure] = 1.0f;
							g_TimeSinceLasetVehicleCounterMesure = GetTickCount();
							FILE_LOG(logINFO) << "CheckForConceptFireCountermeasureNeeded: pLocalSoldier: 0x" << std::hex << pLocalSoldier;
						}
					}
				}
			}
		}
	}


	void DrawMissiles()
{
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pLocalClientPlayer)) return;

		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (phkVeniceClientMissileEntityTAB[i] != 0)
			{
				VeniceClientMissileEntity* pVeniceClientMissileEntity = phkVeniceClientMissileEntityTAB[i];

				Matrix matrix;
				pVeniceClientMissileEntity->GetTransform(&matrix);
				Vec3 posMissile = matrix.Translation();

				if (pVeniceClientMissileEntity->m_teamId == pLocalClientPlayer->m_teamId){

					fb::DebugRenderer2::Singleton()->cdrawSphere3d(posMissile, 0.3f, fb::Color32(0, 255, 0, 255), 30);
				}
				else{
					fb::DebugRenderer2::Singleton()->cdrawSphere3d(posMissile, 0.3f, fb::Color32(174, 0, 0, 255), 30);
				}
				//tk::drawwiresphere(matrix, { 1.0, 0.0, 0.0, 0.5f }, 0.5f);
			}
		}
}

	void DrawBullets()
{
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pLocalClientPlayer)) return;

		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (phkVeniceClientBulletEntityTAB[i] != 0)
			{
				VeniceClientBulletEntity* pVeniceClientBulletEntity = (VeniceClientBulletEntity*)phkVeniceClientBulletEntityTAB[i];
				ClientBulletEntity* pClientBulletEntity = (ClientBulletEntity*)pVeniceClientBulletEntity;
				Matrix mbullet;
				pVeniceClientBulletEntity->GetTransform(&mbullet);
				Vec3 posBullet = mbullet.Translation();
				if (!sschamDelete)
					tk::DrawSphere(posBullet, { 1.0, 0.0, 0.0, 0.5f }, 0.5f);

			/*	FILE_LOG(logINFO) << " pPlayerManager = " << std::hex << &pPlayerManager;
				FILE_LOG(logINFO) << " pLOCALPLAYER = " << std::hex << &pLocalClientPlayer;
				FILE_LOG(logINFO) << " VENICEBULLET = " << std::hex << &pVeniceClientBulletEntity;
				FILE_LOG(logINFO) << "CLIENTBULLET = " << std::hex << &pClientBulletEntity;
				FILE_LOG(logINFO) << " BULLET TEAMID = " << pVeniceClientBulletEntity->m_teamId;
				FILE_LOG(logINFO) << "TEAMID LOCALPLAYER = " << pLocalClientPlayer->m_teamId;*/


				//		fb::DebugRenderer2::Singleton()->cdrawSphere3d(posBullet, 0.3f, fb::Color32(0, 255, 0, 255), 3);
				/*	else
						tk::drawwiresphere(mbullet, { 1.0, 0.0, 0.0, 0.5f }, 0.5f);*/
				//fb::DebugRenderer2::Singleton()->cdrawSphere3d(posBullet, 0.3f, fb::Color32(0, 255, 0, 255), 3);
			}
		}
}


void DrawExplosives()
{
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	FILE_LOG(logINFO) << "A:LOCAPLAYER = 0x" << std::hex << pLocalClientPlayer;
	FILE_LOG(logINFO) << "A:LOCAPLAYER TEAMID = " << pLocalClientPlayer->m_teamId;
	//pLocalClientPlayer->m_teamId = 1;
	for (int i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if (phkVeniceClientExplosionEntityTAB[i] != 0)
		{
			VeniceClientExplosionEntity* pVeniceClientExplosiveEntity = phkVeniceClientExplosionEntityTAB[i];
			Matrix matrix;
			FILE_LOG(logINFO) << "B:EXPLOSIVES = 0x" << std::hex << &phkVeniceClientExplosionEntityTAB[i];
			FILE_LOG(logINFO) << "B:EXPLOSIVES TEAMID = " << pVeniceClientExplosiveEntity->m_teamId;
			//pVeniceClientExplosiveEntity->m_teamId = pLocalClientPlayer->m_teamId;
			pVeniceClientExplosiveEntity->GetTransform(&matrix);
			Vec3 posExplosive = matrix.Translation();
			//FILE_LOG(logINFO) << "TEAMID Explosive = " << pVeniceClientExplosiveEntity->m_teamId;
			//FILE_LOG(logINFO) << "TEAMID LOCALPLAYER = " << pLocalClientPlayer->m_teamId;
				if (!sschamDelete)
					fb::DebugRenderer2::Singleton()->cdrawSphere3d(posExplosive, 0.3f, fb::Color32(0, 255, 0, 255), 30);
				//tk::drawwiresphere(matrix, { 1.0, 0.0, 0.0, 0.5f }, 0.5f);
		}
	}
}


void DrawVehicles(ClientPlayerManager* pPlayerManager, ClientPlayer* pEnnemie)
{
	if (!IsValidPtr(pEnnemie)) return;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (pLocalClientPlayer->m_teamId == pEnnemie->m_teamId) return;

	Vec3 posVehicle[64];
	for (int i = 0; i < MAX_VEHICLES; i++)
	{
		if (phkClientVehicleEntityTAB[i] != 0)
		{
			ClientVehicleEntity* pClientVehicleEntity = phkClientVehicleEntityTAB[i];
			Matrix matrix;
			pClientVehicleEntity->GetTransform(&matrix);
			posVehicle[i] = (Vec3)matrix.Translation();




			chams* onVehicleCham = new chams(pPlayerManager, PlayerInLiveOnMap, IsIamAlive());
			if (IsValidPtrEh(pClientVehicleEntity))

				if ((int)pClientVehicleEntity->presenceInsideVehicle != 0 && !sschamDelete && !gameEnd){
					//FILE_LOG(logINFO) << "ESP CHAM on";
					onVehicleCham->OnVehicleChams(pClientVehicleEntity, pEnnemie);
					//DrawBalloon(10, 10, 10, 255, posVehicle[i], posVehicle[i]);
				}
				else{
					//FILE_LOG(logINFO) << "ESP CHAM off";
					onVehicleCham->OffVehicleChams(pClientVehicleEntity);
				}
			/*pClientVehicleEntity->orange = 1;
			*(BYTE *)((DWORD_PTR)pClientVehicleEntity + 0x1A) = 159;*/
			//pClientVehicleEntity->chamHideBehind2Walls = 159;
			//FILE_LOG(logINFO) << "VEHICLE" << i;
			//if (pClientVehicleEntity->m_teamId == pLocalClientPlayer->m_teamId)
			//FILE_LOG(logINFO) << "PLAYERINSIDEVEHICLE = " << (int)pClientVehicleEntity->presenceInsideVehicle;
			//	tk::drawwiresphere(matrix, { 2.0, 1.0, 1.0, 0.5f }, 0.5f);
			/*else
				tk::drawwiresphere(matrix, { 1.0, 0.0, 0.0, 0.5f }, 0.5f);*/
		}
	}
}



#define CLASSINFO_CLIENTSOLDIERENTITY			0x142809EC0 // fb::ClassInfo<fb::ClientSoldierEntity>
#define CLASSINFO_CLIENTVEHICLEENTITY			0x1427BB6B0 // fb::ClassInfo<fb::ClientVehicleEntity>
#define CLASSINFO_CLIENTGRENADEENTITY			0x14280BD90 // fb::ClassInfo<fb::ClientGrenadeEntity>
#define CLASSINFO_CLIENTEXPLOSIONENTITY			0x14280BED0 // fb::ClassInfo<fb::ClientExplosionPackEntity>
#define CLASSINFO_CLIENTPICKUPENTITY			0x14280A140 // fb::ClassInfo<fb::ClientPickupEntity>
#define CLASSINFO_CLIENTINTERATIONENTITY		0x142745E90 // fb::ClassInfo<fb::ClientInteractionEntity>

void DrawAllExplosives(){
	/*EntityIterator<ClientExplosionPackEntity> explosives(pLevel->m_pGameWorld, CLASSINFO_CLIENTEXPLOSIONENTITY);

	if (explosives.front())
	{
		do
		{
			ClientExplosionPackEntity* pExplosive = explosives.front()->getObject();

			Matrix transform;
			pExplosive->GetTransform(&transform);

			Vec2 screen;
			Vector4 position = transform.Translation();

			if (WorldToScreen(position, &screen))
			{
				fb::DebugRenderer2::Singleton()->drawText(screen.x, screen.y, 0xFFFF00FF, "Explosive [%I64X]", 2);
			}
		} while (explosives.next());
	}*/
}

void Esp()
{
	//FILE_LOG(logINFO) << "CHAM = " << sschamDelete;
	/*GenerateShader(DxRenderer::GetInstance()->m_pDevice, &psRed, 1.0f, 0.0f, 0.0f);*/
	
	if (!IsIamAlive()) return;
	/***********************************************************************************/
	//soldierC4dLancer();
	
	//testNoRecoilling();
	//DrawBullets();

/*	Vector4 cpos = { 41.19f, 136.87f, -143.08f, 0.0f };
	fb::DebugRenderer2::Singleton()->cdrawSphere3d(cpos, 0.3f, fb::Color32(0, 255, 0, 255), 30);
	fb::DebugRenderer2::Singleton()->cdrawSphere3d(gmRayHit.m_position, 0.3f, fb::Color32(100, 50, 100, 255), 30);
	char debugtext[255];
	sprintf_s(debugtext, "visible : %1d", gmRayHitresult);
	fb::DebugRenderer2::Singleton()->drawText(0, 100, fb::Color32(50, 50, 100, 255), debugtext, (float)1.0);
	sprintf_s(debugtext, "rigidbody : %x", gmRayHit.m_rigidBody);
	fb::DebugRenderer2::Singleton()->drawText(0, 150, fb::Color32(50, 50, 100, 255), debugtext, (float)1.0);
	sprintf_s(debugtext, "lambda : %4.4f", gmRayHit.m_lambda);
	fb::DebugRenderer2::Singleton()->drawText(0, 200, fb::Color32(50, 50, 100, 255), debugtext, (float)1.0);
	sprintf_s(debugtext, "material : %4d", gmRayHit.m_material);
	fb::DebugRenderer2::Singleton()->drawText(0, 250, fb::Color32(50, 50, 100, 255), debugtext, (float)1.0);
	sprintf_s(debugtext, "part : %4d", gmRayHit.m_part);
	fb::DebugRenderer2::Singleton()->drawText(200, 300, fb::Color32(50, 50, 100, 255), debugtext, (float)1.0);
*/

		/*DrawMissiles();*/

		/*DrawBullets();*/

	if (GetAsyncKeyState(VK_F12)){
		/*FILE_LOG(logINFO) << "pSoldier " << std::hex << pSoldier;*/
		//TestWeaponUnlock(pPlayer);
		//testDrawBulletVehicle();
		//testDrawSimpleTriangle();
		//testVehicle();
		//TestInput();

	}
	
	//CheckForConceptFireCountermeasureNeeded();
	/***********************************************************************************/

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;

	if (g_Keyb_VK_UP) std::string name = GetVehicleName(pPlayerManager->m_pLocalPlayer->GetClientVehicleEntity());
	//fb::DebugRenderer2::Singleton()->drawText(100, 100, fb::Color32(255, 255, 255, 255), (char*)name.c_str(), 1.0f);
	//FILE_LOG(logINFO) << "TSETE AVANT";
	//FILE_LOG(logINFO) << "<<<<";
	//DrawWorldObjects();
	//RayresultDebug2();
	//RayresultDebug3();
	//RayresultDebug();
	//FILE_LOG(logINFO) << ">>>>";
	//ObjectIteration(pPlayerManager->m_pLocalPlayer, pPlayerManager->m_pLocalPlayer->GetClientSoldier());
	//FILE_LOG(logINFO) << "TSETE APRES";
	//SettingsStuffs();
	//TestingStuffs();
	int numPlayersInLiveOnMap = GetPlayerInLiveOnMap(pPlayerManager);

	for (unsigned int i = 0; i < pPlayerManager->m_maxPlayerCount; i++)
	{


		ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(i);


		if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) continue; // if no player or player is me
		//	DrawVehicles(pPlayerManager, pPlayer);

		ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
		if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) continue;

		
		ClientCharacterEntity* pEnemyClientCharacterEntity = (ClientCharacterEntity*)pPlayer->GetCharacterEntity();
		if (!IsValidPtr(pEnemyClientCharacterEntity)) continue;

		if (pSoldier->m_pHealthComponent->m_Health <= 0.01f) continue;


		//if (g_Keyb_VK_TAB) forceBoneUpdate(pSoldier);


		if (pPlayer->m_teamId != pPlayerManager->m_pLocalPlayer->m_teamId){

			/*if (init_chams){
				chams* activechams = new chams(true, pSoldier);
			}
			else{
				chams* unchams = new chams(false, pSoldier);
			}*/

			//si l'ennemie est mort desactivation du chams
		/*	if (!IsPlayerAliveAndNotMe(i))
			chams* unchams = new chams(false, pSoldier);*/

		/*	char sPlayerName[512];
			Matrix moPlayerTransform;
			pSoldier->GetTransform(&moPlayerTransform);
			Vector4 voPlayerPosition = moPlayerTransform.Translation();

			float dist = Distance3d(pPlayer->GetClientSoldier()->m_pPredictedController->m_Position, pPlayerManager->m_pLocalPlayer->GetClientSoldier()->m_pPredictedController->m_Position);
			float Scale = 250 / dist;*/
			//pPlayer->m_onlineId.m_nativeData

			//FILE_LOG(logINFO) << "<< NOM DE LA CLASSE ===== " << pSoldier->GetData()->getType()->m_infoData->m_name;
		/*	FILE_LOG(logINFO) << "<< getId ===== " << pPlayer->getId();
			FILE_LOG(logINFO) << "<< i ===== " << pPlayer->m_ConnectionId;*/
			



			//CHAMS ACTIVATION SOLDIER HERE
		/*	chams* ChamSoldierEntity = new chams(pPlayerManager, pPlayerManager->m_maxPlayerCount, IsIamAlive());
			ChamSoldierEntity->displaySoldierCham(i, pPlayer, pSoldier);*/

			//
			

			ESPColorimetrie(pPlayer);
			DrawSoldierSkeleton(pSoldier, fb::Color32(r, g, b, 255));
			DrawCenterLine(pPlayer);
		}

		if (pPlayerManager->m_pLocalPlayer->m_teamId == pPlayerManager->GetPlayerById(i)->m_teamId) continue; // ne gere que les enemis

		if (pSoldier->isVisible() || pPlayerManager->GetPlayerById(i)->InVehicle()) // a voir parfois (jeep heli les bones sont actives alors que occluded)
		{
			if (aimbotData.enemyChoosenID == i)
			{

				// Vector Ligne de visé pointe l'ennemie
				/* TODO */
				//r, g, b, 35


				DrawSoldierSkeleton(pSoldier, fb::Color32(106, 213, 146, 255));
				int x = g_dwFrames % 3;
					if (x == 1){
						//color ROSE
						DrawSoldierSkeleton(pSoldier, fb::Color32(106, 213, 146, 255));
					}
			
			//	FILE_LOG(logINFO) << "VIE = " << pSoldier->m_pHealthComponent->m_Health;


				fb::DebugRenderer2::Singleton()->drawLine2d(aimbotData.bonePos2d.x, aimbotData.bonePos2d.y, aimbotData.boneCorrectedPos2d.x, aimbotData.boneCorrectedPos2d.y, fb::Color32(255, 0, 0, 200));
				fb::DebugRenderer2::Singleton()->cdrawCircle2d(aimbotData.boneCorrectedPos2d.x, aimbotData.boneCorrectedPos2d.y, 3.0, fb::Color32(255, 0, 0, 255));
			}
			else
			{
				DrawSoldierSkeleton(pSoldier, fb::Color32(r, g, b, 255));
			}
		}


		if (!pPlayerManager->GetPlayerById(i)->InVehicle()) continue;

		ClientVehicleEntity* pVehicle = pPlayer->GetClientVehicleEntity();
		if (!IsValidPtr(pVehicle)) continue;

		EntryComponent* pPlayerEntryComponent = pPlayerManager->GetPlayerById(i)->GetEntryComponent();
		if (!IsValidPtr(pPlayerEntryComponent)) continue;
		EntryComponentData* pPlayerEntryComponentData = (EntryComponentData*)pPlayerEntryComponent->GetEntryComponentData(); // PlayerEntryComponentData
		if (!IsValidPtr(pPlayerEntryComponentData)) continue;
		/*if (g_Keyb_VK_TAB) FILE_LOG(logINFO) << "Esp: pEntryComponent at 0x" << std::hex << pPlayerEntryComponent;
		if (g_Keyb_VK_TAB) FILE_LOG(logINFO) << "Esp: pEntryComponentData at 0x" << std::hex << pPlayerEntryComponentData;*/

		if (pPlayerEntryComponentData->m_IsShielded)
		{
			if (aimbotData.PlayersRayInfo[i].is_vehicle_ray_visible == true){
				DrawVehicleAABB(pVehicle, fb::Color32(255, 123, 41, 255));
			}
			else{
				DrawVehicleAABB(pVehicle, fb::Color32(184, 117, 88, 255));
			}
		}
		else
		{
			if (aimbotData.PlayersRayInfo[i].is_vehicle_ray_visible == true && vehicleChamState[i]){
				DrawVehicleAABB(pVehicle, fb::Color32(255, 0, 0, 255));
			}
			else{
				DrawVehicleAABB(pVehicle, fb::Color32(r, g, b, 255));
			}
		}

	}
	// Print Name
	//printf("Player[%d]=%s\n", i, pPlayer->szName);
}

/*

void TestInput()
{
	Main* pMain = Main::GetInstance();

	if (!pMain)
		return;

	Client* pClient = pMain->m_pClient;

	if (!pClient)
		return;

	BorderInputNode* pBorderInputNode = pClient->m_pBorderInputNode;

	if (!pBorderInputNode)
		return;

	Mouse* pMouse = pBorderInputNode->m_pMouse;

	// Move cursor 500 pixels to rotate tank turret

	pMouse->m_pDevice->m_Buffer.x = 500;

	// Fire weapon

	pMouse->m_pDevice->m_Buffer.buttons[InputDeviceMouseButtons::IDB_Button_0] = 1;

	Keyboard* pKeyboard = pBorderInputNode->m_pKeyboard;

	// Drive forward

	pKeyboard->m_pDevice->m_Buffer[InputDeviceKeys::IDK_W] = 1;
}

*/

void DrawRotated2dTriangle(float x, float y, float Scale, float Yaw, fb::Color32 dwColor)
{
	Vector2 t1 = { 0.0f, 100.0f };
	Vector2 t2 = { 100.0f, -100.0f };
	Vector2 t3 = { -100.0f, -100.0f };
	Vector2 t4 = { -0.0f, -50.0f };

	Matrix rMatrix=Matrix::CreateFromYawPitchRoll(0,0,Yaw);

	t1 = Vector2::Transform(t1, rMatrix)*Scale + Vector2{ x, y };
	t2 = Vector2::Transform(t2, rMatrix)*Scale + Vector2{ x, y };
	t3 = Vector2::Transform(t3, rMatrix)*Scale + Vector2{ x, y };
	t4 = Vector2::Transform(t4, rMatrix)*Scale + Vector2{ x, y };

	fb::DebugRenderer2::Singleton()->drawLine2d(t1.x, t1.y, t2.x, t2.y, dwColor);
	fb::DebugRenderer2::Singleton()->drawLine2d(t1.x, t1.y, t3.x, t3.y, dwColor);
	fb::DebugRenderer2::Singleton()->drawLine2d(t3.x, t3.y, t4.x, t4.y, dwColor);
	fb::DebugRenderer2::Singleton()->drawLine2d(t4.x, t4.y, t2.x, t2.y, dwColor);
}


fb::Color32 CorrectDistanceColor(fb::Color32 indwColor, Vector3 vFrom, Vector3 vTo)
{
	return indwColor;
}


void Minimap()
{
	if (!IsIamAlive()) return;

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	// get my position
	ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalPlayer)) return; // if no localplayer
	//DrawMissiles(pLocalPlayer);
	ClientSoldierEntity* pLocalSoldier = pLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.1f) return;

	// trouve l'angle de vue
	Matrix mLocalPlayerTransform;
	pLocalSoldier->GetTransform(&mLocalPlayerTransform);
	Vector4 vLocalPlayerPosition = mLocalPlayerTransform.Translation();


	if (pLocalPlayer->InVehicle())
	{
		//FILE_LOG(logINFO) << "pLocalPlayer = 0x" << std::hex << &pLocalPlayer;
		//FILE_LOG(logINFO) << "pLocalPlayer->GetClientVehicleEntity() = 0x" << std::hex << pLocalPlayer->GetClientVehicleEntity();
		GameRenderer* pGameRenderer = GameRenderer::GetInstance();
		if (!IsValidPtr(pGameRenderer)) return;
		mLocalPlayerTransform = pGameRenderer->m_pRenderView->m_viewMatrix;

	}

	float mYaw, mPitch, mRoll;
	MatrixToAngles(mLocalPlayerTransform, &mYaw, &mPitch, &mRoll);

	if (pLocalPlayer->InVehicle())
	{
		mYaw = -mYaw + DirectX::XM_PI;
	}

	//char debugbuff[255];
	///sprintf_s(debugbuff, "Yaw:%2.2f Pitch:%2.2f Roll:%2.2f", mYaw,mPitch,mRoll);
	//fb::DebugRenderer2::Singleton()->drawText(5, 5, fb::Color32(255, 0, 0, 0), debugbuff, 1);


	//mYaw = DirectX::XMScalarModAngle(mYaw);
	//mYaw = mYaw - DirectX::XM_PI / 8.0;

	//DrawRotated2dTriangle(100, 100, 0.2f, mYaw, fb::Color32(0, 255, 255, 255));

	for (unsigned int i = 0; i < pPlayerManager->m_maxPlayerCount; i++)
	{
		// get others players positions
		ClientPlayer* poPlayer = pPlayerManager->GetPlayerById(i);
		if (!IsValidPtr(poPlayer)) continue; //|| poPlayer == pPlayerManager->m_pLocalPlayer) continue; // if no player or player is me
		ClientSoldierEntity* poSoldier = poPlayer->GetClientSoldier();
		if (!IsValidPtr(poSoldier) || !IsValidPtr(poSoldier->m_pPredictedController)) continue;
		ClientCharacterEntity* pEnemyClientCharacterEntity = (ClientCharacterEntity*)poPlayer->GetCharacterEntity();
		if (!IsValidPtr(pEnemyClientCharacterEntity)) continue;
		if (poSoldier->m_pHealthComponent->m_Health <= 0.1f) continue;



		Matrix moPlayerTransform;
		poSoldier->GetTransform(&moPlayerTransform);
		Vector4 voPlayerPosition = moPlayerTransform.Translation();

		float r_1 = vLocalPlayerPosition.z - voPlayerPosition.z;
		float r_2 = vLocalPlayerPosition.x - voPlayerPosition.x;

		float x_1 = r_2 * cos(-mYaw) - r_1 * sin(-mYaw);
		float y_1 = r_2 * sin(-mYaw) + r_1 * cos(-mYaw);

		x_1 *= 1.4f;//2.6f; //1.4f
		x_1 += 325; //milieu de la minicarte en pixels

		y_1 *= 1.4f;
		y_1 += 834; // milieu de la minicarte en pixels

		float tScale = 0.07f; // taille de base de la fleche

		if (x_1 <= 187) { x_1 = 187; tScale = tScale / 4; }
		if (x_1 >= 454) { x_1 = 454;  tScale = tScale / 4; }
		if (y_1 <= 702) { y_1 = 702;  tScale = tScale / 4; }
		if (y_1 >= 962) { y_1 = 962;  tScale = tScale / 4; }

		// angle relatifs / aux autres angles des joueurs 
		float moYaw, moPitch, moRoll;
		MatrixToAngles(moPlayerTransform, &moYaw, &moPitch, &moRoll);
		float mrYaw = moYaw - mYaw; // angle relatif


		if (pPlayerManager->m_pLocalPlayer->m_teamId == pPlayerManager->GetPlayerById(i)->m_teamId)
		{
			DrawRotated2dTriangle(x_1, y_1, tScale, mrYaw + DirectX::XM_PI, fb::Color32(162, 195, 147, 255));
		}
		else
		{
			if (voPlayerPosition.y > vLocalPlayerPosition.y + 2.0f) // above: blue
			{
				DrawRotated2dTriangle(x_1, y_1, tScale, mrYaw + DirectX::XM_PI, fb::Color32(237, 226, 222, 255));
			}
			else if (voPlayerPosition.y < vLocalPlayerPosition.y - 2.0f) // below: yellow
			{
				DrawRotated2dTriangle(x_1, y_1, tScale, mrYaw + DirectX::XM_PI, fb::Color32(138, 90, 72, 255));
			}
			else // same floor: red
			{
				DrawRotated2dTriangle(x_1, y_1, tScale, mrYaw + DirectX::XM_PI, fb::Color32(207, 175, 163, 255));
			}

		}

	}


}


void DrawCrossHair(DxRenderer* dxRenderer, bool state){
	if (state == true){
		int ww = dxRenderer->GetInstance()->m_pScreen->m_WindowWidth;
		int wh = dxRenderer->GetInstance()->m_pScreen->m_WindowHeight;
		unsigned int ch = dxRenderer->GetInstance()->m_pScreen->m_Height;
		unsigned int cw = dxRenderer->GetInstance()->m_pScreen->m_Width;

		float x = ((float)ww / 2) - 22;
		float y = ((float)wh / 2);
		float xx = ((float)ww / 2) + 22;
		float yy = ((float)wh / 2);
		float x1 = ((float)ww / 2);
		float y1 = ((float)wh / 2) - 22;
		float xx1 = ((float)ww / 2);
		float yy1 = ((float)wh / 2) + 22;

		//Draw Crosshair
		/*fb::DebugRenderer2::Singleton()->drawLine2d(hWidth - 1, hHeight - 5, hWidth + 1, hHeight + 5, fb::Color32(255, 255, 255, 255));
		fb::DebugRenderer2::Singleton()->drawLine2d(hWidth - 5, hHeight - 1, hWidth + 5, hHeight + 1, fb::Color32(255, 255, 255, 255));
		*/
		fb::DebugRenderer2::Singleton()->drawLine2d(x, y, xx, yy, fb::Color32(255, 255, 255, 255));
		fb::DebugRenderer2::Singleton()->drawLine2d(x1, y1, xx1, yy1, fb::Color32(255, 255, 255, 255));


		/*DrawFilledBox(WINDOW.width / 2 - 22, WINDOW.height / 2, 44, 1, COLORS::YELLOW);
		DrawFilledBox(WINDOW.width / 2, WINDOW.height / 2 - 22, 1, 44, COLORS::YELLOW);*/
	}
}


void DrawTrailPoint()
{
	if (!IsIamAlive()) return;

	if (g_TrailPointResult.TrailPointToDraw == true)
	{
		fb::DebugRenderer2::Singleton()->cdrawSphere3d(g_TrailPointResult.TrailPosition, 0.3f, fb::Color32(0, 255, 0, 255), 30);
		if (g_TrailPointResult.isValidPlayer == true)
		{
			fb::DebugRenderer2::Singleton()->cdrawSphere3d(g_TrailPointResult.TrailPosition, 1.0f, fb::Color32(255, 0, 0, 255), 30);
		}

	}

}


void SettingsStuffs()
{
	DebugRenderSettings* pDebugRenderSettings = DebugRenderSettings::Singleton();
	if (!IsValidPtr(pDebugRenderSettings)) return;
	EnlightenRuntimeSettings* pEnlightenRuntimeSettings = EnlightenRuntimeSettings::Singleton();
	if (!IsValidPtr(pEnlightenRuntimeSettings)) return;
	if (g_Keyb_VK_UP)
	{
		pDebugRenderSettings->m_DrawStatsEnable = true;
		pDebugRenderSettings->m_DxLine2dAntialiasingEnable = true;

		pEnlightenRuntimeSettings->m_DrawDebugEntities = true;
		pEnlightenRuntimeSettings->m_DrawDebugLightProbes = true;
		pEnlightenRuntimeSettings->m_Enable = true;
	}
	if (g_Keyb_VK_DOWN)
	{
		pDebugRenderSettings->m_DrawStatsEnable = false;
		pDebugRenderSettings->m_DxLine2dAntialiasingEnable = false;

		pEnlightenRuntimeSettings->m_DrawDebugEntities = false;
		pEnlightenRuntimeSettings->m_DrawDebugLightProbes = false;
		pEnlightenRuntimeSettings->m_Enable = false;
	}
}

/*Vec3 MakeForwardVector(float yaw, float pitch)
{
	static float sp, sy, cp, cy, cpi = (DirectX::XM_PI * 2 / 360);
	float angle;
	Vec3 vForward;

	angle = pitch * cpi;
	sy = sin(angle);
	cy = cos(angle);
	angle = yaw * cpi;
	sp = sin(angle);
	cp = cos(angle);

	vForward.x = cp*cy;
	vForward.y = cp*sy;
	vForward.z = -sp;

	return vForward;
}
/*
std::vector<Vec3> PathFinding(Vec3 vFrom, Vec3 vTo)
{
	std::vector<Vec3> steps;

	const int StepDistance = 5;
	Vec3 vCurrent = vFrom;
	Vec3 vDiff = vTo - vFrom;
	vDiff.Normalize();
	float yawToTarget = -atan2(vDiff.x, vDiff.z);
	float pitchToTarget = atan2(vDiff.y, sqrt(vDiff.x * vDiff.x + vDiff.z * vDiff.z));
	Vec3 vForward = MakeForwardVector(yawToTarget, pitchToTarget);
	vForward.Normalize();
	Vec3 vTemp;
	int iteration = 0;

	//Firstly init our variables
	float dist = Distance3d(vTo, vFrom);
	bool &visible();
	if (IsVisible(vFrom, vTo, visible()))
	{
		steps.push_back(vTo);
		return steps;
	}
	else
	{
		while (vCurrent != vTo || iteration > 1000)
		{
			vTemp = (vCurrent + vForward * StepDistance);
			if (IsVisible(&vTemp, &vTo))
			{
				vCurrent = vTemp;
				steps.push_back(vCurrent);
			}
			else
			{
				Vec3 vLeft = MakeForwardVector(yawToTarget + DirectX::XM_PI / 2, pitchToTarget);
				vTemp = (vCurrent + vLeft * StepDistance);
				if (IsVisible(&vTemp, &vTo))
				{
					vCurrent = vTemp;
					steps.push_back(vCurrent);
					continue;
				}

				Vec3 vRight = MakeForwardVector(yawToTarget - DirectX::XM_PI / 2, pitchToTarget);
				vTemp = (vCurrent + vRight * StepDistance);
				if (IsVisible(&vTemp, &vTo))
				{
					vCurrent = vTemp;
					steps.push_back(vCurrent);
					continue;
				}
			}
			iteration++;
		}

		return steps;
	}

}
*/
