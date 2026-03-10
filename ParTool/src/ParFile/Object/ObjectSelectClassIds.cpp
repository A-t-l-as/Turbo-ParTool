#include "Object.hpp"
#include "../../ClassIds/SortedClassIds.hpp"
#include "../../ClassIds/OtherClassIds.hpp"
#include <array>

using namespace std;

std::vector<std::string> v_s_moveable_flags_labels = {
"animalUnit",
"recyclableUnit",
"towerUnit",
"gateUnit",
"sleepModeUnit",
"camouflageModeUnit",
"enemyAlertUnit",
"ghostFriendUnit",
"noEquipmentArtefactsUnit",
"haveArmourExplosion",
"noAccurateStandInSleep",
"noMagicFreezeUnit",
"noMagicGetHPUnit",
"noMagicBlindAttackUnit",
"loopedMoveAnimUnit",
"noPoissonUnit",
"turnAnimUnit",
"noTurnToFreeGridInSleep",
"noGetArtefactUnit" };

std::vector<std::string> v_s_plug_types_labels = {
"tmpPlug",
"swordPlug",
"helmetPlug",
"shieldPlug",
"armourPlug",
"necklacePlug",
"ringPlug",
"beltPlug",
"unknown",
"axePlug",
"bowPlug",
"spearPlug",
"crossbowPlug",
"specialPlug",
"magicPlug",
"eggPlug",
"udderPlug",
"bannerPlug",
"princeSwordPlug",
"princeHelmetPlug",
"princeShieldPlug",
"princeArmourPlug",
"quiverPlug",
"weaponPriestess_Or_SorcererPlug" };

std::vector<std::string> v_s_slot_types_labels = {
"tmpSlot",
"swordSlot",
"helmetSlot",
"shieldSlot",
"armourSlot",
"necklaceSlot",
"ringSlot",
"beltSlot",
"unknown",
"axeSlot",
"bowSlot",
"spearSlot",
"crossbowSlot",
"specialSlot",
"magicSlot",
"eggSlot",
"udderSlot",
"bannerSlot",
"princeWeaponSlot",
"princeHelmetSlot",
"princeShieldSlot",
"princeArmourSlot",
"quiverSlot",
"weaponPriestess_Or_SorcererSlot" };

std::vector<std::string> v_s_slot_type_8_labels = {
"spellPlugShield",
"spellPlugCapture",
"spellPlugStorm",
"spellPlugConversion",
"spellPlugFireRain",
"spellPlugSeeing",
"spellPlugTeleportation",
"spellPlugGhost",
"spellPlugWolf",
"spellPlugRemoveStorm" };

std::vector<std::string> v_s_storeable_flags_labels = {
"alwaysShadowed",
"notEnemyTarget",
"notSelectableActive",
"neverShadowed",
"notAutoTarget",
"childUnit",
"unknown1",
"unknown2",
"drawSelectionFrame",
"drawSelectionHP",
"drawDamagedSelectionFrame",
"drawDamagedSelectionHP_Or_PassiveSelection",
"drawEnemySelectionFrame",
"drawEnemySelectionHP",
"drawUnknown1",
"drawUnknown2",
"lockedDamageIncrease",
"lockedSpeedUpRegeneration",
"lockedSpeedUpMagicReload",
"lockedHarvestSpeedIncrease",
"lockedBuildSpeedIncrease",
"lockedArmourIncrease" };

std::vector<std::string> v_s_rpg_plug_type_labels = {
"spellPlugShield",
"spellPlugCapture",
"spellPlugStorm",
"spellPlugConversion",
"spellPlugRPGPriestess",
"spellPlugSeeing",
"spellPlugTeleportation",
"spellPlugGhost",
"spellPlugRPG1",
"spellPlugRPG2",
"spellPlugRPG3",
"spellPlugRPG4",
"spellPlugRPG5",
"spellPlugRPG6",
"spellPlugRPG7",
"spellPlugRPG8",
"spellPlugRPG9",
"spellPlugRPG10",
"spellPlugRPG11",
"spellPlugRPG12",
"spellPlugRPG13",
"spellPlugRPG14",
"spellPlugRPG15",
"spellPlugRPG16",
"spellPlugRPG17" };


std::vector<std::string> v_s_rpg_unit_flags_labels = {
"userRPGUnit",
"unknown1",
"unknown2",
"unknown3",
"singleShootAnim",
"holdTrapOnceUnit"
};


std::vector<std::string> v_s_artefact_mask_labels = {
"artefactRegenerateHP",
"artefactRegenerateMagic",
"artefactAddMaxHP",
"artefactAddDamage",
"artefactAddMaxMagic",
"artefactAddHP",
"artefactAddMagic",
"artefactGiveMoney",
"artefactShowMap",
"artefactGiveRPGMoney",
"unknown1",
"unknown2",
"artefactEquipment",
"artefactRPGUnitOnly",
"artefactNoLocatedTalk",
"artefactSpecialAI",
"artefactNoToolitpData",
"artefactDropFromInventory",
"artefactNoSold",
"artefactNoDrop",
"artefactNoUse",
"artefactNoRPGUnit",
"artefactUniqueTooltipText",
"artefactCurePoison",
"artefactNoBlinkInventory" };

std::vector<std::string> v_s_look_round_type_mask_labels = {
"lookRoundTypeDamageIncrease",
"lookRoundTypeRadar",
"lookRoundTypeShadow",
"lookRoundTypeArmourIncrease",
"lookRoundTypeSpeedUpHPRegeneration",
"lookRoundTypeSpeedUpMagicRegeneration",
"lookRoundTypeHarvestSpeedIncrease",
"lookRoundTypeBuildSpeedIncrease" };


std::vector<std::string> v_s_passive_mask_labels = {
"_wallConnectMask_",
"_wallTargetMask_",
"_depotMask_",
"_cornerMask_",
"_edgeMask_",
"_roadMask_",
"_startSmokeMask_",
"_transientMask_",
"_cantBeHitMask_",
"_initInvisibleMask_",
"_autoLightsMask_",
"_repairableMask_",
"_destroyableMask_",
"_loopedSoundMask_",
"_notVisibleMask_",
"_noResourceOnPassiveMask_",
"_initRandomLoopedAnimMask_",
"_cannonTransientMask_",
"_dayBirdMask_",
"_nightBirdMask_",
"_removeOnBuildingMask_",
"_colouredMask_",
"_destroyedEventMask_" };

std::vector<std::string> v_s_repairer_flags_labels = {
"repairerCanRepairUnits",
"repairerCanRepairAnimals",
"repairerCanRepairBuildings",
"repairerCanRepairConstructions",
"repairerCanConvertUnits",
"repairerCanConvertAnimals",
"repairerCanConvertBuildings",
"repairerCanCaptureBuildings",
"repairerNotTurnToTarget"
};

std::vector<std::string> v_s_bridge_borders_mask_labels = {
    "lockedBridgeBorderN",
"lockedBridgeBorderE",
"lockedBridgeBorderS",
"lockedBridgeBorderW"

};

