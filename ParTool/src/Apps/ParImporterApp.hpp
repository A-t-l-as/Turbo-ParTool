#ifndef PAR_IMPORTER_APP_H
#define PAR_IMPORTER_APP_H

#include "../ParFile/ParFile.hpp"
#include "System/IApp.hpp"

class ParImporterApp : public IApp
{
public:

    ParImporterApp()
    {}

    void Run(int my_argc, char* my_argv[]) override
    {
        const int correct_number_of_args = 3;

        std::filesystem::path input_dir_path;

        if (my_argc == correct_number_of_args)
        {
            input_dir_path = my_argv[2];
            CONSOLE_OUT.PrintLn("DirectoryName = ", input_dir_path);
        }
        else
        {
            CONSOLE_OUT.Print("Enter the name of the input directory:");
            CONSOLE_IN.Scan(input_dir_path);
        }

        if (std::filesystem::is_directory(input_dir_path) == false)
        {
            CONSOLE_OUT.PrintLn("The specified folder does not exist!");
            exit(EXIT_FAILURE);
        }

        bool error_handler = Globals::success_code;

        ParFile my_new_par_file(error_handler);
        my_new_par_file.ParseFrom(input_dir_path);

        if (error_handler == Globals::success_code)
        {
            const std::string ks_par_file_name = input_dir_path.stem().string() + Formats::par_format_str_with_dot;
            my_new_par_file.SaveTo(input_dir_path.parent_path() / ks_par_file_name);
            CONSOLE_OUT.PrintLn("The ", input_dir_path, " directory was compiled successfully...");
        }
        else
        {
            CONSOLE_OUT.PrintLn("An error occurred during compilation ", input_dir_path, ". The compiler has been terminated.");
            exit(EXIT_FAILURE);
        }

    }




};

#endif // !PAR_IMPORTER_APP_H
