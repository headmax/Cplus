#include <Windows.h>
#include <fstream>
#include <dwmapi.h>
#include <TlHelp32.h>
#include <string>
#include <map> 
#include <atlstr.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>

#include "Audio.h" // - low - level audio API using XAudio2(DirectXTK for Audio public header)
#include "CommonStates.h" // - factory providing commonly used D3D state objects
#include "DirectXHelpers.h" // - misc C++ helpers for D3D programming
#include "DDSTextureLoader.h" // - light - weight DDS file texture loader
#include "Effects.h" // - set of built - in shaders for common rendering tasks
#include "GeometricPrimitive.h" // - draws basic shapes such as cubes and spheres
#include "Model.h" // - draws meshes loaded from.CMO or.SDKMESH files
#include "PrimitiveBatch.h" // - simple and efficient way to draw user primitives
#include "ScreenGrab.h" // - light - weight screen shot saver
#include "SimpleMath.h" // - simplified C++ wrapper for DirectXMath
#include "SpriteBatch.h" // - simple & efficient 2D sprite rendering
#include "SpriteFont.h" // - bitmap based text rendering
#include "VertexTypes.h" // - structures for commonly used vertex data formats
#include "WICTextureLoader.h" // - WIC - based image file texture loader
#include "resource.h"

typedef DirectX::SimpleMath::Vector2 float2;
typedef DirectX::SimpleMath::Vector3 float3;
typedef DirectX::SimpleMath::Vector4 float4;
typedef DirectX::SimpleMath::Matrix float4x4;
using namespace DirectX::SimpleMath;

//

//#define _XM_NO_INTRINSICS_ // sinon il aligne sur 16
//#define XM_NO_ALIGNMENT
//#define XM_STRICT_VECTOR4
//#include <DirectXMath.h>
//#include <D3D11.h>

//
bool g_Keyb_VK_F4, g_Keyb_VK_F5, g_Keyb_VK_F6, g_Keyb_VK_F7, g_Keyb_VK_F8, g_Keyb_VK_END, g_Mouse_VK_RBUTTON, g_Mouse_VK_LBUTTON, g_Keyb_VK_TAB, g_Keyb_VK_SHIFT, g_Keyb_VK_HOME, g_Keyb_VK_LEFT, g_Keyb_VK_UP, g_Keyb_VK_RIGHT, g_Keyb_VK_DOWN, g_Keyb_VK_INSERT, g_Keyb_VK_PRIOR, g_Keyb_VK_NEXT, g_Keyb_VK_SPACE, g_Keyb_VK_T, g_Keyb_VK_X, g_Keyb_VK_O, g_Keyb_VK_L, g_Keyb_VK_M;
//
//

#include "Eastl.h"
#include "Offsets.h"
#include "TypeInfo.h"
#include "log.h"
#include "fonctions.h"
#include "FrostbiteEnumDump.h"
#include "bfsdk.h"

/* pre missiles explosives declarations*/
#define MAX_MISSILES 64
#define MAX_EXPLOSIVES 128
#define MAX_BULLETS 128
#define MAX_VEHICLES 128

VeniceClientMissileEntity* phkVeniceClientMissileEntityTAB[MAX_MISSILES];
VeniceClientExplosionEntity* phkVeniceClientExplosionEntityTAB[MAX_EXPLOSIVES];
VeniceClientBulletEntity* phkVeniceClientBulletEntityTAB[MAX_BULLETS];
ClientVehicleEntity* phkClientVehicleEntityTAB[MAX_VEHICLES];

#include "vtbhooks.h"
#include "Chams.h"
#include "gamefonctions.h"
#include "drawinternal.h"
#include "kitexplosif.h"
#include "sphere.h"

#include "esp.h"
#include "vault.h"
#include "aimbot.h"
#include "norecoil.h"
#include <D3DCompiler.h>

/***********************************************/
/*    BF4 DECLARATIONS GAMEHOOKS ADDRESS       */
/***********************************************/
#define VTABLE_VENICECLIENTMISSILEENTITY 0x1401d2e1a//0x141a2aa40//0x141A3D5C0 //Sig: 48 8D 05 ? ? ? ? 8B DA 48 8B F9 48 89 01 48 8D 05 ? ? ? ? 48 89 41 60 48 8D 05 ? ? ? ? 48 89 81 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 81 ? ? ? ? E8 ? ? ? ? F6 C3 01 74 08
#define VTABLE_VENICECLIENTBULLETENTITY 0x14027b8ea//0x141A2A660 //0x141A2A660//0x141A4E240//0x141A3D1E0//die bug 0x141a879d8//0x141A3D1E0 // il semble qu'il n'y ait que mes bullets parfois d'autres ....Sig: 48 8D 05 ? ? ? ? 8B DA 48 8B F9 48 89 01 48 8D 05 ? ? ? ? 48 89 41 60 48 8D 05 ? ? ? ? 48 89 81 ? ? ? ? E8 ? ? ? ? F6 C3 01 74 08 48 8B CF E8 ? ? ? ? 48 8B C7 48 8B 5C 24 ?
//#define VTABLE_VENICECLIENTEXPLOSIONENTITY 0x141a2a950 //0x141A3D4D0 // ok sauf transform (ce n'est pas les mines c4 etc... mais des explosions...)
#define VTABLE_SERVEREXPLOSIONPACKENTITY 0x141CB6F60 // ne fonctionne qu'en test range
#define VTABLE_CLIENTEXPLOSIONPACKENTITY 0x141CBB2A0 
#define VTABLE_CLIENTPROXYGRENADEENTITY 0x141CBC1B0
#define VTABLE_VENICECLIENTEXPLOSIONENTITY 0x141CBB2A0//0x141CBB2A0
#define VTABLE_CLIENTPICKUPENTITY 0x141C9BF40//0x141cb0b20
#define VTABLE_CLIENTVEHICLEHIDDEN 0x142474ad0 //hide tous les vehicles si on utilise veniceclientexplosionentity hook //Super pour une meilleur vue
#define VTABLE_CLIENTVEHICLEENTITY 0x141B9B210 //0x141bad5e0//0x14247B6B8//0x142474ad0
#define VTABLE_CLIENTISDEAD 0x14048217F//0x141a879d8; //client isdead

/***********************************************/
/*    BF4 TYPE CHEAT 1-HIGH 2-MEDIUM 3-SHORT   */
/***********************************************/


/***********************************************/
/*    BF4 DECLARATIONS MISSILES HOOKS          */
/***********************************************/
typedef PVOID(__fastcall* tFuncMissile)(PVOID pThis);
tFuncMissile oFuncVeniceClientMissileEntity0 = NULL;
tFuncMissile oFuncVeniceClientMissileEntity8 = NULL;

