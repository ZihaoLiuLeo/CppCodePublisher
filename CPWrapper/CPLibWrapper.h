#pragma once
/////////////////////////////////////////////////////////////////////
// CPLibWrapper.h - CodePublisher object factory                   //
// ver 1.0                                                         //
// Zihao Liu, CSE687, 2019                                         //
/////////////////////////////////////////////////////////////////////
/*
*  Provides export and import declarations for CodePublisher
*
*  Required Files:
* -----------------
*  CPLibWrapper.h, CPLibWrapper.cpp
*
*/
#include <string>
#include "../CodePublisher/ICodePublisher.h"

#ifdef IN_DLL
#define DLL_DECL __declspec(dllexport)
#else
#define DLL_DECL __declspec(dllimport)
#endif

extern "C" {
	struct CPFactory {
		static DLL_DECL ICodePublisher* create();
	};
}