#include "stdafx.h"

bool playernoragdoll = false;
bool playerinvisibility = false;
bool fastRun = false;
bool superRun = false;
bool noclip = false;
bool vehjump = false;
bool superJump = false;
bool FIREBREATH = false;
bool force_fie = false;
bool TinyPlayer = false;
bool unlim = false;
bool xpx_ammo = false;
bool molo_gun = false;
bool money_gun = false;
bool airstrikeWep = false;
bool delete_gun = false;
bool rapid_gun = false;
bool teleport_gun = false;
bool hornBoostme = false;
bool Auto__Fix = false;
bool DriftMod = false;
bool showMyFPS = false;
bool mob_rad = false;


int TimePD5;

void NoRagdoll(bool toggle)
{
	PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), !toggle);
	PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), !toggle);
}

void Invisibility()
{
	if (playerinvisibility)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
	}
}
void SuperRun()
{

	if (superRun)
	{
		Ped ped = PLAYER::PLAYER_PED_ID();

		if (AI::IS_PED_RUNNING(ped) || AI::IS_PED_SPRINTING(ped))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.f, 1.5f, 0.f, 0.f, 0.f, 0.f, 1, true, true, true, false, true);
		}
	}
	
}
void FastRun()
{

	if (fastRun)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.5);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1.0);
	}
}
void NoClip()
{

	if (noclip)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {

			///////////////////////////////////////////////////////
			float fivef = 2.0f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			///////////////////////////////////////////////////////

			
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);
			pos.x += xVec, pos.y += yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {

			///////////////////////////////////////////////////////
			float fivef = 2.0f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);
			///////////////////////////////////////////////////////

			pos.x -= xVec, pos.y -= yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {

			///////////////////////////////////////////////////////
			float fivef = 6.0f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			///////////////////////////////////////////////////////

			ENTITY::SET_ENTITY_HEADING(playerPed, heading + 5.50f);
		}
		if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {

			///////////////////////////////////////////////////////
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			///////////////////////////////////////////////////////

			ENTITY::SET_ENTITY_HEADING(playerPed, heading);
			pos.z -= 4.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {

			///////////////////////////////////////////////////////
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			///////////////////////////////////////////////////////

			ENTITY::SET_ENTITY_HEADING(playerPed, heading);
			pos.z += 4.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {

			///////////////////////////////////////////////////////
			float fivef = 6.0f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			///////////////////////////////////////////////////////

			ENTITY::SET_ENTITY_HEADING(playerPed, heading - 5.50f);
		}
	}
}

void VehJump()
{

	if (vehjump) {
		if (GetAsyncKeyState(VK_SPACE) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0 + ENTITY::GET_ENTITY_FORWARD_X(veh), 0 + ENTITY::GET_ENTITY_FORWARD_Y(veh), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
		}
	}
}

void SuperJump()
{
	if (superJump)
	{
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_PED_ID());
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	else
	{
		NULL;
	}
}

void firebreath()
{
	if (FIREBREATH)
	{


		float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;

		STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
		if ((timeGetTime() - TimePD5) > 200)
		{
			int ptfx = GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
				XOff, YOff, ZOff, SKEL_Head, 1, 1, 1, 1);
			TimePD5 = timeGetTime();
		}
	}
	else
	{
		NULL;
	}

}

void ForceFi()
{
	if (force_fie)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()), true);
		FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0x08, 640.00, 0, 1, 0);
	}
	else
	{
		NULL;
	}
}

void IDKwhatISthis()
{
	if (TinyPlayer)
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_SHRINK, 1);
	}
	else
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_SHRINK, 0);
	}
}

bool animNeeded = false;
char* animSetToDo;
int pedToDoAnimOn;
char* animNameToDo;
void doAnimation1(Ped ped, char* animSet, char* animName)
{
	animNeeded = true;
	pedToDoAnimOn = ped;
	animSetToDo = animSet;
	animNameToDo = animName;
	STREAMING::REQUEST_ANIM_DICT(animSetToDo);
}

void unLim()
{
	if (unlim)
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}

void ExplosiveAmmoNormal() // Normal Explosion
{
	Vector3 explosivecoords;
	if (xpx_ammo)
	{
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &explosivecoords))
		{
			FIRE::E_P_X(explosivecoords.x, explosivecoords.y, explosivecoords.z, 5, 5, true, false, 0);
		}
	}
	else
	{
		NULL;
	}
}

void MolotovGun() // Molotov Gun
{
	Vector3 explosivecoords;
	if (molo_gun)
	{
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &explosivecoords))
		{
			FIRE::E_P_X(explosivecoords.x, explosivecoords.y, explosivecoords.z, 3, 3, true, false, 0);
		}
	}
	else
	{
		NULL;
	}
}
#define PICKUP_MONEY_CASE 0x1E9A99F8
#define PROP_MONEY_BAG_03 0x9CA6F755




