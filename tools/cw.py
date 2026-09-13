#!/usr/bin/env python3
"""CodeWarrior / Freescale ARM toolchain plumbing check.

Walks the TWL-line compiler collection under ``tools/mwccarm/mwccarm/dsi/``,
records each component's ``-version`` banner, compiles a trivial ARMv5TE
translation unit with each one and links the result.  This validates only
that the toolchain runs and produces an ELF; it says nothing about whether a
given version reproduces the game's code.

Usage:

    python tools/cw.py versions          # banners only
    python tools/cw.py smoke             # compile + link with every version
    python tools/cw.py smoke --markdown  # emit the docs/SYMBOLS.md table body
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CW_DIR = os.path.join(ROOT, "tools", "mwccarm", "mwccarm")

# Flag set that all nine TWL-line front ends accept, in the style of the
# SDK's own commondefs: ARMv5TE core, size/speed optimisation, ints for
# enums, C99, no C++ exceptions, ARM/Thumb interworking allowed.
CFLAGS = [
    "-proc", "arm946e",
    "-O4,p",
    "-enum", "int",
    "-lang", "c99",
    "-Cpp_exceptions", "off",
    "-interworking",
    "-char", "signed",
    "-gccext,on",
    "-msgstyle", "gcc",
    "-W", "all",
    "-ir", ".",
]

# mwldarm has no -nostdlib; it falls back to a built-in linker command file
# that pulls in the SDK runtime, so a self-contained smoke test supplies its
# own minimal LCF.  ">>" appends to an already-allocated segment; ">" on a
# second section is a "Segment already allocated" error.
LDFLAGS = ["-m", "SmokeEntry"]

SMOKE_LCF = """\
MEMORY {
    main (RWX) : ORIGIN = 0x02000000, LENGTH = 0x00100000
}

SECTIONS {
    .text   : { *(.text) }          >  main
    .rodata : { *(.rodata) }        >> main
    .data   : { *(.data) }          >> main
    .bss    : { *(.bss) *(COMMON) } >> main
}
"""

SMOKE_C = """\
/* Trivial translation unit for toolchain validation only. */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int g_smoke_counter;

static int Smoke_Helper(int x)
{
    return (x * 3) + 1;
}

u32 Smoke_Sum(const u8 *p, u32 n)
{
    u32 acc = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        acc += (u32)p[i];
    }
    return acc;
}

int Smoke_Main(int a, int b)
{
    int i;
    int r = Smoke_Helper(a);
    for (i = 0; i < b; i++) {
        r ^= (r << 1) + i;
    }
    g_smoke_counter += r;
    return r;
}

