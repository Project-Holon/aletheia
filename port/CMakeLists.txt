#
# port/CMakeLists.txt -- the native port of the matched game code.
#
#   cmake -S port -B build/port -DBW_DATA_ROOT=extract/data
#   cmake --build build/port
#   ctest --test-dir build/port --output-on-failure
#
# Nothing here compiles the DS build.  The matched sources under src/matched/
# are compiled *in place*, unchanged, for the host; the DS build still
# compiles the same files with mwccarm through tools/csrc.py.  A matched file
# that has to change to build here has to be re-verified against the ROM in
# the same commit (port/README.md, "Portability rules").
#

cmake_minimum_required(VERSION 3.16)
project(bw_port C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

get_filename_component(BW_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)

# Where the player's extracted assets live.  Relative paths are taken against
# the repository root, so -DBW_DATA_ROOT=extract/data does the obvious thing.
set(BW_DATA_ROOT "extract/data" CACHE STRING
    "Directory holding the extracted NitroFS tree (the one with a/0/0/2)")
if(IS_ABSOLUTE "${BW_DATA_ROOT}")
    set(BW_DATA_ROOT_ABS "${BW_DATA_ROOT}")
else()
    set(BW_DATA_ROOT_ABS "${BW_ROOT}/${BW_DATA_ROOT}")
endif()

find_package(Python3 COMPONENTS Interpreter REQUIRED)

# ---------------------------------------------------------------------------
# Compiler settings
# ---------------------------------------------------------------------------
#
# `-char signed` is part of the pinned DS compiler configuration
# (docs/AGENT-BRIEF.md); the host must agree, because matched code that
# stores into a plain `char` and compares it against a negative value behaves
# differently otherwise.
#
if(MSVC)
    add_compile_options(/W3 /J /wd4996)
else()
    add_compile_options(-Wall -Wextra -fsigned-char)
    # The matched sources are written to reproduce mwccarm's output, not to
    # please a modern warning set.  They are compiled with the same warnings
    # as the port's own code, but the ones that are inherent to the style are
    # turned off for them specifically, further down.
endif()

# ---------------------------------------------------------------------------
# The curated list of matched translation units
# ---------------------------------------------------------------------------
#
# Grown mechanically, never by hand-guessing:
#
#     python tools/port/closure.py --seed-func func_02018A7C
#     python tools/port/closure.py --seed-func func_02018A7C --cmake
#
# prints the transitive closure through matched files and, separately, every
# name that is still open (needs a port/stubs/ entry) or is a global object
# (needs a port/sdk/game_globals.c entry).  Add a file here only when the
# closure report says what it needs and that need is met.
#
set(BW_MATCHED_SOURCES
    # --- archive reading -------------------------------------------------
    ${BW_ROOT}/src/matched/func_02049578.c   # member index -> absolute position
    ${BW_ROOT}/src/matched/func_020495F4.c   # stream read
    ${BW_ROOT}/src/matched/func_0204944C.c   # read a range inside a member
    ${BW_ROOT}/src/matched/func_02048D00.c   # open by id, read whole member, close
    ${BW_ROOT}/src/matched/func_02048F4C.c   # the two-argument front of it
    ${BW_ROOT}/src/matched/sub_02034734.c    # the assert sink the readers call

    # --- message text ----------------------------------------------------
    ${BW_ROOT}/src/matched/func_02045E3C.c   # the message-bank string cipher

    # --- personal data and the stat formula ------------------------------
    ${BW_ROOT}/src/matched/unit_0201AFD4.c   # species + form -> member index
    ${BW_ROOT}/src/matched/unit_0201ADA4.c   # read the 0x3C-byte record
    ${BW_ROOT}/src/matched/unit_02019C54.c   # one-entry memo over that read
    ${BW_ROOT}/src/matched/unit_02019B04.c   # nature multiplier
    ${BW_ROOT}/src/matched/sub_02018A7C.c    # the six-stat recalculation
)

# ---------------------------------------------------------------------------
# The shim and the stubs
# ---------------------------------------------------------------------------

set(BW_SDK_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/fs.c            # FS_SeekFile/ReadFile/CloseFile
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/mi.c            # MI_CpuCopy/Fill family
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/os_alloc.c      # OS heap onto malloc
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/narc.c          # data root, NARC framing, ARM9 rodata
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/game_globals.c  # the ARM9 globals the matched code names
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/aliases.c       # sub_/func_ spelling forwarders
    ${CMAKE_CURRENT_SOURCE_DIR}/sdk/panic.c
)

# One symbol per file, on purpose: a static-library member is only pulled in
# when nothing else defines its symbol, which is how port/tests/test_stats.c
# supplies its own record accessors without displacing anything else.
set(BW_STUB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/reimpl_02045A98.c  # end-of-string code unit
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/reimpl_0204960C.c  # archive stream seek
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/stub_02048DDC.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/stub_02048E34.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/stub_02017E1C.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/stub_02017E40.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/stub_02018598.c
)

add_library(bwport STATIC
    ${BW_MATCHED_SOURCES}
    ${BW_SDK_SOURCES}
    ${BW_STUB_SOURCES}
)
target_include_directories(bwport PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sdk)

# The matched files are compiled with the port's warning set but without the
# ones that are inherent to reproducing a 2010 compiler's output: they declare
# each extern locally with the prototype that call site needs, so prototypes
# for the same function differ between translation units by design.
if(NOT MSVC)
    set_source_files_properties(${BW_MATCHED_SOURCES} PROPERTIES
        COMPILE_OPTIONS "-Wno-unused-parameter;-Wno-missing-prototypes")
endif()

# ---------------------------------------------------------------------------
# Generated fixtures
# ---------------------------------------------------------------------------

set(BW_FIXTURES ${CMAKE_CURRENT_BINARY_DIR}/bw_fixtures.h)

add_custom_command(
    OUTPUT ${BW_FIXTURES}
    COMMAND ${Python3_EXECUTABLE} ${BW_ROOT}/tools/port/fixtures.py
            --data-root ${BW_DATA_ROOT_ABS}
            --out ${BW_FIXTURES}
    DEPENDS ${BW_ROOT}/tools/port/fixtures.py
            ${BW_ROOT}/tools/assets/text.py
            ${BW_ROOT}/tools/assets/narc.py
    COMMENT "Generating port test fixtures from ${BW_DATA_ROOT_ABS}"
    VERBATIM
)
add_custom_target(bw_fixtures DEPENDS ${BW_FIXTURES})

# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

enable_testing()

foreach(t test_text test_stats)
    add_executable(${t} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${t}.c ${BW_FIXTURES})
    add_dependencies(${t} bw_fixtures)
    target_include_directories(${t} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${t} PRIVATE bwport)
    add_test(NAME ${t} COMMAND ${t} ${BW_DATA_ROOT_ABS})
endforeach()
