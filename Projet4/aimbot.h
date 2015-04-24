float g_pInputBuffers[123];//input buffer


class PlayerCache
{
public:
	ClientPlayer* ClientPlayer;
	ClientSoldierEntity* ClientSoldierEntity;
	ClientVehicleEntity* ClientVehicleEntity;
	int FoundSoldierBoneIndex = -1;
	int FoundVehicleBoneIndex = -1;
	bool isVisibleVehicle;
	bool isVisibleSoldier;
	DWORD dwGetTickCount = 0;
};

PlayerCache g_PlayersCache[70];


bool IsRayVisible(Vector4 From, Vector4 To, Vector4 *returnedEndRayPos)
{
	ClientGameContext* pClientGameContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pClientGameContext)) return false;

	HavokPhysicsManager* pHavokPhysicsManager = pClientGameContext->m_pPhysicsManager;
	if (!IsValidPtr(pHavokPhysicsManager)) return false;

	GameWorld* pGameWorld = pHavokPhysicsManager->m_GameWorld;
	if (!IsValidPtr(pGameWorld)) return false;

	IPhysicsRayCaster* pIPhysicsRayCaster = pGameWorld->m_RayCaster;
	if (!IsValidPtr(pIPhysicsRayCaster)) return false;

	__declspec(align(16)) Vector4 fFrom = From;
	__declspec(align(16)) Vector4 fTo = To;


	RayCastHit mRayHit;
	bool visible = false;
	visible = !pIPhysicsRayCaster->PhysicsRayQuery("OnGroundState::update", &fFrom, &fTo, &mRayHit, IPhysicsRayCaster::DontCheckCharacter | IPhysicsRayCaster::DontCheckRagdoll | IPhysicsRayCaster::DontCheckPhantoms | IPhysicsRayCaster::DontCheckWater, NULL);

	*returnedEndRayPos = mRayHit.m_position;

	//IPhysicsRayCaster::DontCheckGroup |

	//if (visible == false && (mRayHit.m_material.isPenetrable() == true)) return true;


	//visible = !pIPhysicsRayCaster->PhysicsRayQuery("OnGroundState::update", &fFrom, &fTo, &mRayHit, (0x4 | 0x10 | 0x20 | 0x80), NULL);
	//Sig 03/06/2014 (fonction) 0x141B889A0->0x1409233F0: 40 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 C7 45 ? ? ? ? ? 48 89 9C 24 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4D 8B F1

	/*
	bool bReturn = false;
	Vector3 dir = ((From - To) / 1000.0);


	while ((bReturn = pIPhysicsRayCaster->PhysicsRayQuery("ControllableFinder", &fFrom, &fTo, &mRayHit, IPhysicsRayCaster::AimbotFlags, NULL))
	&& mRayHit.m_material.isSeeThrough() && mRayHit.m_material.isPenetrable())
	{
	if (!mRayHit.m_rigidBody)
	break;

	From = DirectX::XMLoadFloat4(&mRayHit.m_position) + dir;
	DirectX::XMStoreFloat4(&fFrom, From);fFrom.w = 0;
	}
	return !bReturn;
	*/

	return visible;
}


Vector4 GetPlayerSpeed(ClientPlayer* pClientPlayer)
{

	Vector4 PlayerSpeed = { 0, 0, 0, 0 };
	if (IsValidPtr(pClientPlayer))
	{
		if (pClientPlayer->InVehicle())
		{
			ClientVehicleEntity* pClientVehicleEntity = pClientPlayer->GetClientVehicleEntity();
			if (!IsValidPtr(pClientVehicleEntity)) PlayerSpeed;
			ClientChassisComponent* pClientChassisComponent = pClientVehicleEntity->m_Chassis;
			if (!IsValidPtr(pClientChassisComponent)) PlayerSpeed;
			PlayerSpeed = pClientChassisComponent->m_Velocity;
		}
		else
		{
			ClientSoldierEntity* pSoldier = pClientPlayer->GetClientSoldier();
			if (!IsValidPtr(pSoldier)) PlayerSpeed;
			PlayerSpeed = *pSoldier->GetVelocity();
		}
	}
	return PlayerSpeed;
}

Matrix GetShootSpace(ClientPlayer* pClientPlayer)
{
	Matrix ShootSpaceMatrix;
	if (IsValidPtr(pClientPlayer))
	{
		if (pClientPlayer->InVehicle()) // a voir et qu'il est soit gunner soit conducteur
		{
			Current_Weapon* pOffCurrentWeapon = Current_Weapon::GetInstance();
			/*FILE_LOG(logINFO) << "m_WeaponFiring : " << pOffCurrentWeapon->m_WeaponFiring << " Ang1 : " << pOffCurrentWeapon->m_angle1 << " Ang 2 : " << pOffCurrentWeapon->m_angle2;*/
			Matrix ShootSpaceMatrix = pOffCurrentWeapon->matrice1;
			return ShootSpaceMatrix;
		}
		else
		{
			/*
			EntryComponent* pEntryComponent = pClientPlayer->GetEntryComponent();
			if (!IsValidPtr(pEntryComponent)) return ShootSpaceMatrix;
			int activestance = pEntryComponent->GetActiveStance();
			EntryComponent::FiringCallbacks* pFiringCallbacks = pEntryComponent->weapons.at(activestance); // plante
			if (!IsValidPtr(pFiringCallbacks)) return ShootSpaceMatrix;


			ClientWeapon* pClientWeapon = pFiringCallbacks->weapon_info->GetWeapon();
			if (!IsValidPtr(pClientWeapon)) return ShootSpaceMatrix;
			*/

			ClientSoldierEntity* pSoldier = pClientPlayer->GetClientSoldier();
			if (!IsValidPtr(pSoldier)) return ShootSpaceMatrix;
			ClientSoldierWeapon* pClientSoldierWeapon = pSoldier->GetActiveWeapon();
			if (!IsValidPtr(pClientSoldierWeapon)) return ShootSpaceMatrix;
			ClientWeapon* pClientWeapon = pClientSoldierWeapon->m_pWeapon;
			if (!IsValidPtr(pClientWeapon)) return ShootSpaceMatrix;

			Matrix ShootSpaceMatrix = pClientWeapon->m_shootSpace;
			return ShootSpaceMatrix;
		}
	}
	return ShootSpaceMatrix;
}

