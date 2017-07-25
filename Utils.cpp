#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "Utils.h"

DWORD __stdcall unicode_ror13_hash(const WCHAR *unicode_string)
{
	DWORD hash = 0;

	while (*unicode_string != 0)
	{
		DWORD val = (DWORD)*unicode_string++;
		hash = (hash >> 13) | (hash << 19); // ROR 13
		hash += val;
	}
	return hash;
}

DWORD __stdcall ror13_hash(const char *string)
{
	DWORD hash = 0;

	while (*string) {
		DWORD val = (DWORD)*string++;
		hash = (hash >> 13) | (hash << 19);  // ROR 13
		hash += val;
	}
	return hash;
}

WCHAR * get_wchar(const char * c)
{
	const size_t cSize = strlen(c) + 1;

	WCHAR * wc = new WCHAR[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

std::string format_define(char * cInput, bool toUpper)
{
	const size_t cSize = strlen(cInput) + 1; // add 1 for null char
	CHAR * cDefine = new CHAR[cSize];

	strncpy(cDefine, cInput, cSize - 1);
	cDefine[cSize - 1] = '\0';

	for (int k = 0; k < strlen(cDefine); k++)
	{
		if (cDefine[k] == '.'){
			cDefine[k] = '_';
		}
		else{
			cDefine[k] = (toUpper) ? toupper(cDefine[k]) : cDefine[k];
		}
	}

	std::string ret = std::string(cDefine);

	delete[] cDefine;

	return ret;
}

char tolower(char ch)
{
	if (ch >= 65 && ch <= 90)
	{
		return ch | 0x20;
	}

	return ch;
}

char * tolower(char * pString, DWORD dwLength)
{
	for (int k = 0; k < dwLength; k++)
	{
		pString[k] = tolower(pString[k]);
	}

	return pString;
}

WCHAR tolower(WCHAR ch)
{
	if ((ch >> 8) == 0) // High end byte is 0
	{
		// Let's convert the low end byte to lower like an ASCII char
		// Since high end byte is 0, we can just return this value as a WCHAR
		return (WCHAR)tolower((char)(ch & 0xFF));
	}

	return ch; // Not in our ascii character set (don't care)
}

WCHAR * tolower(WCHAR * pwString, DWORD dwLength)
{
	for (int k = 0; k < dwLength; k++)
	{
		pwString[k] = tolower(pwString[k]);
	}

	return pwString;
}


DWORD length(char * pString)
{
	DWORD count = 0;
	char * iter = pString;

	for (; *iter != NULL; iter++){
		count++;
	}

	return count;
}

DWORD length(WCHAR * pwString)
{
	DWORD count = 0;
	WCHAR * iter = pwString;

	for (; *iter != NULL; iter++){
		count++;
	}

	return count;
}