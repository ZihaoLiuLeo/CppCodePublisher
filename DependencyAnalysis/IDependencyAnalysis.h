#include "../DependencyTable/DependencyTable.h"

class IDependencyAnalysis
{
public:
	using FileIncludes = std::unordered_map<std::string, std::vector<std::string>>;
	static IDependencyAnalysis* create();

	virtual void filelist(const std::vector<std::string>& list) = 0;
	virtual void includeList(const FileIncludes& includes) = 0;
	virtual void performAnalysis() = 0;
	virtual const DependencyTable& analysisResult() const = 0;
	virtual ~IDependencyAnalysis() {}
};