Vector4 GetProjectileSpeed(ClientPlayer* pClientPlayer) //a voir si c'est utile d'avoir la vitesse de balle des autres joueurs
{
	Vector4 vInitialSpeed = { 0, 0, 1000, 0 };
	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return vInitialSpeed;
	PrimaryFire* pPrimaryFire = pWeaponFiring->m_pPrimaryFire; // ne sert a rien a voir pour les vehicles
	if (!IsValidPtr(pPrimaryFire)) return vInitialSpeed;
	FiringFunctionData* pFiringFunctionData = pPrimaryFire->m_FiringData;
	if (!IsValidPtr(pFiringFunctionData)) return vInitialSpeed;
	vInitialSpeed = pWeaponFiring->m_pPrimaryFire->m_FiringData->m_ShotConfigData.m_InitialSpeed;
	return vInitialSpeed;
}

float GetProjectileGravity(ClientPlayer* pClientPlayer) //a voir si c'est utile d'avoir la vitesse de balle des autres joueurs
{
	float gravity = 1.11f;

	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return gravity;
	PrimaryFire* pPrimaryFire = pWeaponFiring->m_pPrimaryFire; // ne sert a rien a voir pour les vehicles
	if (!IsValidPtr(pPrimaryFire)) return gravity;
	FiringFunctionData* pFiringFunctionData = pPrimaryFire->m_FiringData;
	if (!IsValidPtr(pFiringFunctionData)) return gravity;
	ProjectileEntityData* pProjectileData = pWeaponFiring->m_pPrimaryFire->m_FiringData->m_ShotConfigData.m_ProjectileData; // a voir si c'est pas une balle (typeinfo)
	if (!IsValidPtr(pProjectileData)) return gravity;
	TypeInfo* pType = pProjectileData->GetType();
	if (!IsValidPtr(pType)) return gravity;
	if (strcmp(pType->m_infoData->m_name, "BulletEntityData") == 0)
	{
		BulletEntityData* pBulletEntityData = (BulletEntityData*)pWeaponFiring->m_pPrimaryFire->m_FiringData->m_ShotConfigData.m_ProjectileData;
		if (!IsValidPtr(pBulletEntityData)) return gravity;
		return gravity = pBulletEntityData->m_Gravity;
	}
	if (strcmp(pType->m_infoData->m_name, "MissileEntityData") == 0)
	{
		MissileEntityData* pMissileEntityData = (MissileEntityData*)pWeaponFiring->m_pPrimaryFire->m_FiringData->m_ShotConfigData.m_ProjectileData;
		if (!IsValidPtr(pMissileEntityData)) return gravity;
		return gravity = pMissileEntityData->m_Gravity / 5.0f; // a voir
	}
	if (strcmp(pType->m_infoData->m_name, "GrenadeEntityData") == 0)
	{
		GrenadeEntityData* pGrenadeEntityData = (GrenadeEntityData*)pWeaponFiring->m_pPrimaryFire->m_FiringData->m_ShotConfigData.m_ProjectileData;
		if (!IsValidPtr(pGrenadeEntityData)) return gravity;
		return gravity = pGrenadeEntityData->m_Gravity;
	}
	if (strcmp(pType->m_infoData->m_name, "ExplosionPackEntityData") == 0)
	{
		return gravity * 1000;
	}
	if (strcmp(pType->m_infoData->m_name, "SupplySphereEntityData") == 0)
	{
		return gravity * 1000;
	}

	return gravity;
}

Vector2 CalculateAngles(Vector4 vLocal, Vector4 vTarget)
{

	Vector4 vDelta = (vTarget - vLocal);
	vDelta.Normalize();
	Vector2 Angles;
	Angles.x = -atan2(vDelta.x, vDelta.z); //yaw
	Angles.y = atan2(vDelta.y, sqrt(vDelta.x*vDelta.x + vDelta.z*vDelta.z)); //pitch
	return Angles;
}


float GetBulletFlyTimeFromSimulation(Matrix shootTransform, Vector4 ToAimPosition, float flGravity, Vector4 vBulletspeed, float flTimeStep = 0.0333f, float flTimeToLive = 3.f)
{
	Vector4 vForward = shootTransform.Forward();
	Vector4 vUp = shootTransform.Up();
	Vector4 vBulletPos, vBulletStart = shootTransform.Translation();
	Vector4 vGravity = { 0.0f, -flGravity, 0.0f, 0.0f };

	float flTime = 0.0f;
	Vector4 vEpsilon = { 100.0f, 0.33f, 100.0f, 0 };

	vUp = XMVector4Normalize(vUp);
	vForward = XMVector4Normalize(vForward);

	Vector4 vBulletPrevPos = vBulletStart;


	while (flTime < flTimeToLive)
	{
		flTime += flTimeStep;
		vBulletPos = vBulletStart + vForward*(flTime*vBulletspeed.z) + vUp*(flTime*vBulletspeed.y);

		vBulletPos -= 0.5f * vGravity * flTime *flTime;
		vBulletPrevPos = vBulletPos;
		//fb::DebugRenderer2::Singleton()->cdrawSphere3d(vBulletPos, 0.1, fb::Color32(255, 0, 0, 200), 20);

		if (XMVector4NearEqual(vBulletPos, ToAimPosition, vEpsilon)) return flTime;

	}
	return -1;
}

