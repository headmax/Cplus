class ssModule{
	/***********************************************/
	/*             VAULT DECLARATIONS              */
	/***********************************************/
	bool init_view_vault_teleport = false;
	bool init_jump_vault_max = false;
	Vec3 TPpos;
	float heightJump = 0;
	ID3D11Texture2D* CleanScreenShot;
	
	CopySubresourceRegion_t oCopySubresourceRegion = NULL;
	CopyResource_t oCopyResource;
	int g_SSwidth = -1;
	int g_SSheight = -1;
	public : 

		ssModule(ID3D11Texture2D* CleanScreenShot){
			
			this->CleanScreenShot = CleanScreenShot;
			ssModule* ssMod = new ssModule(this->CleanScreenShot);
			ssModule::oCopyResource = NULL;
		}

		 Vec3 checkBoxView(ClientSoldierEntity* pLocalSoldier){

			 if (g_Keyb_VK_X)
				 this->init_view_vault_teleport = (this->init_view_vault_teleport) ? false : true;

			 if (this->init_view_vault_teleport){
				 this->TPpos = relativeBoxPersonView(pLocalSoldier, true);
			 }
			 else{
				 this->TPpos = relativeBoxPersonView(pLocalSoldier, false);
			 }
			 return this->TPpos;
		 }


		 float checkMaxJump(){
			 /*FILE_LOG(logINFO) << "1 - init_jump_vault_max = " << init_jump_vault_max;*/
			 if (this->init_jump_vault_max){
				 this->heightJump = 300000.0f;
			 }
			 else{
				 this->heightJump = 0.0f;
			 }
			 return this->heightJump;
		 }

		 void Draw()
		 {
			 GetFps();
			 fb::DebugRenderer2::Singleton()->drawText(0, 0, fb::Color32(255, 0, 0, 200), g_szFPS, 2.0);
#ifdef DEBUG
			 fb::DebugRenderer2::Singleton()->drawText(1920 / 2, 0, fb::Color32(255, 0, 0, 200), "Debug", 2.0);
#endif

			 //TELEPORTATION INITIALISATION (HELPER + JUMP FROM TO)
			 if (IsIamAlive()){

				 ClientGameContext* pGContext = ClientGameContext::GetInstance();
				 if (!IsValidPtr(pGContext)) return;
				 ClientPlayerManager* pPlayerManager = pGContext->m_pPlayerManager;
				 if (!IsValidPtr(pPlayerManager)) return;
				 // get my position
				 ClientPlayer* pLocalPlayer = pPlayerManager->m_pLocalPlayer;
				 if (!IsValidPtr(pLocalPlayer)) return; // if no localplayer
				 ClientSoldierEntity* pLocalSoldier = pLocalPlayer->GetClientSoldier();


				 if (g_Keyb_VK_T){
					 Vec3 pDestination = checkBoxView(pLocalSoldier);
					 if (g_Keyb_VK_O){
						 ClientVaultInterface* Teleport = new ClientVaultInterface(pLocalSoldier, pDestination, true);
						 Teleport->Teleportation(pLocalSoldier, pDestination);
					 }
				 }

				 if (g_Keyb_VK_F4){
					 if (IsValidPtr(pLocalSoldier)){
						 /*FILE_LOG(logDEBUG) << "pLocalSoldier = 0x" << std::hex << (DWORD_PTR)pLocalSoldier;*/
						 Matrix soldierMatrix;
						 pLocalSoldier->GetTransform(&soldierMatrix);
						 Vec3 TPpos = soldierMatrix.Translation();
						 this->TPpos.y += 200;

						 ClientVaultInterface* Teleport = new ClientVaultInterface(pLocalSoldier, this->TPpos, true);
						 Teleport->Teleportation(pLocalSoldier, this->TPpos);
					 }
				 }

				 if (this->init_jump_vault_max && g_Keyb_VK_SPACE)
				 {
					 //Beep(3000, 100);
					 Matrix soldierMatrix;
					 pLocalSoldier->GetTransform(&soldierMatrix);
					 Vec3 TPpos = soldierMatrix.Translation();
					 ClientVaultInterface* Teleport = new ClientVaultInterface(pLocalSoldier, this->TPpos, true);
					 float heightJump = checkMaxJump();
					 /*FILE_LOG(logINFO) << "MAXJUMP = " << heightJump;*/
					 Teleport->MaxJump(pLocalSoldier);
				 }

				 if (g_Keyb_VK_F6 && (g_dwFrames == 1 || g_dwFrames == 30)){
					 this->init_jump_vault_max = (this->init_jump_vault_max) ? false : true;
					 Beep(2000, 20);
					 /*FILE_LOG(logINFO) << "2 - init_jump_vault_max = " << init_jump_vault_max;*/
				 }

				 if (g_Keyb_VK_F7 && (g_dwFrames == 1 || g_dwFrames == 30)){
					 Beep(2000, 20);
					 //deleteAllChams(false);
				 }

				 //immortalit marche en TEST RANGE
				 /*if (g_Keyb_VK_F7 && (g_dwFrames == 1 || g_dwFrames == 30))
				 {
				 pLocalSoldier->m_pSoldierData->m_Immortal = true;
				 pLocalSoldier->m_pClientVaultComponent->NewPosition = pLocalSoldier->m_pPredictedController->m_Position;

				 } */

				 if (g_Keyb_VK_F8 && (g_dwFrames == 1 || g_dwFrames == 30))
				 {
					 /*init_chams = (init_chams) ? false : true;
					 Beep(2000, 10);*/
				 }
			 }

			 DrawCrossHair(DxRenderer::GetInstance(), true);
			 Esp();
			 Minimap();
			 GetSpectators();
			 NoRecoil();
			 DrawTrailPoint();
		 }


	void runModule(){
		if (GetTickCount64() > g_oldCleanFrameCaptured) //SAVE CLEAN SS it's work
		{
			if (g_cleanFramesPass == 1){
				FILE_LOG(logINFO) << "SSMODULE";
				deleteAllChams(false);
			}
			if (g_cleanFramesPass > 3)
			{
				//Create clean ss
				ID3D11Texture2D* pBuffer;
				HRESULT hRet = DxRenderer::GetInstance()->m_pScreen->m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast< void** >(&pBuffer));
				if (!SUCCEEDED(hRet)) FILE_LOG(logERROR) << "hkPresent: GetBuffer failed with error " << std::hex << hRet;
				D3D11_TEXTURE2D_DESC td;
				pBuffer->GetDesc(&td);
				DxRenderer::GetInstance()->m_pDevice->CreateTexture2D(&td, NULL, &this->CleanScreenShot);
				DxRenderer::GetInstance()->m_pContext->CopyResource(this->CleanScreenShot, pBuffer);

				g_cleanFramesPass = 0;
				g_oldCleanFrameCaptured = (unsigned int)GetTickCount64() + 50042;
				FILE_LOG(logINFO) << "hkPresent: Clean Backbuffer saved.";
				/*DxTexture* dxTexture;
				printf("test %d", dxTexture->GetUsage());*/

			}
			g_cleanFramesPass++;
		}
		else
		{
				Draw();
		}
	}

	void __stdcall hkCopyResource(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
	{
		ID3D11Texture2D* pTexture = (ID3D11Texture2D*)pDstResource;
		D3D11_TEXTURE2D_DESC desc;
		pTexture->GetDesc(&desc);

		if (desc.Width == this->g_SSwidth && desc.Height == this->g_SSheight){
			this->g_SSwidth = -1;
			this->g_SSheight = -1;
			FILE_LOG(logINFO) << "hkCopyResource: SS Taken";
			this->oCopyResource(pContext, pDstResource, this->CleanScreenShot);
			return;
		}
		this->oCopyResource(pContext, pDstResource, pSrcResource);
	}

	void __stdcall hkCopySubresourceRegion(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
	{
		ID3D11Texture2D* pTexture = (ID3D11Texture2D*)pDstResource;
		D3D11_TEXTURE2D_DESC desc;
		pTexture->GetDesc(&desc);

		if (desc.Width == this->g_SSwidth && desc.Height == this->g_SSheight){
			this->g_SSwidth = -1;
			this->g_SSheight = -1;
			FILE_LOG(logINFO) << "hkCopySubresourceRegion: SS Taken";
			this->oCopySubresourceRegion(pContext, pDstResource, DstSubresource, DstX, DstY, DstZ, this->CleanScreenShot, SrcSubresource, pSrcBox);
			return;
		}
		this->oCopySubresourceRegion(pContext, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
	}



	void fHookCopyResource(){

	}

	void fUnhookCopyResource(){
		this->D3D11DeviceContextHook->dwHookMethod((DWORD64)this->oCopyResource, 47);
		this->D3D11DeviceContextHook->dwHookMethod((DWORD64)this->oCopySubresourceRegion, 46);
	}


	ssModule::~ssModule(){
		FILE_LOG(logINFO) << "SSMODULE DELETED";
	};
};