std::vector<std::string> v_s_shadow_type_labels = {
"_shadowSimple",
"_shadowStatic",
"_shadowAnimated",
"_shadowVertical",
"unknown1",
"unknown2",
"unknown3",
"unknown4",
"_moveWind",
"_noReflect",
"unknown5",
"_hasNotBigEnoughBox",
"_noSubObjectShadow",
"_symmetricShadow",
"unknown6",
"unknown7",
"_shadowOldStatic",
"_shadowOldRound",
"_shadowOldEllipse1",
"_shadowOldEllipse2",
"_shadowOldEllipse3",
"_shadowOldTree",
"_hasOldSoftwareRendering" };

std::vector<std::string> v_s_target_type_labels = {
"targetTypeGround",
"targetTypeAir",
"targetNoUnitOnTower",
"turnExplosionToTarget" };

std::vector<std::string> v_s_panel_pos_labels = {
"tab1" };

std::vector<std::string> v_s_build_building_flags_labels = {
"unknown1",
"unknown2",
"unknown3",
"unknown4",
"buildAllowLZ0",
"buildAllowLZ1",
"buildTabBuildings",
"buildTabConstructions",
"buildAutoTurnToRoad",
"buildingLockSold",
"unknown5",
"unknown6",
"buildingNoChangeAltitude",
"buildingNoChangeTerrain",
"buildingNoRoadNeighbour",
"towerNoChangePlayer",
"gateNoChangePlayer",
"gateNoUnitRequired",
"cantBeCaptured",
"haveLoopedDoorsSound",
"gateLockEdge1",
"gateLockEdge2",
"researchUpdateButton",
"initVisibleFlags",
"noDarkVisibleFake" };



vector<string> v_s_moveable_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12",
    "moveableFlags",
    "$productionBuildingID",
    "formationPriority",
    "unitNameSet",
    "unitsListNumber",
    "soilSpeed",
    "roadSpeed",
    "sandSpeed",
    "bankSpeed",
    "waterSpeed",
    "deepWaterSpeed",
    "airSpeed",
    "camouflageSpeed",
    "runSpeed",
    "objectType",
    "$animParamsID",
    "$engineSmokeID",
    "$dustID",
    "$billowID",
    "$standBillowID",
    "$trackID",
    "$experienceExplosionID",
    "experienceExplosionPos",
    "experienceCustomAnimMask",
    "sleepModeHPRegAdd",
    "sleepModeMagicRegAdd",
    "sleepModeDamageMultiply",
    "exitTrapPercent",
    "exitTrapDamageMaxPercent",
    "scriptParams",
    "$childProtectHitExplosionID",
    "$childConversionExplosionID" };




vector <string> v_s_shop_unit_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12",
    "moveableFlags",
    "$productionBuildingID",
    "formationPriority",
    "unitNameSet",
    "unitsListNumber",
    "soilSpeed",
    "roadSpeed",
    "sandSpeed",
    "bankSpeed",
    "waterSpeed",
    "deepWaterSpeed",
    "airSpeed",
    "camouflageSpeed",
    "runSpeed",
    "objectType",
    "$animParamsID",
    "$engineSmokeID",
    "$dustID",
    "$billowID",
    "$standBillowID",
    "$trackID",
    "$experienceExplosionID",
    "experienceExplosionPos",
    "experienceCustomAnimMask",
    "sleepModeHPRegAdd",
    "sleepModeMagicRegAdd",
    "sleepModeDamageMultiply",
    "exitTrapPercent",
    "exitTrapDamageMaxPercent",
    "scriptParams",
    "$childProtectHitExplosionID",
    "$childConversionExplosionID",
    "shopType" 
};

std::vector<std::string> v_s_rpg_unit_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"rpgUnitType",
"RPGUnitFlags",
"rpgViewParamsNum",
"descriptionWave",
"inititializePoints",
"maxInventorySize",
"$experienceParamsID",
"$hpParamsID",
"$damage0ParamsID",
"$damage1ParamsID",
"$damage2ParamsID",
"$magicParamsID",
"$extraCannonDamageParamsID",
"$extraSwordDamageParamsID",
"$avoidSwordHitsParamsID",
"$avoidAnyHitsParamsID",
"$extraRangeParamsID",
"$camouflagingParamsID",
"$holdTrapParamsID",
"$runExtraDamageParamsID",
"$extraCrewDamageParamsID",
"$strongFightParamsID",
"$fastSleepHPRegenerationParamsID",
"$multiTargetDamageParamsID",
"$extraArmour0ParamsID",
"$scriptDiplomacyParamsID",
"$scriptArtefactParamsID",
"$pingMagicMissilesID",
"hireTime",
"hirePrice",
"hireSubObjectsPricePercent",
"$strongFightEffectID",
"$holdTrapID",
"$dropGoldArtefactID" };

std::vector <std::string> v_s_builder_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"repairerFlags",
"repairHPPerTick",
"ticksPerRepair",
"captureMask",
"convertUnitTime",
"convertAnimalTime",
"convertBuildingTime" };

std::vector<std::string> v_s_repairer_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"repairerFlags",
"repairHPPerTick",
"ticksPerRepair",
"captureMask",
"convertUnitTime",
"convertAnimalTime",
"convertBuildingTime" };


std::vector<std::string> v_s_harvester_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"maxHarvestedMoney",
"ticksPerHarvestResource",
"putResourceAngle",
"moneyPerExperiencePoint",
"$ShitFlyingWasteID" };

std::vector<std::string> v_s_cannon_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"minRangeOfFire",
"rangeOfFire",
"shootCloseTowerMinRange",
"shootCloseTowerRange",
"shootCloseTowerBeta",
"shootCloseMinRange",
"shootCloseRange",
"shootCloseBeta",
"shootFarMinRange",
"shootFarRange",
"shootFarBeta",
"alphaMargin",
"shooterSwordAlphaMargin",
"betaMargin",
"cannonAnimType",
"$ammoID",
"$shooterSwordAmmoID",
"ammoType",
"targetType",
"shootDelay",
"shootMagicCost",
"$barrelExplosionID",
"barrelExplosionOnSlot",
"addCannonExtraDamageRandPercent" };

std::vector<std::string> v_s_missile_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"type",
"speed",
"timeOfShoot",
"hitType",
"hitRange",
"damage1",
"damage2",
"damage3",
"poissonHP",
"poissonHPTime",
"$poissonEffectID",
"$explosionID",
"notDamageAllies" };

std::vector<std::string> v_s_special_equipment_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"equipmentFlags",
"addHPRegeneration",
"addArmour1",
"addArmour2",
"addArmour3",
"addMagicRegeneration",
"addMaxMagicPercent",
"addMaxMagicVal",
"addMaxHP",
"addExtraDamage0",
"addExtraDamage1",
"addExtraDamage2",
"addExtraDamageRandPercent" };