Vector4 CalculateTrailPointsold(float flGravity, Matrix shootTransform, Vector4 vBulletspeed, float flTimeStep = 0.0333f, float flTimeToLive = 3.f)
{
	//FILE_LOG(logINFO) << "bSpeed X: " << Vector3GetX(vBulletspeed) << " Y: " << Vector3GetY(vBulletspeed) << " Z: " << Vector3GetZ(vBulletspeed);
	//FILE_LOG(logINFO) << "bGrav: " << flGravity;
	Vector4 vPos, vEndPoint = { 0, 0, 0, 0 };

	ClientGameContext* pClientGameContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pClientGameContext)) return vEndPoint;
	HavokPhysicsManager* pHavokPhysicsManager = pClientGameContext->m_pPhysicsManager;
	if (!IsValidPtr(pHavokPhysicsManager)) return vEndPoint;
	GameWorld* pGameWorld = pHavokPhysicsManager->m_GameWorld;
	if (!IsValidPtr(pGameWorld)) return vEndPoint;
	IPhysicsRayCaster* pIPhysicsRayCaster = pGameWorld->m_RayCaster;
	if (!IsValidPtr(pIPhysicsRayCaster)) return vEndPoint;

	if (vBulletspeed.z > 300.f || vBulletspeed.z < 10.f) return vEndPoint;


	Vector4 vForward = shootTransform.Backward(); // why ?
	Vector4 vUp = shootTransform.Up();
	Vector4 vStart = shootTransform.Translation();
	Vector4 vGravity = { 0.0f, -flGravity, 0.0f, 0.0f };

	bool bHitaPlayer = false;
	bool bHitSomething = false;
	float flTime = 0.0f;

	vUp.Normalize();
	vForward.Normalize();

	Vector4 vPrevPos = vStart;

	__declspec(align(16)) Vector4 fvPos = { 0, 0, 0, 0 };
	__declspec(align(16)) Vector4 fvPrevPos = { 0, 0, 0, 0 };
	RayCastHit mRayHit;

	while (flTime < flTimeToLive)
	{
		flTime += flTimeStep;
		vPos = vStart + vForward*(flTime*vBulletspeed.z) + vUp*(flTime*vBulletspeed.y);

		vPos -= 0.5f * vGravity * flTime *flTime;

		fvPos = vPos;
		fvPrevPos = vPrevPos;


		if (pIPhysicsRayCaster->PhysicsRayQuery("controllableFinder", &fvPrevPos, &fvPos, &mRayHit, IPhysicsRayCaster::DontCheckPhantoms | IPhysicsRayCaster::DontCheckWater, NULL))
		{
			bHitSomething = true;
			vEndPoint = mRayHit.m_position;
			if (!pIPhysicsRayCaster->PhysicsRayQuery("controllableFinder", &fvPrevPos, &mRayHit.m_position, &mRayHit, IPhysicsRayCaster::DontCheckCharacter | IPhysicsRayCaster::DontCheckRagdoll | IPhysicsRayCaster::DontCheckPhantoms | IPhysicsRayCaster::DontCheckWater, NULL)) bHitaPlayer = true;
			break;
		}
		else vPrevPos = vPos;

	}

	g_TrailPointResult.TrailPosition = vEndPoint;
	g_TrailPointResult.isValidPlayer = bHitaPlayer;
	g_TrailPointResult.TrailPointToDraw = bHitSomething;

	return vEndPoint;
}


Vector4 CalcAimCorrection(Matrix shootTransform, Vector4 ToAimPosition, Vector4 MyVelocity, Vector4 EnemyVelocity, Vector4 BulletSpeed, float BulletGravity)
{
	Vector4 CorrectedToAimPosition;

	Vector4 MyPos = shootTransform.Translation();

	float distance = (ToAimPosition - MyPos).Length();

	float bullet_time = distance / BulletSpeed.z;

	Vector4 vGravity = { 0.0f, -BulletGravity, 0.0f, 0.0f };

	CorrectedToAimPosition = ToAimPosition + (EnemyVelocity * bullet_time);
	CorrectedToAimPosition -= (MyVelocity * bullet_time);

	CorrectedToAimPosition += 0.5f * vGravity * bullet_time * bullet_time;

	//float simtime = GetBulletFlyTimeFromSimulation(shootTransform, CorrectedToAimPosition, BulletGravity, BulletSpeed, 0.0333f, 3.0f);
	//FILE_LOG(logINFO) << "simtime: " << simtime;

	return CorrectedToAimPosition;
}

bool CheckVisibleSoldierBoneVector(Vector4 vShootSpacePos, Vector4 BoneVector)
{
	// parametres a prendre en compte pour un soldat (murs etc...) a passer en parametre a IsRayVisible
	Vector4 returnedrayendpos;
	if (IsRayVisible(vShootSpacePos, BoneVector, &returnedrayendpos)) return true;
	else return false;

}


