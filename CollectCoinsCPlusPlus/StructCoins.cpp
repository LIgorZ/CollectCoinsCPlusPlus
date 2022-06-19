struct Header_CollectionCoins
{
public:
	char id_Coin[20];
	char Name_Coin[50];
	char id_Country[20];
	char id_Condition [20];
	char Year_Coin [20];
	char Circulation_Coin[20];
	char Material_Coin[40];
	char Weight_Coin[20];
	char Est_Price_Coin [20];
};

struct CollectCoins
{
public:
	int id_Coin;
	char Name_Coin[50];
	int id_Country;
	int id_Condition;
	int Year_Coin;
	double Circulation_Coin;
	char Material_Coin[40];
	float Weight_Coin;
	float Est_Price_Coin;
};

struct Header_Country
{
public:
	char id_Country[20];
	char Name_Country[50];
	char Code_Country[20];
};

struct Country
{
public:
	int id_Country;
	char Name_Country[50];
	char Code_Country[5];
};

struct Header_Condition
{
	char id_Condition [20];
	char Name_Condition[50];
	char Desc_Condition[50];
};

struct Condition
{
	int id_Condition;
	char Name_Condition[50];
	char Desc_Condition[50];
};