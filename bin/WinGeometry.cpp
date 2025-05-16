#include <iostream>
#include <string>
#include <windows.h>

int wmain(int argc, wchar_t* argv[]) {
    if (argc < 2) {
        std::wcerr << L"Usage: WinGeometry \"Exact Window Title\"\n";
        return 1;
    }

    // Reconstruct the full title from argv[1…].
    std::wstring windowTitle = argv[1];
    for (int i = 2; i < argc; ++i) {
        windowTitle += L" ";
        windowTitle += argv[i];
    }

    HWND hwnd = FindWindowW(NULL, windowTitle.c_str());
    if (!hwnd) {
        std::wcout << L"NOTFOUND\n";
        return 1;
    }

    RECT rect;
    if (!GetWindowRect(hwnd, &rect)) {
        std::wcout << L"ERROR\n";
        return 1;
    }

    int x = rect.left;
    int y = rect.top;
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    // Print one line, tab‑separated
    std::wcout
        << x << L"\t"
        << y << L"\t"
        << width << L"\t"
        << height << L"\n";
    return 0;
}
