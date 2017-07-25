#include "Defines.h"

#include <string>

DWORD __stdcall unicode_ror13_hash(const WCHAR *unicode_string);
DWORD __stdcall ror13_hash(const char *string);

WCHAR * get_wchar(const char * c);

std::string format_define(char * c, bool toUpper);

char tolower(char ch);
char * tolower(char * pString, DWORD dwLength);

WCHAR tolower(WCHAR ch);
WCHAR * tolower(WCHAR * pwString, DWORD dwLength);

DWORD length(char * pString);
DWORD length(WCHAR * pString);