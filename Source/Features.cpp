#include "stdafx.h"

bool Features::lgevts = false;
bool Features::lgevtssss = false;
bool Features::lelellelellelelelellelellelellele = false;
bool Features::lellelellelelellelelellelelelellellelellelele = false;


void Features::autovehi(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{

		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::C_O_P(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON1(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, false);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("shop_controller");
		//WAIT(150);
		//if (MyBools::spawnincurentveh)
		//{
		//	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		//}
		//if (MyBools::spawncurentvehmaxed)
		//{
		//	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		//	for (int i = 0; i < 50; i++)
		//	{

		//		VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
		//		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "flexy");
		//		AUDIO::SET_VEH_RADIO_STATION(veh, "OFF");
		//		//GRAPHICS::SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
		//		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", veh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);

		//	}
		//}
		if (ENTITY::DOES_ENTITY_EXIST(veh)) {
			//spawned_vehs.push_back(veh);
			//spawned_vehs_chars.push_back(toSpawn);

		}
	}
}

int Features::current_frame;
int Features::current_framee;
char* Features::current_header;
int Features::bandelay;
int TimePD1 = 150;
int Playfreqvalue = 150;
int FramesAmount = 55;
int FirstFrame = 0;
void Features::UpdateLoop()
{
	if ((timeGetTime() - TimePD1) > Playfreqvalue) {
		if (current_frame >= FramesAmount)
		{
			current_frame = FirstFrame;

		}
		else 
		{
			current_frame++;
		}

		current_header = _strdup(("frame" + std::to_string(current_frame)).c_str());

		TimePD1 = timeGetTime();
	}
}

