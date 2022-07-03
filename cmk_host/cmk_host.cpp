// cmk_host.cpp : Defines the entry point for the application.
//

#include "cmk_host.h"

#include <windows.h>

#include <cstdint>
#include <filesystem>
#include <string_view>

using CommandFunc = int(__stdcall *)(const char *text, uint32_t);

int main() {
    // Load
    constexpr std::string_view x =
        R"(C:\Users\sk\git\cmk_api\target\debug\cmk_api.dll)";
    HINSTANCE dll = ::LoadLibrary(x.data());

    if (dll == nullptr) {
        std::cout << "could not load the dynamic library" << std::endl;
        return 1;
    }

    // resolve function address here
    auto command =
        reinterpret_cast<CommandFunc>(::GetProcAddress(dll, "command"));
    if (command == nullptr) {
        std::cout << "could not locate the function" << std::endl;
        return 1;
    }
    command("abcde", 5);
    std::cout << "Hello CMake." << std::endl;
    return 0;
}
