// HelloSection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Windows.h"
#include "winnt.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << u8"Hëllö Wörld!" << std::endl;
    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
    PIMAGE_NT_HEADERS32 pNtHeader = (PIMAGE_NT_HEADERS32)((long)pDosHeader + (pDosHeader->e_lfanew));
    PIMAGE_SECTION_HEADER pSectHeaders = (PIMAGE_SECTION_HEADER)((long)pNtHeader + sizeof(IMAGE_NT_HEADERS32));
    for (size_t i = 0; i < pNtHeader->FileHeader.NumberOfSections; i++)
    {
        std::string sectName(reinterpret_cast<const char*>(pSectHeaders[i].Name), 8);
        sectName.append("\x00");
        std::cout << "Section " << i << ": " << sectName << std::endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
