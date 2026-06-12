// ============================================================================
// MODULE : eye (The Eye — Filesystem Surveillance Engine)
// FILE   : the_eye.h
// PURPOSE: Watches a directory for file system changes using Win32 API
// ============================================================================

#ifndef FILESRPG_THE_EYE_H
#define FILESRPG_THE_EYE_H

#ifdef _WIN32
#include <windows.h>
#endif

#include "yk_err.h"

// ── CONSTANTS ────────────────────────────────────────────────────────────────

#define EYE_BUF_SIZE   4096
#define EYE_PATH_MAX   260

// ── TYPES ────────────────────────────────────────────────────────────────────

typedef enum {
    EYE_ACTION_ADDED     = 1,
    EYE_ACTION_REMOVED   = 2,
    EYE_ACTION_MODIFIED  = 3,
    EYE_ACTION_MOVE_FROM = 4,
    EYE_ACTION_MOVE_TO   = 5,
} EyeAction;

// ── PUBLIC API ───────────────────────────────────────────────────────────────

// Watches a single directory for file changes (blocking, synchronous).
// This is the Sprint 1 entry point — will be replaced by a proper
// start/stop API in issue #5.
#ifdef _WIN32
YkResult eye_watcher_run(const WCHAR *p_szPath);
#endif

#endif // FILESRPG_THE_EYE_H