std::vector<std::string> v_s_magic_equipment_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"magicType",
"rpgPointsCost",
"magicAnimType",
"magicCost",
"magicRange",
"magicExecuteRange",
"magicExecuteTime",
"$magicExplosionID",
"magicExplosionPos",
"$targetExplosionID",
"targetExplosionPos",
"$targetEffectID",
"targetEffectExplosionPos",
"$targetEndEffectID",
"$immortalShieldID",
"magicCaptureMask",
"magicCapturePercent",
"stormPower",
"$spyID",
"$magicConversionUnitID",
"magicConversionMask",
"magicConversionPercent",
"fireRainPower",
"$ghostID",
"$wildAnimalID",
"magicRangeMesh",
"getHPValue",
"$magicTrapID",
"aroundDamage0",
"aroundDamage1",
"aroundDamage2",
"$fireWallSmokeID",
"fireWallLength",
"magicMirrorExperiencePercent",
"healingHP",
"timedLifeMagicUnitMaxCount",
"magicUpdateMinExperienceLevel" };

std::vector<std::string> v_s_equipment_artefact_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"artefactMask",
"artefactInventorySize",
"artefactRPGCost",
"artefactRPGCostCategory",
"minExperienceLevel",
"minMagic",
"minDamage0",
"minDamage1",
"minDamage2",
"useButtonNum",
"useButtonPriority",
"$useExplosionID",
"artefactParam",
"respawnTime",
"addDamage1",
"addDamage2",
"addDamage3",
"$equipmentID" };

std::vector<std::string> v_s_artefact_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"artefactMask",
"artefactInventorySize",
"artefactRPGCost",
"artefactRPGCostCategory",
"minExperienceLevel",
"minMagic",
"minDamage0",
"minDamage1",
"minDamage2",
"useButtonNum",
"useButtonPriority",
"$useExplosionID",
"artefactParam",
"respawnTime",
"addDamage1",
"addDamage2",
"addDamage3" };

std::vector<std::string> v_s_look_round_equipment_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"lookRoundTypeMask",
"lookRoundRange",
"turnSpeed",
"damageIncreasePercent",
"speedUpHPRegenerationAdd",
"speedUpMagicRegerationAdd",
"harvestSpeedIncrease",
"buildSpeedIncrease",
"armour0Increase",
"armour1Increase",
"armour2Increase",
"$lookRoundEffectID",
"showEffectForAllPlayers" };

std::vector<std::string> v_s_look_round_equipment_effect_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID" };

std::vector<std::string> v_s_equipment_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID" };

std::vector<std::string> v_s_building_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"buildingType",
"buildingTypeEx",
"buildBuildingFlags",
"$requiredBuilding",
"$copulaID",
"productionNumber",
"maxUnitsInBuilding",
"buildingConnectFlags",
"$chimneySmokeID",
"$nightSmokeID",
"$buildExplosionID",
"$connectWallID",
"$bridgeGateID",
"extraTowerArmour1",
"extraTowerArmour2",
"extraTowerArmour3",
"assemblyPointMesh",
"harvestLoopsCnt",
"harvestStartBeg",
"harvestStartEnd",
"harvestLoopBeg",
"harvestLoopEnd",
"harvestEndBeg",
"harvestEndEnd" };

std::vector<std::string> v_s_passive_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$buildCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID" };

std::vector<std::string> v_s_special_passive_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"entranceTunnelNumber",
"$entranceExplosionID",
"entranceExplosionPos",
"hpRegenerationAdd",
"magicRegenerationAdd",
"$conversionUnitID",
"conversionMask",
"conversionTime",
"conversionRequiredHPPercent" };

std::vector<std::string> v_s_trap_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"trapType",
"trapInventorySize",
"trapRPGCost",
"trapRPGCostCategory",
"holdTime",
"trapDamage0",
"trapDamage1",
"trapDamage2",
"trapDamageRange",
"trapPoissonHP",
"trapPoissonHPTime",
"$trapPoissonEffectID",
"beginTrapAnimBeg",
"beginTrapAnimEnd",
"endTrapAnimBeg",
"endTrapAnimEnd",
"$trapExplosionID",
"trapExistTime",
"holdExtraDamagePercent" };

std::vector<std::string> v_s_vertical_vehicle_spy_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"vehicleSpeed",
"verticalVehicleAnimationType",
"flightLevel" };

std::vector<std::string> v_s_vertical_vehicle_bomber_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"vehicleSpeed",
"verticalVehicleAnimationType",
"bombsCnt",
"createDistanceFromTarget" };

std::vector<std::string> v_s_explosion_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"explosionTicks",
"explosionFlags",
"explosionSoundDelay" };

std::vector<std::string> v_s_multi_explosion_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"useDownBuilding",
"downBuildingStart",
"downBuildingTime",
"$subObject1",
"time1",
"angle1",
"dist4X1",
"$subObject2",
"time2",
"angle2",
"dist4X2",
"$subObject3",
"time3",
"angle3",
"dist4X3",
"$subObject4",
"time4",
"angle4",
"dist4X4",
"$subObject5",
"time5",
"angle5",
"dist4X5",
"$subObject6",
"time6",
"angle6",
"dist4X6",
"$subObject7",
"time7",
"angle7",
"dist4X7",
"$subObject8",
"time8",
"angle8",
"dist4X8" };

std::vector<std::string> v_s_smoke_labels = {
"classID",
"mesh",
"lowResmesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"mainSmokeTicks",
"mesh1",
"mesh2",
"mesh3",
"smokeTime1",
"smokeTime2",
"smokeTime3",
"smokeFrequency",
"startingTime",
"smokingTime",
"endingTime",
"smokeUpSpeed",
"newSmokeDistance" };

std::vector<std::string> v_s_smoke_fire_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"standType",
"mapSign",
"mainSmokeTicks",
"mesh1",
"mesh2",
"mesh3",
"smokeTime1",
"smokeTime2",
"smokeTime3",
"smokeFrequency",
"startingTime",
"smokingTime",
"endingTime",
"smokeUpSpeed",
"newSmokeDistance",
"smokeDamage1",
"smokeDamage2",
"smokeDamage3",
"smokeDamageTicks",
"smokeTime" };

std::vector<std::string> v_s_starting_position_mark_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"positionType" };

std::vector<std::string> v_s_ai_platoon_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12" };

std::vector<std::string> v_s_flying_waste_labels = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"wasteSize",
"$subWasteID1",
"subWaste1Alpha",
"$subWasteID2",
"subWaste2Alpha",
"$subWasteID3",
"subWaste3Alpha",
"$subWasteID4",
"subWaste4Alpha",
"flightTime",
"wasteSpeed",
"wasteDistanceX4",
"wasteBeta" };

