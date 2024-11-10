#include <iostream>
#include <string>
#include "PowerShellExecutor.h"

int main() {
    std::cout << "Enter a PowerShell command to execute: ";
    std::string command;
    std::getline(std::cin, command);

    if (executePowershellCommand(command)) {
        std::cout << "Command executed successfully!" << std::endl;
    }
    else {
        std::cout << "Failed to execute the command." << std::endl;
    }

    return 0;
}
