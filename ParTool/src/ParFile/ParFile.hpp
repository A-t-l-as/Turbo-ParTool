#ifndef PAR_FILE_H
#define PAR_FILE_H

#include <string>
#include "EndOfPar.hpp"
#include "../ParCompilator/ParDirectoryCompilator.hpp"
#include "ParHeader.hpp"
#include "ParSection.hpp"
#include "Utils/Formats.hpp"
#include "../ParCompilator/ParCompilatorStrings.hpp"
#include "../ParGlobals.hpp"

class ParFile
{
public:
    ParFile(bool& error_handler) :
        m_error_handler(error_handler)
    {}

    ~ParFile()
    {}

    void LoadFrom(const std::filesystem::path& input_path)
    {
        this->m_par_file.LoadFrom(input_path);

        this->m_par_file.Informations();
        this->m_error_handler = !(this->m_par_file.GetIsOpened());
        //this->m_par_file.ExitWhenFileDontExist();
    }

    void ExportTo(const std::filesystem::path& output_path, ConfigSwitches& config_switches) // Create a directory with exported content
    {
        ParExporterHashMaps hash_maps;
        TextFile section_order_file;

        std::filesystem::create_directory(output_path); // folder roboczy

        ParHeader par_header;
        par_header.ReadFrom(this->m_par_file);
        par_header.ExportTo( output_path / ParGlobals::par_header_file_name_str );

        section_order_file << ParCompilatorStrings::par_header_section_name_str << std::endl;

        uint64_t number_of_sections = par_header.GetNumberOfSections();

        for (uint64_t i = 0; i <= number_of_sections; ++i)
        {
            ParSection single_par_section(i, config_switches, hash_maps);
            single_par_section.ReadFrom(this->m_par_file);
            single_par_section.WriteObjNamesListToCppFileStream(this->m_obj_names_list);

            const std::string single_section_name = "section_" + std::to_string(i) + "_" + single_par_section.GetSectionName();
            section_order_file << single_section_name << std::endl;

            const std::string single_section_file_name = single_section_name + Formats::cpp_format_str_with_dot;

            single_par_section.ExportTo(  output_path / single_section_file_name  );
        }

        EndOfPar end_of_par;
        end_of_par.ReadFrom(this->m_par_file);
        end_of_par.ExportTo( output_path / ParGlobals::end_of_par_file_name_str );

        section_order_file << ParCompilatorStrings::end_of_par_section_name_str << std::endl;
        section_order_file.SaveOnlyStringStream(output_path / ParGlobals::section_order_file_name_str);
    }

    inline void SaveObjNamesListTo(const std::filesystem::path& output_path) // Only available after export
	{
		this->m_obj_names_list.SaveToTextFile(output_path);
	}

    void ParseFrom(const std::filesystem::path& input_dir_path)
    {
        this->m_par_file = ParDirectoryCompilator(input_dir_path, m_error_handler).GetOutputFile();
    }

    void SaveTo(const std::filesystem::path& output_file_path)
    {
        if (m_error_handler == Globals::success_code)
        {
            this->m_par_file.SaveTo(output_file_path);
        }
    }

private:
	BinFile m_par_file;

	CppFile m_obj_names_list;

	bool& m_error_handler;
};



#endif // !PAR_FILE_H
