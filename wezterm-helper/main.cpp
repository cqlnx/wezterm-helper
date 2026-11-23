#include <windows.h>

#include <string>

#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

constexpr wchar_t kWezTermGui[] = L"C:\\Program Files\\WezTerm\\wezterm-gui.exe";

std::wstring QuoteArg(const std::wstring& value) {
    size_t trailing = 0;
    while (trailing < value.size() && value[value.size() - 1 - trailing] == L'\\') {
        ++trailing;
    }
    std::wstring quoted = L"\"" + value;
    quoted.append(trailing, L'\\');
    quoted += L'"';
    return quoted;
}

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int) {
    DWORD needed = GetCurrentDirectoryW(0, nullptr);
    if (needed == 0) {
        return 1;
    }
    std::wstring cwd(needed, L'\0');
    DWORD written = GetCurrentDirectoryW(needed, cwd.data());
    if (written == 0 || written >= needed) {
        return 1;
    }
    cwd.resize(written);

    std::wstring commandLine =
        QuoteArg(kWezTermGui) + L" start --cwd " + QuoteArg(cwd);

    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    if (!CreateProcessW(nullptr, commandLine.data(), nullptr, nullptr, FALSE, 0,
        nullptr, nullptr, &startup, &process)) {
        return 1;
    }
    CloseHandle(process.hThread);
    CloseHandle(process.hProcess);
    return 0;
}