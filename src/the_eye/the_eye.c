// ============================================================================
// MODULE : eye (The Eye — Filesystem Surveillance Engine)
// FILE   : the_eye.c
// PURPOSE: Watches a directory for file system changes using Win32 API
// ============================================================================

#include "the_eye.h"

#include <windows.h>

void eye_dir_open(const wchar_t *eye_szDirectoryPath) {
    const HANDLE eye_hDirectory = CreateFileW(
        eye_szDirectoryPath,
        FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS,
        NULL
    );

    if (eye_hDirectory == INVALID_HANDLE_VALUE) {
        const DWORD eye_dwError = GetLastError();
        LPWSTR eye_szMsgBuf = NULL;

        FormatMessageW(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, eye_dwError, 0,
            (LPWSTR) &eye_szMsgBuf, 0, NULL);

        wprintf(L"Error %lu: %s\n", eye_dwError, eye_szMsgBuf);

        LocalFree(eye_szMsgBuf);
        CloseHandle(eye_hDirectory);
    }

    wprintf(L"[Eye] Opened: %s\n", eye_szDirectoryPath);
    CloseHandle(eye_hDirectory);
}