int FoundVisibleSoldierBoneVector(ClientPlayer* pClientLocalPlayer, ClientPlayer* pEnemyClientPlayer)
{
	// connaitre la position de mon canon
	Matrix ShootSpaceMatrix = GetShootSpace(pClientLocalPlayer);
	Vector4 vShootSpacePos = ShootSpaceMatrix.Translation(); // +(ShootSpaceMatrix.r[2] * 1.0f); // a enlever

	ClientSoldierEntity* pEnemySoldier = pEnemyClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pEnemySoldier)) return -1;

	int iSkeletonBones[23] = { 4, 6, 8, 9, 11, 15, 61, 63, 104, 109, 111, 115, 182, 183, 184, 185, 196, 197, 198, 199, 46, 96, NULL };//those are bone ID's
	for (int BoneIndex = 0; BoneIndex < 23 - 1; BoneIndex++)
	{
		Vector4 BoneVector;
		if (!GetSoldierBoneVector(pEnemySoldier, iSkeletonBones[BoneIndex], &BoneVector)) continue; //100
		if (CheckVisibleSoldierBoneVector(vShootSpacePos, BoneVector)) return iSkeletonBones[BoneIndex];

	}
	return -1;
}


int FoundVehicleBoneVector(ClientPlayer* pClientLocalPlayer, ClientPlayer* pEnemyClientPlayer, int idcache)
{
	if (pEnemyClientPlayer->InVehicle())
	{
		// connaitre la position de mon canon
		Matrix ShootSpaceMatrix = GetShootSpace(pClientLocalPlayer);
		Vector4 vShootSpacePos = ShootSpaceMatrix.Translation(); // +(ShootSpaceMatrix.r[2] * 1.0f); // a enlever

		ClientVehicleEntity* pEnemyVehicle = pEnemyClientPlayer->GetClientVehicleEntity();
		if (!IsValidPtr(pEnemyVehicle)) return -1;

		DynamicPhysicsEntity* pDynamicPhysicsEntity = pEnemyVehicle->m_pDynamicPhysicsEntity;
		if (!IsValidPtr(pDynamicPhysicsEntity)) return -1;

		for (int BoneIndex = 0; BoneIndex < 70; BoneIndex++)
		{
			LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
			transform = transform + (BoneIndex);
			Vector4 transformpos = transform->m_trans;

			if (CheckVisibleSoldierBoneVector(vShootSpacePos, transformpos)) return BoneIndex; // pour l'instant meme / a voir

		}
	}
	return -1;
}


int FoundVehicleBoneVectorCached(ClientPlayer* pClientLocalPlayer, ClientPlayer* pEnemyClientPlayer, int idcache)
{
	int ReturnedBoneIndex = -1; // par defaut n'a rien trouvé
	ClientVehicleEntity* pEnemyVehicle = pEnemyClientPlayer->GetClientVehicleEntity();
	if (!IsValidPtr(pEnemyVehicle)) return ReturnedBoneIndex;
	DynamicPhysicsEntity* pDynamicPhysicsEntity = pEnemyVehicle->m_pDynamicPhysicsEntity;
	if (!IsValidPtr(pDynamicPhysicsEntity)) return ReturnedBoneIndex;


	// le joueur n'est pas en cache
	if (g_PlayersCache[idcache].ClientPlayer != pEnemyClientPlayer)
	{
		//FILE_LOG(logINFO) << "FoundVehicleBoneVectorCached: player changed.";
		g_PlayersCache[idcache].dwGetTickCount = 0;
	}
	// l'update date de moins de 62*2*16ms
	if (g_PlayersCache[idcache].dwGetTickCount + 1000 > GetTickCount64())
	{
		//FILE_LOG(logINFO) << "FoundVehicleBoneVectorCached: use cached.";
		return g_PlayersCache[idcache].FoundVehicleBoneIndex;
	}
	else
	{
		//FILE_LOG(logINFO) << "FoundVehicleBoneVectorCached: dont use cached.";
		// connaitre la position de mon canon
		Vector4 vShootSpacePos = GetShootSpace(pClientLocalPlayer).Translation();

		for (int BoneIndex = 0; BoneIndex < 70; BoneIndex++)
		{
			LinearTransform* transform = pDynamicPhysicsEntity->m_GameWorldTransformBase;
			transform = transform + (BoneIndex);
			Vector4 transformpos = transform->m_trans;

			if (CheckVisibleSoldierBoneVector(vShootSpacePos, transformpos))
			{
				ReturnedBoneIndex = BoneIndex;
				break;
			}
		}
		g_PlayersCache[idcache].FoundVehicleBoneIndex = ReturnedBoneIndex;
		g_PlayersCache[idcache].dwGetTickCount = (unsigned int)GetTickCount64();
		g_PlayersCache[idcache].ClientPlayer = pEnemyClientPlayer;
	}

	return ReturnedBoneIndex;
}

