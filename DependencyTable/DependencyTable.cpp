#include "DependencyTable.h"
#include "../Logger/Logger.h"
#include <sstream>

using namespace LoggingNew;

// -----< default ctor >---------------------------------------------------
DependencyTable::DependencyTable(){
  LoggerDebug::write("\n  Created instance of DependencyTable using default ctor\n");
}

// -----< files initializer ctor >-----------------------------------------
/* sets the keys for the undordered map */
DependencyTable::DependencyTable(const files & list)
{
  LoggerDebug::write("\n  Created instance of DependencyTable given files list\n");
  table_.reserve(list.size()); // improves performance 
  for (auto file : list)
    table_[file];
}

// -----< dtor - used only for logging >-----------------------------------
DependencyTable::~DependencyTable(){
  LoggerDebug::write("\n  Destroying DependencyTable instance");
}

// -----< has function - searches map for given key >----------------------
bool DependencyTable::has(const std::string & file)
{
  return table_.find(file) != table_.end();
}

// -----< add dependency function - adds filename to key's vector >--------
void DependencyTable::addDependency(file filename, file dependency)
{
  LoggerDebug::write("\n  Adding dependency from " + filename + " to " + dependency);
  // this will create entry if key didnt exists in the map
  DependencyTable::dependencies & deps = table_[filename]; 
  auto dep = std::find(deps.begin(), deps.end(), dependency);
  if (dep == deps.end()) // don't add depndency if it already exists
    deps.push_back(dependency);
}

// -----< remove dependency function >-------------------------------------
void DependencyTable::removeDependency(file filename, file dependency)
{
  LoggerDebug::write("\n  Removing dependency from " + filename + " to " + dependency);
  DependencyTable::dependencies & deps = table_[filename];
  auto dep = std::find(deps.begin(), deps.end(), dependency);
  if (dep != deps.end())
    deps.erase(dep);
}

// -----< remove entry - removes key/value pair from map >-----------------
void DependencyTable::removeEntry(file filename)
{
  LoggerDebug::write("\n  Removing entry [" + filename + "] from dependency table");
  auto entry = table_.find(filename);
  if (entry != table_.end())
    table_.erase(entry);
}

// -----< get key's dependencies >-----------------------------------------
const DependencyTable::dependencies & DependencyTable::getDependencies(file filename) const
{
  return table_.at(filename);
}

// -----< operator [] to provide easier access >---------------------------
const DependencyTable::dependencies & DependencyTable::operator[](const file & filename) const
{
  return table_.at(filename);
}

// -----< begin() iterator - allows for loop >-----------------------------
DependencyTable::iterator DependencyTable::begin()
{
  return table_.begin();
}

// -----< end() iterator - allows for loop >-------------------------------
DependencyTable::iterator DependencyTable::end()
{
  return table_.end();
}

// -----< get keys of map >------------------------------------------------
DependencyTable::files DependencyTable::getFiles() const
{
  files list;
  for (auto entry : table_)
    list.push_back(entry.first);
  return list;
}

// -----< display entire table in formatted way >--------------------------
void DependencyTable::display() const
{
  std::ostringstream out; 
  out << "\n  Dependency table:";
  for (auto entry : table_) {
    out << "\n  -- " << entry.first;
    for (auto dep : entry.second)
      out << "\n   -> " << dep;
  }
  LoggerDebug::write(out.str());
  LoggerDemo::write(out.str());
}


#ifdef TEST_DEBTABLE

#include <iostream>

// ----< test stub for dependency table package >---------------------------
int main(int argc, char ** argv) {
  LoggerDebug::attach(&std::cout);
  LoggerDebug::start();

  LoggerDebug::title("Testing DependencyTable Operations");

  DependencyTable dt;
  dt.addDependency("A.h", "B.h");
  dt.addDependency("A.h", "C.h");
  dt.addDependency("C.h", "B.h");
  dt.addDependency("D.h", "B.h");
  dt.addDependency("E.h", "A.h");
  dt.addDependency("B.h", "E.h");
  dt.addDependency("C.h", "E.h");
  dt.addDependency("E.h", "E.h");
  dt.removeDependency("E.h", "E.h");

  dt.display();

  LoggerDebug::stop();

  return 0;

}

#endif