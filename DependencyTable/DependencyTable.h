#pragma once
#include <unordered_map>
#include <string>
#include <vector>

class DependencyTable
{
public:
  using file = std::string;
  using files = std::vector<file>;
  using dependencies = std::vector<file>;
  using iterator = std::unordered_map<file, dependencies>::iterator;


  DependencyTable();
  DependencyTable(const files& list);
  ~DependencyTable();

  bool has(const std::string& file);

  void addDependency(file filename, file dependency);
  void removeDependency(file filename, file dependency);

  void removeEntry(file filename);

  const dependencies& getDependencies(file filename) const;
  const dependencies& operator[](const file& filename) const;

  // these two functions allow 'for' loops in the form of
  // for(auto entry : dt) {...}
  iterator begin();
  iterator end();
  void clear() { table_.clear(); }

  files getFiles() const;

  void display() const;

private:
  std::unordered_map<file, dependencies> table_;
};