float RealDistanceFromCrossair(ClientPlayer* pClientLocalPlayer, Vector4 ToEnemyPosition)
{
	//http://www.unknowncheats.me/forum/c-and-c/114805-real-aimbot-crosshair-distance.html
	float fRealDistance = 999999.0;

	// connaitre la position de mon canon
	Matrix ShootSpaceMatrix = GetShootSpace(pClientLocalPlayer);
	Vector4 vShootSpacePos = ShootSpaceMatrix.Translation();

	// calcule la distance entre mon canon et l'enemi
	float fDistance = vDistance3d(vShootSpacePos, ToEnemyPosition);
	// Get the angle needed to aim at the enemy
	Vector2 vAngles = CalculateAngles(vShootSpacePos, ToEnemyPosition);
	// Get the distance between your current yaw and the yaw to aim at the enemy

	// ok mais ne fonction qu'avec les soldats
	/*
	ClientSoldierEntity* pLocalSoldier = pClientLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier)) return fRealDistance;
	ClientSoldierWeapon* pClientSoldierWeapon = pLocalSoldier->GetActiveWeapon();
	if (!IsValidPtr(pClientSoldierWeapon)) return fRealDistance;
	ClientSoldierAimingSimulation* pClientSoldierAimingSimulation = pClientSoldierWeapon->m_authorativeAiming;
	if (!IsValidPtr(pClientSoldierAimingSimulation)) return fRealDistance;

	float YawSway = vAngles.x -pClientSoldierAimingSimulation->m_sway.x; // correction du sway
	float PitchSway = vAngles.y -pClientSoldierAimingSimulation->m_sway.y;

	float DiffYaw = YawSway - pClientSoldierAimingSimulation->m_fpsAimer->m_yaw;
	float DiffPitch = PitchSway - pClientSoldierAimingSimulation->m_fpsAimer->m_pitch;

	float fRealDistancex = sin(DiffYaw) * fDistance;
	float fRealDistancey = sin(DiffPitch) * fDistance;

	fRealDistance = sqrt(fRealDistancex * fRealDistancex + fRealDistancey * fRealDistancey);
	*/

	Vector4 vShootSpaceLeft = ShootSpaceMatrix.Left(); // left (right for vehicle)
	Vector4 vShootSpaceUp = ShootSpaceMatrix.Up();

	Vector4 vDir = (ToEnemyPosition - vShootSpacePos);
	vDir.Normalize();

	GameRenderer* pGameRenderer = GameRenderer::GetInstance();
	if (!IsValidPtr(pGameRenderer)) return fRealDistance;
	float fov_x = 1.0f; // pGameRenderer->m_pRenderView->m_FovX / 2.0f;
	float fov_y = 1.0f; // pGameRenderer->m_pRenderView->m_FovY / 2.0f;


	float flYaw = asinf(DirectX::XMVectorGetX(XMVector4Dot(vShootSpaceLeft, vDir))) / fov_x;
	float flPitch = asinf(DirectX::XMVectorGetX(XMVector4Dot(vShootSpaceUp, vDir))) / fov_y;
	float flRoll = flYaw;

	//FILE_LOG(logINFO) << "flyaw:" << flYaw << "flpitch:" << flPitch;

	flYaw = DirectX::XMScalarModAngle(flYaw);
	flPitch = DirectX::XMScalarModAngle(flPitch);

	float fRealDistancex = sin(flYaw) * fDistance;
	float fRealDistancey = sin(flPitch) * fDistance;

	fRealDistance = sqrt(fRealDistancex * fRealDistancex + fRealDistancey * fRealDistancey);



	Vector2 pos2d = { 0, 0 };



	if (!WorldToScreen(ToEnemyPosition, &pos2d)) fRealDistance = 99999.0; // pas parfait a voir


	//FILE_LOG(logINFO) << "dist: " << fRealDistance << "dy: " << flYaw;
	return fRealDistance;
}


void sWriteAimAt(ClientPlayer* pClientLocalPlayer, ClientPlayer* pEnemyClientPlayer, Vector4 ToAimPosition, float smoothDivisor)
{
	// connaitre la position de mon canon
	Matrix ShootSpaceMatrix = GetShootSpace(pClientLocalPlayer);
	Vector4 vShootSpacePos = ShootSpaceMatrix.Translation();
	// correction de la cible en fonction des vitesses et de la gravité de la balle
	ToAimPosition = CalcAimCorrection(ShootSpaceMatrix, ToAimPosition, GetPlayerSpeed(pClientLocalPlayer), GetPlayerSpeed(pEnemyClientPlayer), GetProjectileSpeed(pClientLocalPlayer), GetProjectileGravity(pClientLocalPlayer));
	// calcul les nouveaux angles
	// doute: faut il utiliser le vShootSpacePos ou la camera pour le calcule d'angles ?
	//Matrix InvMatrix = GameRenderer::GetInstance()->m_pRenderView->m_viewMatrixInverse;
	//vShootSpacePos = InvMatrix.r[3];
	Vector2 vAngles = CalculateAngles(vShootSpacePos, ToAimPosition);
	// set angles
	ClientSoldierEntity* pLocalSoldier = pClientLocalPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier)) return;
	ClientSoldierWeapon* pClientSoldierWeapon = pLocalSoldier->GetActiveWeapon();
	if (!IsValidPtr(pClientSoldierWeapon)) return;
	ClientSoldierAimingSimulation* pClientSoldierAimingSimulation = pClientSoldierWeapon->m_authorativeAiming;
	if (!IsValidPtr(pClientSoldierAimingSimulation)) return;

	float YawSway = vAngles.x - pClientSoldierAimingSimulation->m_sway.x; // correction du sway
	float PitchSway = vAngles.y - pClientSoldierAimingSimulation->m_sway.y;
	// smooth les angles
	float smoothDiffYaw = YawSway - pClientSoldierAimingSimulation->m_fpsAimer->m_yaw;
	float smoothDiffPitch = PitchSway - pClientSoldierAimingSimulation->m_fpsAimer->m_pitch;
	smoothDiffYaw = DirectX::XMScalarModAngle(smoothDiffYaw);
	smoothDiffPitch = DirectX::XMScalarModAngle(smoothDiffPitch);
	smoothDiffYaw = smoothDiffYaw / smoothDivisor;
	smoothDiffPitch = smoothDiffPitch / smoothDivisor;
	YawSway = pClientSoldierAimingSimulation->m_fpsAimer->m_yaw + smoothDiffYaw;
	PitchSway = pClientSoldierAimingSimulation->m_fpsAimer->m_pitch + smoothDiffPitch;
	YawSway = DirectX::XMScalarModAngle(YawSway);
	PitchSway = DirectX::XMScalarModAngle(PitchSway);
	// fin smooth
	//debug pour l'esp
	WorldToScreen(ToAimPosition, &aimbotData.boneCorrectedPos2d);

	if (g_Mouse_VK_RBUTTON)
	{

		pClientSoldierAimingSimulation->m_fpsAimer->m_yaw = YawSway;
		pClientSoldierAimingSimulation->m_fpsAimer->m_pitch = PitchSway;
	}
};


