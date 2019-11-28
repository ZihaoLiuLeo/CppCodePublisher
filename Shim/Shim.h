#pragma once

#include <string>
#include "../CodePublisher/ICodePublisher.h"
#include "../CPWrapper/CPLibWrapper.h"

using namespace System;
using namespace System::Text;
//using namespace Utilities;

public ref class Shim
{
public:
	Shim();
	void publish();
private:
	CPFactory* pFactory;
	ICodePublisher* pCp;
};

Shim::Shim()
{

}

inline void Shim::publish()
{
	pFactory = new CPFactory;
	pCp = pFactory->create();
	
	//pCp->processCommandLineArgs();
	//pCp->publish();
	delete pFactory;
}