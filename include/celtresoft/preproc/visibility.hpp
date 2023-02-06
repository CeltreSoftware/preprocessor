//==============================================================================
// The MIT License (MIT)
//
// Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//==============================================================================

#ifndef CELTRESOFT_PREPROC_VISIBILITY_HPP
#define CELTRESOFT_PREPROC_VISIBILITY_HPP

#if defined _WIN32 || defined __CYGWIN__
#  ifdef WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define CELTRESOFT_API_EXPORT __attribute__((dllexport))
#    else // __GNUC__
#      define CELTRESOFT_API_EXPORT __declspec(dllexport)
#    endif // __GNUC__
#  else    // WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define CELTRESOFT_API_EXPORT __attribute__((dllimport))
#    else // __GNUC__
#      define CELTRESOFT_API_EXPORT __declspec(dllimport)
#    endif // __GNUC__
#  endif   // WINDOWS_EXPORT_SYMBOLS
#  ifdef __GNUC__
#    define CELTRESOFT_API_IMPORT __attribute__((dllimport))
#  else // __GNUC__
#    define CELTRESOFT_API_IMPORT __declspec(dllimport)
#  endif // __GNUC__
#else    // _WIN32 || __CYGWIN__
#  if __GNUC__ >= 4
#    define CELTRESOFT_API_EXPORT __attribute__((visibility("default")))
#    define CELTRESOFT_API_IMPORT __attribute__((visibility("hidden")))
#  else // __GNUC__ >= 4
#    warning                                                                   \
        "Compiler unsupported by CeltreSoftware's Preprocessor library for export/import attributes"
#    define CELTRESOFT_API_EXPORT
#    define CELTRESOFT_API_EXPORT
#  endif // __GNUC__ >= 4
#endif   // _WIN32 || __CYGWIN__

#endif // CELTRESOFT_PREPROC_VISIBILITY_HPP