void AirstrikeGun()
{
	Vector3 ShootCoord;
	Player MyPlayer = PLAYER::PLAYER_PED_ID();
	if (airstrikeWep)
	{
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(MyPlayer, &ShootCoord))
		{
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ShootCoord.x, ShootCoord.y, ShootCoord.z + 5, ShootCoord.x, ShootCoord.y, ShootCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), MyPlayer, 1, 1, 100);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ShootCoord.x, ShootCoord.y + 5, ShootCoord.z + 5, ShootCoord.x, ShootCoord.y, ShootCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), MyPlayer, 1, 1, 130);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ShootCoord.x + 3, ShootCoord.y, ShootCoord.z + 5, ShootCoord.x, ShootCoord.y, ShootCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), MyPlayer, 1, 1, 80);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ShootCoord.x - 5, ShootCoord.y, ShootCoord.z + 5, ShootCoord.x, ShootCoord.y, ShootCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), MyPlayer, 1, 1, 110);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ShootCoord.x, ShootCoord.y - 2, ShootCoord.z + 5, ShootCoord.x, ShootCoord.y, ShootCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), MyPlayer, 1, 1, 150);
		}
	}
	else
	{
		NULL;
	}
}

void DeleteGun()
{
	if (delete_gun)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 deltetecoords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &deltetecoords))
			{
				GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(deltetecoords.x, deltetecoords.y, deltetecoords.z, 2, 0, 0, 0, 0);
			}
		}
	}
	else
	{
		NULL;
	}
}
double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}

Vector3 get_coords_infront_player(float dist)
{
	//Credits to Sub1To and Mike Rohsoft
	Vector3 r = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	float	heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
	r.x += dist * sin(DegreeToRadian(heading)) * -1,
		r.y += dist * cos(DegreeToRadian(heading));
	return r;
}
Vector3 addVectors(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}
void RapidFire()
{
	if (rapid_gun)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
			//PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
			Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
			Vector3 startCoords = addVectors(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
			Vector3 endCoords = addVectors(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
			Hash weaponhash;
			WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
			}
		}
	}
	else
	{
		NULL;
	}
}


char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "")
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

void TeleportGun()
{
	if (teleport_gun)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 teleportcoords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &teleportcoords))
			{
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), teleportcoords.x, teleportcoords.y, teleportcoords.z + 1, 0, 0, 0, 0);
			}
		}
		else
		{
			NULL;
		}
	}
}

void MaxVeh()
{
	Vehicle vehicle123 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle123, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle123, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle123, i) - 1, false);
	}
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle123, "marsbar");
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle123, 135, 0, 0);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle123, 0, 0, 0);
	Vehicle vehicle1234 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_FIXED(vehicle1234);
	VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle1234);
	VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle1234, 0);
}

void HornBoostMe()
{
	if (hornBoostme)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
			NETWORK::N_R_C_O_E(Veh);
			if (NETWORK::N_H_C_O_E(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 40);
				GRAPHICS::_START_SCREEN_EFFECT("RaceTurbo", 0, 0);
			}
		}
	}
	else
	{
		NULL;
	}
}

void AutoVehRep()
{
	if (Auto__Fix)
	{
		uint AutoVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()));

		VEHICLE::SET_VEHICLE_FIXED(AutoVeh);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(AutoVeh);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(AutoVeh, 0);
	}
	else
	{
		NULL;
	}
}

void VehDriftMode()
{
	if (DriftMod)
	{
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), true);
	}
	else
	{
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), false);
	}
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void Teleport_To_Blip()
{
	Vector3 BlipCoords = get_blip_marker();
	Entity MyPlayer = PLAYER::PLAYER_PED_ID();
	int None = 0;
	float AirHeight = 1000.0;
	bool groundFound = false;
	static float groundCheckHeight[] = { 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	char* ErrorMGS = "~r~ERROR: ~s~No waypoint found!";

	// If no waypoint has been set
	if (BlipCoords.x == None && BlipCoords.y == None)
	{
		notifyMap(ErrorMGS);
		return;
	}

	// Check if you are in any vehicle , If you are define you player as a vehicle
	if (PED::IS_PED_IN_ANY_VEHICLE(MyPlayer, false))
	{
		MyPlayer = PED::GET_VEHICLE_PED_IS_USING(MyPlayer);
	}

	// Get ground height and stuff ;)
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(MyPlayer, BlipCoords.x, BlipCoords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(BlipCoords.x, BlipCoords.y, groundCheckHeight[i], &BlipCoords.z, 0))
		{
			groundFound = true;
			BlipCoords.z += 2.5;
			break;
		}
	}

	// If no ground where found, Set player in air and give parachute
	if (!groundFound)
	{
		BlipCoords.z = AirHeight;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	teleport_to_coords(MyPlayer, BlipCoords);
}

bool CheckFriendStatus(Player player, bool result)
{
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER_UPD(player, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13))
	{
		result = NETWORK::NETWORK_IS_FRIEND(&NETWORK_HANDLE[0]);
		return true;
	}
	return false;
}

namespace HASHHH
{
#define PICKUP_MONEY_CASE 0x1E9A99F8 

