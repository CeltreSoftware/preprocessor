# ===============================================================================
# The MIT License (MIT)
#
# Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ===============================================================================

cmake_minimum_required(VERSION 3.23)
project(
  CELTRE_SOFTWARE_PREPROCESSOR
  VERSION 1.1.0
  DESCRIPTION
    "Interface library with definitions for preprocessor options to support multiple compiler decorations."
  HOMEPAGE_URL "https://github.com/CeltreSoftware/preprocessor"
  LANGUAGES CXX C)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(
  ${PROJECT_NAME}
  INTERFACE FILE_SET HEADERS FILES
            ${PROJECT_SOURCE_DIR}/include/celtresoft/preproc/callconv.hpp
            ${PROJECT_SOURCE_DIR}/include/celtresoft/preproc/visibility.hpp)

target_include_directories(${PROJECT_NAME}
                           INTERFACE ${PROJECT_SOURCE_DIR}/include)

if(${CMAKE_SIZEOF_VOID_P} STREQUAL 8)
  target_compile_definitions(${PROJECT_NAME} INTERFACE CELTRESOFT_ARCH_64BIT)
else()
  target_compile_definitions(${PROJECT_NAME} INTERFACE CELTRESOFT_ARCH_32BIT)
endif()

if(${PROJECT_IS_TOP_LEVEL})
  set_target_properties(${PROJECT_NAME} PROPERTIES VERIFY_INTERFACE_HEADER_SETS
                                                   ON)
endif()
