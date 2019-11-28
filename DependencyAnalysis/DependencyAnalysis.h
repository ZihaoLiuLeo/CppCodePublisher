#pragma once
#include <vector>
#include <string>
#include "../DependencyTable/DependencyTable.h"
#include "IDependencyAnalysis.h"

class DependencyAnalysis : public IDependencyAnalysis
{
public:
  //using FileIncludes = std::unordered_map<std::string, std::vector<std::string>>;

  DependencyAnalysis();
  ~DependencyAnalysis();
  void filelist(const std::vector<std::string>& list);
  void includeList(const FileIncludes& includes);
  void performAnalysis();
  const DependencyTable& analysisResult() const;

private:
  std::vector<std::string> filelist_;
  FileIncludes includeList_;
  DependencyTable dt_;
};

inline IDependencyAnalysis* IDependencyAnalysis::create()
{
	IDependencyAnalysis* pDA = new DependencyAnalysis();
	return pDA;
}

