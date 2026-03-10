cmake_minimum_required(VERSION 3.16)

project(ParTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ParTool src/main.cpp
    src/ClassIds/OtherClassIds.hpp src/ClassIds/SortedClassIds.hpp src/ParFile/Object/Object.cpp src/ParFile/Object/Object.hpp src/ParFile/Object/ObjectSelectClassIds.cpp src/ParFile/EndOfPar.hpp src/ParFile/ParFile.hpp src/ParFile/ParHeader.hpp src/ParFile/ParSection.hpp src/ParFile/PartOfPar.hpp src/ParFile/SectionHeader.hpp          src/ParExporterHashMaps.hpp src/ParGlobals.hpp
    src/ParCompilator/ParCompilator.hpp src/ParCompilator/ParCompilatorStrings.hpp src/ParCompilator/ParDirectoryCompilator.hpp
    src/Apps/ParExporterApp.hpp src/Apps/ParImporterApp.hpp src/Apps/ParToolApp.hpp
    src/ParCompilator/ParOrderFile.hpp
    src/ParCfg/CfgFile.cpp src/ParCfg/CfgFile.hpp src/ParCfg/CfgFileUtils.hpp src/ParCfg/ConfigSwitches.hpp
    src/ParCompilator/ParCompilatorHashMaps.hpp
)

target_include_directories(ParTool PRIVATE
    ../KsUtils
    ../KsUtils/src
)

target_link_libraries(ParTool PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../KsUtils/build/Desktop_Qt_6_9_3_MinGW_64_bit-Release/libKsUtils.a
)

include(GNUInstallDirs)
install(TARGETS ParTool
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
