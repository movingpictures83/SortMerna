#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SortMernaPlugin.h"

void SortMernaPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
 }
 
void SortMernaPlugin::run() {
}

void SortMernaPlugin::output(std::string file) {
std::string command = "sortmerna ";
command += "--ref "+parameters["database"]+" ";
command += "--reads "+parameters["reads"]+" --otu_map True --workdir "+PluginManager::prefix();
command += std::string("; cp ")+std::string(PluginManager::prefix());
command += std::string("/out/aligned_otus.txt ")+std::string(PluginManager::prefix());
 system(command.c_str());
}

PluginProxy<SortMernaPlugin> SortMernaPluginProxy = PluginProxy<SortMernaPlugin>("SortMerna", PluginManager::getInstance());
