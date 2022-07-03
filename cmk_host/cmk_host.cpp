// cmk_host.cpp : Defines the entry point for the application.
//

#include "cmk_host.h"

#include <windows.h>

#include <cstdint>
#include <filesystem>
#include <string_view>

using CommandFunc = int(__stdcall *)(const char *text, uint32_t len);

int main() {
    constexpr std::string_view x =
        R"(C:\Users\sk\git\cmk_api\target\debug\cmk_api.dll)";
    auto *dll = reinterpret_cast<HINSTANCE>(::LoadLibraryA(x.data()));

    if (dll == nullptr) {
        std::cout << "could not load the dynamic library" << std::endl;
        return 1;
    }

    auto command =
        reinterpret_cast<CommandFunc>(::GetProcAddress(dll, "command"));
    if (command == nullptr) {
        std::cout << "could not locate the function" << std::endl;
        return 1;
    }
    constexpr std::string_view cmd{"From C++"};
    command(cmd.data(), static_cast<uint32_t>(cmd.size()));
    return 0;
}