/***********************************************/
/*    BF4 DECLARATIONS BULLETS HOOKS          */
/***********************************************/
typedef PVOID(__fastcall* tFuncBullet)(PVOID pThis);
tFuncBullet oFuncVeniceClientBulletEntity0 = NULL;
tFuncBullet oFuncVeniceClientBulletEntity8 = NULL;

/***********************************************/
/*    BF4 DECLARATIONS EXPLOSIVES HOOKS          */
/***********************************************/
typedef PVOID(__fastcall* tFuncExplosive)(PVOID pThis);
tFuncExplosive oFuncVeniceClientExplosiveEntity0 = NULL;
tFuncExplosive oFuncVeniceClientExplosiveEntity8 = NULL;


/***********************************************/
/*    BF4 DECLARATIONS VEHICLES HOOKS          */
/***********************************************/
typedef PVOID(__fastcall* tFuncVehicle)(PVOID pThis);
tFuncVehicle oFuncClientVehicleEntity0 = NULL;
tFuncVehicle oFuncClientVehicleEntity8 = NULL;

/***********************************************/
/*             VAULT DECLARATIONS              */
/***********************************************/
bool init_view_vault_teleport = false;
bool init_jump_vault_max = false;
Vec3 TPpos;
float heightJump = 0;
//bool old_Init_chams = false;
//bool init_chams = true;


/*HRSRC hRsrc = FindResource(inj_hModule, MAKEINTRESOURCE(IDR_DDS1), "DDS");
HGLOBAL hGlob = LoadResource(inj_hModule, hRsrc);
DWORD dwResSize = SizeofResource(inj_hModule, hRsrc);
LPVOID pRes = LockResource(hGlob);
HRESULT hr = DirectX::CreateDDSTextureFromMemory(pDxRenderer->m_pDevice, (const uint8_t *)pRes, dwResSize, nullptr, &iconRessourceView);
*/

DirectX::SpriteBatch* spriteBatch;
ID3D11ShaderResourceView* iconRessourceView = nullptr;

void drawSprite(float x, float y, ID3D11ShaderResourceView* texture){
	/*std::unique_ptr<DirectX::SpriteBatch>(new DirectX::SpriteBatch(DxRenderer::GetInstance()->m_pContext));
	spriteBatch->Begin();
	spriteBatch->Draw(texture, DirectX::XMFLOAT2(x, y));
	spriteBatch->End();*/
}

void __stdcall loadTexture(){
	HRSRC hRsrc = FindResource(inj_hModule, MAKEINTRESOURCE(IDR_DDS1), "DDS");
	HGLOBAL hGlob = LoadResource(inj_hModule, hRsrc);
	DWORD dwResSize = SizeofResource(inj_hModule, hRsrc);
	LPVOID pRes = LockResource(hGlob);
	HRESULT hr = DirectX::CreateDDSTextureFromMemory(DxRenderer::GetInstance()->m_pDevice, (const uint8_t *)pRes, dwResSize, nullptr, &iconRessourceView);
	if (FAILED(hr))
		FILE_LOG(logINFO) << "ERROR LOADING TEXTURE";
	else
		FILE_LOG(logINFO) << "LOADING TEXTURE";
}
/*
void routine(){

	void Sprite32(Vector2 pos2d, Color color = Colors::White, float rotation = 0.0f, float scale = 0.0f)
	{
		RECT sourceRectangle; // ({ 470, 465, 470 + 32, 465 + 32 });
		sourceRectangle.left = 470;
		sourceRectangle.top = 465;
		sourceRectangle.right = 470 + 32;
		sourceRectangle.bottom = 465 + 32;

		m_states = std::unique_ptr<DirectX::CommonStates>(new DirectX::CommonStates(pDxRenderer->m_pDevice));

		m_SpriteBatch->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
		//m_SpriteBatch->Draw(iconRessourceView, Vector2(0, 0), nullptr, Colors::White, 0.0f);
		m_SpriteBatch->Draw(iconRessourceView, pos2d, &sourceRectangle, color, rotation, Vector2(32 / 2, 32 / 2), scale);
		m_SpriteBatch->End();
	}
}
*/
/////////////////////////////////////////////
bool bRunThreads = true;
//HINSTANCE  inj_hModule;
/////////////////////////////////////////////
/*HRSRC hRsrc = FindResource(inj_hModule, MAKEINTRESOURCE(IDR_DDS1), "DDS");
HGLOBAL hGlob = LoadResource(inj_hModule, hRsrc);
DWORD dwResSize = SizeofResource(inj_hModule, hRsrc);
LPVOID pRes = LockResource(hGlob);
CVMTHookManager64* CreateDDSTextureFromMemoryHook = NULL;
typedef HRESULT(__stdcall *CreateDDSTextureFromMemory_t)(ID3D11Device *pDevice, LPVOID pRes, DWORD dwResSize, DirectX::DDS_ALPHA_MODE*, ID3D11ShaderResourceView* &iconRessourceView);
CreateDDSTextureFromMemory_t oCreateDDSTextureFromMemory = NULL;*/

CVMTHookManager64* DXGISwapChainHook = NULL;
typedef HRESULT(__stdcall *Present_t)(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags);
Present_t oPresent = NULL;

CVMTHookManager64* CreateTexture2DHook = NULL;
typedef HRESULT(__stdcall *CreateTexture2D_t)(ID3D11Device *pDevice, const D3D11_TEXTURE2D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture2D **ppTexture2D);
CreateTexture2D_t oCreateTexture2D = NULL;

CVMTHookManager64* PreFrameHook = NULL;
typedef float(__stdcall *PreFrame_t) (__int64* ptr, float DeltaTime);
PreFrame_t oPreFrame = NULL;

CVMTHookManager64* D3D11DeviceContextHook = NULL;
typedef void(__stdcall* CopyResource_t)(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource);
CopyResource_t oCopyResource = NULL;


typedef void(__stdcall* CopySubresourceRegion_t)(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox);
CopySubresourceRegion_t oCopySubresourceRegion = NULL;


Vec3 checkBoxView(ClientSoldierEntity* pLocalSoldier){

	if (g_Keyb_VK_X)
		init_view_vault_teleport = (init_view_vault_teleport) ? false : true;

	if (init_view_vault_teleport){
		TPpos = relativeBoxPersonView(pLocalSoldier, true);
	}
	else{
		TPpos = relativeBoxPersonView(pLocalSoldier, false);
	}
	return TPpos;
}



