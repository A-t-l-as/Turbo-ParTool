#ifndef CFG_FILE_UTILS_H
#define CFG_FILE_UTILS_H

#include <cstddef>
namespace CfgFileUtils
{
    enum en_cfg_value_types
    {
        e_moveableFlags,
        e_plugType,
        e_slotType,
        e_storeableFlags,
        e_RPGUnitFlags,
        e_artefactMask,
        e_repairerFlags,
        e_bridgeBordersMask,
        e_shadowType,
        e_targetType,
        e_lookRoundTypeMask,
        e_passiveMask,
        e_buildBuildingFlags,
        e_panelPos,
        e_invalid
    };

    constexpr char text_of_cfg_file[] =
        "//1bitmasks:\nmoveableFlags = YES;\nplugType = YES;\nslotType = YES;\nstoreableFlags = YES;\nRPGUnitFlags = YES;\nartefactMask = YES;\nrepairerFlags = YES;\nbridgeBordersMask = YES;\nshadowType = YES;\ntargetType = YES;\nlookRoundTypeMask = YES;\npassiveMask = YES;\nbuildBuildingFlags = YES;\npanelPos = YES;";

    constexpr size_t number_of_value_types = 15;
    static const char* value_types[] = {
        "moveableFlags",
        "plugType",
        "slotType",
        "storeableFlags",
        "RPGUnitFlags",
        "artefactMask",
        "repairerFlags",
        "bridgeBordersMask",
        "shadowType",
        "targetType",
        "lookRoundTypeMask",
        "passiveMask",
        "buildBuildingFlags",
        "panelPos",
        ""
    };

    constexpr std::size_t number_of_false_and_true_config_values_str = 3;
    static const char* true_config_values_str[] =
    {
        "1",
        "YES",
        "TRUE"
    };

    static const char* false_config_values_str[] =
    {
        "0",
        "NO",
        "FALSE"
    };

};


#endif // !CFG_FILE_UTILS_H