void vWriteAimAt(ClientPlayer* pClientLocalPlayer, ClientPlayer* pEnemyClientPlayer, Vector4 ToAimPosition, float smoothDivisor)
{
	// connaitre la position de mon canon
	Matrix ShootSpaceMatrix = GetShootSpace(pClientLocalPlayer);
	Vector4 vShootSpacePos = ShootSpaceMatrix.Translation();
	Vector4 vShootSpaceLeft = ShootSpaceMatrix.Left(); // right
	Vector4 vShootSpaceUp = ShootSpaceMatrix.Up();
	// correction de la cible en fonction des vitesses et de la gravité de la balle
	ToAimPosition = CalcAimCorrection(ShootSpaceMatrix, ToAimPosition, GetPlayerSpeed(pClientLocalPlayer), GetPlayerSpeed(pEnemyClientPlayer), GetProjectileSpeed(pClientLocalPlayer), GetProjectileGravity(pClientLocalPlayer));
	//FILE_LOG(logINFO) << "pspeed:" << GetProjectileSpeed(pClientLocalPlayer) << "pgrav:" << GetProjectileGravity(pClientLocalPlayer);
	// calcul les nouveaux angles
	// doute: faut il utiliser le vShootSpacePos ou la camera pour le calcule d'angles ?

	/*
	Matrix InvMatrix = GameRenderer::GetInstance()->m_pRenderView->m_viewMatrixInverse;
	vShootSpaceLeft = InvMatrix.r[0];
	vShootSpaceUp = InvMatrix.r[1];
	vShootSpacePos = InvMatrix.r[3];
	*/

	Vector2 vAngles = CalculateAngles(vShootSpacePos, ToAimPosition);
	//FILE_LOG(logINFO) << "angle.x:" << vAngles.x << "angle.y:" << vAngles.y;
	//

	Vector4 vDir = (ToAimPosition - vShootSpacePos);
	vDir.Normalize();


	GameRenderer* pGameRenderer = GameRenderer::GetInstance();
	if (!IsValidPtr(pGameRenderer)) return;
	float fov_x = pGameRenderer->m_pRenderView->m_FovX / 2.0f;
	float fov_y = pGameRenderer->m_pRenderView->m_FovY / 2.0f;


	float flYaw = asinf(DirectX::XMVectorGetX(XMVector4Dot(vShootSpaceLeft, vDir))) / fov_x;
	float flPitch = asinf(DirectX::XMVectorGetX(XMVector4Dot(vShootSpaceUp, vDir))) / fov_y;
	float flRoll = flYaw;

	//FILE_LOG(logINFO) << "flyaw:" << flYaw << "flpitch:" << flPitch;

	flYaw = DirectX::XMScalarModAngle(flYaw);
	flPitch = DirectX::XMScalarModAngle(flPitch);
	flRoll = DirectX::XMScalarModAngle(flRoll);

	//debug pour l'esp
	WorldToScreen(ToAimPosition, &aimbotData.boneCorrectedPos2d);

	/* besoin de savoir si on est gunner ou ....
	std::string sVehicleName = GetVehicleName(pClientLocalPlayer->GetClientVehicleEntity());
	if (sVehicleName == "AH6" || sVehicleName == "AH1Z" || sVehicleName == "UH1Y") flPitch = -flPitch;
	if (sVehicleName == "AH64" || sVehicleName == "MI28" || sVehicleName == "WZ10") flPitch = -flPitch;
	if (sVehicleName == "UH60" || sVehicleName == "Z9" || sVehicleName == "Z11") flPitch = -flPitch;

	if (sVehicleName == "FA18" || sVehicleName == "SU35" || sVehicleName == "A10") flPitch = -flPitch;
	if (sVehicleName == "AME_F35" || sVehicleName == "SU25" || sVehicleName == "Q5") flPitch = -flPitch;
	if (sVehicleName == "J20" || sVehicleName == "SU50" || sVehicleName == "F22") flPitch = -flPitch;
	*/

	if (g_Keyb_VK_SHIFT)
	{
		float vSensibility = 2.0f;
		g_pInputBuffers[ConceptYaw] = flYaw*vSensibility;
		g_pInputBuffers[ConceptPitch] = flPitch*vSensibility;
		g_pInputBuffers[ConceptRoll] = flRoll*vSensibility;
	}
};