	Hash MoneyModel(int id)
	{
		switch (id)
		{
		case 0: return -1666779307; break;                                        //Paperbag
		case 1: return -1803909274; break;                                        //Paperbag2
		case 2: return 0x113FD533; break;                                         //Moneybag
		case 3: return 1803116220; break;                                         //Alien egg
		case 4: return -708789241; break;                                         //Guitar
		case 5: return 1522853652; break;                                         //Grave
		case 6: return -463441113; break;                                         //Dildo
		case 7: return -144591170; break;                                         //Dummy
		case 8: return -930879665; break;                                         //Toilet
		case 9: return -1688127; break;                                           //Weed
		case 10: return -492435441; break;                                        //Oil
		case 11: return GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp"); break;      //EMP
		case 12: return GAMEPLAY::GET_HASH_KEY("prop_juicestand"); break;         //Ball
		case 13: return GAMEPLAY::GET_HASH_KEY("prop_weed_01"); break;            //Weed2
		case 14: return GAMEPLAY::GET_HASH_KEY("p_v_43_safe_s"); break;           //Safe
		case 15: return GAMEPLAY::GET_HASH_KEY("p_spinning_anus_s"); break;       //UFO
		case 16: return GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"); break;      //Xmas tree
		case 17: return GAMEPLAY::GET_HASH_KEY("prop_air_bigradar"); break;       //Radar
		case 18: return GAMEPLAY::GET_HASH_KEY("prop_cs_duffel_01b"); break;      //Duffel
		case 19: return GAMEPLAY::GET_HASH_KEY("PROP_MP_RAMP_03"); break;         //Ramp
		case 20: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_1"); break;           //1
		case 21: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_2"); break;           //2
		case 22: return GAMEPLAY::GET_HASH_KEY("PROP_MP_NUM_3"); break;           //3
		case 23: return GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"); break;        //Plane
		case 24: return GAMEPLAY::GET_HASH_KEY("prop_anim_cash_pile_02"); break;  //Cash pile
		case 25: return GAMEPLAY::GET_HASH_KEY("prop_amb_donut"); break;          //Donut
		case 26: return GAMEPLAY::GET_HASH_KEY("prop_Ld_ferris_wheel"); break;    //Ferris wheel
		}
	}
}


bool AllDropOn = false;
int DropDelay = 0;
int TimePD20;
int RainAmount = 2500;
int MoneyType = 0;
void AllMoneyDrop(bool enable)
{
	if ((timeGetTime() - TimePD20) > DropDelay)
	{
		for (int i = 0; i < 32; i++)
		{
			if (MoneyType < 0)
			{
				MoneyType = 0;
			}
			if (MoneyType > 26)
			{
				MoneyType = 26;
			}
			if (DropDelay < 0)
			{
				DropDelay = 0;
			}
			if (DropDelay > 500)
			{
				DropDelay = 500;
			}
			int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
			{
				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				STREAMING::REQUEST_MODEL(HASHHH::MoneyModel(MoneyType));

				if (!STREAMING::HAS_MODEL_LOADED(HASHHH::MoneyModel(MoneyType)))
				{

				}
				else
				{
					Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, false);
					OBJECT::CREATE_AMBIENT_PICKUP(0x1E9A99F8, playerPosition.x, playerPosition.y, playerPosition.z + 3, 0, RainAmount, HASHHH::MoneyModel(MoneyType), FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(HASHHH::MoneyModel(MoneyType));
				}
				TimePD20 = timeGetTime();
			}
		}
	}
}


void FullRecovery()
{
	notifyMap("Preparing to make full account recovery");
	WAIT(1000);
	notifyMap("Loading requirements...");
	WAIT(1000);
	notifyMap("Your recovery will start in 3 seconds...");
	WAIT(3000);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);

	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);

	STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
	STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
	STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
	STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
	STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);

	RECOVERY::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
	RECOVERY::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
	RECOVERY::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
	RECOVERY::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
	RECOVERY::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
	STATS::I_S_S_T(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
	STATS::S_I_S(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
	WAIT(2000);
	notifyMap("full account recovery has been done!");
}

void setupdraw(bool outline)
{
	UI::SET_TEXT_FONT(1);
	UI::SET_TEXT_SCALE(0.4f, 0.4f);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	if (outline)
	{
		UI::SET_TEXT_OUTLINE();
	}
}

void drawstring(char* text, float X, float Y)
{
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT((char*)"STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(X, Y);
}

void DisplayFPS()
{
	if (showMyFPS)
	{
		float LastFrameTime = GAMEPLAY::GET_FRAME_TIME();
		int getFPS = (1.0f / LastFrameTime);
		char FPStext[60];
		snprintf(FPStext, sizeof(FPStext), "FPS: ~r~ %d", getFPS);
		setupdraw(true);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(0.5f, 0.5f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_CENTRE(0);
		drawstring(FPStext, 0.020f, 0.010f);
	}
}

void MobileRadio()
{
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
	if (mob_rad)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
	}
}

bool OffRbool = false;
void OffRadar(bool toggle)
{
	globalHandle(2424073).At(PLAYER::PLAYER_ID(), 421).At(200).As<int>() = 1;
	globalHandle(2437549).At(70).As<int>() = NETWORK::GET_NETWORK_TIME();


}


