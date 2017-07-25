#include "Defines.h"

typedef struct _ROR13{
	char * cData;
	wchar_t * wData;
	DWORD cHash;
	DWORD wHash;

	_ROR13(const char * data);
	~_ROR13();

}ROR13, *PROR13;

typedef struct _ROR13Lib{
	PROR13 library; // maybe library
	PROR13 flist; //function list
	DWORD dwNumFunctions; // size of the funtion list
	BOOL bwLib;

	_ROR13Lib(const char * library);
	_ROR13Lib(const char * library, PROR13 pFunctionList, DWORD nNumFunctions);
	_ROR13Lib(const char * library, PROR13 pFunctionList, DWORD nNumFunctions, BOOL bWlib);
	~_ROR13Lib();

	void print_library(void);

} ROR13Lib, *PROR13Lib;