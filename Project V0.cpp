#include <iostream>
#include <fstream>
using namespace std;


string items[] = {"Sange", "Yasha", "Orb of Venom", "Mask Of Madness", "Monkey King Bar", "Frostmourne", "Shadowmourne", "Heart Of True Strike", "Sabimaru"};  //friend




class Player {
	private:
		double health, exp;
		long gold;
		int level;
		
	public:
		Player(){
			health = 0;
			level = 8;
		}
		void sethealth(double healthx){
			health = healthx;
		}
		double gethealth(){
			return health;
		}
		
		void setexp(double exp){
			(*this).exp = exp;
		}
		double getexp(){
			return exp;
		}
		
		void setlevel(int level){
			(*this).level = level;
		}
		int getlevel(){
			return level;
		}
};

class Warrior: virtual public Player{
	private:
		int rage;
	public:
		static string Ability[6];
		Warrior(){
			sethealth(300);
			rage = 100;
//			cout<<"warrior";
		}
		void setrage(double rage)
		{
			(*this).rage = rage;
		}
		double getrage()
		{
			return rage;
		}

};

string Warrior ::  Ability[6] = {"1. Heroic Strike", "2. Shield Bash", "3. Pummel", "4. Assault", "5. Overthrow", "6. Enrage"};

class Rogue: virtual public Player{
	private:
		double energy;
	public:
		static string Ability[6];
		Rogue(){
			sethealth(200);
			energy = 200;
	//		cout<<"rogue";
		}
		void setenergy(double energy)
		{
			(*this).energy = energy;
		}
		double getenergy()
		{
			return energy;
		}
	
};
string Rogue ::  Ability[6] = {"1. Stab", "2. Sunder", "3. Flank Attack", "4. Knife Throw", "5. Shadow Dance"};

class Mage: virtual public Player{
	private:
		double mana;
	public:
	static string Ability[6];
	
	Mage(){
		sethealth(100);
		mana = 300;
//		cout<<"mage";
	}
	void setmana(double mana)
	{
		(*this).mana = mana;
	}
	double getmana()
	{
		return mana;
	}
	

};
string Mage ::  Ability[6] = {"1. Winter Grasp", "2. Immolate", "3. Curse", "4. Ice Mine", "5. Fire Mine" "6. Blizzard", "7. Fire Storm"};

class Enemy {
	protected:
		double healthE, damageE;
	public:
		Enemy(){
			healthE = 0;			
			damageE = 0;
		}
		double sethealthE(double healthEx){
			healthE = healthEx;
		}
		double gethealthE(){
		return healthE;
	}
};
class Bandits: virtual public Enemy {
	public:
		int punch;
	
	Bandits(){
		sethealthE(200);
	}
};
class MiniBoss: virtual public Enemy{
	public:
};
class Boss: virtual public Enemy {
	public:
};

class shop{
	public:
		shop();
};

//                    BATTLEGROUND
class Battle: public  Warrior, public Rogue, public Mage, public Bandits, public MiniBoss, public Boss{
	public:
		Battle(){}
		int option, abilityoption;
		friend void levelup();
		
		Bandits B[50];
		
		MiniBoss MB[3];
		Boss boss;
		
		void Attackmenu(int choice){
			if (choice == 1){
		
				Warrior W;
				
				cout << "1. Ability\n";
				cout << "2. Inventory\n";
				cin>>option;
				
				if(option == 1){
					
					for(int i = 0; i < 6; i++)
					{
						if(i+1 <= W.getlevel())
						{
							cout << W.Ability[i] << endl;	
						}
					}
					
					cout<<"\nWhich ability do you wish to use?\n";
					fflush(stdin);
					cin >> abilityoption;
						if(abilityoption == 1)
						{
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
							B[0].sethealthE(B[0].gethealthE() - 20);
							W.setrage(W.getrage() - 20);
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
							
						}
						else if(abilityoption == 2)
						{
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							B[0].sethealthE(B[0].gethealthE() - 50);
							cout<<"Rage: " <<W.getrage()<<endl;
							W.setrage(W.getrage() - 30);
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
						}
						else if(abilityoption == 3)
						{
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
							B[0].sethealthE(B[0].gethealthE() - 80);
							W.setrage(W.getrage() - 40);
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
						}
						else if(abilityoption == 4)
						{
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
							B[0].sethealthE(B[0].gethealthE() - 100);
							W.setrage(W.getrage() - 50);
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
						}
						else if(abilityoption == 5)
						{
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
							B[0].sethealthE(B[0].gethealthE() - 150);
							W.setrage(W.getrage() - 60);
							cout<<"Health: "<<B[0].gethealthE()<<endl;
							cout<<"Rage: " <<W.getrage()<<endl;
						}
						else if(abilityoption == 6)
						{
							cout<<"Rage: " <<W.getrage()<<endl;
							W.setrage(W.getrage() - 100);
							cout << "You are Enraged all damage dealt is multiplied by 2" << endl;
							cout<<"Rage: " <<W.getrage()<<endl;
						}
						
			}
			else if(option == 2)
			{
				//items
			}
			else{
				cout << "ERROR - invalid option.";
			}
		}
		else if (choice == 2){
			Rogue R;
			
			
			cout << "1. Ability\n";
			cout << "2. Inventory\n";
			cin>>option;
			
			if(option == 1){
				
				for(int i = 0; i < 6; i++)
				{
					if(i+1 <= R.getlevel())
					{
						cout << R.Ability[i] << endl;	
					}
				}
				
				cout<<"\nWhich ability do you wish to use?\n";
				fflush(stdin);
				cin >> abilityoption;
					if(abilityoption == 1)
					{
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
						B[0].sethealthE(B[0].gethealthE() - 20);
						R.setenergy(R.getenergy() - 20);
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
						
					}
					else if(abilityoption == 2)
					{
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						B[0].sethealthE(B[0].gethealthE() - 50);
						cout<<"Energy: " <<R.getenergy()<<endl;
						R.setenergy(R.getenergy() - 30);
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
					}
					else if(abilityoption == 3)
					{
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
						B[0].sethealthE(B[0].gethealthE() - 80);
						R.setenergy(R.getenergy() - 40);
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
					}
					else if(abilityoption == 4)
					{
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
						B[0].sethealthE(B[0].gethealthE() - 100);
						R.setenergy(R.getenergy() - 50);
						cout<<"Health: "<<B[0].gethealthE()<<endl;
						cout<<"Energy: " <<R.getenergy()<<endl;
					}
					else if(abilityoption == 5)
					{
				
						cout<<"Energy: " <<R.getenergy()<<endl;
						R.setenergy(R.getenergy() - 200);
						cout << "You are hidden you can deal damage with taking damage for the next few moves";
						cout<<"Energy: " <<R.getenergy()<<endl;
					}
		}
	}
}
//		else if (choice == 3){
//			Mage M;
//		}
};
// ============================================================
//void levelup(int choice)
//{
//	
//}



int main(){
	Battle bp;
	
	int choice;
	cin>>choice;
	bp.Attackmenu(choice);
}