std::vector<std::string> v_s_talk_packs_labels = {
"talkPack1",
"talkPack2",
"talkPack3",
"talkPack4",
"talkPack5",
"talkPack6",
"talkPack7",
"talkPack8",
"talkPack9",
"talkPack10",
"talkPack11",
"talkPack12",
"talkPack13",
"talkPack14",
"talkPack15",
"talkPack16",
"talkPack17",
"talkPack18",
"talkPack19",
"talkPack20",
"talkPack21",
"talkPack22",
"talkPack23",
"talkPack24",
"talkPack25",
"talkPack26",
"talkPack27",
"talkPack28",
"talkPack29",
"talkPack30" };

std::vector<std::string> v_s_anim_params_labels = {
"speedFactAccelerate",
"speedFactorMove",
"speedFactorBreak",
"speedFactorTurn45",
"speedFactorTurn90",
"speedFactorTurn135",
"speedFactorTurn180",
"trajcFactor1",
"trajcFactor2",
"trajcFactor3",
"trajcFactor4",
"trajcFactor5",
"trajcFactor6",
"trajcFactor7",
"trajcFactor8",
"trajcFactor9",
"trajcFactor10",
"trajcFactor11",
"trajcFactor12",
"stay1Beg",
"stay1End",
"stay2Beg",
"stay2End",
"stay3Beg",
"stay3End",
"stay4Beg",
"stay4End",
"stayCamouflagedBeg",
"stayCamouflagedEnd",
"accelerateBeg",
"accelerateEnd",
"moveBeg",
"moveEnd",
"breakBeg",
"breakEnd",
"runBeg",
"runEnd",
"turnR45Beg",
"turnR45End",
"turnR90Beg",
"turnR90End",
"turnR135Beg",
"turnR135End",
"turnR180Beg",
"turnR180End",
"turnL45Beg",
"turnL45End",
"turnL90Beg",
"turnL90End",
"turnL135Beg",
"turnL135End",
"accelerateCamouflagedBeg",
"accelerateCamouflagedEnd",
"moveCamouflagedBeg",
"moveCamouflagedEnd",
"breakCamouflagedBeg",
"breakCamouflagedEnd",
"turnCamouflagedR45Beg",
"turnCamouflagedR45End",
"turnCamouflagedR90Beg",
"turnCamouflagedR90End",
"turnCamouflagedR135Beg",
"turnCamouflagedR135End",
"turnCamouflagedR180Beg",
"turnCamouflagedR180End",
"turnCamouflagedL45Beg",
"turnCamouflagedL45End",
"turnCamouflagedL90Beg",
"turnCamouflagedL90End",
"turnCamouflagedL135Beg",
"turnCamouflagedL135End",
"moveClimbBeg",
"moveClimbEnd",
"moveFlyingStartBeg",
"moveFlyingStartEnd",
"moveFlyingBeg",
"moveFlyingEnd",
"moveFlyingStopBeg",
"moveFlyingStopEnd",
"landToFlyBeg",
"landToFlyEnd",
"flyToLandBeg",
"flyToLandEnd",
"animStartCamouflageBeg",
"animStartCamouflageEnd",
"animEndCamouflageBeg",
"animEndCamouflageEnd",
"animStartSleepBeg",
"animStartSleepEnd",
"animSleepBeg",
"animSleepEnd",
"animEndSleepBeg",
"animEndSleepEnd",
"animEnemyAlertBeg",
"animEnemyAlertEnd",
"animStartWorkBeg",
"animStartWorkEnd",
"animWork1Beg",
"animWork1End",
"animWork2Beg",
"animWork2End",
"animEndWorkBeg",
"animEndWorkEnd",
"animShitBeg",
"animShitEnd",
"animStartFightBeg",
"animStartFightEnd",
"animFightHit1Beg",
"animFightHit1End",
"animFightHit2Beg",
"animFightHit2End",
"animFightHit3Beg",
"animFightHit3End",
"animFightHit4Beg",
"animFightHit4End",
"animEndFightBeg",
"animEndFightEnd",
"animStartFight2Beg",
"animStartFight2End",
"animFight2Hit1Beg",
"animFight2Hit1End",
"animFight2Hit2Beg",
"animFight2Hit2End",
"animFight2Hit3Beg",
"animFight2Hit3End",
"animFight2Hit4Beg",
"animFight2Hit4End",
"animEndFight2Beg",
"animEndFight2End",
"animStartRunFightBeg",
"animStartRunFightEnd",
"animRunFightHitBeg",
"animRunFightHitEnd",
"animEndRunFightBeg",
"animEndRunFightEnd",
"animStartShootBeg",
"animStartShootEnd",
"animShootFar1Beg",
"animShootFar1End",
"animShootFar2Beg",
"animShootFar2End",
"animShootClose1Beg",
"animShootClose1End",
"animShootClose2Beg",
"animShootClose2End",
"animShootCloseTowerBeg",
"animShootCloseTowerEnd",
"animEndShootBeg",
"animEndShootEnd",
"animMagic1Beg",
"animMagic1End",
"animMagic2Beg",
"animMagic2End",
"animMagic3Beg",
"animMagic3End",
"animMagic4Beg",
"animMagic4End",
"animDead1Beg",
"animDead1End",
"animDead2Beg",
"animDead2End",
"animDead3Beg",
"animDead3End",
"animDead4Beg",
"animDead4End",
"animDeadSleepBeg",
"animDeadSleepEnd",
"animCustom1Beg",
"animCustom1End",
"animCustom2Beg",
"animCustom2End",
"animCustom3Beg",
"animCustom3End",
"animCustom4Beg",
"animCustom4End",
"animPutHoldTrapBeg",
"animPutHoldTrapEnd",
"animGetHoldTrapBeg",
"animGetHoldTrapEnd",
"animWork1Fire",
"animWork2Fire",
"shitFire",
"animFightHit1Fire",
"animFightHit2Fire",
"animFightHit3Fire",
"animFightHit4Fire",
"animFight2Hit1Fire",
"animFight2Hit2Fire",
"animFight2Hit3Fire",
"animFight2Hit4Fire",
"animRunFightHitFire",
"animShootFar1Fire",
"animShootFar2Fire",
"animShootClose1Fire",
"animShootClose2Fire",
"animShootCloseTowerFire",
"animMagic1Fire",
"animMagic2Fire",
"animMagic3Fire",
"animMagic4Fire",
"animDead1Frame",
"animDead2Frame",
"animDead3Frame",
"animDead4Frame",
"animDeadSleepFrame",
"animPutHoldTrapFrame",
"animGetHoldTrapFrame" };

std::vector<std::string> v_s_sound_pack_labels = {
"normalWavePack1",
"normalWavePack2",
"normalWavePack3",
"normalWavePack4",
"loopedWavePack1",
"loopedWavePack2",
"loopedWavePack3",
"loopedWavePack4" };

std::vector<std::string> v_s_passive_anim_params_labels = {
"anim1Beg",
"anim1End",
"anim2Beg",
"anim2End",
"anim3Beg",
"anim3End",
"anim4Beg",
"anim4End",
"anim5Beg",
"anim5End" };

