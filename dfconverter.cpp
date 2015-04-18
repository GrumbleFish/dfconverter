#include "Core.h"
#include "Console.h"
#include "Export.h"
#include "PluginManager.h"
#include "DataDefs.h"

#include "libanvil/region_file_reader.hpp"

using namespace DFHack;
using namespace df::enums;

DFHACK_PLUGIN("myplugin");

DFhackCExport command_result plugin_shutdown(color_ostream &out){
	return CR_OK;
}

command_result myplugin(color_ostream &out, std::vector <std::string> & parameters){
	try{

		region_file_reader r = region_file_reader("r.-3.0.mca");
		r.read();
		std::vector<int> h = r.get_blocks_at(0,0);
		for (int z=0;z<5;z++){
			for (int i=0;i<16;i++){
				for (int j=0;j<16;j++){
					out.print("%d ",h[256*z+16*i+j]);
				}
				out.print("\n");
			}
		out.print("\n\n");
		}
	}catch(std::runtime_error e){
		out.print("Ow, try again\n");
		return CR_NOT_FOUND;
	}
	return CR_OK;
}

DFhackCExport command_result plugin_init(color_ostream &out, std::vector <PluginCommand> &commands){
	commands.push_back(PluginCommand("myplugin", "Fill in all the adamantine tubes again.", myplugin, false,
		"Screams\n"
		"A lot\n"));
	return CR_OK;
}
