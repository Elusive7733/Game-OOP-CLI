#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

int count = 5;
//this count is for Enrage and shadowdance for 2 turns.
//add more comments you assholes.

string items[] = {"Sange", "Yasha", "Orb of Venom", "Mask Of Madness", "Monkey King Bar", "Frostmourne", "Shadowmourne", "Heart Of True Strike", "Sabimaru"};  //friend

class Player {	
	private:
		double health,maxhealth;
		long gold;
		int level, exp;

	public:
		Player(){
			maxhealth = 300;
			health = 0;
			level = 1;
			exp = 0;
		}
		void sethealth(double healthx){
			health = healthx;
		}
		void setmaxhealth(double healthx){
			maxhealth = healthx;
		}
		void increasehealth(double healthx){
			if (health <= maxhealth){
				health = healthx;
				if (health > maxhealth){
					health = maxhealth;
				}
			}
		}
		double gethealth(){
			return health;
		}
		double getmaxhealth(){
			return maxhealth;
		}

		void setexp(double exp){
			(*this).exp = exp;
		}
		int getexp(){
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
		double rage, maxrage;
		double multiply;
	public:
		static string Ability[6];
		Warrior(){
			sethealth(300);
			rage = 100;
			maxrage = 100;
			multiply = 1;
//			cout<<"warrior";
		}
		void setrage(double rage)
		{
			if (rage != 0){
				(*this).rage = rage;
			}
			else rage = 1;

		}
		double getrage()
		{
			return rage;
		}

		void setmultiply(double multiply)
		{
			this->multiply = multiply;
		}

		int getmultiply()
		{
			return multiply;
		}
		void setmaxrage(double mrage)
		{
			maxrage = mrage;
		}
		double getmaxrage()
		{
			return maxrage;
		}	

};

string Warrior ::  Ability[6] = {"1. Heroic Strike", "2. Shield Bash", "3. Pummel", "4. Assault", "5. Overthrow", "6. Enrage"};

class Rogue: virtual public Player{
	private:
		double energy, maxenergy;
		double multiply;
	public:
		static string Ability[6];
		Rogue(){
			sethealth(300);
			energy = 100;
			maxenergy = 100;
			multiply = 1;
		}
		void setenergy(double energy)
		{
			(*this).energy = energy;
		}
		double getenergy()
		{
			return energy;
		}
		void setmultiply(double multiply)
		{
			this->multiply = multiply;
		}

		double getmultiply()
		{
			return multiply;
		}
		void setmaxenergy(double menergy)
		{
			energy = menergy;
		}
		double getmaxenergy()
		{
			return maxenergy;
		}

};
string Rogue ::  Ability[6] = {"1. Stab", "2. Sunder", "3. Flank Attack", "4. Knife Throw", "5. Eviscerate", "6. Shadow Dance"};

class Mage: virtual public Player{
	private:
		double mana, maxmana;
	public:
	static string Ability[8];

	Mage(){
		sethealth(300);
		mana = 100;
		maxmana = 100;
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
	void setmaxmana(double mmana)
	{
		mana = mmana;
	}
	double getmaxmana()
	{
		return maxmana;
	}
	


};
string Mage ::  Ability[8] = {"1.Arcane Bolt", "2. Drain Life", "3. Winter Grasp ", "4. Lightning", "5. Flame Blast" , "6. Heal" , "7. Blizzard", "8. Fire Storm"};

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
		void virtual useless(){
		}
};
class Bandits: virtual public Enemy {
	public:
		static const int punch = 5;

