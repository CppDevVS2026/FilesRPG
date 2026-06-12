// ============================================================================
// MODULE : eye (The Eye — Filesystem Surveillance Engine)
// FILE   : the_eye.c
// PURPOSE: Watches a directory for file system changes using Win32 API
// ============================================================================

#include "the_eye.h"

#ifdef _WIN32

#include <stdio.h>
#include <wchar.h>

// ── INTERNAL HELPERS ─────────────────────────────────────────────────────────

// ── PUBLIC API ───────────────────────────────────────────────────────────────

YkResult eye_watcher_run(const WCHAR *p_szPath) {
    YK_CHECK_NULL(p_szPath);

    // TODO (Issue #1): Open folder with CreateFileW + error handling
    // TODO (Issue #2): Watch loop with ReadDirectoryChangesW
    // TODO (Issue #3): Walk FILE_NOTIFY_INFORMATION chain
    // TODO (Issue #5): Refactor into eye_start/eye_stop API

    wprintf(L"[eye] Stub — would watch: %s\n", p_szPath);
    return YK_OK;
}

#endif // _WIN32
