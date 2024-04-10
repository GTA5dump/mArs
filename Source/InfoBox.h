#include "stdafx.h"

void LoadPlayerInfo(char* playerName, Player p) {

	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);

	RequestControlOfEnt(ped);

	int money = globalHandle(1590446).At(p, 871).At(211).At(3).As<int>();
	int rp = globalHandle(1589747).At(p, 790).At(211).At(5).As<int>();
	int earnings = globalHandle(1590446).At(p, 871).At(211).At(56).As<int>();
	int rank = globalHandle(1590446).At(p, 871).At(211).At(6).As<int>();
	int kills = globalHandle(1589747).At(p, 790).At(211).At(28).As<int>();
	int handle = globalHandle(1589747).At(p, 790).At(211).At(56).As<int>();
	int handle2 = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int bankMoney = earnings - money;
	int deaths = globalHandle(1589747).At(p, 790).At(211).At(29).As<int>();
	int tempMoney = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int death = globalHandle(1589747).At(p, 790).At(211).At(20).As<int>();
	int deathlost = globalHandle(1589747).At(p, 790).At(211).At(21).As<int>();
	int races = globalHandle(1589747).At(p, 790).At(211).At(15).As<int>();
	int raceslost = globalHandle(1589747).At(p, 790).At(211).At(16).As<int>();
	float kd = globalHandle(1589747).At(p, 790).At(211).At(26).As<float>();  // so i use for stealth money the transactions globals from benny garage , after used stealth benny garage not work anymorehm can i look?
	ostringstream Money, RP, Rank, Kills, Deaths, KD, Earnings, Money1, Moneybank, Golf, EXP, Races, Raceslost, Miss, Death, Deathlost;

	Vector3 __coords = ENTITY::GET_ENTITY_COORDS(ped, 0);
	char buf[0x80]; snprintf(buf, sizeof(buf), "X: ~g~%f", __coords.x);
	char buf1[0x80]; snprintf(buf1, sizeof(buf1), "~s~Y: ~g~%f", __coords.y);
	char buf2[0x80]; snprintf(buf2, sizeof(buf2), "~s~Z: ~g~%f", __coords.z);

	string money2 = to_string(tempMoney);
	int insertPosition = money2.length() - 3;
	while (insertPosition > 0) {
		money2.insert(insertPosition, ",");
		insertPosition -= 3;
	}

	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {
		Money << "~w~Wallet Money:~s~ N/A";
		Money1 << "~w~Cash:~s~ $";
		Moneybank << "~w~Bank Money:~s~ $";
		RP << "~w~RP:~s~ N/A";
		Rank << "~w~Rank:~s~ N/A";
		Kills << "~w~Kills:~s~ N/A";
		Deaths << "~w~Deaths:~s~ N/A";
		KD << "~w~KD Ratio:~s~ N/A";
		Earnings << "~w~Total Earnings:~s~ N/A";
		Races << "~w~Total Races Won:~s~~b~ N/A";
		Raceslost << "~w~Total Races Lost:~s~~b~ N/A";
		Death << "~w~Total Deathmatch Won:~s~~b~ N/A";
		Deathlost << "~w~Total Deathmatch Lost:~s~~b~ N/A";
		//  //__ipbuf << "~w~ IP::~s~ N/A";
		// 
	}
	else {
		Money << "~w~Wallet Money:~s~ $" << money;
		Money1 << "~w~Cash:~s~ $" << money2;
		Moneybank << "~w~Bank Money:~s~ $" << bankMoney;
		RP << "~w~RP:~s~ " << rp;
		Rank << "~w~Rank:~s~ " << rank;
		Kills << "~w~Kills:~s~ " << kills;
		Deaths << "~w~Deaths:~s~ " << deaths;
		KD << "~w~KD Ratio:~s~ " << kd;
		Earnings << "~t~Total Earnings:~s~ $" << earnings;
		Races << "~w~Total Races Won:~s~~b~ " << races;
		Raceslost << "~w~Total Races Lost:~s~~b~" << raceslost;
		Death << "~w~Total Deathmatch Won:~s~~b~" << death;
		Deathlost << "~w~Total Deathmatch Lost:~s~~b~" << deathlost;

	}



	float health = ENTITY::GET_ENTITY_HEALTH(ped);
	float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
	float healthPercent = health * 100 / maxHealth;
	ostringstream Health; Health << "Health:~s~ " << healthPercent;
	float armor = PED::GET_PED_ARMOUR(ped);
	float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(p);
	float armorPercent = armor * 100 / maxArmor;
	ostringstream Armor; Armor << "Armor:~s~ " << armorPercent;
	bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
	char* aliveStatus;
	if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
	ostringstream Alive; Alive << "Alive:~s~ " << aliveStatus;
	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";
	ostringstream Speed; Speed << "Speed:~s~ ";
	ostringstream IsInAVehicle; IsInAVehicle << "Vehicle:~s~ ";
	if (inVehicle)
	{
		Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedConverted;
		vehSpeedConverted = round(vehSpeed * 1.6);
		Speed << vehSpeedConverted << " KM/H";
		IsInAVehicle << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
	}
	else
	{
		IsInAVehicle << "~r~None";
		float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
		Speed << speed << " M/S";
		VehicleModel << "--------";
	}


	ostringstream WantedLevel; WantedLevel << "Wanted Level:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);
	ostringstream Weapon; Weapon << "Weapon: ~s~";
	Hash weaponHash;
	if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1)) {
		char* weaponName;
		if (weaponHash == 2725352035) {
			weaponName = "Unarmed";
		}
		else if (weaponHash == 2578778090) {
			weaponName = "Knife";
		}
		else if (weaponHash == 0x678B81B1) {
			weaponName = "Nightstick";
		}
		else if (weaponHash == 0x4E875F73) {
			weaponName = "Hammer";
		}
		else if (weaponHash == 0x958A4A8F) {
			weaponName = "Bat";
		}
		else if (weaponHash == 0x440E4788) {
			weaponName = "GolfClub";
		}
		else if (weaponHash == 0x84BD7BFD) {
			weaponName = "Crowbar";
		}
		else if (weaponHash == 0x1B06D571) {
			weaponName = "Pistol";
		}
		else if (weaponHash == 0x5EF9FEC4) {
			weaponName = "Combat Pistol";
		}
		else if (weaponHash == 0x22D8FE39) {
			weaponName = "AP Pistol";
		}
		else if (weaponHash == 0x99AEEB3B) {
			weaponName = "Pistol 50";
		}
		else if (weaponHash == 0x13532244) {
			weaponName = "Micro SMG";
		}
		else if (weaponHash == 0x2BE6766B) {
			weaponName = "SMG";
		}
		else if (weaponHash == 0xEFE7E2DF) {
			weaponName = "Assault SMG";
		}
		else if (weaponHash == 0xBFEFFF6D) {
			weaponName = "Assault Riffle";
		}
		else if (weaponHash == 0x83BF0278) {
			weaponName = "Carbine Riffle";
		}
		else if (weaponHash == 0xAF113F99) {
			weaponName = "Advanced Riffle";
		}
		else if (weaponHash == 0x9D07F764) {
			weaponName = "MG";
		}
		else if (weaponHash == 0x7FD62962) {
			weaponName = "Combat MG";
		}
		else if (weaponHash == 0x1D073A89) {
			weaponName = "Pump Shotgun";
		}
		else if (weaponHash == 0x7846A318) {
			weaponName = "Sawed-Off Shotgun";
		}
		else if (weaponHash == 0xE284C527) {
			weaponName = "Assault Shotgun";
		}
		else if (weaponHash == 0x9D61E50F) {
			weaponName = "Bullpup Shotgun";
		}
		else if (weaponHash == 0x3656C8C1) {
			weaponName = "Stun Gun";
		}
		else if (weaponHash == 0x05FC3C11) {
			weaponName = "Sniper Rifle";
		}
		else if (weaponHash == 0x0C472FE2) {
			weaponName = "Heavy Sniper";
		}
		else if (weaponHash == 0xA284510B) {
			weaponName = "Grenade Launcher";
		}
		else if (weaponHash == 0x4DD2DC56) {
			weaponName = "Smoke Grenade Launcher";
		}
		else if (weaponHash == 0xB1CA77B1) {
			weaponName = "RPG";
		}
		else if (weaponHash == 0x42BF8A85) {
			weaponName = "Minigun";
		}
		else if (weaponHash == 0x93E220BD) {
			weaponName = "Grenade";
		}
		else if (weaponHash == 0x2C3731D9) {
			weaponName = "Sticky Bomb";
		}
		else if (weaponHash == 0xFDBC8A50) {
			weaponName = "Smoke Grenade";
		}
		else if (weaponHash == 0xA0973D5E) {
			weaponName = "BZGas";
		}
		else if (weaponHash == 0x24B17070) {
			weaponName = "Molotov";
		}
		else if (weaponHash == 0x060EC506) {
			weaponName = "Fire Extinguisher";
		}
		else if (weaponHash == 0x34A67B97) {
			weaponName = "Petrol Can";
		}
		else if (weaponHash == 0xFDBADCED) {
			weaponName = "Digital scanner";
		}
		else if (weaponHash == 0x88C78EB7) {
			weaponName = "Briefcase";
		}
		else if (weaponHash == 0x23C9F95C) {
			weaponName = "Ball";
		}
		else if (weaponHash == 0x497FACC3) {
			weaponName = "Flare";
		}
		else if (weaponHash == 0xF9E6AA4B) {
			weaponName = "Bottle";
		}
		else if (weaponHash == 0x61012683) {
			weaponName = "Gusenberg";
		}
		else if (weaponHash == 0xC0A3098D) {
			weaponName = "Special Carabine";
		}
		else if (weaponHash == 0xD205520E) {
			weaponName = "Heavy Pistol";
		}
		else if (weaponHash == 0xBFD21232) {
			weaponName = "SNS Pistol";
		}
		else if (weaponHash == 0x7F229F94) {
			weaponName = "Bullpup Rifle";
		}
		else if (weaponHash == 0x92A27487) {
			weaponName = "Dagger";
		}
		else if (weaponHash == 0x083839C4) {
			weaponName = "Vintage Pistol";
		}
		else if (weaponHash == 0x7F7497E5) {
			weaponName = "Firework";
		}
		else if (weaponHash == 0xA89CB99E) {
			weaponName = "Musket";
		}
		else if (weaponHash == 0x3AABBBAA) {
			weaponName = "Heavy Shotgun";
		}
		else if (weaponHash == 0xC734385A) {
			weaponName = "Marksman Rifle";
		}
		else if (weaponHash == 0x63AB0442) {
			weaponName = "Homing Launcher";
		}
		else if (weaponHash == 0xAB564B93) {
			weaponName = "Proximity Mine";
		}
		else if (weaponHash == 0x787F0BB) {
			weaponName = "Snowball";
		}
		else if (weaponHash == 0x47757124) {
			weaponName = "Flare Gun";
		}
		else if (weaponHash == 0xE232C28C) {
			weaponName = "Garbage Bag";
		}
		else if (weaponHash == 0xD04C944D) {
			weaponName = "Handcuffs";
		}
		else if (weaponHash == 0x0A3D4D34) {
			weaponName = "Combat PDW";
		}
		else if (weaponHash == 0xDC4DB296) {
			weaponName = "Marksman Pistol";
		}
		else if (weaponHash == 0xD8DF3C3C) {
			weaponName = "Brass Knuckles";
		}
		else if (weaponHash == 0x6D544C99) {
			weaponName = "Railgun";
		}
		else {
			weaponName = "Unarmed";
		}
		Weapon << weaponName;


	}
	else Weapon << "Unarmed";
	/*Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);*/
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	ostringstream Zone; Zone << "Zone: ~s~" << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));

	char ipBuf[32] = {};
	static auto nigNog = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
	auto nigger = nigNog(p);

	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {

		for (int i = 0; i < 3; i++)
		{
			if (nigger)
			{
				auto faggot = *(uintptr_t*)(nigger + 0x10b8);
				if (faggot)
				{


					auto ip = (BYTE*)(faggot + 0x44);
					std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: ~s~Hide", i);

				}
			}

		}

	}
	else {

		if (nigger)
		{
			auto faggot = *(uintptr_t*)(nigger + 0x10b8);
			if (faggot)
			{
				auto ip = (BYTE*)(faggot + 0x44);
				std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: %u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);

			}
		}

	}

	Menu::AddSmallTitle2(playerName);
	Menu::AddSmallInfo2((char*)Health.str().c_str(), 0);
	Menu::AddSmallInfo2((char*)Armor.str().c_str(), 1);
	Menu::AddSmallInfo2((char*)Alive.str().c_str(), 2);
	Menu::AddSmallInfo2((char*)IsInAVehicle.str().c_str(), 3);
	Menu::AddSmallInfo2((char*)Speed.str().c_str(), 4);
	Menu::AddSmallInfo2((char*)WantedLevel.str().c_str(), 5);
	Menu::AddSmallInfo2((char*)Weapon.str().c_str(), 6);
	Menu::AddSmallInfo2((char*)Zone.str().c_str(), 7);
	Menu::AddSmallInfo2((char*)Money.str().c_str(), 8);
	Menu::AddSmallInfo2((char*)Moneybank.str().c_str(), 9);
	Menu::AddSmallInfo2((char*)Rank.str().c_str(), 10);
	Menu::AddSmallInfo2(ipBuf, 11);
	//Menu::AddSmallInfo2((char*)Kills.str().c_str(), 13);
	//Menu::AddSmallInfo2((char*)Deaths.str().c_str(), 14);
	//Menu::AddSmallInfo2((char*)KD.str().c_str(), 15);
	//Menu::AddSmallInfo2(ipBuf, 16);
	//Menu::AddSmallInfo2(buf, 17);
	//Menu::AddSmallInfo2(buf1, 18);
	//Menu::AddSmallInfo2(buf2, 19);
	//Menu::AddSmallInfo2((char*)Earnings.str().c_str(), 20);
	//Menu::AddSmallInfo2((char*)Money1.str().c_str(), 21);
	//Menu::AddSmallInfo2((char*)Death.str().c_str(), 22);
	//Menu::AddSmallInfo2((char*)Deathlost.str().c_str(), 23);
	//Menu::AddSmallInfo2((char*)Races.str().c_str(), 24);
	//Menu::AddSmallInfo2((char*)Raceslost.str().c_str(), 25);
}
