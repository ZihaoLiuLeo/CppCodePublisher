
#include "Translator.h"

using namespace Translator;

void Shim::publish(List<String^>^ listArgs)
{
	pFactory = new CPFactory;
	pCp = pFactory->create();
	pCp->storeArgs(mToNL(listArgs));
	
	pCp->publish();
	delete pFactory;
}

List<String^>^ Shim::getls()
{
	return nToML(pCp->getArg());
}

std::string Shim::mToN(String^ str)
{
	std::string temp;
	for (int i = 0; i < str->Length; ++i)
		temp += char(str[i]);
	return temp;
}

String^ Shim::nToM(const std::string& str)
{
	StringBuilder^ sb = gcnew StringBuilder();
	for (size_t i = 0; i < str.size(); ++i)
		sb->Append((wchar_t)str[i]);
	return sb->ToString();
}

List<String^>^ Shim::nToML(const std::vector<std::string>& vecstr)
{
	List<String^>^ temp = gcnew List<String^>();
	for (size_t i = 0; i < vecstr.size(); ++i)
		temp->Add(nToM(vecstr[i]));
	return temp;
}

std::vector<std::string> Shim::mToNL(List<String^>^ listArgs)
{
	std::vector<std::string> temp;
	for (int i = 0; i < listArgs->Count; ++i)
		temp.push_back(mToN(listArgs[i]));
	return temp;
}

int main(array<System::String ^> ^args)
{

}