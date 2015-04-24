bool gameEnd = false;
bool sschamDelete = true;
bool vehicleChamState[64];
bool soldierChamState[64];
bool soldierPatch[64];

bool pPatchSoldier[70];
bool pUnPatchSoldier[70];


class chams{
	int maxPlayers;
	ClientPlayer * pCplayer[70];
	ClientSoldierEntity* pSEntity[70];
	ClientPlayer* pLocalPlayer;
	bool init_sChams[70];
	bool delete_sChams[70];

	bool sVisibleSoldier[70];
	bool IamAlive;

public:
	chams(ClientPlayerManager* pPlayerManager, int PlayerInLiveOnMap, bool IamAlive){
		this->maxPlayers = PlayerInLiveOnMap;
		this->IamAlive = IamAlive;
		this->pLocalPlayer = pPlayerManager->m_pLocalPlayer;
	}

	void activeSoldierChams(ClientSoldierEntity* pSoldier, int i){

		if (!sschamDelete){// si SS n'est pas en cours
			if (IsValidPtr(pSoldier) && this->maxPlayers >= i && pUnPatchSoldier[i] == true){
				pSoldier->orange = 4;
				pPatchSoldier[i] = true;
				pUnPatchSoldier[i] = false;
			}
		}
		else{
		//	FILE_LOG(logINFO) << "SS EN COURS SUPPRIMER CHAMSOLDIER OK";
			if (IsValidPtr(pSoldier)){
				unactiveSoldierChams(pSoldier, i);
			}
		}

	}

	void OnVehicleChams(ClientVehicleEntity* pcVehicleEntity, ClientPlayer* pEnnemie){
		
		//INTERFACAGE si l'oject vehicleEntity(veniceVehicleEntity) = clientplayer->vehicleEntity
		FILE_LOG(logINFO) << "PENNEMIES teamid" << pEnnemie->m_teamId;
		FILE_LOG(logINFO) << "PLOCALPLAYER teamid" << this->pLocalPlayer->m_teamId;
		if (pEnnemie->GetClientVehicleEntity() == pLocalPlayer->GetClientVehicleEntity() && pEnnemie->m_teamId == pLocalPlayer->m_teamId) return; 
		
		//FILE_LOG(logINFO) << "VEHICLE ADRESS =  0x" << std::hex << pcVehicleEntity;
		//les ptr doivent etre checked sinon crash car parfois 0x0 comme adress ptr
		//sschamdelete notre clean screenshot true desactive tout
		if (sschamDelete) return; //si on mode suppression pour SS
		if (!IsValidPtrEh(pcVehicleEntity)) return; //si ptr non valid
		//on cast le byte en int pour obtenir une valeur decimal pour notre check avant modif
		int checkOrangeCham = (int)pcVehicleEntity->orange;
		if (!this->isMeSoldierAlive(this->IamAlive)) return; //si je suis mort
		if (checkOrangeCham==1) return;
		FILE_LOG(logINFO) << "PENNEMIES " << std::hex << &pEnnemie;
		FILE_LOG(logINFO) << "PLOCALPLAYER " << std::hex << &this->pLocalPlayer;
		FILE_LOG(logINFO) << "pClientVehicleEntity " << std::hex << &pcVehicleEntity;
	//	if (pcVehicleEntity->vehicleLiveBarShowBool <= 1) return; //les ennemies
		
		//	pcVehicleEntity->vehicleLiveBarShowBool = 2;
			pcVehicleEntity->orange = 1;
			*(BYTE *)((DWORD_PTR)pcVehicleEntity + 0x1A) = 159;
					//pcVehicleEntity->chamHideBehind2Walls = 159;
				//*(BYTE *)(DWORD_PTR)(Entity->m_pEntity->pClientVehicle + 0x443) = 1;

		
	}

	void OffVehicleChams(ClientVehicleEntity* pcVehicleEntity){
	//	FILE_LOG(logINFO) << "VEHICLE ADRESS =  0x" << std::hex << pcVehicleEntity;
 		//les ptr doivent etre checked sinon crash car parfois 0x0 comme adress ptr
		//sschamdelete notre clean screenshot true desactive tout
		
			//on cast le byte en int pour obtenir une valeur decimal pour notre check avant modif
			if (IsValidPtrEh(pcVehicleEntity)){
				int checkOrangeCham = (int)pcVehicleEntity->orange;
				if (checkOrangeCham == 1){
				//	FILE_LOG(logINFO) << "Vehicle 0x" << std::hex << pcVehicleEntity;
					pcVehicleEntity->orange = 0;
					//pcVehicleEntity->vehicleLiveBarShowBool = 0;
					*(BYTE *)((DWORD_PTR)pcVehicleEntity + 0x1A) = 191;
					//pcVehicleEntity->chamHideBehind2Walls = 191;
				}

			}
	}


