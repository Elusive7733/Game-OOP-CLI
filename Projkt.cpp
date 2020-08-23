#include <iostream>
#include <fstream>
using namespace std;


string items[] = {"Sange", "Yasha", "Orb of Venom", "Mask Of Madness", "Monkey King Bar", "Frostmourne", "Shadowmourne", "Heart Of True Strike", "Sabimaru"};  //friend

//class entities{
//	protected:
//		double health, mana, stamina,damage;
//		long gold;
//		
//	public:
//		virtual void attack()=0;
//		virtual void defend(){};
//		
//		
//};

class player{
		private:
			double health, mana, stamina,damage;
			long gold;
		public:
		
			void attack(enemy &e ,double dmg) {
				damage = dmg;
				e.health -= damage;
			}
			void defend(){
				
			}
};

class 

class enemy{
		void attack(){
			
		}
};

class bossEnemy: public entities{
		void attack(){
			
		}
		void defend(){
		
		}
};

class shop{
		
};






