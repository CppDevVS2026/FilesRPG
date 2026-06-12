// ============================================================================
// MODULE : eng (Engine — Main Entry Point)
// FILE   : main.c
// PURPOSE: FilesRPG — launches the filesystem RPG engine
// ============================================================================

#include "the_eye.h"
#include "yk_log.h"
#include "yk_mem.h"

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

// ── CONSTANTS ────────────────────────────────────────────────────────────────

// ── PUBLIC API ───────────────────────────────────────────────────────────────

int main(int argc, char *argv[]) {
    yk_mem_init();
    yk_log_init(NULL);

    YK_LOG_INFO("eng", "FilesRPG v0.0.0 starting...");

#ifdef _WIN32
    if (argc < 2) {
        YK_LOG_ERROR("eng", "Usage: FilesRPG.exe <watch_directory>");
        yk_log_shutdown();
        yk_mem_shutdown();
        return 1;
    }

    // Convert argv[1] to wide string for Win32 APIs
    WCHAR eng_szWidePath[EYE_PATH_MAX];
    MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, eng_szWidePath, EYE_PATH_MAX);

    YkResult eng_res = eye_watcher_run(eng_szWidePath);
    if (YK_IS_ERR(eng_res)) {
        YK_LOG_ERROR("eng", "Eye watcher failed: %s", yk_err_str(eng_res));
    }
#else
    (void)argc;
    (void)argv;
    YK_LOG_WARN("eng", "FilesRPG requires Windows. This is a stub build.");
#endif

    yk_log_shutdown();
    yk_mem_shutdown();
    return 0;
}