float checkMaxJump(){
	/*FILE_LOG(logINFO) << "1 - init_jump_vault_max = " << init_jump_vault_max;*/
	if (init_jump_vault_max){
		heightJump = 300000.0f;
	}
	else{
		heightJump = 0.0f;
	}
	return heightJump;
}


void WriteLogFile(const char* szString, int i, char* buffer)
{
	FILE* pFile = fopen("logFile.txt", "a");
	fprintf(pFile, "%s -> [%i] -> (%s)\n", szString, i, buffer);
	fclose(pFile);
}

int makeSigsPkBter(){
	//Punkbuster stuff :: 14:32:30
	static PBSigTable* pSigTable = PBSigTable::GetInstance();

	if (!pSigTable)
		pSigTable = PBSigTable::GetInstance();
	else
	{
		for (int i = 0; i < (int)pSigTable->dwTableSize; i++)
		{
			PBScanSignature* pSignature = pSigTable->GetScanSignature(i);

			if (pSignature)
			{
				char szBuffer[1024] = { 0 };
				sprintf(szBuffer, "T[%C] O[%X] L[%i] %02X %02X %02X %02X", pSignature->m_ScanType, pSignature->m_Offset, (int)pSignature->m_ScanLength, pSignature->m_Byte1, pSignature->m_Byte2, pSignature->m_Byte3, pSignature->m_Byte4);

				for (int j = 0; j < (int)pSignature->m_ScanLength && j < 128; j++)
				{
					if (pSignature->m_Signature[j] > 0xFF)//wildcard?
						sprintf(&szBuffer[(int)strlen(szBuffer)], " ??");
					else
						sprintf(&szBuffer[(int)strlen(szBuffer)], " %02X", pSignature->m_Signature[j]);
				}

				sprintf(&szBuffer[(int)strlen(szBuffer)], " [ %X : %X : %X : %X : %X ]", pSignature->m_Arg1, pSignature->m_Arg2, pSignature->m_Arg3, pSignature->m_Enabled, pSignature->m_Arg5);
				FILE_LOG(logINFO) << "Signature[" << i << "] :: " << szBuffer;
				WriteLogFile("Signature[%i] :: %s", i, szBuffer);
			}
		}
		FILE_LOG(logINFO) << "Signature[0] :: NULL";
		WriteLogFile("Signature[%i] :: %s", 0, "");
		return 0;
	}
}



void Draw()
{
	//GetFps();
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
				TPpos.y += 200;

				ClientVaultInterface* Teleport = new ClientVaultInterface(pLocalSoldier, TPpos, true);
				Teleport->Teleportation(pLocalSoldier, TPpos);
			}
		}

		if (init_jump_vault_max && g_Keyb_VK_SPACE)
		{
			//Beep(3000, 100);
			Matrix soldierMatrix;
			pLocalSoldier->GetTransform(&soldierMatrix);
			Vec3 TPpos = soldierMatrix.Translation();
			ClientVaultInterface* Teleport = new ClientVaultInterface(pLocalSoldier, TPpos, true);
			float heightJump = checkMaxJump();
			/*FILE_LOG(logINFO) << "MAXJUMP = " << heightJump;*/
			Teleport->MaxJump(pLocalSoldier);
		}

		if (g_Keyb_VK_F6 && (g_dwFrames == 1 || g_dwFrames == 30)){
			init_jump_vault_max = (init_jump_vault_max) ? false : true;
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
	NoRecoil();
	GetSpectators();

	//makeSigsPkBter();
	/*Minimap();
	GetSpectators();
	NoRecoil();*/
	DrawTrailPoint();
}


int g_SSwidth = -1;
int g_SSheight = -1;


ID3D11Texture2D* CleanScreenShot[5];
ID3D11Texture2D* pBuffer[5];
D3D11_TEXTURE2D_DESC td[5];
void makeScreenShot(int i, int counter){
	//Create clean ss


	HRESULT hRet = DxRenderer::GetInstance()->m_pScreen->m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast< void** >(&pBuffer[i]));
	if (!SUCCEEDED(hRet)) FILE_LOG(logERROR) << "hkPresent: GetBuffer failed with error SS_ 0x" << std::hex << hRet;

	pBuffer[i]->GetDesc(&td[i]);
	DxRenderer::GetInstance()->m_pDevice->CreateTexture2D(&td[i], NULL, &CleanScreenShot[i]);
	DxRenderer::GetInstance()->m_pContext->CopyResource(CleanScreenShot[i], pBuffer[i]);

	g_cleanFramesPass[i] = 0;
	g_oldCleanFrameCaptured[i] = (unsigned int)GetTickCount64() + counter;
	FILE_LOG(logINFO) << "hkPresent: Clean Backbuffer saved. SS_" << i;
	//D3DXSaveTextureToFile("Desktop.bmp", D3DXIFF_BMP, (LPDIRECT3DBASETEXTURE9)CleanScreenShot[i], NULL);
	/*DxTexture* dxTexture;
	printf("test %d", dxTexture->GetUsage());*/
}


