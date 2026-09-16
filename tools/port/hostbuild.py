#!/usr/bin/env python3
"""
hostbuild.py -- build and run the port tests without CMake.

CMake is the supported build (port/CMakeLists.txt, and port/README.md tells
you how).  This script exists for two cases CMake does not cover:

  * a machine with a C compiler but no CMake, which is where this lane was
    written;
  * `--check`, a compile-and-link-only pass with the cross compiler already
    in tools/gcc-arm/.  It proves every source compiles clean and that the
    symbol closure is complete (the link fails on the first missing name),
    which is most of what the CMake build would tell you, without needing a
    native toolchain at all.  It cannot run the tests: the resulting binary
    is an ARM ELF and there is no runner for it here.

It reads the source lists straight out of port/CMakeLists.txt, so there is
one list, not two.

    python tools/port/hostbuild.py                  # find a native compiler, build, run
    python tools/port/hostbuild.py --check          # cross compile + link only
    python tools/port/hostbuild.py --probe          # say what is available, do nothing
"""

from __future__ import annotations

import argparse
import glob
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PORT = os.path.join(ROOT, "port")
CMAKELISTS = os.path.join(PORT, "CMakeLists.txt")

TESTS = ["test_text", "test_stats"]


def read_source_lists():
    """Pull BW_MATCHED_SOURCES, BW_SDK_SOURCES and BW_STUB_SOURCES out of
    port/CMakeLists.txt so the two builds can never drift apart."""
    with open(CMAKELISTS, encoding="utf-8") as fh:
        text = fh.read()
    out = []
    for var in ("BW_MATCHED_SOURCES", "BW_SDK_SOURCES", "BW_STUB_SOURCES"):
        m = re.search(r"set\(%s\s*(.*?)\n\)" % var, text, re.S)
        if not m:
            raise SystemExit("hostbuild.py: %s not found in port/CMakeLists.txt" % var)
        for line in m.group(1).splitlines():
            line = line.split("#")[0].strip()
            if not line:
                continue
            line = line.replace("${BW_ROOT}", ROOT)
            line = line.replace("${CMAKE_CURRENT_SOURCE_DIR}", PORT)
            out.append(os.path.normpath(line))
    return out


def find_cross():
    hits = sorted(glob.glob(os.path.join(
        ROOT, "tools", "gcc-arm", "*", "bin", "arm-none-eabi-gcc.exe")))
    hits += sorted(glob.glob(os.path.join(
        ROOT, "tools", "gcc-arm", "*", "bin", "arm-none-eabi-gcc")))
    env = os.environ.get("BW_ARM_TOOLCHAIN")
    if env:
        for name in ("arm-none-eabi-gcc.exe", "arm-none-eabi-gcc"):
            cand = os.path.join(env, name)
            if os.path.exists(cand):
                hits.insert(0, cand)
    return hits[0] if hits else None


def find_native():
    """Return (kind, path) for the first usable native C compiler."""
    for name in ("cc", "gcc", "clang"):
        path = shutil.which(name)
        if path:
            return ("unix", path)
    path = shutil.which("cl")
    if path:
        return ("msvc", path)
    return (None, None)


def probe():
    kind, native = find_native()
    print("cmake:          %s" % (shutil.which("cmake") or "NOT FOUND"))
    print("ctest:          %s" % (shutil.which("ctest") or "NOT FOUND"))
    print("native C:       %s" % (native or "NOT FOUND (cc, gcc, clang, cl)"))
    if native:
        print("                kind: %s" % kind)
    print("cross (arm):    %s" % (find_cross() or "NOT FOUND under tools/gcc-arm/"))
    print("python:         %s" % sys.executable)
    return 0


def run(cmd, **kw):
    r = subprocess.run(cmd, **kw)
    return r.returncode


def gen_fixtures(builddir, data_root):
    os.makedirs(builddir, exist_ok=True)
    out = os.path.join(builddir, "bw_fixtures.h")
    rc = run([sys.executable, os.path.join(ROOT, "tools", "port", "fixtures.py"),
              "--data-root", data_root, "--out", out])
    if rc != 0:
        raise SystemExit("hostbuild.py: fixture generation failed")
    return out


