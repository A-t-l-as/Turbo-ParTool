#ifndef PAR_SECTION_H
#define PAR_SECTION_H

#include "SectionHeader.hpp"
#include "Object/Object.hpp"
#include "PartOfPar.hpp"

class ParSection : public PartOfPar
{
public:

    ParSection(size_t& arg_section_id, ConfigSwitches& config_switches, ParExporterHashMaps& hash_maps) :
        PartOfPar(),
        m_section_id(arg_section_id),
        m_config_switches(config_switches),
        m_hash_maps(hash_maps),
        m_section_name(std::string())
    {}


    std::string GetSectionName() const
    {
        return this->m_section_name;
    }


    void ReadFrom(BinFile& bin_file)
    {
        SectionHeader section_header(m_section_id, m_hash_maps.m_list_of_race_masks);
        section_header.ReadFrom(bin_file);
        section_header.WriteToCppFileStream(this->m_cpp_file);

        this->m_section_name = section_header.GetSectionName();

        uint32_t number_of_objects = section_header.GetNumberOfObjects();

        for (uint32_t i = 0; i < number_of_objects; ++i)
        {
            Object single_object(this->m_config_switches, this->m_hash_maps);
            single_object.ReadFrom(bin_file);
            single_object.WriteToCppFileStream(this->m_cpp_file);

            this->m_obj_names_list << single_object.GetObjectName() << std::endl;
        }

    }


	inline void WriteObjNamesListToCppFileStream(CppFile& arg_cpp_file)
	{
		arg_cpp_file << this->m_obj_names_list.str();
	}

private:
    size_t& m_section_id;

	CppFile m_obj_names_list;

	ConfigSwitches& m_config_switches;
    ParExporterHashMaps& m_hash_maps;
	std::string m_section_name;
};


#endif // !PAR_SECTION_H
