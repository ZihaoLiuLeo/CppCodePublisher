#pragma once
/////////////////////////////////////////////////////////////////////
// ICodePublisher.h - interface for code publish                   //
// ver 1.0                                                         //
// Zihao Liu CSE 687 2019                                          //
/////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>

#include "../Converter/Converter.h"
#include "../Display/Display.h"
#include "../DirExplorer-Naive/DirExplorerN.h"

//#include "../Utilities/CodeUtilities/CodeUtilities.h"

class ICodePublisher
{
public :
	static ICodePublisher* create();
	virtual bool processCommandLineArgs(int argc, char ** argv) = 0;

	virtual void workingDirectory(const std::string& dir) = 0;
	virtual const std::string& workingDirectory() const = 0;

	virtual void outputDirectory(const std::string& dir) = 0;
	virtual const std::string& outputDirectory() const = 0;

	virtual bool configure() = 0;

	virtual void publish() = 0;
	virtual void publish(const std::string& file) = 0;
	virtual void publish(const std::vector<std::string>& files) = 0;

	virtual void storeArgs(std::vector<std::string>& sArgv) = 0;
	virtual std::vector<std::string>& getArg() = 0;

	//virtual Utilities::DisplayMode displayMode() const = 0;
	std::vector<std::string> _sarg;
	CodeConverter cconv_;
	Display display_;

	std::string dirIn_;
	std::string dirOut_;

	std::vector<std::string> files_;

	virtual bool extractFiles() = 0;
	virtual void analyzeFiles() = 0;


	virtual ~ICodePublisher() {}
};
