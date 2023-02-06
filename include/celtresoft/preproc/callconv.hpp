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

#ifndef CELTRESOFT_PREPROC_CALLCONV_HPP
#define CELTRESOFT_PREPROC_CALLCONV_HPP

#if defined _WIN32 || defined __CYGWIN__
#  define CELTRESOFT_CALLCONV_CDECL      __cdecl
#  define CELTRESOFT_CALLCONV_CLRCALL    __clrcall
#  define CELTRESOFT_CALLCONV_STDCALL    __stdcall
#  define CELTRESOFT_CALLCONV_FASTCALL   __fastcall
#  define CELTRESOFT_CALLCONV_THISCALL   __thiscall
#  define CELTRESOFT_CALLCONV_VECTORCALL __vectorcall
#else // _WIN32 || __CYGWIN__
#  define CELTRESOFT_CALLCONV_CDECL
#  define CELTRESOFT_CALLCONV_CLRCALL
#  define CELTRESOFT_CALLCONV_STDCALL
#  define CELTRESOFT_CALLCONV_FASTCALL
#  define CELTRESOFT_CALLCONV_THISCALL
#  define CELTRESOFT_CALLCONV_VECTORCALL
#endif // _WIN32 || __CYGWIN__

#endif // CELTRESOFT_PREPROC_CALLCONV_HPP