/********************************************************************************/
/*                   F : hkCopySubresourceRegion (void __stdcall)
/*******************************************************************************/
/*	+@type void __stdcall
+@arg1 = PTR* class [ID3D11DeviceContext]
+@arg2 = PTR* class [ID3D11Resource]
+@arg3 = UINT [Destination subresource]
+@arg4 = UINT [Destination X]
+@arg5 = UINT [Destination Y]
+@arg6 = UINT [Destination Z]
+@arg7 = PTR* class [ID3D11Resource] (Source resource)
+@arg6 = UINT [Source SubResource]
+@arg6 = const PTR* class [D3D11_BOX] (ptr box)
+@return void
+@goal = This Take a ScreenShot from PunkBuster Servers (HOOK)
/********************************************************************************/
void __stdcall hkCopySubresourceRegion(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
{
	ID3D11Texture2D* pTexture = (ID3D11Texture2D*)pDstResource;
	D3D11_TEXTURE2D_DESC desc;
	pTexture->GetDesc(&desc);



	if (desc.Width == g_SSwidth && desc.Height == g_SSheight){
		int RandIndex = rand() % 4; //random sur 5 SS
		g_SSwidth = -1;
		g_SSheight = -1;
		FILE_LOG(logINFO) << "hkCopySubresourceRegion: SS Taken";
		oCopySubresourceRegion(pContext, pDstResource, DstSubresource, DstX, DstY, DstZ, CleanScreenShot[RandIndex], SrcSubresource, pSrcBox);
		return;
	}
	oCopySubresourceRegion(pContext, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
}


/********************************************************************************/
/*                   F : hkCopyResource (void __stdcall)
/*******************************************************************************/
/*	+@type void __stdcall
+@arg1 = PTR* class [ID3D11DeviceContext]
+@arg2 = PTR* class [ID3D11Resource]
+@arg3 = PTR* class [ID3D11Resource]
+@return void
+@goal = This Take a ScreenShot with Console Game (HOOK)
/********************************************************************************/
int ssTaken = 0;
void __stdcall hkCopyResource(ID3D11DeviceContext* pContext, ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
{
	
	ID3D11Texture2D* pTexture = (ID3D11Texture2D*)pDstResource;
	D3D11_TEXTURE2D_DESC desc;
	pTexture->GetDesc(&desc);

	if (desc.Width == g_SSwidth && desc.Height == g_SSheight){
		int RandIndex = rand() % 4;
		g_SSwidth = -1;
		g_SSheight = -1;
		FILE_LOG(logINFO) << "hkCopyResource: SS Taken = " << ssTaken;
		ssTaken = (ssTaken >= 5) ? 0 : ssTaken;
		oCopyResource(pContext, pDstResource, CleanScreenShot[ssTaken]);
		ssTaken++;
		return;
	}
	oCopyResource(pContext, pDstResource, pSrcResource);
}



/********************************************************************************/
/*                    HOOK VTB VENICECLIENTMISSILEENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientMissileEntity0
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Creation missile) Missiles Objects Array +1
*******************************************************************************/
PVOID __fastcall hkFuncVeniceClientMissileEntity0(PVOID pThis)
{
	//hookChoices::vtbhooks* testVtbHooks = new hookChoices::vtbhooks(pThis, "Missile");

	bool alreadyintab = false;
	for (int i = 0; i < MAX_MISSILES; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkVeniceClientMissileEntityTAB[i] == (VeniceClientMissileEntity*)pThis) alreadyintab = true;
	}

	if (alreadyintab == false)
	{
		for (int i = 0; i < MAX_MISSILES; i++)
		{
			if (!IsValidPtrEh(pThis)) continue;
			if (phkVeniceClientMissileEntityTAB[i] == 0)
			{
				phkVeniceClientMissileEntityTAB[i] = (VeniceClientMissileEntity*)pThis;
				//FILE_LOG(logINFO) << "call create missile pThis: " << std::hex << pThis << " i: " << i;
				break;
			}
		}
	}
	//FILE_LOG(logINFO) << "call missile from: " << _ReturnAddress();
	//FILE_LOG(logINFO) << "call missile pThis: " << std::hex << pThis;
	PVOID ret = oFuncVeniceClientMissileEntity0(pThis);
	return ret;
}


/********************************************************************************/
/*                    HOOK VTB VENICECLIENTMISSILEENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientMissileEntity8
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Destruction missile) Missiles Objects array -1
*******************************************************************************/

PVOID __fastcall hkFuncVeniceClientMissileEntity8(PVOID pThis)
{

	for (int i = 0; i < MAX_MISSILES; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkVeniceClientMissileEntityTAB[i] == (VeniceClientMissileEntity*)pThis)
		{
			phkVeniceClientMissileEntityTAB[i] = 0;
			//FILE_LOG(logINFO) << "call Death missile del pThis: " << std::hex << pThis << " i: " << i;
			break;
		}
	}
	//FILE_LOG(logINFO) << "call Death missile from: " << _ReturnAddress();
	PVOID ret = oFuncVeniceClientMissileEntity8(pThis);
	return ret;
}


/********************************************************************************/


/********************************************************************************/
/*                    HOOK VTB VENICECLIENTBULLETENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientBulletEntity0
/*******************************************************************************/
/*	+@type float
+@arg1 = PVOID
+@return PVOID
/*	Hook (Creation Bullet) Bullets Objects Array +1
*******************************************************************************/
/*PVOID __fastcall hkFuncVeniceClientBulletEntity0(PVOID pThis)
{
#define MAX_DIE 1
	//hookChoices::vtbhooks* testVtbHooks = new hookChoices::vtbhooks(pThis, "Bullet");
	bool alreadyintab = false;
	for (int i = 0; i < MAX_DIE; i++)
	{
		if (IsValidPtrEh(phkVeniceClientBulletEntityTAB[i]))
		if (phkVeniceClientBulletEntityTAB[i] == (VeniceClientBulletEntity*)pThis) alreadyintab = true;
	}

	if (alreadyintab == false)
	{
		for (int i = 0; i < MAX_DIE; i++)
		{
			if (phkVeniceClientBulletEntityTAB[i] == 0)
			{
				if (IsValidPtrEh(pThis))
				phkVeniceClientBulletEntityTAB[i] = (VeniceClientBulletEntity*)pThis;
				FILE_LOG(logINFO) << "call create die pThis: " << std::hex << pThis << " i: " << i;
				break;
			}
		}
	}
	FILE_LOG(logINFO) << "call die from: " << _ReturnAddress();
	if (IsValidPtrEh(pThis))
	FILE_LOG(logINFO) << "call die pThis: " << std::hex << pThis;
	PVOID ret = oFuncVeniceClientBulletEntity0(pThis);
	return ret;
}*/


PVOID __fastcall hkFuncVeniceClientBulletEntity0(PVOID pThis)
{
	//hookChoices::vtbhooks* testVtbHooks = new hookChoices::vtbhooks(pThis, "Bullet");
	bool alreadyintab = false;
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
			if (phkVeniceClientBulletEntityTAB[i] == (VeniceClientBulletEntity*)pThis) alreadyintab = true;
	}

	if (alreadyintab == false)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!IsValidPtrEh(pThis)) continue;
			if (phkVeniceClientBulletEntityTAB[i] == 0)
			{
				//TABLEAU DE BALLES DE TOUT LES JOUEURS
				phkVeniceClientBulletEntityTAB[i] = (VeniceClientBulletEntity*)pThis;
				//FILE_LOG(logINFO) << "call create bullet pThis: " << std::hex << pThis << " i: " << i;
				break;
			}
		}
	}
	//FILE_LOG(logINFO) << "call bullet from: " << _ReturnAddress();
	//FILE_LOG(logINFO) << "call bullet pThis: " << std::hex << pThis;
	//	DrawBullets();
		PVOID ret = oFuncVeniceClientBulletEntity0(pThis);
	return ret;
}


/********************************************************************************/
/*                    HOOK VTB VENICECLIENTBULLETENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientBulletEntity8
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Destruction Bullet) Bullets Objects array -1
*******************************************************************************/