	void unactiveSoldierChams(ClientSoldierEntity* pSoldier, int i){
		if (IsValidPtrEh(pSoldier)){
				if (pUnPatchSoldier[i] == false){
					pSoldier->orange = 0;
					pPatchSoldier[i] = false;
					pUnPatchSoldier[i] = true;
				}
		}
	}


	void displaySoldierCham(int i, ClientPlayer* pClientPlayer, ClientSoldierEntity* pSoldier){

		if (!sschamDelete && this->isSoldierAlive(i, pSoldier) && this->IamAlive){
			//Active les chamsSoldiers lorsqu'ils sont invisible
			this->sVisibleSoldier[i] = true;
			pPatchSoldier[i] = true;
			this->activeSoldierChams(pSoldier, i);
		}
	}

	void deleteSoldierCham(int i, ClientSoldierEntity* pSoldier){
		/*FILE_LOG(logINFO) << "DELETE CHAM";
		FILE_LOG(logINFO) << "sschamDelete = " << sschamDelete;*/

			pUnPatchSoldier[i] = false;
			this->unactiveSoldierChams(pSoldier, i);
	}

	void deleteAllSoldierChams(){
		// check if a player is valid
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return;
		for (unsigned int i = 0; i < 70; i++)
		{
			ClientPlayer* pPlayer = pPlayerManager->GetPlayerById(i);
			if (!IsValidPtr(pPlayer) || pPlayer == pPlayerManager->m_pLocalPlayer) return; // if no player or player is me

			ClientSoldierEntity* pSoldier = pPlayer->GetClientSoldier();
			if (!IsValidPtr(pSoldier) || !IsValidPtr(pSoldier->m_pPredictedController)) return;

			ClientCharacterEntity* pEnemyClientCharacterEntity = (ClientCharacterEntity*)pPlayer->GetCharacterEntity();
			if (!IsValidPtr(pEnemyClientCharacterEntity)) return;

			if (pSoldier->m_pHealthComponent->m_Health <= 0.01f) return;

			if (pPlayer->m_teamId != pPlayerManager->m_pLocalPlayer->m_teamId){
			//	FILE_LOG(logINFO) << "UNCHAM SOLDIER START";
				chams* UnChamSoldierEntity = new chams(pPlayerManager, pPlayerManager->m_maxPlayerCount, this->IamAlive);
				UnChamSoldierEntity->deleteSoldierCham(i, pSoldier);

				pPatchSoldier[i] = false;
				pUnPatchSoldier[i] = true;
			}
		}
	}


	void deleteAllVehicleChams()
	{
		//FILE_LOG(logINFO) << "DELETEALLVEHCHAMS";
		for (int i = 0; i < MAX_VEHICLES; i++)
		{
			if (phkClientVehicleEntityTAB[i] != 0)
			{
			//	FILE_LOG(logINFO) << "VEHICLE I = " << i;
				ClientVehicleEntity* pClientVehicleEntity = phkClientVehicleEntityTAB[i];
				//FILE_LOG(logINFO) << "VEHICLE& I = 0x" << std::hex << pClientVehicleEntity;
				pClientVehicleEntity->vehicleLiveBarShowBool = 0;

				if (IsValidPtrEh(pClientVehicleEntity))
						this->OffVehicleChams(pClientVehicleEntity);
			}
		}
	}

	bool isSoldierAlive(int i, ClientSoldierEntity* pSoldier){
		// check if a player is valid
		ClientGameContext* pGContext = ClientGameContext::GetInstance();
		if (!IsValidPtr(pGContext)) return false;
		ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
		if (!IsValidPtr(pPlayerManager)) return false;
		if (!IsValidPtr(pSoldier)) return false;
		if (pSoldier->m_pHealthComponent->m_Health <= 0.017f || gameEnd){
			return false;
		}
		else{
			this->deleteSoldierCham(i, pSoldier);
			return true;
		}
	}

	bool isMeSoldierAlive(bool IamAlive){
		// check if my local soldier is valid
		return IamAlive;
	}
};

class chams;