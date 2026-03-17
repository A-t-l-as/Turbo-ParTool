#ifndef END_OF_PAR_H
#define END_OF_PAR_H

#include <array>
#include "File/CppFile.hpp"
#include "File/BinFile.hpp"
#include "PartOfPar.hpp"

class EndOfPar : public PartOfPar
{
public:
    EndOfPar() : PartOfPar()
    {}

    void ReadFrom(BinFile& bin_file)
    {
        this->m_cpp_file << CompilatorValueTypes::c_struct_type_str << " EndOfPar" << std::endl
                         << '{' << std::endl;

        uint32_t var_field_0 = 0;
        std::array<uint32_t, 5> var_fields = {};
        std::array<std::string, 2> str_fields = {};

        bin_file.ReadValue(var_field_0);
        str_fields[0] = bin_file.ReadString();

        bin_file.ReadValue(var_fields);
        str_fields[1] = bin_file.ReadString();


        this->m_cpp_file.WriteTrivialValue(1, "var_field", var_field_0);
        this->m_cpp_file.WriteString(1, "str_field", str_fields[0]);

        for(int i = 0 ; i < var_fields.size() ; ++i)
            this->m_cpp_file.WriteTrivialValue(1, "var_field_" + std::to_string(i), var_fields[i]);

        this->m_cpp_file.WriteString(1, "str_field", str_fields[1]);

        this->m_cpp_file << "};";

    }

};


#endif // !END_OF_PAR_H
