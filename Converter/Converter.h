#pragma once

#include "../DependencyTable/DependencyTable.h"
#include "../FileProcessor/FileProcessor.h"
#include <vector>
#include <string>
#include <sstream>

class CodeConverter
{
public:
	using LineInfo = FileProcessor::LineInfo;
	using FileLineInfo = FileProcessor::FileLineInfo;

	CodeConverter();
	CodeConverter(const DependencyTable& dt);

	const std::string& outputDir() const;
	void outputDir(const std::string& dir);
	bool createOutpurDir();

	void setDepTable(const DependencyTable& dt);
	void setFileLineInfo(const FileLineInfo& info);

	std::vector<std::string> convert();
	std::string convert(const std::string& filepath);
	std::vector<std::string> convert(const std::vector<std::string>& files);

	const std::vector<std::string> convertedFiles() const;

	void clear();

private:
	bool convertFile(std::string file);
	void addPreCodeHTML(const std::string& title);
	void addPreTag();
	void addDependencyLinks(std::string file);
	void addClosingTags();

	void skipSpecialChars(std::string& line);
	void handleSLComment(std::string& line);
	void handleMLComment(std::string& line);
	void handleScopeInfo(std::string filepath, size_t lineCount, std::string& line);

private:
	DependencyTable dt_;
	std::string outputDir_ = "..\\ConvertedWebpages\\";
	std::vector<std::string> convertedFiles_;
	std::stringstream out_;

	FileLineInfo fileLineInfo_;
};