void AimbotSoldier()
{

	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier)) return;




	if (aimbotData.enemyChoosenID == -1)
	{
		aimbotData.previousEnemyChoosenID = -1;
		aimbotData.sameenemyChoosenIDcount = 1;
	}
	else if (aimbotData.previousEnemyChoosenID == aimbotData.enemyChoosenID)
	{
		aimbotData.sameenemyChoosenIDcount++;
		//FILE_LOG(logINFO) << "Same: " << aimbotData.sameenemyChoosenIDcount;
	}
	aimbotData.previousEnemyChoosenID = aimbotData.enemyChoosenID;


	aimbotData.enemyChoosenID = -1;
	aimbotData.enemyDistanceCrossair2d = 9999.0;
	aimbotData.enemyDistance3d = 9999.0;
	aimbotData.boneSoldierIndex = -1;
	aimbotData.boneVehicleIndex = -1;

	for (int i = 0; i < (int)pPlayerManager->m_maxPlayerCount; i++)
	{
		ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(i);
		if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) continue; // if no player or player is me

		if (GetAsyncKeyState(VK_F10))
		if (pPlayerManager->m_pLocalPlayer->m_teamId == pPlayerManager->GetPlayerById(i)->m_teamId){

			ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
			if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) continue;
			ClientCharacterEntity* pAmiClientCharacterEntity = (ClientCharacterEntity*)pPlayer->GetCharacterEntity();
			
		/*	FILE_LOG(logINFO) << "pPlayer ami " << std::hex << (DWORD_PTR)pPlayer;
			FILE_LOG(logINFO) << "pAmiClientCharacterEntity " << std::hex << (DWORD_PTR)pAmiClientCharacterEntity;*/
		}

		if (pPlayerManager->m_pLocalPlayer->m_teamId == pPlayerManager->GetPlayerById(i)->m_teamId) continue; // si c'est un membre de mon equipe

		ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
		if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) continue;

		ClientCharacterEntity* pEnemyClientCharacterEntity = (ClientCharacterEntity*)pPlayer->GetCharacterEntity();
		if (GetAsyncKeyState(VK_F11))
		/*FILE_LOG(logINFO) << "pEnemyClientCharacterEntity " << std::hex << (DWORD_PTR)pEnemyClientCharacterEntity;*/
		if (!IsValidPtr(pEnemyClientCharacterEntity)) continue;

		if (pSoldier->m_pHealthComponent->m_Health <= 0.01f) continue;

#define MAX_DISTANCE 500 // metres


		// si il n'est pas a l'ecran ou trop loin , abandonne
		Vector4 EnemyPos = pSoldier->m_pPredictedController->m_Position;
		Vector4 Mypos = pLocalSoldier->m_pPredictedController->m_Position;
		Vector2 EnemyPlayerPos2d = { 0, 0 };
		if (!WorldToScreen(EnemyPos, &EnemyPlayerPos2d)) continue;
		if (vDistance3d(Mypos, EnemyPos) > MAX_DISTANCE) continue;

		//fb::DebugRenderer2::Singleton()->cdrawSphere3d(EnemyPos, RealDistanceFromCrossair(pPlayerManager->m_pLocalPlayer, EnemyPos), fb::Color32(255, 0, 0, 255), 20);
#define MAX_FOV 10 // metres
		if (RealDistanceFromCrossair(pPlayerManager->m_pLocalPlayer, EnemyPos) > MAX_FOV) continue;
		// note pour des raisons de performances il faudra tester si ils sont dans le fov avant de lancer pleins de rayons

		int FoundSoldierBoneIndex = -1;
		if (pSoldier->isVisible()) FoundSoldierBoneIndex = FoundVisibleSoldierBoneVector(pLocalClientPlayer, pPlayer); // lancé de rayon sur le soldat
		int FoundVehicleBoneIndex = -1;
		if (pPlayer->InVehicle()) FoundVehicleBoneIndex = FoundVehicleBoneVectorCached(pLocalClientPlayer, pPlayer, i); // lancé de rayon sur l'eventuel vehicle


		// renseigne l'esp puisque filtrage par fov seuls les vehicles dans le fov seront traités
		if (FoundSoldierBoneIndex != -1) aimbotData.PlayersRayInfo[i].is_soldier_ray_visible = true; else  aimbotData.PlayersRayInfo[i].is_soldier_ray_visible = false;
		if (FoundVehicleBoneIndex != -1) aimbotData.PlayersRayInfo[i].is_vehicle_ray_visible = true; else  aimbotData.PlayersRayInfo[i].is_vehicle_ray_visible = false;

		if (FoundSoldierBoneIndex == -1 && FoundVehicleBoneIndex == -1) continue; // si le lancé de rayon n'a trouvé ni soldat ni vehicle visible

		if (pPlayer->InVehicle() && FoundVehicleBoneIndex != -1) FoundSoldierBoneIndex = 100; // (tete) a voir parfois (jeep heli les bones sont actives alors que occluded) donc fait une tentative de recup de bones

		Vector4 BoneVector;
		if (!GetSoldierBoneVector(pSoldier, FoundSoldierBoneIndex, &BoneVector)) continue;

		Vector2 BoneVector2d = { 0, 0 };
		if (!WorldToScreen(BoneVector, &BoneVector2d)) continue;


		// si un joueur est plus proche de mon crosshair et que je ne suis pas en train de viser
		if ((g_Mouse_VK_RBUTTON || g_Keyb_VK_SHIFT) && i == aimbotData.previousEnemyChoosenID)
		{
			aimbotData.enemyDistanceCrossair2d = RealDistanceFromCrossair(pPlayerManager->m_pLocalPlayer, BoneVector);
			aimbotData.enemyChoosenID = i;
			aimbotData.boneSoldierIndex = FoundSoldierBoneIndex;
			aimbotData.bonePos2d = BoneVector2d; // pour l'esp
			break;
		}
		if (RealDistanceFromCrossair(pPlayerManager->m_pLocalPlayer, BoneVector) < aimbotData.enemyDistanceCrossair2d)
		{
			aimbotData.enemyDistanceCrossair2d = RealDistanceFromCrossair(pPlayerManager->m_pLocalPlayer, BoneVector);
			aimbotData.enemyChoosenID = i;
			aimbotData.boneSoldierIndex = FoundSoldierBoneIndex;
			aimbotData.bonePos2d = BoneVector2d; // pour l'esp
		}

	}

	// a partir d'ici un enemy est désigné ou pas

	if (aimbotData.enemyChoosenID != -1)
	{
		ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(aimbotData.enemyChoosenID);
		if (!IsValidPtr(pPlayer)) return;
		ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
		if (!IsValidPtr(pSoldier)) return;

		if (aimbotData.mode == 0)
		{
			Vector4 BoneVector;
			if (!GetSoldierBoneVector(pSoldier, aimbotData.boneSoldierIndex, &BoneVector)) return;

			float smoothDivisor;
			if (aimbotData.sameenemyChoosenIDcount > 20) smoothDivisor = 1.0f; else smoothDivisor = 4.0f;
			sWriteAimAt(pLocalClientPlayer, pPlayer, BoneVector, smoothDivisor);
		}

		if (aimbotData.mode == 1)
		{
			Vector4 BoneVector;
			if (!GetSoldierBoneVector(pSoldier, aimbotData.boneSoldierIndex, &BoneVector)) return;

			float smoothDivisor;
			if (aimbotData.sameenemyChoosenIDcount > 20) smoothDivisor = 1.0f; else smoothDivisor = 4.0f;
			vWriteAimAt(pLocalClientPlayer, pPlayer, BoneVector, smoothDivisor);
		}
	}
}

