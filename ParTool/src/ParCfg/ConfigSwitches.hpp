#ifndef CONFIG_SWITCHES_H
#define CONFIG_SWITCHES_H

struct ConfigSwitches
{
	bool moveable_flags_switch = true;
	bool plug_type_switch = true;
	bool slot_type_switch = true;
	bool storeable_flags_switch = true;
	bool rpg_unit_flags_switch = true;
	bool artefact_mask_switch = true;
	bool repairer_flags_switch = true;
	bool bridge_borders_mask_switch = true;
	bool shadow_type_switch = true;
	bool target_type_switch = true;
	bool look_round_type_mask_switch = true;
	bool passive_mask_switch = true;
	bool build_building_flags_switch = true;
	bool panel_pos_switch = true;
};

#endif // !CONFIG_SWITCHES_H