#include "Object.hpp"
#include "../../ClassIds/SortedClassIds.hpp"
#include "../../ClassIds/OtherClassIds.hpp"

using namespace std;

constexpr uint32_t defined_mask_values[] = 
{ 
    GENERIC, 
    MOVEABLE, 
    SHOPUNIT, 
    RPGUNIT, 
    BUILDER, 
    REPAIRER,
    HARVESTER, 
    CANNON, 
    MISSILE,
    SPECIALEQUIPMENT,
    SPECIALEQUIPMENTEX,
    MAGICEQUIPMENT,
    EQUIPMENTARTEFACT,
    ARTEFACT,
    LOOKROUNDEQUIPMENT,
    LOOKROUNDEQUIPMENTEFFECT,
    EQUIPMENT,
    STOREABLE,
    BUILDING,
    PASSIVE,
    DYNAMIC,
    ACTIVE,
    MINE,
    VISIBLEFAKE,
    ANIMATEDPASSIVE,
    ANIMALPASSIVE, 
    BUILDPASSIVE, 
    GHOSTPASSIVE, 
    TRANSIENTPASSIVE, 
    SPECIALPASSIVE, 
    TRAP, 
    SCRIPTEDACTIVE,
    VERTICALVEHICLE, 
    VERTICALVEHICLESPY, 
    VERTICALVEHICLEBOMBER, 
    EXPLOSION, 
    EXPLOSIONEX, 
    MULTIEXPLOSION, 
    SMOKE, 
    SMOKEFIRE,
    STARTINGPOSITIONMARK, 
    AIPLATOON,
    FLYINGWASTE
};

constexpr std::size_t count_of_defined_mask_values = sizeof(defined_mask_values) / sizeof(defined_mask_values[0]);


Object::Object(ConfigSwitches& config_switches, ParExporterHashMaps& hash_maps) :
    PartOfPar(),
    m_classid(OTHER_CLASS_ID_INVALID),

    m_config_switches(config_switches),
    m_hash_maps(hash_maps),

    m_obj_name(string()),
    m_logic_table_bits(string())
{
}


bool Object::CheckIfClassIdIsADefinedMask() const
{

    for (int i = 0; i < count_of_defined_mask_values; ++i)
        if (m_classid == defined_mask_values[i])
            return true;


    return false;
}

void Object::CheckClassIdAndCorrect(BinFile& bin_file)
{
    this->m_classid = OTHER_CLASS_ID_INVALID;

    if (this->m_logic_table_bits.length() > 0)
    {
        if (m_logic_table_bits[0] == '0')
        {
            bin_file.ReadValue(this->m_classid);
            bin_file.MoveOverBy(- static_cast<int64_t>( sizeof( this->m_classid ) ) );
        }
    }

    if (CheckIfClassIdIsADefinedMask() == true)
    {
        return;
    }


    if (this->m_obj_name.starts_with("TALK_"))
    {
        this->m_classid = OTHER_CLASS_ID_TALK_PACKS;
        return;
    }

    if (
        this->m_obj_name.starts_with("ANIMPARAMS_")
        ||
        this->m_obj_name.starts_with("del_parAMS_")
        ||
        this->m_obj_name.starts_with("OLD_ANIMPARAMS_")
        )
    {
        this->m_classid = OTHER_CLASS_ID_ANIM_PARAMS;
        return;
    }


    if (this->m_obj_name.starts_with("SND_"))
    {
        this->m_classid = OTHER_CLASS_ID_SOUND_PACK;
        return;
    }


    if (this->m_obj_name.starts_with("PASSIVE_ANIMPARAMS_"))
    {
        this->m_classid = OTHER_CLASS_ID_PASSIVE_ANIM_PARAMS;
        return;
    }

    if (
        this->m_obj_name.starts_with("UNITTALKPACKDELAYS")
        ||
        this->m_obj_name.starts_with("BUILDINGTALKPACKDELAYS")
        )
    {
        this->m_classid = OTHER_CLASS_ID_TALK_PACK_DELAYS;
        return;
    }


    if (this->m_obj_name.starts_with("PLAYERTALK_POL"))
    {
        this->m_classid = OTHER_CLASS_ID_PLAYER_TALK_PACK;
        return;
    }

    if (this->m_obj_name.starts_with("PLAYERTALKPACKDELAYS"))
    {
        this->m_classid = OTHER_CLASS_ID_PLAYER_TALK_PACK_DELAYS;
        return;
    }

    if (this->m_obj_name.starts_with("MUSIC_PACK_"))
    {
        this->m_classid = OTHER_CLASS_ID_MUSIC_PACK;
        return;
    }

    if (this->m_obj_name.starts_with("EXPERIENCE_"))
    {
        this->m_classid = OTHER_CLASS_ID_EXPERIENCE_PARAMS;
        return;
    }

    if (
        this->m_obj_name.starts_with("RPG_VIEWPARAMS_")
        ||
        this->m_obj_name.starts_with("VIEWPARAMS_")
        )
    {
        this->m_classid = OTHER_CLASS_ID_MESH_BUTTON_VIEW_PARAMS;
        return;
    }

    if (this->m_obj_name.starts_with("SELECTION_MESHES"))
    {
        this->m_classid = OTHER_CLASS_ID_SELECTION_MESHES;
        return;
    }

    if (
        this->m_obj_name.starts_with("__")
        &&
        this->m_obj_name.ends_with("__")
        )
    {
        this->m_classid = OTHER_CLASS_ID_SPECIAL_UPDATES_LINKS;
        return;
    }


    if (this->m_obj_name.starts_with("RACE_"))
    {
        this->m_classid = OTHER_CLASS_ID_RACE_DATA;
        return;
    }

    if (
        this->m_obj_name.starts_with("RPG_")
        &&
        ((this->m_logic_table_bits.length() + 1) / 2 <= 4)
        )
    {
        this->m_classid = OTHER_CLASS_ID_RPG_PARAMS;
        return;
    }

    if (
        this->m_obj_name.starts_with("RPG_EXPERIENCE")
        &&
        (this->m_classid == SPECIALEQUIPMENT)
        )
    {
        this->m_classid = SPECIALEQUIPMENT;
        return;
    }

    if (
        this->m_obj_name.starts_with("RPG_EXPERIENCE")
        ||
        this->m_obj_name.starts_with("RPG_ENEMY_EXPERIENCE")
        )
    {
        this->m_classid = OTHER_CLASS_ID_RPG_EXPERIENCE;
        return;
    }
}


void Object::ReadFrom(BinFile& bin_file)
{
    this->m_obj_name = bin_file.ReadString();
    uint32_t research_switch = 0;
    bin_file.ReadValue(research_switch);

    this->m_cpp_file
        << CompilatorValueTypes::c_struct_type_str << " " << this->m_obj_name << endl
        << "{" << endl;

    this->m_cpp_file.WriteString(1, "obj_name", this->m_obj_name);
    this->m_cpp_file.WriteTrivialValue(1, "research_switch", research_switch);

    if (research_switch == 1)
    {
        string research_str = bin_file.ReadString();
        this->m_cpp_file.WriteString(1, "research", research_str);
    }
        
    this->m_logic_table_bits = bin_file.ReadLogicTable();
    this->m_cpp_file << '\t'
                     << CompilatorValueTypes::c_bool_type_str
                     << " classID_array[] = {"
                     << this->m_logic_table_bits
                     << "};"
                     << endl;

    this->CheckClassIdAndCorrect(bin_file);

    this->SelectAndPrintLabelsForClassId(bin_file);

    this->m_cpp_file << "};" << endl << endl;
    
}
