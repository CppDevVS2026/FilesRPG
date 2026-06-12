# FilesRPG 👁️

**FilesRPG** is a minimalist, high-concept world simulator where your computer's
native file system *is* the game canvas.

There is no custom game window. The game maps its simulation state directly onto
the Windows file system. You play by interacting with directories and files in
Windows Explorer.

## Core Concept

- **Directories are Spaces:** Folders represent rooms, buildings, streets.
- **Files are Citizens:** Each `.txt` file is a living Citizen with stats and traits.
- **Locomotion is File I/O:** Drag-and-drop a file to move a Citizen between zones.

The engine runs in the background as a Win32 process, watching your actions in
real-time and updating the world dynamically.

## Project Structure

```
FilesRPG/
├── include/              Public headers
│   ├── the_eye.h         Directory watcher (The Eye)
│   └── citizen.h         Citizen data model
├── src/
│   ├── the_eye/          The Eye — filesystem surveillance engine
│   └── citizen/          Citizen — entity state and serialization
├── apps/game_launcher/   Main executable entry point
├── tests/                Unity framework test suite
├── extern/yklib/         Yokim Core Library (Git submodule)
├── yokim.cfg             Uncrustify formatter config
├── Doxyfile.in           Doxygen documentation template
└── CMakeLists.txt        Root build orchestration
```

## Module Prefixes

| Prefix | Module                    |
|--------|---------------------------|
| `eye_` | The Eye (directory watcher)|
| `ctz_` | Citizen system            |
| `reg_` | Citizen registry          |
| `eng_` | Engine / main loop        |
| `cfg_` | Configuration             |

## Dependencies

- [yklib](https://gitlab.com/yokim-software/yklib) — Yokim Core Library
  (error handling, logging, memory, strings, vectors)

## Build (CMake)

```bash
git clone --recurse-submodules https://github.com/CppDevVS2026/FilesRPG.git
cd FilesRPG
mkdir build && cd build
cmake -G "Ninja" ..
cmake --build .
```

On Windows with MSYS2/UCRT64:
```bash
cmake -G "Ninja" -DCMAKE_C_COMPILER=gcc ..
cmake --build .
```

## Conventions

This project follows the
[Yokim Gold Standard v4.0](https://gitlab.com/yokim-software/yokim-gold-standard-v1.0).

- **Error handling:** All fallible functions return `YkResult`. Use `YK_TRY()` macros.
- **Naming:** `module_sigilPurpose` (e.g. `eye_hFolder`, `ctz_nHealth`)
- **Formatter:** Uncrustify with `yokim.cfg`
- **Logging:** yklib structured logging (`YK_LOG_INFO`, etc.)

## Version

**v0.0.0** — Scaffolded. See [CHANGELOG.md](CHANGELOG.md).

## License

Yokim Software Group — Internal use.
