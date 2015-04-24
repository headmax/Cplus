class KitExplosif{
public :
	bool state;
	Vec3 C4Position;
	KitExplosif(bool state, Vec3 C4Position, CObjectEntry* Entity){
		this->state = state;
		if (this->state == true)
			this->lancier(this->C4Position, Entity);
	}


	//l'endroit ou on lance
	//@c4Positon (le point de references helper visuel Vec3)
	//l'object entity

	void lancier(Vec3 c4Position, CObjectEntry* Entity){

		//Je verifie si les coordonnées ne sont pas null car elle le sont c le ptr est invalide
		if (c4Position.x != 0 && c4Position.y != 0 && c4Position.z != 0){

			FILE_LOG(logINFO) << "C4.x = " << c4Position.x;
			FILE_LOG(logINFO) << "C4.y = " << c4Position.y;
			FILE_LOG(logINFO) << "C4.z = " << c4Position.z;

			//ton code ...
			ClientExplosionPackEntity* pClientExplosionPackEntity = (ClientExplosionPackEntity*)Entity->m_pEntity->Ptr2;

			//mon check ultra de dogmatt pour les crash ...
			if (IsValidPtrEh(pClientExplosionPackEntity)){
				FILE_LOG(logINFO) << "PACKENTITY ADRESS = 0x" << std::hex << &pClientExplosionPackEntity;
				
				FILE_LOG(logINFO) << "WRITE POSITION = 0x" << std::hex << &c4Position;
				
				//FILE_LOG(logINFO) << "ADDRESS NEW WRITED IS = 0x" << std::hex << &pClientExplosionPackEntity->m_position;
				


				pClientExplosionPackEntity->m_position = c4Position;
		
			}
		}
	}

	~KitExplosif();
};

class KitExplosif;