#ifndef OBJECT_H
#define OBJECT_H

#include "File/BinFile.hpp"
#include "../../ParCfg/ConfigSwitches.hpp"
#include "../../ParExporterHashMaps.hpp"
#include "../PartOfPar.hpp"

class Object : public PartOfPar
{
public:
    Object(ConfigSwitches& config_switches, ParExporterHashMaps& hash_maps);

	void ReadFrom(BinFile& bin_file);

    std::string GetObjectName() const { return this->m_obj_name; }

private:
	void CheckClassIdAndCorrect(BinFile& bin_file);
	void SelectAndPrintLabelsForClassId(BinFile& bin_file);

	bool CheckIfClassIdIsADefinedMask() const;

    void PrintLabels(BinFile& bin_file, std::vector<std::string>& labels);

    void CheckIfItIsAMaskLabel(BinFile& bin_file, const std::string& label);

    void CheckMaskLabelsAndCorrect(std::vector<std::string>& mask_labels);

	ConfigSwitches& m_config_switches;
    ParExporterHashMaps& m_hash_maps;

	uint32_t m_classid;

	std::string m_obj_name;
	std::string m_logic_table_bits;

};


#endif // !OBJECT_H
