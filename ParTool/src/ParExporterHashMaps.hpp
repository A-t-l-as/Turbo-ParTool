#ifndef PAR_EXPORTER_HASH_MAPS_H
#define PAR_EXPORTER_HASH_MAPS_H

#include <unordered_map>
#include <string>
#include <cstdint>

class ParExporterHashMaps
{
public:

	ParExporterHashMaps()
	{
		InitializeHashMaps();
	}	
	
	std::unordered_map<uint32_t, std::string> m_list_of_passive_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magic_anim_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magic_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_explosion_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_trap_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_missile_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_object_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_building_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_waste_size_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_group_template_num_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_position_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_race_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_stand_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_hit_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_experience_explosion_pos_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_equipment_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_race_masks = {};
	
	
	void InitializeHashMaps()
	{
		m_list_of_passive_masks[0x00000001] = "_bridgePassive_";
		m_list_of_passive_masks[0x00000002] = "_pontoonBridgePassive_";
		m_list_of_passive_masks[0x00000003] = "_singleBridgePassive_";
		m_list_of_passive_masks[0x00000004] = "_singlePontoonBridgePassive_";
		m_list_of_passive_masks[0x00000005] = "_bridgeRuinPassive_";
		m_list_of_passive_masks[0x00000006] = "_pontoonBridgeRuinPassive_";
		m_list_of_passive_masks[0x00000007] = "_artefactPassive_";
		m_list_of_passive_masks[0x00000008] = "_tunnelEntrancePassive_";
		m_list_of_passive_masks[0x00000009] = "_healthPlacePassive_";
		m_list_of_passive_masks[0x0000000A] = "_conversionPlacePassive_";
		m_list_of_passive_masks[0x0000000B] = "_teleportPassive_";
		m_list_of_passive_masks[0x0000000C] = "_birdPassive_";
		m_list_of_passive_masks[0x0000000D] = "_waterAnimalPassive_";
		m_list_of_passive_masks[0x00000000] = "_mapOtherPassive_";
		m_list_of_passive_masks[0x00000010] = "_mapNothingPassive_";
		m_list_of_passive_masks[0x00000020] = "_mapBuildingPassive_";
		m_list_of_passive_masks[0x00000030] = "_mapRockPassive_";
		m_list_of_passive_masks[0x00000040] = "_mapTreePassive_";
		m_list_of_passive_masks[0x00000050] = "_mapWallPassive_";
		m_list_of_passive_masks[0x00000060] = "_mapEditorPassive_";

		m_list_of_magic_anim_type_masks[0] = "equipmentAnimTypeNone";
		m_list_of_magic_anim_type_masks[1] = "equipmentAnimTypeFight";
		m_list_of_magic_anim_type_masks[2] = "equipmentAnimTypeFight2";
		m_list_of_magic_anim_type_masks[3] = "equipmentAnimTypeShoot";
		m_list_of_magic_anim_type_masks[4] = "equipmentAnimTypeMagic1";
		m_list_of_magic_anim_type_masks[5] = "equipmentAnimTypeMagic2";
		m_list_of_magic_anim_type_masks[6] = "equipmentAnimTypeMagic3";
		m_list_of_magic_anim_type_masks[7] = "equipmentAnimTypeMagic4";
		m_list_of_magic_anim_type_masks[0x00000000] = "magicTalkNone";
		m_list_of_magic_anim_type_masks[0x00010000] = "magicTalk1";
		m_list_of_magic_anim_type_masks[0x00020000] = "magicTalk2";
		m_list_of_magic_anim_type_masks[0x00030000] = "magicTalk3";
		m_list_of_magic_anim_type_masks[0x00040000] = "magicTalk4";


		m_list_of_magic_type_masks[0] = "NULL";
		m_list_of_magic_type_masks[1] = "magicImmortalShield";
		m_list_of_magic_type_masks[2] = "magicFreeze";
		m_list_of_magic_type_masks[3] = "magicCapturing";
		m_list_of_magic_type_masks[4] = "magicStorm";
		m_list_of_magic_type_masks[5] = "magicSeeing";
		m_list_of_magic_type_masks[6] = "magicConversion";
		m_list_of_magic_type_masks[7] = "magicFireRain";
		m_list_of_magic_type_masks[8] = "magicRemoveStormFireRain";
		m_list_of_magic_type_masks[9] = "magicTeleportation";
		m_list_of_magic_type_masks[10] = "magicGhost";
		m_list_of_magic_type_masks[11] = "magicWildAnimal";
		m_list_of_magic_type_masks[12] = "magicTrap";
		m_list_of_magic_type_masks[13] = "magicGetHP";
		m_list_of_magic_type_masks[14] = "magicSingleFreeze";
		m_list_of_magic_type_masks[15] = "magicBlindAttack";
		m_list_of_magic_type_masks[16] = "magicTimedCapturing";
		m_list_of_magic_type_masks[17] = "magicOurWildAnimal";
		m_list_of_magic_type_masks[18] = "magicOurHoldWildAnimal";
		m_list_of_magic_type_masks[19] = "magicOurMagicMirror";
		m_list_of_magic_type_masks[20] = "magicRandConversion";
		m_list_of_magic_type_masks[21] = "magicAroundDamage";
		m_list_of_magic_type_masks[22] = "magicSelfHealing";
		m_list_of_magic_type_masks[23] = "magicFireWall";


		m_list_of_trap_type_masks[0] = "NULL";
		m_list_of_trap_type_masks[1] = "typeHoldTrap";
		m_list_of_trap_type_masks[2] = "typeDamageTrap";
		m_list_of_trap_type_masks[3] = "typeHoldTrapOnce";

		m_list_of_explosion_flags_masks[0x00] = "noEarthquake";
		m_list_of_explosion_flags_masks[0x01] = "smallEarthquake";
		m_list_of_explosion_flags_masks[0x02] = "mediumEarthquake";
		m_list_of_explosion_flags_masks[0x03] = "bigEarthquake";

		m_list_of_missile_type_masks[0] = "NULL";
		m_list_of_missile_type_masks[1] = "missileSword";
		m_list_of_missile_type_masks[2] = "missileInvisible";
		m_list_of_missile_type_masks[3] = "missileCannon";
		m_list_of_missile_type_masks[4] = "missileDropBomb";
		m_list_of_missile_type_masks[5] = "missileBomb";
		m_list_of_missile_type_masks[6] = "missileElectric";
		m_list_of_missile_type_masks[7] = "missileLightning";
		m_list_of_missile_type_masks[8] = "missileMeteor";

		m_list_of_object_type_masks[0x00] = "animNone";
		m_list_of_object_type_masks[0x01] = "animWalk";
		m_list_of_object_type_masks[0x02] = "animRotor";
		m_list_of_object_type_masks[0x02] = "animRotation";
		m_list_of_object_type_masks[0x0000] = "moveLand";
		m_list_of_object_type_masks[0x0100] = "moveAmphibia";
		m_list_of_object_type_masks[0x0200] = "moveShip";
		m_list_of_object_type_masks[0x0300] = "moveFlyable";
		m_list_of_object_type_masks[0x10000] = "notMoveable";

		m_list_of_building_type_masks[0] = "buildingNormal";
		m_list_of_building_type_masks[1] = "buildingFactory";
		m_list_of_building_type_masks[2] = "buildingHarvestFactory";
		m_list_of_building_type_masks[3] = "buildingGate";
		m_list_of_building_type_masks[4] = "buildingBridgeGate";
		m_list_of_building_type_masks[5] = "buildingTower";
		m_list_of_building_type_masks[6] = "buildingWall";
		m_list_of_building_type_masks[7] = "buildingCopula";

		m_list_of_waste_size_masks[0] = "smallFlyingWaste";
		m_list_of_waste_size_masks[1] = "mediumFlyingWaste";
		m_list_of_waste_size_masks[2] = "bigFlyingWaste";

		m_list_of_group_template_num_masks[91] = "groupSword";
		m_list_of_group_template_num_masks[92] = "groupDrop";
		m_list_of_group_template_num_masks[93] = "groupMag";
		m_list_of_group_template_num_masks[94] = "groupSpecial";
		m_list_of_group_template_num_masks[95] = "groupAnimal";
		m_list_of_group_template_num_masks[96] = "groupMulti";
		m_list_of_group_template_num_masks[97] = "groupBuilding";


		m_list_of_position_type_masks[0] = "positionStartingPoint";
		m_list_of_position_type_masks[1] = "positionMarkPoint";
		m_list_of_position_type_masks[2] = "positionProductionPoint";

		m_list_of_race_flags_masks[0x01] = "eCanBePlayedInSkirmish";

		m_list_of_stand_type_masks[0x0000] = "standNone";
		m_list_of_stand_type_masks[0x0001] = "standAccurate";
		m_list_of_stand_type_masks[0x0002] = "standVertical";
		m_list_of_stand_type_masks[0x0003] = "standCoarsly";
		m_list_of_stand_type_masks[0x0004] = "standSwing";
		m_list_of_stand_type_masks[0x0005] = "standWater";
		m_list_of_stand_type_masks[0x0010] = "standMoveDownSmall";
		m_list_of_stand_type_masks[0x0020] = "standMoveDownMedium";
		m_list_of_stand_type_masks[0x0030] = "standMoveDownBig";
		m_list_of_stand_type_masks[0x0040] = "standTurn";
		m_list_of_stand_type_masks[0x0080] = "standTurnToFlat";
		m_list_of_stand_type_masks[0x0100] = "standMoveSmall";
		m_list_of_stand_type_masks[0x0200] = "standMoveMedium";
		m_list_of_stand_type_masks[0x0300] = "standMoveBig";
		m_list_of_stand_type_masks[0x0345] = "standWaterPlant";
		m_list_of_stand_type_masks[0x0340] = "standTree";
		m_list_of_stand_type_masks[0x0380] = "standTreeFall";
		m_list_of_stand_type_masks[0x0150] = "standRock";
		m_list_of_stand_type_masks[0x0140] = "standStone";
		m_list_of_stand_type_masks[0x0045] = "standFish";


		m_list_of_hit_type_masks[0] = "singleHit";
		m_list_of_hit_type_masks[1] = "multiHit";

		m_list_of_experience_explosion_pos_masks[0] = "expPosZero";

		m_list_of_equipment_flags_masks[0x01] = "shieldArmourType";
		m_list_of_equipment_flags_masks[0x02] = "maxArmourType";

		m_list_of_race_masks[0] = "NEUTRAL";
		m_list_of_race_masks[1] = "POL";

	}
};

#endif // !PAR_EXPORTER_HASH_MAPS_H
