
/////////////////////////////////////////////////////////////
//  Typeinfo
/////////////////////////////////////////////////////////////
class TestList;
struct MemberInfoFlags;
class ModuleInfo;
class MemberInfo;
class TypeInfo;
class FieldInfo;
class ClassInfo;
class ITypedObject;
class DataContainer;

class TestList
{
public:
	typedef void* Test;

	Test* m_head; //0x0000 
	Test* m_tail; //0x0008 

};//Size=0x0010

struct MemberInfoFlags
{
	unsigned short m_flagBits; //0x0000 

};//Size=0x0002

class ModuleInfo
{
public:
	char* m_moduleName; //0x0000 
	ModuleInfo* m_nextModule; //0x0008 
	TestList* m_testList; //0x0010 

};//Size=0x0018

class MemberInfo
{
public:
#pragma pack(push, 2)
	struct MemberInfoData
	{
		char* m_name; //0x0000
		MemberInfoFlags m_flags; //0x0008

	};//Size=0x000A
#pragma pack(pop)

	MemberInfoData* m_infoData; //0x0000

	bool MemberInfo::isClass()
	{
		MemberInfo::MemberInfoData* memberInfoData = getMemberInfoData();
		if (memberInfoData)
		{
			return (memberInfoData->m_flags.m_flagBits & 0x1F0) == 0x30;
		}
		return false;
	}
 
	MemberInfo::MemberInfoData* MemberInfo::getMemberInfoData()
	{
		return ((MemberInfoData*)m_infoData);
	}

};//Size=0x0008

class TypeInfo : public MemberInfo
{
public:
	struct TypeInfoData : public MemberInfoData
	{
		unsigned short m_totalSize; //0x000A 
		char _0x000C[4];
		ModuleInfo* m_module; //0x0010 
		unsigned char m_alignment; //0x0018 
		unsigned char m_fieldCount; //0x0019 
		char _0x001A[6];

	};//Size=0x0020

	TypeInfo* m_pNext; //0x0008
	unsigned short m_runtimeId; //0x0010
	unsigned short m_flags; //0x0012
	char _0x0014[4];

	TypeInfo::TypeInfoData* TypeInfo::getTypeInfoData()
	{
		return ((TypeInfoData*)m_infoData);
	}

	//TypeInfoData* getTypeInfoData();

};//Size=0x0018

class FieldInfo : public MemberInfo
{
public:
	struct FieldInfoData : public MemberInfo::MemberInfoData
	{
		unsigned short m_fieldOffset; //0x000A
		char _0x000C[4];
		TypeInfo* m_fieldTypePtr; //0x0010

	};//Size=0x0018

	virtual TypeInfo* getDeclaringType();
	virtual unsigned short getFieldIndex();

	TypeInfo* m_declaringType; //0x0010 
	unsigned short m_fieldIndex; //0x0018 
	unsigned short m_attributeMask; //0x001A 
	char _0x001C[4];

	FieldInfo::FieldInfoData* FieldInfo::getFieldInfoData()
	{
		return ((FieldInfoData*)m_infoData);
	}

};//Size=0x0020
 
class ClassInfo : public TypeInfo
{
public:
	struct ClassInfoData : TypeInfo::TypeInfoData
	{
		ClassInfo* m_superClass; //0x0020 
		void* m_createFun; //0x0028 
		FieldInfo::FieldInfoData* m_fields; //0x0030     

	};//Size=0x0038

	ClassInfo* m_super; //0x0018 
	DataContainer* m_defaultInstance; //0x0020 
	unsigned short m_classId; //0x0028 
	unsigned short m_lastSubClassId; //0x002A 
	char _0x002C[4];
	ClassInfo* m_firstDerivedClass; //0x0030 
	ClassInfo* m_nextSiblingClass; //0x0038 
	FieldInfo** m_fieldInfos; //0x0040 
	unsigned int m_totalFieldCount; //0x0048 
	char _0x004C[4];

	ClassInfo::ClassInfoData* ClassInfo::getClassInfoData()
	{
		return ((ClassInfoData*)m_infoData);
	}


};//Size=0x0050

class ITypedObject
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
	virtual void* GetData(); // Function9() jd62 //EntityData
	virtual void* GetComponents(); // Function10() jd62 // Components
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
	virtual void* GetPhysiscsEntity(); //physics PhysicsEntity
	virtual Vector4* GetVelocity(); //velocity Vec3
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
};//Size=0x0008

class DataContainer : public ITypedObject
{
public:
	union
	{
		struct
		{
			unsigned short m_refCnt; //0x0008
			unsigned short m_flags; //0x000A
		};
		__int32 m_refCountAndId; //0x0008 
	};
	char _0x000C[4];

};//Size=0x0010