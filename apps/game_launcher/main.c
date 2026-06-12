// ============================================================================
// MODULE : eng (Engine — Main Entry Point)
// FILE   : main.c
// PURPOSE: FilesRPG — launches the filesystem RPG engine
// ============================================================================

#include <stdio.h>
#include "the_eye.h"

int main(void) {
    wprintf(L"FilesRPG v0.0.0 — engine starting...");
    eye_dir_open(L"C:\\Users\\JcTheKing\\CLionProjects\\FilesRPG");


    return 0;
}