PVOID __fastcall hkFuncVeniceClientBulletEntity8(PVOID pThis)
{

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkVeniceClientBulletEntityTAB[i] == (VeniceClientBulletEntity*)pThis)
		{
			phkVeniceClientBulletEntityTAB[i] = 0;
			//FILE_LOG(logINFO) << "call Death bullet del pThis: " << std::hex << pThis << " i: " << i;
			break;
		}
	}
	//FILE_LOG(logINFO) << "call Death bullet from: " << _ReturnAddress();
	PVOID ret = oFuncVeniceClientBulletEntity8(pThis);
	return ret;
}



/********************************************************************************/
/*                    HOOK VTB VENICECLIENTEXPLOSIVEENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientExplosiveEntity0
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Creation explosive) Explosives Objects Array +1
*******************************************************************************/
PVOID __fastcall hkFuncVeniceClientExplosiveEntity0(PVOID pThis)
{
	//hookChoices::vtbhooks* testVtbHooks = new hookChoices::vtbhooks(pThis, "Explosive");
	bool alreadyintab = false;
	for (int i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if (IsValidPtrEh(pThis))
		if (phkVeniceClientExplosionEntityTAB[i] == (VeniceClientExplosionEntity*)pThis) alreadyintab = true;
	}

	if (alreadyintab == false)
	{
		for (int i = 0; i < MAX_EXPLOSIVES; i++)
		{
			if (!IsValidPtrEh(pThis)) continue;
			if (phkVeniceClientExplosionEntityTAB[i] == 0)
			{
				phkVeniceClientExplosionEntityTAB[i] = (VeniceClientExplosionEntity*)pThis;
				//FILE_LOG(logINFO) << "call create Explosive pThis: " << std::hex << pThis << " i: " << i;
				break;
			}
		}
	}
	//FILE_LOG(logINFO) << "call Explosive from: " << _ReturnAddress();
	//FILE_LOG(logINFO) << "call Explosive pThis: " << std::hex << pThis;
//	DrawExplosives(); //??????????????????????????????????????????????????????
	PVOID ret = oFuncVeniceClientExplosiveEntity0(pThis);
	return ret;
}


/********************************************************************************/
/*                    HOOK VTB VENICECLIENTEXPLOSIVEENTITY						*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncVeniceClientExplosiveEntity8
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Destruction Explosive) Explosives Objects array -1
*******************************************************************************/

PVOID __fastcall hkFuncVeniceClientExplosiveEntity8(PVOID pThis)
{

	for (int i = 0; i < MAX_EXPLOSIVES; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkVeniceClientExplosionEntityTAB[i] == (VeniceClientExplosionEntity*)pThis)
		{
			phkVeniceClientExplosionEntityTAB[i] = 0;
			//FILE_LOG(logINFO) << "call Death Explosive del pThis: " << std::hex << pThis << " i: " << i;
			break;
		}
	}
	//FILE_LOG(logINFO) << "call Death Explosive from: " << _ReturnAddress();
	PVOID ret = oFuncVeniceClientExplosiveEntity8(pThis);
	return ret;
}


/********************************************************************************/
/*                    HOOK VTB CLIENTVEHICLEENTITY								*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncClientVehicleEntity0
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Creation vehicle) Vehicles Objects Array +1
*******************************************************************************/
PVOID __fastcall hkFuncClientVehicleEntity0(PVOID pThis)
{
	//hookChoices::vtbhooks* testVtbHooks = new hookChoices::vtbhooks(pThis, "Vehicle");
	bool alreadyintab = false;
	for (int i = 0; i < MAX_VEHICLES; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkClientVehicleEntityTAB[i] == (ClientVehicleEntity*)pThis) alreadyintab = true;
	}

	if (alreadyintab == false)
	{
		for (int i = 0; i < MAX_VEHICLES; i++)
		{
			if (!IsValidPtrEh(pThis)) continue;
			if (phkClientVehicleEntityTAB[i] == 0)
			{
				phkClientVehicleEntityTAB[i] = (ClientVehicleEntity*)pThis;
			//	FILE_LOG(logINFO) << "call create Vehicle pThis: " << std::hex << pThis << " i: " << i;
				break;
			}
		}
	}
	//FILE_LOG(logINFO) << "call Vehicle from: " << _ReturnAddress();
	//FILE_LOG(logINFO) << "call Vehicle pThis: " << std::hex << pThis;
	PVOID ret = oFuncClientVehicleEntity0(pThis);
	return ret;
}


/********************************************************************************/
/*                    HOOK VTB CLIENTVEHICLEENTITY								*/
/********************************************************************************/
/*                   F : PVOID __fastcall  hkFuncClientVehicleEntity0
/*******************************************************************************/
/*	+@type float
	+@arg1 = PVOID
	+@return PVOID
/*	Hook (Destruction vehicle) Vehicles Objects array -1
*******************************************************************************/

PVOID __fastcall hkFuncClientVehicleEntity8(PVOID pThis)
{

	for (int i = 0; i < MAX_VEHICLES; i++)
	{
		if (!IsValidPtrEh(pThis)) continue;
		if (phkClientVehicleEntityTAB[i] == (ClientVehicleEntity*)pThis)
		{
			phkClientVehicleEntityTAB[i] = 0;
			//FILE_LOG(logINFO) << "call Death Vehicle del pThis: " << std::hex << pThis << " i: " << i;
			break;
		}
	}
	//FILE_LOG(logINFO) << "call Death Vehicle from: " << _ReturnAddress();
	PVOID ret = oFuncClientVehicleEntity8(pThis);
	return ret;
}




/********************************************************************************/
/*                    void DrawGame(bool end)   								*/
/********************************************************************************/
/*                   F : VOID  DrawGame
/*******************************************************************************/
/*	+@type void
	+@arg1 = bool
	+@return void
/*	Dessin general
*******************************************************************************/
void DrawGame(bool end){
	if (end){
		sschamDelete = false;
	}
	sschamDelete = ((!gameDead && !sschamDelete )|| !sschamDelete) ? false : true;
	if (!sschamDelete)
		Draw();
}




