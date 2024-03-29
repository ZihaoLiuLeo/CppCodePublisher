#pragma once

#include <string>
#include <iostream>
#include "../CodePublisher/ICodePublisher.h"
#include "../CPWrapper/CPLibWrapper.h"
/////////////////////////////////////////////////////////////////////////
// Translater.h - Translates to/from managed and native types          //
// ver 1.0                                                             //
// Zihao Liu, CSE687 2019                                              //
/////////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
* ---------------------
*  This C++\Cli Package contains one class, Translater.  It's purpose is to convert
*  managed messages, to native messages, Message, and back.
*
*  Required Files:
* -----------------
*  Translater.h, Translater.cpp
*  Required References:
* ----------------------
*  CPLibWrapper.dll
*
*
*/
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace Translator {
	public ref class Shim
	{
	public:
		Shim();
		void publish(List<String^>^ listArgs);
		List<String^>^ getls();
	private:
		CPFactory * pFactory;
		ICodePublisher* pCp;
		std::string mToN(String^ str);
		std::vector<std::string> mToNL(List<String^>^ listArgs);
		String^ nToM(const std::string& str);
		List<String^>^ nToML(const std::vector<std::string>& vecstr);

	};

	Shim::Shim()
	{
		
	}

}
