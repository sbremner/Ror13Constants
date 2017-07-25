#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "Defines.h"
#include "Ror13.h"
#include "Utils.h"

#define FORMAT_MESSAGE(msg, b) \
	format_define(msg, b).c_str()


ROR13::_ROR13(const char * data)
{
	const size_t cSize = strlen(data) + 1;
	this->cData = new char[cSize];
	strncpy(this->cData, data, cSize - 1);
	this->cData[cSize - 1] = '\0';

	this->wData = get_wchar(data);	

	this->cHash = ror13_hash(tolower(this->cData, length(this->cData)));
	this->wHash = unicode_ror13_hash(tolower(this->wData, length(this->cData)));
}

ROR13::~_ROR13()
{
	delete[] this->cData;
	delete[] this->wData;
}

ROR13Lib::_ROR13Lib(const char * library)
{
	this->library = new ROR13(library);
	this->flist = NULL;
	this->dwNumFunctions = 0;
	this->bwLib = FALSE;
}

ROR13Lib::_ROR13Lib(const char * library, PROR13 pFunctionList, DWORD nNumFunctions)
{
	this->library = new ROR13(library);
	this->flist = (PROR13)malloc(sizeof(ROR13) * nNumFunctions);
	this->bwLib = FALSE;

	for (int k = 0; k < nNumFunctions; k++)
	{
		try{
			this->flist[k] = pFunctionList[k];
		}
		catch (...){
			nNumFunctions = k; // if we error our, we can use this k value to set number of functions
			break;
		}
	}

	this->dwNumFunctions = nNumFunctions;

	if (this->dwNumFunctions == 0 && this->flist != NULL){
		free(this->flist); // don't maintain the memory if we aren't using it
		this->flist = NULL;
	}
}

ROR13Lib::_ROR13Lib(const char * library, PROR13 pFunctionList, DWORD nNumFunctions, BOOL bwLib)
{
	this->library = new ROR13(library);
	this->flist = (PROR13)malloc(sizeof(ROR13) * nNumFunctions);
	this->bwLib = bwLib;

	for (int k = 0; k < nNumFunctions; k++)
	{
		try{
			this->flist[k] = pFunctionList[k];
		}
		catch (...){
			nNumFunctions = k; // if we error our, we can use this k value to set number of functions
			break;
		}
	}

	this->dwNumFunctions = nNumFunctions;

	if (this->dwNumFunctions == 0 && this->flist != NULL){
		free(this->flist); // don't maintain the memory if we aren't using it
		this->flist = NULL;
	}
}

ROR13Lib::~_ROR13Lib()
{
	if (this->library != NULL){
		delete this->library;	// delete since allocated with new
	}

	if (this->flist != NULL){
		free(this->flist);		// free since allocated with malloc
	}
}

void ROR13Lib::print_library(void)
{
	CHAR data[MAX_PATH];

	// Print a comment letting the user know what library is here
	printf("// ***** %s (%d functions) ***** //\n", this->library->cData, this->dwNumFunctions);
	
	// Print a define for the module as a char array (not a string)

	printf("#define\t%s_STR\t", FORMAT_MESSAGE(this->library->cData, true));

	printf("\t{ ");
	for (int i = 0; i < strlen(this->library->cData); i++)
	{
		printf("'%c', ", this->library->cData[i]);
	}
	printf("'\\0' }\n");

	// Print the has of the module
	printf("#define\t%-35s\t0x%X\n", FORMAT_MESSAGE(this->library->cData, true), (this->bwLib) ? this->library->wHash : this->library->cHash);

	for (int k = 0; k < this->dwNumFunctions; k++)
	{
		printf("#define\t%s_%-20s\t0x%X\n",
			FORMAT_MESSAGE(this->library->cData, true), FORMAT_MESSAGE(this->flist[k].cData, false), this->flist[k].wHash
		);
	}
}