/********************************************************************************/
/*                    HKPRESENT HOOK + SAVE ALL SS                              */
/********************************************************************************/
//unsigned int g_cleanFramesPass = 0;
//unsigned int g_oldCleanFrameCaptured = 0;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapchain, UINT SyncInterval, UINT Flags)
{
	/*int iHeight = (int)g_Renderer->m_settings->ScreenHeight;
	int iWidth = (int)g_Renderer->m_settings->ScreenWidth;

	if (iHeight != g_Renderer->m_Height || iWidth != g_Renderer->m_Width)
	{
	
	int iCenterX = (int)iWidth / 2;
	int iCenterY = (int)iHeight / 2;
	}*/

	//Désactivation des visuals helpers du jeux
	//old_Init_chams = init_chams;
	bool IamAlive = booltestIsAlive();
	if (!IsIamAlive()){
	//	FILE_LOG(logINFO) << "SCREENSHOT NOW CAN BE TAKEN NO DRAWING...";

		if (GetTickCount64() > g_oldCleanFrameCaptured[0]) //SAVE CLEAN SS it's work
		{
			sschamDelete = true;
			if (g_cleanFramesPass[0] == 1){
				deleteAllChams(true);
			}
			if (g_cleanFramesPass[0] > 3)
			{
				sschamDelete = true;
				makeScreenShot(0, 6255);
			}
			if (g_cleanFramesPass[1] == 4)
			{
				g_cleanFramesPass[1] = 4;
				makeScreenShot(1, 6255);
			}
			if (g_cleanFramesPass[2] == 5)
			{
				g_cleanFramesPass[2] = 5;
				makeScreenShot(2, 6255);
				g_cleanFramesPass[2] = 0;
			}
			if (g_cleanFramesPass[3] == 6)
			{
				g_cleanFramesPass[3] = 6;
				makeScreenShot(3, 6255);
				g_cleanFramesPass[3] = 0;
			}
			if (g_cleanFramesPass[4] == 7)
			{
				g_cleanFramesPass[4] = 7;
				makeScreenShot(4, 6255);
				g_cleanFramesPass[0] = 0;
			}
			g_cleanFramesPass[0]++;
			g_cleanFramesPass[1]++;
			g_cleanFramesPass[2]++;
			g_cleanFramesPass[3]++;
			g_cleanFramesPass[4]++;
			sschamDelete = true;

		}
	}
	else{


		if (GetTickCount64() > g_oldCleanFrameCaptured[0]) //SAVE CLEAN SS it's work
		{
			//bool desactivation des chams
			sschamDelete = true;

			//Suppression de tout les chams dessinés en Frame 1
			if (g_cleanFramesPass[0] == 1){
				deleteAllChams(true);
			}
			//Creation 1ere SS en Frame 3
			if (g_cleanFramesPass[0] > 3)
			{
				sschamDelete = true;
				makeScreenShot(0, 50042);
			}

			//Creation 2ème SS en Frame 4
			if (g_cleanFramesPass[1] == 4)
			{
				g_cleanFramesPass[1] = 4;
				makeScreenShot(1, 50042);
			}

			//Creation 3ème SS en Frame 5
			if (g_cleanFramesPass[2] == 5)
			{
				g_cleanFramesPass[2] = 5;
				makeScreenShot(2, 50042);
				g_cleanFramesPass[2] = 0;
			}

			//Creation 4ème SS en Frame 6
			if (g_cleanFramesPass[3] == 6)
			{
				g_cleanFramesPass[3] = 6;
				makeScreenShot(3, 50042);
				g_cleanFramesPass[3] = 0;
			}

			//Creation 5ème SS en Frame 7
			if (g_cleanFramesPass[4] == 7)
			{
				g_cleanFramesPass[4] = 7;
				makeScreenShot(4, 50042);
				g_cleanFramesPass[0] = 0;
			}

			g_cleanFramesPass[0]++;
			g_cleanFramesPass[1]++;
			g_cleanFramesPass[2]++;
			g_cleanFramesPass[3]++;
			g_cleanFramesPass[4]++;
			sschamDelete = true;

		}
		else{
			sschamDelete = true;
			DrawGame(true);
		}
	}

	return oPresent(pSwapchain, SyncInterval, Flags);
}




HRESULT __stdcall hkCreateTexture2D(ID3D11Device* pDevice, const D3D11_TEXTURE2D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture2D **ppTexture2D)
{
	if (pDesc->CPUAccessFlags == D3D11_CPU_ACCESS_READ) //Check if this is really a screenshot
	{
		g_SSwidth = pDesc->Width;
		g_SSheight = pDesc->Height;
		FILE_LOG(logINFO) << "hkCreateTexture2D: SS Width: " << g_SSwidth << " Height: " << g_SSheight;

		HRESULT hRet = oCreateTexture2D(pDevice, pDesc, pInitialData, ppTexture2D);
		if (!SUCCEEDED(hRet)) FILE_LOG(logERROR) << "hkCreateTexture2D: oCreateTexture2D failed with error " << std::hex << hRet;
		return hRet;
	}
	return oCreateTexture2D(pDevice, pDesc, pInitialData, ppTexture2D);
}
/*
HRESULT __stdcall hkCreateDDSTextureFromMemory(ID3D11Device *pDevice, LPVOID pRes, DWORD dwResSize, DirectX::DDS_ALPHA_MODE*, ID3D11ShaderResourceView* &iconRessourceView)
{
	if (IsValidPtrEh(pRes) && IsValidPtrEh(iconRessourceView)){
		HRESULT hRet = oCreateDDSTextureFromMemory(pDevice, pRes, dwResSize, nullptr, iconRessourceView);
		if (!SUCCEEDED(hRet)) FILE_LOG(logERROR) << "hkCreateDDSTextureFromMemory: CreateDDSTextureFromMemory failed with error " << std::hex << hRet;
		return hRet;
	}
		return oCreateDDSTextureFromMemory(pDevice, pRes, dwResSize, nullptr, iconRessourceView);
}
*/



float __stdcall hkPreFrame(__int64* ptr, float DeltaTime)
{
	float returnval = oPreFrame(ptr, DeltaTime);

	Aimbot();

	BorderInputNode* pBorderInputNode = BorderInputNode::GetInstance();
	if (!IsValidPtr(pBorderInputNode)) return returnval;
	for (int i = 0; i < 123; i++)
	{
		pBorderInputNode->m_inputCache->flInputBuffer[i] += g_pInputBuffers[i];
		//if (g_pBorderInputNode->m_inputCache->flInputBuffer[i] == 0.0) g_pBorderInputNode->m_inputCache->flInputBuffer[i] = g_pInputBuffers[i];
		g_pInputBuffers[i] = 0.0f;
	}
	return returnval;
}



