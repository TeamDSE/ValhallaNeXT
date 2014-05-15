struct CharStat
{
	int Max;
	int Min;
	int Current;
	int Previous;
};

struct CharLocation
{
	int X;
	int Y;
	int PreviousX;
	int PreviousY;
	int onMapGridX;
	int onMapGridY;
};

struct PLAYER
{
	std::string Name;
	CharStat HP;
	CharStat MP;
	CharStat XP;
	CharLocation Loc;

};

struct UIButton
{
	std::string Name;
	int x;
	int y;
	int x2;
	int y2;
	int height;
	int width;
	std::string function;
	bool selected;
	bool mouseover;
	SDL_Surface* image;
	SDL_Surface* mouseoverimage;
};

struct map
{
	int data[256][256];
	std::string name;
	std::string filename;
	int x;
	int y;
};