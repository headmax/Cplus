
void LowerDispersion(GunSwayDispersionData& DispersionData)
{
	if (DispersionData.m_MaxAngle > 0.05f) // protection crosshair petit
	{
		DispersionData.m_MinAngle *= 0.75f;
		DispersionData.m_MaxAngle *= 0.75f;
		DispersionData.m_IncreasePerShot *= 0.75f;
		DispersionData.m_DecreasePerSecond = DispersionData.m_DecreasePerSecond;
	}
}

void LowerDispersionMod(GunSwayDispersionModData& DispersionModData)
{
	if (DispersionModData.m_MaxAngleModifier > 0.05f)
	{
		DispersionModData.m_MinAngleModifier *= 0.75f;
		DispersionModData.m_MaxAngleModifier *= 0.75f;
		DispersionModData.m_IncreasePerShotModifier *= 0.75f;
		DispersionModData.m_DecreasePerSecondModifier = DispersionModData.m_DecreasePerSecondModifier;
	}
}

void RemoveRecoil(GunSwayRecoilData& RecoilData)
{
	RecoilData.m_RecoilAmplitudeMax = 0.02f; 
	RecoilData.m_RecoilAmplitudeIncPerShot=0.01f;
	RecoilData.m_HorizontalRecoilAmplitudeIncPerShotMin = 0.01f;
	RecoilData.m_HorizontalRecoilAmplitudeIncPerShotMax = 0.02f;
	RecoilData.m_HorizontalRecoilAmplitudeMax = 0.02f;
	RecoilData.m_RecoilAmplitudeDecreaseFactor = RecoilData.m_RecoilAmplitudeDecreaseFactor;
}


void NoRecoilSoldier()
{
	ClientGameContext* pGContext = ClientGameContext::GetInstance();
	if (!IsValidPtr(pGContext)) return;
	ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
	if (!IsValidPtr(pPlayerManager)) return;
	ClientPlayer* pClientPlayer = pPlayerManager->m_pLocalPlayer;
	if (!IsValidPtr(pClientPlayer)) return;
	ClientSoldierEntity* pSoldier = pClientPlayer->GetClientSoldier();



	//FILE_LOG(logINFO) << "GunSwayData: fps" << g_dwFrames;
	if (g_Keyb_VK_END && (g_dwFrames == 1 || g_dwFrames == 30))
	{
		Beep(8000, 10);

		if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) return;


		WeaponSway* pWeaponSway = pSoldier->getWeaponSway();
		if (!IsValidPtr(pWeaponSway)) return;

		if (pSoldier->m_soldierWeaponsComponent->m_activeSlot == 0 || pSoldier->m_soldierWeaponsComponent->m_activeSlot == 1)
		{
			GunSwayData* pGunSwayData = (GunSwayData*)pWeaponSway->GunSwayData;
			if (!IsValidPtr(pGunSwayData)) return;
			FILE_LOG(logINFO) << "GunSwayData: 0x" << std::hex << pGunSwayData;


			/*************/
			ClientSoldierWeaponsComponent * listWeapons = pSoldier->m_soldierWeaponsComponent;

			FILE_LOG(logINFO) << "listWeapons->GetSlot(): " << listWeapons->GetSlot() << listWeapons->GetSlot();

			FILE_LOG(logINFO) << "listWeapons->GetActiveSoldierWeapon(): " << listWeapons->GetActiveSoldierWeapon() << listWeapons->GetActiveSoldierWeapon();
			
			/*pSoldier->m_breathControlHandler->m_breathActive = false;
			pSoldier->m_breathControlHandler->m_breathControlActive = false;
			pSoldier->m_breathControlHandler->m_breathControlInput = false;
			pSoldier->m_breathControlHandler->m_breathControlMultiplier = 0;
			pSoldier->m_breathControlHandler->m_breathControlpenaltyMultiplier = 0;
			pSoldier->m_breathControlHandler->m_breathControlPenaltyTimer = 0;
			pSoldier->m_breathControlHandler->m_breathControlTimer = false;
			pSoldier->m_breathControlHandler->m_Enabled = false;
			*/

			/*pSoldier->m_pSoldierData->m_BreathControl.At(0);*/



			RemoveRecoil(pGunSwayData->m_Stand.m_Zoom.m_Recoil);
			RemoveRecoil(pGunSwayData->m_Stand.m_NoZoom.m_Recoil);
			RemoveRecoil(pGunSwayData->m_Crouch.m_Zoom.m_Recoil);
			RemoveRecoil(pGunSwayData->m_Crouch.m_NoZoom.m_Recoil);
			RemoveRecoil(pGunSwayData->m_Prone.m_Zoom.m_Recoil);
			RemoveRecoil(pGunSwayData->m_Prone.m_NoZoom.m_Recoil);
			
			// ... transitions a faire
			LowerDispersion(pGunSwayData->m_Stand.m_Zoom.m_BaseValue);
			LowerDispersion(pGunSwayData->m_Stand.m_Zoom.m_Moving);
			LowerDispersion(pGunSwayData->m_Stand.m_Zoom.m_Jumping);
			LowerDispersion(pGunSwayData->m_Stand.m_Zoom.m_Sprinting);

			LowerDispersion(pGunSwayData->m_Stand.m_NoZoom.m_BaseValue);
			LowerDispersion(pGunSwayData->m_Stand.m_NoZoom.m_Moving);
			LowerDispersion(pGunSwayData->m_Stand.m_NoZoom.m_Jumping);
			LowerDispersion(pGunSwayData->m_Stand.m_NoZoom.m_Sprinting);

			//
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierUnzoomed.m_DispersionMod);
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierUnzoomed.m_MovingDispersionMod);
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierUnzoomed.m_SprintingDispersionMod);
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierZoomed.m_DispersionMod);
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierZoomed.m_MovingDispersionMod);
			LowerDispersionMod(pGunSwayData->m_SuppressionModifierZoomed.m_SprintingDispersionMod);

			/*
			pGunSwayData->m_Stand.m_Zoom.m_Recoil.m_HorizontalRecoilAmplitudeIncPerShotMax = 0.02f;
			pGunSwayData->m_Stand.m_Zoom.m_Recoil.m_HorizontalRecoilAmplitudeIncPerShotMin = 0.01f;
			pGunSwayData->m_Stand.m_Zoom.m_Recoil.m_HorizontalRecoilAmplitudeMax = 0.02f;
			pGunSwayData->m_Stand.m_Zoom.m_Recoil.m_RecoilAmplitudeIncPerShot = 0.01f;
			pGunSwayData->m_Stand.m_Zoom.m_Recoil.m_RecoilAmplitudeMax = 0.02f;
			*/

			//GunSwayModifierUnlock pGunSwayModifierUnlock = pGunSwayData->m_ModifierUnlocks < GunSwayModifierUnlock > ;

		}
		//GunSwayModifierUnlock* = pGunSwayData->m_ModifierUnlocks.At;

		/*
		GunSwayModifierUnlock * pGunSwayModifierUnlock = (GunSwayModifierUnlock*)pGunSwayData->m_ModifierUnlocks[11];

		FILE_LOG(logINFO) << "GunSwayModifierData: 0x" << std::hex << pGunSwayModifierData;
		*/
	}

}