def build(cc, kind, builddir, data_root, link, run_tests):
    sources = read_source_lists()
    gen_fixtures(builddir, data_root)

    if kind == "msvc":
        raise SystemExit("hostbuild.py: the MSVC path is not implemented; "
                         "use CMake, which knows how to drive cl.exe")

    warn = ["-std=c99", "-Wall", "-Wextra", "-fsigned-char"]
    objs = []
    failed = 0
    for src in sources:
        obj = os.path.join(builddir, os.path.splitext(os.path.basename(src))[0] + ".o")
        extra = ["-Wno-unused-parameter"] if os.sep + "matched" + os.sep in src else []
        rc = run([cc] + warn + extra + ["-c", src, "-o", obj])
        if rc != 0:
            failed += 1
            print("hostbuild.py: FAILED to compile %s" % src)
        else:
            objs.append(obj)
    for t in TESTS:
        src = os.path.join(PORT, "tests", t + ".c")
        obj = os.path.join(builddir, t + ".o")
        rc = run([cc] + warn + ["-I", builddir, "-c", src, "-o", obj])
        if rc != 0:
            failed += 1
            print("hostbuild.py: FAILED to compile %s" % src)
    if failed:
        return 1
    print("[*] %d objects compiled clean" % (len(objs) + len(TESTS)))

    if not link:
        return 0

    # Only the basename: the directory can contain "gcc" too (tools/gcc-arm).
    cc_dir, cc_base = os.path.split(cc)
    ar = os.path.join(cc_dir, cc_base.replace("gcc", "ar").replace("clang", "ar"))
    if not os.path.exists(ar) and shutil.which("ar"):
        ar = shutil.which("ar")
    lib = os.path.join(builddir, "libbwport.a")
    if os.path.exists(lib):
        os.remove(lib)
    if run([ar, "rcs", lib] + objs) != 0:
        return 1

    extra_link = ["--specs=nosys.specs"] if "arm-none-eabi" in cc else []
    rc_all = 0
    for t in TESTS:
        exe = os.path.join(builddir, t + (".elf" if extra_link else ""))
        obj = os.path.join(builddir, t + ".o")
        p = subprocess.run([cc, "-std=c99"] + extra_link + [obj, lib, "-o", exe],
                           capture_output=True, text=True)
        bad = [ln for ln in p.stderr.splitlines()
               if "undefined reference" in ln or "multiple definition" in ln]
        if p.returncode != 0 or bad:
            print("hostbuild.py: LINK FAILED for %s" % t)
            for ln in bad:
                print("    " + ln)
            rc_all = 1
        else:
            print("[*] linked %s" % exe)
    if rc_all:
        return rc_all

    if not run_tests:
        print("[*] link closure complete; not running (cross-built binary)")
        return 0

    for t in TESTS:
        exe = os.path.join(builddir, t)
        print("---- %s ----" % t)
        if run([exe, data_root]) != 0:
            rc_all = 1
    return rc_all


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--build-dir", default=os.path.join(ROOT, "build", "port-host"))
    ap.add_argument("--data-root", default=os.path.join(ROOT, "extract", "data"))
    ap.add_argument("--check", action="store_true",
                    help="compile and link with the cross compiler; do not run")
    ap.add_argument("--probe", action="store_true", help="report tools and exit")
    args = ap.parse_args(argv)

    if args.probe:
        return probe()

    if args.check:
        cc = find_cross()
        if cc is None:
            raise SystemExit("hostbuild.py: no arm-none-eabi-gcc under tools/gcc-arm/")
        print("[*] cross compile check with %s" % cc)
        return build(cc, "unix", args.build_dir, args.data_root, link=True, run_tests=False)

    kind, cc = find_native()
    if cc is None:
        print("hostbuild.py: no native C compiler (cc, gcc, clang, cl) on PATH.")
        print("              try `--check` for a cross compile-and-link pass,")
        print("              or install a compiler and use CMake.")
        return 2
    print("[*] native build with %s" % cc)
    return build(cc, kind, args.build_dir, args.data_root, link=True, run_tests=True)


if __name__ == "__main__":
    sys.exit(main())
