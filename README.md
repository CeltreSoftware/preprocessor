# CeltreSoftware's Preprocessor Library

Interface library with definitions for preprocessor options to support multiple compiler
decorations.

## How To Use

This is a header only library with only definitions, so you can simply download the code and include
the `include` directory, or download the package with your favorite manager, such as `vcpkg` or
CMake's `FetchContent` and, again, include the `include` directory.

## Supported Preprocessor Options

### Calling Convention Options

- Windows:
  - MSVC and GCC/CYGWIN:
    - `CELTRESOFT_CALLCONV_CDECL` as `__cdecl`
    - `CELTRESOFT_CALLCONV_CLRCALL` as `__clrcall`
    - `CELTRESOFT_CALLCONV_STDCALL` as `__stdcall`
    - `CELTRESOFT_CALLCONV_FASTCALL` as `__fastcall`
    - `CELTRESOFT_CALLCONV_THISCALL` as `__thiscall`
    - `CELTRESOFT_CALLCONV_VECTORCALL` as `__vectorcall`

Outside of Windows, these options are defined as nothing as they are only used for Windows.

Note that `CELTRESOFT_CALLCONV_STDCALL` is equivalent to `WINAPI` as both are definitions for
`__stdcall` and `CELTRESOFT_CALLCONV_CDECL` will be used in cross platform functions as it is
defined as `__cdecl`.

### Visibility Options

- Windows with the definition of `WINDOWS_EXPORT_SYMBOLS`:
  - MSVC and Clang:
    - `CELTRESOFT_API_EXPORT` as `__declspec(dllexport)`
    - `CELTRESOFT_API_IMPORT` as `__declspec(dllimport)`
  - GCC/CYGWIN:
    - `CELTRESOFT_API_EXPORT` as `__attribute__((dllexport))`
    - `CELTRESOFT_API_IMPORT` as `__attribute__((dllimport))`
- Windows without the definition of `WINDOWS_EXPORT_SYMBOLS`:
  - MSVC and CLang:
    - `CELTRESOFT_API_EXPORT` and `CELTRESOFT_API_IMPORT` as `__declspec(dllimport)`
  - GCC/CYGWIN:
    - `CELTRESOFT_API_EXPORT` and `CELTRESOFT_API_IMPORT` as `__attribute__((dllimport))`
- Other Systems:
  - GCC and Clang:
    - `CELTRESOFT_API_EXPORT` as `__attribute__((visibility("default")))`
    - `CELTRESOFT_API_IMPORT` as `__attribute__((visibility("hidden")))`
