#pragma once
///////////////////////////////////////////////////////////////////////////
// CodePublisher.h : defines facade/executive for OOD Pr1 S19            //
// ver 2.0                                                               //
//                                                                       // 
// Application   : OOD-S19 Instructor Solution                           //
// Platform      : Visual Studio Community 2017, Windows 10 Pro x64      //
// Author        : Ammar Salman, Syracuse University                     //
//                 313/788-4694, assalman@syr.edu                        //
///////////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
* =======================
*  This package defines CodePublisher which uses different components of
*  CodeConverter, Display and DirectoryN to put together the entire 
*  functionality of the CodePublisher. The mentioned packages are indep-
*  ndent of each other and their only interaction is through this facade
*
*  NOTE: there are TWO modes for compiling this file:
*   1) Preprocessor DEMO_CP : runs in full demo mode for Pr1.
*   2) Preprocessor USE_CP  : runs normal functionality. 
*
*  Required Files:
* =======================
*  CodePublisher.h CodePublisher.cpp CodeUtilities.h
*  Converter.h Converter.cpp DirExplorerN.h DirExplorerN.cpp
*  Display.h Display.cpp Logger.h Logger.cpp 
*
*  Maintainence History:
* =======================
*  ver 2.0 - 27 Mar 2019
*  - added file parsing support to extract information
*  - added automated dependency analysis support 
*  - function 'extractFiles' is no longer public, it's replaced with 'configure()'
*  ver 1.0 - 14 Feb 2019
*  - first release
*/

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

