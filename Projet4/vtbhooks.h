#include <map>
#include <vector>
#include <string>
namespace hookChoices{

	template <class T> class VectorOfRefs : public std::vector<T *> {
	public:
		inline T & at(const uint64_t i) {
			T * x = std::vector<T *>::at(i);
			return *x;
		}
	};

	class vtbhooks{
			enum StringValue {
				Missile = 0,
				Explosive = 1,
				Pickup = 2,
				Grenade = 3,
				Bullet = 4
			};
	

		PVOID addObjHook;
		std::string hookContext[255];
	//	int* hookContext[255][255];
		int count;
		VectorOfRefs < std::string > myVector;
	public :

		vtbhooks(PVOID pThis, std::string myClass){

			myVector.push_back(&myClass);

			// later in the code:
			//myVector.at(i).myMethod(); //myVector.at(i).GetData()->getType()->m_infoData->m_name;
			

			vtbhooks::addObjHook = pThis;
			vtbhooks::hookContext[count] = myClass;
			//vtbhooks::StringValue myClassNumber = vtbhooks::hookContext[count];

			//FILE_LOG(logINFO) << "ARGS = " << myClass;
		//	FILE_LOG(logINFO) << "EXEC MAP = " << myClassNumber;

			/*if (vtbhooks::addObjHook != 0){
				switch (myClassNumber)
				{
				case vtbhooks::Missile:
					FILE_LOG(logINFO) << "MISSILE SWITCH";
					break;
				case vtbhooks::Explosive:
					FILE_LOG(logINFO) << "EXPLOSIVE SWITCH";
					break;
				case vtbhooks::Pickup:
					FILE_LOG(logINFO) << "PICKUP SWITCH";
					break;
				case vtbhooks::Grenade:
					FILE_LOG(logINFO) << "GRENADE SWITCH";
				default:
					FILE_LOG(logINFO) << "DEFAULT SWITCH";
					break;
				}
			}*/
			count++;
		}


		void phkStartHookTAB(){

		}

		void phkEndHookTAB(){

		}
	};
};
class hookChoices::vtbhooks;