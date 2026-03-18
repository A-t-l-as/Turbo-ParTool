#ifndef PAR_EXPORTER_APP_H
#define PAR_EXPORTER_APP_H

#include <filesystem>
#include "../ParCfg/CfgFile.hpp"
#include "../ParCfg/ConfigSwitches.hpp"
#include "../ParFile/ParFile.hpp"
#include "System/IApp.hpp"
#include "Utils/Globals.hpp"
#include "Console/Console.hpp"

class ParExporterApp : public IApp
{
public:
    ParExporterApp()
    {}

    ~ParExporterApp()
    {}

    int Run(int my_argc, char* my_argv[]) override
    {
        const unsigned int correct_number_of_args = 3;

        std::filesystem::path input_par_file_path;

        bool error_handler = Globals::success_code;

        const char par_ex_cfg_file_name[] = "PARex.cfg";
        const char par_ex_data_dir_name[] = "PARex_DATA";
        const char editor_names_txt_file_name[] = "EditorNames.txt";

        if (my_argc == correct_number_of_args)
        {
            input_par_file_path = my_argv[2];

            CONSOLE_OUT.PrintLn("Input file = ", input_par_file_path);
        }
        else
        {
            CONSOLE_OUT.PrintLn("Enter the path to the input .par file, including the extension:");
            CONSOLE_IN.Scan(input_par_file_path);
        }

        if (!std::filesystem::exists(input_par_file_path))
        {
            CONSOLE_OUT.PrintLn("Error: The specified ", input_par_file_path, " file does not exist.");
            exit(EXIT_FAILURE);
        }

        if (input_par_file_path.extension().string() != Formats::par_format_str_with_dot )
        {
            CONSOLE_OUT.PrintLn("The specified file is not a .par file. The program terminates with an error.");
            exit(EXIT_FAILURE);
        }

        CfgFile par_ex_cfg_file( std::filesystem::current_path() / par_ex_cfg_file_name );
        ConfigSwitches config_switches = par_ex_cfg_file.GetConfigSwitches();

        ParFile my_ks_par(error_handler);
        my_ks_par.LoadFrom(input_par_file_path);

        if (error_handler == Globals::error_code)
        {
            CONSOLE_OUT.PrintLn("Error: Failed to open ", input_par_file_path, " file.");
            exit(EXIT_FAILURE);
        }
        my_ks_par.ExportTo( input_par_file_path.parent_path() / input_par_file_path.stem(), config_switches);


        const std::filesystem::path par_ex_data_directory_path = std::filesystem::current_path() / par_ex_data_dir_name;
        std::filesystem::create_directory(par_ex_data_directory_path);

        my_ks_par.SaveObjNamesListTo(  par_ex_data_directory_path / editor_names_txt_file_name  );


        CONSOLE_OUT.PrintLn("Decompilation of file ", input_par_file_path, " completed successfully!");

        return EXIT_SUCCESS;
    }



};


#endif // !PAR_EXPORTER_APP_H
