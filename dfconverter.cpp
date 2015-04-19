#include "Core.h"
#include "Console.h"
#include "Export.h"
#include "PluginManager.h"
#include "DataDefs.h"

#include "libanvil/region_file_reader.hpp"

using namespace DFHack;
using namespace df::enums;

DFHACK_PLUGIN("dfconverter");

DFhackCExport command_result plugin_shutdown(color_ostream &out){
	return CR_OK;
}

command_result dfconverter(color_ostream &out, std::vector <std::string> & parameters){
	return CR_OK;
}

DFhackCExport command_result plugin_init(color_ostream &out, std::vector <PluginCommand> &commands){
	commands.push_back(PluginCommand("dfconverter", "Converts the current fortress map to a Minecraft map.", dfconverter, false,
		"Currently supports DF 40.24, and MC 1.8.3.\n"
		"Usage/Info\n"));
	return CR_OK;
}
