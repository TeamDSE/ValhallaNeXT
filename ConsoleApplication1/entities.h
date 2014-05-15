struct item
{
	string name;
	int atk;
	int def;
	int mag;
	int slot; // 0 - unequippable; 1 - head; 2 - chest; 3 - legs; 4 - feet
};

struct spell
{
	string name;
	int atk;
	int def;
	int mag;
	int duration;
	int element;
};

struct player
{
	string name;
	int HP;
	int MP;
	int MaxHP;
	int MaxMP;
	int atk;
	int def;
	item inventory[5];
	item equip[5];
	spell spellbook[2];
	int x;
	int y;
};

struct enemy
{
	string name;
	int HP;
	int MP;
	int MaxHP;
	int MaxMP;
	int atk;
	int def;
	item drop;
	int ChanceToDrop;
};
