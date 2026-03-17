#ifndef SECTION_HEADER_H
#define SECTION_HEADER_H

#include "File/BinFile.hpp"
#include "File/CppFile.hpp"
#include "PartOfPar.hpp"
#include "../ParCompilator/ParCompilatorStrings.hpp"
#include "Compilator/CompilatorStrings.hpp"

class SectionHeader : public PartOfPar
{
public:

    SectionHeader(size_t& arg_section_id, std::unordered_map<uint32_t, std::string>& arg_list_of_race_masks) :
        PartOfPar(),
        m_id(arg_section_id),
        m_number_of_objects(0),
        m_section_name(std::string()),
        m_list_of_race_masks(arg_list_of_race_masks)
    {}


    uint32_t GetNumberOfObjects() const { return this->m_number_of_objects; }

    std::string GetSectionName() const { return this->m_section_name; }

    void ReadFrom(BinFile& bin_file)
    {
        uint32_t race_unique_key = 0;
        uint32_t flag = 0;

        bin_file.ReadValue(race_unique_key);
        bin_file.ReadValue(flag);
        bin_file.ReadValue(this->m_number_of_objects);

        this->m_section_name = bin_file.ReadString();

        const int64_t binary_string_length = this->m_section_name.length() + sizeof(uint32_t);
        bin_file.MoveOverBy(-binary_string_length);


        this->m_cpp_file << CompilatorValueTypes::c_struct_type_str
                         << " Section_"
                         << this->m_id
                         << '_'
                         << this->m_section_name
                         << "_Header"
                         << std::endl
                         << '{'
                         << std::endl;


        this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>(1, "race", race_unique_key, this->m_list_of_race_masks);
        this->m_cpp_file.WriteTrivialValue(1, "flag", flag);
        this->m_cpp_file << '\t'
                         << CompilatorValueTypes::c_uint32_t_type_str
                         << ' '
                         << CompilatorStrings::number_of_str
                         << ParCompilatorStrings::objects_str
                         << " = "
                         << CompilatorStrings::count_fn_str
                         << ';'
                         << std::endl
                         << "};"
                         << std::endl
                         << std::endl;

    }


private:
    size_t& m_id;

	uint32_t m_number_of_objects;
	std::string m_section_name;

	std::unordered_map<uint32_t, std::string>& m_list_of_race_masks;
};


#endif // !SECTION_HEADER_H
