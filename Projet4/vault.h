#include <math.h>
class ClientVaultInterface{
public :
	ClientVaultInterface(ClientSoldierEntity* p_LocalSoldier, Vec3 pDestination, bool wait){


		if (pDestination.x != 0 && pDestination.y != 0 && pDestination.z != 0){
			this->Teleportation(p_LocalSoldier, pDestination);
		}
	}
	void Teleportation(ClientSoldierEntity* p_LocalSoldier, Vec3 pDestination, float heightJump=0){
		//pSoldier->m_pClientVaultComponent->m_oldvault->teleportVector = pDestination;

		heightJump = (!isnan(heightJump)) ? 0 : heightJump;
		p_LocalSoldier->m_pClientVaultComponent->pVaultComponentData->m_StartHeightMax = heightJump;

		this->VaultPatch();

		if (heightJump == 0)
			p_LocalSoldier->m_pClientVaultComponent->m_oldvault->teleportVector = pDestination;

		p_LocalSoldier->m_pClientVaultComponent->m_VaultState = 1;

		if (true)
			Sleep(100);
			
		this->VaultUnPatch();
		

	}

	void MaxJump(ClientSoldierEntity* pSoldier){

		Sleep(50);

		pSoldier->m_pClientVaultComponent->pVaultComponentData->m_StartHeightMax = 300000.0f;
		/*FILE_LOG(logINFO) << "pSoldier at 0x" << std::hex << pSoldier;
		FILE_LOG(logINFO) << "pSoldier mdata at 0x" << std::hex << pSoldier->m_data;
		FILE_LOG(logINFO) << "VaultComponent at 0x" << std::hex << pSoldier->m_pClientVaultComponent;
		FILE_LOG(logINFO) << "VaultComponentData at 0x" << std::hex << pSoldier->m_pClientVaultComponent->pVaultComponentData;
		FILE_LOG(logINFO) << "VaultComponentData Maxheight at 0x" << std::hex << pSoldier->m_pClientVaultComponent->pVaultComponentData->m_StartHeightMax;*/

		VaultPatch();


		pSoldier->m_pClientVaultComponent->m_VaultState = 1;

		if (true)
			Sleep(100);
			VaultUnPatch();
	}

	//this is the patch vault start end
	void VaultPatch(){
		std::MemPatchSafe(0x1403697e8, (BYTE*)"\x90\x90\x90", 3);
		std::MemPatchSafe(0x140369764, (BYTE*)"\x90\x90\x90", 3);
	}

	//the unpatch vault start end
	void VaultUnPatch(){
		std::MemPatchSafe(0x1403697e8, (BYTE*)"\x89\x73\x48", 3);
		std::MemPatchSafe(0x140369764, (BYTE*)"\x89\x73\x48", 3);
	}

	Vec3 NullifyTelePortVector(){
		Vec3 nullTelePortVector;
		nullTelePortVector.x = 0;
		nullTelePortVector.y = 0;
		nullTelePortVector.z = 0;

		return nullTelePortVector;
	}

	~ClientVaultInterface();
};