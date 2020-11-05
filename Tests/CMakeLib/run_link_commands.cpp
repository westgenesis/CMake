#include "cmConfigure.h" // IWYU pragma: keep

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../Utilities/cmjsoncpp/include/json/json.h"
#include "cmsys/FStream.hxx"

#include "cmSystemTools.h"


int main()
{
  cmsys::ifstream file("link_commands.json");
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(file, root);
  if (!parsingSuccessful) {
    std::cerr << "Error parsing the file" << std::endl;
  }

  for (auto const& elem : root) {
    const std::string command = elem["command"].asString();
    if (!cmSystemTools::RunSingleCommand(
          command, nullptr, nullptr, nullptr,
          elem["directory"].asString().c_str())) {
      std::cerr << "ERROR: Failed to run command \"" << command << "\""
                << std::endl;
      exit(1);
    }
  }

  return 0;
}
