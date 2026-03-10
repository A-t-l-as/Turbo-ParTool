#ifndef PAR_ORDER_FILE_H
#define PAR_ORDER_FILE_H

#include "File/OrderFileBase.hpp"

class ParOrderFile : public OrderFileBase
{
public:
    ParOrderFile() :
        OrderFileBase(),
        m_number_of_sections(0)
    {}

    uint64_t GetNumberOfSections() const { return this->m_number_of_sections; }

protected:
    void SpecialAction(const std::filesystem::path& arg_path, bool& arg_error_handler) override
    {
        size_t order_file_names_size = m_order_file_names.size();

        if (order_file_names_size >= 3)
        {
            this->m_number_of_sections = order_file_names_size - 3;
        }

        CONSOLE_OUT.PrintLn(m_number_of_sections, " sections were counted.");
    }

private:
	uint64_t m_number_of_sections;

};

#endif // !PAR_ORDER_FILE_H
