#include "PowerShellExecutor.h"
#include <iostream>
#include <windows.h>
#include <string>

bool executePowershellCommand(const std::string& command) {
    std::wstring psCommand = L"powershell.exe -NoProfile -ExecutionPolicy Bypass -Command " + std::wstring(command.begin(), command.end());

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    si.cb = sizeof(si);

    if (!CreateProcess(
        NULL,               
        &psCommand[0],      
        NULL,               
        NULL,               
        FALSE,              
        CREATE_NO_WINDOW,   
        NULL,              
        NULL,               
        &si,               
        &pi                 
    )) {
        std::cerr << "CreateProcess failed (" << GetLastError() << ")" << std::endl;
        return false;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return true;
}