std::vector<std::string> v_s_talk_pack_delays_labels = {
"talkPackDelay1",
"talkPack1MapSign",
"talkPack1MapSignTime",
"talkPackDelay2",
"talkPack2MapSign",
"talkPack2MapSignTime",
"talkPackDelay3",
"talkPack3MapSign",
"talkPack3MapSignTime",
"talkPackDelay4",
"talkPack4MapSign",
"talkPack4MapSignTime",
"talkPackDelay5",
"talkPack5MapSign",
"talkPack5MapSignTime",
"talkPackDelay6",
"talkPack6MapSign",
"talkPack6MapSignTime",
"talkPackDelay7",
"talkPack7MapSign",
"talkPack7MapSignTime",
"talkPackDelay8",
"talkPack8MapSign",
"talkPack8MapSignTime",
"talkPackDelay9",
"talkPack9MapSign",
"talkPack9MapSignTime",
"talkPackDelay10",
"talkPack10MapSign",
"talkPack10MapSignTime",
"talkPackDelay11",
"talkPack11MapSign",
"talkPack11MapSignTime",
"talkPackDelay12",
"talkPack12MapSign",
"talkPack12MapSignTime",
"talkPackDelay13",
"talkPack13MapSign",
"talkPack13MapSignTime",
"talkPackDelay14",
"talkPack14MapSign",
"talkPack14MapSignTime",
"talkPackDelay15",
"talkPack15MapSign",
"talkPack15MapSignTime",
"talkPackDelay16",
"talkPack16MapSign",
"talkPack16MapSignTime",
"talkPackDelay17",
"talkPack17MapSign",
"talkPack17MapSignTime",
"talkPackDelay18",
"talkPack18MapSign",
"talkPack18MapSignTime",
"talkPackDelay19",
"talkPack19MapSign",
"talkPack19MapSignTime",
"talkPackDelay20",
"talkPack20MapSign",
"talkPack20MapSignTime",
"talkPackDelay21",
"talkPack21MapSign",
"talkPack21MapSignTime",
"talkPackDelay22",
"talkPack22MapSign",
"talkPack22MapSignTime",
"talkPackDelay23",
"talkPack23MapSign",
"talkPack23MapSignTime",
"talkPackDelay24",
"talkPack24MapSign",
"talkPack24MapSignTime",
"talkPackDelay25",
"talkPack25MapSign",
"talkPack25MapSignTime",
"talkPackDelay26",
"talkPack26MapSign",
"talkPack26MapSignTime",
"talkPackDelay27",
"talkPack27MapSign",
"talkPack27MapSignTime",
"talkPackDelay28",
"talkPack28MapSign",
"talkPack28MapSignTime",
"talkPackDelay29",
"talkPack29MapSign",
"talkPack29MapSignTime",
"talkPackDelay30",
"talkPack30MapSign",
"talkPack30MapSignTime" };

std::vector<std::string> v_s_player_talk_pack_labels = {
"talkPack1",
"talkPack2",
"talkPack3",
"talkPack4",
"talkPack5",
"talkPack6",
"talkPack7",
"talkPack8",
"talkPack9",
"talkPack10",
"talkPack11",
"talkPack12",
"talkPack13",
"talkPack14" };

std::vector<std::string> v_s_player_talk_pack_delays_labels = {
"talkPackDelay1",
"talkPackMapSign1",
"talkPackMapSignTime1",
"talkPackDelay2",
"talkPackMapSign2",
"talkPackMapSignTime2",
"talkPackDelay3",
"talkPackMapSign3",
"talkPackMapSignTime3",
"talkPackDelay4",
"talkPackMapSign4",
"talkPackMapSignTime4",
"talkPackDelay5",
"talkPackMapSign5",
"talkPackMapSignTime5",
"talkPackDelay6",
"talkPackMapSign6",
"talkPackMapSignTime6",
"talkPackDelay7",
"talkPackMapSign7",
"talkPackMapSignTime7",
"talkPackDelay8",
"talkPackMapSign8",
"talkPackMapSignTime8",
"talkPackDelay9",
"talkPackMapSign9",
"talkPackMapSignTime9",
"talkPackDelay10",
"talkPackMapSign10",
"talkPackMapSignTime10",
"talkPackDelay11",
"talkPackMapSign11",
"talkPackMapSignTime11",
"talkPackDelay12",
"talkPackMapSign12",
"talkPackMapSignTime12",
"talkPackDelay13",
"talkPackMapSign13",
"talkPackMapSignTime13",
"talkPackDelay14",
"talkPackMapSign14",
"talkPackMapSignTime14" };

std::vector<std::string> v_s_music_pack_labels = {
"mainMusic",
"statisticVictoryMusic",
"statisticDefeatMusic",
"dayMusic1",
"dayMusic2",
"dayMusic3",
"dayMusic4",
"dayMusic5",
"dayMusic6",
"dayMusic7",
"dayMusic8",
"nightMusic1",
"nightMusic2",
"nightMusic3",
"nightMusic4",
"nightMusic5",
"nightMusic6",
"nightMusic7",
"nightMusic8",
"warMusic1",
"warMusic2",
"warMusic3",
"warMusic4",
"warMusic5",
"warMusic6",
"warMusic7",
"warMusic8" };

std::vector<std::string> v_s_experience_params_labels = {
"levelPoints",
"harvesterLevelPoints",
"convertLevelPoints",
"speedAdd",
"maxHPAdd",
"maxMagicAdd",
"damageAdd",
"shootDelayAdd",
"sightRangeAdd",
"shootRangeAdd",
"maxHarvesterMoneyAdd",
"convertPercentAdd" };

std::vector<std::string> v_s_mesh_button_view_params_labels = {
"posX",
"posY",
"posZ",
"posAlpha",
"posBeta" };

std::vector<std::string> v_s_selection_meshes_labels = {
"road",
"roadOnBridge",
"roadBad",
"roadBadOnBridge",
"bridgeBeg",
"bridgeBegOnBridge",
"buildEntrance",
"buildEntranceOnBridge",
"commandMove",
"commandMoveOnBridge",
"commandMoveHoldPos",
"commandMoveHoldPosOnBridge",
"commandEnter",
"commandEnterOnBridge",
"commandAttack",
"commandAttackOnBridge",
"commandAttack1x1",
"commandAttack3x3",
"commandAttack4x1",
"commandOther",
"commandOtherOnBridge",
"commandOther1x1",
"commandOther3x3",
"commandOther4x1" };

std::vector<std::string> v_s_special_updates_links_labels = {
"$specialUpdateLink",
};

