#ifndef PAR_COMPILATOR_H
#define PAR_COMPILATOR_H

#include "Compilator/CompilatorBase.hpp"
#include "Compilator/CompilatorStrings.hpp"
#include "File/TextFile.hpp"
#include "ParCompilatorStrings.hpp"

class ParCompilator : public CompilatorBase
{
public:							
    ParCompilator(
                    BinFile& arg_output_file_buffer,
                    HashMapsBase& arg_hash_maps,
                    uint64_t arg_number_of_sections,
                    bool& arg_error_handler
                ) :

        CompilatorBase(arg_output_file_buffer, arg_hash_maps, arg_error_handler),

		m_number_of_sections(arg_number_of_sections),
		m_number_of_obj_in_section(0),

        m_special_function_lock(false)
	{}
	
	void CompileFile(const std::filesystem::path& arg_input_path) override
	{
        TextFile input_file;
        input_file.LoadFrom(arg_input_path);

		input_file.Informations();
		//input_file.ExitWhenFileDontExist();
        this->r_error_handler = !(input_file.GetIsOpened());
	
        if ((input_file.Empty() == false) && (this->r_error_handler == Globals::success_code))
		{
			input_file.DeleteComments();

			this->m_number_of_obj_in_section = input_file.CountOccurrencesOfText("struct ") - 1;

            input_file.CleanCppFileBufferFromContrChars();

			CompileCppFileToBin(input_file.GetCleanFileBuffer());
		}
	}


private:
    uint64_t m_number_of_sections;
	bool m_special_function_lock;
	size_t m_number_of_obj_in_section;

protected:

    bool TryResolveSpecialValue
    (
        std::string& arg_instruction,
        std::string& arg_value_type,
        Enums::value_types_enum& arg_en_value_type,
        std::string& arg_name,
        std::string& arg_value
    )
    override
    {
        // This part is performed once per file.
        if (!this->m_special_function_lock)
        {
            if (arg_value == CompilatorStrings::count_fn_str && arg_name.starts_with( CompilatorStrings::number_of_str ))
            {
                // Number of objs
                if (arg_name.ends_with( ParCompilatorStrings::objects_str ))
                {
                    this->m_special_function_lock = true; // <- lock special functions
                    arg_value = std::to_string(this->m_number_of_obj_in_section);
                    return true;
                }

                // Number of sections
                if (arg_name.ends_with( ParCompilatorStrings::sections_str ))
                {
                    this->m_special_function_lock = true; // <- lock special functions
                    arg_value = std::to_string(this->m_number_of_sections);
                    return true;
                }
            }
        }

        return false;
    }


};



#endif // !PAR_COMPILATOR_H