	Bandits(){
		sethealthE(100);
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
class BattleGround: public  Warrior, public Rogue, public Mage, public Bandits, public MiniBoss, public Boss{
	public:
		BattleGround(){}
		int option,abilityoption;

		void gotoXY(int x, int y) {
			CursorPosition.X = x;
			CursorPosition.Y = y;
			SetConsoleCursorPosition(console,CursorPosition);
		}

//		friend void levelup(); yaar ye friend wali cheez nehi chal rhai ajeeb

	int levelup(int x, Player *ptr)
	{
			int levelchoice;
			system("cls");
			ptr->setlevel(getlevel() + 1);
		
			if(x == 1)
			{
				cout << "Your Warrior has reached level: " << ptr->getlevel() << endl;
				cout << "1-Upgrade Health" << endl;
				cout << "2-Upgrade Rage" << endl;			
			}
			else if(x == 2)
			{
				cout << "Your Rouge has reached level: " << ptr->getlevel() << endl;
				cout << "1-Upgrade Health" << endl;
				cout << "2-Upgrade Energy" << endl;		
			}
			else if(x == 3)
			{
				cout << "Your Mage has reached level: " << ptr->getlevel() << endl;
				cout << "1-Upgrade Health" << endl;
				cout << "2-Upgrade Mana" << endl;		
			}
			cin >> levelchoice;
			return levelchoice;
	}

		MiniBoss MB[3];
		Boss boss;

		void AttackMenu(Warrior &W, Enemy *E, int bandit_number,string enemytype){

			if (enemytype == "Bandit"){
				Bandits *B = dynamic_cast<Bandits*> (E);
			}
			else if ( enemytype == "Miniboss"){
				MiniBoss *MB = dynamic_cast<MiniBoss*> (E);
			}
			else if ( enemytype == "Boss"){
				Boss *FB = dynamic_cast<Boss*> (E);
			}

			cout <<	"Player Health " << W.gethealth() <<"/ "<<W.getmaxhealth()<<"\t\t"<<enemytype<<" "<<bandit_number<<" Health "<< E->gethealthE()<<"/ 100"<<endl;
			cout <<	"Player Rage   " << W.getrage() <<"/ "<<W.getmaxrage()<<endl<<endl;

			cout << "1)Ability      2)Inventory\n";
			cin>>option;

			if (option == 1){
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
					if(count < 2)
					{
						W.setmultiply(2);
						count++;
					}
					else
					{
						W.setmultiply(1);
					}
						if(abilityoption == 1 && W.getlevel() >= 1)
						{
							E->sethealthE(  E->gethealthE() - ( 20 * W.getmultiply() ) );
							W.setrage(W.getrage() - 5);
							cout<<"Damage dealt = "<< 20 * W.getmultiply() <<endl;
							cout<<"Rage Reduced = -5\n";
							return ;
						}
						else if(abilityoption == 2 && W.getlevel() >= 2)
						{
							E->sethealthE(  E->gethealthE() - ( 35 * W.getmultiply() ) );
							W.setrage(W.getrage() - 10);
							cout<<"Damage dealt = "<< 35 * W.getmultiply() <<endl;
							cout<<"Rage Reduced = -10\n";

							return ;
						}
						else if(abilityoption == 3 && W.getlevel() >= 4)
						{
							E->sethealthE(  E->gethealthE() - ( 60 * W.getmultiply() ) );
							W.setrage(W.getrage() - 15);
							cout<<"Damage dealt = "<< 60 * W.getmultiply() <<endl;
							cout<<"Rage Reduced = -15\n";

							return ;
						}
						else if(abilityoption == 4 && W.getlevel() >= 6)
						{
							E->sethealthE(  E->gethealthE() - ( 100 * W.getmultiply() ) );
							W.setrage(W.getrage() - 40);
							cout<<"Damage dealt = "<< 100 * W.getmultiply() <<endl;
							cout<<"Rage Reduced = -40\n";

							return ;
						}
						else if(abilityoption == 5 && W.getlevel() >= 8)
						{
							E->sethealthE(  E->gethealthE() - ( 150 * W.getmultiply() ) );
							W.setrage(W.getrage() - 50);
							cout<<"Damage dealt = "<< 150 * W.getmultiply() <<endl;
							cout<<"Rage Reduced = -50\n";

							return ;
						}
						else if(abilityoption == 6 && W.getlevel() >= 10)
						{
						W.setrage(W.getrage() - 40);
						cout << "You are Enraged all damage dealt is multiplied by 2" << endl;
						count = 0;
						W.setmultiply(2);
						cout<<"Rage Reduced = -40\n";
						return;
						}
			}
			else if (option == 2 ){
			}
			else{
				cout << "ERROR - invalid option.";
			}

		}
		void AttackMenu(Rogue &R, Enemy *E, int bandit_number, string enemytype){

			if (enemytype == "Bandit"){
				Bandits *B = dynamic_cast<Bandits*> (E);
			}
			else if (enemytype == "Miniboss"){
				MiniBoss *MB = dynamic_cast<MiniBoss*> (E);
			}
			else if (enemytype == "Boss"){
				Boss *FB = dynamic_cast<Boss*> (E);
			}

			cout <<	"Player Health " << R.gethealth() <<"/ "<<R.getmaxhealth()<<"\t\t"<<enemytype<<" "<<bandit_number<<" Health "<< E->gethealthE()<<"/ 100"<<endl;
			cout <<	"Player Energy " << R.getenergy() <<"/ "<<R.getmaxenergy()<<endl<<endl;

			cout << "1)Ability      2)Inventory\n";
			cin>>option;

			if (option == 1){
				for(int i = 0; i < 6; i++)
				{
					if(i+1 <= R.getlevel())
					{
						cout << R.Ability[i] << endl;
					}
				}
				if(count < 2)
				{
					R.setmultiply(0.5);
					count++;
				}
				else
				{
					R.setmultiply(1);
				}
				cout<<"\nWhich ability do you wish to use?\n";
				fflush(stdin);
				cin >> abilityoption;
					if(abilityoption == 1 && R.getlevel() >= 1)
					{

						E->sethealthE( E->gethealthE() - 25 );
						R.setenergy(R.getenergy() - 5 * R.getmultiply());
						cout<<"Damage dealt = "<< 25 <<endl;
						cout<<"Energy Reduced = -5\n";
						return;

					}
					else if(abilityoption == 2 && R.getlevel() >= 2)
					{
						E->sethealthE(E->gethealthE() - 70 );
						R.setenergy(R.getenergy() - 12 * R.getmultiply());
						cout<<"Damage dealt = "<< 70 <<endl;
						cout<<"Energy Reduced = -12\n";
						return;
					}
					else if(abilityoption == 3 && R.getlevel() >= 4)
					{
						E->sethealthE( E->gethealthE() - 70 );
						R.setenergy(R.getenergy() - 18 * R.getmultiply());
						cout<<"Damage dealt = "<< 70 <<endl;
						cout<<"Energy Reduced = -18\n";
						return;
					}
					else if(abilityoption == 4 && R.getlevel() >= 6)
					{
						E->sethealthE( E->gethealthE() - 110 );
						R.setenergy(R.getenergy() - 44 * R.getmultiply());
						cout<<"Damage dealt = "<< 110 <<endl;
						cout<<"Energy Reduced = -44\n";
						return;
					}
					else if(abilityoption == 5 && R.getlevel() >= 8)
					{
						E->sethealthE( E->gethealthE() - 160 );
						R.setenergy(R.getenergy() - 55 * R.getmultiply());
						cout<<"Damage dealt = "<< 160 <<endl;
						cout<<"Energy Reduced = -55\n";
						return;
					}
					else if(abilityoption == 6 && R.getlevel() >= 10)
					{
						R.setenergy(R.getenergy() - 40 * R.getmultiply());
						cout << "You are in Sage Mode, Energy will be reduce by 1/2 for the next few moves"<<endl;
						count = 0;
						R.setmultiply(0.5);
						return;
					}
			}
			else if (option == 2){
			}
			else{
				cout << "ERROR - invalid option.";
			}

		}
		void AttackMenu(Mage &M, Enemy *E, int bandit_number,string enemytype){

			if (enemytype == "Bandit"){
				Bandits *B = dynamic_cast<Bandits*> (E);
			}
			else if ( enemytype == "Miniboss"){
				MiniBoss *MB = dynamic_cast<MiniBoss*> (E);
			}
			else if ( enemytype == "Boss"){
				Boss *FB = dynamic_cast<Boss*> (E);
			}

			cout <<	"Player Health " << M.gethealth() <<"/ "<<M.getmaxhealth()<<"\t\t"<<enemytype<<" "<<bandit_number<<" Health "<< E->gethealthE()<<"/ 100"<<endl;
			cout <<	"Player Mana " << M.getmana() <<"/ "<<M.getmaxmana()<<endl<<endl;

			cout << "1)Ability      2)Inventory\n";
			cin>>option;

			if (option == 1){

				for(int i = 0; i < 8; i++)
				{
					if(i+1 <= M.getlevel())
					{
						cout << M.Ability[i] << endl;
					}
				}

				cout<<"\nWhich ability do you wish to use?\n";
				fflush(stdin);
				cin >> abilityoption;
					if(abilityoption == 1 && M.getlevel() >= 1)
					{
						E->sethealthE( E->gethealthE() - 25 );
						M.setmana(M.getmana() - 5);
						cout<<"Damage dealt = "<< 25 <<endl;
						cout<<"Mana Reduced = -5\n";
						return;

					}
					else if(abilityoption == 2 && M.getlevel() >= 2)
					{
						E->sethealthE( E->gethealthE() - 40 );
						M.setmana(M.getmana() - 10);
						cout<<"Damage dealt = "<< 40 <<endl;
						cout<<"Mana Reduced = -10\n";
						return;
					}
					else if(abilityoption == 3 && M.getlevel() >= 3)
					{
						E->sethealthE( E->gethealthE() - 75 );
						M.setmana(M.getmana() - 25);
						cout<<"Damage dealt = "<< 75 <<endl;
						cout<<"Mana Reduced = -25\n";
						return;
					}
					else if(abilityoption == 4 && M.getlevel() >= 4)
					{
						E->sethealthE( E->gethealthE() - 80 );
						M.setmana(M.getmana() - 27);
						cout<<"Damage dealt = "<< 80 <<endl;
						cout<<"Mana Reduced = -27\n";
						return;
					}
					else if(abilityoption == 5 && M.getlevel() >= 6)
					{

						E->sethealthE( E->gethealthE() - 85 );
						M.setmana(M.getmana() - 28);
						cout<<"Damage dealt = "<< 85 <<endl;
						cout<<"Mana Reduced = -28\n";
						return;
					}

					else if(abilityoption == 6 && M.getlevel() >= 7)
					{
						cout<<"Health increased by 50"<<endl;
						M.increasehealth(50);
						return;
					}

					else if(abilityoption == 7 && M.getlevel() >= 8)
					{
						E->sethealthE( E->gethealthE() - 175 );
						M.setmana(M.getmana() - 50);
						cout<<"Damage dealt = "<< 175 <<endl;
						cout<<"Mana Reduced = -50\n";
						return;
					}
					else if(abilityoption == 8 && M.getlevel() >= 10)
					{
						E->sethealthE( E->gethealthE() - 200 );
						M.setmana(M.getmana() - 60);
						cout<<"Damage dealt = "<< 200 <<endl;
						cout<<"Mana Reduced = -60\n";
						return;
					}

			}
			else if (option == 2){
			}
			else{
				cout << "ERROR - invalid option.";
			}
		}


		void EnemyAttack(Player *ptr , Bandits B){
			
			ptr->sethealth(ptr->gethealth() - B.punch);
			cout<<"Damage Recieved = "<<B.punch<<endl;
			getch();
			return;
		}
//		void MiniBossAttack(Player *ptr , MiniBoss B){
//			ptr->sethealth(ptr->gethealth() - B.punch);
//			cout<<"Damage Recieved = "<<B.punch<<endl;
//			getch();
//			return;
//		}
//		void BossAttack(Player *ptr , Boss B){
//			ptr->sethealth(ptr->gethealth() - B.punch);
//			cout<<"Damage Recieved = "<<B.punch<<endl;
//			getch();
//			return;
//		}

		void WarriorPLay(int choice){
			Warrior W;
			int levelchoice;
			while(W.gethealth() != 0){
				for ( int bandit_number = 1 ; bandit_number <= 50 ; bandit_number++){
					Bandits B;
					while (B.gethealthE() != 0){
						system("cls");
						AttackMenu(W,&B,bandit_number, "Bandit");
						EnemyAttack(&W,B);
					}
					W.setrage(W.getrage() + 20);
					W.setexp(W.getexp()+100);
					if(W.getexp()%500 == 0)
					{
						levelchoice = levelup(choice, &W);
						if(levelchoice == 1)
						{
							W.setmaxhealth(W.getmaxhealth() + 50);
							W.sethealth(W.getmaxhealth()); //delete this if you dont want character to heal at levelup
							W.setrage(W.getmaxrage()); //delete this if you dont want character to heal at levelup
						}
						else
						{
							W.setmaxrage(W.getmaxrage() + 50);
							W.sethealth(W.getmaxhealth()); //delete this if you dont want character to heal at levelup
							W.setrage(W.getmaxrage()); //delete this if you dont want character to heal at levelup
						}
					}
					
				}
			}

		}
		void RoguePlay(int choice){
			Rogue R;
			int levelchoice;
			while(R.gethealth() != 0){
				for ( int bandit_number = 1 ; bandit_number <= 50 ; bandit_number++){
					Bandits B;
					while (B.gethealthE() != 0){
						system("cls");
						AttackMenu(R,&B,bandit_number, "Bandit");
						EnemyAttack(&R,B);
					}
					R.setenergy(R.getenergy() + 20);
					R.setexp(R.getexp()+100);
					if(R.getexp()%500 == 0)
					{
						levelchoice = levelup(choice, &R);
						if(levelchoice == 1)
						{
							R.setmaxhealth(R.getmaxhealth() + 50);
							R.sethealth(R.getmaxhealth()); //delete this if you dont want character to heal at levelup
							R.setenergy(R.getmaxenergy()); //delete this if you dont want character to heal at levelup
						}
						else
						{
							R.setmaxenergy(R.getmaxenergy() + 50);
							R.sethealth(R.getmaxhealth()); //delete this if you dont want character to heal at levelup
							R.setenergy(R.getmaxenergy());  //delete this if you dont want character to heal at levelup
						}
					}
				}
			}

		}
		void MagePlay(int choice){
			Mage M;
			int levelchoice;
			while(M.gethealth() != 0){
				for ( int bandit_number = 1 ; bandit_number <= 50 ; bandit_number++){
					Bandits B;
					while (B.gethealthE() != 0){
						system("cls");
						AttackMenu(M,&B,bandit_number, "Bandit");
						EnemyAttack(&M,B);
					}
					M.setmana(M.getmana() + 20);
					M.setexp(M.getexp()+100);
					if(M.getexp()%500 == 0)
					{
						levelchoice = levelup(choice, &M);
						if(levelchoice == 1)
						{
							M.setmaxhealth(M.getmaxhealth() + 50);
							M.sethealth(M.getmaxhealth()); //delete this if you dont want character to heal at levelup
							M.setmana(M.getmaxmana()); //delete this if you dont want character to heal at levelup
						}
						else
						{
							M.setmaxmana(M.getmaxmana() + 50);
							M.sethealth(M.getmaxhealth()); //delete this if you dont want character to heal at levelup
							M.setmana(M.getmaxmana()); //delete this if you dont want character to heal at levelup
						} 
						
					}
				}
			}
		}


		void INTERFACE(){
			int menu_item=1, run, x=7;
			bool running = true;

			gotoXY(18,5); cout << "Character Selection";
			gotoXY(14,7); cout << "-|==>";

			while(running)
			{
		        gotoXY(20,7);  cout << "1) Warrior";
				gotoXY(20,8);  cout << "2) Rogue";
				gotoXY(20,9);  cout << "3) Mage";


				system("pause>nul");

				if(GetAsyncKeyState(VK_DOWN) && x != 9)
					{
						gotoXY(14,x); cout << "     ";
						x++;
						gotoXY(14,x); cout << "-|==>";
						menu_item++;
						continue;

					}

				if(GetAsyncKeyState(VK_UP) && x != 7)
					{
						gotoXY(14,x); cout << "     ";
						x--;
						gotoXY(14,x); cout << "-|==>";
						menu_item--;
						continue;
					}

				if(GetAsyncKeyState(VK_RETURN)){

					switch(menu_item){

						case 1: {
							system("cls");
							WarriorPLay(1);
							running = false;
							break;
						}


						case 2: {
							system("cls");
							RoguePlay(2);
							running = false;
							break;
						}


						case 3: {
							system("cls");
							MagePlay(3);
							running = false;
							break;
						}

					}

				}

			}

			gotoXY(20,21);


		}

		void MENU(){

			int menu_item=1, run, x=7;
			bool running = true;

			gotoXY(18,5); cout << "Main Menu";
			gotoXY(14,7); cout << "-|==>";

			while(running)
			{
		        gotoXY(20,7);  cout << "1) Start New Game";
				gotoXY(20,8);  cout << "2) Load Game";
				gotoXY(20,9);  cout << "3) Quit Game";


				system("pause>nul");

				if(GetAsyncKeyState(VK_DOWN) && x != 9)
					{
						gotoXY(14,x); cout << "     ";
						x++;
						gotoXY(14,x); cout << "-|==>";
						menu_item++;
						continue;

					}

				if(GetAsyncKeyState(VK_UP) && x != 7)
					{
						gotoXY(14,x); cout << "     ";
						x--;
						gotoXY(14,x); cout << "-|==>";
						menu_item--;
						continue;
					}

				if(GetAsyncKeyState(VK_RETURN)){

					switch(menu_item){

						case 1: {

							gotoXY(20,16);
							system("cls");
							INTERFACE();
							running = false;
							break;
						}


						case 2: {
							gotoXY(20,16);
							cout << "You chose Output...     ";
							break;
						}


						case 3: {
							gotoXY(20,16);
							cout << "The program has now terminated!!";
							running = false;
						}

					}

				}

			}

			gotoXY(20,21);

		}

};

int main(){
	BattleGround play;
	play.MENU();
}
