#include "stdafx.h"
bool freezeprotect = false;
bool antiexplo = false;
bool timewe = false;
bool noTP = false;
bool generalPro = false;



void AntiFreeze(bool t)
{
	Hooking::defuseEvent(RAGDOLL_REQUEST_EVENT, t);
	Hooking::defuseEvent(INCIDENT_ENTITY_EVENT, t);
	Hooking::defuseEvent(CLEAR_AREA_EVENT, t);
	Hooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, t);
	Hooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, t);
	Hooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_STOP_SOUND_EVENT, t);
	Hooking::defuseEvent(NETWORK_PLAY_AIRDEFENSE_FIRE_EVENT, t);
}

void AntiExplosion(bool t)
{
	Hooking::defuseEvent(FIRE_EVENT, t);
	Hooking::defuseEvent(EXPLOSION_EVENT, t);
	Hooking::defuseEvent(REQUEST_PHONE_EXPLOSION_EVENT, t);
	Hooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, t);
}

void antiWeatherTime(bool t)
{
	Hooking::defuseEvent(GAME_CLOCK_EVENT, t);
	Hooking::defuseEvent(GAME_WEATHER_EVENT, t);
}

void antiTP(bool t)
{
	Hooking::defuseEvent(NETWORK_REQUEST_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_UPDATE_SYNCED_SCENE_EVENT, t);
	Hooking::defuseEvent(NETWORK_START_SYNCED_SCENE_EVENT, t);
	globalHandle(1377446).At(486).As<int>() = 486; //TP
	globalHandle(1382674).At(499).As<int>() = 499; //TP
}

void GeneralProtect(bool t)
{
	globalHandle(1382674).At(610).As<int>() = 610; //SP kick
	globalHandle(1382674).At(609).As<int>() = 609; //kick
	globalHandle(1382674).At(536).As<int>() = 536; //ceo kick
	globalHandle(1382674).At(558).As<int>() = 558; //ceo ban
	globalHandle(1377446).At(486).As<int>() = 486; //TP
	globalHandle(1382674).At(499).As<int>() = 499; //TP
	globalHandle(1382674).At(532).As<int>() = 532; //ceo kick 2
	globalHandle(1382674).At(295).As<int>() = 295; //mission
	globalHandle(1382674).At(350).As<int>() = 350; //transaction
	globalHandle(1382674).At(0).As<int>() = 0; //notification
	globalHandle(1382674).At(61).As<int>() = 61; //gentle kick
	globalHandle(1382674).At(584).As<int>() = 584; //kick 2
	globalHandle(1382674).At(2).As<int>() = 2; //rotate cam
	globalHandle(1382674).At(490).As<int>() = 490; //clearwanted
	globalHandle(1382674).At(545).As<int>() = 545; //bribe cops
	globalHandle(1382674).At(433).As<int>() = 433; //insurance
	globalHandle(1382674).At(492).As<int>() = 492; //offradar
	globalHandle(1382674).At(609).As<int>() = 609; //Non-Host kick
	globalHandle(1382674).At(608).As<int>() = 608; //SP kick
	globalHandle(1382674).At(16).As<int>() = 16; //Superkick XXI
	globalHandle(1382674).At(21).As<int>() = 21; //Superkick XX
	globalHandle(1382674).At(677).As<int>() = 677; //Superkick XIX
	globalHandle(1382674).At(601).As<int>() = 601; //Superkick XVIII
	globalHandle(1382674).At(23).As<int>() = 23; //Superkick XVII
	globalHandle(1382674).At(24).As<int>() = 24; //Superkick XVI
	globalHandle(1382674).At(582).As<int>() = 582; //Superkick XV
	globalHandle(1382674).At(599).As<int>() = 599; //Superkick XIV
	globalHandle(1382674).At(577).As<int>() = 577; //Superkick XIII
	globalHandle(1382674).At(576).As<int>() = 576; //Superkick XII
	globalHandle(1382674).At(532).As<int>() = 532; //Superkick XI
	globalHandle(1382674).At(688).As<int>() = 688; //Superkick X
	globalHandle(1382674).At(455).As<int>() = 455; //Superkick IX
	globalHandle(1382674).At(449).As<int>() = 449; //Superkick VIII
	globalHandle(1382674).At(336).As<int>() = 336; //Superkick VII
	globalHandle(1382674).At(294).As<int>() = 294; //Superkick VI
	globalHandle(1382674).At(694).As<int>() = 694; //Superkick V
	globalHandle(1382674).At(602).As<int>() = 602; //Superkick IV
	globalHandle(1382674).At(584).As<int>() = 584; //Superkick III
	globalHandle(1382674).At(610).As<int>() = 610; //Superkick II
	globalHandle(1382674).At(693).As<int>() = 693; //Superkick I
}







void ProtectLoop()
{
	freezeprotect ? AntiFreeze(true) : NULL;
	antiexplo ? AntiExplosion(true) : NULL;
	timewe ? antiWeatherTime(true) : NULL;
	noTP ? antiTP(true) : NULL;
	generalPro ? GeneralProtect(true) : NULL;
}

