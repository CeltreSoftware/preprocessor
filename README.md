# CeltreSoftware's Preprocessor Library

Interface library with definitions for preprocessor options to support multiple compiler
decorations.

## How To Use

Download the package with your favorite manager, such as `vcpkg` or CMake's `FetchContent` and then,
once exposed, simply link your target to the library. This will expose all the required options to
build and link the target using CeltreSoftware's Preprocessor Library.

For example:

```cmake
cmake_minimum_required(VERSION 3.23)
project(MyProject)

include(FetchContent)

FetchContent_Declare(
  celtresoft_preproc
  GIT_REPOSITORY https://github.com/CeltreSoftware/preprocessor.git
  GIT_TAG main)

FetchContent_MakeAvailable(celtresoft_preproc)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE CELTRE_SOFTWARE_PREPROCESSOR)
```

This will add any compiler options and definitions as well as include directories required.

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

### Architecture Options

While not visible through code, this project creates definitions that can be inherited in other
projects for 32-bit vs 64-bit architectures.

- `CELTRESOFT_ARCH_64BIT` in a 64-bit architecture (when `sizeof(void*) == 8`)
- `CELTRESOFT_ARCH_32BIT` in a 32-bit architecture (when `sizeof(void*) == 4`)
