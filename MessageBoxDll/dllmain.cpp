#include <Windows.h>
#include "pch.h"

void ShowMessageBox()
{
	MessageBoxA(NULL, "Hello World!", "Hello There!", NULL);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH: CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ShowMessageBox, NULL, NULL, NULL);
	case DLL_THREAD_ATTACH: break;
	case DLL_THREAD_DETACH: break;
	case DLL_PROCESS_DETACH: break;
	}
	return TRUE;
}

