#ifndef PAR_COMPILATOR_HASH_MAPS_H
#define PAR_COMPILATOR_HASH_MAPS_H

#include "Compilator/HashMapsBase.hpp"

class ParCompilatorHashMaps : public HashMapsBase
{
public:
    ParCompilatorHashMaps() : HashMapsBase()
    {}

    void InitializeHashMapsOfConsts() override
    {
        m_list_of_32_bit_consts["NULL"] = 0;
        m_list_of_32_bit_consts["magicImmortalShield"] = 1;
        m_list_of_32_bit_consts["magicFreeze"] = 2;
        m_list_of_32_bit_consts["magicCapturing"] = 3;
        m_list_of_32_bit_consts["magicStorm"] = 4;
        m_list_of_32_bit_consts["magicSeeing"] = 5;
        m_list_of_32_bit_consts["magicConversion"] = 6;
        m_list_of_32_bit_consts["magicFireRain"] = 7;
        m_list_of_32_bit_consts["magicRemoveStormFireRain"] = 8;
        m_list_of_32_bit_consts["magicTeleportation"] = 9;
        m_list_of_32_bit_consts["magicGhost"] = 10;
        m_list_of_32_bit_consts["magicWildAnimal"] = 11;
        m_list_of_32_bit_consts["magicTrap"] = 12;
        m_list_of_32_bit_consts["magicGetHP"] = 13;
        m_list_of_32_bit_consts["magicSingleFreeze"] = 14;
        m_list_of_32_bit_consts["magicBlindAttack"] = 15;
        m_list_of_32_bit_consts["magicTimedCapturing"] = 16;
        m_list_of_32_bit_consts["magicOurWildAnimal"] = 17;
        m_list_of_32_bit_consts["magicOurHoldWildAnimal"] = 18;
        m_list_of_32_bit_consts["magicOurMagicMirror"] = 19;
        m_list_of_32_bit_consts["magicRandConversion"] = 20;
        m_list_of_32_bit_consts["magicAroundDamage"] = 21;
        m_list_of_32_bit_consts["magicSelfHealing"] = 22;
        m_list_of_32_bit_consts["magicFireWall"] = 23;
        m_list_of_32_bit_consts["noEarthquake"] = 0x00;
        m_list_of_32_bit_consts["smallEarthquake"] = 0x01;
        m_list_of_32_bit_consts["mediumEarthquake"] = 0x02;
        m_list_of_32_bit_consts["bigEarthquake"] = 0x03;
        m_list_of_32_bit_consts["typeHoldTrap"] = 1;
        m_list_of_32_bit_consts["typeDamageTrap"] = 2;
        m_list_of_32_bit_consts["typeHoldTrapOnce"] = 3;
        m_list_of_32_bit_consts["missileSword"] = 1;
        m_list_of_32_bit_consts["missileInvisible"] = 2;
        m_list_of_32_bit_consts["missileCannon"] = 3;
        m_list_of_32_bit_consts["missileDropBomb"] = 4;
        m_list_of_32_bit_consts["missileBomb"] = 5;
        m_list_of_32_bit_consts["missileElectric"] = 6;
        m_list_of_32_bit_consts["missileLightning"] = 7;
        m_list_of_32_bit_consts["missileMeteor"] = 8;

        m_list_of_32_bit_consts["buildingNormal"] = 0;
        m_list_of_32_bit_consts["buildingFactory"] = 1;
        m_list_of_32_bit_consts["buildingHarvestFactory"] = 2;
        m_list_of_32_bit_consts["buildingGate"] = 3;
        m_list_of_32_bit_consts["buildingBridgeGate"] = 4;
        m_list_of_32_bit_consts["buildingTower"] = 5;
        m_list_of_32_bit_consts["buildingWall"] = 6;
        m_list_of_32_bit_consts["buildingCopula"] = 7;

        m_list_of_32_bit_consts["smallFlyingWaste"] = 0;
        m_list_of_32_bit_consts["mediumFlyingWaste"] = 1;
        m_list_of_32_bit_consts["bigFlyingWaste"] = 2;

        m_list_of_32_bit_consts["groupSword"] = 91;
        m_list_of_32_bit_consts["groupDrop"] = 92;
        m_list_of_32_bit_consts["groupMag"] = 93;
        m_list_of_32_bit_consts["groupSpecial"] = 94;
        m_list_of_32_bit_consts["groupAnimal"] = 95;
        m_list_of_32_bit_consts["groupMulti"] = 96;
        m_list_of_32_bit_consts["groupBuilding"] = 97;

        m_list_of_32_bit_consts["positionStartingPoint"] = 0;
        m_list_of_32_bit_consts["positionMarkPoint"] = 1;
        m_list_of_32_bit_consts["positionProductionPoint"] = 2;

        m_list_of_32_bit_consts["eCanBePlayedInSkirmish"] = 0x01;

        m_list_of_32_bit_consts["standNone"] = 0x0000;
        m_list_of_32_bit_consts["standAccurate"] = 0x0001;
        m_list_of_32_bit_consts["standVertical"] = 0x0002;
        m_list_of_32_bit_consts["standCoarsly"] = 0x0003;
        m_list_of_32_bit_consts["standSwing"] = 0x0004;
        m_list_of_32_bit_consts["standWater"] = 0x0005;
        m_list_of_32_bit_consts["standMoveDownSmall"] = 0x0010;
        m_list_of_32_bit_consts["standMoveDownMedium"] = 0x0020;
        m_list_of_32_bit_consts["standMoveDownBig"] = 0x0030;
        m_list_of_32_bit_consts["standTurn"] = 0x0040;
        m_list_of_32_bit_consts["standTurnToFlat"] = 0x0080;
        m_list_of_32_bit_consts["standMoveSmall"] = 0x0100;
        m_list_of_32_bit_consts["standMoveMedium"] = 0x0200;
        m_list_of_32_bit_consts["standMoveBig"] = 0x0300;
        m_list_of_32_bit_consts["standWaterPlant"] = 0x0345;
        m_list_of_32_bit_consts["standTree"] = 0x0340;
        m_list_of_32_bit_consts["standTreeFall"] = 0x0380;
        m_list_of_32_bit_consts["standRock"] = 0x0150;
        m_list_of_32_bit_consts["standStone"] = 0x0140;
        m_list_of_32_bit_consts["standFish"] = 0x0045;

        m_list_of_32_bit_consts["singleHit"] = 0;
        m_list_of_32_bit_consts["multiHit"] = 1;

        m_list_of_32_bit_consts["expPosZero"] = 0;

        m_list_of_32_bit_consts["shieldArmourType"] = 0x01;
        m_list_of_32_bit_consts["maxArmourType"] = 0x02;

        m_list_of_32_bit_consts["NEUTRAL"] = 0;
        m_list_of_32_bit_consts["POL"] = 1;

    }


