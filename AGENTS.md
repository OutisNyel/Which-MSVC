# AGENTS.md

## 1. Goal and Scope
- Goal: build GNU `which` successfully on Windows with MSVC and keep CLI behavior aligned with upstream intent.
- Scope: source files used by the MSVC target (`which.c`, `bash.c`, `tilde.c`, `getopt.c`, `getopt1.c`, `sys.h`, related headers).
- Out of scope: replacing the build system with CMake, swapping in a different getopt implementation, or changing test semantics.

## 2. Repository Layout
- Root sources: `which.c`, `bash.c`, `tilde.c`, `getopt.c`, `getopt1.c` and headers.
- Visual Studio project: `Which-MSVC/Which-MSVC.vcxproj`.
- Tests/resources: `test/`.
- Autotools files: `build-aux/`, `m4/`, `configure.ac`, `Makefile.am`.

## 3. Standard Build Flow (MSVC)
- Open `Which-MSVC/Which-MSVC.vcxproj` in Visual Studio.
- Recommended configs: `Debug|x64` and `Release|x64`.
- Command line example (Developer PowerShell):
```powershell
msbuild .\Which-MSVC\Which-MSVC.vcxproj /t:Build /p:Configuration=Debug /p:Platform=x64
```

## 4. Windows Compatibility Contract
- Ensure GNU-style feature macros are set for MSVC builds: `STDC_HEADERS`, `HAVE_GETCWD`, `HAVE_STRING_H`.
- Keep `_WIN32` path and string behavior in `sys.h` intact (`PATH_SEPARATOR`, `DIR_SEPARATOR`, `STRCMP`, `STRNCMP`).
- If `getcwd/getwd` errors appear, first check `sys.h` preprocessor order and `getcwd -> _getcwd` mapping.

## 5. Acceptance Checklist
- `Debug|x64` build passes without blocking `C1189` (`getcwd/getwd`) errors.
- `which --help` runs and prints usage.
- `which cmd` and `which where` return executable paths on Windows.

## 6. Collaboration Rules
- Prefer minimal compatibility fixes over broad refactors.
- When changing build macros in `Which-MSVC.vcxproj`, document why.
- If build parameters or output structure changes, update this file.