bool IsRayVisible(Vector4 From, Vector4 To, RayCastHit *mRayHit)
{
	ClientGameContext* pClientGameContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pClientGameContext)) return false;
	HavokPhysicsManager* pHavokPhysicsManager = pClientGameContext->m_pPhysicsManager;
	if (!IsValidPtr(pHavokPhysicsManager)) return false;
	GameWorld* pGameWorld = pHavokPhysicsManager->m_GameWorld;
	if (!IsValidPtr(pGameWorld)) return false;
	IPhysicsRayCaster* pIPhysicsRayCaster = pGameWorld->m_RayCaster;
	if (!IsValidPtr(pIPhysicsRayCaster)) return false;

	__declspec(align(16)) Vector4 fFrom = From;
	__declspec(align(16)) Vector4 fTo = To;

	return !pIPhysicsRayCaster->PhysicsRayQuery("OnGroundState::update", &fFrom, &fTo, mRayHit, IPhysicsRayCaster::DontCheckCharacter | IPhysicsRayCaster::DontCheckRagdoll | IPhysicsRayCaster::DontCheckPhantoms | IPhysicsRayCaster::DontCheckWater, NULL);
	//visible = !pIPhysicsRayCaster->PhysicsRayQuery("OnGroundState::update", &fFrom, &fTo, &mRayHit, (0x4 | 0x10 | 0x20 | 0x80), NULL);
	//Sig 03/06/2014 (fonction) 0x141B889A0->0x1409233F0: 40 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 C7 45 ? ? ? ? ? 48 89 9C 24 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4D 8B F1
}

void VehicleBot(ClientPlayer* pLocalClientPlayer){
	Vector4 cpos = { 41.19f, 136.87f, -143.08f, 0.0f };
	Matrix mShootSpace = GetShootSpace(pLocalClientPlayer);

	gmRayHitresult = IsRayVisible((Vector4)mShootSpace.Translation(), cpos, &gmRayHit);

	//avec comme isRayvisible 

}

void AimbotVehicle()
{
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pLocalClientPlayer)) return;
	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
	if (!IsValidPtr(pLocalSoldier) || !IsValidPtr(pLocalSoldier->m_pPredictedController)) return;
	ClientCharacterEntity* pLocalClientCharacterEntity = (ClientCharacterEntity*)pLocalClientPlayer->GetCharacterEntity();
	if (!IsValidPtr(pLocalClientCharacterEntity)) return;
	if (pLocalSoldier->m_pHealthComponent->m_Health <= 0.01f) return;
	VehicleBot(pLocalClientPlayer);
	AimbotSoldier();
}

void Aimbot()
{
	if (!IsIamAlive()) return;

	// get current weapon 
	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return;
	FiringHolderData* tempclass = (FiringHolderData*)pWeaponFiring->m_pFiringHolderData;
	if (!IsValidPtr(tempclass)) return;
	TypeInfo* pType = tempclass->GetType();
	if (!IsValidPtr(pType)) return;
	if (strcmp(pType->m_infoData->m_name, "SoldierWeaponData") == 0)
	{
		aimbotData.mode = 0;
		AimbotSoldier();
	}
	else
	{
		aimbotData.mode = 1;
		AimbotVehicle();
	}



	if (g_Keyb_VK_SHIFT)
	{

		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pLocalClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pLocalClientPlayer)) return;

		Vec3 vTrailPoint = CalculateTrailPointsold(GetProjectileGravity(pLocalClientPlayer), GetShootSpace(pLocalClientPlayer), GetProjectileSpeed(pLocalClientPlayer), 0.1f, 5.f);
		
		/***************TELEPORT PARABOLIQUE*************/
	/*	ClientSoldierEntity* pLocalSoldier = pLocalClientPlayer->GetClientSoldier();
		if (!IsValidPtr(pLocalSoldier)) return;

		if (g_Keyb_VK_T){

			Vec3 pDestination = relativeDestinationJumpView(pLocalSoldier, true, vTrailPoint);
			if (g_Keyb_VK_O){

					ClientVaultInterface* myTeleport = new ClientVaultInterface(pLocalSoldier, pDestination, true);
					myTeleport->Teleportation(pLocalSoldier, pDestination);

			}

		}*/
			/****************************************/
	}
	else
	{
		g_TrailPointResult.TrailPointToDraw = false;
	}


}