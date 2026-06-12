// ============================================================================
// MODULE : eye (The Eye — Filesystem Surveillance Engine)
// FILE   : the_eye.h
// PURPOSE: Watches a directory for file system changes using Win32 API
// ============================================================================

#ifndef FILESRPG_THE_EYE_H
#define FILESRPG_THE_EYE_H
#include <wchar.h>

// Your code goes here — Sprint 1 will build this out.
void eye_dir_open(const wchar_t *eye_szDirectoryPath);
#endif // FILESRPG_THE_EYE_H