std::vector<std::string> v_s_race_data_labels = {
"raceIdentifier",
"raceFlags",
"buildFlags",
"$wallID",
"$narrowBridgeID",
"$wideBridgeID",
"$singleBridgeID",
"$roadID",
"roadCost",
"$platoonID",
"wallTemplateNum",
"wallPanelPos",
"narrowBridgeTemplateNum",
"narrowBridgePanelPos",
"wideBridgeTemplateNum",
"wideBridgeTemplatePos",
"singleBridgeTemplateNum",
"singleBridgePanelPos",
"roadTemplateNum",
"roadPanelPos",
"$unitTalkPackDelaysID",
"$buildingTalkPackDelaysID",
"$playerTalkPackID",
"$playerTalkPackDelaysID",
"$musicPackID",
"interfaceFlags",
"defBannerName",
"defStatsBannerName",
"defaultInterface",
"$selectionMeshes" };

std::vector<std::string> v_s_rpg_params_labels = {
"pointsCost",
"value1",
"value2",
"value3" };

std::vector<std::string> v_s_rpg_experience_labels = {
"experiencePoints",
"addRPGPoints",
"addHireCost",
"addHPLevel",
"addDamageLevel" };

vector<string> v_s_vertical_vehicle_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12",
    "vehicleSpeed",
    "verticalVehicleAnimationType" 
};

vector<string> v_s_scripted_active_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12" 
};

vector<string> v_s_active_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12" 
};

vector<string> v_s_generic_labels = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID" 
};

vector<string> v_s_mine_labels = {
    "classID",
    "mesh",
    "shadowType",
    "viewParamsIndex",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "regenerationHP",
    "armour",
    "calorificCapacity",
    "disableResist",
    "storeableFlags",
    "standType",
    "mineSize",
    "mineTypeOfDamage",
    "mineDamage" 
};

void Object::PrintLabels(BinFile& bin_file, vector<string>& labels)
{
    int i = 0;

    size_t delta = (m_logic_table_bits.length() + 1) / 2;
    if (delta > labels.size())
    {
        delta -= labels.size();

        for (int j = 0; j < delta; ++j)
            labels.push_back("ExtraField" + to_string(j));
    }

    bool is_special = false;

    for (const std::string& label : labels)
    {

        if (label[0] == '$')
        {
            is_special = true;
        }
        else
        {
            is_special = false;
        }

        switch (m_logic_table_bits[i])
        {
        case '0':
            CheckIfItIsAMaskLabel(bin_file, label);
        break;

        case '1':

            if (is_special == true)
            {
                string str_field = bin_file.ReadString();
                this->m_cpp_file.WriteString(1, label, str_field);

                uint32_t var_field = 0;
                bin_file.ReadValue(var_field);
                this->m_cpp_file.WriteTrivialValue(1, label, var_field);
            }
            else
            {
                string str_field = bin_file.ReadString();
                this->m_cpp_file.WriteString(1, label, str_field);
            }
            break;

        default: break;
        }


        if (is_special == true)
        {
            i += 2;
        }

        i += 2;

        if (i > m_logic_table_bits.length() - 1) break;

    }

}


void Object::SelectAndPrintLabelsForClassId(BinFile& bin_file)
{
    uint32_t help_mask = 0x00FFFFFF;

    uint32_t help_classid = this->m_classid & help_mask;

    uint32_t var_field = 0;
    string str_field = string();

    if (help_classid == help_mask)
    {
        switch (this->m_classid)
        {
        case OTHER_CLASS_ID_TALK_PACKS:
            PrintLabels(bin_file, v_s_talk_packs_labels);
        break;

        case OTHER_CLASS_ID_ANIM_PARAMS:
            PrintLabels(bin_file, v_s_anim_params_labels);
        break;

        case OTHER_CLASS_ID_SOUND_PACK:
            PrintLabels(bin_file, v_s_sound_pack_labels);
        break;

        case OTHER_CLASS_ID_PASSIVE_ANIM_PARAMS:
            PrintLabels(bin_file, v_s_passive_anim_params_labels);
        break;

        case OTHER_CLASS_ID_TALK_PACK_DELAYS:
            PrintLabels(bin_file, v_s_talk_pack_delays_labels);
        break;

        case OTHER_CLASS_ID_PLAYER_TALK_PACK:
            PrintLabels(bin_file, v_s_player_talk_pack_labels);
        break;

        case OTHER_CLASS_ID_PLAYER_TALK_PACK_DELAYS:
            PrintLabels(bin_file, v_s_player_talk_pack_delays_labels);
        break;

        case OTHER_CLASS_ID_MUSIC_PACK:
            PrintLabels(bin_file, v_s_music_pack_labels);
        break;

        case OTHER_CLASS_ID_EXPERIENCE_PARAMS:
            PrintLabels(bin_file, v_s_experience_params_labels);
        break;

        case OTHER_CLASS_ID_MESH_BUTTON_VIEW_PARAMS:
            PrintLabels(bin_file, v_s_mesh_button_view_params_labels);
        break;

        case OTHER_CLASS_ID_SELECTION_MESHES:
            PrintLabels(bin_file, v_s_selection_meshes_labels);
        break;

        case OTHER_CLASS_ID_SPECIAL_UPDATES_LINKS:
            PrintLabels(bin_file, v_s_special_updates_links_labels);
        break;

        case OTHER_CLASS_ID_RACE_DATA:
            PrintLabels(bin_file, v_s_race_data_labels);
        break;

        case OTHER_CLASS_ID_RPG_PARAMS:
            PrintLabels(bin_file, v_s_rpg_params_labels);
        break;

        case OTHER_CLASS_ID_RPG_EXPERIENCE:
            PrintLabels(bin_file, v_s_rpg_experience_labels);
        break;

        default:
            for (int i = 0; i < m_logic_table_bits.length(); i++)
            {
                switch (m_logic_table_bits[i])
                {
                    case '0': 
                        bin_file.ReadValue(var_field);
                        this->m_cpp_file.WriteTrivialValue(1, "var_field", var_field);
                    break;

                    case '1': 
                        str_field = bin_file.ReadString();
                        this->m_cpp_file.WriteString(1, "str_field", str_field);
                    break;

                    default: 
                    break;
                }
            }
            break;

        }

        return;
    }

    if (
        (this->m_classid == ANIMATEDPASSIVE)
        || 
        (this->m_classid == ANIMALPASSIVE)
        || 
        (this->m_classid == BUILDPASSIVE)
        || 
        (this->m_classid == GHOSTPASSIVE)
        ||
        (this->m_classid == TRANSIENTPASSIVE)
        || 
        (this->m_classid == PASSIVE)
       )
    {
        PrintLabels(bin_file, v_s_passive_labels);
        return;
    }

    if ((this->m_classid == SPECIALEQUIPMENT) || (this->m_classid == SPECIALEQUIPMENTEX))
    {
        PrintLabels(bin_file, v_s_special_equipment_labels);
        return;
    }


    if (
        (this->m_classid == STOREABLE) 
        || 
        (this->m_classid == DYNAMIC)
        || 
        (this->m_classid == GENERIC)
        || 
        (this->m_classid == VISIBLEFAKE)
       )
    {
        PrintLabels(bin_file, v_s_generic_labels);
        return;
    }

    if ((this->m_classid == EXPLOSION) || (this->m_classid == EXPLOSIONEX))
    {
        PrintLabels(bin_file, v_s_explosion_labels);
        return;
    }


    switch (this->m_classid)
    {
        case MOVEABLE:
            PrintLabels(bin_file, v_s_moveable_labels);
        break;

        case SHOPUNIT:
            PrintLabels(bin_file, v_s_shop_unit_labels);
        break;

        case RPGUNIT:
            PrintLabels(bin_file, v_s_rpg_unit_labels);
        break;

        case BUILDER:
            PrintLabels(bin_file, v_s_builder_labels);
        break;

        case REPAIRER:
            PrintLabels(bin_file, v_s_repairer_labels);
        break;

        case HARVESTER:
            PrintLabels(bin_file, v_s_harvester_labels);
        break;

        case CANNON:
            PrintLabels(bin_file, v_s_cannon_labels);
        break;

        case MISSILE:
            PrintLabels(bin_file, v_s_missile_labels);
        break;

        case MAGICEQUIPMENT:
            PrintLabels(bin_file, v_s_magic_equipment_labels);
        break;

        case EQUIPMENTARTEFACT:
            PrintLabels(bin_file, v_s_equipment_artefact_labels);
        break;

        case ARTEFACT:
            PrintLabels(bin_file, v_s_artefact_labels);
        break;

        case LOOKROUNDEQUIPMENT:
            PrintLabels(bin_file, v_s_look_round_equipment_labels);
        break;

        case LOOKROUNDEQUIPMENTEFFECT:
            PrintLabels(bin_file, v_s_look_round_equipment_effect_labels);
        break;

        case EQUIPMENT:
            PrintLabels(bin_file, v_s_equipment_labels);
        break;

        case BUILDING:
            PrintLabels(bin_file, v_s_building_labels);
        break;

        //active
        case ACTIVE:
            PrintLabels(bin_file, v_s_active_labels);
        break;

        //mine
        case MINE:
            PrintLabels(bin_file, v_s_mine_labels);
        break;

        case SPECIALPASSIVE:
            PrintLabels(bin_file, v_s_special_passive_labels);
        break;

        case TRAP:
            PrintLabels(bin_file, v_s_trap_labels);
        break;

        case SCRIPTEDACTIVE:
            PrintLabels(bin_file, v_s_scripted_active_labels);
        break;

        case VERTICALVEHICLE:
            PrintLabels(bin_file, v_s_vertical_vehicle_labels);
        break;

        case VERTICALVEHICLESPY:
            PrintLabels(bin_file, v_s_vertical_vehicle_spy_labels);
        break;

        case VERTICALVEHICLEBOMBER:
            PrintLabels(bin_file, v_s_vertical_vehicle_bomber_labels);
        break;


        case MULTIEXPLOSION:
            PrintLabels(bin_file, v_s_multi_explosion_labels);
        break;

        case SMOKE:
            PrintLabels(bin_file, v_s_smoke_labels);
        break;

        case SMOKEFIRE:
            PrintLabels(bin_file, v_s_smoke_fire_labels);
        break;

        case STARTINGPOSITIONMARK:
            PrintLabels(bin_file, v_s_starting_position_mark_labels);
        break;

        case AIPLATOON:
            PrintLabels(bin_file, v_s_ai_platoon_labels);
        break;

        case FLYINGWASTE:
            PrintLabels(bin_file, v_s_flying_waste_labels);
        break;

    default:

        for (int i = 0; i < m_logic_table_bits.length(); i++)
        {
            switch (m_logic_table_bits[i])
            {
                case '0': 
                    bin_file.ReadValue(var_field);
                    this->m_cpp_file.WriteTrivialValue(1, "var_field", var_field);
                break;

                case '1': 
                    str_field = bin_file.ReadString();
                    this->m_cpp_file.WriteString(1, "str_field", str_field);
                break;
                
                default: 
                break;
            }
        }

        break;

    }


}

