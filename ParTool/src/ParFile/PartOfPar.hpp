#ifndef PART_OF_PAR_HPP
#define PART_OF_PAR_HPP

#include "File/CppFile.hpp"

class PartOfPar
{
public:

    PartOfPar() = default;
    ~PartOfPar() = default;

    inline void WriteToCppFileStream(CppFile& arg_cpp_file)
    {
        arg_cpp_file << this->m_cpp_file.str();
    }

    inline void ExportTo(const std::filesystem::path& arg_output_file_path)
    {
        this->m_cpp_file.SaveToTextFile(arg_output_file_path);
    }

protected:

    CppFile m_cpp_file;

};

#endif // !PART_OF_PAR_HPP
