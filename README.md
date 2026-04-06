# Which-MSVC

Windows/MSVC-friendly build of GNU `which`.

This repository keeps the original C sources and adds a Visual Studio
project so you can build `which` directly on Windows.

## What This Program Does

`which` prints the full path of commands found in `PATH`.

Compared with very old `which` variants, this codebase keeps GNU behavior,
including options like:

- `--all` / `-a`
- `--read-alias` / `-i`
- `--read-functions`

## Build (Visual Studio)

### Option 1: IDE

1. Open `Which-MSVC.slnx`.
2. Select configuration (`Debug|x64` or `Release|x64`).
3. Build project `Which-MSVC`.

### Option 2: Command Line

Run in a Developer PowerShell / Developer Command Prompt:

```powershell
msbuild .\Which-MSVC\Which-MSVC.vcxproj /t:Build /p:Configuration=Debug /p:Platform=x64
```

For release:

```powershell
msbuild .\Which-MSVC\Which-MSVC.vcxproj /t:Build /p:Configuration=Release /p:Platform=x64
```

## Quick Check

After build, run:

```powershell
.\x64\Debug\which.exe --version
.\x64\Debug\which.exe cmd
.\x64\Debug\which.exe where
```

## Usage

1. Move `which.exe` to your preferred directory.
2. Add that directory to your system `PATH`.
3. Restart your terminal.
4. Run which.

## Repository Layout

- `which.c` - main program and option handling.
- `bash.c`, `tilde.c` - path/tilde/function lookup helpers.
- `getopt.c`, `getopt1.c` - GNU getopt implementation.
- `sys.h` - platform compatibility macros.
- `win_compat.c`, `win_compat.h` - Windows helper functions.
- `Which-MSVC/Which-MSVC.vcxproj` - Visual Studio project file.

## Notes

- This project targets Windows and keeps `CharacterSet=Unicode` in VS config.
- Internally, compatibility code uses Win32 `A` APIs where needed for `char *` logic.

## License

See `COPYING` for the full license text.
