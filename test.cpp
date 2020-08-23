//#include"pch.h"
#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

class User
{
public:
	int gold;
	int lvl;
	string name;
	User()
	{
		gold = 0;
		lvl = 0;
		string n;
		cout << "Choose Name:\n-->";
		cin >> n;
		while (n.length() < 3 || n.length() > 20)
		{
			cout << "Choose Name:\n-->";
			cin >> n;
		}
		name = n;
		cout << "Your name is: " << name << endl;
	}
	void addgold(int amt)
	{
		gold += amt;
	}
	void uplvl()
	{
		lvl++;
	}
	void setname(string n)
	{
		name = n;
	}
};

class Character
{
public:
	int hp;
	int mana;
	int dmg;
	Character()
	{
		hp = 0;
		mana = 0;
		dmg = 0;
	}
	Character(int h, int m, int d)
	{
		hp = h;
		mana = m;
		dmg = d;
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg;
	}
};


//player classes
class Warrior : public Character
{
public:
	Warrior() : Character(1000, 500, 300)
	{
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg * 2;
	}
	int gethp()
	{
		return hp;
	}
};

class Healer : Character
{
public:
	Healer() : Character()
	{
		hp = 0;
		mana = 0;
		dmg = 0;
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg * 2;
	}
};

class Tank : Character
{
public:
	Tank() : Character()
	{
		hp = 0;
		mana = 0;
		dmg = 0;
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg * 2;
	}
};

class Mystic : Character
{
public:
	Mystic() : Character()
	{
		hp = 0;
		mana = 0;
		dmg = 0;
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg * 2;
	}
};


//Enemy npc
class 
Enemy : public Character
{
public:
	string name;
	Enemy() : Character(1000, 500, 300)
	{
	}
	void attack(class Character enemy)
	{
		enemy.hp -= dmg * 2;
	}
	int gethp()
	{
		return hp;
	}
};




void main_menu()
{
	int o;
	cout << "1-Load Savegame\n2-Start New Game\nAny other key to quit" << endl;
	cin >> o;
	if (o == 1)
	{

	}
	if (o == 2)
	{

	}
	else
	{
		exit(0);
	}
}
int main()
{
	main_menu();
	system("cls");
	int opt = 0, opt2 = 0;
	User p;
	cout << "\nSelect Class:\n1-Warrior""\n2-Healer""\n3-Tank""\n4-Mystic""\n-->";
	cin >> opt;
	cout << "Are you sure? 1-Yes 2-No\n-->";
	cin >> opt2;
	system("cls");
	Warrior a;
	/*switch (opt)
	{
	case 1:
		Warrior a;
		break;
		case 2:
			Healer a;
			break;
		case 3:
			Tank a;
			break;
		case 4:
			Mystic a;
			break;
		default:
			cout<<"Incorrect!";
	}*/
	cout<<"\nDarkness. Then Light. The sound of horns blowing. War is calling.";
	cout<<"\n\nSteward: Wake up sire. The king demands your presence.""\nYou: Does he?""\nSteward: The falmers are invading the kingdom""\nYou: HA! Blood must be shed!" "\nYou get on your way"<<endl;
	system("pause");
	system("cls");
	//Begin Fight 1:
	cout << p.name << " VS " << "Enemy" << endl;//enemy.name;
	int hp = a.hp;
	int mana = a.mana;
	cout << hp << "/" << a.hp << endl << mana << "/" << a.mana << endl;
	return 0;
}
void fightsim(class Character a, class Enemy b)
{
	while(a.hp>0 && b.hp>0)
	{
		//playermove;
		if(b.hp<0)
		{
			break;
		}
		//enemymove;
		if(a.hp<0)
		{
			break;
		}
	}
}
menu()
{
	cout<<name;
	cout<<gold;
	cout<<lvl;

}
battlemenu()
{
	cout<<hp<<a.hp<<mana<<a.mana;
	enemy cout<<hp<<maxhp<<mana<<maxmana;
}
func lvlupmenu()
{
	cout<<"Select attribute to levelup";
	cout<<"HP, mana, dmg";

}
func charcreator()
{

}

func enemygen()
{
	string enemynames[10] = { "Helminth", "Huras", "Kronen", "Saitama", "Dante", "PlainsWalker", "Zamasu", "Troll Warlord", "Ligma Sugma", "Ricardo" };
	string name;
public:
	enemy()
	{
		name=enemynames[rand()%10];
	}
	hp=Character lvl*30;
	dmg=Character lvl*20;
}