void Object::CheckMaskLabelsAndCorrect(vector<string>& mask_labels)
{
    if (mask_labels.size() < Globals::int_to_bits)
    {
        size_t delta = Globals::int_to_bits - mask_labels.size();
        for (int j = 0; j < delta; ++j)
        {
            mask_labels.push_back("ExtraFlag" + std::to_string(j));
        }
    }

}

void Object::CheckIfItIsAMaskLabel(BinFile& bin_file, const string& label)
{
    uint8_t temp_uint8_val = 0;
    uint16_t temp_uint16_val = 0;
    uint32_t temp_val = 0;

    array<uint8_t, sizeof(uint32_t) - 1> temp_uint8_array_3 = {};
    array<uint8_t, sizeof(uint32_t)> temp_uint8_array_4 = {};
    array<uint8_t, sizeof(uint16_t)> temp_uint8_array_2 = {};
    array<uint8_t, sizeof(uint8_t)> temp_uint8_array_1 = {};

    if (label == "mapSign")
    {
        int32_t map_sign_value = 0;
        bin_file.ReadValue(map_sign_value);
        this->m_cpp_file.WriteTrivialValue(1, label, map_sign_value);
        return;
    }

    if (
        (label == "moveableFlags") 
        && 
        (this->m_config_switches.moveable_flags_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_moveable_flags_labels);

        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_moveable_flags_labels, temp_uint8_array_4, label);
        return;
    }

    if (
        (label == "buildBuildingFlags") 
        && 
        (this->m_config_switches.build_building_flags_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_build_building_flags_labels);

        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_build_building_flags_labels, temp_uint8_array_4, label);
        return;
    }

    if (
        (label == "plugType") 
        && 
        (this->m_config_switches.plug_type_switch == true) 
        && 
        (m_classid == MAGICEQUIPMENT) 
        && 
        (this->m_obj_name.starts_with("RPG_"))
        )
    {
        CheckMaskLabelsAndCorrect(v_s_rpg_plug_type_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_rpg_plug_type_labels, temp_uint8_array_4, label);
        return;
    }

    if (
        (label == "plugType") 
        && 
        (this->m_config_switches.plug_type_switch == true)
        && 
        (this->m_classid == MAGICEQUIPMENT)
        )
    {
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_slot_type_8_labels, temp_uint8_array_4, label);
        return;
    }


    if (
        (label == "plugType") 
        && 
        (this->m_config_switches.plug_type_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_plug_types_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_plug_types_labels, temp_uint8_array_4, label);
        return;
    }


    if (
        (label.starts_with("slotType8"))
        && 
        (this->m_config_switches.slot_type_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_slot_type_8_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_slot_type_8_labels, temp_uint8_array_4, label);
        return;
    }


    if (
        (label.starts_with("slotType"))
        && 
        (this->m_config_switches.slot_type_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_slot_types_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_slot_types_labels, temp_uint8_array_4, label);
        return;
    }

    if (
        (label == "storeableFlags") 
        && 
        (this->m_config_switches.storeable_flags_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_storeable_flags_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_storeable_flags_labels, temp_uint8_array_4, label);
        return;
    }

    if (
        (label == "RPGUnitFlags") 
        && 
        (this->m_config_switches.rpg_unit_flags_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_rpg_unit_flags_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_rpg_unit_flags_labels, temp_uint8_array_4, label);

        return;
    }

    if (
        (label == "artefactMask") 
        && 
        (this->m_config_switches.artefact_mask_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_artefact_mask_labels);
        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_artefact_mask_labels, temp_uint8_array_4, label);

        return;
    }

    if (
        (label == "repairerFlags") 
        && 
        (this->m_config_switches.repairer_flags_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_repairer_flags_labels);

        bin_file.ReadValue(temp_uint8_array_2);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_repairer_flags_labels, temp_uint8_array_2, "first two bytes of " + label);

        bin_file.ReadValue(temp_uint16_val);
        this->m_cpp_file.WriteTrivialValue(1, label, temp_uint16_val);
        this->m_cpp_file << endl;

        return;
    }

    if (
        (label == "bridgeBordersMask") 
        && 
        (this->m_config_switches.bridge_borders_mask_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_bridge_borders_mask_labels);

        bin_file.ReadValue(temp_uint8_array_1);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_bridge_borders_mask_labels, temp_uint8_array_1, label);

        bin_file.ReadValue(temp_uint8_array_3);
        this->m_cpp_file.WriteTrivialArray(1, label, temp_uint8_array_3);
        this->m_cpp_file << endl;

        return;
    }

    if (
        (label == "shadowType") 
        && 
        (this->m_config_switches.shadow_type_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_shadow_type_labels);

        bin_file.ReadValue(temp_uint8_array_3);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_shadow_type_labels, temp_uint8_array_3, label);

        bin_file.ReadValue(temp_uint8_val);
        this->m_cpp_file.WriteTrivialValue(1, label, temp_uint8_val);
        this->m_cpp_file << endl;

        return;
    }

    if (
        (label == "targetType") 
        && 
        (this->m_config_switches.target_type_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_target_type_labels);

        bin_file.ReadValue(temp_uint8_array_1);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_target_type_labels, temp_uint8_array_1, label);

        bin_file.ReadValue(temp_uint8_array_3);
        this->m_cpp_file.WriteTrivialArray(1, label, temp_uint8_array_3);
        this->m_cpp_file << endl;

        return;
    }


    if (
        (label == "lookRoundTypeMask") 
        && 
        (this->m_config_switches.look_round_type_mask_switch == true)
        )
    {
        CheckMaskLabelsAndCorrect(v_s_look_round_type_mask_labels);

        bin_file.ReadValue(temp_uint8_array_4);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_look_round_type_mask_labels, temp_uint8_array_4, label);

        return;
    }


    if (
        (label == "passiveMask") 
        && 
        (this->m_config_switches.passive_mask_switch == true)
        )
    {

        bin_file.ReadValue(temp_uint8_val);
        this->m_cpp_file.WriteNBitMask<uint8_t>
            (
                1, 
                "passiveMask", 
                temp_uint8_val, 
                "first byte of " + label, 
                this->m_hash_maps.m_list_of_passive_masks
            );

        CheckMaskLabelsAndCorrect(v_s_passive_mask_labels);

        bin_file.ReadValue(temp_uint8_array_3);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_passive_mask_labels, temp_uint8_array_3, "rest bytes of " + label);

        return;
    }

    if (
        (label == "panelPos") 
        && 
        (this->m_config_switches.panel_pos_switch == true)
        )
    {
        this->m_cpp_file << endl;
        bin_file.ReadValue(temp_uint16_val);
        this->m_cpp_file.WriteTrivialValue(1, label, temp_uint16_val);

        CheckMaskLabelsAndCorrect(v_s_panel_pos_labels);

        bin_file.ReadValue(temp_uint8_array_1);
        this->m_cpp_file.WriteAll1BitMasks(1, v_s_panel_pos_labels, temp_uint8_array_1, "third byte of " + label);


        bin_file.ReadValue(temp_uint8_val);
        this->m_cpp_file.WriteTrivialValue(1, label, temp_uint8_val);
        this->m_cpp_file << endl;

        return;
    }

    if (label == "magicAnimType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteNBitMask<uint32_t>
            (
                1, 
                "magicAnimType", 
                temp_val, 
                label, 
                this->m_hash_maps.m_list_of_magic_anim_type_masks
            );

        return;
    }

    if (label == "objectType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteNBitMask<uint32_t>
            (
                1, 
                "objectType", 
                temp_val, 
                label, 
                this->m_hash_maps.m_list_of_object_type_masks
            );

        return;
    }

    if (label == "magicType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "magicType", 
                temp_val, 
                this->m_hash_maps.m_list_of_magic_type_masks
            );

        return;
    }

    if (label == "buildingType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "buildingType", 
                temp_val, 
                this->m_hash_maps.m_list_of_building_type_masks
            );

        return;
    }

    if (label == "trapType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "trapType", 
                temp_val, 
                this->m_hash_maps.m_list_of_trap_type_masks
            );

        return;
    }

    if (label == "wasteSize")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "wasteSize", 
                temp_val, 
                this->m_hash_maps.m_list_of_waste_size_masks
            );

        return;
    }

    if (label == "groupTemplateNum")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "groupTemplateNum", 
                temp_val, 
                this->m_hash_maps.m_list_of_group_template_num_masks
            );

        return;
    }

    if (label == "positionType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "positionType", 
                temp_val, 
                this->m_hash_maps.m_list_of_position_type_masks
            );

        return;
    }

    if (label == "explosionFlags")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "explosionFlags", 
                temp_val, 
                this->m_hash_maps.m_list_of_explosion_flags_masks
            );

        return;
    }

    if (label == "raceFlags")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "raceFlags", 
                temp_val, 
                this->m_hash_maps.m_list_of_race_flags_masks
            );

        return;
    }

    if (label == "standType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "standType", 
                temp_val, 
                this->m_hash_maps.m_list_of_stand_type_masks
            );

        return;
    }

    if (label == "experienceExplosionPos")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "experienceExplosionPos", 
                temp_val, 
                this->m_hash_maps.m_list_of_experience_explosion_pos_masks
            );

        return;
    }

    if (label == "equipmentFlags")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "equipmentFlags", 
                temp_val, 
                this->m_hash_maps.m_list_of_equipment_flags_masks
            );

        return;
    }

    if (label == "hitType")
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "hitType", 
                temp_val, 
                this->m_hash_maps.m_list_of_hit_type_masks
            );

        return;
    }

    if ((label == "type") && (m_classid == MISSILE))
    {
        bin_file.ReadValue(temp_val);
        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>
            (
                1, 
                "type",
                temp_val, 
                this->m_hash_maps.m_list_of_missile_type_masks
            );

        return;
    }

    
    bin_file.ReadValue(temp_val);
    this->m_cpp_file.WriteTrivialValue(1, label, temp_val);

}