void OnUnloadAndKeybThread(HMODULE hModule)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_DELETE) & 0x8000)
		{
			//STOP GAMES PATCH AND FUNCTIONALITY 
			/*chams*/
			sschamDelete = true;
			gameEnd = true;
			FILE_LOG(logINFO) << "DEBUT SUPPRIMER CHAMS";
			deleteAllChams(true);
			FILE_LOG(logINFO) << "FIN SUPPRIMER CHAMS";

			// stop threads
			bRunThreads = false;
			// sleep to be sure that all threads are not running
			// this mean that every single thread cant sleep more then 5 seconds
			Beep(400, 3000);
			//Sleep(1000);
			//....
			// unload
			FreeLibraryAndExitThread(hModule, 0);
			// exit this thread
			ExitThread(0);
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x8000) g_Keyb_VK_INSERT = true; else g_Keyb_VK_INSERT = false;
		if (GetAsyncKeyState(VK_HOME) & 0x8000) g_Keyb_VK_HOME = true; else g_Keyb_VK_HOME = false;
		if (GetAsyncKeyState(VK_END) & 0x8000) g_Keyb_VK_END = true; else g_Keyb_VK_END = false;
		if (GetAsyncKeyState(VK_PRIOR) & 0x8000) g_Keyb_VK_PRIOR = true; else g_Keyb_VK_PRIOR = false;
		if (GetAsyncKeyState(VK_NEXT) & 0x8000) g_Keyb_VK_NEXT = true; else g_Keyb_VK_NEXT = false;

		if (GetAsyncKeyState(VK_UP) & 0x8000) g_Keyb_VK_UP = true; else g_Keyb_VK_UP = false;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) g_Keyb_VK_DOWN = true; else g_Keyb_VK_DOWN = false;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) g_Keyb_VK_LEFT = true; else g_Keyb_VK_LEFT = false;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) g_Keyb_VK_RIGHT = true; else g_Keyb_VK_RIGHT = false;

		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) g_Mouse_VK_RBUTTON = true; else g_Mouse_VK_RBUTTON = false;
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) g_Mouse_VK_LBUTTON = true; else g_Mouse_VK_LBUTTON = false;

		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) g_Keyb_VK_SHIFT = true; else g_Keyb_VK_SHIFT = false;
		if (GetAsyncKeyState(VK_TAB) & 0x8000) g_Keyb_VK_TAB = true; else g_Keyb_VK_TAB = false;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) g_Keyb_VK_SPACE = true; else g_Keyb_VK_SPACE = false;
		if (GetAsyncKeyState(VK_F4) & 0x8000) g_Keyb_VK_F4 = true; else g_Keyb_VK_F4 = false;
		if (GetAsyncKeyState(VK_F5) & 0x8000) g_Keyb_VK_F5 = true; else g_Keyb_VK_F5 = false;
		if (GetAsyncKeyState(VK_F6) & 0x8000) g_Keyb_VK_F6 = true; else g_Keyb_VK_F6 = false;
		if (GetAsyncKeyState(VK_F7) & 0x8000) g_Keyb_VK_F7 = true; else g_Keyb_VK_F7 = false;
		if (GetAsyncKeyState(VK_F8) & 0x8000) g_Keyb_VK_F8 = true; else g_Keyb_VK_F8 = false;
		//letters
		if (GetAsyncKeyState((0x54)) & 0x8000) g_Keyb_VK_T = true; else g_Keyb_VK_T = false;
		if (GetAsyncKeyState(0x58) & 0x8000) g_Keyb_VK_X = true; else g_Keyb_VK_X = false;
		if (GetAsyncKeyState(0x4F) & 0x8000) g_Keyb_VK_O = true; else g_Keyb_VK_O = false;
		if (GetAsyncKeyState(0x4C) & 0x8000) g_Keyb_VK_L = true; else g_Keyb_VK_L = false;
		if (GetAsyncKeyState(0x4D) & 0x8000) g_Keyb_VK_M = true; else g_Keyb_VK_M = false;



		Sleep(100); // check it every 0.10 second
	}
}


/*****************************************************************************************************/









/*********************************************************************************************************/


