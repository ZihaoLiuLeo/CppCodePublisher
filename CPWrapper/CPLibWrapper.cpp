
//////////////////////////////////////////////////////////////////////
// CPLibWrapper.cpp - CodePublisher object factory                   //
// ver 1.0                                                         //
// Zihao Liu, CSE687, 2019                                         //
/////////////////////////////////////////////////////////////////////
#define IN_DLL

#include "CPLibWrapper.h"
#include "../CodePublisher/CodePublisher.h"

DLL_DECL ICodePublisher* CPFactory::create()
{
	return ICodePublisher::create();
}