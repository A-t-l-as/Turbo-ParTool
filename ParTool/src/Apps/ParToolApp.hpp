#ifndef PAR_TOOL_APP_HPP
#define PAR_TOOL_APP_HPP

#include "System/HybridApp.hpp"
#include "ParExporterApp.hpp"
#include "ParImporterApp.hpp"

class ParToolApp : public HybridApp
{
public:

    ParToolApp()
    {}

protected:

    void ShowStartScreen() override
    {
        CONSOLE_OUT.PrintLn("******************", Mess::endl,
                            "|ParTool by ATLAS|", Mess::endl,
                            "********2026******");
    }

    void RunExporter(int my_argc, char* my_argv[]) override
    {
        ParExporterApp().Run(my_argc, my_argv);
    }

    void RunImporter(int my_argc, char* my_argv[]) override
    {
        ParImporterApp().Run(my_argc, my_argv);
    }



};



#endif // !PAR_TOOL_APP_HPP