/*MSG msg;*/
DWORD WINAPI ThreadProc(LPVOID lpParam)
{

	//pump the message loop
/*	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		FILE_LOG(logINFO) << "PEEKMESSSAGE = " << &msg;
	}*/

	/********************************************************************************/
	/*                    APPLICATION DES HOOKS VTB									*/
	/********************************************************************************/

	while (!IsValidPtr(DxRenderer::GetInstance()->m_pScreen->m_pSwapChain));
	DXGISwapChainHook = new CVMTHookManager64((DWORD64**)DxRenderer::GetInstance()->m_pScreen->m_pSwapChain);
	oPresent = (Present_t)DXGISwapChainHook->dwGetMethodAddress(8);
	DXGISwapChainHook->dwHookMethod((DWORD64)hkPresent, 8);
	FILE_LOG(logINFO) << "Hooking Present at 0x" << std::hex << DxRenderer::GetInstance()->m_pScreen->m_pSwapChain;

	while (!IsValidPtr(DxRenderer::GetInstance()->m_pDevice));
	CVMTHOOK(DxRenderer::GetInstance()->m_pDevice, CreateTexture2D, 5);
	FILE_LOG(logINFO) << "Hooking CreateTexture2D at 0x" << std::hex << DxRenderer::GetInstance()->m_pDevice;

	/*while (!IsValidPtr(DxRenderer::GetInstance()->m_pDevice));
	CVMTHOOK(DxRenderer::GetInstance()->m_pDevice, CreateDDSTextureFromMemory, 7);
	FILE_LOG(logINFO) << "Hooking CreateDDSTextureFromMemory at 0x" << std::hex << DxRenderer::GetInstance()->m_pDevice;
	*/
	while (!IsValidPtr(BorderInputNode::GetInstance()));
	CVMTHOOK(BorderInputNode::GetInstance()->m_pInputNode, PreFrame, 3);
	FILE_LOG(logINFO) << "Hooking PreFrame at 0x" << std::hex << BorderInputNode::GetInstance()->m_pInputNode;

	// soit l'un soit l'autre sinon ca plante
	while (!IsValidPtr(DxRenderer::GetInstance()->m_pContext));
	D3D11DeviceContextHook = new CVMTHookManager64((DWORD64**)DxRenderer::GetInstance()->m_pContext);
	oCopyResource = (CopyResource_t)D3D11DeviceContextHook->dwGetMethodAddress(47);
	oCopySubresourceRegion = (CopySubresourceRegion_t)D3D11DeviceContextHook->dwGetMethodAddress(46);
	D3D11DeviceContextHook->dwHookMethod((DWORD64)hkCopyResource, 47);
	D3D11DeviceContextHook->dwHookMethod((DWORD64)hkCopySubresourceRegion, 46);
	FILE_LOG(logINFO) << "Hooking CopyResource or CopySubresourceRegion at 0x" << std::hex << DxRenderer::GetInstance()->m_pContext;

/*	//hook class veniceClientMissileEntity
	ZeroMemory(&phkVeniceClientMissileEntityTAB, sizeof(phkVeniceClientMissileEntityTAB));
	oFuncVeniceClientMissileEntity0 = (tFuncMissile)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTMISSILEENTITY, (PBYTE)&hkFuncVeniceClientMissileEntity0, 0);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientMissileEntity0 at 0x" << std::hex << &hkFuncVeniceClientMissileEntity0; 
	oFuncVeniceClientMissileEntity8 = (tFuncMissile)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTMISSILEENTITY, (PBYTE)&hkFuncVeniceClientMissileEntity8, 8);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientMissileEntity8 at 0x" << std::hex << &hkFuncVeniceClientMissileEntity8;

	//hook class veniceClientBulletEntity
	ZeroMemory(&phkVeniceClientBulletEntityTAB, sizeof(phkVeniceClientBulletEntityTAB));
	oFuncVeniceClientBulletEntity0 = (tFuncBullet)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTBULLETENTITY, (PBYTE)&hkFuncVeniceClientBulletEntity0, 0);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientBulletEntity0 at 0x" << std::hex << &hkFuncVeniceClientBulletEntity0;
	oFuncVeniceClientBulletEntity8 = (tFuncBullet)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTBULLETENTITY, (PBYTE)&hkFuncVeniceClientBulletEntity8, 8);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientBulletEntity8 at 0x" << std::hex << &hkFuncVeniceClientBulletEntity8;

	//hook class veniceClientExplosionEntity
	ZeroMemory(&phkVeniceClientExplosionEntityTAB, sizeof(phkVeniceClientExplosionEntityTAB));
	oFuncVeniceClientExplosiveEntity0 = (tFuncExplosive)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTEXPLOSIONENTITY, (PBYTE)&hkFuncVeniceClientExplosiveEntity0, 0);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientExplosiveEntity0 at 0x" << std::hex << &hkFuncVeniceClientExplosiveEntity0;
	oFuncVeniceClientExplosiveEntity8 = (tFuncExplosive)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTEXPLOSIONENTITY, (PBYTE)&hkFuncVeniceClientExplosiveEntity8, 8);
	FILE_LOG(logINFO) << "Hooking hkFuncVeniceClientExplosiveEntity8 at 0x" << std::hex << &hkFuncVeniceClientExplosiveEntity8;


	//hook class ClientVehicleEntity
	ZeroMemory(&phkClientVehicleEntityTAB, sizeof(phkClientVehicleEntityTAB));
	oFuncClientVehicleEntity0 = (tFuncVehicle)std::HookaVTableFunction((PDWORD64)VTABLE_CLIENTVEHICLEENTITY, (PBYTE)&hkFuncClientVehicleEntity0, 0);
	FILE_LOG(logINFO) << "Hooking oFuncClientVehicleEntity0 at 0x" << std::hex << &hkFuncClientVehicleEntity0;
	oFuncClientVehicleEntity8 = (tFuncVehicle)std::HookaVTableFunction((PDWORD64)VTABLE_CLIENTVEHICLEENTITY, (PBYTE)&hkFuncClientVehicleEntity8, 8);
	FILE_LOG(logINFO) << "Hooking oFuncClientVehicleEntity8 at 0x" << std::hex << &hkFuncClientVehicleEntity8;
	*/

	while (bRunThreads == true)
	{
		Sleep(100);
	}


/*	//unhook class veniceClientMissileEntity
	(tFuncMissile)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTMISSILEENTITY, (PBYTE)oFuncVeniceClientMissileEntity0, 0);
	(tFuncMissile)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTMISSILEENTITY, (PBYTE)oFuncVeniceClientMissileEntity8, 8);

	//unhook class veniceClientBulletEntity
	(tFuncBullet)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTBULLETENTITY, (PBYTE)oFuncVeniceClientBulletEntity0, 0);
	(tFuncBullet)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTBULLETENTITY, (PBYTE)oFuncVeniceClientBulletEntity8, 8);

	//unhook class veniceClientExplosiveEntity
	(tFuncExplosive)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTEXPLOSIONENTITY, (PBYTE)oFuncVeniceClientExplosiveEntity0, 0);
	(tFuncExplosive)std::HookaVTableFunction((PDWORD64)VTABLE_VENICECLIENTEXPLOSIONENTITY, (PBYTE)oFuncVeniceClientExplosiveEntity8, 8);

	//unhook class ClientVehicleEntity
	(tFuncVehicle)std::HookaVTableFunction((PDWORD64)VTABLE_CLIENTVEHICLEENTITY, (PBYTE)oFuncClientVehicleEntity0, 0);
	(tFuncVehicle)std::HookaVTableFunction((PDWORD64)VTABLE_CLIENTVEHICLEENTITY, (PBYTE)oFuncClientVehicleEntity8, 8);
	*/
	DXGISwapChainHook->UnHook();
	CreateTexture2DHook->UnHook();
	PreFrameHook->UnHook();

	//D3D11DeviceContextHook->UnHook();
	D3D11DeviceContextHook->dwHookMethod((DWORD64)oCopyResource, 47);
	D3D11DeviceContextHook->dwHookMethod((DWORD64)oCopySubresourceRegion, 46);
/*	D3D11DeviceContextHook->dwHookMethod((DWORD64)oCreateDDSTextureFromMemory, 7);*/



	ExitThread(0);
	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		AddVectoredExceptionHandler(1, EH);
		inj_hModule = hModule;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)OnUnloadAndKeybThread, hModule, NULL, NULL);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadProc, hModule, NULL, NULL);
		Beep(2000, 500);


		//FILE *pFile;
		//errno_t err = fopen_s(&pFile, "C:\\out\\dllapplication.log", "a");
		//Output2FILE::Stream() = pFile;
		ReadyConsole();
		FILE_LOG(logINFO) << "Dll Attached " << ul_reason_for_call;

		DWORD64 dwBase, dwSize;
		ModuleAppz* mAppEXE = new ModuleAppz(NULL, &dwBase, &dwSize);
		FILE_LOG(logINFO) << "BF4 Base: 0x" << std::hex << dwBase;
		FILE_LOG(logINFO) << "BF4 Size: 0x" << std::hex << dwSize;
		ModuleAppz* mAppDLL = new ModuleAppz("bfdll.dll", &dwBase, &dwSize);
		FILE_LOG(logINFO) << "Dll Base: 0x" << std::hex << dwBase;
		FILE_LOG(logINFO) << "Dll Size: 0x" << std::hex << dwSize;

		dumpsig();
	}
	if (ul_reason_for_call == DLL_PROCESS_DETACH){

		int numfilesclosed = _fcloseall();
		Beep(500, 1000);
		FreeConsole();
	}
	return TRUE;
}
