#ifndef PAR_DIRECTORY_COMPILATOR_H
#define PAR_DIRECTORY_COMPILATOR_H

#include <filesystem>
#include <string>
#include "ParCompilatorHashMaps.hpp"
#include "Console/Console.hpp"
#include "Utils/Globals.hpp"
#include "Compilator/CompilatorStrings.hpp"
#include "ParOrderFile.hpp"
#include "Utils/Formats.hpp"
#include "File/BinFile.hpp"
#include "ParCompilator.hpp"

class ParDirectoryCompilator
{
public:
    ParDirectoryCompilator(const std::filesystem::path& arg_input_path, bool& arg_error_handler)
    {
        if (std::filesystem::exists(arg_input_path))
        {
            if (std::filesystem::is_directory(arg_input_path) == false)
            {
                CONSOLE_OUT.PrintLn("The specified folder does not exist!");
                arg_error_handler = Globals::error_code;
            }
        }

        if (arg_error_handler == Globals::success_code)
        {
            const std::string order_file_name = "section" + std::string(CompilatorStrings::order_txt_rest);

            ParCompilatorHashMaps par_file_hash_maps;
            par_file_hash_maps.Init();

            bool order_file_error_handler = Globals::success_code;

            ParOrderFile order_file;
            order_file.LoadFrom(arg_input_path / order_file_name, order_file_error_handler);

            if (order_file_error_handler == Globals::success_code)
            {
                const std::vector<std::string>& order_file_names_vec = order_file.GetOrderFileNames();
                const uint64_t number_of_sections = order_file.GetNumberOfSections();

                for (const auto& file_name : order_file_names_vec)
                {
                    const std::string data_sub_file_name = file_name + Formats::cpp_format_str_with_dot;

                    ParCompilator
                    (
                        this->m_output_file,
                        par_file_hash_maps,
                        number_of_sections,
                        arg_error_handler
                    )
                    .CompileFile(arg_input_path / data_sub_file_name);
                }
            }
            else
            {
                arg_error_handler = Globals::error_code;
            }
        }

    }


    inline void SaveCompiledFileTo(const std::filesystem::path& arg_output_file_path)
	{
		this->m_output_file.SaveTo(arg_output_file_path);
	}

    BinFile GetOutputFile() const { return this->m_output_file; }

private:
	BinFile m_output_file;
};

#endif // !PAR_DIRECTORY_COMPILATOR_H