    void InitializeHashMapOfMasks() override
    {

        m_list_of_masks["_bridgePassive_"] = 0x00000001;
        m_list_of_masks["_pontoonBridgePassive_"] = 0x00000002;
        m_list_of_masks["_singleBridgePassive_"] = 0x00000003;
        m_list_of_masks["_singlePontoonBridgePassive_"] = 0x00000004;
        m_list_of_masks["_bridgeRuinPassive_"] = 0x00000005;
        m_list_of_masks["_pontoonBridgeRuinPassive_"] = 0x00000006;
        m_list_of_masks["_artefactPassive_"] = 0x00000007;
        m_list_of_masks["_tunnelEntrancePassive_"] = 0x00000008;
        m_list_of_masks["_healthPlacePassive_"] = 0x00000009;
        m_list_of_masks["_conversionPlacePassive_"] = 0x0000000A;
        m_list_of_masks["_teleportPassive_"] = 0x0000000B;
        m_list_of_masks["_birdPassive_"] = 0x0000000C;
        m_list_of_masks["_waterAnimalPassive_"] = 0x0000000D;
        m_list_of_masks["_mapOtherPassive_"] = 0x00000000;
        m_list_of_masks["_mapNothingPassive_"] = 0x00000010;
        m_list_of_masks["_mapBuildingPassive_"] = 0x00000020;
        m_list_of_masks["_mapRockPassive_"] = 0x00000030;
        m_list_of_masks["_mapTreePassive_"] = 0x00000040;
        m_list_of_masks["_mapWallPassive_"] = 0x00000050;
        m_list_of_masks["_mapEditorPassive_"] = 0x00000060;
        m_list_of_masks["equipmentAnimTypeNone"] = 0;
        m_list_of_masks["equipmentAnimTypeFight"] = 1;
        m_list_of_masks["equipmentAnimTypeFight2"] = 2;
        m_list_of_masks["equipmentAnimTypeShoot"] = 3;
        m_list_of_masks["equipmentAnimTypeMagic1"] = 4;
        m_list_of_masks["equipmentAnimTypeMagic2"] = 5;
        m_list_of_masks["equipmentAnimTypeMagic3"] = 6;
        m_list_of_masks["equipmentAnimTypeMagic4"] = 7;
        m_list_of_masks["magicTalkNone"] = 0x00000000;
        m_list_of_masks["magicTalk1"] = 0x00010000;
        m_list_of_masks["magicTalk2"] = 0x00020000;
        m_list_of_masks["magicTalk3"] = 0x00030000;
        m_list_of_masks["magicTalk4"] = 0x00040000;

        m_list_of_masks["animNone"] = 0x00;
        m_list_of_masks["animWalk"] = 0x01;
        m_list_of_masks["animRotor"] = 0x02;
        m_list_of_masks["animRotation"] = 0x02;
        m_list_of_masks["moveLand"] = 0x0000;
        m_list_of_masks["moveAmphibia"] = 0x0100;
        m_list_of_masks["moveShip"] = 0x0200;
        m_list_of_masks["moveFlyable"] = 0x0300;
        m_list_of_masks["notMoveable"] = 0x10000;
    }

};


#endif // !PAR_COMPILATOR_HASH_MAPS_H
