#include "File/TextFile.hpp"
#include "CfgFile.hpp"
#include "Console/Console.hpp"
#include <fstream>
#include "Utils/StringUtils.hpp"

using namespace std;

namespace fs = filesystem;


CfgFile::CfgFile(const fs::path& input_path)
{
   
    if (!fs::exists(input_path))
    {
        fstream new_cfg_file;
        
        CONSOLE_OUT.PrintLn(input_path.filename(), " file does not exist so I created a new one...");

        new_cfg_file.open(input_path, ios::out);
        new_cfg_file << CfgFileUtils::text_of_cfg_file << endl;
        new_cfg_file.close();
    }

    TextFile cfg_file;
    cfg_file.LoadFrom(input_path);

    cfg_file.Informations();
    cfg_file.ExitWhenFileDontExist();

    if (cfg_file.Empty() == false)
    {
        cfg_file.DeleteComments();

        cfg_file.CleanCppFileBufferFromContrChars();
        //cfg_file.DeleteContrCharAndPutToCleanFileVector();

        InitializeHashMap();

        GetInfoFromCfg(cfg_file.GetCleanFileBuffer());
    }
    
}

void CfgFile::InitializeHashMap()
{
    for (size_t i = 0; i < CfgFileUtils::number_of_false_and_true_config_values_str; ++i)
    {
        this->m_config_values_hash_map[ CfgFileUtils::true_config_values_str [i] ] = true;
        this->m_config_values_hash_map[ CfgFileUtils::false_config_values_str[i] ] = false;
    }

    for (size_t i = 0; i < CfgFileUtils::number_of_value_types; ++i)
        m_config_en_value_types_hash_map[CfgFileUtils::value_types[i]] = static_cast<CfgFileUtils::EnCfgValueTypes>(i);

}


void CfgFile::GetInfoFromCfg(const vector<char>& arg_clean_file)
{
    CONSOLE_OUT.PrintLn(Mess::endl,
                        "PARex.cfg:", Mess::endl,
                        "##########", Mess::endl,
                        "1bitmasks:");

    string_view file_view(arg_clean_file.data(), arg_clean_file.size());

    string ins_value_type;
    string ins_value;

    size_t start = 0;
    while (true)
    {
        size_t end = file_view.find(';', start);

        if (end == string_view::npos)
            break;

        string instruction(file_view.substr(start, end - start + 1));

        DEBUG_PRINT("----", Mess::endl, instruction, Mess::endl);

        GetValuesFromString(instruction, ins_value_type, ins_value);
        InitializeSwitches(ins_value_type, ins_value);

        DEBUG_PRINT(ins_value_type, Mess::endl, ins_value, Mess::endl, "----", Mess::endl);

        // Reset wartosci
        ins_value_type.clear();
        ins_value.clear();

        start = end + 1;
    }
}

void CfgFile::GetValuesFromString(const string& arg_instruction, string& arg_ins_value_type, string& arg_ins_value)
{
    while (true)
    {
        bool nopswitch = true;

        //Sprawdzenie czy jest prawidlowy typ
        for (uint32_t i = 0; i < CfgFileUtils::number_of_value_types; ++i)
        {
            if (arg_instruction.starts_with(CfgFileUtils::value_types[i]) )
            {
                arg_ins_value_type = CfgFileUtils::value_types[i];
                nopswitch = false;
                break;
            }
        }

        // Jesli typ byl nieprawidlowy czyli nopswitch == true to wychodze
        if (nopswitch == true)
        {
            arg_ins_value_type = string();
            arg_ins_value = string();
            return;
        }

        //Wyodrebnienie wartosci od instrukcji
        uint64_t valueindex = arg_instruction.find("=") + 1;
        arg_ins_value = arg_instruction.substr(valueindex, arg_instruction.length() - valueindex - 1);

        StringUtils::ToUpper(arg_ins_value);

        break;
    }

}

void CfgFile::PrintSwitchInfo(const string& value_type, bool value)
{
    CONSOLE_OUT.PrintLn(value_type, " = ", value);
}

void CfgFile::InitializeSwitches(const string& value_type, const string& value)
{
    CfgFileUtils::EnCfgValueTypes arg_en_value_type = this->m_config_en_value_types_hash_map[value_type];
    bool boolean_value_from_str = this->m_config_values_hash_map[value];

    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_invalid)
        return;

    // moveableFlags
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_moveableFlags)
    {
        this->m_config_switches.moveable_flags_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type,this->m_config_switches.moveable_flags_switch);

        return;
    }

    // plugType
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_plugType)
    {
        this->m_config_switches.plug_type_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.plug_type_switch);

        return;
    }

    // slotType
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_slotType)
    {
        this->m_config_switches.slot_type_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.slot_type_switch);

        return;
    }

    // storeableFlags
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_storeableFlags)
    {
        this->m_config_switches.storeable_flags_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.storeable_flags_switch);

        return;
    }

    // RPGUnitFlags
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_RPGUnitFlags)
    {
        this->m_config_switches.rpg_unit_flags_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.rpg_unit_flags_switch);

        return;
    }

    // artefactMask
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_artefactMask)
    {
        this->m_config_switches.artefact_mask_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.artefact_mask_switch);

        return;
    }

    // repairerFlags
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_repairerFlags)
    {
        this->m_config_switches.repairer_flags_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.repairer_flags_switch);

        return;
    }

    // bridgeBordersMask
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_bridgeBordersMask)
    {
        this->m_config_switches.bridge_borders_mask_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.bridge_borders_mask_switch);

        return;
    }

    // shadowType
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_shadowType)
    {
        this->m_config_switches.shadow_type_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.shadow_type_switch);

        return;
    }

    // targetType
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_targetType)
    {
        this->m_config_switches.target_type_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.target_type_switch);

        return;
    }

    // lookRoundTypeMask
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_lookRoundTypeMask)
    {
        this->m_config_switches.look_round_type_mask_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.look_round_type_mask_switch);

        return;
    }

    // passiveMask
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_passiveMask)
    {
        this->m_config_switches.passive_mask_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.passive_mask_switch);

        return;
    }

    // buildBuildingFlags
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_buildBuildingFlags)
    {
        this->m_config_switches.build_building_flags_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.build_building_flags_switch);

        return;
    }

    // panelPos
    if (arg_en_value_type == CfgFileUtils::EnCfgValueTypes::e_panelPos)
    {
        this->m_config_switches.panel_pos_switch = boolean_value_from_str;

        PrintSwitchInfo(value_type, this->m_config_switches.panel_pos_switch);

        return;
    }

}
