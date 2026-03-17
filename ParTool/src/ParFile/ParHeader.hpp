#ifndef PAR_HEADER_H
#define PAR_HEADER_H

#include "Compilator/CompilatorStrings.hpp"
#include "File/BinFile.hpp"
#include "File/CppFile.hpp"
#include <array>
#include <cstdint>
#include "PartOfPar.hpp"
#include "../ParCompilator/ParCompilatorStrings.hpp"

class ParHeader : public PartOfPar
{
public:
    ParHeader() :
        PartOfPar(),
        m_number_of_sections(0)
    {}

    uint64_t GetNumberOfSections() const { return this->m_number_of_sections; }

    void ReadFrom(BinFile& bin_file)
    {
        this->m_cpp_file << CompilatorValueTypes::c_struct_type_str << " ParHeader" << std::endl
                         << '{' << std::endl;


        uint32_t time;
        bin_file.ReadValue(time);
        this->m_cpp_file.WriteTime32(1, "time", time);

        std::string header_string = bin_file.ReadSimpleString();
        uint8_t header_string_len = static_cast<uint8_t>(header_string.length());
        this->m_cpp_file.WriteTrivialValue(1, "header_string_length", header_string_len);

        this->m_cpp_file << '\t'
                         << CompilatorValueTypes::c_char_type_str
                         << " header_string[header_string_length] = \""
                         << header_string
                         << "\";"
                         << std::endl
                         << std::endl;

        //GUID SEPARATOR - start
        uint32_t parameters_version_start;
        bin_file.ReadValue(parameters_version_start);
        this->m_cpp_file.WriteTrivialValue(1, "parameters_version_start", parameters_version_start);
        //----------------

        //GUID - get and write
        std::string guid = bin_file.ReadGuid();
        this->m_cpp_file.WriteGuid(1, "header_guid", guid);
        this->m_cpp_file << std::endl;

        std::array<uint8_t, sizeof(uint32_t)> format = {};
        bin_file.ReadValue(format);

        for (int i = 0; i < format.size(); ++i)
        {
            this->m_cpp_file.WriteTrivialValue(1, "format_" + std::to_string(i), format[i], false);

            if (isalpha(format[i]))
                this->m_cpp_file << " // " << format[i];

            this->m_cpp_file << std::endl;
        }
        //-------------------------------------------------------------------------------------------

        //GUID SEPARATOR - end
        uint32_t parameters_version_end;
        bin_file.ReadValue(parameters_version_end);
        this->m_cpp_file.WriteTrivialValue( 1, "parameters_version_end", parameters_version_end);
        //----------------


        //NUMBER OF SECTIONS
        bin_file.ReadValue(this->m_number_of_sections);
        this->m_cpp_file << std::endl
                         << '\t'
                         << CompilatorValueTypes::c_uint64_t_type_str
                         << ' '
                         << CompilatorStrings::number_of_str
                         << ParCompilatorStrings::sections_str
                         << " = "
                         << CompilatorStrings::count_fn_str
                         << ';'
                         << std::endl
                         << "};";
        //----------------
    }


private:

    uint64_t m_number_of_sections;

};


#endif // !PAR_HEADER_H