void SmokeEntry(void)
{
    g_smoke_counter = Smoke_Main(3, 7);
}
"""


def versions_dir():
    dsi = os.path.join(CW_DIR, "dsi")
    if not os.path.isdir(dsi):
        return []
    out = []
    for name in sorted(os.listdir(dsi), key=verkey):
        p = os.path.join(dsi, name)
        if os.path.isdir(p) and os.path.exists(os.path.join(p, "mwccarm.exe")):
            out.append((name, p))
    return out


def verkey(name):
    """Sort 1.1 < 1.1p1 < 1.2 < ... < 1.6sp2 the way a human would."""
    m = re.match(r"^(\d+)\.(\d+)(?:(sp|p)(\d+))?$", name)
    if not m:
        return (99, 99, 9, 99, name)
    major, minor = int(m.group(1)), int(m.group(2))
    kind = {None: 0, "p": 1, "sp": 2}.get(m.group(3), 3)
    patch = int(m.group(4) or 0)
    return (major, minor, kind, patch, name)


def run(cmd, cwd=None):
    env = dict(os.environ)
    # Silence the two "Environment variable not found" usage warnings; the
    # smoke test deliberately links nothing from the SDK.
    env.setdefault("MWLibraries", cwd or ".")
    env.setdefault("MWLibraryFiles", " ")
    try:
        p = subprocess.run(cmd, cwd=cwd, capture_output=True, timeout=120, env=env)
    except Exception as exc:
        return 127, "", str(exc)
    dec = lambda b: b.decode("latin1", "replace")
    return p.returncode, dec(p.stdout), dec(p.stderr)


def banner(exe):
    """Return (product, version) from a -version banner."""
    rc, out, err = run([exe, "-version"])
    text = (out + "\n" + err).replace("\r", "")
    product = ""
    version = ""
    for line in text.split("\n"):
        line = line.strip()
        if not line:
            continue
        if not product and ("for Embedded ARM" in line or "Assembler" in line
                            or "Linker" in line):
            product = line.rstrip(".")
        m = re.match(r"^Version (\S+) build (\S+)", line)
        if m and not version:
            version = "%s build %s" % (m.group(1), m.group(2))
    if not version:
        m = re.search(r"Version ([^\r\n]+)", text)
        if m:
            version = m.group(1).strip()
    return product, version


def smoke_one(name, path, workroot, keep=False):
    """Compile and link the smoke TU with one compiler version."""
    res = {
        "version": name,
        "cc": banner(os.path.join(path, "mwccarm.exe")),
        "as": banner(os.path.join(path, "mwasmarm.exe")),
        "ld": banner(os.path.join(path, "mwldarm.exe")),
        "compile": "fail",
        "link": "fail",
        "detail": "",
        "objsize": 0,
        "elfsize": 0,
    }
    work = os.path.join(workroot, name.replace(".", "_"))
    os.makedirs(work, exist_ok=True)
    src = os.path.join(work, "smoke.c")
    with open(src, "w", newline="\n") as fh:
        fh.write(SMOKE_C)

    obj = os.path.join(work, "smoke.o")
    env_exe = os.path.join(path, "mwccarm.exe")
    rc, out, err = run([env_exe] + CFLAGS + ["-c", "-o", obj, "smoke.c"], cwd=work)
    if rc != 0 or not os.path.exists(obj):
        res["detail"] = first_error(out + err)
        return res
    res["compile"] = "ok"
    res["objsize"] = os.path.getsize(obj)

    lcf = os.path.join(work, "smoke.lcf")
    with open(lcf, "w", newline="\n") as fh:
        fh.write(SMOKE_LCF)

    elf = os.path.join(work, "smoke.elf")
    rc, out, err = run([os.path.join(path, "mwldarm.exe")] + LDFLAGS
                       + ["-o", elf, "smoke.lcf", "smoke.o"], cwd=work)
    if rc == 0 and os.path.exists(elf):
        ok, why = check_elf(elf)
        res["link"] = "ok" if ok else "bad"
        res["detail"] = why
        res["elfsize"] = os.path.getsize(elf)
    else:
        res["detail"] = first_error(out + err)
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return res


def check_elf(path):
    """Confirm the linker produced an ET_EXEC EM_ARM image with an entry point."""
    import struct
    with open(path, "rb") as fh:
        d = fh.read()
    if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
        return False, "not ELF32 LE"
    e_type, e_machine = struct.unpack_from("<HH", d, 16)
    e_entry, = struct.unpack_from("<I", d, 24)
    if e_machine != 40:
        return False, "machine %d, expected EM_ARM" % e_machine
    if e_type != 2:
        return False, "e_type %d, expected ET_EXEC" % e_type
    if not (0x02000000 <= e_entry < 0x02100000):
        return False, "entry %#x outside the linker script range" % e_entry
    return True, "entry %#010x" % e_entry


def first_error(text):
    for line in text.replace("\r", "").split("\n"):
        line = line.strip()
        if line and ("error" in line.lower() or "fatal" in line.lower()):
            return line[:160]
    for line in text.replace("\r", "").split("\n"):
        if line.strip():
            return line.strip()[:160]
    return ""


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="smoke",
                    choices=("versions", "smoke"))
    ap.add_argument("--markdown", action="store_true",
                    help="print the result as a Markdown table")
    ap.add_argument("--keep", action="store_true",
                    help="keep the temporary build directories")
    args = ap.parse_args(argv)

    vers = versions_dir()
    if not vers:
        print("no compilers found under %s" % os.path.join(CW_DIR, "dsi"))
        return 1

    if args.command == "versions":
        for name, path in vers:
            for tool in ("mwccarm", "mwasmarm", "mwldarm"):
                prod, ver = banner(os.path.join(path, tool + ".exe"))
                print("%-8s %-10s %-46s %s" % (name, tool, prod, ver))
        return 0

    workroot = os.path.join(tempfile.gettempdir(), "bw_cw_smoke")
    os.makedirs(workroot, exist_ok=True)
    results = [smoke_one(n, p, workroot, keep=args.keep) for n, p in vers]

    if args.markdown:
        print("| dir | mwccarm | mwasmarm | mwldarm | compile | link | .o bytes |")
        print("| --- | --- | --- | --- | --- | --- | --- |")
        for r in results:
            print("| `dsi/%s` | %s | %s | %s | %s | %s | %d |"
                  % (r["version"], r["cc"][1], r["as"][1], r["ld"][1],
                     r["compile"], r["link"], r["objsize"]))
    else:
        print("%-8s %-22s %-20s %-20s %-8s %-6s %s"
              % ("dir", "mwccarm", "mwasmarm", "mwldarm", "compile", "link", "detail"))
        for r in results:
            print("%-8s %-22s %-20s %-20s %-8s %-6s %s"
                  % (r["version"], r["cc"][1], r["as"][1], r["ld"][1],
                     r["compile"], r["link"], r["detail"]))
    bad = [r for r in results if r["compile"] != "ok" or r["link"] != "ok"]
    print("\n%d/%d versions compiled and linked" % (len(results) - len(bad), len(results)))
    print("cflags: %s" % " ".join(CFLAGS))
    print("ldflags: %s -o smoke.elf smoke.lcf smoke.o" % " ".join(LDFLAGS))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