void NoRecoilVehicle()
{
	if (g_Keyb_VK_END && (g_dwFrames == 1 || g_dwFrames== 30))
	{
		Beep(8000, 10);
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		ClientPlayer* pClientPlayer = pPlayerManager->m_pLocalPlayer;
		if (!IsValidPtr(pClientPlayer)) return;
		ClientSoldierEntity* pSoldier = pClientPlayer->GetClientSoldier();
		if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) return;


		WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
		if (!IsValidPtr(pWeaponFiring)) return;
		WeaponComponentData* pWeaponComponentData = (WeaponComponentData*)pWeaponFiring->m_pFiringHolderData;
		if (!IsValidPtr(pWeaponComponentData)) return;

		WeaponFiringData* pWeaponFiringData = pWeaponComponentData->m_WeaponFiring;
		if (!IsValidPtr(pWeaponFiringData)) return;


		FiringFunctionData* pFiringFunctionData = pWeaponFiringData->m_PrimaryFire;
		if (!IsValidPtr(pFiringFunctionData)) return;

		FILE_LOG(logINFO) << "FiringFunctionData: 0x" << std::hex << pFiringFunctionData;

		pFiringFunctionData->m_FireLogic.m_Recoil.m_MaxRecoilAngleX = 0.002f; //-0.3
		pFiringFunctionData->m_FireLogic.m_Recoil.m_MinRecoilAngleX = 0.001f; // -0.6
		pFiringFunctionData->m_FireLogic.m_Recoil.m_MaxRecoilAngleY = 0.002f; // 0.079
		pFiringFunctionData->m_FireLogic.m_Recoil.m_MinRecoilAngleY = 0.001f; // -s0.079
		pFiringFunctionData->m_FireLogic.m_Recoil.m_MaxRecoilAngleZ = 0.002f; // -0.1
		pFiringFunctionData->m_FireLogic.m_Recoil.m_MinRecoilAngleZ = 0.001f; // -0.1
	
	
		if (pFiringFunctionData->m_WeaponDispersion.m_StandDispersion.m_MaxAngle == 0) // pour les armes type vehicule ouvert
		{

			// attention FiringFunctionData modifié car je ne savais pas utiliser les <array>
			FiringDispersionData* pFiringDispersionData = (FiringDispersionData*)pFiringFunctionData->m_Dispersion;

			pFiringDispersionData->m_MinAngle = pFiringDispersionData->m_MinAngle / 3.0f;
			pFiringDispersionData->m_MaxAngle = pFiringDispersionData->m_MaxAngle / 3.0f;
			pFiringDispersionData->m_IncreasePerShot = pFiringDispersionData->m_IncreasePerShot / 3.0f;
			//LocalFiringDispersionData.m_DecreasePerSecond = 0.001;
		}
		else
		{
			pFiringFunctionData->m_WeaponDispersion.m_StandDispersion.m_MaxAngle = pFiringFunctionData->m_WeaponDispersion.m_StandDispersion.m_MaxAngle / 5.0f;
			pFiringFunctionData->m_WeaponDispersion.m_StandDispersion.m_MinAngle = pFiringFunctionData->m_WeaponDispersion.m_StandDispersion.m_MinAngle / 5.0f;
		}

	
	
	}
}

void NoRecoil()
{
	if (!IsIamAlive()) return;

	WeaponFiring* pWeaponFiring = *(WeaponFiring**)OFFSET_CURRENT_WEAPONFIRING;
	if (!IsValidPtr(pWeaponFiring)) return;
	FiringHolderData* tempclass = (FiringHolderData*)pWeaponFiring->m_pFiringHolderData;
	if (!IsValidPtr(tempclass)) return;
	TypeInfo* pType = tempclass->GetType();
	if (!IsValidPtr(pType)) return;
	if (strcmp(pType->m_infoData->m_name, "SoldierWeaponData") == 0)
	{
		NoRecoilSoldier();
	}
	else
	{
		NoRecoilVehicle();
	}
}