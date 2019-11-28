#pragma once

#include <string>
#include <vector>
#include "ICodePublisher.h"

#include "../Utilities/CodeUtilities/CodeUtilities.h"

class CodePublisher : public ICodePublisher
{
public:
  CodePublisher();

  bool processCommandLineArgs(int argc, char ** argv);
  
  void workingDirectory(const std::string& dir);
  const std::string& workingDirectory() const;

  void outputDirectory(const std::string& dir);
  const std::string& outputDirectory() const; 

  bool configure();

  void publish();
  void publish(const std::string& file);
  void publish(const std::vector<std::string>& files);

  void storeArgs(std::vector<std::string>& sArgv);

  std::vector<std::string>& getArg();

  Utilities::DisplayMode displayMode() const;

  

private:
  Utilities::ProcessCmdLine *pcl_;
  bool extractFiles();
  void analyzeFiles();
  /*CodeConverter cconv_;
  Display display_;

  std::string dirIn_; 
  std::string dirOut_;

  std::vector<std::string> files_;

  */

  //std::vector<std::string> _sarg;

};

inline ICodePublisher* ICodePublisher::create()
{
	ICodePublisher* pCP = new CodePublisher();
	return pCP;
}

